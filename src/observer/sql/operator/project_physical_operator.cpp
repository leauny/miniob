/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by WangYunlai on 2022/07/01.
//

#include "common/log/log.h"
#include "sql/operator/project_physical_operator.h"
#include "storage/record/record.h"
#include "storage/table/table.h"

RC ProjectPhysicalOperator::open(Trx *trx)
{
  if (children_.empty()) {
    return RC::SUCCESS;
  }

  PhysicalOperator *child = children_[0].get();
  RC rc = child->open(trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  return RC::SUCCESS;
}

RC ProjectPhysicalOperator::next()
{
  if (children_.empty()) {
    return RC::RECORD_EOF;
  }
  auto rc = RC::SUCCESS;
  if (agg_tuple_) {
    rc = children_[0]->next();
    if (rc != RC::SUCCESS) {
      return rc;
    }
    rc = do_aggregation();
    if (rc != RC::SUCCESS) {
      return rc;
    }
    return rc;
  }
  return children_[0]->next();
}

RC ProjectPhysicalOperator::close()
{
  if (!children_.empty()) {
    children_[0]->close();
  }
  if (agg_tuple_) {
    delete agg_tuple_;
  }
  return RC::SUCCESS;
}
Tuple *ProjectPhysicalOperator::current_tuple()
{
  if (agg_tuple_) {
    return agg_tuple_;
  }
  return current_tuple_norm();
}

Tuple *ProjectPhysicalOperator::current_tuple_norm()
{
  tuple_.set_tuple(children_[0]->current_tuple());
  return &tuple_;
}

void ProjectPhysicalOperator::add_projection(const Table *table, const FieldMeta *field_meta, AggType type)
{
  ASSERT(agg_tuple_ && type == AGG_NONE, "Mixed selection.");
  if (type != AGG_NONE && !agg_tuple_){
    agg_tuple_ = new AggregationTuple();
  }
  // 对单表来说，展示的(alias) 字段总是字段名称，
  // 对多表查询来说，展示的alias 需要带表名字
  TupleCellSpec *spec = new TupleCellSpec(table->name(), field_meta->name(), field_meta->name(), type);
  tuple_.add_cell_spec(spec);
}

RC ProjectPhysicalOperator::do_aggregation() {
  auto* tuple = dynamic_cast<ProjectTuple*>(current_tuple_norm());
  agg_tuple_->set_size(tuple->cell_num());         // 设置聚集函数tuple大小
  std::vector<AggType> agg_type(tuple->cell_num());
  for (auto i = 0; i < tuple->cell_num(); ++i) {
    agg_type[i] = tuple->agg_type_at(i);
  }

  RC rc = RC::SUCCESS;
  int count = 0;  // 用于统计tuple个数
  do {
    ++count;
    auto tuple = current_tuple_norm();
    assert(tuple != nullptr);

    int cell_num = tuple->cell_num();
    for (int i = 0; i < cell_num; i++) {
      Value value;
      rc = tuple->cell_at(i, value);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      if (agg_type[i] == AGG_NONE) { return RC::INTERNAL; }
      compute_aggregation(agg_type[i], agg_tuple_->get_value(i), value);
    }
  } while (!children_.empty() && RC::SUCCESS == children_[0]->next());

  for (auto i = 0; i < tuple->cell_num(); ++i) {
    if (agg_type[i] != AGG_AVG) {
      continue;
    }
    if (agg_tuple_->get_value(i).attr_type() == FLOATS) {
      agg_tuple_->get_value(i).set_float(agg_tuple_->get_value(i).get_float() / (float)count);
    } else if (agg_tuple_->get_value(i).attr_type() == INTS) {
      agg_tuple_->get_value(i).set_float((float)agg_tuple_->get_value(i).get_int() / (float)count);
    } else {
      return RC::INTERNAL;
    }
  }

  return rc;
}
RC ProjectPhysicalOperator::compute_aggregation(AggType type, Value &ans, const Value &val) {
  switch (type) {
    case AGG_MIN: {
       // 初始化值
       if (ans.attr_type() == UNDEFINED) {
        ans.set_type(val.attr_type());
        ans.set_value(val);
        break;
       }
       switch (val.attr_type()) {
        case CHARS: {
          if (strcmp(ans.data(), val.data()) <= 0) { break; }
          ans.set_data(val.data(), strlen(val.data()));
          break;
        }
        case INTS: {
          if (ans.get_int() <= val.get_int()) { break; }
          ans.set_int(val.get_int());
          break;
        }
        case DATES: {
          if (ans.get_date() <= val.get_date()) { break; }
          ans.set_date(val.get_date());
          break;
        }
        case FLOATS: {
          if (ans.get_float() <= val.get_float()) { break; }
          ans.set_float(val.get_float());
          break;
        }
        case BOOLEANS: {
          if (ans.get_boolean() <= val.get_boolean()) { break; }
          ans.set_boolean(val.get_boolean());
          break;
        }
       }
       break;
    }
    case AGG_MAX: {
       if (ans.attr_type() == UNDEFINED) {
        ans.set_type(val.attr_type());
        ans.set_value(val);
        break;
       }
       switch (val.attr_type()) {
        case CHARS: {
          if (strcmp(ans.data(), val.data()) >= 0) { break; }
          ans.set_data(val.data(), strlen(val.data()));
          break;
        }
        case INTS: {
          if (ans.get_int() >= val.get_int()) { break; }
          ans.set_int(val.get_int());
          break;
        }
        case DATES: {
          if (ans.get_date() >= val.get_date()) { break; }
          ans.set_date(val.get_date());
          break;
        }
        case FLOATS: {
          if (ans.get_float() >= val.get_float()) { break; }
          ans.set_float(val.get_float());
          break;
        }
        case BOOLEANS: {
          if (ans.get_boolean() >= val.get_boolean()) { break; }
          ans.set_boolean(val.get_boolean());
          break;
        }
       }
       break;
    }
    // avg和sum都是先计算总值
    case AGG_SUM:
    case AGG_AVG: {
       // 不支持boolean
       if (ans.attr_type() == UNDEFINED) {
        ans.set_type(val.attr_type());
        if (val.attr_type() == INTS) { ans.set_int(val.get_int()); }
        else if (val.attr_type() == FLOATS) { ans.set_float(val.get_float()); }
        else if (val.attr_type() == CHARS) {
          // 隐式转换，直接取float
          ans.set_type(FLOATS);
          ans.set_float(val.get_float());
        }
        else { return RC::INTERNAL; }
       } else {
        if (val.attr_type() == INTS) { ans.set_int(ans.get_int() + val.get_int()); }
        else if (val.attr_type() == FLOATS) { ans.set_float(ans.get_float() + val.get_float()); }
        else if (val.attr_type() == CHARS) { ans.set_float(ans.get_float() + val.get_float()); }
        else { return RC::INTERNAL; }
       }
       break;
    }
    case AGG_COUNT:
    case AGG_WCOUNT:
    default: {
       if (ans.attr_type() == UNDEFINED) {
        ans.set_type(INTS);
        ans.set_int(1);
       } else {
        ans.set_int(ans.get_int() + 1);
       }
    }
  }
  return RC::SUCCESS;
}

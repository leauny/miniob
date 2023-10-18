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
  if (has_agg_ && !agg_tuple_) {
    agg_tuple_ = new LeafTuple;
  }
  return RC::SUCCESS;
}

RC ProjectPhysicalOperator::next()
{
  if (children_.empty()) {
    return RC::RECORD_EOF;
  }
  auto rc = RC::SUCCESS;
  if (has_agg_) {
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
  if (has_agg_ && agg_tuple_) {
    delete agg_tuple_;
  }
  if (result_) {
    delete result_;
  }
  return RC::SUCCESS;
}
Tuple *ProjectPhysicalOperator::current_tuple()
{
  if (has_agg_) {
    return agg_tuple_;
  }

  // function length, round, data_format.
  if (!result_) {
    result_ = new LeafTuple(current_tuple_norm()->cell_num());         // 设置聚集函数tuple大小
  }
  int cell_num = tuple_.cell_num();
  for (int i = 0; i < cell_num; i++) {
    auto func_type = tuple_.func_type_at(i);
    auto func_parm = tuple_.func_parm_at(i);

    // TODO: 检测value是否是null
    Value value;
    tuple_.cell_at(i, value);

    // 无需判断类型，在SelectStmt::create已经判断过
    switch (func_type) {
      case FUNC_LENGTH: {
        value.set_int(strlen(value.data()));
        break;
      }
      case FUNC_ROUND: {
        value.set_float(value.get_float(), std::stoi(func_parm));
        value.set_float(std::stof(value.to_string()));
        break;
      }
      case FUNC_DATE_FORMAT: {
        value.set_date(value.get_date(), func_parm);
        auto str = value.to_string();
        value.set_type(CHARS);
        value.set_data(str.c_str(), str.size());
        break;
      }
    }

    // 设置结果
    result_->set_value(i, value);
  }

  return result_;
}

Tuple *ProjectPhysicalOperator::current_tuple_norm()
{
  tuple_.set_tuple(children_[0]->current_tuple());
  return &tuple_;
}

void ProjectPhysicalOperator::add_projection(
    const Table *table, const FieldMeta *field_meta, const std::string& alias, FuncType type, std::string func_parm)
{
  ASSERT(has_agg_ && !(type > FUNC_NONE && type < FUNC_AGG_END), "Mixed selection.");
  if (type > FUNC_NONE && type < FUNC_AGG_END){
    has_agg_ = true;
  }
  // 对单表来说，展示的(alias) 字段总是字段名称，
  // 对多表查询来说，展示的alias 需要带表名字
  TupleCellSpec *spec = new TupleCellSpec(table->name(), field_meta->name(),
      alias == "" ? field_meta->name() : alias.c_str(), type, func_parm);
  tuple_.add_cell_spec(spec);
}

RC ProjectPhysicalOperator::do_aggregation() {
  auto* tuple = dynamic_cast<ProjectTuple*>(current_tuple_norm());
  agg_tuple_->set_size(tuple->cell_num());         // 设置聚集函数tuple大小
  std::vector<FuncType> agg_type(tuple->cell_num());
  for (auto i = 0; i < tuple->cell_num(); ++i) {
    agg_type[i] = tuple->func_type_at(i);
  }

  RC rc = RC::SUCCESS;
  int count = 0;  // 用于统计tuple个数
  do {
    auto tuple = current_tuple_norm();
    assert(tuple != nullptr);

    int cell_num = tuple->cell_num();
    for (int i = 0; i < cell_num; i++) {
      Value value;
      rc = tuple->cell_at(i, value);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      if (!(agg_type[i] > FUNC_NONE && agg_type[i] < FUNC_AGG_END)) { return RC::INTERNAL; }
      compute_aggregation(agg_type[i], agg_tuple_->get_value(i), value, count);
    }
  } while (!children_.empty() && RC::SUCCESS == children_[0]->next());

  for (auto i = 0; i < tuple->cell_num(); ++i) {
    if (agg_type[i] != FUNC_AVG) {
      continue;
    }
    switch (agg_tuple_->get_value(i).attr_type()) {
      case FLOATS: {
        agg_tuple_->get_value(i).set_float(agg_tuple_->get_value(i).get_float() / (float)count);
      } break;
      case INTS: {
        agg_tuple_->get_value(i).set_float((float)agg_tuple_->get_value(i).get_int() / (float)count);
      } break;
      case NULLS: {
        // do nothing
      } break;
      default: {
        return RC::INTERNAL;
      }
    }
  }

  return rc;
}

RC ProjectPhysicalOperator::compute_aggregation(FuncType type, Value &ans, const Value &val, int& count) {
  switch (type) {
    case FUNC_MIN: {
       // 初始化值
       if (ans.attr_type() == UNDEFINED) {
        ans.set_type(val.attr_type());
        ans.set_value(val);
        break;
       }
       if (val.attr_type() == NULLS) {
        break;
       }
       if (ans.attr_type() == NULLS) {
        ans.set_value(val);
       }
       if (val.compare(ans) < 0) {
        ans.set_value(val);
       }
    } break;
    case FUNC_MAX: {
       if (ans.attr_type() == UNDEFINED) {
        ans.set_type(val.attr_type());
        ans.set_value(val);
        break;
       }
       if (val.attr_type() == NULLS) {
        break;
       }
       if (ans.attr_type() == NULLS) {
        ans.set_value(val);
       }
       if (val.compare(ans) > 0) {
        ans.set_value(val);
       }
       break;
    } break;
    // avg和sum都是先计算总值
    case FUNC_SUM:
    case FUNC_AVG: {
       // 不支持boolean
       if (val.attr_type() == NULLS) {
        if (ans.attr_type() == UNDEFINED) {
          ans.set_type(val.attr_type());
          ans.set_value(val);
        }
        break;
       }
       ++count;
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
    } break;
    case FUNC_COUNT: {
       if (val.attr_type() == NULLS) {
        if (ans.attr_type() == UNDEFINED) {
          ans.set_type(INTS);
          ans.set_int(0);
        }
        break;
       }
       if (ans.attr_type() == UNDEFINED) {
        ans.set_type(INTS);
        ans.set_int(1);
       } else {
        ans.set_int(ans.get_int() + 1);
       }
    } break;
    case FUNC_WCOUNT:
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

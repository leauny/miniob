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
    agg_tuple_ = new LeafTuple(tuple_.cell_num());
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
  return RC::SUCCESS;
}
Tuple *ProjectPhysicalOperator::current_tuple()
{
  if (has_agg_) {
    return agg_tuple_;
  }

  return current_tuple_norm();
}

Tuple *ProjectPhysicalOperator::current_tuple_norm()
{
  tuple_.set_tuple(children_[0]->current_tuple());
  return &tuple_;
}

RC ProjectPhysicalOperator::do_aggregation() {
  RC rc = RC::SUCCESS;
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
      if (!agg_tuple_) { return RC::INTERNAL; }
      agg_tuple_->set_value(i, value);
    }
  } while (!children_.empty() && RC::SUCCESS == children_[0]->next());

  return rc;
}
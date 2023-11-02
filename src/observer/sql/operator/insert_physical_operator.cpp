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
// Created by WangYunlai on 2021/6/9.
//

#include "sql/operator/insert_physical_operator.h"
#include "sql/stmt/insert_stmt.h"
#include "storage/table/table.h"
#include "storage/trx/trx.h"

using namespace std;

InsertPhysicalOperator::InsertPhysicalOperator(Table *table, vector<std::vector<Value>> &&values)
    : table_(table) { for (auto &n : values) { values_.emplace_back(std::move(n)); } }

RC InsertPhysicalOperator::open(Trx *trx)
{
  auto rc = RC::SUCCESS;

  // 收集select的结果
  if (!children().empty() && values_.empty()) {
    PhysicalOperator *child = children_[0].get();
    rc = child->open(trx);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to open child operator: %s", strrc(rc));
      return rc;
    }

    rc = child->next();
    if (rc != RC::SUCCESS) {
      // 避免select无内容
      if (rc == RC::RECORD_EOF) {
        rc = RC::SUCCESS;
      }
      return rc;
    }

    do {
      auto tuple = current_tuple_norm();
      if (!tuple) { break; }
      int cell_num = tuple->cell_num();
      std::vector<Value> values;
      for (int i = 0; i < cell_num; i++) {
        Value value;
        rc = tuple->cell_at(i, value);
        if (rc != RC::SUCCESS) {
          return rc;
        }
        values.emplace_back(value);
      }
      values_.emplace_back(std::move(values));  // 存入select到的结果
    } while (!children_.empty() && RC::SUCCESS == children_[0]->next());;
  }

  for (const auto &value : values_) {
    Record record;
    rc = table_->make_record(static_cast<int>(value.size()), value.cells().data(), record);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to make record. rc=%s", strrc(rc));
      return rc;
    }

    rc = trx->insert_record(table_, record);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to insert record by transaction. rc=%s", strrc(rc));
    }
  }
  return rc;
}

RC InsertPhysicalOperator::next()
{
  return RC::RECORD_EOF;
}

RC InsertPhysicalOperator::close()
{
  return RC::SUCCESS;
}

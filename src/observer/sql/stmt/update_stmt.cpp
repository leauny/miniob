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
// Created by Wangyunlai on 2022/5/22.
//

#include <cmath>
#include "sql/stmt/update_stmt.h"
#include "common/log/log.h"
#include "storage/db/db.h"
#include "storage/table/table.h"
#include "sql/stmt/filter_stmt.h"
#include "sql/parser/value.h"
class Value;
UpdateStmt::UpdateStmt(Table *table, const std::vector<std::pair<Expression*, int>>& expressionsAndOffsets, FilterStmt *filterStmt)
    : table_(table), expressions_and_offsets_(expressionsAndOffsets), filter_stmt_(filterStmt) {}

RC UpdateStmt::create(Db *db, const UpdateSqlNode &update, Stmt *&stmt)
{
  RC rc = RC::SUCCESS;
  const char *table_name = update.relation_name.c_str();
  if (nullptr == db || nullptr == table_name) {
    LOG_WARN("invalid argument. db=%p, table_name=%p", db, table_name);
    return RC::INVALID_ARGUMENT;
  }

  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  std::vector<std::pair<Expression*, int>> expressions_and_offsets;
  const TableMeta &table_meta = table->table_meta();
  for (auto& [attribute_name, expr] : update.update_fields) {
    const FieldMeta *field_meta = table_meta.field(attribute_name.c_str());
    if (field_meta == nullptr) {
      LOG_WARN("field type mismatch. the attribute name %s is not in table %s",
              attribute_name.c_str(), table_name);
      return RC::SCHEMA_FIELD_NOT_EXIST;
    }

    const AttrType field_type = field_meta->type();
    if (expr->type() == ExprType::VALUE) {
      AttrType value_type = expr->value_type();
      ValueExpr* value_expr = dynamic_cast<ValueExpr*>(expr);
      if (!value_expr) {
        return RC::INVALID_ARGUMENT;
      }
      Value& value = value_expr->get_value();

      // check the type valid
      rc = value_cast(field_meta, value);
      if (OB_FAIL(rc)) {
        return rc;
      }
      // check the date valid
      if (value_type == DATES) {
        auto dates = value.get_date();
        if (!dates.ok()) {
          LOG_WARN("date is invalid, table=%s, value_type=%d",table_name, value_type);
          return RC::VARIABLE_NOT_VALID;
        }
      }
    } else if (expr->type() == ExprType::SUBQUERY) {
      SubQueryExpr* subquery_expr = dynamic_cast<SubQueryExpr*>(expr);
      if (!subquery_expr) {
        return RC::INVALID_ARGUMENT;
      }
      subquery_expr->set_field_meta(field_meta);
    }

    // everything is ok, append it in expressions_and_offsets
    expressions_and_offsets.emplace_back(expr, field_meta->offset());
  }

  // where子句中构建FieldExpr
  for (auto &condition : update.conditions) {
    rc = FieldExpr::build_field(condition, table);
    if(OB_FAIL(rc)) { return rc; };
  }

  std::unordered_map<std::string, Table *> table_map;
  table_map.insert(std::pair<std::string, Table *>(std::string(table_name), table));

  FilterStmt *filter_stmt = nullptr;
  rc = FilterStmt::create(
      db, table, &table_map, update.conditions, filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create filter statement. rc=%d:%s", rc, strrc(rc));
    return rc;
  }
  // everything alright
  stmt = new UpdateStmt(table, expressions_and_offsets, filter_stmt);
  return RC::SUCCESS;
}

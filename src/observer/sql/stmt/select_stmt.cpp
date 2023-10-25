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
// Created by Wangyunlai on 2022/6/6.
//

#include "sql/stmt/select_stmt.h"
#include "sql/stmt/filter_stmt.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "storage/db/db.h"
#include "storage/table/table.h"
#include "event/sql_debug.h"

SelectStmt::~SelectStmt()
{
  if (nullptr != filter_stmt_) {
    delete filter_stmt_;
    filter_stmt_ = nullptr;
  }
}

static void wildcard_fields(Table *table, std::vector<std::unique_ptr<Expression>> &field_expressions, bool multi_table)
{
  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num();
  for (int i = table_meta.sys_field_num(); i < field_num; i++) {
    std::string name = table_meta.field(i)->name();
    if (multi_table) {
      name = std::string(table_meta.name()) + "." + name;
    }
    field_expressions.emplace_back(
        new FieldExpr(table, table_meta.field(i), name)
    );
  }
}

RC SelectStmt::create(Db *db, const SelectSqlNode &select_sql, Stmt *&stmt)
{
  RC rc = RC::SUCCESS;

  if (nullptr == db) {
    LOG_WARN("invalid argument. db is null");
    return RC::INVALID_ARGUMENT;
  }

  // collect tables in `from` statement
  std::vector<Table *> tables;
  std::unordered_map<std::string, Table *> table_map;
  for (size_t i = 0; i < select_sql.relations.size(); i++) {
    if (select_sql.relations[i]->type() != ExprType::TABLE) {
      LOG_WARN("invalid argument. relation type is not table. index=%d", i);
      return RC::INVALID_ARGUMENT;
    }
    auto table_name = select_sql.relations[i]->name();
    if (common::is_blank(table_name.c_str())) {
      LOG_WARN("invalid argument. relation name is null. index=%d", i);
      return RC::INVALID_ARGUMENT;
    }

    Table *table = db->find_table(table_name.c_str());
    if (nullptr == table) {
      LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name.c_str());
      return RC::SCHEMA_TABLE_NOT_EXIST;
    }

    tables.push_back(table);
    table_map.insert(std::pair<std::string, Table *>(table_name, table));
  }

  // 构建FieldExpr
  // TODO: 根据表的个数构建alias, 并且判断表名冲突
  bool has_attr  = false;
  bool has_agg = false;
  if (tables.size() == 1) {
    for (int i = static_cast<int>(select_sql.attributes.size()) - 1; i >= 0; i--) {
      rc = FieldExpr::build_field(select_sql.attributes[i], tables[0], has_attr, has_agg);
      if(OB_FAIL(rc)) { return rc; };
    }

    for (auto &condition : select_sql.conditions) {
      rc = FieldExpr::build_field(condition, tables[0], has_attr, has_agg);
      if(OB_FAIL(rc)) { return rc; };
    }

  } else {
    for (int i = static_cast<int>(select_sql.attributes.size()) - 1; i >= 0; i--) {
      rc = FieldExpr::build_field(select_sql.attributes[i], db, has_attr, has_agg);
      if(OB_FAIL(rc)) { return rc; };
    }

    for (auto &condition : select_sql.conditions) {
      rc = FieldExpr::build_field(condition, db, has_attr, has_agg);
      if(OB_FAIL(rc)) { return rc; };
    }
  }
  // collect query fields in `select` statement
  std::vector<std::unique_ptr<Expression>> query_expressions;
  // 倒序处理是因为yacc_sql.y中select语句的attributes是尾插的
  for (int i = static_cast<int>(select_sql.attributes.size()) - 1; i >= 0; i--) {
    Expression* relation_attr = select_sql.attributes[i];

    switch (relation_attr->type()) {
      case ExprType::STAR: {
        has_attr = true;
        for (Table *table : tables) {
          wildcard_fields(table, query_expressions, tables.size() != 1);
        }
      } break;
      case ExprType::FIELD:
      case ExprType::FUNC:
      case ExprType::ARITHMETIC: {
        query_expressions.emplace_back(relation_attr);
      } break;
      default:
        sql_debug("Got error relation attribute: %d", relation_attr->type());
        return RC::INTERNAL;
    }

    if (has_attr && has_agg) { return RC::SCHEMA_MIXED_QUERY; }
  }

  LOG_INFO("got %d tables in from stmt and %d fields in query stmt", tables.size(), query_expressions.size());

  Table *default_table = nullptr;
  if (tables.size() == 1) {
    default_table = tables[0];
  }

  // create filter statement in `where` statement
  FilterStmt *filter_stmt = nullptr;
  rc = FilterStmt::create(db,
      default_table,
      &table_map,
      select_sql.conditions,
      filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("cannot construct filter stmt");
    return rc;
  }

  // everything alright
  SelectStmt *select_stmt = new SelectStmt();

  select_stmt->tables_.swap(tables);
  select_stmt->query_exprs_.swap(query_expressions);
  select_stmt->filter_stmt_ = filter_stmt;
  select_stmt->has_agg_ = has_agg;
  stmt = select_stmt;
  return RC::SUCCESS;
}
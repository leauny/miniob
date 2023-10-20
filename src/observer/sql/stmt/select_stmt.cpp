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

static void wildcard_fields(Table *table, std::vector<Expression*> &field_expressions)
{
  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num();
  for (int i = table_meta.sys_field_num(); i < field_num; i++) {
    field_expressions.emplace_back(new FieldExpr(table, table_meta.field(i)));
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
  if (tables.size() == 1) {
    for (int i = static_cast<int>(select_sql.attributes.size()) - 1; i >= 0; i--) {
      rc = build_field(select_sql.attributes[i], tables[0]);
      if(OB_FAIL(rc)) { return rc; };
    }

    for (auto &condition : select_sql.conditions) {
      rc = build_field(condition, tables[0]);
      if(OB_FAIL(rc)) { return rc; };
    }

  } else {
    for (int i = static_cast<int>(select_sql.attributes.size()) - 1; i >= 0; i--) {
      rc = build_field(select_sql.attributes[i], db);
      if(OB_FAIL(rc)) { return rc; };
    }

    for (auto &condition : select_sql.conditions) {
      rc = build_field(condition, db);
      if(OB_FAIL(rc)) { return rc; };
    }
  }
  // collect query fields in `select` statement
  std::vector<Expression*> query_expressions;
  bool has_aggregation = false;
  bool has_attributes = false;
  // 倒序处理是因为yacc_sql.y中select语句的attributes是尾插的
  for (int i = static_cast<int>(select_sql.attributes.size()) - 1; i >= 0; i--) {
    Expression* relation_attr = select_sql.attributes[i];

    // TODO: 判断relation_attr的类型后处理
    switch (relation_attr->type()) {
      case ExprType::FIELD: {
        auto expr = dynamic_cast<FieldExpr*>(relation_attr);
        auto type = expr->get_func_type();
        if (type > FUNC_NONE && type < FUNC_AGG_END) {
          has_aggregation = true;
        } else {
          has_attributes = true;
        }

        // function只支持指定类型
        if ((type == FUNC_LENGTH && expr->field().meta()->type() != CHARS) ||
            (type == FUNC_ROUND && expr->field().meta()->type() != FLOATS) ||
            (type == FUNC_DATE_FORMAT && expr->field().meta()->type() != DATES)) {
          return RC::SCHEMA_WRONG_FUNC;
        }
        query_expressions.emplace_back(relation_attr);
      } break;
      case ExprType::STAR: {
        for (Table *table : tables) {
          wildcard_fields(table, query_expressions);
        }
      } break;
      default:
        sql_debug("Got error relation attribute: %d", relation_attr->type());
        return RC::INTERNAL;
    }

    if (has_aggregation && has_attributes) { return RC::SCHEMA_MIXED_QUERY; }
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
  stmt = select_stmt;
  return RC::SUCCESS;
}

RC SelectStmt::build_field(Expression *expr, Table *table) {
  RC rc = RC::SUCCESS;
  switch (expr->type()) {
    case ExprType::FIELD: {
      rc = create_field_expr(expr, table);
      if(OB_FAIL(rc)) { return rc; };
    }break;
    case ExprType::COMPARISON: {
        auto comparison_expr = dynamic_cast<ComparisonExpr*>(expr);
        rc = build_field(comparison_expr->left().get(), table);
        if(OB_FAIL(rc)) { return rc; };
        rc = build_field(comparison_expr->right().get(), table);
        if(OB_FAIL(rc)) { return rc; };
    }break;
    case ExprType::CONJUNCTION: {
        for (auto &expression : dynamic_cast<ConjunctionExpr*>(expr)->children()) {
          rc = build_field(expression.get(), table);
          if(OB_FAIL(rc)) { return rc; };
        }
    } break;
    case ExprType::ARITHMETIC: {
        auto arithmetic_expr = dynamic_cast<ArithmeticExpr*>(expr);
        rc = build_field(arithmetic_expr->left().get(), table);
        if(OB_FAIL(rc)) { return rc; };
        rc = build_field(arithmetic_expr->right().get(), table);
        if(OB_FAIL(rc)) { return rc; };
    }break;
  }
  return rc;
}

// multi-table
RC SelectStmt::build_field(Expression *expr, Db* db) {
  RC rc = RC::SUCCESS;
  switch (expr->type()) {
    case ExprType::FIELD: {
        auto field_expr = dynamic_cast<FieldExpr*>(expr);
        auto table = db->find_table(field_expr->get_node().relation_name.c_str());
        rc = create_field_expr(expr, table);
        if(OB_FAIL(rc)) { return rc; };
    }break;
    case ExprType::COMPARISON: {
        auto comparison_expr = dynamic_cast<ComparisonExpr*>(expr);
        rc = build_field(comparison_expr->left().get(), db);
        if(OB_FAIL(rc)) { return rc; };
        rc = build_field(comparison_expr->right().get(), db);
        if(OB_FAIL(rc)) { return rc; };
    }break;
    case ExprType::CONJUNCTION: {
        for (auto &expression : dynamic_cast<ConjunctionExpr*>(expr)->children()) {
          rc = build_field(expression.get(), db);
          if(OB_FAIL(rc)) { return rc; };
        }
    } break;
    case ExprType::ARITHMETIC: {
        auto arithmetic_expr = dynamic_cast<ArithmeticExpr*>(expr);
        rc = build_field(arithmetic_expr->left().get(), db);
        if(OB_FAIL(rc)) { return rc; };
        rc = build_field(arithmetic_expr->right().get(), db);
        if(OB_FAIL(rc)) { return rc; };
    }break;
  }
  return rc;
}

RC SelectStmt::create_field_expr(Expression *expr, Table *table) {
  auto field_expr = dynamic_cast<FieldExpr*>(expr);
  if (field_expr == nullptr) {
    return RC::SCHEMA_FIELD_NOT_EXIST;
  }
  auto attribute_name = field_expr->get_node().attribute_name;
  auto field_meta = table->table_meta().field(attribute_name.c_str());
  if (!field_meta) {
    return RC::SCHEMA_FIELD_NOT_EXIST;
  }
  Field field(table, field_meta);
  field_expr->set_field(field);
  return RC::SUCCESS;
}

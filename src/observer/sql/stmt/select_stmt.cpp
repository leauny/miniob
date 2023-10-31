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
    auto table_alias = select_sql.relations[i]->alias();
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
    if (table_map.count(table_alias) > 0) {
      LOG_WARN("duplicate table alias. table_alias=%s", table_alias.c_str());
      return RC::SCHEMA_TABLE_ALIAS_DUPLICATE;
    }
    if (!table_alias.empty()) {
      table_map.insert(std::pair<std::string, Table *>(table_alias, table));
    }
    table_map.insert(std::pair<std::string, Table *>(table_name, table));
  }

  // 构建FieldExpr
  // TODO: 根据表的个数构建alias, 并且判断表名冲突
  bool has_attr  = false;
  bool has_agg = false;
  bool useless = false;
  if (tables.size() == 1) {
    for (int i = static_cast<int>(select_sql.attributes.size()) - 1; i >= 0; i--) {
      rc = FieldExpr::build_field(select_sql.attributes[i], tables[0], has_attr, has_agg);
      if(OB_FAIL(rc)) { return rc; };
    }

    // 处理order by
    for (auto &order : select_sql.order) {
      rc = FieldExpr::build_field(order, tables[0], useless, useless);
      if(OB_FAIL(rc)) { return rc; };
    }

    // 处理group by
    for (auto &group : select_sql.group) {
      rc = FieldExpr::build_field(group, tables[0], useless, useless);
      if(OB_FAIL(rc)) { return rc; };
    }

    // 处理having
    for (auto &having : select_sql.having) {
      rc = FieldExpr::build_field(having, tables[0], useless, useless);
      if(OB_FAIL(rc)) { return rc; };
    }

    for (auto &condition : select_sql.conditions) {
      rc = FieldExpr::build_field(condition, tables[0], useless, useless);
      if(OB_FAIL(rc)) { return rc; };
    }

  } else {
    for (int i = static_cast<int>(select_sql.attributes.size()) - 1; i >= 0; i--) {
      rc = FieldExpr::build_field(select_sql.attributes[i], table_map, has_attr, has_agg);
      if(OB_FAIL(rc)) { return rc; };
    }

    // 处理order by
    for (auto &order : select_sql.order) {
      rc = FieldExpr::build_field(order, table_map, useless, useless);
      if(OB_FAIL(rc)) { return rc; };
    }

    // 处理group by
    for (auto &group : select_sql.group) {
      rc = FieldExpr::build_field(group, table_map, useless, useless);
      if(OB_FAIL(rc)) { return rc; };
    }

    // 处理having
    for (auto &having : select_sql.having) {
      rc = FieldExpr::build_field(having, table_map, useless, useless);
      if(OB_FAIL(rc)) { return rc; };
    }

    for (auto &condition : select_sql.conditions) {
      rc = FieldExpr::build_field(condition, table_map, useless, useless);
      if(OB_FAIL(rc)) { return rc; };
    }
  }

  std::vector<std::unique_ptr<Expression>> order_expr;

  // collect query fields in `select` statement
  std::vector<std::unique_ptr<Expression>> query_expressions;
  // 倒序处理是因为yacc_sql.y中select语句的attributes是尾插的
  for (int i = static_cast<int>(select_sql.attributes.size()) - 1; i >= 0; i--) {
    Expression* relation_attr = select_sql.attributes[i];

    switch (relation_attr->type()) {
      case ExprType::STAR: {
        has_attr = true;
        auto star_expr = dynamic_cast<StarExpr *>(relation_attr);
        // 反向添加，避免后期join时的顺序错误
        if (star_expr->table_name().empty()) {
          for (int index = tables.size() - 1; index >= 0; --index) {
            wildcard_fields(tables[index], query_expressions, tables.size() != 1);
            // 处理order by的表达式
            wildcard_fields(tables[index], order_expr, tables.size() != 1);
          }
        } else {
          auto table = table_map[star_expr->table_name()];
          if (nullptr == table) {
            LOG_WARN("no such table. table_name=%s", star_expr->table_name().c_str());
            return RC::SCHEMA_TABLE_NOT_EXIST;
          }
          wildcard_fields(table, query_expressions, tables.size() != 1);
          // 处理order by的表达式
          wildcard_fields(table, order_expr, tables.size() != 1);
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

    // group by时已经在parser阶段判断过了
    if (select_sql.group.empty() && has_attr && has_agg) { return RC::SCHEMA_MIXED_QUERY; }
  }

  // 处理order by
  for (auto &expr : select_sql.order) {
    if (expr->type() != ExprType::FIELD) {
      LOG_WARN("Found unknown type %d", expr->type());
      continue;
    }
    order_expr.emplace_back(expr);
  }

  // 处理group by(包括 select attr + group attr + having expr)
  std::vector<std::unique_ptr<Expression>> group_expr;
  for (auto &expr : select_sql.group) {
    if (expr->type() != ExprType::FIELD
        && expr->type() != ExprType::FUNC
        && expr->type() != ExprType::CAST) {
      sql_debug("Found unknown type %d", expr->type());
      continue;
    }
    group_expr.emplace_back(expr);
  }

  // 处理having
  std::vector<std::unique_ptr<Expression>> having_expr;
  for (auto &expr : select_sql.having) {
    having_expr.emplace_back(expr);
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
  select_stmt->has_agg_ = has_agg && group_expr.empty();
  select_stmt->order_fields_.swap(order_expr);
  select_stmt->group_fields_.swap(group_expr);
  select_stmt->having_fields_.swap(having_expr);
  stmt = select_stmt;
  return RC::SUCCESS;
}
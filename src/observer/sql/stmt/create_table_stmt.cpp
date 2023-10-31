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
// Created by Wangyunlai on 2023/6/13.
//

#include "sql/stmt/create_table_stmt.h"
#include "sql/stmt/select_stmt.h"
#include "sql/expr/expression.h"
#include "event/sql_debug.h"

RC CreateTableStmt::create(Db *db, const CreateTableSqlNode &create_table, Stmt *&stmt)
{
  const auto *attr_infos = &create_table.attr_infos;
  Stmt *select_stmt = nullptr;
  std::vector<AttrInfoSqlNode> infos;
  if (create_table.select_node) {
    if (create_table.attr_infos.size() != 0) {
      LOG_ERROR("Error stmt.");
      return RC::INTERNAL;
    }
    SelectStmt::create(db, *create_table.select_node, select_stmt);
    for (const auto &attr : (reinterpret_cast<SelectStmt*>(select_stmt))->query_exprs()) {
      if (attr->type() != ExprType::FIELD) {
        LOG_ERROR("Unsupported attr type %d in create-table-select stmt", attr->type());
        return RC::UNIMPLENMENT;
      }
      const auto ptr = dynamic_cast<FieldExpr*>(attr.get());
      AttrInfoSqlNode attr_info;
      attr_info.name = ptr->field().meta()->name();
      attr_info.type = ptr->field().meta()->type();
      attr_info.length = ptr->field().meta()->len();
      attr_info.nullable = ptr->field().meta()->nullable();
      infos.emplace_back(attr_info);
    }
    attr_infos = &infos;
  }
  CreateTableStmt *create_stmt = new CreateTableStmt(create_table.relation_name, *attr_infos);
  sql_debug("create table statement: table name %s", create_table.relation_name.c_str());
  create_stmt->select_stmt_ = reinterpret_cast<SelectStmt*>(select_stmt);
  stmt = create_stmt;
  return RC::SUCCESS;
}

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

#include "sql/executor/create_table_executor.h"

#include "session/session.h"
#include "common/log/log.h"
#include "storage/table/table.h"
#include "sql/stmt/create_table_stmt.h"
#include "event/sql_event.h"
#include "event/session_event.h"
#include "storage/db/db.h"
#include "sql/operator/insert_physical_operator.h"

RC CreateTableExecutor::execute(SQLStageEvent *sql_event)
{
  Stmt *stmt = sql_event->stmt();
  Session *session = sql_event->session_event()->session();
  ASSERT(stmt->type() == StmtType::CREATE_TABLE, 
         "create table executor can not run this command: %d", static_cast<int>(stmt->type()));

  CreateTableStmt *create_table_stmt = static_cast<CreateTableStmt *>(stmt);

  const int attribute_count = static_cast<int>(create_table_stmt->attr_infos().size());

  const char *table_name = create_table_stmt->table_name().c_str();
  RC rc = session->get_current_db()->create_table(table_name, attribute_count, create_table_stmt->attr_infos().data());

  if (OB_FAIL(rc)) { return rc; }

  Table *table = session->get_current_db()->find_table(create_table_stmt->table_name().c_str());

  if (!table) {
    LOG_ERROR("Unable to find table %s.", create_table_stmt->table_name().c_str());
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  if (create_table_stmt->is_create_select()) {
    auto &phy_oper = sql_event->session_event()->sql_result()->get_operator();
    ASSERT(phy_oper, "No phy oper.");
    if (phy_oper->type() != PhysicalOperatorType::INSERT) {
      return rc;
    }
    // 设置operator的table指针
    auto oper = dynamic_cast<InsertPhysicalOperator*>(phy_oper.get());
    oper->set_table(table);
    rc = RC::CONTINUE;
  }

  return rc;
}
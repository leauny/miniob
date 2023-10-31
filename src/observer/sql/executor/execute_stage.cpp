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
// Created by Longda on 2021/4/13.
//

#include <string>
#include <sstream>

#include "sql/executor/execute_stage.h"

#include "common/log/log.h"
#include "session/session.h"
#include "event/storage_event.h"
#include "event/sql_event.h"
#include "event/session_event.h"
#include "sql/stmt/stmt.h"
#include "sql/stmt/select_stmt.h"
#include "storage/default/default_handler.h"
#include "sql/executor/command_executor.h"
#include "sql/operator/calc_physical_operator.h"
#include "sql/operator/project_physical_operator.h"

using namespace std;
using namespace common;

RC ExecuteStage::handle_request(SQLStageEvent *sql_event)
{
  RC rc = RC::SUCCESS;
  const unique_ptr<PhysicalOperator> &physical_operator = sql_event->physical_operator();
  if (physical_operator != nullptr) {
    rc = handle_request_with_physical_operator(sql_event);
    if (rc != RC::CONTINUE) {
      return rc;
    }
  }

  SessionEvent *session_event = sql_event->session_event();

  Stmt *stmt = sql_event->stmt();
  if (stmt != nullptr) {
    CommandExecutor command_executor;
    rc = command_executor.execute(sql_event);
    if (rc != RC::CONTINUE) {
      session_event->sql_result()->set_return_code(rc);
    } else {
      rc = RC::SUCCESS;
    }
  } else {
    return RC::INTERNAL;
  }
  return rc;
}

RC ExecuteStage::handle_request_with_physical_operator(SQLStageEvent *sql_event)
{
  RC rc = RC::SUCCESS;

  Stmt *stmt = sql_event->stmt();
  ASSERT(stmt != nullptr, "SQL Statement shouldn't be empty!");

  unique_ptr<PhysicalOperator> &physical_operator = sql_event->physical_operator();
  ASSERT(physical_operator != nullptr, "physical operator should not be null");

  TupleSchema schema;
  switch (stmt->type()) {
    case StmtType::SELECT: {
      const auto *oper = dynamic_cast<ProjectPhysicalOperator*>(physical_operator.get());
      for (int i = 0; i < oper->cell_num(); ++i) {
        if (!oper->alias_at(i).empty()) {
          schema.append_cell(oper->alias_at(i).c_str());
          continue;
        } else {
          schema.append_cell(oper->name_at(i).c_str());
        }
      }
    } break;

    case StmtType::CALC: {
      CalcPhysicalOperator *oper = static_cast<CalcPhysicalOperator *>(physical_operator.get());
      for (int i = 0; i < oper->cell_num(); ++i) {
        auto tuple = dynamic_cast<ExpressionTuple*>(oper->current_tuple());
        if (!tuple->alias_at(i).empty()) {
          schema.append_cell(tuple->alias_at(i).c_str());
          continue;
        } else {
          schema.append_cell(tuple->name_at(i).c_str());
        }
      }
    } break;

    case StmtType::CREATE_TABLE: {
      // create-table-select才会走到这个地方
      // 返回RC::CONTINUE让handle_request继续执行
      rc = RC::CONTINUE;
    } break;

    case StmtType::EXPLAIN: {
      schema.append_cell("Query Plan");
    } break;
    default: {
      // 只有select返回结果
    } break;
  }

  SqlResult *sql_result = sql_event->session_event()->sql_result();
  sql_result->set_tuple_schema(schema);
  sql_result->set_operator(std::move(physical_operator));
  return rc;
}

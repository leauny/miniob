//
// Created by leauny on 23-11-2.
//

#include "sql/executor/create_view_executor.h"
#include "sql/stmt/create_view_stmt.h"
#include "session/session.h"
#include "common/log/log.h"
#include "storage/table/table.h"
#include "event/sql_event.h"
#include "event/session_event.h"
#include "storage/db/db.h"

RC CreateViewExecutor::execute(SQLStageEvent *sql_event)
{
  Stmt *stmt = sql_event->stmt();
  Session *session = sql_event->session_event()->session();
  ASSERT(stmt->type() == StmtType::CREATE_VIEW,
      "create view executor can not run this command: %d", static_cast<int>(stmt->type()));

  CreateViewStmt *create_view_stmt = static_cast<CreateViewStmt *>(stmt);

  const int attribute_count = static_cast<int>(create_view_stmt->attr_infos().size());

  const char *table_name = create_view_stmt->table_name().c_str();

  std::string sql_tmp = sql_event->sql();
  std::transform(sql_tmp.begin(), sql_tmp.end(), sql_tmp.begin(), ::tolower);  // 转换为小写后调用find
  auto pos = sql_tmp.find("where");
  std::string condition = new char[sql_tmp.size()];
  if (pos != std::string::npos) {
    condition = sql_event->sql().substr(pos + 5).c_str();
    if (condition[condition.size() - 1] == ';') {
      condition[condition.size() - 1] = '\0';
    }
  } else {
    condition = "";
  }

  RC rc = session->get_current_db()->create_view(
      table_name, attribute_count, create_view_stmt->attr_infos().data(), condition.c_str());

  return rc;
}
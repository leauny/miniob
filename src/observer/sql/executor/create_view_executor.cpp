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

  auto base_tables = create_view_stmt->base_tables();

  std::string sql_tmp = sql_event->sql();
  std::transform(sql_tmp.begin(), sql_tmp.end(), sql_tmp.begin(), ::tolower);  // 转换为小写后调用find

  auto w_pos = sql_tmp.find("where");
  std::string condition = new char[sql_tmp.size()];
  if (w_pos != std::string::npos) {
    condition = sql_event->sql().substr(w_pos + 5).c_str();
    if (condition[condition.size() - 1] == ';') {
      condition[condition.size() - 1] = '\0';
    }
  } else {
    condition = "";
  }

  auto f_pos = sql_tmp.find("from");
  std::string from = new char[sql_tmp.size()];
  if (f_pos != std::string::npos) {
    size_t size = w_pos != std::string::npos ? w_pos - f_pos -4: -1;
    from = sql_event->sql().substr(f_pos + 4, size).c_str();
    if (from[from.size() - 1] == ';') {
      from[from.size() - 1] = '\0';
    }
  } else {
    from = "";
  }

  RC rc = session->get_current_db()->create_view(
      table_name, attribute_count, create_view_stmt->attr_infos().data(), condition.c_str(), from.c_str(), base_tables);

  return rc;
}
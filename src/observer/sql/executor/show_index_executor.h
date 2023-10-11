//
// Created by leauny on 23-10-11.
//

#pragma once

#include "common/rc.h"
#include "sql/operator/string_list_physical_operator.h"
#include "event/sql_event.h"
#include "event/session_event.h"
#include "sql/executor/sql_result.h"
#include "session/session.h"
#include "sql/stmt/show_index_stmt.h"
#include "storage/table/table.h"
#include "storage/index/index.h"

class ShowIndexExecutor
{
public:
  ShowIndexExecutor() = default;
  virtual ~ShowIndexExecutor() = default;

  RC execute(SQLStageEvent *sql_event)
  {
    SqlResult *sql_result = sql_event->session_event()->sql_result();

    // 设置表头
    TupleSchema tuple_schema;
    tuple_schema.append_cell(TupleCellSpec("", "Table", "Table"));
    tuple_schema.append_cell(TupleCellSpec("", "Non_unique", "Non_unique"));
    tuple_schema.append_cell(TupleCellSpec("", "Key_name", "Key_name"));
    tuple_schema.append_cell(TupleCellSpec("", "Seq_in_index", "Seq_in_index"));
    tuple_schema.append_cell(TupleCellSpec("", "Column_name", "Column_name"));
    sql_result->set_tuple_schema(tuple_schema);

    auto stmt = (ShowIndexStmt*)sql_event->stmt();
    auto table = stmt->table();
    std::vector<Index*> indexes = table->all_indexes();

    auto oper = new StringListPhysicalOperator;
    for (const auto &index : indexes) {
      oper->append({
          table->name(),
          "1",   // TODO: Unimplemented
          index->index_meta().name(),
          "1",   // TODO: Unimplemented
          index->index_meta().field()
      });
    }

    sql_result->set_operator(std::unique_ptr<PhysicalOperator>(oper));
    return RC::SUCCESS;
  }
};
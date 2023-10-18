//
// Created by leauny on 23-10-11.
//

#pragma once

#include "common/rc.h"
#include "sql/stmt/stmt.h"
#include "storage/db/db.h"

class Db;

class ShowIndexStmt : public Stmt
{
public:
  ShowIndexStmt() = default;
  virtual ~ShowIndexStmt() = default;

  StmtType type() const override { return StmtType::SHOW_INDEX; }

  static RC create(Db *db, const ShowIndexSqlNode &show_index, Stmt *&stmt)
  {
    if (nullptr == db) {
      LOG_WARN("invalid argument. db is null");
      return RC::INVALID_ARGUMENT;
    }

    // collect tables in `from` statement
    std::vector<Table *> tables;
    std::unordered_map<std::string, Table *> table_map;
    const char *table_name = show_index.relation_name.c_str();
    if (nullptr == table_name) {
      LOG_WARN("invalid argument. relation name is null.");
      return RC::INVALID_ARGUMENT;
    }

    Table *table = db->find_table(table_name);
    if (nullptr == table) {
      LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
      return RC::SCHEMA_TABLE_NOT_EXIST;
    }

    auto *show_index_stmt = new ShowIndexStmt();
    show_index_stmt->table_ = table;
    stmt = show_index_stmt;
    return RC::SUCCESS;
  }

  Table *table() const { return table_; }

private:
    Table * table_;
};
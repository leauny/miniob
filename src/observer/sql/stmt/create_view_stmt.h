//
// Created by leauny on 23-11-2.
//

#ifndef MINIDB_CREATEVIEWSTMT_H
#define MINIDB_CREATEVIEWSTMT_H

#pragma once

#include <string>
#include <vector>

#include "sql/stmt/stmt.h"
#include "storage/table/table.h"

class Db;
class SelectStmt;

class CreateViewStmt : public Stmt
{
public:
  CreateViewStmt(const std::string &table_name, std::vector<ViewInfoSqlNode>&& attr_infos, std::vector<Table*> tables)
      : table_name_(table_name),
        attr_infos_(std::move(attr_infos)),
        tables_(tables)
  {}
  virtual ~CreateViewStmt() = default;

  StmtType type() const override { return StmtType::CREATE_VIEW; }

  const std::string &table_name() const { return table_name_; }
  const std::vector<Table *> base_tables() const { return tables_; }
  const std::vector<ViewInfoSqlNode> &attr_infos() const { return attr_infos_; }

  static RC create(Db *db, const CreateViewSqlNode &create_table, Stmt *&stmt);

  SelectStmt *select_stmt() { return select_stmt_; }

private:
  std::string table_name_;
  std::vector<Table*> tables_;
  std::vector<ViewInfoSqlNode> attr_infos_;
  SelectStmt *select_stmt_ = nullptr;
};

#endif  // MINIDB_CREATEVIEWSTMT_H

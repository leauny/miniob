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
// Created by Wangyunlai on 2022/6/5.
//

#pragma once

#include <vector>
#include <memory>

#include "common/rc.h"
#include "sql/stmt/stmt.h"
#include "storage/field/field.h"

class FieldMeta;
class FilterStmt;
class Db;
class Table;

/**
 * @brief 表示select语句
 * @ingroup Statement
 */
class SelectStmt : public Stmt 
{
public:
  SelectStmt() = default;
  ~SelectStmt() override;

  StmtType type() const override
  {
    return StmtType::SELECT;
  }

public:
  static RC create(Db *db, const SelectSqlNode &select_sql, Stmt *&stmt);

public:
  const std::vector<Table *> &tables() const
  {
    return tables_;
  }
  std::vector<std::unique_ptr<Expression>> &query_exprs()
  {
    return query_exprs_;
  }
  std::vector<std::unique_ptr<Expression>> &order_fields()
  {
    return order_fields_;
  }
  std::vector<std::unique_ptr<Expression>> &group_fields()
  {
    return group_fields_;
  }
  std::vector<std::unique_ptr<Expression>> &having_fields()
  {
    return having_fields_;
  }
  FilterStmt *filter_stmt() const
  {
    return filter_stmt_;
  }
  bool get_agg() { return has_agg_; }

private:
  std::vector<std::unique_ptr<Expression>> query_exprs_;
  // order by和group by的处理逻辑类似，默认不会同时出现两种情况
  /*
   * order_fields = query_exprs_ + order attr,
   */
  std::vector<std::unique_ptr<Expression>> order_fields_;
  /*
   * group_fields = query_exprs_ + group attr + having的field_expr
   */
  std::vector<std::unique_ptr<Expression>> group_fields_;
  std::vector<std::unique_ptr<Expression>> having_fields_;

  std::vector<Table *> tables_;
  bool has_agg_;
  FilterStmt *filter_stmt_ = nullptr;
};

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
// Created by Wangyunlai on 2022/5/22.
//

#pragma once

#include <vector>
#include <unordered_map>
#include "sql/parser/parse_defs.h"
#include "sql/stmt/stmt.h"
#include "sql/expr/expression.h"

class Db;
class Table;
class FieldMeta;
class SelectStmt;

struct FilterObj 
{
  bool is_attr;
  Field field;
  Value value;

  void init_attr(const Field &field)
  {
    is_attr = true;
    this->field = field;
  }

  void init_value(const Value &value)
  {
    is_attr = false;
    this->value = value;
  }
};

class FilterUnit 
{
public:
  FilterUnit() = default;
  ~FilterUnit()
  {}

  void set_comp(CompOp comp)
  {
    comp_ = comp;
  }

  CompOp comp() const
  {
    return comp_;
  }

  void set_left(const FilterObj &obj)
  {
    left_ = obj;
  }
  void set_right(const FilterObj &obj)
  {
    right_ = obj;
  }

  const FilterObj &left() const
  {
    return left_;
  }
  const FilterObj &right() const
  {
    return right_;
  }

private:
  CompOp comp_ = NO_OP;
  FilterObj left_;
  FilterObj right_;
};

/**
 * @brief Filter/谓词/过滤语句
 * @ingroup Statement
 */
class FilterStmt 
{
public:
  FilterStmt() = default;
  virtual ~FilterStmt();

public:
  const std::vector<Expression *> &filter_units() const
  {
    return filter_units_;
  }

public:
  // TODO: 将ConditionSqlNode转换为FilterUnit
  static RC create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
      const std::vector<Expression*> conditions, FilterStmt *&stmt);

  static RC create_filter_unit(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
      Expression *condition, FilterUnit *&filter_unit);

private:
  // TODO: 改为Expression, 直接在解析层面创建ast
  std::vector<Expression *> filter_units_;  // 默认当前都是AND关系
  Expression* filter_expr_ = nullptr;       // 将数组中的ConjunctionExpr合并为一个ConjunctionExpr
};

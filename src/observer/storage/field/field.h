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
// Created by Wangyunlai on 2022/07/05.
//

#pragma once

#include <utility>

#include "storage/table/table.h"
#include "storage/field/field_meta.h"

/**
 * @brief 字段
 * 
 */
class Field 
{
public:
  Field() = default;
  Field(const Table *table, const FieldMeta *field) : table_(table), field_(field)
  {}
  Field(const Table *table, const FieldMeta *field, const FuncType type, std::string func_parm)
      : table_(table), field_(field), function_(type), func_parm_(std::move(func_parm)) {}
  Field(const Field &) = default;

  const Table *table() const
  {
    return table_;
  }
  const FieldMeta *meta() const
  {
    return field_;
  }

  AttrType attr_type() const
  {
    return field_->type();
  }

  FuncType func_type() const
  {
    return function_;
  }

  void set_func_type(FuncType type) {
    function_ = type;
  }

  std::string func_parm() const
  {
    return func_parm_;
  }

  void set_func_parm(const std::string &parm) {
    func_parm_ = parm;
  }

  const char *table_name() const
  {
    return table_->name();
  }
  const char *field_name() const
  {
    return field_->name();
  }

  void set_table(const Table *table)
  {
    this->table_ = table;
  }
  void set_field(const FieldMeta *field)
  {
    this->field_ = field;
  }
  void set_alias(const std::string& alias)
  {
    this->alias_ = alias;
  }
  void set_int(Record &record, int value);
  int  get_int(const Record &record);
  const char *get_alias() const;

  const char *get_data(const Record &record);

private:
  const Table *table_ = nullptr;
  const FieldMeta *field_ = nullptr;
  FuncType         function_ = FUNC_NONE;
  std::string      func_parm_;
  std::string      alias_;
};

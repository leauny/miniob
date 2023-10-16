/* Copyright (c) 2021OceanBase and/or its affiliates. All rights reserved.
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

#include <cmath>
#include <string>
#include <sstream>
#include "sql/stmt/insert_stmt.h"
#include "common/log/log.h"
#include "storage/db/db.h"
#include "storage/table/table.h"

InsertStmt::InsertStmt(Table *table, const std::vector<std::vector<Value>> *values)
    : table_(table), values_(values)
{}

RC InsertStmt::create(Db *db, const InsertSqlNode &inserts, Stmt *&stmt)
{
  const char *table_name = inserts.relation_name.c_str();
  if (nullptr == db || nullptr == table_name || inserts.values.empty()) {
    LOG_WARN("invalid argument. db=%p, table_name=%p, value_num=%d",
        db, table_name, static_cast<int>(inserts.values.size()));
    return RC::INVALID_ARGUMENT;
  }

  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  const std::vector<std::vector<Value>> *values = &inserts.values;
  const int        values_num  = static_cast<int>(values->size());
  const TableMeta &table_meta = table->table_meta();
  const int        field_num  = table_meta.field_num() - table_meta.sys_field_num();
  for (const auto &value : *values) {
    // check the fields number
    int value_num = static_cast<int>(value.size());
    if (field_num != value_num) {
      LOG_WARN("schema mismatch. value num=%d, field num in schema=%d", value_num, field_num);
      return RC::SCHEMA_FIELD_MISSING;
    }

    // check fields type
    const int sys_field_num = table_meta.sys_field_num();
    std::vector<Value> &mutable_value = const_cast<std::vector<Value> &>(value);
    for (int i = 0; i < value_num; i++) {
      const FieldMeta *field_meta = table_meta.field(i + sys_field_num);
      const AttrType   field_type = field_meta->type();
      const AttrType   value_type = value[i].attr_type();
      if (field_type != value_type) {
        if (field_meta->nullable() && value_type == NULLS) {
          continue;
        }
        if (field_type == CHARS) {
          const char* data = value[i].get_string().c_str();
          mutable_value[i].set_string(data, strlen(data));
        } else if (field_type == INTS) {
          int data;
          switch (value_type)
          {
            case CHARS:{
              std::string v = (char *)value[i].data();
              if(!('0' <= v[0] && v[0] <= '9')) {
                data = 0;
              } else {
                data = std::stoi(v);
              }
            }  break;
            case FLOATS:{
              float v = *(float *) value[i].data();
              data = (int) std::round(v);
            }  break;
          }
          mutable_value[i].set_int(data);
        } else if (field_type == FLOATS) {
          float data;
          switch (value_type)
          {
            case CHARS:{
              std::string v = (char *)value[i].data();
              if(!(('0' <= v[0] && v[0] <= '9') ||(v[0] == '.'))) {
                data = 0;
              } else {
                data = std::stof(v);
              }
            }  break;
            case INTS:{
              int v = *(int *) value[i].data();
              data = (float) v;
            }  break;  
          }
          mutable_value[i].set_float(data);
        } 
        else {
          LOG_WARN("field type mismatch. table=%s, field=%s, field type=%d, value_type=%d",
          table_name, field_meta->name(), field_type, value_type);
          return RC::SCHEMA_FIELD_TYPE_MISMATCH;
        }
      }

      // check the date valid
      if (value_type == DATES) {
        auto dates = value[i].get_date();
        if (!dates.ok()) {
          LOG_WARN("date is invalid, table=%s, value_type=%d",table_name, value_type);
          return RC::VARIABLE_NOT_VALID;
        }
      }
    }
  }
  // everything alright
  stmt = new InsertStmt(table, values);
  return RC::SUCCESS;
}

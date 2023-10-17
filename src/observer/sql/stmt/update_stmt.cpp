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

#include <cmath>
#include "sql/stmt/update_stmt.h"
#include "common/log/log.h"
#include "storage/db/db.h"
#include "storage/table/table.h"
#include "sql/stmt/filter_stmt.h"

UpdateStmt::UpdateStmt(Table *table, const std::vector<std::pair<Value, int>>& valuesAndOffsets, FilterStmt *filterStmt)
    : table_(table), values_and_offsets_(valuesAndOffsets), filter_stmt_(filterStmt) {}

RC UpdateStmt::create(Db *db, const UpdateSqlNode &update, Stmt *&stmt)
{
  const char *table_name = update.relation_name.c_str();
  if (nullptr == db || nullptr == table_name) {
    LOG_WARN("invalid argument. db=%p, table_name=%p", db, table_name);
    return RC::INVALID_ARGUMENT;
  }

  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  std::vector<std::pair<Value, int>> values_and_offsets;
  const TableMeta &table_meta = table->table_meta();
  auto& mutable_update_fields = const_cast<std::vector<std::pair<std::string, Value>>&>(update.update_fields);
  for (auto& [attribute_name, value] : mutable_update_fields) {
    const FieldMeta *field_meta = table_meta.field(attribute_name.c_str());
    if (field_meta == nullptr) {
      LOG_WARN("field type mismatch. the attribute name %s is not in table %s",
              attribute_name.c_str(), table_name);
      return RC::SCHEMA_FIELD_NOT_EXIST;
    }

    const AttrType field_type = field_meta->type();
    AttrType value_type = value.attr_type();
    if (field_type != value_type) {
      if (field_meta->nullable() && value_type == NULLS) {
        // do nothing, skip the type check and convert
      } else if (field_type == CHARS) {
        const char* data = value.get_string().c_str();
        value.set_string(data, strlen(data));
      } else if (field_type == INTS) {
        int data;
        switch (value_type)
        {
          case CHARS:{
            std::string v = (char *)value.data();
            if(!('0' <= v[0] && v[0] <= '9')) {
              data = 0;
            } else {
              data = std::stoi(v);
            }
          }  break;
          case FLOATS:{
            float v = *(float *) value.data();
            data = (int) std::round(v);
          }  break;
        }
        value.set_int(data);
      } else if (field_type == FLOATS) {
        float data;
        switch (value_type)
        {
          case CHARS:{
            std::string v = (char *)value.data();
            if(!(('0' <= v[0] && v[0] <= '9') ||(v[0] == '.'))) {
              data = 0;
            } else {
              data = std::stof(v);
            }
          }  break;
          case INTS:{
            int v = *(int *) value.data();
            data = (float) v;
          }  break;
        }
        value.set_float(data);
      }
      else {
        LOG_WARN("field type mismatch. table=%s, field=%s, field type=%d, value_type=%d",
          table_name, field_meta->name(), field_type, value_type);
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
      }
    }

    // check the date valid
    if (value_type == DATES) {
      auto dates = value.get_date();
      if (!dates.ok()) {
        LOG_WARN("date is invalid, table=%s, value_type=%d",table_name, value_type);
        return RC::VARIABLE_NOT_VALID;
      }
    }

    // everything is ok, append it in values_and_offsets
    values_and_offsets.emplace_back(value, field_meta->offset());
  }

  std::unordered_map<std::string, Table *> table_map;
  table_map.insert(std::pair<std::string, Table *>(std::string(table_name), table));

  FilterStmt *filter_stmt = nullptr;
  RC rc = FilterStmt::create(
      db, table, &table_map, update.conditions.data(), static_cast<int>(update.conditions.size()), filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create filter statement. rc=%d:%s", rc, strrc(rc));
    return rc;
  }
  // everything alright
  stmt = new UpdateStmt(table, values_and_offsets, filter_stmt);
  return RC::SUCCESS;
}

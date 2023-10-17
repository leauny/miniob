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
#include "common/rc.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/db/db.h"
#include "storage/table/table.h"

FilterStmt::~FilterStmt()
{
  for (FilterUnit *unit : filter_units_) {
    delete unit;
  }
  filter_units_.clear();
}

RC FilterStmt::create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const ConditionSqlNode *conditions, int condition_num, FilterStmt *&stmt)
{
  RC rc = RC::SUCCESS;
  stmt = nullptr;

  FilterStmt *tmp_stmt = new FilterStmt();
  for (int i = 0; i < condition_num; i++) {
    FilterUnit *filter_unit = nullptr;
    rc = create_filter_unit(db, default_table, tables, conditions[i], filter_unit);
    if (rc != RC::SUCCESS) {
      delete tmp_stmt;
      LOG_WARN("failed to create filter unit. condition index=%d", i);
      return rc;
    }
    tmp_stmt->filter_units_.push_back(filter_unit);
  }

  stmt = tmp_stmt;
  return rc;
}

RC get_table_and_field(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const RelAttrSqlNode &attr, Table *&table, const FieldMeta *&field)
{
  if (common::is_blank(attr.relation_name.c_str())) {
    table = default_table;
  } else if (nullptr != tables) {
    auto iter = tables->find(attr.relation_name);
    if (iter != tables->end()) {
      table = iter->second;
    }
  } else {
    table = db->find_table(attr.relation_name.c_str());
  }
  if (nullptr == table) {
    LOG_WARN("No such table: attr.relation_name: %s", attr.relation_name.c_str());
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  field = table->table_meta().field(attr.attribute_name.c_str());
  if (nullptr == field) {
    LOG_WARN("no such field in table: table %s, field %s", table->name(), attr.attribute_name.c_str());
    table = nullptr;
    return RC::SCHEMA_FIELD_NOT_EXIST;
  }

  return RC::SUCCESS;
}

RC FilterStmt::create_filter_unit(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const ConditionSqlNode &condition, FilterUnit *&filter_unit)
{
  RC rc = RC::SUCCESS;

  CompOp comp = condition.comp;
  if (comp < EQUAL_TO || comp >= NO_OP) {
    LOG_WARN("invalid compare operator : %d", comp);
    return RC::INVALID_ARGUMENT;
  }

  filter_unit = new FilterUnit;

  if (condition.left_is_attr) {
    Table *table = nullptr;
    const FieldMeta *field = nullptr;
    rc = get_table_and_field(db, default_table, tables, condition.left_attr, table, field);
    if (rc != RC::SUCCESS) {
      LOG_WARN("cannot find attr");
      return rc;
    }
    FilterObj filter_obj;
    filter_obj.init_attr(Field(table, field));
    filter_unit->set_left(filter_obj);
  } else {
    if (condition.left_value.attr_type() == DATES && !condition.left_value.get_date().ok()) {
      LOG_WARN("invalid date value");
      return RC::INVALID_ARGUMENT;
    }
    FilterObj filter_obj;
    filter_obj.init_value(condition.left_value);
    filter_unit->set_left(filter_obj);
  }

  if (condition.right_is_attr) {
    Table *table = nullptr;
    const FieldMeta *field = nullptr;
    rc = get_table_and_field(db, default_table, tables, condition.right_attr, table, field);
    if (rc != RC::SUCCESS) {
      LOG_WARN("cannot find attr");
      return rc;
    }
    FilterObj filter_obj;
    filter_obj.init_attr(Field(table, field));
    filter_unit->set_right(filter_obj);
  } else {
    if (condition.right_value.attr_type() == DATES && !condition.right_value.get_date().ok()) {
      LOG_WARN("invalid date value");
      return RC::INVALID_ARGUMENT;
    }
    FilterObj filter_obj;
    filter_obj.init_value(condition.right_value);
    filter_unit->set_right(filter_obj);
  }

  filter_unit->set_comp(comp);

  // 检查两个类型是否能够比较, 仅考虑左field，右value的情况
  if (filter_unit->left().is_attr && !filter_unit->right().is_attr) {
    const FieldMeta* left = filter_unit->left().field.meta();
    FilterObj right = filter_unit->right();
    AttrType type_left = left->type();
    AttrType type_right = right.value.attr_type();

    if (type_left != type_right) {
      if (type_left == NULLS || type_right == NULLS) {
        // do nothing, skip the type check and convert
      } else if (!left->nullable() && type_right == NULLS) {
        LOG_WARN("field type mismatch, field=%s, field type=%d, value_type=%d",
              left->name(), type_left, type_right);
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;return RC::SCHEMA_FIELD_TYPE_MISMATCH;
      } else if (type_left == CHARS) {
        const char *data = right.value.get_string().c_str();
        right.value.set_string(data, strlen(data));
      } else if (type_left == INTS) {
        int data;
        switch (type_right) {
          case CHARS: {
            std::string v = (char *)right.value.data();
            if (!('0' <= v[0] && v[0] <= '9')) {
              data = 0;
            } else {
              data = std::stoi(v);
            }
          } break;
          case FLOATS: {
            float v = *(float *)right.value.data();
            data    = (int)std::round(v);
          } break;
        }
        right.value.set_int(data);
      } else if (type_left == FLOATS) {
        float data;
        switch (type_right) {
          case CHARS: {
            std::string v = (char *)right.value.data();
            if (!(('0' <= v[0] && v[0] <= '9') || (v[0] == '.'))) {
              data = 0;
            } else {
              data = std::stof(v);
            }
          } break;
          case INTS: {
            int v = *(int *)right.value.data();
            data  = (float)v;
          } break;
        }
        right.value.set_float(data);
      } else {
        LOG_WARN("field type mismatch, field=%s, field type=%d, type_right=%d",
        type_left, type_left, type_right);
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
      }
    }
  }
  return rc;
}
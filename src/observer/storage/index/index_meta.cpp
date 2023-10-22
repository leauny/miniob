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
// Created by Wangyunlai.wyl on 2021/5/18.
//

#include "storage/index/index_meta.h"
#include "storage/field/field_meta.h"
#include "storage/table/table_meta.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "json/json.h"

const static Json::StaticString FIELD_NAME("name");
const static Json::StaticString FIELD_FIELD_NAMES("field_name");         

RC IndexMeta::init(const char *name, const FieldMeta &field)
{
  if (common::is_blank(name)) {
    LOG_ERROR("Failed to init index, name is empty.");
    return RC::INVALID_ARGUMENT;
  }

  name_ = name;
  field_ = field.name();
  return RC::SUCCESS;
}

RC IndexMeta::init(const char *name, const std::vector<const FieldMeta *> &fields) {
  if (common::is_blank(name)) {
    LOG_ERROR("Failed to init index, name is empty.");
    return RC::INVALID_ARGUMENT;
  }

  name_ = name;
  for (auto &field : fields) {
    fields_.emplace_back(field->name());
  }
  field_ = fields_[0];
  return RC::SUCCESS;
}

const char *IndexMeta::name() const
{
  return name_.c_str();
}

const char *IndexMeta::field() const
{
  return field_.c_str();
}

const std::vector<std::string>& IndexMeta::fields() const
{
  return fields_;
}

void IndexMeta::desc(std::ostream &os) const
{
  os << "index name=" << name_ << ", fields=";
  for (auto &field : fields_) {
    os << field << ",";
  }
  os.seekp(-1, std::ios_base::end);
}

void IndexMeta::to_json(Json::Value &json_value) const
{
  json_value[FIELD_NAME] = name_;
  Json::Value field_names(Json::arrayValue);
  for (auto &field : fields_) {
    field_names.append(field);
  }
  json_value[FIELD_FIELD_NAMES] = field_names;
}

RC IndexMeta::from_json(const TableMeta &table, const Json::Value &json_value, IndexMeta &index)
{
  const Json::Value &name_value = json_value[FIELD_NAME];
  const Json::Value &field_names_value = json_value[FIELD_FIELD_NAMES];
  if (!name_value.isString()) {
    LOG_ERROR("Index name is not a string. json value=%s", name_value.toStyledString().c_str());
    return RC::INTERNAL;
  }

  if (!field_names_value.isArray()) {
    LOG_ERROR("Field names of index [%s] is not an array. json value=%s",
        name_value.asCString(),
        field_names_value.toStyledString().c_str());
    return RC::INTERNAL;
  }

  std::vector<const FieldMeta *> fields;
  for (Json::ArrayIndex i = 0; i < field_names_value.size(); ++i) {
    const Json::Value &field_name_value = field_names_value[i];
    if (!field_name_value.isString()) {
      LOG_ERROR("Field name of index [%s] is not a string. json value=%s",
          name_value.asCString(),
          field_name_value.toStyledString().c_str());
      return RC::INTERNAL;
    }

    const FieldMeta *field = table.field(field_name_value.asCString());
    if (nullptr == field) {
      LOG_ERROR("Deserialize index [%s]: no such field: %s", name_value.asCString(), field_name_value.asCString());
      return RC::SCHEMA_FIELD_MISSING;
    }

    fields.emplace_back(field);
  }

  if (fields.size() == 1) {
    return index.init(name_value.asCString(), *fields[0]);
  } else {
    return index.init(name_value.asCString(), fields);
  }
}

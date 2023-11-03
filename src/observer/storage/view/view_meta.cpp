//
// Created by leauny on 23-11-3.
//

#include <algorithm>
#include <common/lang/string.h>

#include "storage/view/view_meta.h"
#include "json/json.h"
#include "common/log/log.h"
#include "storage/trx/trx.h"
#include "event/sql_debug.h"

using namespace std;

static const Json::StaticString FIELD_VIEW_ID("view_id");
static const Json::StaticString FIELD_VIEW_NAME("view_name");
static const Json::StaticString FIELD_FIELDS("fields");
static const Json::StaticString FIELD_RELATIONS("tables");
static const Json::StaticString FIELD_CONDITION("conditions");
static const Json::StaticString FIELD_MUTABLE("mutable");

ViewMeta::ViewMeta(const ViewMeta &other)
    : table_id_(other.table_id_),
      name_(other.name_),
      fields_(other.fields_),
      conditions_(other.conditions_),
      tables_(other.tables_)
{}

void ViewMeta::swap(ViewMeta &other) noexcept
{
  name_.swap(other.name_);
  fields_.swap(other.fields_);
  conditions_.swap(other.conditions_);
  tables_.swap(other.tables_);
}

RC ViewMeta::init(
    const std::unordered_map<std::string, Table *> &opened_tables,
    int32_t view_id,
    const char *name,
    int field_num,
    const ViewInfoSqlNode attributes[],
    const char * conditions)
{
  if (common::is_blank(name)) {
    LOG_ERROR("Name cannot be empty");
    return RC::INVALID_ARGUMENT;
  }

  if (field_num <= 0 || nullptr == attributes) {
    LOG_ERROR("Invalid argument. name=%s, attr_num=%d, attributes=%p", name, field_num, attributes);
    return RC::INVALID_ARGUMENT;
  }

  fields_.resize(field_num);
  for (int i = 0; i < field_num; i++) {
    const ViewInfoSqlNode &attr_info = attributes[i];
    sql_debug("Got view field: name(%s), base(%s), rel(%s)."
        , attr_info.name.c_str(), attr_info.base_name.c_str(), attr_info.relation_name.c_str());
    if (attr_info.base_name.find("(") != std::string::npos) {
      mutable_ = false;
    }
    fields_[i] = ViewFieldMata(i, attr_info.name, attr_info.base_name, attr_info.relation_name);
    if (opened_tables.count(attr_info.relation_name) <= 0) {
      LOG_ERROR("Unknown table %d.", attr_info.relation_name.c_str());
      return RC::INTERNAL;
    }
    tables_[attr_info.relation_name] = opened_tables.at(attr_info.relation_name);  // 插入表，但没有指针，需要open
  }

  table_id_ = view_id;
  name_     = name;
  conditions_ = conditions;
  LOG_INFO("Sussessfully initialized view meta. view_id=%d, name=%s", view_id, name);
  return RC::SUCCESS;
}

int ViewMeta::serialize(std::ostream &ss) const
{

  Json::Value view_value;
  view_value[FIELD_VIEW_ID]   = table_id_;
  view_value[FIELD_VIEW_NAME] = name_;
  view_value[FIELD_CONDITION] = conditions_;
  view_value[FIELD_MUTABLE] = mutable_;

  Json::Value fields_value;
  for (const ViewFieldMata& field : fields_) {
    Json::Value field_value;
    field.to_json(field_value);
    fields_value.append(std::move(field_value));
  }

  view_value[FIELD_FIELDS] = std::move(fields_value);

  Json::Value tables_value;
  for (const auto &[name, _] : tables_) {
    tables_value.append(name);
  }

  view_value[FIELD_RELATIONS] = std::move(tables_value);

  Json::StreamWriterBuilder builder;
  Json::StreamWriter *writer = builder.newStreamWriter();

  std::streampos old_pos = ss.tellp();
  writer->write(view_value, &ss);
  int ret = (int)(ss.tellp() - old_pos);

  delete writer;
  return ret;
}

int ViewMeta::deserialize(std::istream &is)
{
  Json::Value table_value;
  Json::CharReaderBuilder builder;
  std::string errors;

  std::streampos old_pos = is.tellg();
  if (!Json::parseFromStream(builder, is, &table_value, &errors)) {
    LOG_ERROR("Failed to deserialize table meta. error=%s", errors.c_str());
    return -1;
  }

  const Json::Value &table_id_value = table_value[FIELD_VIEW_ID];
  if (!table_id_value.isInt()) {
    LOG_ERROR("Invalid table id. json value=%s", table_id_value.toStyledString().c_str());
    return -1;
  }

  int32_t table_id = table_id_value.asInt();

  const Json::Value &is_mutable = table_value[FIELD_MUTABLE];
  if (!is_mutable.isBool()) {
    LOG_ERROR("Invalid mutable flag. json value=%s", is_mutable.toStyledString().c_str());
    return -1;
  }

  bool mutable_value = is_mutable.asBool() == 1;

  const Json::Value &table_name_value = table_value[FIELD_VIEW_NAME];
  if (!table_name_value.isString()) {
    LOG_ERROR("Invalid table name. json value=%s", table_name_value.toStyledString().c_str());
    return -1;
  }

  std::string table_name = table_name_value.asString();

  const Json::Value &conditions_value = table_value[FIELD_CONDITION];
  if (!conditions_value.isString()) {
    LOG_ERROR("Invalid view condition. json value=%s", conditions_value.toStyledString().c_str());
    return -1;
  }

  std::string conditions = conditions_value.asString();

  const Json::Value &fields_value = table_value[FIELD_FIELDS];
  if (!fields_value.isArray() || fields_value.size() <= 0) {
    LOG_ERROR("Invalid table meta. fields is not array, json value=%s", fields_value.toStyledString().c_str());
    return -1;
  }

  RC rc = RC::SUCCESS;
  int field_num = fields_value.size();
  std::vector<ViewFieldMata> fields(field_num);
  for (int i = 0; i < field_num; i++) {
    ViewFieldMata &field = fields[i];

    const Json::Value &field_value = fields_value[i];
    rc = ViewFieldMata::from_json(field_value, field);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Failed to deserialize view meta. table name =%s", table_name.c_str());
      return -1;
    }
  }

  auto comparator = [](const ViewFieldMata &f1, const ViewFieldMata &f2) { return f1.index() < f2.index(); };
  std::sort(fields.begin(), fields.end(), comparator);

  const Json::Value &relations_value = table_value[FIELD_RELATIONS];
  if (!relations_value.isArray() || relations_value.size() <= 0) {
    LOG_ERROR("Invalid view meta. relation is not array, json value=%s", relations_value.toStyledString().c_str());
    return -1;
  }

  int relation_num = relations_value.size();
  std::unordered_map<std::string, Table*> tables;
  for (int i = 0; i < relation_num; i++) {
    const Json::Value &relation_name = relations_value[i];
    // 获取表名Failed to create table
    if (!relation_name.isString()) {
      LOG_ERROR("Invalid view relation name. json value=%s", relation_name.toStyledString().c_str());
      return -1;
    }
    auto name = relation_name.asString();
    if (tables.count(name) != 0) {
      LOG_ERROR("Duplicate relation %s in view. ", name.c_str());
      return -1;
    }
    tables[name] = nullptr;  // 暂时存储nullptr，后期添加表指针
  }

  table_id_ = table_id;
  name_.swap(table_name);
  fields_.swap(fields);
  conditions_.swap(conditions);
  tables_.swap(tables);
  mutable_ = mutable_value;

  return (int)(is.tellg() - old_pos);
}

int ViewMeta::record_size() const {
  if (tables_.size() == 1) {
    return tables_.begin()->second->table_meta().record_size();
  } else {
    return 0;
  }
}

bool ViewMeta::is_mutable()
{
  return mutable_;
}

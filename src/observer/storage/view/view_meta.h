//
// Created by leauny on 23-11-3.
//

#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "common/rc.h"
#include "storage/field/field_meta.h"
#include "storage/index/index_meta.h"
#include "common/lang/serializable.h"

class Table;

/**
 * @brief 视图元数据
 *
 */
class ViewMeta : public common::Serializable
{
public:
  ViewMeta() = default;
  ~ViewMeta() = default;

  ViewMeta(const ViewMeta &other);

  void swap(ViewMeta &other) noexcept;

  RC init(int32_t view_id, const char *name, int attr_num, const ViewInfoSqlNode attributes[], const char * conditions);

public:
  int32_t table_id() const { return table_id_; }
  const char *name() const { return name_.c_str(); }
  int record_size() const;  // 仅单表视图支持

  int get_serial_size() const override { return -1; }
  void to_string(std::string &output) const override {}

  std::unordered_map<std::string , Table*> tables() { return tables_; }
  bool is_mutable();

public:
  int serialize(std::ostream &os) const override;
  int deserialize(std::istream &is) override;

protected:
  bool mutable_{true};  // 多表或出现聚集函数时无法修改
  std::string name_;
  int32_t table_id_ = -1;
  std::string conditions_;
  std::vector<ViewFieldMata> fields_;
  std::unordered_map<std::string, Table*> tables_;
};

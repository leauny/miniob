//
// Created by jacky on 2023/10/10.
//

#ifndef MINIDB_UPDATE_FIELD_H
#define MINIDB_UPDATE_FIELD_H
#include <iostream>
#include <string>
#include "sql/parser/value.h"
#include "sql/parser/parse_defs.h"

class ParsedSqlNode;
class ConditionSqlNode;

struct UpdateField {

  std::string field_name;
  Value value;  // 使用通用的 Value 类型表示字段的值

  // 如果字段的值是子查询，可以添加一个标志来表示它是子查询类型
  bool is_subquery;

  // 如果是子查询，可以添加一个表示子查询的结构
  ParsedSqlNode* subquery;

  // 构造函数用于初始化普通值的字段
  UpdateField(const std::string& name, const Value& val)
      : field_name(name), value(val), is_subquery(false) {}

  // 构造函数用于初始化子查询值的字段
  UpdateField(const std::string& name, ParsedSqlNode* subq)
      : field_name(name), subquery(subq), is_subquery(true) {}
};

/**
 * @brief 描述一个update语句
 * @ingroup SQLParser
 */
struct UpdateSqlNode
{
  std::string                   relation_name;         ///< Relation to update
  std::vector<UpdateField>      parser_update_fields;  /// 混合存储更新字段，更新值以及子查询
  std::vector<std::pair<std::string, Value>>   update_fields; // 存储要更新的字段和值
  std::vector<ConditionSqlNode> conditions;
};

#endif  // MINIDB_UPDATE_FIELD_H

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

#include <cmath>
#include "sql/expr/expression.h"
#include "sql/expr/tuple.h"
#include "sql/operator/physical_operator.h"
#include "storage/db/db.h"

class PhysicalOperator;

using namespace std;

RC FieldExpr::get_value(const Tuple *tuple, Value &value)
{
  if (related_) {
    value = *related_value_;
    return RC::SUCCESS;
  }
  if (tuple) {
    if (tuple->type() == TupleType::VALUE && value.attr_type() == INTS) {
      // Value存储的是index，用于传递信息保持接口统一
      return tuple->cell_at(value.get_int(), value);
    }
    return tuple->find_cell(TupleCellSpec(table_name(), field_name()), value);
  } else {
    value.set_null();
    return RC::SUCCESS;
  }
}

RC FieldExpr::set_related_value(const Tuple *tuple)
{
  related_value_ = new Value();
  RC rc = RC::SUCCESS;
  if (tuple) {
    rc = tuple->find_cell(TupleCellSpec(table_name(), field_name()), *related_value_);
  } else {
    related_value_->set_null();
  }
  return rc;
}

RC FieldExpr::build_field(Expression *expr, Table *table, bool &has_attr, bool &has_agg) {
  RC rc = RC::SUCCESS;
  if (!expr) {
    LOG_WARN("Expr is null.");
    return rc;
  }
  switch (expr->type()) {
    case ExprType::FIELD: {
      rc = create_field_expr(expr, table, has_attr, has_agg, false);
      if(OB_FAIL(rc)) { return rc; };
    }break;
    case ExprType::COMPARISON: {
      auto comparison_expr = dynamic_cast<ComparisonExpr*>(expr);
      rc = build_field(comparison_expr->left().get(), table, has_attr, has_agg);
      if(OB_FAIL(rc)) { return rc; };
      rc = build_field(comparison_expr->right().get(), table, has_attr, has_agg);
      if(OB_FAIL(rc)) { return rc; };
    }break;
    case ExprType::CONJUNCTION: {
      for (auto &expression : dynamic_cast<ConjunctionExpr*>(expr)->children()) {
        rc = build_field(expression.get(), table, has_attr, has_agg);
        if(OB_FAIL(rc)) { return rc; };
      }
    } break;
    case ExprType::CAST: {
      auto cast_expr = dynamic_cast<CastExpr*>(expr);
      rc = build_field(cast_expr->child().get(), table, has_attr, has_agg);
      if(OB_FAIL(rc)) { return rc; };
    } break;
    case ExprType::ARITHMETIC: {
      auto arithmetic_expr = dynamic_cast<ArithmeticExpr*>(expr);
      rc = build_field(arithmetic_expr->left().get(), table, has_attr, has_agg);
      if(OB_FAIL(rc)) { return rc; };
      rc = build_field(arithmetic_expr->right().get(), table, has_attr, has_agg);
      if(OB_FAIL(rc)) { return rc; };
    }break;
    case ExprType::FUNC: {
      auto func_expr = dynamic_cast<FuncExpr*>(expr);
      rc = build_field(func_expr->child().get(), table, has_attr, has_agg);
      auto type = func_expr->func_type();
      auto parm = func_expr->get_parm();
      auto child_name = func_expr->child()->alias().empty() ? func_expr->child()->name() : func_expr->child()->alias();
      std::string name{};
      switch (type) {
        case FUNC_MIN: name += "min(" + child_name + ')'; break;
        case FUNC_MAX: name += "max(" + child_name + ')'; break;
        case FUNC_AVG: name += "avg(" + child_name + ')'; break;
        case FUNC_SUM: name += "sum(" + child_name + ')'; break;
        case FUNC_COUNT:
        case FUNC_WCOUNT: name += "count(" + child_name + ')'; break;
        case FUNC_ROUND: {
          if (parm.empty()) {
            name += "round(" + child_name + ')';
          } else {
            name += "round(" + child_name + "," + parm + ')';
          }
        } break;
        case FUNC_LENGTH: name += "length(" + child_name + ')'; break;
        case FUNC_DATE_FORMAT: name += "data_format(" + child_name + "," + parm + ')'; break;
        default:
          LOG_WARN("Wrong func type.");
      }
      func_expr->set_name(name);  // 设置名称
      if(OB_FAIL(rc)) { return rc; };
    } break;
    default:
      LOG_WARN("Got unsupported ExprType: %d, check whether it has child nodes.", expr->type());
  }
  return rc;
}

// multi-table
RC FieldExpr::build_field(Expression *expr, const std::unordered_map<std::string, Table *> &table_map, bool &has_attr, bool &has_agg) {
  RC rc = RC::SUCCESS;
  switch (expr->type()) {
    case ExprType::FIELD: {
      auto field_expr = dynamic_cast<FieldExpr*>(expr);
      auto table =
          table_map.count(field_expr->get_node().relation_name) == 1 ?
          table_map.at(field_expr->get_node().relation_name) : nullptr;
      if (!table) {
        LOG_ERROR("No table name in attribute %s.", field_expr->get_node().relation_name.c_str());
        return RC::INTERNAL;
      }
      rc = create_field_expr(expr, table, has_attr, has_agg, true);
      if(OB_FAIL(rc)) { return rc; };
    }break;
    case ExprType::COMPARISON: {
      auto comparison_expr = dynamic_cast<ComparisonExpr*>(expr);
      rc = build_field(comparison_expr->left().get(), table_map, has_attr, has_agg);
      if(OB_FAIL(rc)) { return rc; };
      rc = build_field(comparison_expr->right().get(), table_map, has_attr, has_agg);
      if(OB_FAIL(rc)) { return rc; };
    }break;
    case ExprType::CONJUNCTION: {
      for (auto &expression : dynamic_cast<ConjunctionExpr*>(expr)->children()) {
        rc = build_field(expression.get(), table_map, has_attr, has_agg);
        if(OB_FAIL(rc)) { return rc; };
      }
    } break;
    case ExprType::CAST: {
      auto cast_expr = dynamic_cast<CastExpr*>(expr);
      rc = build_field(cast_expr->child().get(), table_map, has_attr, has_agg);
      if(OB_FAIL(rc)) { return rc; };
    } break;
    case ExprType::ARITHMETIC: {
      auto arithmetic_expr = dynamic_cast<ArithmeticExpr*>(expr);
      rc = build_field(arithmetic_expr->left().get(), table_map, has_attr, has_agg);
      if(OB_FAIL(rc)) { return rc; };
      rc = build_field(arithmetic_expr->right().get(), table_map, has_attr, has_agg);
      if(OB_FAIL(rc)) { return rc; };
    }break;
    case ExprType::FUNC: {
      auto func_expr = dynamic_cast<FuncExpr*>(expr);
      rc = build_field(func_expr->child().get(), table_map, has_attr, has_agg);
      auto type = func_expr->func_type();
      auto parm = func_expr->get_parm();
      auto child_name = func_expr->child()->alias().empty() ? func_expr->child()->name() : func_expr->child()->alias();
      std::string name{};
      switch (type) {
        case FUNC_MIN: name += "min(" + child_name + ')'; break;
        case FUNC_MAX: name += "max(" + child_name + ')'; break;
        case FUNC_AVG: name += "avg(" + child_name + ')'; break;
        case FUNC_SUM: name += "sum(" + child_name + ')'; break;
        case FUNC_COUNT:
        case FUNC_WCOUNT: name += "count(" + child_name + ')'; break;
        case FUNC_ROUND: {
          if (parm.empty()) {
            name += "round(" + child_name + ')';
          } else {
            name += "round(" + child_name + "," + parm + ')';
          }
        } break;
        case FUNC_LENGTH: name += "length(" + child_name + ')'; break;
        case FUNC_DATE_FORMAT: name += "data_format(" + child_name + "," + parm + ')'; break;
        default:
          LOG_WARN("Wrong func type.");
      }
      func_expr->set_name(name);  // 设置名称
      if(OB_FAIL(rc)) { return rc; };
    } break;
    default:
      LOG_WARN("Got unsupported ExprType: %d, check whether it has child nodes.", expr->type());
  }
  return rc;
}

RC FieldExpr::build_subquery_field(Expression *expr, Table *table, const std::unordered_map<std::string, Table *> &parent_table_map, bool &has_attr, bool &has_agg,
    std::vector<Expression *> &related_expr_)
{
  RC rc = RC::SUCCESS;
  if (!expr) {
    LOG_WARN("Expr is null.");
    return rc;
  }
  switch (expr->type()) {
    case ExprType::FIELD: {
      auto field_expr = dynamic_cast<FieldExpr*>(expr);
      if (!field_expr->get_node().relation_name.empty() && parent_table_map.count(field_expr->get_node().relation_name) == 1) {
        auto parent_table =
            parent_table_map.count(field_expr->get_node().relation_name) == 1 ?
            parent_table_map.at(field_expr->get_node().relation_name) : nullptr;
        if (!parent_table) {
          LOG_ERROR("No table name in attribute %s.", field_expr->get_node().relation_name.c_str());
          return RC::INTERNAL;
        }
        rc = create_field_expr(expr, parent_table, has_attr, has_agg, true);
        if(OB_FAIL(rc)) { return rc; };
        field_expr->set_related(true);
        related_expr_.push_back(field_expr);
      } else {
        rc = create_field_expr(expr, table, has_attr, has_agg, false);
        if(OB_FAIL(rc)) { return rc; };
      }
    }break;
    case ExprType::COMPARISON: {
      auto comparison_expr = dynamic_cast<ComparisonExpr*>(expr);
      rc = build_subquery_field(comparison_expr->left().get(), table, parent_table_map, has_attr, has_agg, related_expr_);
      if(OB_FAIL(rc)) { return rc; };
      rc = build_subquery_field(comparison_expr->right().get(), table, parent_table_map, has_attr, has_agg, related_expr_);
      if(OB_FAIL(rc)) { return rc; };
    }break;
    case ExprType::CONJUNCTION: {
      for (auto &expression : dynamic_cast<ConjunctionExpr*>(expr)->children()) {
        rc = build_subquery_field(expression.get(), table, parent_table_map, has_attr, has_agg, related_expr_);
        if(OB_FAIL(rc)) { return rc; };
      }
    } break;
    case ExprType::CAST: {
      auto cast_expr = dynamic_cast<CastExpr*>(expr);
      rc = build_subquery_field(cast_expr->child().get(), table, parent_table_map, has_attr, has_agg, related_expr_);
      if(OB_FAIL(rc)) { return rc; };
    } break;
    case ExprType::ARITHMETIC: {
      auto arithmetic_expr = dynamic_cast<ArithmeticExpr*>(expr);
      rc = build_subquery_field(arithmetic_expr->left().get(), table, parent_table_map, has_attr, has_agg, related_expr_);
      if(OB_FAIL(rc)) { return rc; };
      rc = build_subquery_field(arithmetic_expr->right().get(), table, parent_table_map, has_attr, has_agg, related_expr_);
      if(OB_FAIL(rc)) { return rc; };
    }break;
    case ExprType::FUNC: {
      auto func_expr = dynamic_cast<FuncExpr*>(expr);
      rc = build_subquery_field(func_expr->child().get(), table, parent_table_map, has_attr, has_agg, related_expr_);
      auto type = func_expr->func_type();
      auto parm = func_expr->get_parm();
      auto child_name = func_expr->child()->alias().empty() ? func_expr->child()->name() : func_expr->child()->alias();
      std::string name{};
      switch (type) {
        case FUNC_MIN: name += "min(" + child_name + ')'; break;
        case FUNC_MAX: name += "max(" + child_name + ')'; break;
        case FUNC_AVG: name += "avg(" + child_name + ')'; break;
        case FUNC_SUM: name += "sum(" + child_name + ')'; break;
        case FUNC_COUNT:
        case FUNC_WCOUNT: name += "count(" + child_name + ')'; break;
        case FUNC_ROUND: {
          if (parm.empty()) {
            name += "round(" + child_name + ')';
          } else {
            name += "round(" + child_name + "," + parm + ')';
          }
        } break;
        case FUNC_LENGTH: name += "length(" + child_name + ')'; break;
        case FUNC_DATE_FORMAT: name += "data_format(" + child_name + "," + parm + ')'; break;
        default:
          LOG_WARN("Wrong func type.");
      }
      func_expr->set_name(name);  // 设置名称
      if(OB_FAIL(rc)) { return rc; };
    } break;
    default:
      LOG_WARN("Got unsupported ExprType: %d, check whether it has child nodes.", expr->type());
  }
  return rc;
}

RC FieldExpr::create_field_expr(Expression *expr, Table *table, bool &has_attr, bool &has_agg, bool multi_table)
{
  auto field_expr = dynamic_cast<FieldExpr*>(expr);
  if (field_expr == nullptr) {
    return RC::SCHEMA_FIELD_NOT_EXIST;
  }
  auto attr_node = field_expr->get_node();
  auto relation_name = attr_node.relation_name.empty()
                            ? table->name() : attr_node.relation_name;
  auto attribute_name = attr_node.attribute_name;
  auto alias = attr_node.alias;
  auto type = attr_node.func_type;
  auto field_meta = table->table_meta().field(attribute_name.c_str());
  if (type == FUNC_WCOUNT) {
    ASSERT(field_meta == nullptr, "Unknown error.");
    field_meta = table->table_meta().field(0);
  }
  if (!field_meta) {
    return RC::SCHEMA_FIELD_NOT_EXIST;
  }
  Field field(table, field_meta);
  field_expr->set_name(attribute_name);
  field_expr->set_alias(alias);
  field_expr->set_field(field);
  if (multi_table && field_expr->alias().empty()) {
    // 如果多表情况下没有别名，则设置alias
    field_expr->set_alias(relation_name + "." + attribute_name);
  } else {
    if (!alias.empty()) {
      LOG_WARN("RelAttrSqlNode and expr both have alias.");
    }
  }
  if (type > FUNC_NONE && type < FUNC_AGG_END) {
    has_agg = true;
  } else {
    has_attr = true;
  }
  if ((type == FUNC_LENGTH && field.meta()->type() != CHARS) ||
      (type == FUNC_ROUND && field.meta()->type() != FLOATS) ||
      (type == FUNC_DATE_FORMAT && field.meta()->type() != DATES)) {
    return RC::SCHEMA_WRONG_FUNC;
  }

  return RC::SUCCESS;
}

RC ValueExpr::get_value(const Tuple *tuple, Value &value)
{
  value = value_;
  return RC::SUCCESS;
}

/////////////////////////////////////////////////////////////////////////////////

RC CastExpr::cast(const Value &value, Value &cast_value) const
{
  RC rc = RC::SUCCESS;
  if (this->value_type() == value.attr_type()) {
    cast_value = value;
    return rc;
  }

  switch (cast_type_) {
    case BOOLEANS: {
      bool val = value.get_boolean();
      cast_value.set_boolean(val);
    } break;
    default: {
      rc = RC::INTERNAL;
      LOG_WARN("unsupported convert from type %d to %d", child_->value_type(), cast_type_);
    }
  }
  return rc;
}

RC CastExpr::get_value(const Tuple *tuple, Value &cell)
{
  RC rc = child_->get_value(tuple, cell);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  return cast(cell, cell);
}

RC CastExpr::try_get_value(Value &value)
{
  RC rc = child_->try_get_value(value);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  return cast(value, value);
}

////////////////////////////////////////////////////////////////////////////////

RC ComparisonExpr::compare_value(const Value &left, const Value &right, bool &result) const
{
  RC rc = RC::SUCCESS;
  if (comp_ != IS_NULL && comp_ != IS_NOT_NULL && (left.attr_type() == NULLS || right.attr_type() == NULLS)) {
    result = false;
    return rc;
  }
  int cmp_result = left.compare(right);
  result = false;
  switch (comp_) {
    case IS_NULL: {
      result = (cmp_result == 0);
    } break;
    case IS_NOT_NULL: {
      result = (cmp_result != 0);
    } break;
    case NOT_LIKE_TO:  {
      result = !(left.is_like(right));
    } break;
    case LIKE_TO: {
      result = left.is_like(right);
    } break;
    case EQUAL_TO: {
      result = (0 == cmp_result);
    } break;
    case LESS_EQUAL: {
      result = (cmp_result <= 0);
    } break;
    case NOT_EQUAL: {
      result = (cmp_result != 0);
    } break;
    case LESS_THAN: {
      result = (cmp_result < 0);
    } break;
    case GREAT_EQUAL: {
      result = (cmp_result >= 0);
    } break;
    case GREAT_THAN: {
      result = (cmp_result > 0);
    } break;
    default: {
      LOG_WARN("unsupported comparison. %d", comp_);
      rc = RC::INTERNAL;
    } break;
  }

  return rc;
}

RC ComparisonExpr::try_get_value(Value &cell)
{
  if (left_->type() == ExprType::VALUE && right_->type() == ExprType::VALUE) {
    ValueExpr *left_value_expr = static_cast<ValueExpr *>(left_.get());
    ValueExpr *right_value_expr = static_cast<ValueExpr *>(right_.get());
    const Value &left_cell = left_value_expr->get_value();
    const Value &right_cell = right_value_expr->get_value();

    bool value = false;
    RC rc = compare_value(left_cell, right_cell, value);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to compare tuple cells. rc=%s", strrc(rc));
    } else {
      cell.set_boolean(value);
    }
    return rc;
  }

  return RC::INVALID_ARGUMENT;
}

RC ComparisonExpr::get_value(const Tuple *tuple, Value &value)
{
  Value left_value;
  Value right_value;

  value.set_boolean(false);
  RC rc = left_->get_value(tuple, left_value);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
    return rc;
  }
  if (right_->type() == ExprType::SUBQUERY &&
      dynamic_cast<SubQueryExpr*>(right_.get())->get_subquery_type() == SubQueryType::LIST_VALUE) {
    ValueListTuple value_list;
    auto* subquery = dynamic_cast<SubQueryExpr*>(right_.get());
    rc = subquery->list_get_value(value_list);
    if (OB_FAIL(rc)) { return rc; }
    rc = value_list.find(left_value, comp_);
    if (rc == RC::SUCCESS) {
      value.set_boolean(true);
    }
    rc = RC::SUCCESS;
  } else {
    rc = right_->get_value(tuple, right_value);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get value of right expression. rc=%s", strrc(rc));
      return rc;
    }

    bool bool_value = false;
    rc = compare_value(left_value, right_value, bool_value);
    if (rc == RC::SUCCESS) {
      value.set_boolean(bool_value);
    }
  }
  return rc;
}

////////////////////////////////////////////////////////////////////////////////

/*
ConjunctionExpr::ConjunctionExpr(ConjunctionExpr::Type type, Expression *left, Expression *right)
    : conjunction_type_(type), left_(left), right_(right) {}

ConjunctionExpr::ConjunctionExpr(
    ConjunctionExpr::Type type, std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
    : conjunction_type_(type), left_(std::move(left)), right_(std::move(right)) {}
*/

RC ConjunctionExpr::get_value(const Tuple *tuple, Value &value)
{
  RC rc = RC::SUCCESS;
  if (children_.empty()) {
    value.set_boolean(true);
    return rc;
  }

  Value tmp_value;
  for (const unique_ptr<Expression> &expr : children_) {
    rc = expr->get_value(tuple, tmp_value);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get value by child expression. rc=%s", strrc(rc));
      return rc;
    }
    bool bool_value = tmp_value.get_boolean();
    if ((conjunction_type_ == Type::AND && !bool_value) || (conjunction_type_ == Type::OR && bool_value)) {
      value.set_boolean(bool_value);
      return rc;
    }
  }

  bool default_value = (conjunction_type_ == Type::AND);
  value.set_boolean(default_value);
  return rc;
}

////////////////////////////////////////////////////////////////////////////////

AttrType ArithmeticExpr::value_type() const
{
  if (!right_) {
    return left_->value_type();
  }

  if (left_->value_type() == AttrType::INTS &&
      right_->value_type() == AttrType::INTS &&
      arithmetic_type_ != Type::DIV) {
    return AttrType::INTS;
  }
  
  return AttrType::FLOATS;
}

RC ArithmeticExpr::calc_value(const Value &left_value, const Value &right_value, Value &value) const
{
  RC rc = RC::SUCCESS;

  const AttrType target_type = value_type();

  // null计算始终为null
  if (left_value.attr_type() == NULLS || right_value.attr_type() == NULLS) {
    value.set_null();
    return rc;
  }

  switch (arithmetic_type_) {
    case Type::ADD: {
      if (target_type == AttrType::INTS) {
        value.set_int(left_value.get_int() + right_value.get_int());
      } else {
        value.set_float(left_value.get_float() + right_value.get_float());
      }
    } break;

    case Type::SUB: {
      if (target_type == AttrType::INTS) {
        value.set_int(left_value.get_int() - right_value.get_int());
      } else {
        value.set_float(left_value.get_float() - right_value.get_float());
      }
    } break;

    case Type::MUL: {
      if (target_type == AttrType::INTS) {
        value.set_int(left_value.get_int() * right_value.get_int());
      } else {
        value.set_float(left_value.get_float() * right_value.get_float());
      }
    } break;

    case Type::DIV: {
      if (target_type == AttrType::INTS) {
        if (right_value.get_int() == 0) {
          value.set_null();
        } else {
          value.set_int(left_value.get_int() / right_value.get_int());
        }
      } else {
        if (right_value.get_float() > -EPSILON && right_value.get_float() < EPSILON) {
          value.set_null();
        } else {
          value.set_float(left_value.get_float() / right_value.get_float());
        }
      }
    } break;

    case Type::NEGATIVE: {
      if (target_type == AttrType::INTS) {
        value.set_int(-left_value.get_int());
      } else {
        value.set_float(-left_value.get_float());
      }
    } break;

    default: {
      rc = RC::INTERNAL;
      LOG_WARN("unsupported arithmetic type. %d", arithmetic_type_);
    } break;
  }
  return rc;
}

RC ArithmeticExpr::get_value(const Tuple *tuple, Value &value)
{
  RC rc = RC::SUCCESS;

  Value left_value;
  Value right_value;

  if (left_) {
    rc = left_->get_value(tuple, left_value);
  } else {
    return RC::EXPRESSION_INVALID;
  }
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
    return rc;
  }
  if (right_) {
    rc = right_->get_value(tuple, right_value);
  } else {
    return RC::EXPRESSION_INVALID;
  }
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of right expression. rc=%s", strrc(rc));
    return rc;
  }
  return calc_value(left_value, right_value, value);
}

RC ArithmeticExpr::try_get_value(Value &value)
{
  RC rc = RC::SUCCESS;

  Value left_value;
  Value right_value;

  rc = left_->try_get_value(left_value);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
    return rc;
  }

  if (right_) {
    rc = right_->try_get_value(right_value);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get value of right expression. rc=%s", strrc(rc));
      return rc;
    }
  }

  return calc_value(left_value, right_value, value);
}

void SubQueryExpr::set_list_tuple(std::vector<Value> &value_list)
{
  list_tuple_ = new ValueListTuple(value_list);
}

int SubQueryExpr::list_tuple_len()
{
  if (list_tuple_) {
    return list_tuple_->cell_num();
  }
  return 0;
}

RC SubQueryExpr::get_value(const Tuple *tuple, Value &value)
{
  RC rc = operator_->open(trx_);
  if (OB_FAIL(rc)) {
    return rc;
  }
  std::vector<Value> subquery_result;
  while (RC::SUCCESS == operator_->next()) {
    auto t = operator_->current_tuple();
    int cell_num = t->cell_num();
    if (cell_num > 1) {
      LOG_TRACE("subquery result is not a single value");
      return RC::INTERNAL;
    }
    Value tmp_value;
    t->cell_at(0, tmp_value);
    subquery_result.push_back(tmp_value);
  }
  if (subquery_result.empty()) {
    query_value_ = new Value();
    query_value_->set_null();
  } else if (subquery_result.size() > 1) {
    operator_->close();
    LOG_TRACE("subquery result is not a single value");
    return RC::INTERNAL;
  } else {
    query_value_ = new Value(subquery_result[0]);
  }
  operator_->close();
  value = *query_value_;
  return RC::SUCCESS;
}

RC SubQueryExpr::list_get_value(ValueListTuple& list_tuple)
{
  if (operator_) {
    list_tuple_ = new ValueListTuple();
    operator_->open(trx_);
    std::vector<Tuple *> subquery_result;
    while (RC::SUCCESS == operator_->next()) {
      Tuple *t        = operator_->current_tuple();
      int    cell_num = t->cell_num();
      if (cell_num > 1) {
        operator_->close();
        LOG_TRACE("subquery a tuple result is not a single value");
        return RC::INTERNAL;
      }
      Value tmp_value;
      t->cell_at(0, tmp_value);
      list_tuple_->add_value(tmp_value);
    }
    operator_->close();
  }
  list_tuple = *list_tuple_;
  return RC::SUCCESS;
}

RC FuncExpr::get_value(const Tuple *tuple, Value &value) {
  RC rc = RC::SUCCESS;

  // 当tuple为nullptr，仅存在于select时没有元祖满足条件
  if (!tuple) {
    switch (type_) {
      case FUNC_MIN:
      case FUNC_MAX:
      case FUNC_AVG:
      case FUNC_SUM:
      case FUNC_LENGTH:
      case FUNC_ROUND:
      case FUNC_DATE_FORMAT: {
        value.set_null();
        return rc;
      }
      case FUNC_COUNT:
      case FUNC_WCOUNT: {
        value.set_int(0);
        return rc;
      }
      default:
        return RC::INTERNAL;
    }
  }

  if (!child_) {
    return RC::EXPRESSION_INVALID;
  } else {
    rc = child_->get_value(tuple, value);
    if (!OB_SUCC(rc)) { return rc; }
    if (value.attr_type() != NULLS) {
      count_++;
    }
    w_count_++;
  }

  switch (type_) {
    case FUNC_MIN: {
      // 初始化值
      if (min_.attr_type() == UNDEFINED) {
        min_.set_type(value.attr_type());
        min_.set_value(value);
        break;
      }

      if (value.attr_type() == NULLS) {
        break;
      }

      if (min_.attr_type() == NULLS) {
        min_.set_value(value);
      }

      if (value.compare(min_) < 0) {
        min_.set_value(value);
      }
      value = min_;
    } break;
    case FUNC_MAX: {
      // 初始化值
      if (max_.attr_type() == UNDEFINED) {
        max_.set_type(value.attr_type());
        max_.set_value(value);
        break;
      }

      if (value.attr_type() == NULLS) {
        break;
      }

      if (max_.attr_type() == NULLS) {
        max_.set_value(value);
      }

      if (value.compare(max_) > 0) {
        max_.set_value(value);
      }
      value = max_;
    } break;
    case FUNC_AVG:
    case FUNC_SUM: {
      // 不支持boolean
      if (value.attr_type() == NULLS) {
        if (sum_.attr_type() == UNDEFINED) {
          sum_.set_type(value.attr_type());
          sum_.set_value(value);
        }
        break;
      }
      if (sum_.attr_type() == UNDEFINED) {
        sum_.set_type(value.attr_type());
        if (value.attr_type() == INTS) { sum_.set_int(value.get_int()); }
        else if (value.attr_type() == FLOATS) { sum_.set_float(value.get_float()); }
        else if (value.attr_type() == CHARS) {
          // 隐式转换，直接取float
          sum_.set_type(FLOATS);
          sum_.set_float(value.get_float());
        }
        else { return RC::INTERNAL; }
      } else {
        if (value.attr_type() == INTS) { sum_.set_int(sum_.get_int() + value.get_int()); }
        else if (value.attr_type() == FLOATS) { sum_.set_float(sum_.get_float() + value.get_float()); }
        else if (value.attr_type() == CHARS) { sum_.set_float(sum_.get_float() + value.get_float()); }
        else { return RC::INTERNAL; }
      }
      value = sum_;
    } break;
    case FUNC_COUNT: {
      value.set_int(count_);
    } break;
    case FUNC_WCOUNT: {
      value.set_int(w_count_);
    } break;
    case FUNC_LENGTH: {
      if (value.attr_type() != CHARS) {
        LOG_ERROR("length only support chars.");
        return RC::INTERNAL;
      }
      value.set_int(value.get_string().size());
    } break;
    case FUNC_ROUND: {
      value.set_float(std::round(value.get_float() * pow(10, std::stoi(parm_))) / pow(10, std::stoi(parm_)));
    } break;
    case FUNC_DATE_FORMAT: {
      value.set_date(value.get_date(), parm_);
      auto str = value.to_string();
      value.set_type(CHARS);
      value.set_data(str.c_str(), str.size());
    } break;
    default:
      LOG_ERROR("Wrong functino type %d.", type_);
      return RC::INTERNAL;
  }

  if (type_ != FUNC_AVG) { return rc; }

  // 计算avg
  switch (sum_.attr_type()) {
    case FLOATS: {
      value.set_float(sum_.get_float() / (float)count_);
    } break;
    case INTS: {
      value.set_float(sum_.get_int() / (float)count_);
    } break;
    case NULLS: {
      // do nothing
    } break;
    default: {
      return RC::INTERNAL;
    }
  }

  return RC::SUCCESS;
}

void FuncExpr::reset() {
  w_count_ = 0;
  count_ = 0;
  min_ = Value();
  max_ = Value();
  sum_ = Value();
}

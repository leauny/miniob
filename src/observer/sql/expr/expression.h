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

#include <string.h>
#include <memory>
#include <string>
#include <utility>

#include "storage/field/field.h"
#include "sql/parser/value.h"
#include "common/log/log.h"

class Db;
class Tuple;

/**
 * @defgroup Expression
 * @brief 表达式
 */

/**
 * @brief 表达式类型
 * @ingroup Expression
 */
enum class ExprType 
{
  NONE,
  STAR,         ///< 星号，表示所有字段
  FIELD,        ///< 字段。在实际执行时，根据行数据内容提取对应字段的值
  VALUE,        ///< 常量值
  CAST,         ///< 需要做类型转换的表达式
  COMPARISON,   ///< 需要做比较的表达式
  CONJUNCTION,  ///< 多个表达式使用同一种关系(AND或OR)来联结
  ARITHMETIC,   ///< 算术运算
  SUBQUERY,     ///< 子查询
  LIST,         ///< 列表
  REL_ATTR,     ///< 关系属性
  FUNC,         ///< 函数(length, random, data_format 以及 聚集函数)
  TABLE,        ///< 表名
};

/**
 * @brief 表达式的抽象描述
 * @ingroup Expression
 * @details 在SQL的元素中，任何需要得出值的元素都可以使用表达式来描述
 * 比如获取某个字段的值、比较运算、类型转换
 * 当然还有一些当前没有实现的表达式，比如算术运算。
 *
 * 通常表达式的值，是在真实的算子运算过程中，拿到具体的tuple后
 * 才能计算出来真实的值。但是有些表达式可能就表示某一个固定的
 * 值，比如ValueExpr。
 */
class Expression 
{
public:
  Expression() = default;
  Expression(const std::string &name) : name_(name) {}
  Expression(const std::string &name, const std::string & alias)
      : name_(name), alias_(alias) {}
  virtual ~Expression() = default;

  /**
   * @brief 根据具体的tuple，来计算当前表达式的值。tuple有可能是一个具体某个表的行数据
   */
  virtual RC get_value(const Tuple &tuple, Value &value) const = 0;

  /**
   * @brief 在没有实际运行的情况下，也就是无法获取tuple的情况下，尝试获取表达式的值
   * @details 有些表达式的值是固定的，比如ValueExpr，这种情况下可以直接获取值
   */
  virtual RC try_get_value(Value &value) const
  {
    return RC::UNIMPLENMENT;
  }

  /**
   * @brief 表达式的类型
   * 可以根据表达式类型来转换为具体的子类
   */
  virtual ExprType type() const = 0;

  /**
   * @brief 表达式值的类型
   * @details 一个表达式运算出结果后，只有一个值
   */
  virtual AttrType value_type() const = 0;

  /**
   * @brief 表达式的名字，比如是字段名称，或者用户在执行SQL语句时输入的内容
   */
  virtual std::string name() const { return name_; }
  virtual void set_name(const std::string &name) { name_ = name; }

  virtual std::string alias() const { return alias_; }
  virtual void set_alias(const std::string &alias) { alias_ = alias; }

private:
  std::string  name_;
  std::string  alias_;
};

// 仅用于存放*, 不包括count(*), count(*)存放在FieldExpr中
class StarExpr : public Expression {
public:
  explicit StarExpr() = default;
  RC get_value(const Tuple &tuple, Value &value) const override { return RC::UNIMPLENMENT; }
  ExprType type() const override { return ExprType::STAR; }
  AttrType value_type() const override { return AttrType::UNDEFINED; }
};

/**
 * @brief 字段表达式
 * @ingroup Expression
 */
class FieldExpr : public Expression 
{
public:
  FieldExpr() = delete;
  FieldExpr(RelAttrSqlNode node) : node_(node) {}
  FieldExpr(const Table *table, const FieldMeta *field) : field_(table, field)
  {}
  FieldExpr(const Field &field) : field_(field)
  {}

  virtual ~FieldExpr() = default;

  ExprType type() const override { return ExprType::FIELD; }
  AttrType value_type() const override { return field_.attr_type(); }

  Field &field() { return field_; }

  const Field &field() const { return field_; }

  const char *table_name() const { return field_.table_name(); }

  const char *field_name() const { return field_.field_name(); }

  void set_field(Field field) { field_ = field; }

  RC get_value(const Tuple &tuple, Value &value) const override;

  RelAttrSqlNode& get_node() { return node_; }

  static RC build_field(Expression *expr, Table *table);
  static RC build_field(Expression *expr, Db* db);  // multi-table
  static RC create_field_expr(Expression *expr, Table *table);

private:
  Field field_;
  RelAttrSqlNode node_;
};

/**
 * @brief 常量值表达式
 * @ingroup Expression
 */
class ValueExpr : public Expression 
{
public:
  ValueExpr() = default;
  explicit ValueExpr(const Value &value) : value_(value)
  {}

  virtual ~ValueExpr() = default;

  RC get_value(const Tuple &tuple, Value &value) const override;
  RC try_get_value(Value &value) const override { value = value_; return RC::SUCCESS; }

  ExprType type() const override { return ExprType::VALUE; }

  AttrType value_type() const override { return value_.attr_type(); }

  void get_value(Value &value) const { value = value_; }

  const Value &get_value() const { return value_; }

private:
  Value value_;
};

/**
 * @brief 类型转换表达式
 * @ingroup Expression
 */
class CastExpr : public Expression 
{
public:
  CastExpr(std::unique_ptr<Expression> child, AttrType cast_type);
  virtual ~CastExpr();

  ExprType type() const override
  {
    return ExprType::CAST;
  }
  RC get_value(const Tuple &tuple, Value &value) const override;

  RC try_get_value(Value &value) const override;

  AttrType value_type() const override { return cast_type_; }

  std::unique_ptr<Expression> &child() { return child_; }

private:
  RC cast(const Value &value, Value &cast_value) const;

private:
  std::unique_ptr<Expression> child_;  ///< 从这个表达式转换
  AttrType cast_type_;  ///< 想要转换成这个类型
};

/**
 * @brief 比较表达式
 * @ingroup Expression
 */
class ComparisonExpr : public Expression 
{
public:
  ComparisonExpr(CompOp comp, std::unique_ptr<Expression> left, std::unique_ptr<Expression> right);
  virtual ~ComparisonExpr();

  ExprType type() const override { return ExprType::COMPARISON; }

  RC get_value(const Tuple &tuple, Value &value) const override;

  AttrType value_type() const override { return BOOLEANS; }

  CompOp comp() const { return comp_; }

  std::unique_ptr<Expression> &left()  { return left_;  }
  std::unique_ptr<Expression> &right() { return right_; }

  /**
   * 尝试在没有tuple的情况下获取当前表达式的值
   * 在优化的时候，可能会使用到
   */
  RC try_get_value(Value &value) const override;

  /**
   * compare the two tuple cells
   * @param value the result of comparison
   */
  RC compare_value(const Value &left, const Value &right, bool &value) const;

private:
  CompOp comp_;
  std::unique_ptr<Expression> left_;
  std::unique_ptr<Expression> right_;
};

/**
 * @brief 联结表达式
 * @ingroup Expression
 * 多个表达式使用同一种关系(AND或OR)来联结
 * 当前miniob仅有AND操作
 */
class ConjunctionExpr : public Expression 
{
public:
  enum class Type {
    AND,
    OR,
  };

public:
  /*ConjunctionExpr(Type type, Expression *left, Expression *right);
  ConjunctionExpr(Type type, std::unique_ptr<Expression> left, std::unique_ptr<Expression> right);*/
  ConjunctionExpr(Type type, std::vector<std::unique_ptr<Expression>> &children);
  virtual ~ConjunctionExpr() = default;

  ExprType type() const override { return ExprType::CONJUNCTION; }

  AttrType value_type() const override { return BOOLEANS; }

  RC get_value(const Tuple &tuple, Value &value) const override;

  Type conjunction_type() const { return conjunction_type_; }

  std::vector<std::unique_ptr<Expression>> &children() { return children_; }
/*  std::unique_ptr<Expression> &left() { return left_; }
  std::unique_ptr<Expression> &right() { return right_; }*/

private:
  Type conjunction_type_;
  std::vector<std::unique_ptr<Expression>> children_;
  /*std::unique_ptr<Expression> left_;
  std::unique_ptr<Expression> right_;*/
};

/**
 * @brief 算术表达式
 * @ingroup Expression
 */
class ArithmeticExpr : public Expression 
{
public:
  enum class Type {
    ADD,
    SUB,
    MUL,
    DIV,
    NEGATIVE,
  };

public:
  ArithmeticExpr(Type type, Expression *left, Expression *right);
  ArithmeticExpr(Type type, std::unique_ptr<Expression> left, std::unique_ptr<Expression> right);
  virtual ~ArithmeticExpr() = default;

  ExprType type() const override { return ExprType::ARITHMETIC; }

  AttrType value_type() const override;

  RC get_value(const Tuple &tuple, Value &value) const override;
  RC try_get_value(Value &value) const override;

  Type arithmetic_type() const { return arithmetic_type_; }

  std::unique_ptr<Expression> &left() { return left_; }
  std::unique_ptr<Expression> &right() { return right_; }

private:
  RC calc_value(const Value &left_value, const Value &right_value, Value &value) const;
  
private:
  Type arithmetic_type_;
  std::unique_ptr<Expression> left_;
  std::unique_ptr<Expression> right_;
};

/**
 * @brief 子查询表达式
 * @ingroup Expression
 */
class SubQueryExpr: public Expression {
public:
  explicit SubQueryExpr(SelectSqlNode &node) {
    attributes_ = std::move(node.attributes);
    relations_ = std::move(node.relations);
    conditions_ = std::move(node.conditions);
  };
  RC get_value(const Tuple &tuple, Value &value) const override { return RC::UNIMPLENMENT; }
  ExprType type() const override { return ExprType::SUBQUERY; }
  AttrType value_type() const override { return UNDEFINED; }
private:
  std::vector<Expression*>        attributes_;         ///< attributes in select clause
  std::vector<Expression*>        relations_;          ///< from clause
  std::vector<Expression*>        conditions_;         ///< where clause
};

/**
 * @brief 列表表达式, 用于存储如 id in (col, 1, 2)中(col, 1, 2)这样的表达式
 * @ingroup Expression
 */
class ListExpr: public Expression {
public:
  RC get_value(const Tuple &tuple, Value &value) const override { return RC::UNIMPLENMENT; }
  ExprType type() const override { return ExprType::LIST; }
  AttrType value_type() const override { return UNDEFINED; }
private:
  std::vector<std::unique_ptr<Expression>> children_;
};

/**
 * @brief Relation, Attribute表达式, 后续需要转换为FieldExpr
 * @ingroup Expression
 */
class RelAttrExpr: public Expression {
public:
  explicit RelAttrExpr(RelAttrSqlNode node) {  node_ = std::move(node); }
  RC get_value(const Tuple &tuple, Value &value) const override { return RC::UNIMPLENMENT; }
  ExprType type() const override { return ExprType::REL_ATTR; }
  AttrType value_type() const override { return UNDEFINED; }
  RelAttrSqlNode & node() { return node_; }
private:
  RelAttrSqlNode node_;
};

/**
 * @brief 聚集函数或函数的表达式
 * @ingroup Expression
 */
class FuncExpr: public Expression {
public:
  explicit FuncExpr(const FieldExpr& field) : child_(std::make_unique<FieldExpr>(field)) {}
  RC get_value(const Tuple &tuple, Value &value) const override { return RC::UNIMPLENMENT; }
  ExprType type() const override { return ExprType::FUNC; }
  AttrType value_type() const override { return UNDEFINED; }
private:
  std::unique_ptr<Expression> child_;
};

/**
 * @brief 表名表达式
 * @ingroup Expression
 */
class TableExpr: public Expression {
public:
  explicit TableExpr(const std::string &name) : Expression(name) {}
  explicit TableExpr(const std::string &name, const std::string &alias)
      : Expression(name, alias) {}
  RC get_value(const Tuple &tuple, Value &value) const override
  { return RC::UNIMPLENMENT; }
  ExprType type() const override { return ExprType::TABLE; }
  AttrType value_type() const override { return UNDEFINED; }
private:
};
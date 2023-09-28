//
// Created by jacky on 2023/9/28.
//
#pragma once

#include "sql/operator/logical_operator.h"

/**
 * @brief 逻辑算子，用于执行delete语句
 * @ingroup LogicalOperator
 */
class UpdateLogicalOperator : public LogicalOperator
{
public:
  UpdateLogicalOperator(Table *table, Value value, int value_offset);
  virtual ~UpdateLogicalOperator() = default;

  LogicalOperatorType type() const override
  {
    return LogicalOperatorType::UPDATE;
  }
  Table *table() const
  {
    return table_;
  }
  Value value() const
  {
    return value_;
  }
  int value_offset()
  {
    return value_offset_;
  }
private:
  Table *table_ = nullptr;
  Value value_;
  int value_offset_ = 0;
};


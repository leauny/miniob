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
  UpdateLogicalOperator(Table *table, const std::vector<std::pair<Expression *, int>> &expressionsAndOffsets);
  virtual ~UpdateLogicalOperator() = default;

  LogicalOperatorType type() const override
  {
    return LogicalOperatorType::UPDATE;
  }
  Table *table() const
  {
    return table_;
  }

  auto expressions_and_offsets() const {
    return expressions_and_offsets_;
  }
private:
  Table *table_ = nullptr;
  std::vector<std::pair<Expression*, int>> expressions_and_offsets_;
};


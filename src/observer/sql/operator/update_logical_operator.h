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
  UpdateLogicalOperator(Table *table, const std::vector<std::pair<Value, int>>& valueAndOffsets);
  virtual ~UpdateLogicalOperator() = default;

  LogicalOperatorType type() const override
  {
    return LogicalOperatorType::UPDATE;
  }
  Table *table() const
  {
    return table_;
  }

  auto values_and_offsets() const {
    return values_and_offsets_;
  }
private:
  Table *table_ = nullptr;
  std::vector<std::pair<Value, int>> values_and_offsets_;
};


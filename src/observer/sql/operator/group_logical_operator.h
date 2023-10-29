//
// Created by leauny on 23-10-26.
//

#ifndef MINIDB_GROUP_LOGICAL_OPERATOR_H
#define MINIDB_GROUP_LOGICAL_OPERATOR_H

#pragma once

#include <memory>
#include <vector>

#include "sql/operator/logical_operator.h"

class GroupLogicalOperator : public LogicalOperator
{
public:
  GroupLogicalOperator(int group_size, int having_size,
      std::vector<std::unique_ptr<Expression>> &group,
      std::vector<std::unique_ptr<Expression>> &having) {
      group_size_ = group_size;
      having_size_ = having_size;
      set_expressions(group);
      set_having_expr(having);
  }

  LogicalOperatorType type() const override { return LogicalOperatorType::GROUP; }

  std::vector<std::unique_ptr<Expression>> &having_expr()
  {
    return having_expr_;
  }

  void set_having_expr(std::vector<std::unique_ptr<Expression>> &expression) {
    having_expr_.swap(expression);
  }

  int get_group_size() { return group_size_; }
  int get_having_size() { return having_size_; }

private:
  int group_size_{};
  int having_size_{};
  std::vector<std::unique_ptr<Expression>> having_expr_;
};

#endif  // MINIDB_GROUP_LOGICAL_OPERATOR_H

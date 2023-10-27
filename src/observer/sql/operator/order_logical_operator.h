//
// Created by leauny on 23-10-26.
//

#ifndef MINIDB_ORDER_LOGICAL_OPERATOR_H
#define MINIDB_ORDER_LOGICAL_OPERATOR_H

#pragma once

#include <memory>
#include <vector>

#include "sql/operator/logical_operator.h"

class OrderLogicalOperator: public LogicalOperator {
public:
  explicit OrderLogicalOperator(int size): order_size_(size) {};

  LogicalOperatorType type() const override { return LogicalOperatorType::ORDER; }

  int get_size() { return order_size_; }

private:
  int order_size_;
};

#endif  // MINIDB_ORDER_LOGICAL_OPERATOR_H

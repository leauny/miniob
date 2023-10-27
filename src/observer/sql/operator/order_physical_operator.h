//
// Created by leauny on 23-10-26.
//

#ifndef MINIDB_ORDER_PHYSICAL_OPERATOR_H
#define MINIDB_ORDER_PHYSICAL_OPERATOR_H

#pragma once


#include "sql/operator/physical_operator.h"

class OrderPhysicalOperator: public PhysicalOperator {
public:
  explicit OrderPhysicalOperator(int size, std::vector<std::unique_ptr<Expression>> &expressions)
      : order_size_(size), order_fields_(std::move(expressions)) {}

  PhysicalOperatorType type() const override { return PhysicalOperatorType::ORDER; }

  RC open(Trx *trx) override;
  RC next() override;
  RC close() override;

  Tuple *current_tuple_norm()
  {
    return children_[0]->current_tuple();
  }

  RC get_all_tuple();

  Tuple *current_tuple() override {
    if (index_ >= tuples_.size()) { return nullptr; }
    tuples_[index_].pop_value(order_size_);
    return &tuples_[index_];
  }

  RC collect_tuple_value(Tuple *tuple);

  RC sort();

private:
  std::vector<std::unique_ptr<Expression>> order_fields_;
  std::vector<ValueListTuple> tuples_;
  int order_size_{};
  int index_{-1};
};

#endif  // MINIDB_ORDER_PHYSICAL_OPERATOR_H

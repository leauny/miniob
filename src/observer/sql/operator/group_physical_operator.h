//
// Created by leauny on 23-10-26.
//

#ifndef MINIDB_GROUP_PHYSICAL_OPERATOR_H
#define MINIDB_GROUP_PHYSICAL_OPERATOR_H

#pragma once

#include "sql/operator/physical_operator.h"

class GroupPhysicalOperator : public PhysicalOperator {
public:
  GroupPhysicalOperator() = default;

  explicit GroupPhysicalOperator(int group_size, int having_size,
      std::vector<std::unique_ptr<Expression>> &group, std::vector<std::unique_ptr<Expression>> &having)
      : group_size_(group_size), having_size_(having_size), having_field_(std::move(having)), group_field_(std::move(group)) {}

  PhysicalOperatorType type() const override { return PhysicalOperatorType::GROUP; }

  RC open(Trx *trx) override;

  RC next() override;

  RC close() override;

  RC get_all_tuple();

  RC collect_tuple_value(Tuple *tuple);

  Tuple * current_tuple() override;

  RC create_group();

  RC sort();

  bool same_group(ValueListTuple *pre, ValueListTuple *now);

  RC get_filter_expr_addr(std::vector<ValueExpr *> &exprs_addr, std::unique_ptr<Expression> &filter_expr);

  Tuple *current_tuple_norm()
  {
    return children_[0]->current_tuple();
  }

private:
  std::vector<ValueListTuple> tuples_;
  std::vector<ValueListTuple> ans_;
  std::vector<std::unique_ptr<Expression>> having_field_; // 存放having字段
  std::vector<std::unique_ptr<Expression>> group_field_;  // 存放select + group + having的FieldExpr
  int group_size_{};
  int having_size_{};
  int index_{-1};
};

#endif  // MINIDB_GROUP_PHYSICAL_OPERATOR_H

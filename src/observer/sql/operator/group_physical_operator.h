//
// Created by leauny on 23-10-26.
//

#ifndef MINIDB_GROUP_PHYSICAL_OPERATOR_H
#define MINIDB_GROUP_PHYSICAL_OPERATOR_H

#pragma once

#include "sql/operator/physical_operator.h"

class GroupPhysicalOperator : public PhysicalOperator {
public:
  PhysicalOperatorType type() const override {}

  std::string name() const override {}

  RC open(Trx *trx) override {}

  RC next() override {}

  RC close() override {}

  Tuple * current_tuple() override {}

private:
  std::unique_ptr<Expression> expression_;                      // 存放having中和聚集函数有关的内容
  std::map<std::vector<Value>, std::vector<ValueListTuple>> group_;  // 存放所有的group
};

#endif  // MINIDB_GROUP_PHYSICAL_OPERATOR_H

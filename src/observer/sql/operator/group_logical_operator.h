//
// Created by leauny on 23-10-26.
//

#ifndef MINIDB_GROUP_LOGICAL_OPERATOR_H
#define MINIDB_GROUP_LOGICAL_OPERATOR_H

#pragma once

#include <memory>
#include <vector>

#include "sql/operator/logical_operator.h"
#include "sql/expr/expression.h"
#include "storage/field/field.h"

class GropuLogicalOperator : public LogicalOperator
{
  LogicalOperatorType type() const override { return LogicalOperatorType::GROUP; }
};

#endif  // MINIDB_GROUP_LOGICAL_OPERATOR_H

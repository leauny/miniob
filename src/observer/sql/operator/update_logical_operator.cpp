//
// Created by jacky on 2023/9/28.
//

#include "sql/operator/update_logical_operator.h"

UpdateLogicalOperator::UpdateLogicalOperator(Table *table, const std::vector<std::pair<Value, int>>& valueAndOffsets)
    : table_(table), values_and_offsets_(valueAndOffsets) {}

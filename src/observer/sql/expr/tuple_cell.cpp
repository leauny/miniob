/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by WangYunlai on 2022/07/05.
//

#include <sstream>
#include "sql/expr/tuple_cell.h"
#include "storage/field/field.h"
#include "common/log/log.h"
#include "common/lang/comparator.h"
#include "common/lang/string.h"

TupleCellSpec::TupleCellSpec(const char *table_name, const char *field_name, const char *alias, AggType agg_type)
{
  if (table_name) {
    table_name_ = table_name;
  }
  if (field_name) {
    field_name_ = field_name;
  }
  agg_type_ = agg_type;
  // TODO(wty): alias used at ExpressionTuple::find_cell();
  if (alias) {
    alias_ = alias;
  } else {
    if (table_name_.empty()) {
      alias_ = field_name_;
    } else {
      alias_ = table_name_ + "." + field_name_;
    }
    switch (agg_type_) {
      case AGG_NONE: break;
      case AGG_COUNT: {
        alias_ = "COUNT(" + alias_ + ")";
        break;
      }
      case AGG_WCOUNT: {
        alias_ = "COUNT(*)";
        break;
      }
      case AGG_MIN: {
        alias_ = "MIN(" + alias_ + ")";
        break;
      }
      case AGG_MAX: {
        alias_ = "MAX(" + alias_ + ")";
        break;
      }
      case AGG_AVG: {
        alias_ = "AVG(" + alias_ + ")";
        break;
      }
      case AGG_SUM: {
        alias_ = "SUM(" + alias_ + ")";
        break;
      }
      default: {
        LOG_ERROR("Unknown aggration type: %d.", static_cast<int>(agg_type));
      }
    }
  }
}

TupleCellSpec::TupleCellSpec(const char *alias, AggType agg_type)
{
  agg_type_ = agg_type;
  if (alias) {
    alias_ = alias;
  }
}

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
// Created by WangYunlai on 2022/07/01.
//

#pragma once

#include "sql/operator/physical_operator.h"

/**
 * @brief 选择/投影物理算子
 * @ingroup PhysicalOperator
 */
class ProjectPhysicalOperator : public PhysicalOperator
{
public:
  ProjectPhysicalOperator(std::vector<std::unique_ptr<Expression>> &&expressions) : tuple_(expressions)
  {}

  virtual ~ProjectPhysicalOperator() = default;

  PhysicalOperatorType type() const override
  {
    return PhysicalOperatorType::PROJECT;
  }

  RC open(Trx *trx) override;
  RC next() override;
  RC close() override;

  int cell_num() const
  {
    return tuple_.cell_num();
  }

  void set_agg(bool has_agg) { has_agg_ = has_agg; }

  const std::string name_at(int i) const { return tuple_.name_at(i); }

  const std::string alias_at(int i) const { return tuple_.alias_at(i); }

  Tuple *current_tuple() override;

private:
  /**
   * @brief 通过在内部调用普通select步骤来执行聚集函数，最后将agg_tuple_复制给tuple_完成
   * */
  RC do_aggregation(bool is_no_tuple);

  Tuple *current_tuple_norm(bool is_no_tuple);  // 用于在do_aggregation内调用

  ExpressionTuple tuple_;
  bool has_agg_ = false;
  bool agg_done_ = false;
  LeafTuple *agg_tuple_ = nullptr;
};

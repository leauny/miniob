 //
// Created by jacky on 2023/9/28.
//

#pragma once
 
#include "sql/operator/physical_operator.h"

 class Trx;
 class UpdateStmt;

 /**
 * @brief 物理算子，更新
 * @ingroup PhysicalOperator
  */
 class UpdatePhysicalOperator : public PhysicalOperator
 {
 public:
   UpdatePhysicalOperator(Table *table, const std::vector<std::pair<Expression*, int>>& valueAndOffsets) : table_(table), expressions_and_offsets_(valueAndOffsets) {}

   virtual ~UpdatePhysicalOperator() = default;

   PhysicalOperatorType type() const override
   {
     return PhysicalOperatorType::UPDATE;
   }

   RC open(Trx *trx) override;
   RC next() override;
   RC close() override;

   Tuple *current_tuple() override
   {
     return nullptr;
   }

 private:
   Table *table_ = nullptr;
   std::vector<std::pair<Expression*, int>> expressions_and_offsets_;
   Trx *trx_ = nullptr;
 };


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
   UpdatePhysicalOperator(Table *table, Value value, int value_offset) : table_(table), value_(value), value_offset_(value_offset)
   {}

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
   Value value_ ;
   int value_offset_ = 0;
   Trx *trx_ = nullptr;
 };


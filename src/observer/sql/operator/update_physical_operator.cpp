//
// Created by jacky on 2023/9/28.
//

#include "sql/operator/update_physical_operator.h"
#include "storage/trx/trx.h"
#include "sql/parser/value.h"

RC UpdatePhysicalOperator::open(Trx *trx)
{
  if (children_.empty()) {
    return RC::SUCCESS;
  }

  std::unique_ptr<PhysicalOperator> &child = children_[0];
  RC rc = child->open(trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  trx_ = trx;

  return RC::SUCCESS;
}

RC UpdatePhysicalOperator::next()
{
  RC rc = RC::SUCCESS;
  if (children_.empty()) {
    return RC::RECORD_EOF;
  }

  PhysicalOperator *child = children_[0].get();
  bool first_get_subquery = false;
  while (RC::SUCCESS == (rc = child->next())) {
    if (!first_get_subquery) {
      for (auto &[expr, offset] : expressions_and_offsets_) {
        if (expr->type() == ExprType::SUBQUERY) {
          auto subquery_expr = dynamic_cast<SubQueryExpr *>(expr);
          Value value;
          RowTuple tuple;
          rc = subquery_expr->get_value(&tuple, value);
          if (OB_FAIL(rc)) {
            return rc;
          }
          const FieldMeta* field = subquery_expr->field_meta();
          rc = value_cast(field, value);
          if (OB_FAIL(rc)) {
            return rc;
          }
          expr = new ValueExpr(value);
        }
      }
      first_get_subquery = true;
    }
    Tuple *tuple = child->current_tuple();
    if (nullptr == tuple) {
      LOG_WARN("failed to get current record: %s", strrc(rc));
      return rc;
    }

    RowTuple *row_tuple = static_cast<RowTuple *>(tuple);
    Record &record = row_tuple->record();
    
    rc = trx_->update_record(table_, expressions_and_offsets_, record);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to Update record: %s", strrc(rc));
      return rc;
    }
  }

  return RC::RECORD_EOF;
}

RC UpdatePhysicalOperator::close()
{
  if (!children_.empty()) {
    children_[0]->close();
  }
  return RC::SUCCESS;
}

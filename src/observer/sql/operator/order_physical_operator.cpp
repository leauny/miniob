//
// Created by leauny on 23-10-26.
//

#include "sql/operator/order_physical_operator.h"
RC OrderPhysicalOperator::open(Trx *trx) {
  if (children_.empty()) {
    return RC::SUCCESS;
  }

  PhysicalOperator *child = children_[0].get();
  RC rc = child->open(trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  get_all_tuple();

  return RC::SUCCESS;
}

RC OrderPhysicalOperator::next() {
  if (children_.empty()) {
    return RC::RECORD_EOF;
  }

  index_++;

  if (index_ >= tuples_.size()) {
    return RC::RECORD_EOF;
  }
  return RC::SUCCESS;
}

RC OrderPhysicalOperator::close() {
  if (!children_.empty()) {
    children_[0]->close();
  }
  return RC::SUCCESS;
}

RC OrderPhysicalOperator::collect_tuple_value(Tuple *tuple) {
  if (!tuple) {
    return RC::INTERNAL;
  }

  std::vector<Value> record;

  for (int i = 0; i < order_fields_.size(); ++i) {
    Value value;
    if (order_fields_[i]->type() != ExprType::FIELD) {
      LOG_ERROR("Unsupported order expr type %d.", order_fields_[i]->type());
    }

    const auto ptr = dynamic_cast<FieldExpr*>(order_fields_[i].get());
    tuple->find_cell(TupleCellSpec(ptr->table_name(), ptr->field_name()), value);
    record.emplace_back(value);
  }

  tuples_.emplace_back(record);  // 插入元祖
  return RC::SUCCESS;
}

RC OrderPhysicalOperator::get_all_tuple() {
  RC rc = RC::SUCCESS;
  while (!children_.empty() && RC::SUCCESS == children_[0]->next()) {
    collect_tuple_value(current_tuple_norm());
  }
  return sort();
}

RC OrderPhysicalOperator::sort() {
  if (tuples_.size() <= 0) { return RC::SUCCESS; }

  std::vector<int> sort_list;
  std::unordered_map<int, bool> sort_order;

  for (int i = order_fields_.size() - order_size_; i < order_fields_.size(); ++i) {
    const auto field = dynamic_cast<FieldExpr *>(order_fields_[i].get());

    if (field->type() != ExprType::FIELD) {
      LOG_ERROR("Wrong sort arrt type. %d", field->type());
      return RC::INTERNAL;
    }
    bool asc = field->get_order() == FieldExpr::Order::ASC;

    sort_list.emplace_back(i);
    sort_order[i] = asc;
  }

  Value left;
  Value right;

  std::sort(tuples_.begin(), tuples_.end(), [&](ValueListTuple &a, ValueListTuple &b) {
    bool ans = false;

    for (auto i : sort_list) {
      a.cell_at(i, left);
      b.cell_at(i, right);

      auto tmp = left.compare(right);

      if (tmp == 0) {
        continue;  // 进入下一步比较
      } else {
        ans = sort_order.at(i) ? tmp < 0 : tmp > 0;
        break;
      }
    }

    return ans;  // 两个值都相同
  });
  return RC::SUCCESS;
}

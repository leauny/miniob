//
// Created by leauny on 23-10-26.
//

#include "sql/operator/group_physical_operator.h"
RC GroupPhysicalOperator::open(Trx *trx) {
  if (children_.empty()) {
    return RC::SUCCESS;
  }

  PhysicalOperator *child = children_[0].get();
  RC rc = child->open(trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  rc = get_all_tuple();
  if (OB_FAIL(rc)) {
    LOG_WARN("failed to get all tuple: %s", strrc(rc));
    return rc;
  }

  return RC::SUCCESS;
}

RC GroupPhysicalOperator::next() {
  if (children_.empty()) {
    return RC::RECORD_EOF;
  }

  index_++;

  if (index_ >= ans_.size()) {
    return RC::RECORD_EOF;
  }
  return RC::SUCCESS;
}

RC GroupPhysicalOperator::close() {
  if (!children_.empty()) {
    children_[0]->close();
  }
  return RC::SUCCESS;
}

Tuple *GroupPhysicalOperator::current_tuple() {
  if (index_ >= ans_.size()) { return nullptr; }
  ans_[index_].pop_value(group_size_ + having_size_);  // 弹出多余的列
  return &ans_[index_];
}

RC GroupPhysicalOperator::collect_tuple_value(Tuple *tuple) {
  if (!tuple) {
    return RC::INTERNAL;
  }

  std::vector<Value> record;

  for (int i = 0; i < group_field_.size(); ++i) {
    Value value;
    switch (group_field_[i]->type()) {
      case ExprType::FIELD: {
        const auto ptr = dynamic_cast<FieldExpr*>(group_field_[i].get());
        tuple->find_cell(TupleCellSpec(ptr->table_name(), ptr->field_name()), value);
      } break;
      case ExprType::FUNC: {
        const auto ptr = dynamic_cast<FieldExpr*>(
            dynamic_cast<FuncExpr*>(group_field_[i].get())->child().get()
        );
        tuple->find_cell(TupleCellSpec(ptr->table_name(), ptr->field_name()), value);
      } break;
      default:
        LOG_ERROR("Unsupported order expr type %d.", group_field_[i]->type());
        return RC::UNIMPLENMENT;
    }

    const auto ptr = dynamic_cast<FieldExpr*>(group_field_[i].get());
    tuple->find_cell(TupleCellSpec(ptr->table_name(), ptr->field_name()), value);
    record.emplace_back(value);
  }

  tuples_.emplace_back(record);  // 插入元祖
  return RC::SUCCESS;
}

RC GroupPhysicalOperator::get_all_tuple() {
  RC rc = RC::SUCCESS;
  while (!children_.empty() && RC::SUCCESS == (rc = children_[0]->next())) {
    collect_tuple_value(current_tuple_norm());
  }
  if (rc != RC::RECORD_EOF) {
    LOG_WARN("failed to get current record: %s", strrc(rc));
    return rc;
  }
  return create_group();
}

RC GroupPhysicalOperator::create_group() {
  auto rc = sort();
  if (!OB_SUCC(rc)) { return rc; }

  if (tuples_.empty()) { return RC::RECORD_EOF; }

  // 将非聚集函数的FieldExpr转换为FuncExpr
  for (auto &n : group_field_) {
    if (n->type() != ExprType::FIELD) {
      LOG_ERROR("Unknown group field %d.", n->type());
      return RC::INTERNAL;
    }

    // 释放unique_ptr指向的内容
    auto ptr = dynamic_cast<FieldExpr*>(n.get());
    auto type = ptr->get_node().func_type;
    if (type != FuncType::FUNC_NONE) {
      if (type >= FuncType::FUNC_AGG_END) {
        LOG_ERROR("Unknown agg type %d.", type);
        return RC::INTERNAL;
      }
      auto func_expr = new FuncExpr(ptr);
      func_expr->set_type(type);
      n.release();
      n.reset(func_expr);
    }
  }

  std::vector<Value> record(tuples_[0].size());  // 设置tuple大小

  // 分组并构建元祖
  ValueListTuple *last = nullptr;
  ValueListTuple *now = nullptr;
  for (auto &n : tuples_) {
    now = &n;
    bool same = same_group(last, now);
    if (!same && last) {
      // 将前一组的结果存下, reset FuncExpr
      ans_.emplace_back(record);
      for (auto &expr : group_field_) {
        if (expr->type() == ExprType::FUNC) {
          // 重置聚集函数结果
          dynamic_cast<FuncExpr*>(expr.get())->reset();
        }
      }
    }

    // 计算结果
    for (int i = 0; i < group_field_.size(); ++i) {
      auto expr = group_field_[i].get();

      Value val;
      val.set_int(i);  // 用于传递信息，告知Expr返回ValueListTuple的第几个

      switch (expr->type()) {
        case ExprType::FIELD: {
          const auto e = dynamic_cast<FieldExpr*>(expr);
          e->get_value(now, val);
          record[i] = val;
        } break;
        case ExprType::FUNC: {
          const auto e = dynamic_cast<FuncExpr*>(expr);
          e->get_value(now, val);
          record[i] = val;
        } break;
        default:
          LOG_ERROR("Unsupported expr type %d.", expr->type());
          return RC::INTERNAL;
      }
    }

    if (!same) {
      last = now;
    }
  }

  // 存储最后的一个结果
  if (now) {
    ans_.emplace_back(record);
  }

  return rc;
}

RC GroupPhysicalOperator::sort() {
  if (tuples_.empty()) { return RC::SUCCESS; }

  std::vector<int> sort_list;

  // group_field_(select + group + having)
  // 只需要排序中间的group部分
  for (int i = group_field_.size() - group_size_ - having_size_; i < group_field_.size() - having_size_; ++i) {
    const auto field = dynamic_cast<FieldExpr *>(group_field_[i].get());

    if (field->type() != ExprType::FIELD) {
      LOG_ERROR("Wrong sort arrt type. %d", field->type());
      return RC::INTERNAL;
    }
    sort_list.emplace_back(i);
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
        ans = tmp < 0;
        break;
      }
    }

    return ans;  // 两个值都相同
  });
  return RC::SUCCESS;
}

bool GroupPhysicalOperator::same_group(ValueListTuple *pre, ValueListTuple *now) {
  if (!pre || !now) { return false; }

  std::vector<int> sort_list;

  // group_field_(select + group + having)
  // 只需要排序中间的group部分
  for (int i = group_field_.size() - group_size_ - having_size_; i < group_field_.size() - having_size_; ++i) {
    sort_list.emplace_back(i);
  }

  Value left;
  Value right;

  for (auto i : sort_list) {
    pre->cell_at(i, left);
    now->cell_at(i, right);

    auto tmp = left.compare(right);

    if (tmp == 0) {
      continue;  // 进入下一步比较
    } else {
      return false;
    }
  }

  return true;
}
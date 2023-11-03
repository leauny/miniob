/* Copyright (c) 2023 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2023/08/16.
//

#include "sql/optimizer/logical_plan_generator.h"

#include "sql/operator/logical_operator.h"
#include "sql/operator/calc_logical_operator.h"
#include "sql/operator/project_logical_operator.h"
#include "sql/operator/predicate_logical_operator.h"
#include "sql/operator/order_logical_operator.h"
#include "sql/operator/group_logical_operator.h"
#include "sql/operator/table_get_logical_operator.h"
#include "sql/operator/insert_logical_operator.h"
#include "sql/operator/delete_logical_operator.h"
#include "sql/operator/join_logical_operator.h"
#include "sql/operator/project_logical_operator.h"
#include "sql/operator/explain_logical_operator.h"
#include "sql/operator/update_logical_operator.h"

#include "sql/stmt/stmt.h"
#include "sql/stmt/calc_stmt.h"
#include "sql/stmt/select_stmt.h"
#include "sql/stmt/filter_stmt.h"
#include "sql/stmt/insert_stmt.h"
#include "sql/stmt/delete_stmt.h"
#include "sql/stmt/explain_stmt.h"
#include "sql/stmt/update_stmt.h"
#include "sql/stmt/create_table_stmt.h"

using namespace std;

RC LogicalPlanGenerator::create(Stmt *stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  RC rc = RC::SUCCESS;
  switch (stmt->type()) {
    case StmtType::CALC: {
      CalcStmt *calc_stmt = static_cast<CalcStmt *>(stmt);
      rc = create_plan(calc_stmt, logical_operator);
    } break;

    case StmtType::SELECT: {
      SelectStmt *select_stmt = static_cast<SelectStmt *>(stmt);
      rc = create_plan(select_stmt, logical_operator);
    } break;

    case StmtType::INSERT: {
      InsertStmt *insert_stmt = static_cast<InsertStmt *>(stmt);
      rc = create_plan(insert_stmt, logical_operator);
    } break;

    case StmtType::DELETE: {
      DeleteStmt *delete_stmt = static_cast<DeleteStmt *>(stmt);
      rc = create_plan(delete_stmt, logical_operator);
    } break;

    case StmtType::EXPLAIN: {
      ExplainStmt *explain_stmt = static_cast<ExplainStmt *>(stmt);
      rc = create_plan(explain_stmt, logical_operator);
    } break;

    case StmtType::CREATE_TABLE: {
      // 判断建表类型，如果是create-table-select就创建insert计划包裹select计划
      CreateTableStmt *create_stmt = static_cast<CreateTableStmt *>(stmt);
      if (!create_stmt->is_create_select()) {
        rc = RC::UNIMPLENMENT;
        break;
      }
      unique_ptr<LogicalOperator> select_oper;
      rc = create_plan((SelectStmt*)create_stmt->select_stmt(), select_oper);
      if (OB_FAIL(rc)) { break; }
      rc = create_plan((InsertStmt*)nullptr, logical_operator);
      if (OB_FAIL(rc)) { break; }
      // 将select添加到insert下
      logical_operator->add_child(std::move(select_oper));
    } break;

    case StmtType::UPDATE: {
      UpdateStmt *update_stmt = static_cast<UpdateStmt *>(stmt);
      rc = create_plan(update_stmt, logical_operator);
    } break;
    default: {
      rc = RC::UNIMPLENMENT;
    }
  }
  return rc;
}

RC LogicalPlanGenerator::create_plan(CalcStmt *calc_stmt, std::unique_ptr<LogicalOperator> &logical_operator)
{
  logical_operator.reset(new CalcLogicalOperator(std::move(calc_stmt->expressions())));
  return RC::SUCCESS;
}

RC LogicalPlanGenerator::create_plan(UpdateStmt *update_stmt, std::unique_ptr<LogicalOperator> &logical_operator)
{
  Table *table = update_stmt->table();
  FilterStmt *filter_stmt = update_stmt->filter_stmt();
  std::vector<Field> fields;
  for (int i = table->table_meta().sys_field_num(); i < table->table_meta().field_num(); i++) {
    const FieldMeta *field_meta = table->table_meta().field(i);
    fields.push_back(Field(table, field_meta));
  }
  unique_ptr<LogicalOperator> table_get_oper(new TableGetLogicalOperator(table, fields, false/*readonly*/));

  unique_ptr<LogicalOperator> predicate_oper;
  RC rc = create_plan(filter_stmt, predicate_oper);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  unique_ptr<LogicalOperator> update_oper(new UpdateLogicalOperator(table, update_stmt->expressions_and_offsets()));

  if (predicate_oper) {
    predicate_oper->add_child(std::move(table_get_oper));
    update_oper->add_child(std::move(predicate_oper));
  } else {
    update_oper->add_child(std::move(table_get_oper));
  }

  logical_operator = std::move(update_oper);
  return rc;
}

RC get_fields(std::vector<Field> &fields, const std::string &table_name, const std::unique_ptr<Expression> &expr) {
  RC rc = RC::SUCCESS;
  switch (expr->type()) {
    case ExprType::FIELD: {
      const auto e = dynamic_cast<FieldExpr*>(expr.get());
      if (0 == strcmp(e->table_name(), table_name.c_str())) {
        fields.push_back(e->field());  // 按照表来遍历，找到属与当前表中的field
      }
    } break;
    case ExprType::CAST: {
      const auto e = dynamic_cast<CastExpr*>(expr.get());
      rc = get_fields(fields, table_name, e->child());
      if (OB_SUCC(rc)) { return rc; }
    } break;
    case ExprType::COMPARISON: {
      const auto e = dynamic_cast<ComparisonExpr*>(expr.get());
      rc = get_fields(fields, table_name, e->left());
      if (OB_SUCC(rc)) { return rc; }
      rc = get_fields(fields, table_name, e->right());
      if (OB_SUCC(rc)) { return rc; }
    } break;
    case ExprType::CONJUNCTION: {
      const auto e = dynamic_cast<ConjunctionExpr*>(expr.get());
      for (auto &child : e->children()) {
        rc = get_fields(fields, table_name, child);
        if (OB_SUCC(rc)) { return rc; }
      }
    } break;
    case ExprType::ARITHMETIC: {
      const auto e = dynamic_cast<ArithmeticExpr*>(expr.get());
      rc = get_fields(fields, table_name, e->left());
      if (OB_SUCC(rc)) { return rc; }
      rc = get_fields(fields, table_name, e->right());
      if (OB_SUCC(rc)) { return rc; }
    } break;
    case ExprType::FUNC: {
      const auto e = dynamic_cast<FuncExpr*>(expr.get());
      rc = get_fields(fields, table_name, e->child());
      if (OB_SUCC(rc)) { return rc; }
    } break;
    case ExprType::VALUE: break;
    case ExprType::NONE: break;
    case ExprType::STAR: break;
    case ExprType::SUBQUERY:
    case ExprType::LIST:
    case ExprType::REL_ATTR:
    case ExprType::TABLE: {
      return RC::UNIMPLENMENT;
    } break;
  }
  return rc;
}

RC LogicalPlanGenerator::create_plan(
    SelectStmt *select_stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  unique_ptr<LogicalOperator> table_oper(nullptr);

  const std::vector<Table *> &tables = select_stmt->tables();
  // 当存在order by或group by时会有隐含的问题，order by/group by中其实需要获得更多的field，
  // 但是拿表只拿了select的属性，如果使用索引方式取到表会存在错误（但测试用例可能没有测到）
  vector<unique_ptr<Expression>> &all_exprs = select_stmt->query_exprs();
  for (Table *table : tables) {
    std::vector<Field> fields;
    for (const auto &expr : all_exprs) {
      get_fields(fields, table->name(), expr);
    }

    // 根据找到的field来创建table get operator
    unique_ptr<TableGetLogicalOperator> table_get_oper(new TableGetLogicalOperator(table, fields, true/*readonly*/));
    table_get_oper->set_related_exprs(select_stmt->related_expr());
    if (table_oper == nullptr) {
      table_oper = std::move(table_get_oper);
    } else {
      // 如果存在多表就将TableGetLogicalOperator移动到JoinLogicalOperator中
      JoinLogicalOperator *join_oper = new JoinLogicalOperator;
      join_oper->add_child(std::move(table_oper));
      join_oper->add_child(std::move(table_get_oper));
      table_oper = unique_ptr<LogicalOperator>(join_oper);
    }
  }

  // 创建predicate operator
  unique_ptr<LogicalOperator> predicate_oper;
  RC rc = create_plan(select_stmt->filter_stmt(), predicate_oper);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create predicate logical plan. rc=%s", strrc(rc));
    return rc;
  }

  // 创建order/group operator (设置需要排序的列数)
  unique_ptr<LogicalOperator> order_group_oper{};
  int order_size = select_stmt->order_fields().size() - all_exprs.size();
  int group_size = select_stmt->group_fields().size() - all_exprs.size() - select_stmt->having_fields().size();

  if (order_size > 0) {
    order_group_oper = make_unique<OrderLogicalOperator>(order_size);
    order_group_oper->set_expressions(select_stmt->order_fields());
  }

  if (group_size > 0) {
    if (order_group_oper) {
      LOG_ERROR("Both have order and group by");
      return RC::INTERNAL;
    }
    order_group_oper = make_unique<GroupLogicalOperator>(group_size, select_stmt->having_fields().size(),
        select_stmt->group_fields(), select_stmt->having_fields());
  }

  if (order_size > 0 || group_size > 0) {
    if (predicate_oper) {
      if (table_oper) {
        predicate_oper->add_child(std::move(table_oper));
      }
      order_group_oper->add_child(std::move(predicate_oper));
    } else {
      if (table_oper) {
        order_group_oper->add_child(std::move(table_oper));
      }
    }
  } else {
    order_group_oper.reset();
  }

  // 创建project operator
  unique_ptr<LogicalOperator> project_oper = make_unique<ProjectLogicalOperator>(select_stmt->get_agg());
  project_oper->set_expressions(all_exprs);  // 将查询内容移动到physical_oper
  if (order_group_oper) {
    project_oper->add_child(std::move(order_group_oper));
  } else {
    if (predicate_oper) {
      if (table_oper) {
        predicate_oper->add_child(std::move(table_oper));
      }
      project_oper->add_child(std::move(predicate_oper));
    } else {
      if (table_oper) {
        project_oper->add_child(std::move(table_oper));
      }
    }
  }

  // 将相关子查询给到table_scan操作符
  logical_operator.swap(project_oper);
  return RC::SUCCESS;
}

RC LogicalPlanGenerator::create_plan(
    FilterStmt *filter_stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  unique_ptr<PredicateLogicalOperator> predicate_oper;
  if (!filter_stmt->filter_expr().empty()) {
    unique_ptr<ConjunctionExpr> conjunction_expr(
        new ConjunctionExpr(filter_stmt->conjunction_type(), filter_stmt->filter_expr()));
    predicate_oper = std::make_unique<PredicateLogicalOperator>(std::move(conjunction_expr));
  }

  logical_operator = std::move(predicate_oper);
  return RC::SUCCESS;
}

RC LogicalPlanGenerator::create_plan(
    InsertStmt *insert_stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  InsertLogicalOperator *insert_operator = nullptr;

  if (!insert_stmt) {
    // 用于create-select
    insert_operator = new InsertLogicalOperator();
  } else {
    // 普通insert
    Table *table = insert_stmt->table();
    vector<vector<Value>> values(std::move(*insert_stmt->values()));
    insert_operator = new InsertLogicalOperator(table, values);
  }

  logical_operator.reset(insert_operator);
  return RC::SUCCESS;
}

RC LogicalPlanGenerator::create_plan(
    DeleteStmt *delete_stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  Table *table = delete_stmt->table();
  FilterStmt *filter_stmt = delete_stmt->filter_stmt();
  std::vector<Field> fields;
  for (int i = table->table_meta().sys_field_num(); i < table->table_meta().field_num(); i++) {
    const FieldMeta *field_meta = table->table_meta().field(i);
    fields.push_back(Field(table, field_meta));
  }
  unique_ptr<LogicalOperator> table_get_oper(new TableGetLogicalOperator(table, fields, false/*readonly*/));

  unique_ptr<LogicalOperator> predicate_oper;
  RC rc = create_plan(filter_stmt, predicate_oper);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  unique_ptr<LogicalOperator> delete_oper(new DeleteLogicalOperator(table));

  if (predicate_oper) {
    predicate_oper->add_child(std::move(table_get_oper));
    delete_oper->add_child(std::move(predicate_oper));
  } else {
    delete_oper->add_child(std::move(table_get_oper));
  }

  logical_operator = std::move(delete_oper);
  return rc;
}

RC LogicalPlanGenerator::create_plan(
    ExplainStmt *explain_stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  Stmt *child_stmt = explain_stmt->child();
  unique_ptr<LogicalOperator> child_oper;
  RC rc = create(child_stmt, child_oper);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create explain's child operator. rc=%s", strrc(rc));
    return rc;
  }

  logical_operator = unique_ptr<LogicalOperator>(new ExplainLogicalOperator);
  logical_operator->add_child(std::move(child_oper));
  return rc;
}

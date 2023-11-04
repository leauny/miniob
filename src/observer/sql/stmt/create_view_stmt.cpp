//
// Created by leauny on 23-11-2.
//

#include "sql/stmt/create_view_stmt.h"
#include "sql/stmt/select_stmt.h"
#include "sql/expr/expression.h"
#include "event/sql_debug.h"

RC CreateViewStmt::create(Db *db, const CreateViewSqlNode &create_view, Stmt *&stmt)
{
  const auto &view_infos = create_view.view_infos;
  Stmt *select_stmt = nullptr;
  std::vector<ViewInfoSqlNode> infos;

  if (!create_view.select_node) {
    sql_debug("create_view must have select stmt.");
    return RC::INTERNAL;
  }

  // 构建select stmt
  auto rc = SelectStmt::create(db, *create_view.select_node, select_stmt);
  if (OB_FAIL(rc)) { return rc; }

  // 获取select的字段并对比自带的字段
  bool have_field = false;
  auto &exprs = reinterpret_cast<SelectStmt*>(select_stmt)->query_exprs();
  if (!view_infos.empty()) {
    have_field = true;
    if (view_infos.size() != exprs.size()) {
      LOG_ERROR("Create view select attr number didn't same.");
      return RC::INTERNAL;
    }
  }

  // 获取基表
  auto tables = reinterpret_cast<SelectStmt*>(select_stmt)->tables();

  // 创建视图属性映射
  std::string field_name;
  for (auto i = 0; i < exprs.size(); ++i) {
    ViewInfoSqlNode view_info{};
    auto *expr = exprs[i].get();
    if (exprs[i]->type() == ExprType::FIELD) {
      view_info.relation_name = dynamic_cast<FieldExpr*>(exprs[i].get())->field().table_name();
      view_info.base_name = view_info.relation_name + "." + expr->name();
    } else if (exprs[i]->type() == ExprType::FUNC) {
      auto func_expr = dynamic_cast<FieldExpr*>(dynamic_cast<FuncExpr*>(expr)->child().get());
      view_info.relation_name = func_expr->field().table_name();
      // auto name = view_info.relation_name + "." + func_expr->field().field_name();
      auto name = func_expr->field().field_name();
      view_info.base_name =  FuncExpr::gen_alias(dynamic_cast<FuncExpr*>(expr)->func_type(),
          dynamic_cast<FuncExpr*>(expr)->get_parm(), name);
    } else {
      sql_debug("selct expr %s, is not field/func type.", exprs[i]->name().c_str());
      view_info.base_name = expr->name();
    }

    if (have_field) {
      view_info.name = view_infos.at(i).name;              // 设置视图属性名
    } else {
      if (!expr->alias().empty()) {
        auto pos = expr->alias().find('.');
        view_info.name = pos == std::string::npos ? expr->alias() : expr->alias().substr(pos + 1);
      } else {
        view_info.name = expr->name();
      }
    }

    infos.emplace_back(std::move(view_info));
  }
  auto *create_stmt = new CreateViewStmt(create_view.relation_name, std::move(infos), tables);
  sql_debug("create view statement: view name %s", create_view.relation_name.c_str());
  create_stmt->select_stmt_ = reinterpret_cast<SelectStmt*>(select_stmt);
  stmt = create_stmt;
  return RC::SUCCESS;
}
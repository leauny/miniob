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

  // 创建视图属性映射
  for (auto i = 0; i < exprs.size(); ++i) {
    if (exprs[i]->type() != ExprType::FIELD) {
      sql_debug("selct expr %s, is not field type.", exprs[i]->name().c_str());
      return RC::INTERNAL;
    }

    const auto expr = dynamic_cast<FieldExpr*>(exprs[i].get());

    ViewInfoSqlNode view_info{};

    view_info.base_name = expr->name();                    // 设置对应的基表属性名
    view_info.relation_name = expr->field().table_name();  // 设置基表名
    if (have_field) {
      view_info.name = view_infos.at(i).name;              // 设置视图属性名
    } else {
      if (!expr->alias().empty()) {
        auto pos = expr->alias().find('.');
        view_info.name = pos == std::string::npos ? expr->alias() : expr->alias().substr(pos + 1);
      } else {
        view_info.name = view_info.base_name;
      }
    }

    infos.emplace_back(std::move(view_info));
  }
  auto *create_stmt = new CreateViewStmt(create_view.relation_name, std::move(infos));
  sql_debug("create view statement: view name %s", create_view.relation_name.c_str());
  create_stmt->select_stmt_ = reinterpret_cast<SelectStmt*>(select_stmt);
  stmt = create_stmt;
  return RC::SUCCESS;
}
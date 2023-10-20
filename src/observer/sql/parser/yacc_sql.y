
%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <chrono>

#include "sql/parser/value.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/parser/parse_defs.h"
#include "sql/expr/expression.h"
#include "sql/parser/yacc_sql.hpp"
#include "sql/parser/lex_sql.h"
#include "storage/db/db.h"
#include "storage/field/field_meta.h"

using namespace std;

static Db* __current_db;

string token_name(const char *sql_string, YYLTYPE *llocp)
{
  return string(sql_string + llocp->first_column, llocp->last_column - llocp->first_column + 1);
}

int yyerror(YYLTYPE *llocp, const char *sql_string, ParsedSqlResult *sql_result, yyscan_t scanner, const char *msg)
{
  std::unique_ptr<ParsedSqlNode> error_sql_node = std::make_unique<ParsedSqlNode>(SCF_ERROR);
  error_sql_node->error.error_msg = msg;
  error_sql_node->error.line = llocp->first_line;
  error_sql_node->error.column = llocp->first_column;
  sql_result->add_sql_node(std::move(error_sql_node));
  return 0;
}

FieldExpr *create_field_expr(const RelAttrSqlNode &node) {
  Table* table = __current_db->find_table(node.relation_name.c_str());
  const FieldMeta* field = table->table_meta().field(node.attribute_name.c_str());

  auto expr = new FieldExpr(table, field);
  expr->set_name(field->name());
  expr->set_alias(node.relation_name.c_str());
  expr->set_func_type(node.func_type);
  expr->set_func_parm(node.func_parm.c_str());

  return expr;
}

ArithmeticExpr *create_arithmetic_expression(ArithmeticExpr::Type type,
                                             Expression *left,
                                             Expression *right,
                                             const char *sql_string,
                                             YYLTYPE *llocp)
{
  ArithmeticExpr *expr = new ArithmeticExpr(type, left, right);
  expr->set_name(token_name(sql_string, llocp));
  return expr;
}

%}

%define api.pure full
%define parse.error verbose
/** 启用位置标识 **/
%locations
%lex-param { yyscan_t scanner }
/** 这些定义了在yyparse函数中的参数 **/
%parse-param { const char * sql_string }
%parse-param { ParsedSqlResult * sql_result }
%parse-param { void * scanner }

//标识tokens
%token  SEMICOLON
        CREATE
        DROP
        TABLE
        TABLES
        INDEX
        CALC
        SELECT
        DESC
        SHOW
        SYNC
        INSERT
        DELETE
        UPDATE
        LBRACE
        RBRACE
        COMMA
        TRX_BEGIN
        TRX_COMMIT
        TRX_ROLLBACK
        INT_T
        STRING_T
        FLOAT_T
        DATE_T
        HELP
        EXIT
        DOT //QUOTE
        INTO
        VALUES
        FROM
        WHERE
        AND
        OR
        SET
        ON
        AS
        LOAD
        DATA
        INFILE
        EXPLAIN
        LENGTH
        ROUND
        DATE_FORMAT
        EQ
        LT
        GT
        LE
        GE
        NE
        LIKE
        NOT_LIKE
        INNER_JOIN
        NULL_T
        NOT_NULL
        IS
        IS_NOT



/** union 中定义各种数据类型，真实生成的代码也是union类型，所以不能有非POD类型的数据 **/
%union {
  ParsedSqlNode *                               sql_node;
  Expression *                                  condition;
  Value *                                       value;
  std::vector<Value> *                          record;
  enum CompOp                                   comp;
  enum FuncType                                 func_t;
  RelAttrSqlNode *                              rel_attr;
  std::vector<AttrInfoSqlNode> *                attr_infos;
  AttrInfoSqlNode *                             attr_info;
  Expression *                                  expression;
  std::vector<Expression *> *                   expression_list;
  std::vector<Value> *                          value_list;
  std::vector<std::vector<Value>> *             record_list;
  std::vector<Expression*>*                     condition_list;
  std::vector<Expression*>*                     rel_attr_list;
  std::vector<Expression*>*                     relation_list;
  std::vector<
    std::pair<Expression*, Expression*>
  > *                                           update_list;
  std::vector<JoinSqlNode> *                    join_list;
  char *                                        string;
  int                                           number;
  float                                         floats;
  date                                          dates;
  bool                                          bools;
}

%token <number> NUMBER
%token <floats> FLOAT
%token <string> ID
%token <string> SSS
%token <func_t> AGG
%token <dates>  DATE
//非终结符

/** type 定义了各种解析后的结果输出的是什么类型。类型对应了 union 中的定义的成员变量名称 **/
%type <sql_node>            subquery
%type <number>              type
%type <condition>           condition
%type <value>               value
%type <value_list>          record
%type <number>              number
%type <comp>                comp_op
%type <rel_attr>            rel_attr
%type <attr_infos>          attr_def_list
%type <attr_info>           attr_def
%type <value_list>          value_list
%type <record_list>         record_list
%type <condition_list>      where
%type <condition_list>      condition_list
%type <rel_attr_list>       select_attr
%type <relation_list>       rel_list
%type <rel_attr_list>       attr_list
%type <update_list>         update_list
%type <expression>          expression
%type <expression_list>     expression_list
%type <join_list>           join_stmt
%type <sql_node>            calc_stmt
%type <sql_node>            select_stmt
%type <sql_node>            insert_stmt
%type <sql_node>            update_stmt
%type <sql_node>            delete_stmt
%type <sql_node>            create_table_stmt
%type <sql_node>            drop_table_stmt
%type <sql_node>            show_tables_stmt
%type <sql_node>            show_index_stmt
%type <sql_node>            desc_table_stmt
%type <sql_node>            create_index_stmt
%type <sql_node>            drop_index_stmt
%type <sql_node>            sync_stmt
%type <sql_node>            begin_stmt
%type <sql_node>            commit_stmt
%type <sql_node>            rollback_stmt
%type <sql_node>            load_data_stmt
%type <sql_node>            explain_stmt
%type <sql_node>            set_variable_stmt
%type <sql_node>            help_stmt
%type <sql_node>            exit_stmt
%type <sql_node>            command_wrapper
%type <bools>               is_nullable
// commands should be a list but I use a single command instead
%type <sql_node>            commands

%left '+' '-'
%left '*' '/'
%nonassoc UMINUS
%%

commands: command_wrapper opt_semicolon  //commands or sqls. parser starts here.
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>($1);
    sql_result->add_sql_node(std::move(sql_node));
  }
  ;

command_wrapper:
    calc_stmt
  | select_stmt
  | insert_stmt
  | update_stmt
  | delete_stmt
  | create_table_stmt
  | drop_table_stmt
  | show_tables_stmt
  | show_index_stmt
  | desc_table_stmt
  | create_index_stmt
  | drop_index_stmt
  | sync_stmt
  | begin_stmt
  | commit_stmt
  | rollback_stmt
  | load_data_stmt
  | explain_stmt
  | set_variable_stmt
  | help_stmt
  | exit_stmt
    ;

exit_stmt:      
    EXIT {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      $$ = new ParsedSqlNode(SCF_EXIT);
    };

help_stmt:
    HELP {
      $$ = new ParsedSqlNode(SCF_HELP);
    };

sync_stmt:
    SYNC {
      $$ = new ParsedSqlNode(SCF_SYNC);
    }
    ;

begin_stmt:
    TRX_BEGIN  {
      $$ = new ParsedSqlNode(SCF_BEGIN);
    }
    ;

commit_stmt:
    TRX_COMMIT {
      $$ = new ParsedSqlNode(SCF_COMMIT);
    }
    ;

rollback_stmt:
    TRX_ROLLBACK  {
      $$ = new ParsedSqlNode(SCF_ROLLBACK);
    }
    ;

drop_table_stmt:    /*drop table 语句的语法解析树*/
    DROP TABLE ID {
      $$ = new ParsedSqlNode(SCF_DROP_TABLE);
      $$->drop_table.relation_name = $3;
      free($3);
    };

show_tables_stmt:
    SHOW TABLES {
      $$ = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
    ;

show_index_stmt:
    SHOW INDEX FROM ID {
      $$ = new ParsedSqlNode(SCF_SHOW_INDEX);
      $$->show_index.relation_name = $4;
    }
    ;

desc_table_stmt:
    DESC ID  {
      $$ = new ParsedSqlNode(SCF_DESC_TABLE);
      $$->desc_table.relation_name = $2;
      free($2);
    }
    ;

create_index_stmt:    /*create index 语句的语法解析树*/
    CREATE INDEX ID ON ID LBRACE ID RBRACE
    {
      $$ = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = $$->create_index;
      create_index.index_name = $3;
      create_index.relation_name = $5;
      create_index.attribute_name = $7;
      free($3);
      free($5);
      free($7);
    }
    ;

drop_index_stmt:      /*drop index 语句的语法解析树*/
    DROP INDEX ID ON ID
    {
      $$ = new ParsedSqlNode(SCF_DROP_INDEX);
      $$->drop_index.index_name = $3;
      $$->drop_index.relation_name = $5;
      free($3);
      free($5);
    }
    ;
create_table_stmt:    /*create table 语句的语法解析树*/
    CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE
    {
      $$ = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = $$->create_table;
      create_table.relation_name = $3;
      free($3);

      std::vector<AttrInfoSqlNode> *src_attrs = $6;

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
      }
      create_table.attr_infos.emplace_back(*$5);
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete $5;
    }
    ;
attr_def_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | COMMA attr_def attr_def_list
    {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<AttrInfoSqlNode>;
      }
      $$->emplace_back(*$2);
      delete $2;
    }
    ;
    
attr_def:
    ID type LBRACE number RBRACE is_nullable
    {
      $$ = new AttrInfoSqlNode;
      $$->type = (AttrType)$2;
      $$->name = $1;
      $$->length = $4 + 1;
      if ($6) {
        $$->nullable = true;
      }
      free($1);
    }
    | ID type is_nullable
    {
      $$ = new AttrInfoSqlNode;
      $$->type = (AttrType)$2;
      $$->name = $1;
      if ($2 == DATES) {
        $$->length = 10;
      } else {
        $$->length = 4;
      }
      if ($3) {
        $$->nullable = true;
      }
      free($1);
    }
    ;
is_nullable:
     /* empty */
     {
       $$ = false;
     }
     | NOT_NULL
     {
       $$ = false;
     }
     | NULL_T {
       $$ = true;
     }
number:
    NUMBER {$$ = $1;}
    ;
type:
    INT_T      { $$=INTS; }
    | STRING_T { $$=CHARS; }
    | FLOAT_T  { $$=FLOATS; }
    | DATE_T   { $$=DATES; }
    ;
insert_stmt:        /*insert   语句的语法解析树*/
    INSERT INTO ID VALUES record_list
    {
      $$ = new ParsedSqlNode(SCF_INSERT);
      $$->insertion.relation_name = $3;
      $$->insertion.values.swap(*$5);
    }
    ;
record_list:    /*insert  语句的多个record内容 */
    record
    {
      $$ = new std::vector<std::vector<Value>>;
      $$->emplace_back(std::move(*$1));
    }
    | record_list COMMA record
    {
      // 无需考虑插入顺序
      if ($1 != nullptr) {
        $$ = $1;
      } else {
      $$ = new std::vector<std::vector<Value>>;
      }
      $$->emplace_back(std::move(*$3));
    }
    ;
record:
    LBRACE value value_list RBRACE
    {
      if ($3 != nullptr) {
        $$ = std::move($3);
      } else {
        $$ = new std::vector<Value>;
      }
      // 尾差法之后全部reverse
      $$->emplace_back(std::move(*$2));
      std::reverse($$->begin(), $$->end());
    }
    ;
value_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | COMMA value value_list  { 
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<Value>;
      }
      $$->emplace_back(*$2);
      delete $2;
    }
    ;
value:
    NUMBER {
      $$ = new Value((int)$1);
      @$ = @1;
    }
    |FLOAT {
      $$ = new Value((float)$1);
      @$ = @1;
    }
    |SSS {
      char *tmp = common::substr($1,1,strlen($1)-2);
      $$ = new Value(tmp);
      free(tmp);
    }
    |DATE {
      $$ = new Value((date)$1);
      @$ = @1;
    }
    |NULL_T {
      $$ = new Value();
      $$->set_null();
      @$ = @1;
    }
    | LENGTH LBRACE value RBRACE
    {
        if ($3->attr_type() != AttrType::CHARS) {
          LOG_ERROR("length function only support string type.");
          return -1;
        }
        $$ = new Value((int)$3->get_string().size());  // translate into int
        free($3);
    }
    | ROUND LBRACE value COMMA number RBRACE
    {
        if ($3->attr_type() != AttrType::FLOATS) {
          LOG_ERROR("round function only support float type.");
          return -1;
        }
        $$ = new Value((float)(std::round($3->get_float() * pow(10, $5)) / pow(10, $5)));
        free($3);
    }
    | DATE_FORMAT LBRACE value COMMA SSS RBRACE
    {
        if ($3->attr_type() != AttrType::DATES) {
          LOG_ERROR("data_format function only support date type.");
          return -1;
        }
        $$ = new Value((date)$3->get_date(), common::substr($5,1,strlen($5)-2));
        free($3);
    }
    ;
    
delete_stmt:    /*  delete 语句的语法解析树*/
    DELETE FROM ID where 
    {
      $$ = new ParsedSqlNode(SCF_DELETE);
      $$->deletion.relation_name = $3;
      if ($4 != nullptr) {
        $$->deletion.conditions.swap(*$4);
      }
      free($3);
    }
    ;
update_stmt:      /*  update 语句的语法解析树*/
    UPDATE ID SET update_list where
    {
      $$ = new ParsedSqlNode(SCF_UPDATE);
      $$->update.relation_name = $2;
      if ($5 != nullptr) {
        $$->update.conditions.swap(*$5);
      }
      for (auto &[expr, value] : *$4) {
        RelAttrExpr* rel = reinterpret_cast<RelAttrExpr*>(expr);
        rel->node().relation_name = $2; 
        $$->update.update_fields.emplace_back(
          std::make_pair(create_field_expr(rel->node()), value)
        );
      }
      free($2);
    }
    ;
update_list:
    ID EQ value {
      $$ = new std::vector<std::pair<Expression*, Expression*>>;
      RelAttrSqlNode tmp;
      tmp.attribute_name = $1;
      $$->emplace_back(make_pair(new RelAttrExpr(tmp), new ValueExpr(*$3)));
      free($1);
      free($3);
    }
    | update_list COMMA ID EQ value
    {
      if ($1 != nullptr) {
        $$ = $1;
      } else {
        $$ = new std::vector<std::pair<Expression*, Expression*>>;
      }
      RelAttrSqlNode tmp;
      tmp.attribute_name = $3;
      $$->emplace_back(make_pair(new RelAttrExpr(tmp), new ValueExpr(*$5)));
      free($3);
      free($5);
    }
    | ID EQ subquery {
      $$ = new std::vector<std::pair<Expression*, Expression*>>;
      RelAttrSqlNode tmp;
      tmp.attribute_name = $1;
      $$->emplace_back(make_pair(new RelAttrExpr(tmp), new SubQueryExpr($3->selection)));
      free($1);
      delete $3;  // new SubQueryExpr($3->selection)已经move了部分字段，可能有问题
    }
    | update_list COMMA ID EQ subquery
    {
      if ($1 != nullptr) {
        $$ = $1;
      } else {
        $$ = new std::vector<std::pair<Expression*, Expression*>>;
      }
      RelAttrSqlNode tmp;
      tmp.attribute_name = $3;
      $$->emplace_back(make_pair(new RelAttrExpr(tmp), new SubQueryExpr($5->selection)));
      free($3);
    }
    ;
subquery:
    LBRACE select_stmt RBRACE {
      $$ = $2;
    }
    ;
select_stmt:        /*  select 语句的语法解析树*/
    SELECT select_attr FROM ID rel_list where
    {
      $$ = new ParsedSqlNode(SCF_SELECT);
      if ($2 != nullptr) {
        $$->selection.attributes.swap(*$2);
        delete $2;
      }
      if ($5 != nullptr) {
        $$->selection.relations.swap(*$5);
        delete $5;
      }
      $$->selection.relations.push_back(new TableExpr($4));
      std::reverse($$->selection.relations.begin(), $$->selection.relations.end());
      free($4);

      if ($6 != nullptr) {
        $$->selection.conditions.swap(*$6);
      }
    }
    | SELECT select_attr FROM ID ID rel_list where
    {
      $$ = new ParsedSqlNode(SCF_SELECT);
      if ($2 != nullptr) {
        $$->selection.attributes.swap(*$2);
        delete $2;
      }
      if ($6 != nullptr) {
        $$->selection.relations.swap(*$6);
        delete $6;
      }
      $$->selection.relations.push_back(new TableExpr($4, $5));
      std::reverse($$->selection.relations.begin(), $$->selection.relations.end());
      free($4);
      free($5);

      if ($7 != nullptr) {
        $$->selection.conditions.swap(*$7);
      }
    }
    | SELECT select_attr FROM ID AS ID rel_list where
    {
      $$ = new ParsedSqlNode(SCF_SELECT);
      if ($2 != nullptr) {
        $$->selection.attributes.swap(*$2);
        delete $2;
      }
      if ($7 != nullptr) {
        $$->selection.relations.swap(*$7);
        delete $7;
      }
      $$->selection.relations.push_back(new TableExpr($4, $6));
      std::reverse($$->selection.relations.begin(), $$->selection.relations.end());
      free($4);
      free($6);

      if ($8 != nullptr) {
        $$->selection.conditions.swap(*$8);
        delete $8;
      }
    }
    | SELECT select_attr FROM ID join_stmt where
    {
      $$ = new ParsedSqlNode(SCF_SELECT);
      if ($2 != nullptr) {
        $$->selection.attributes.swap(*$2);
        delete $2;
      }
      if ($6 != nullptr) {
        $$->selection.conditions.swap(*$6);
      }
      if ($5 != nullptr) {
        for (auto &join : *$5) {
          $$->selection.relations.push_back(join.relation_name);
          for (auto &cond : join.conditions) {
            $$->selection.conditions.emplace_back(cond);
          }
        }
        delete $5;
      }
      $$->selection.relations.push_back(new TableExpr($4));
      std::reverse($$->selection.relations.begin(), $$->selection.relations.end());
      free($4);
    }
    ;
select_attr:
    '*' attr_list {
      if ($2 != nullptr) {
        $$ = $2;
      } else {
        $$ = new std::vector<Expression*>;
      }
      $$->emplace_back(new StarExpr(false));
    }
    | rel_attr attr_list {
      if ($2 != nullptr) {
        $$ = $2;
      } else {
        $$ = new std::vector<Expression*>;
      }
      if (0 == strcmp($1->attribute_name.c_str(), "*")) {
        bool is_wcount = $1->func_type == FUNC_WCOUNT ? true : false;
        $$->emplace_back(new StarExpr(is_wcount));
      } else {
        $$->emplace_back(create_field_expr(*$1));
      }
      delete $1;
    }
    ;

rel_attr:
    ID {
      $$ = new RelAttrSqlNode;
      $$->attribute_name = $1;
      free($1);
    }
    | ID ID {
        $$ = new RelAttrSqlNode;
        $$->attribute_name = $1;
        $$->alias = $2;
        free($1);
        free($2);
        LOG_DEBUG("alias: %s", $$->alias.c_str());
    }
    | ID AS ID {
        $$ = new RelAttrSqlNode;
        $$->attribute_name = $1;
        $$->alias = $3;
        free($1);
        free($3);
        LOG_DEBUG("alias: %s", $$->alias.c_str());
    }
    | ID DOT ID {
      $$ = new RelAttrSqlNode;
      $$->relation_name  = $1;
      $$->attribute_name = $3;
      free($1);
      free($3);
    }
    | AGG LBRACE '*' RBRACE {
      $$ = new RelAttrSqlNode;
      $$->relation_name  = "";
      $$->attribute_name = "*";
      if ($1 != FUNC_COUNT) {
        LOG_ERROR("Aggregation * only support count(*).");
        return -1;
      }
      $$->func_type = FUNC_WCOUNT;  // 通配符版本的count
    }
    | AGG LBRACE rel_attr RBRACE {
      $$ = $3;
      $$->func_type = $1;
    }
    | LENGTH LBRACE rel_attr RBRACE {
      $$ = $3;
      $$->func_type = FUNC_LENGTH;
    }
    | ROUND LBRACE rel_attr COMMA number RBRACE {
      $$ = $3;
      $$->func_type = FUNC_ROUND;
      $$->func_parm = std::to_string($5);
    }
    | DATE_FORMAT LBRACE rel_attr COMMA SSS RBRACE {
      $$ = $3;
      $$->func_type = FUNC_DATE_FORMAT;
      $$->func_parm = common::substr($5,1,strlen($5)-2);
      free($5);
    }
    ;

attr_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | COMMA rel_attr attr_list {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<Expression*>;
      }
      $$->emplace_back(create_field_expr(*$2));
      delete $2;
    }
    ;

rel_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | COMMA ID rel_list {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<Expression*>();
      }

      $$->emplace_back(new TableExpr($2));
      free($2);
    }
    | COMMA ID ID rel_list {
      if ($4 != nullptr) {
        $$ = $4;
      } else {
        $$ = new std::vector<Expression*>();
      }

      $$->emplace_back(new TableExpr($2, $3));
      free($2);
      free($3);
    }
    | COMMA ID AS ID rel_list {
      if ($5 != nullptr) {
        $$ = $5;
      } else {
        $$ = new std::vector<Expression*>();
      }

      $$->emplace_back(new TableExpr($2, $4));
      free($2);
      free($4);
    }
    ;
where:
    /* empty */
    {
      $$ = nullptr;
    }
    | WHERE condition_list {
      $$ = $2;
    }
    ;
condition_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | condition {
      $$ = new std::vector<Expression*>;
      $$->emplace_back($1);
    }
    | condition AND condition_list {
      if ($3) {
        $$ = $3;
      } else {
        $$ = new std::vector<Expression*>;
      }
      std::vector<std::unique_ptr<Expression>> children;
      children.emplace_back($1);
      $$->emplace_back(new ConjunctionExpr(ConjunctionExpr::Type::AND, children));
    }
    | condition OR condition_list {
      if ($3) {
        $$ = $3;
      } else {
        $$ = new std::vector<Expression*>;
      }
      std::vector<std::unique_ptr<Expression>> children;
      children.emplace_back($1);
      $$->emplace_back(new ConjunctionExpr(ConjunctionExpr::Type::OR, children));
    }
    ;
condition:
    rel_attr comp_op expression
    {
      auto value_r = Value();
      $3->try_get_value(value_r);
      $$ = new ComparisonExpr($2,
            std::unique_ptr<FieldExpr>(create_field_expr(*$1)),
            std::make_unique<ValueExpr>(value_r)
            );
    }
    | rel_attr comp_op rel_attr
    {
      $$ = new ComparisonExpr($2,
            std::unique_ptr<FieldExpr>(create_field_expr(*$1)),
            std::unique_ptr<FieldExpr>(create_field_expr(*$3))
            );
    }
    | expression comp_op rel_attr
    {
      auto value_l = Value();
      $1->try_get_value(value_l);
      $$ = new ComparisonExpr($2, std::make_unique<ValueExpr>(value_l), std::unique_ptr<FieldExpr>(create_field_expr(*$3)));
    }
    | expression comp_op expression
    {
      // 直接获取表达式的值, 只支持ArithmeticExpr或ValueExpr
      auto value_l = Value();
      auto value_r = Value();
      $1->try_get_value(value_l);
      $3->try_get_value(value_r);
      $$ = new ComparisonExpr($2, std::make_unique<ValueExpr>(value_l), std::make_unique<ValueExpr>(value_r));
    }
    ;
comp_op:
      EQ { $$ = EQUAL_TO; }
    | LT { $$ = LESS_THAN; }
    | GT { $$ = GREAT_THAN; }
    | LE { $$ = LESS_EQUAL; }
    | GE { $$ = GREAT_EQUAL; }
    | NE { $$ = NOT_EQUAL; }
    | LIKE { $$ = LIKE_TO; }
    | NOT_LIKE { $$ = NOT_LIKE_TO; }
    | IS { $$ = IS_NULL; }
    | IS_NOT { $$ = IS_NOT_NULL; }
    ;
join_stmt:
    INNER_JOIN ID ON condition_list {
      $$ = new std::vector<JoinSqlNode>;
      JoinSqlNode join;
      join.relation_name = new TableExpr($2);
      join.conditions.swap(*$4);
      $$->emplace_back(join);
      free($2);
    }
    | INNER_JOIN ID ON condition_list join_stmt {
      if ($5 != nullptr) {
        $$ = $5;
      } else {
        $$ = new std::vector<JoinSqlNode>;
      }
      JoinSqlNode join;
      join.relation_name = new TableExpr($2);
      join.conditions.swap(*$4);
      $$->emplace_back(join);
      free($2);
    }
    ;

calc_stmt:
    CALC expression_list
    {
      $$ = new ParsedSqlNode(SCF_CALC);
      std::reverse($2->begin(), $2->end());
      $$->calc.expressions.swap(*$2);
      delete $2;
    }
    ;

expression_list:
    expression
    {
      $$ = new std::vector<Expression*>;
      $$->emplace_back($1);
    }
    | expression COMMA expression_list
    {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<Expression *>;
      }
      $$->emplace_back($1);
    }
    ;
expression:
    expression '+' expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::ADD, $1, $3, sql_string, &@$);
    }
    | expression '-' expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::SUB, $1, $3, sql_string, &@$);
    }
    | expression '*' expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::MUL, $1, $3, sql_string, &@$);
    }
    | expression '/' expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::DIV, $1, $3, sql_string, &@$);
    }
    | LBRACE expression RBRACE {
      $$ = $2;
      $$->set_name(token_name(sql_string, &@$));
    }
    | '-' expression %prec UMINUS {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, $2, nullptr, sql_string, &@$);
    }
    | value {
      $$ = new ValueExpr(*$1);
      $$->set_name(token_name(sql_string, &@$));
      delete $1;
    }
    ;

load_data_stmt:
    LOAD DATA INFILE SSS INTO TABLE ID 
    {
      char *tmp_file_name = common::substr($4, 1, strlen($4) - 2);
      
      $$ = new ParsedSqlNode(SCF_LOAD_DATA);
      $$->load_data.relation_name = $7;
      $$->load_data.file_name = tmp_file_name;
      free($7);
      free(tmp_file_name);
    }
    ;

explain_stmt:
    EXPLAIN command_wrapper
    {
      $$ = new ParsedSqlNode(SCF_EXPLAIN);
      $$->explain.sql_node = std::unique_ptr<ParsedSqlNode>($2);
    }
    ;

set_variable_stmt:
    SET ID EQ value
    {
      $$ = new ParsedSqlNode(SCF_SET_VARIABLE);
      $$->set_variable.name  = $2;
      $$->set_variable.value = *$4;
      free($2);
      delete $4;
    }
    ;

opt_semicolon: /*empty*/
    | SEMICOLON
    ;
%%
//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(Db* db, const char *s, ParsedSqlResult *sql_result) {
  __current_db = db;
  yyscan_t scanner;
  yylex_init(&scanner);
  scan_string(s, scanner);
  int result = yyparse(s, sql_result, scanner);
  yylex_destroy(scanner);
  __current_db = nullptr;
  return result;
}

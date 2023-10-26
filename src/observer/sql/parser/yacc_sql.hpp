/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_YACC_SQL_HPP_INCLUDED
# define YY_YY_YACC_SQL_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    FLOAT = 259,                   /* FLOAT  */
    ID = 260,                      /* ID  */
    SSS = 261,                     /* SSS  */
    AGG = 262,                     /* AGG  */
    DATE = 263,                    /* DATE  */
    SEMICOLON = 264,               /* SEMICOLON  */
    CREATE = 265,                  /* CREATE  */
    DROP = 266,                    /* DROP  */
    TABLE = 267,                   /* TABLE  */
    TABLES = 268,                  /* TABLES  */
    INDEX = 269,                   /* INDEX  */
    CALC = 270,                    /* CALC  */
    SELECT = 271,                  /* SELECT  */
    DESC = 272,                    /* DESC  */
    SHOW = 273,                    /* SHOW  */
    SYNC = 274,                    /* SYNC  */
    INSERT = 275,                  /* INSERT  */
    DELETE = 276,                  /* DELETE  */
    UPDATE = 277,                  /* UPDATE  */
    LBRACE = 278,                  /* LBRACE  */
    RBRACE = 279,                  /* RBRACE  */
    COMMA = 280,                   /* COMMA  */
    TRX_BEGIN = 281,               /* TRX_BEGIN  */
    TRX_COMMIT = 282,              /* TRX_COMMIT  */
    TRX_ROLLBACK = 283,            /* TRX_ROLLBACK  */
    INT_T = 284,                   /* INT_T  */
    STRING_T = 285,                /* STRING_T  */
    FLOAT_T = 286,                 /* FLOAT_T  */
    DATE_T = 287,                  /* DATE_T  */
    HELP = 288,                    /* HELP  */
    EXIT = 289,                    /* EXIT  */
    DOT = 290,                     /* DOT  */
    INTO = 291,                    /* INTO  */
    VALUES = 292,                  /* VALUES  */
    FROM = 293,                    /* FROM  */
    WHERE = 294,                   /* WHERE  */
    AND = 295,                     /* AND  */
    OR = 296,                      /* OR  */
    SET = 297,                     /* SET  */
    ON = 298,                      /* ON  */
    AS = 299,                      /* AS  */
    LOAD = 300,                    /* LOAD  */
    DATA = 301,                    /* DATA  */
    INFILE = 302,                  /* INFILE  */
    EXPLAIN = 303,                 /* EXPLAIN  */
    LENGTH = 304,                  /* LENGTH  */
    ROUND = 305,                   /* ROUND  */
    DATE_FORMAT = 306,             /* DATE_FORMAT  */
    EQ = 307,                      /* EQ  */
    LT = 308,                      /* LT  */
    GT = 309,                      /* GT  */
    LE = 310,                      /* LE  */
    GE = 311,                      /* GE  */
    NE = 312,                      /* NE  */
    LIKE = 313,                    /* LIKE  */
    NOT_LIKE = 314,                /* NOT_LIKE  */
    INNER_JOIN = 315,              /* INNER_JOIN  */
    NULL_T = 316,                  /* NULL_T  */
    NOT_NULL = 317,                /* NOT_NULL  */
    IS = 318,                      /* IS  */
    IS_NOT = 319,                  /* IS_NOT  */
    UNIQUE = 320,                  /* UNIQUE  */
    IN_ = 321,                     /* IN_  */
    NOT_IN_ = 322,                 /* NOT_IN_  */
    EXISTS = 323,                  /* EXISTS  */
    NOT_EXISTS = 324,              /* NOT_EXISTS  */
    UMINUS = 325                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 62 "yacc_sql.y"

  ParsedSqlNode *                               sql_node;
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
  std::vector<
    std::pair<std::string, Expression*>
  > *                                           update_list;
  std::vector<JoinSqlNode> *                    join_list;
  std::vector<std::string> *                    field_list;
  char *                                        string;
  int                                           number;
  float                                         floats;
  date                                          dates;
  bool                                          bools;

#line 159 "yacc_sql.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif




int yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner);


#endif /* !YY_YY_YACC_SQL_HPP_INCLUDED  */

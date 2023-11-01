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
    ASC = 272,                     /* ASC  */
    DESC = 273,                    /* DESC  */
    SHOW = 274,                    /* SHOW  */
    SYNC = 275,                    /* SYNC  */
    INSERT = 276,                  /* INSERT  */
    DELETE = 277,                  /* DELETE  */
    UPDATE = 278,                  /* UPDATE  */
    LBRACE = 279,                  /* LBRACE  */
    RBRACE = 280,                  /* RBRACE  */
    COMMA = 281,                   /* COMMA  */
    TRX_BEGIN = 282,               /* TRX_BEGIN  */
    TRX_COMMIT = 283,              /* TRX_COMMIT  */
    TRX_ROLLBACK = 284,            /* TRX_ROLLBACK  */
    INT_T = 285,                   /* INT_T  */
    STRING_T = 286,                /* STRING_T  */
    FLOAT_T = 287,                 /* FLOAT_T  */
    DATE_T = 288,                  /* DATE_T  */
    TEXT_T = 289,                  /* TEXT_T  */
    HELP = 290,                    /* HELP  */
    EXIT = 291,                    /* EXIT  */
    DOT = 292,                     /* DOT  */
    INTO = 293,                    /* INTO  */
    VALUES = 294,                  /* VALUES  */
    FROM = 295,                    /* FROM  */
    WHERE = 296,                   /* WHERE  */
    OR = 297,                      /* OR  */
    AND = 298,                     /* AND  */
    SET = 299,                     /* SET  */
    ON = 300,                      /* ON  */
    AS = 301,                      /* AS  */
    LOAD = 302,                    /* LOAD  */
    DATA = 303,                    /* DATA  */
    INFILE = 304,                  /* INFILE  */
    EXPLAIN = 305,                 /* EXPLAIN  */
    LENGTH = 306,                  /* LENGTH  */
    ROUND = 307,                   /* ROUND  */
    DATE_FORMAT = 308,             /* DATE_FORMAT  */
    EQ = 309,                      /* EQ  */
    LT = 310,                      /* LT  */
    GT = 311,                      /* GT  */
    LE = 312,                      /* LE  */
    GE = 313,                      /* GE  */
    NE = 314,                      /* NE  */
    LIKE = 315,                    /* LIKE  */
    NOT_LIKE = 316,                /* NOT_LIKE  */
    INNER_JOIN = 317,              /* INNER_JOIN  */
    NULL_T = 318,                  /* NULL_T  */
    NOT_NULL = 319,                /* NOT_NULL  */
    IS = 320,                      /* IS  */
    IS_NOT = 321,                  /* IS_NOT  */
    UNIQUE = 322,                  /* UNIQUE  */
    IN_ = 323,                     /* IN_  */
    NOT_IN_ = 324,                 /* NOT_IN_  */
    EXISTS = 325,                  /* EXISTS  */
    NOT_EXISTS = 326,              /* NOT_EXISTS  */
    GROUP_BY = 327,                /* GROUP_BY  */
    ORDER_BY = 328,                /* ORDER_BY  */
    HAVING = 329,                  /* HAVING  */
    UMINUS = 330                   /* UMINUS  */
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

#line 164 "yacc_sql.hpp"

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

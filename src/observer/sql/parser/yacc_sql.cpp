/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


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

using namespace std;

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


#line 120 "yacc_sql.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "yacc_sql.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_SSS = 6,                        /* SSS  */
  YYSYMBOL_AGG = 7,                        /* AGG  */
  YYSYMBOL_DATE = 8,                       /* DATE  */
  YYSYMBOL_SEMICOLON = 9,                  /* SEMICOLON  */
  YYSYMBOL_CREATE = 10,                    /* CREATE  */
  YYSYMBOL_DROP = 11,                      /* DROP  */
  YYSYMBOL_VIEW = 12,                      /* VIEW  */
  YYSYMBOL_TABLE = 13,                     /* TABLE  */
  YYSYMBOL_TABLES = 14,                    /* TABLES  */
  YYSYMBOL_INDEX = 15,                     /* INDEX  */
  YYSYMBOL_CALC = 16,                      /* CALC  */
  YYSYMBOL_SELECT = 17,                    /* SELECT  */
  YYSYMBOL_ASC = 18,                       /* ASC  */
  YYSYMBOL_DESC = 19,                      /* DESC  */
  YYSYMBOL_SHOW = 20,                      /* SHOW  */
  YYSYMBOL_SYNC = 21,                      /* SYNC  */
  YYSYMBOL_INSERT = 22,                    /* INSERT  */
  YYSYMBOL_DELETE = 23,                    /* DELETE  */
  YYSYMBOL_UPDATE = 24,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 25,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 26,                    /* RBRACE  */
  YYSYMBOL_COMMA = 27,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 28,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 29,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 30,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 31,                     /* INT_T  */
  YYSYMBOL_STRING_T = 32,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 33,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 34,                    /* DATE_T  */
  YYSYMBOL_TEXT_T = 35,                    /* TEXT_T  */
  YYSYMBOL_HELP = 36,                      /* HELP  */
  YYSYMBOL_EXIT = 37,                      /* EXIT  */
  YYSYMBOL_DOT = 38,                       /* DOT  */
  YYSYMBOL_INTO = 39,                      /* INTO  */
  YYSYMBOL_VALUES = 40,                    /* VALUES  */
  YYSYMBOL_FROM = 41,                      /* FROM  */
  YYSYMBOL_WHERE = 42,                     /* WHERE  */
  YYSYMBOL_OR = 43,                        /* OR  */
  YYSYMBOL_AND = 44,                       /* AND  */
  YYSYMBOL_SET = 45,                       /* SET  */
  YYSYMBOL_ON = 46,                        /* ON  */
  YYSYMBOL_AS = 47,                        /* AS  */
  YYSYMBOL_LOAD = 48,                      /* LOAD  */
  YYSYMBOL_DATA = 49,                      /* DATA  */
  YYSYMBOL_INFILE = 50,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 51,                   /* EXPLAIN  */
  YYSYMBOL_LENGTH = 52,                    /* LENGTH  */
  YYSYMBOL_ROUND = 53,                     /* ROUND  */
  YYSYMBOL_DATE_FORMAT = 54,               /* DATE_FORMAT  */
  YYSYMBOL_EQ = 55,                        /* EQ  */
  YYSYMBOL_LT = 56,                        /* LT  */
  YYSYMBOL_GT = 57,                        /* GT  */
  YYSYMBOL_LE = 58,                        /* LE  */
  YYSYMBOL_GE = 59,                        /* GE  */
  YYSYMBOL_NE = 60,                        /* NE  */
  YYSYMBOL_LIKE = 61,                      /* LIKE  */
  YYSYMBOL_NOT_LIKE = 62,                  /* NOT_LIKE  */
  YYSYMBOL_INNER_JOIN = 63,                /* INNER_JOIN  */
  YYSYMBOL_NULL_T = 64,                    /* NULL_T  */
  YYSYMBOL_NOT_NULL = 65,                  /* NOT_NULL  */
  YYSYMBOL_IS = 66,                        /* IS  */
  YYSYMBOL_IS_NOT = 67,                    /* IS_NOT  */
  YYSYMBOL_UNIQUE = 68,                    /* UNIQUE  */
  YYSYMBOL_IN_ = 69,                       /* IN_  */
  YYSYMBOL_NOT_IN_ = 70,                   /* NOT_IN_  */
  YYSYMBOL_EXISTS = 71,                    /* EXISTS  */
  YYSYMBOL_NOT_EXISTS = 72,                /* NOT_EXISTS  */
  YYSYMBOL_GROUP_BY = 73,                  /* GROUP_BY  */
  YYSYMBOL_ORDER_BY = 74,                  /* ORDER_BY  */
  YYSYMBOL_HAVING = 75,                    /* HAVING  */
  YYSYMBOL_76_ = 76,                       /* '+'  */
  YYSYMBOL_77_ = 77,                       /* '-'  */
  YYSYMBOL_78_ = 78,                       /* '*'  */
  YYSYMBOL_79_ = 79,                       /* '/'  */
  YYSYMBOL_UMINUS = 80,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 81,                  /* $accept  */
  YYSYMBOL_commands = 82,                  /* commands  */
  YYSYMBOL_command_wrapper = 83,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 84,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 85,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 86,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 87,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 88,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 89,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 90,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 91,          /* show_tables_stmt  */
  YYSYMBOL_show_index_stmt = 92,           /* show_index_stmt  */
  YYSYMBOL_desc_table_stmt = 93,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 94,         /* create_index_stmt  */
  YYSYMBOL_is_unique = 95,                 /* is_unique  */
  YYSYMBOL_id_list = 96,                   /* id_list  */
  YYSYMBOL_alias = 97,                     /* alias  */
  YYSYMBOL_drop_index_stmt = 98,           /* drop_index_stmt  */
  YYSYMBOL_create_view_stmt = 99,          /* create_view_stmt  */
  YYSYMBOL_create_table_stmt = 100,        /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 101,            /* attr_def_list  */
  YYSYMBOL_attr_def = 102,                 /* attr_def  */
  YYSYMBOL_is_nullable = 103,              /* is_nullable  */
  YYSYMBOL_number = 104,                   /* number  */
  YYSYMBOL_type = 105,                     /* type  */
  YYSYMBOL_insert_stmt = 106,              /* insert_stmt  */
  YYSYMBOL_record_list = 107,              /* record_list  */
  YYSYMBOL_record = 108,                   /* record  */
  YYSYMBOL_value_list = 109,               /* value_list  */
  YYSYMBOL_value = 110,                    /* value  */
  YYSYMBOL_delete_stmt = 111,              /* delete_stmt  */
  YYSYMBOL_update_stmt = 112,              /* update_stmt  */
  YYSYMBOL_update_list = 113,              /* update_list  */
  YYSYMBOL_subquery = 114,                 /* subquery  */
  YYSYMBOL_select_stmt = 115,              /* select_stmt  */
  YYSYMBOL_attr_list = 116,                /* attr_list  */
  YYSYMBOL_rel_attr = 117,                 /* rel_attr  */
  YYSYMBOL_rel_list = 118,                 /* rel_list  */
  YYSYMBOL_order_list = 119,               /* order_list  */
  YYSYMBOL_where = 120,                    /* where  */
  YYSYMBOL_condition_list = 121,           /* condition_list  */
  YYSYMBOL_condition = 122,                /* condition  */
  YYSYMBOL_rel_expr = 123,                 /* rel_expr  */
  YYSYMBOL_comp_op = 124,                  /* comp_op  */
  YYSYMBOL_join_stmt = 125,                /* join_stmt  */
  YYSYMBOL_calc_stmt = 126,                /* calc_stmt  */
  YYSYMBOL_expression_list = 127,          /* expression_list  */
  YYSYMBOL_expression = 128,               /* expression  */
  YYSYMBOL_load_data_stmt = 129,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 130,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 131,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 132             /* opt_semicolon  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  85
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   772

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  81
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  186
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  366

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   331


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    78,    76,     2,    77,     2,    79,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    80
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   222,   222,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   255,   261,   266,   272,   278,
     284,   290,   295,   303,   309,   316,   324,   343,   346,   351,
     357,   366,   369,   375,   386,   398,   426,   442,   463,   478,
     481,   494,   505,   525,   528,   532,   536,   539,   540,   541,
     542,   543,   546,   554,   559,   571,   585,   588,   599,   603,
     607,   613,   621,   626,   636,   646,   656,   669,   680,   694,
     700,   711,   717,   729,   734,   754,   833,   944,   988,   992,
     999,  1003,  1009,  1013,  1019,  1027,  1035,  1044,  1052,  1064,
    1069,  1076,  1086,  1090,  1094,  1099,  1104,  1113,  1121,  1130,
    1138,  1147,  1162,  1178,  1190,  1206,  1221,  1236,  1251,  1270,
    1273,  1279,  1282,  1288,  1298,  1310,  1314,  1321,  1328,  1335,
    1342,  1349,  1356,  1366,  1376,  1389,  1399,  1409,  1419,  1432,
    1437,  1445,  1452,  1459,  1466,  1473,  1480,  1487,  1494,  1501,
    1508,  1515,  1522,  1529,  1536,  1559,  1560,  1561,  1562,  1563,
    1564,  1565,  1566,  1567,  1568,  1572,  1580,  1592,  1600,  1615,
    1622,  1631,  1636,  1643,  1652,  1665,  1670,  1673,  1676,  1679,
    1682,  1686,  1694,  1707,  1715,  1725,  1726
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "FLOAT",
  "ID", "SSS", "AGG", "DATE", "SEMICOLON", "CREATE", "DROP", "VIEW",
  "TABLE", "TABLES", "INDEX", "CALC", "SELECT", "ASC", "DESC", "SHOW",
  "SYNC", "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA",
  "TRX_BEGIN", "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T",
  "FLOAT_T", "DATE_T", "TEXT_T", "HELP", "EXIT", "DOT", "INTO", "VALUES",
  "FROM", "WHERE", "OR", "AND", "SET", "ON", "AS", "LOAD", "DATA",
  "INFILE", "EXPLAIN", "LENGTH", "ROUND", "DATE_FORMAT", "EQ", "LT", "GT",
  "LE", "GE", "NE", "LIKE", "NOT_LIKE", "INNER_JOIN", "NULL_T", "NOT_NULL",
  "IS", "IS_NOT", "UNIQUE", "IN_", "NOT_IN_", "EXISTS", "NOT_EXISTS",
  "GROUP_BY", "ORDER_BY", "HAVING", "'+'", "'-'", "'*'", "'/'", "UMINUS",
  "$accept", "commands", "command_wrapper", "exit_stmt", "help_stmt",
  "sync_stmt", "begin_stmt", "commit_stmt", "rollback_stmt",
  "drop_table_stmt", "show_tables_stmt", "show_index_stmt",
  "desc_table_stmt", "create_index_stmt", "is_unique", "id_list", "alias",
  "drop_index_stmt", "create_view_stmt", "create_table_stmt",
  "attr_def_list", "attr_def", "is_nullable", "number", "type",
  "insert_stmt", "record_list", "record", "value_list", "value",
  "delete_stmt", "update_stmt", "update_list", "subquery", "select_stmt",
  "attr_list", "rel_attr", "rel_list", "order_list", "where",
  "condition_list", "condition", "rel_expr", "comp_op", "join_stmt",
  "calc_stmt", "expression_list", "expression", "load_data_stmt",
  "explain_stmt", "set_variable_stmt", "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-255)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-92)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     683,    26,   131,    19,   416,    35,    94,  -255,     3,    20,
      41,  -255,  -255,  -255,  -255,  -255,    87,    49,   683,   115,
     111,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,   120,   137,  -255,   135,   151,   158,   161,
    -255,  -255,  -255,  -255,    19,   144,   146,   167,  -255,    19,
    -255,  -255,   499,   166,    11,   510,   171,   177,   190,   510,
     162,   117,  -255,   156,  -255,   259,  -255,  -255,   197,   234,
     240,   201,   196,   203,  -255,  -255,  -255,  -255,     1,     6,
     249,  -255,  -255,   212,    34,   618,   618,   618,  -255,  -255,
      19,   255,    19,    19,    19,    19,   238,     9,   232,   247,
     250,   251,   248,   256,   164,    56,   598,   598,   598,   618,
    -255,   416,   272,   416,   510,   510,   510,   510,   260,  -255,
     416,   510,   510,   510,   510,    -6,   278,   252,   253,   284,
     618,   287,   416,   277,   294,   277,   265,   296,  -255,   286,
     112,   291,  -255,  -255,   -45,   -45,  -255,  -255,    19,  -255,
    -255,   319,   261,   261,   261,  -255,  -255,  -255,   299,   122,
     302,  -255,   538,    90,   253,  -255,   397,    95,   397,    95,
     618,  -255,   618,  -255,   416,  -255,   397,    95,   397,    95,
     618,  -255,   618,  -255,   416,  -255,   303,   516,  -255,   271,
       5,  -255,   292,   304,   416,  -255,   153,   305,  -255,   328,
    -255,  -255,  -255,   331,   333,  -255,  -255,  -255,   331,   334,
     416,   314,   272,   338,    89,   318,   133,  -255,  -255,   618,
     320,  -255,   478,   705,  -255,   332,   378,   680,   605,   341,
    -255,   335,   277,  -255,  -255,  -255,  -255,  -255,    54,   294,
     323,   326,  -255,   340,   343,   346,   347,   416,  -255,     8,
     272,   325,   272,   416,   261,   337,   303,   348,   581,   301,
     619,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,   546,   516,   516,   510,   358,   358,   546,   510,   277,
    -255,  -255,   330,   391,  -255,   331,  -255,  -255,  -255,   305,
     277,   392,  -255,  -255,  -255,  -255,   516,   361,  -255,   272,
    -255,   329,   193,   382,   618,   384,  -255,  -255,  -255,   484,
    -255,   244,   103,  -255,  -255,   244,   103,   580,  -255,  -255,
    -255,  -255,  -255,   244,   103,   244,   103,   605,  -255,   385,
    -255,  -255,  -255,   187,   349,   516,  -255,   516,  -255,  -255,
     261,   337,  -255,  -255,  -255,   172,  -255,   408,  -255,   349,
    -255,   382,  -255,  -255,  -255,  -255
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    37,     0,     0,     0,     0,     0,    27,     0,     0,
       0,    28,    29,    30,    26,    25,     0,     0,     0,     0,
     185,    24,    23,    16,    17,    18,    19,    10,    11,    12,
      13,    14,    15,     9,     8,     5,     7,     6,     4,     3,
      20,    21,    22,     0,     0,    38,     0,     0,     0,     0,
      68,    69,    70,    71,     0,     0,     0,     0,    72,     0,
     181,   169,   171,    99,     0,     0,     0,     0,     0,     0,
      88,     0,   154,    92,   170,   171,    35,    33,     0,     0,
       0,     0,     0,     0,   183,     1,   186,     2,     0,     0,
       0,    32,    31,     0,     0,     0,     0,     0,   180,    41,
       0,     0,     0,     0,     0,     0,   172,     0,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   145,
     180,     0,     0,     0,     0,     0,     0,     0,    93,   140,
       0,     0,     0,     0,     0,   172,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   175,     0,
       0,     0,   173,    42,   176,   177,   178,   179,     0,   100,
      89,     0,     0,     0,     0,   101,   102,   139,     0,     0,
       0,    94,    90,   109,   119,    97,   141,   146,   142,   147,
     143,   148,   144,   149,     0,    95,   150,   176,   151,   177,
     152,   178,   153,   179,     0,    34,     0,   121,    77,     0,
     119,   184,     0,     0,     0,    44,     0,    49,    48,     0,
      43,    73,    75,     0,     0,   174,   103,   105,     0,     0,
       0,    91,     0,     0,   110,   107,    84,    98,    96,     0,
      62,    63,     0,     0,   120,   122,     0,     0,     0,     0,
      78,     0,     0,    57,    58,    59,    60,    61,    53,     0,
       0,     0,    56,     0,     0,     0,     0,     0,   113,     0,
       0,   108,     0,     0,     0,    66,     0,     0,     0,     0,
       0,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,     0,   121,   121,     0,     0,     0,     0,     0,     0,
      79,    81,     0,     0,    45,     0,    55,    54,    52,    49,
      46,     0,    74,    76,   104,   106,   121,     0,   114,     0,
     111,    85,   115,    87,     0,     0,    64,    83,   125,     0,
     134,   132,     0,   124,   123,   128,   129,     0,   137,   135,
     138,   136,   133,   131,   126,   127,   130,     0,   182,     0,
      50,    47,    39,     0,   165,   121,   112,   121,   116,   117,
       0,    66,    65,    80,    82,    53,    36,     0,   166,   167,
      86,   118,    67,    51,    40,   168
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -255,  -255,   399,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,   -66,  -255,  -255,  -255,
     116,   176,    71,  -214,  -255,  -255,  -255,  -236,    76,    81,
    -255,  -255,  -255,  -201,     2,  -106,   -59,  -219,    78,  -155,
    -254,   211,   -57,   -14,  -218,  -255,     7,    -3,  -255,  -255,
    -255,  -255
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    46,   343,   106,    32,    33,    34,
     250,   207,   298,   253,   248,    35,   230,   231,   315,    60,
      36,    37,   200,   233,   267,    71,    72,   174,   313,   198,
     234,   235,    73,   284,   225,    39,   152,   172,    40,    41,
      42,    87
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,    75,    38,   258,   255,   113,   261,   128,   114,   135,
      61,    74,   119,    99,   159,   171,   108,   175,    64,   226,
      38,   194,    50,    51,   185,    52,   142,    53,   323,   324,
     316,   144,   239,   104,   105,   -91,   203,   291,    43,    44,
      76,   308,    79,   310,    54,   240,    81,   197,   143,   328,
     330,    94,   344,   145,   306,   101,    98,   168,   169,   170,
     148,    80,   115,   109,   110,   111,   120,   176,   178,   180,
     182,    55,    56,    57,   186,   188,   190,   192,   227,   295,
     320,   339,   148,    58,   329,   331,   332,   160,   228,   112,
     346,   359,    82,   360,    45,    99,    59,    62,    83,   154,
     155,   156,   157,   168,   169,   170,   221,   224,    77,    78,
     102,   103,   104,   105,   185,    85,   260,   222,   296,   297,
      86,   177,   179,   181,   183,    88,   358,    75,   187,   189,
     191,   193,   131,   132,   133,   134,   354,   101,   212,   213,
     236,   365,    89,    47,    48,   205,    49,   208,   217,   218,
      90,   228,   223,   223,   129,    62,    91,   311,   122,    50,
      51,    99,    52,    92,    53,   215,    93,    50,    51,    95,
      52,    96,    53,   133,   134,   269,   149,   150,   151,   131,
     132,   133,   134,   123,   243,   244,   245,   246,   247,   121,
     167,    75,    97,   307,   237,   129,   116,   149,   150,   151,
     129,   215,   117,   101,   107,   312,   263,   264,    55,    56,
      57,   348,   349,   356,   357,   118,    55,    56,    57,   281,
      58,   201,   287,   288,   321,   236,   236,   325,    58,   270,
     333,   335,   124,   125,   126,   127,   296,   297,   136,   137,
     124,   125,   126,   127,   294,   138,   139,    50,    51,   236,
      52,   140,    53,   141,   146,   287,   288,   129,   147,   129,
     153,   129,   114,   129,    99,   158,   108,   129,    64,   129,
     161,   129,   162,   129,   165,   163,   164,   173,   322,   237,
     237,   326,   166,   195,   334,   336,   130,   184,   236,   199,
     236,   312,   196,   202,   204,   197,    55,    56,    57,   206,
     -90,   210,   341,   237,    50,    51,   101,    52,    58,    53,
     265,   209,   211,   109,   110,   111,   115,   129,   214,   290,
     124,   125,   126,   127,   159,   216,   238,   167,   229,   219,
     242,   241,   249,   251,   252,   131,   132,   133,   134,   254,
     256,   257,   237,   259,   237,   262,   292,   266,   293,   300,
     129,   301,   309,    55,    56,    57,   271,   272,   273,   274,
     275,   276,   277,   278,   314,    58,   302,   279,   280,   303,
     285,   286,   304,   305,   317,   282,   283,   124,   125,   126,
     127,    50,    51,   327,    52,   337,    53,   271,   272,   273,
     274,   275,   276,   277,   278,   351,   338,   342,   279,   280,
      50,    51,   129,    52,   347,    53,   129,   345,   265,   350,
     352,   355,   223,   364,   129,   340,   129,    84,   353,    50,
      51,    63,    52,    64,    53,   299,   363,   362,   361,     0,
      55,    56,    57,   271,   272,   273,   274,   275,   276,   277,
     278,    65,    58,   268,   279,   280,     0,   285,   286,    55,
      56,    57,     0,     0,   124,   125,   126,   127,     0,     0,
       0,    58,     0,     0,     0,     0,     0,     0,    66,    67,
      68,     0,     0,     0,     0,   126,   127,     0,     0,     0,
      58,    50,    51,   108,    52,    64,    53,    50,    51,   108,
      52,    64,    53,    69,    70,   204,     0,     0,     0,     0,
       0,   204,     0,   232,    99,     0,     0,     0,     0,    65,
       0,     0,     0,    50,    51,   108,    52,    64,    53,    50,
      51,   108,    52,    64,    53,     0,   100,     0,     0,     0,
      66,    67,    68,     0,     0,    65,    66,    67,    68,     0,
       0,   232,    58,    99,     0,     0,   101,     0,    58,    50,
      51,   108,    52,    64,    53,    69,     0,     0,     0,     0,
       0,    69,    66,    67,    68,   220,     0,     0,    66,    67,
      68,   319,     0,     0,    58,   102,   103,   104,   105,     0,
      58,     0,     0,    50,    51,   101,    52,    69,    53,     0,
       0,     0,     0,    69,     0,     0,     0,   204,    66,    67,
      68,    50,    51,   108,    52,    64,    53,   318,    50,    51,
      58,    52,     0,    53,   131,   132,   133,   134,     0,     0,
       0,    50,    51,    69,    52,     0,    53,     0,     0,     0,
     289,     0,    55,    56,    57,     0,   271,   272,   273,   274,
     275,   276,   277,   278,    58,   148,     0,   279,   280,     0,
      66,    67,    68,     0,     0,     0,     0,    55,    56,    57,
       0,     0,    58,     0,     0,     0,     0,     0,     0,    58,
      55,    56,    57,     0,   271,   272,   273,   274,   275,   276,
     277,   278,    58,     0,     0,   279,   280,     0,     0,     0,
       0,     0,     0,     1,     2,   131,   132,   133,   134,     3,
       4,     0,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    11,    12,    13,     0,     0,     0,     0,     0,    14,
      15,     0,     0,     0,     0,     0,     0,     0,    16,     0,
       0,    17,     0,     0,    18,   271,   272,   273,   274,   275,
     276,   277,   278,     0,     0,     0,   279,   280,     0,     0,
       0,     0,     0,     0,     0,     0,   131,   132,   133,   134,
     271,   272,   273,   274,   275,   276,   277,   278,     0,     0,
       0,   279,   280
};

static const yytype_int16 yycheck[] =
{
       3,     4,     0,   222,   218,    64,   224,    73,    65,    75,
       3,     4,    69,     5,     5,   121,     5,   123,     7,   174,
      18,    27,     3,     4,   130,     6,    25,     8,   282,   283,
     266,    25,    27,    78,    79,    41,   142,   238,    12,    13,
       5,   260,    39,   262,    25,   200,     5,    42,    47,   285,
     286,    54,   306,    47,    46,    47,    59,   116,   117,   118,
      26,    41,    65,    52,    53,    54,    69,   124,   125,   126,
     127,    52,    53,    54,   131,   132,   133,   134,   184,    25,
     281,   295,    26,    64,   285,   286,   287,    78,   194,    78,
     309,   345,     5,   347,    68,     5,    77,   100,    49,   102,
     103,   104,   105,   162,   163,   164,   172,   173,    14,    15,
      76,    77,    78,    79,   220,     0,    27,    27,    64,    65,
       9,   124,   125,   126,   127,     5,   344,   130,   131,   132,
     133,   134,    76,    77,    78,    79,   337,    47,    26,    27,
     197,   359,     5,    12,    13,   143,    15,   145,    26,    27,
      15,   257,    63,    63,    73,   158,     5,   263,    41,     3,
       4,     5,     6,     5,     8,   158,     5,     3,     4,    25,
       6,    25,     8,    78,    79,   232,    95,    96,    97,    76,
      77,    78,    79,    27,    31,    32,    33,    34,    35,    27,
      26,   194,    25,   259,   197,   114,    25,   116,   117,   118,
     119,   194,    25,    47,    38,   264,    73,    74,    52,    53,
      54,    18,    19,    26,    27,    25,    52,    53,    54,   233,
      64,   140,   236,   237,   281,   282,   283,   284,    64,   232,
     287,   288,    76,    77,    78,    79,    64,    65,    41,     5,
      76,    77,    78,    79,   242,     5,    45,     3,     4,   306,
       6,    55,     8,    50,     5,   269,   270,   176,    46,   178,
       5,   180,   319,   182,     5,    27,     5,   186,     7,   188,
      38,   190,    25,   192,    26,    25,    25,     5,   281,   282,
     283,   284,    26,     5,   287,   288,    27,    27,   345,     5,
     347,   350,    40,     6,    17,    42,    52,    53,    54,     5,
      41,     5,   300,   306,     3,     4,    47,     6,    64,     8,
     229,    46,    26,    52,    53,    54,   319,   236,    27,   238,
      76,    77,    78,    79,     5,    26,    55,    26,    25,    27,
      26,    39,    27,     5,     3,    76,    77,    78,    79,     6,
       6,    27,   345,     5,   347,    27,     5,    27,    13,    26,
     269,    25,    27,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    27,    64,    26,    66,    67,    26,
      69,    70,    26,    26,    26,    43,    44,    76,    77,    78,
      79,     3,     4,    25,     6,    55,     8,    55,    56,    57,
      58,    59,    60,    61,    62,   314,     5,     5,    66,    67,
       3,     4,   321,     6,    75,     8,   325,    46,   327,    27,
      26,    26,    63,     5,   333,   299,   335,    18,   337,     3,
       4,     5,     6,     7,     8,   249,   355,   351,   350,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    25,    64,   232,    66,    67,    -1,    69,    70,    52,
      53,    54,    -1,    -1,    76,    77,    78,    79,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,
      54,    -1,    -1,    -1,    -1,    78,    79,    -1,    -1,    -1,
      64,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,    77,    78,    17,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    25,     5,    -1,    -1,    -1,    -1,    25,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     3,
       4,     5,     6,     7,     8,    -1,    27,    -1,    -1,    -1,
      52,    53,    54,    -1,    -1,    25,    52,    53,    54,    -1,
      -1,    25,    64,     5,    -1,    -1,    47,    -1,    64,     3,
       4,     5,     6,     7,     8,    77,    -1,    -1,    -1,    -1,
      -1,    77,    52,    53,    54,    27,    -1,    -1,    52,    53,
      54,    25,    -1,    -1,    64,    76,    77,    78,    79,    -1,
      64,    -1,    -1,     3,     4,    47,     6,    77,     8,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    17,    52,    53,
      54,     3,     4,     5,     6,     7,     8,    26,     3,     4,
      64,     6,    -1,     8,    76,    77,    78,    79,    -1,    -1,
      -1,     3,     4,    77,     6,    -1,     8,    -1,    -1,    -1,
      25,    -1,    52,    53,    54,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    64,    26,    -1,    66,    67,    -1,
      52,    53,    54,    -1,    -1,    -1,    -1,    52,    53,    54,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      52,    53,    54,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    64,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    11,    76,    77,    78,    79,    16,
      17,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    48,    -1,    -1,    51,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    66,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    -1,
      -1,    66,    67
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    11,    16,    17,    19,    20,    21,    22,    23,
      24,    28,    29,    30,    36,    37,    45,    48,    51,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    98,    99,   100,   106,   111,   112,   115,   126,
     129,   130,   131,    12,    13,    68,    95,    12,    13,    15,
       3,     4,     6,     8,    25,    52,    53,    54,    64,    77,
     110,   127,   128,     5,     7,    25,    52,    53,    54,    77,
      78,   116,   117,   123,   127,   128,     5,    14,    15,    39,
      41,     5,     5,    49,    83,     0,     9,   132,     5,     5,
      15,     5,     5,     5,   128,    25,    25,    25,   128,     5,
      27,    47,    76,    77,    78,    79,    97,    38,     5,    52,
      53,    54,    78,   117,   123,   128,    25,    25,    25,   123,
     128,    27,    41,    27,    76,    77,    78,    79,    97,   110,
      27,    76,    77,    78,    79,    97,    41,     5,     5,    45,
      55,    50,    25,    47,    25,    47,     5,    46,    26,   110,
     110,   110,   127,     5,   128,   128,   128,   128,    27,     5,
      78,    38,    25,    25,    25,    26,    26,    26,   117,   117,
     117,   116,   128,     5,   118,   116,   123,   128,   123,   128,
     123,   128,   123,   128,    27,   116,   123,   128,   123,   128,
     123,   128,   123,   128,    27,     5,    40,    42,   120,     5,
     113,   110,     6,   116,    17,   115,     5,   102,   115,    46,
       5,    26,    26,    27,    27,   127,    26,    26,    27,    27,
      27,    97,    27,    63,    97,   125,   120,   116,   116,    25,
     107,   108,    25,   114,   121,   122,   123,   128,    55,    27,
     120,    39,    26,    31,    32,    33,    34,    35,   105,    27,
     101,     5,     3,   104,     6,   104,     6,    27,   118,     5,
      27,   125,    27,    73,    74,   110,    27,   115,   122,   123,
     128,    55,    56,    57,    58,    59,    60,    61,    62,    66,
      67,   124,    43,    44,   124,    69,    70,   124,   124,    25,
     110,   114,     5,    13,   115,    25,    64,    65,   103,   102,
      26,    25,    26,    26,    26,    26,    46,    97,   118,    27,
     118,   116,   117,   119,    27,   109,   108,    26,    26,    25,
     114,   123,   128,   121,   121,   123,   128,    25,   108,   114,
     108,   114,   114,   123,   128,   123,   128,    55,     5,   104,
     101,   115,     5,    96,   121,    46,   118,    75,    18,    19,
      27,   110,    26,   110,   114,    26,    26,    27,   125,   121,
     121,   119,   109,   103,     5,   125
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    81,    82,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    84,    85,    86,    87,    88,
      89,    90,    90,    91,    92,    93,    94,    95,    95,    96,
      96,    97,    97,    98,    99,    99,   100,   100,   100,   101,
     101,   102,   102,   103,   103,   103,   104,   105,   105,   105,
     105,   105,   106,   107,   107,   108,   109,   109,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   111,   112,   113,
     113,   113,   113,   114,   115,   115,   115,   115,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   117,
     117,   117,   117,   117,   117,   117,   117,   118,   118,   118,
     118,   118,   118,   118,   118,   119,   119,   119,   119,   120,
     120,   121,   121,   121,   121,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   125,   125,   125,   125,   126,
     126,   127,   127,   127,   127,   128,   128,   128,   128,   128,
     128,   128,   129,   130,   131,   132,   132
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     2,     4,     2,     9,     0,     1,     1,
       3,     1,     2,     5,     5,     7,     7,     8,     5,     0,
       3,     6,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     1,     3,     4,     0,     3,     1,     1,
       1,     1,     1,     4,     6,     4,     6,     4,     5,     3,
       5,     3,     5,     3,     5,     7,     9,     7,     1,     3,
       1,     2,     1,     2,     3,     3,     4,     3,     4,     1,
       3,     3,     3,     4,     6,     4,     6,     2,     3,     1,
       2,     4,     5,     3,     4,     1,     2,     2,     3,     0,
       2,     0,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     5,     5,     6,     2,
       2,     1,     2,     3,     4,     3,     3,     3,     3,     3,
       2,     1,     7,     2,     4,     0,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, sql_string, sql_result, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, sql_string, sql_result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, sql_string, sql_result, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), sql_string, sql_result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, sql_string, sql_result, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* commands: command_wrapper opt_semicolon  */
#line 223 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1984 "yacc_sql.cpp"
    break;

  case 25: /* exit_stmt: EXIT  */
#line 255 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1993 "yacc_sql.cpp"
    break;

  case 26: /* help_stmt: HELP  */
#line 261 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 2001 "yacc_sql.cpp"
    break;

  case 27: /* sync_stmt: SYNC  */
#line 266 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 2009 "yacc_sql.cpp"
    break;

  case 28: /* begin_stmt: TRX_BEGIN  */
#line 272 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 2017 "yacc_sql.cpp"
    break;

  case 29: /* commit_stmt: TRX_COMMIT  */
#line 278 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 2025 "yacc_sql.cpp"
    break;

  case 30: /* rollback_stmt: TRX_ROLLBACK  */
#line 284 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 2033 "yacc_sql.cpp"
    break;

  case 31: /* drop_table_stmt: DROP TABLE ID  */
#line 290 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2043 "yacc_sql.cpp"
    break;

  case 32: /* drop_table_stmt: DROP VIEW ID  */
#line 295 "yacc_sql.y"
                   {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2053 "yacc_sql.cpp"
    break;

  case 33: /* show_tables_stmt: SHOW TABLES  */
#line 303 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 2061 "yacc_sql.cpp"
    break;

  case 34: /* show_index_stmt: SHOW INDEX FROM ID  */
#line 309 "yacc_sql.y"
                       {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_INDEX);
      (yyval.sql_node)->show_index.relation_name = (yyvsp[0].string);
    }
#line 2070 "yacc_sql.cpp"
    break;

  case 35: /* desc_table_stmt: DESC ID  */
#line 316 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2080 "yacc_sql.cpp"
    break;

  case 36: /* create_index_stmt: CREATE is_unique INDEX ID ON ID LBRACE id_list RBRACE  */
#line 325 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.is_unique = (yyvsp[-7].bools);
      create_index.index_name = (yyvsp[-5].string);
      create_index.relation_name = (yyvsp[-3].string);
      create_index.attribute_names.swap(*(yyvsp[-1].field_list));
      if (create_index.attribute_names.size() > 1) {
        create_index.is_multi_index = true;
      }
      create_index.attribute_name = create_index.attribute_names[0];
      free((yyvsp[-5].string)); 
      free((yyvsp[-3].string));
      free((yyvsp[-1].field_list));
    }
#line 2100 "yacc_sql.cpp"
    break;

  case 37: /* is_unique: %empty  */
#line 343 "yacc_sql.y"
    {
      (yyval.bools) = false;
    }
#line 2108 "yacc_sql.cpp"
    break;

  case 38: /* is_unique: UNIQUE  */
#line 346 "yacc_sql.y"
             {
      (yyval.bools) = true;
    }
#line 2116 "yacc_sql.cpp"
    break;

  case 39: /* id_list: ID  */
#line 352 "yacc_sql.y"
    {
      (yyval.field_list) = new std::vector<std::string>;
      (yyval.field_list)->push_back((yyvsp[0].string));
      free((yyvsp[0].string));
    }
#line 2126 "yacc_sql.cpp"
    break;

  case 40: /* id_list: id_list COMMA ID  */
#line 358 "yacc_sql.y"
    {
      (yyval.field_list) = (yyvsp[-2].field_list);
      (yyval.field_list)->push_back((yyvsp[0].string));
      free((yyvsp[0].string));
    }
#line 2136 "yacc_sql.cpp"
    break;

  case 41: /* alias: ID  */
#line 366 "yacc_sql.y"
     {
    (yyval.string) = common::substr((yyvsp[0].string),0,strlen((yyvsp[0].string)));
  }
#line 2144 "yacc_sql.cpp"
    break;

  case 42: /* alias: AS ID  */
#line 369 "yacc_sql.y"
          {
    (yyval.string) = common::substr((yyvsp[0].string),0,strlen((yyvsp[0].string)));
  }
#line 2152 "yacc_sql.cpp"
    break;

  case 43: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 376 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2164 "yacc_sql.cpp"
    break;

  case 44: /* create_view_stmt: CREATE VIEW ID AS select_stmt  */
#line 387 "yacc_sql.y"
    {
      (yyval.sql_node) = (yyvsp[0].sql_node);
      ParsedSqlNode* p = (yyval.sql_node);
      p->set_flag(SCF_CREATE_VIEW);

      CreateViewSqlNode &create_view = (yyval.sql_node)->create_view;
      create_view.relation_name = (yyvsp[-2].string);
      free((yyvsp[-2].string));

      create_view.select_node = &((yyval.sql_node)->selection);
    }
#line 2180 "yacc_sql.cpp"
    break;

  case 45: /* create_view_stmt: CREATE VIEW ID LBRACE attr_list RBRACE select_stmt  */
#line 399 "yacc_sql.y"
    {
      (yyval.sql_node) = (yyvsp[0].sql_node);
      ParsedSqlNode* p = (yyval.sql_node);
      p->set_flag(SCF_CREATE_VIEW);

      CreateViewSqlNode &create_view = (yyval.sql_node)->create_view;
      create_view.relation_name = (yyvsp[-4].string);
      free((yyvsp[-4].string));

      create_view.select_node = &((yyval.sql_node)->selection);

      for (auto &field : *(yyvsp[-2].expression_list)) {
        if (field->type() != ExprType::FIELD) {
          LOG_ERROR("create view attr must be field.");
          return -1;
        }
        ViewInfoSqlNode node;
        node.name = field->name();  // 设置视图中的属性名
        create_view.view_infos.emplace_back(std::move(node));
      }

      std::reverse(create_view.view_infos.begin(), create_view.view_infos.end());
      delete (yyvsp[-2].expression_list);
    }
#line 2209 "yacc_sql.cpp"
    break;

  case 46: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE  */
#line 427 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-4].string);
      free((yyvsp[-4].string));

      std::vector<AttrInfoSqlNode> *src_attrs = (yyvsp[-1].attr_infos);

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
      }
      create_table.attr_infos.emplace_back(*(yyvsp[-2].attr_info));
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-2].attr_info);
    }
#line 2229 "yacc_sql.cpp"
    break;

  case 47: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE select_stmt  */
#line 443 "yacc_sql.y"
    {
      (yyval.sql_node) = (yyvsp[0].sql_node);
      ParsedSqlNode* p = (yyval.sql_node);
      p->set_flag(SCF_CREATE_TABLE);

      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-5].string);
      free((yyvsp[-5].string));

      create_table.select_node = &((yyval.sql_node)->selection);

      std::vector<AttrInfoSqlNode> *src_attrs = (yyvsp[-2].attr_infos);

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
      }
      create_table.attr_infos.emplace_back(*(yyvsp[-3].attr_info));
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-3].attr_info);
    }
#line 2254 "yacc_sql.cpp"
    break;

  case 48: /* create_table_stmt: CREATE TABLE ID AS select_stmt  */
#line 464 "yacc_sql.y"
    {
      (yyval.sql_node) = (yyvsp[0].sql_node);
      ParsedSqlNode* p = (yyval.sql_node);
      p->set_flag(SCF_CREATE_TABLE);

      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-2].string);
      free((yyvsp[-2].string));

      create_table.select_node = &((yyval.sql_node)->selection);
    }
#line 2270 "yacc_sql.cpp"
    break;

  case 49: /* attr_def_list: %empty  */
#line 478 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 2278 "yacc_sql.cpp"
    break;

  case 50: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 482 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2292 "yacc_sql.cpp"
    break;

  case 51: /* attr_def: ID type LBRACE number RBRACE is_nullable  */
#line 495 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number) + 1;
      if ((yyvsp[0].bools)) {
        (yyval.attr_info)->nullable = true;
      }
      free((yyvsp[-5].string));
    }
#line 2307 "yacc_sql.cpp"
    break;

  case 52: /* attr_def: ID type is_nullable  */
#line 506 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      if ((yyvsp[-1].number) == DATES) {
        (yyval.attr_info)->length = 10;
      } else if((yyvsp[-1].number) == TEXTS){
        (yyval.attr_info)->length = MAX_TEXT_LENGTH;
      }else{
        (yyval.attr_info)->length = 4;
      }
      if ((yyvsp[0].bools)) {
        (yyval.attr_info)->nullable = true;
      }
      free((yyvsp[-2].string));
    }
#line 2328 "yacc_sql.cpp"
    break;

  case 53: /* is_nullable: %empty  */
#line 525 "yacc_sql.y"
     {
       (yyval.bools) = false;
     }
#line 2336 "yacc_sql.cpp"
    break;

  case 54: /* is_nullable: NOT_NULL  */
#line 529 "yacc_sql.y"
     {
       (yyval.bools) = false;
     }
#line 2344 "yacc_sql.cpp"
    break;

  case 55: /* is_nullable: NULL_T  */
#line 532 "yacc_sql.y"
              {
       (yyval.bools) = true;
     }
#line 2352 "yacc_sql.cpp"
    break;

  case 56: /* number: NUMBER  */
#line 536 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2358 "yacc_sql.cpp"
    break;

  case 57: /* type: INT_T  */
#line 539 "yacc_sql.y"
               { (yyval.number)=INTS; }
#line 2364 "yacc_sql.cpp"
    break;

  case 58: /* type: STRING_T  */
#line 540 "yacc_sql.y"
               { (yyval.number)=CHARS; }
#line 2370 "yacc_sql.cpp"
    break;

  case 59: /* type: FLOAT_T  */
#line 541 "yacc_sql.y"
               { (yyval.number)=FLOATS; }
#line 2376 "yacc_sql.cpp"
    break;

  case 60: /* type: DATE_T  */
#line 542 "yacc_sql.y"
               { (yyval.number)=DATES; }
#line 2382 "yacc_sql.cpp"
    break;

  case 61: /* type: TEXT_T  */
#line 543 "yacc_sql.y"
               { (yyval.number)=TEXTS; }
#line 2388 "yacc_sql.cpp"
    break;

  case 62: /* insert_stmt: INSERT INTO ID VALUES record_list  */
#line 547 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_INSERT);
      (yyval.sql_node)->insertion.relation_name = (yyvsp[-2].string);
      (yyval.sql_node)->insertion.values.swap(*(yyvsp[0].record_list));
    }
#line 2398 "yacc_sql.cpp"
    break;

  case 63: /* record_list: record  */
#line 555 "yacc_sql.y"
    {
      (yyval.record_list) = new std::vector<std::vector<Value>>;
      (yyval.record_list)->emplace_back(std::move(*(yyvsp[0].value_list)));
    }
#line 2407 "yacc_sql.cpp"
    break;

  case 64: /* record_list: record_list COMMA record  */
#line 560 "yacc_sql.y"
    {
      // 无需考虑插入顺序
      if ((yyvsp[-2].record_list) != nullptr) {
        (yyval.record_list) = (yyvsp[-2].record_list);
      } else {
      (yyval.record_list) = new std::vector<std::vector<Value>>;
      }
      (yyval.record_list)->emplace_back(std::move(*(yyvsp[0].value_list)));
    }
#line 2421 "yacc_sql.cpp"
    break;

  case 65: /* record: LBRACE value value_list RBRACE  */
#line 572 "yacc_sql.y"
    {
      if ((yyvsp[-1].value_list) != nullptr) {
        (yyval.value_list) = std::move((yyvsp[-1].value_list));
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      // 尾差法之后全部reverse
      (yyval.value_list)->emplace_back(std::move(*(yyvsp[-2].value)));
      std::reverse((yyval.value_list)->begin(), (yyval.value_list)->end());
    }
#line 2436 "yacc_sql.cpp"
    break;

  case 66: /* value_list: %empty  */
#line 585 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2444 "yacc_sql.cpp"
    break;

  case 67: /* value_list: COMMA value value_list  */
#line 588 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2458 "yacc_sql.cpp"
    break;

  case 68: /* value: NUMBER  */
#line 599 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2467 "yacc_sql.cpp"
    break;

  case 69: /* value: FLOAT  */
#line 603 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2476 "yacc_sql.cpp"
    break;

  case 70: /* value: SSS  */
#line 607 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
      (yyloc) = (yylsp[0]);
    }
#line 2487 "yacc_sql.cpp"
    break;

  case 71: /* value: DATE  */
#line 613 "yacc_sql.y"
          {
      if (!((yyvsp[0].dates)).ok()) {
        LOG_WARN("date is invalid");
        return -1;
      }
      (yyval.value) = new Value((date)(yyvsp[0].dates));
      (yyloc) = (yylsp[0]);
    }
#line 2500 "yacc_sql.cpp"
    break;

  case 72: /* value: NULL_T  */
#line 621 "yacc_sql.y"
            {
      (yyval.value) = new Value();
      (yyval.value)->set_null();
      (yyloc) = (yylsp[0]);
    }
#line 2510 "yacc_sql.cpp"
    break;

  case 73: /* value: LENGTH LBRACE value RBRACE  */
#line 627 "yacc_sql.y"
    {
        if ((yyvsp[-1].value)->attr_type() != AttrType::CHARS) {
          LOG_ERROR("length function only support string type.");
          return -1;
        }
        (yyval.value) = new Value((int)(yyvsp[-1].value)->get_string().size());  // translate into int
        free((yyvsp[-1].value));
        (yyloc) = (yylsp[-3]);
    }
#line 2524 "yacc_sql.cpp"
    break;

  case 74: /* value: ROUND LBRACE value COMMA number RBRACE  */
#line 637 "yacc_sql.y"
    {
        if ((yyvsp[-3].value)->attr_type() != AttrType::FLOATS) {
          LOG_ERROR("round function only support float type.");
          return -1;
        }
        (yyval.value) = new Value((float)(std::round((yyvsp[-3].value)->get_float() * pow(10, (yyvsp[-1].number))) / pow(10, (yyvsp[-1].number))));
        free((yyvsp[-3].value));
        (yyloc) = (yylsp[-5]);
    }
#line 2538 "yacc_sql.cpp"
    break;

  case 75: /* value: ROUND LBRACE value RBRACE  */
#line 647 "yacc_sql.y"
    {
        if ((yyvsp[-1].value)->attr_type() != AttrType::FLOATS) {
          LOG_ERROR("round function only support float type.");
          return -1;
        }
        (yyval.value) = new Value((std::round((yyvsp[-1].value)->get_float())));
        free((yyvsp[-1].value));
        (yyloc) = (yylsp[-3]);
    }
#line 2552 "yacc_sql.cpp"
    break;

  case 76: /* value: DATE_FORMAT LBRACE value COMMA SSS RBRACE  */
#line 657 "yacc_sql.y"
    {
        if ((yyvsp[-3].value)->attr_type() != AttrType::DATES) {
          LOG_ERROR("data_format function only support date type.");
          return -1;
        }
        (yyval.value) = new Value((date)(yyvsp[-3].value)->get_date(), common::substr((yyvsp[-1].string),1,strlen((yyvsp[-1].string))-2));
        free((yyvsp[-3].value));
        (yyloc) = (yylsp[-5]);
    }
#line 2566 "yacc_sql.cpp"
    break;

  case 77: /* delete_stmt: DELETE FROM ID where  */
#line 670 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].expression_list));
      }
      free((yyvsp[-1].string));
    }
#line 2579 "yacc_sql.cpp"
    break;

  case 78: /* update_stmt: UPDATE ID SET update_list where  */
#line 681 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_UPDATE);
      (yyval.sql_node)->update.relation_name = (yyvsp[-3].string);
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.sql_node)->update.conditions.swap(*(yyvsp[0].expression_list));
      }
       if ((yyvsp[-1].update_list) != nullptr) {
         (yyval.sql_node)->update.update_fields.swap(*(yyvsp[-1].update_list));
       }
      free((yyvsp[-3].string));
    }
#line 2595 "yacc_sql.cpp"
    break;

  case 79: /* update_list: ID EQ value  */
#line 694 "yacc_sql.y"
                {
      (yyval.update_list) = new std::vector<std::pair<std::string, Expression*>>;
      (yyval.update_list)->emplace_back(make_pair((yyvsp[-2].string), new ValueExpr(*(yyvsp[0].value))));
      free((yyvsp[-2].string));
      free((yyvsp[0].value));
    }
#line 2606 "yacc_sql.cpp"
    break;

  case 80: /* update_list: update_list COMMA ID EQ value  */
#line 701 "yacc_sql.y"
    {
      if ((yyvsp[-4].update_list) != nullptr) {
        (yyval.update_list) = (yyvsp[-4].update_list);
      } else {
        (yyval.update_list) = new std::vector<std::pair<std::string, Expression*>>;
      }
      (yyval.update_list)->emplace_back(make_pair((yyvsp[-2].string), new ValueExpr(*(yyvsp[0].value))));
      free((yyvsp[-2].string));
      free((yyvsp[0].value));
    }
#line 2621 "yacc_sql.cpp"
    break;

  case 81: /* update_list: ID EQ subquery  */
#line 711 "yacc_sql.y"
                     {
      (yyval.update_list) = new std::vector<std::pair<std::string, Expression*>>;
      (yyval.update_list)->emplace_back(make_pair((yyvsp[-2].string), new SubQueryExpr(*(yyvsp[0].sql_node))));
      free((yyvsp[-2].string));
      delete (yyvsp[0].sql_node);
    }
#line 2632 "yacc_sql.cpp"
    break;

  case 82: /* update_list: update_list COMMA ID EQ subquery  */
#line 718 "yacc_sql.y"
    {
      if ((yyvsp[-4].update_list) != nullptr) {
        (yyval.update_list) = (yyvsp[-4].update_list);
      } else {
        (yyval.update_list) = new std::vector<std::pair<std::string, Expression*>>;
      }
      (yyval.update_list)->emplace_back(make_pair((yyvsp[-2].string), new SubQueryExpr(*(yyvsp[0].sql_node))));
      free((yyvsp[-2].string));
    }
#line 2646 "yacc_sql.cpp"
    break;

  case 83: /* subquery: LBRACE select_stmt RBRACE  */
#line 729 "yacc_sql.y"
                              {
      (yyval.sql_node) = (yyvsp[-1].sql_node);
    }
#line 2654 "yacc_sql.cpp"
    break;

  case 84: /* select_stmt: SELECT attr_list FROM rel_list where  */
#line 735 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-3].expression_list) != nullptr) {
        (yyval.sql_node)->selection.attributes = std::move(*(yyvsp[-3].expression_list));
        delete (yyvsp[-3].expression_list);
      }
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[0].expression_list));
      }
      if ((yyvsp[-1].join_list) != nullptr) {
        for (auto &join : *(yyvsp[-1].join_list)) {
          (yyval.sql_node)->selection.relations.push_back(join.relation_name);
          for (auto &cond : join.conditions) {
            (yyval.sql_node)->selection.conditions.emplace_back(cond);
          }
        }
        delete (yyvsp[-1].join_list);
      }
    }
#line 2678 "yacc_sql.cpp"
    break;

  case 85: /* select_stmt: SELECT attr_list FROM rel_list where GROUP_BY attr_list  */
#line 755 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      
      std::set<RelAttrSqlNode> attr_set;
      if ((yyvsp[0].expression_list) == nullptr) {
        LOG_ERROR("Order by attr not exist.");
        return -1;
      }

      for (auto &n : *(yyvsp[0].expression_list)) {
        switch (n->type()) {
          case ExprType::FIELD: {
            attr_set.insert(dynamic_cast<FieldExpr*>(n)->get_node());
          } break;
          default:
            LOG_ERROR("group by only support Field");
            return -1;
        }
      }

      if ((yyvsp[-5].expression_list) != nullptr) {
        (yyval.sql_node)->selection.attributes = std::move(*(yyvsp[-5].expression_list));
        for (auto &n : (yyval.sql_node)->selection.attributes) {
          switch (n->type()) {
            case ExprType::FIELD: {
              // 判断select attr是否都存在于group attr
              if (attr_set.count(dynamic_cast<FieldExpr*>(n)->get_node()) <= 0) {
                LOG_ERROR("group by has field not in select.");
                return -1;
              }
            } break;
            case ExprType::FUNC: {
              // do nothing.
            } break;
            default:
              LOG_ERROR("group by select only support Field or Func");
              return -1;
          }
        }
        delete (yyvsp[-5].expression_list);
      }
      if ((yyvsp[-2].expression_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[-2].expression_list));
      }
      if ((yyvsp[-3].join_list) != nullptr) {
        for (auto &join : *(yyvsp[-3].join_list)) {
          (yyval.sql_node)->selection.relations.push_back(join.relation_name);
          for (auto &cond : join.conditions) {
            (yyval.sql_node)->selection.conditions.emplace_back(cond);
          }
        }
        delete (yyvsp[-3].join_list);
      }

      for (int i = (yyval.sql_node)->selection.attributes.size() - 1; i >= 0; --i) {
        auto ptr = (yyval.sql_node)->selection.attributes[i];
        switch (ptr->type()) {
          case ExprType::FIELD: {
            auto tmp = dynamic_cast<FieldExpr*>(((yyval.sql_node)->selection.attributes)[i]);
            (yyval.sql_node)->selection.group.emplace_back(new FieldExpr(tmp->get_node()));
          } break;
          case ExprType::FUNC: {
            // 将FuncExpr当做FieldExpr存入Order中
            auto tmp = dynamic_cast<FieldExpr*>(dynamic_cast<FuncExpr*>(((yyval.sql_node)->selection.attributes)[i])->child().get());
            (yyval.sql_node)->selection.group.emplace_back(new FieldExpr(tmp->get_node()));
          } break;
          default: {
            LOG_ERROR("Didn't support expr type %d.", ((yyval.sql_node)->selection.attributes)[i]->type());
            return -1;
          }
        }
      }

      for (int i = 0; i < (yyvsp[0].expression_list)->size(); ++i) {
        (yyval.sql_node)->selection.group.emplace_back((*(yyvsp[0].expression_list))[i]);
      }
      delete (yyvsp[0].expression_list);
    }
#line 2761 "yacc_sql.cpp"
    break;

  case 86: /* select_stmt: SELECT attr_list FROM rel_list where GROUP_BY attr_list HAVING condition_list  */
#line 834 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      
      std::set<RelAttrSqlNode> attr_set;
      if ((yyvsp[-2].expression_list) == nullptr) {
        LOG_ERROR("Order by attr not exist.");
        return -1;
      }

      for (auto &n : *(yyvsp[-2].expression_list)) {
        switch (n->type()) {
          case ExprType::FIELD: {
            attr_set.insert(dynamic_cast<FieldExpr*>(n)->get_node());
          } break;
          default:
            LOG_ERROR("group by only support Field");
            return -1;
        }
      }

      if ((yyvsp[-7].expression_list) != nullptr) {
        (yyval.sql_node)->selection.attributes = std::move(*(yyvsp[-7].expression_list));
        for (auto &n : (yyval.sql_node)->selection.attributes) {
          switch (n->type()) {
            case ExprType::FIELD: {
              // 判断select attr是否都存在于group attr
              if (attr_set.count(dynamic_cast<FieldExpr*>(n)->get_node()) <= 0) {
                LOG_ERROR("group by has field not in select.");
                return -1;
              }
            } break;
            case ExprType::FUNC: {
              // do nothing.
            } break;
            default:
              LOG_ERROR("group by select only support Field or Func");
              return -1;
          }
        }
        delete (yyvsp[-7].expression_list);
      }
      if ((yyvsp[-4].expression_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[-4].expression_list));
      }
      if ((yyvsp[-5].join_list) != nullptr) {
        for (auto &join : *(yyvsp[-5].join_list)) {
          (yyval.sql_node)->selection.relations.push_back(join.relation_name);
          for (auto &cond : join.conditions) {
            (yyval.sql_node)->selection.conditions.emplace_back(cond);
          }
        }
        delete (yyvsp[-5].join_list);
      }

      for (int i = (yyval.sql_node)->selection.attributes.size() - 1; i >= 0; --i) {
        auto ptr = (yyval.sql_node)->selection.attributes[i];
        switch (ptr->type()) {
          case ExprType::FIELD: {
            auto tmp = dynamic_cast<FieldExpr*>(((yyval.sql_node)->selection.attributes)[i]);
            (yyval.sql_node)->selection.group.emplace_back(new FieldExpr(tmp->get_node()));
          } break;
          case ExprType::FUNC: {
            // 将FuncExpr当做FieldExpr存入Order中
            auto tmp = dynamic_cast<FieldExpr*>(dynamic_cast<FuncExpr*>(((yyval.sql_node)->selection.attributes)[i])->child().get());
            (yyval.sql_node)->selection.group.emplace_back(new FieldExpr(tmp->get_node()));
          } break;
          default: {
            LOG_ERROR("Didn't support expr type %d.", ((yyval.sql_node)->selection.attributes)[i]->type());
            return -1;
          }
        }
      }

      for (int i = 0; i < (yyvsp[-2].expression_list)->size(); ++i) {
        (yyval.sql_node)->selection.group.emplace_back((*(yyvsp[-2].expression_list))[i]);
      }
      delete (yyvsp[-2].expression_list);

      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.sql_node)->selection.having.swap(*(yyvsp[0].expression_list));
        delete (yyvsp[0].expression_list);

        for (auto &expr : (yyval.sql_node)->selection.having) {
          if (!(expr->type() == ExprType::CONJUNCTION
                && dynamic_cast<ConjunctionExpr*>(expr)->conjunction_type() == ConjunctionExpr::Type::AND
                && 1 == dynamic_cast<ConjunctionExpr*>(expr)->children().size()
                && dynamic_cast<ConjunctionExpr*>(expr)->children()[0]->type() == ExprType::COMPARISON
                )) {
               // std::cout << "type: " << (int)expr->type() << std::endl;
               // std::cout << "size: " << dynamic_cast<ConjunctionExpr*>(expr)->children().size() << std::endl;
               // std::cout << "ctype: " << (int)dynamic_cast<ConjunctionExpr*>(expr)->children()[0]->type() << std::endl;
            LOG_ERROR("Only support conjunction 'and' in having.");
            return -1;
          }
          const auto comp_expr = dynamic_cast<ComparisonExpr*>(dynamic_cast<ConjunctionExpr*>(expr)->children()[0].get());
          if (comp_expr->left()->type() == ExprType::FUNC) {
            // 将聚集条件拆分成FieldExpr放入order
            // std::cout << "left" << std::endl;
            auto tmp = dynamic_cast<FieldExpr*>(dynamic_cast<FuncExpr*>(comp_expr->left().get())->child().get())->get_node();
            (yyval.sql_node)->selection.group.emplace_back(new FieldExpr(tmp));
          }
          if (comp_expr->right()->type() == ExprType::FUNC) {
            // 将聚集条件拆分成FieldExpr放入order
            // std::cout << "ritht" << std::endl;
            auto tmp = dynamic_cast<FieldExpr*>(dynamic_cast<FuncExpr*>(comp_expr->right().get())->child().get())->get_node();
            (yyval.sql_node)->selection.group.emplace_back(new FieldExpr(tmp));
          }
        }
      }
    }
#line 2876 "yacc_sql.cpp"
    break;

  case 87: /* select_stmt: SELECT attr_list FROM rel_list where ORDER_BY order_list  */
#line 945 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-5].expression_list) != nullptr) {
        (yyval.sql_node)->selection.attributes = std::move(*(yyvsp[-5].expression_list));
        delete (yyvsp[-5].expression_list);
      }
      if ((yyvsp[-2].expression_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[-2].expression_list));
      }
      if ((yyvsp[-3].join_list) != nullptr) {
        for (auto &join : *(yyvsp[-3].join_list)) {
          (yyval.sql_node)->selection.relations.push_back(join.relation_name);
          for (auto &cond : join.conditions) {
            (yyval.sql_node)->selection.conditions.emplace_back(cond);
          }
        }
        delete (yyvsp[-3].join_list);
      }
      for (int i = (yyval.sql_node)->selection.attributes.size() - 1; i >= 0; --i) {
        auto ptr = (yyval.sql_node)->selection.attributes[i];
        switch (ptr->type()) {
          case ExprType::FIELD: {
            auto tmp = dynamic_cast<FieldExpr*>(((yyval.sql_node)->selection.attributes)[i]);
            (yyval.sql_node)->selection.order.emplace_back(new FieldExpr(tmp->get_node()));
          } break;
          case ExprType::STAR: {
            (yyval.sql_node)->selection.order.emplace_back(new StarExpr("*"));
          } break;
          default: {
            LOG_ERROR("Didn't support expr type %d.", ((yyval.sql_node)->selection.attributes)[i]->type());
            return -1;
          }
        }
      }
      if ((yyvsp[0].expression_list) != nullptr) {
        for (int i = 0; i < (yyvsp[0].expression_list)->size(); ++i) {
          (yyval.sql_node)->selection.order.emplace_back((*(yyvsp[0].expression_list))[i]);
        }
        delete (yyvsp[0].expression_list);
      }
    }
#line 2922 "yacc_sql.cpp"
    break;

  case 88: /* attr_list: '*'  */
#line 988 "yacc_sql.y"
        {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back(new StarExpr("*"));
    }
#line 2931 "yacc_sql.cpp"
    break;

  case 89: /* attr_list: ID DOT '*'  */
#line 992 "yacc_sql.y"
                 {
      (yyval.expression_list) = new std::vector<Expression*>;
      auto tmp = new StarExpr("*");
      tmp->set_table_name((yyvsp[-2].string));
      (yyval.expression_list)->emplace_back(tmp);
      free((yyvsp[-2].string));
    }
#line 2943 "yacc_sql.cpp"
    break;

  case 90: /* attr_list: expression  */
#line 999 "yacc_sql.y"
                 {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2952 "yacc_sql.cpp"
    break;

  case 91: /* attr_list: expression alias  */
#line 1003 "yacc_sql.y"
                       {
      (yyvsp[-1].expression)->set_alias((yyvsp[0].string));
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[-1].expression));
      free((yyvsp[0].string));
    }
#line 2963 "yacc_sql.cpp"
    break;

  case 92: /* attr_list: rel_expr  */
#line 1009 "yacc_sql.y"
               {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2972 "yacc_sql.cpp"
    break;

  case 93: /* attr_list: rel_expr alias  */
#line 1013 "yacc_sql.y"
                     {
      (yyvsp[-1].expression)->set_alias((yyvsp[0].string));
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[-1].expression));
      free((yyvsp[0].string));
    }
#line 2983 "yacc_sql.cpp"
    break;

  case 94: /* attr_list: '*' COMMA attr_list  */
#line 1019 "yacc_sql.y"
                          {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      (yyval.expression_list)->emplace_back(new StarExpr("*"));
    }
#line 2996 "yacc_sql.cpp"
    break;

  case 95: /* attr_list: expression COMMA attr_list  */
#line 1027 "yacc_sql.y"
                                 {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 3009 "yacc_sql.cpp"
    break;

  case 96: /* attr_list: expression alias COMMA attr_list  */
#line 1035 "yacc_sql.y"
                                       {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      (yyvsp[-3].expression)->set_alias((yyvsp[-2].string));
      (yyval.expression_list)->emplace_back((yyvsp[-3].expression));
    }
#line 3023 "yacc_sql.cpp"
    break;

  case 97: /* attr_list: rel_expr COMMA attr_list  */
#line 1044 "yacc_sql.y"
                               {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 3036 "yacc_sql.cpp"
    break;

  case 98: /* attr_list: rel_expr alias COMMA attr_list  */
#line 1052 "yacc_sql.y"
                                     {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      (yyvsp[-3].expression)->set_alias((yyvsp[-2].string));
      (yyval.expression_list)->emplace_back((yyvsp[-3].expression));
    }
#line 3050 "yacc_sql.cpp"
    break;

  case 99: /* rel_attr: ID  */
#line 1064 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 3060 "yacc_sql.cpp"
    break;

  case 100: /* rel_attr: ID DOT ID  */
#line 1069 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 3072 "yacc_sql.cpp"
    break;

  case 101: /* rel_attr: AGG '*' RBRACE  */
#line 1076 "yacc_sql.y"
                     {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = "";
      (yyval.rel_attr)->attribute_name = "*";
      if ((yyvsp[-2].func_t) != FUNC_COUNT) {
        LOG_ERROR("Aggregation * only support count(*).");
        return -1;
      }
      (yyval.rel_attr)->func_type = FUNC_WCOUNT;  // 通配符版本的count
    }
#line 3087 "yacc_sql.cpp"
    break;

  case 102: /* rel_attr: AGG rel_attr RBRACE  */
#line 1086 "yacc_sql.y"
                          {
      (yyval.rel_attr) = (yyvsp[-1].rel_attr);
      (yyval.rel_attr)->func_type = (yyvsp[-2].func_t);
    }
#line 3096 "yacc_sql.cpp"
    break;

  case 103: /* rel_attr: LENGTH LBRACE rel_attr RBRACE  */
#line 1090 "yacc_sql.y"
                                    {
      (yyval.rel_attr) = (yyvsp[-1].rel_attr);
      (yyval.rel_attr)->func_type = FUNC_LENGTH;
    }
#line 3105 "yacc_sql.cpp"
    break;

  case 104: /* rel_attr: ROUND LBRACE rel_attr COMMA number RBRACE  */
#line 1094 "yacc_sql.y"
                                                {
      (yyval.rel_attr) = (yyvsp[-3].rel_attr);
      (yyval.rel_attr)->func_type = FUNC_ROUND;
      (yyval.rel_attr)->func_parm = std::to_string((yyvsp[-1].number));
    }
#line 3115 "yacc_sql.cpp"
    break;

  case 105: /* rel_attr: ROUND LBRACE rel_attr RBRACE  */
#line 1099 "yacc_sql.y"
                                   {
      (yyval.rel_attr) = (yyvsp[-1].rel_attr);
      (yyval.rel_attr)->func_type = FUNC_ROUND;
      (yyval.rel_attr)->func_parm = std::to_string(0);
    }
#line 3125 "yacc_sql.cpp"
    break;

  case 106: /* rel_attr: DATE_FORMAT LBRACE rel_attr COMMA SSS RBRACE  */
#line 1104 "yacc_sql.y"
                                                   {
      (yyval.rel_attr) = (yyvsp[-3].rel_attr);
      (yyval.rel_attr)->func_type = FUNC_DATE_FORMAT;
      (yyval.rel_attr)->func_parm = common::substr((yyvsp[-1].string),1,strlen((yyvsp[-1].string))-2);
      free((yyvsp[-1].string));
    }
#line 3136 "yacc_sql.cpp"
    break;

  case 107: /* rel_list: ID join_stmt  */
#line 1114 "yacc_sql.y"
    {
      (yyval.join_list) = (yyvsp[0].join_list);
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-1].string));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-1].string));
    }
#line 3148 "yacc_sql.cpp"
    break;

  case 108: /* rel_list: ID alias join_stmt  */
#line 1122 "yacc_sql.y"
    {
      (yyval.join_list) = (yyvsp[0].join_list);
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-2].string), (yyvsp[-1].string));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-2].string));
      free((yyvsp[-1].string));
    }
#line 3161 "yacc_sql.cpp"
    break;

  case 109: /* rel_list: ID  */
#line 1131 "yacc_sql.y"
    {
      (yyval.join_list) = new std::vector<JoinSqlNode>;
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[0].string));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[0].string));
    }
#line 3173 "yacc_sql.cpp"
    break;

  case 110: /* rel_list: ID alias  */
#line 1139 "yacc_sql.y"
    {
      (yyval.join_list) = new std::vector<JoinSqlNode>;
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-1].string), (yyvsp[0].string));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-1].string));
      free((yyvsp[0].string));
    }
#line 3186 "yacc_sql.cpp"
    break;

  case 111: /* rel_list: ID join_stmt COMMA rel_list  */
#line 1148 "yacc_sql.y"
    {
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-3].string));
      if ((yyvsp[0].join_list) != nullptr) {
        (yyval.join_list) = (yyvsp[0].join_list);
        for (auto &n : *(yyvsp[-2].join_list)) {
          (yyval.join_list)->emplace_back(std::move(n));
        }
      } else {
        (yyval.join_list) = (yyvsp[-2].join_list);
      }
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-3].string));
    }
#line 3205 "yacc_sql.cpp"
    break;

  case 112: /* rel_list: ID alias join_stmt COMMA rel_list  */
#line 1163 "yacc_sql.y"
    {
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-4].string), (yyvsp[-3].string));
      if ((yyvsp[0].join_list) != nullptr) {
        (yyval.join_list) = (yyvsp[0].join_list);
        for (auto &n : *(yyvsp[-2].join_list)) {
          (yyval.join_list)->emplace_back(std::move(n));
        }
      } else {
        (yyval.join_list) = (yyvsp[-2].join_list);
      }
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-4].string));
      free((yyvsp[-3].string));
    }
#line 3225 "yacc_sql.cpp"
    break;

  case 113: /* rel_list: ID COMMA rel_list  */
#line 1179 "yacc_sql.y"
    {
      if ((yyvsp[0].join_list) != nullptr) {
        (yyval.join_list) = (yyvsp[0].join_list);
      } else {
        (yyval.join_list) = new std::vector<JoinSqlNode>;
      }
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-2].string));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-2].string));
    }
#line 3241 "yacc_sql.cpp"
    break;

  case 114: /* rel_list: ID alias COMMA rel_list  */
#line 1191 "yacc_sql.y"
    {
      if ((yyvsp[0].join_list) != nullptr) {
        (yyval.join_list) = (yyvsp[0].join_list);
      } else {
        (yyval.join_list) = new std::vector<JoinSqlNode>;
      }
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-3].string), (yyvsp[-2].string));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-3].string));
      free((yyvsp[-2].string));
    }
#line 3258 "yacc_sql.cpp"
    break;

  case 115: /* order_list: rel_attr  */
#line 1207 "yacc_sql.y"
    {
      if (0 == strcmp((yyvsp[0].rel_attr)->attribute_name.c_str(), "*") || (yyvsp[0].rel_attr)->func_type != FUNC_NONE) {
        LOG_ERROR("Order by * / aggregation is not supported.");
        free((yyvsp[0].rel_attr));
        return -1;
      }
      auto name = (yyvsp[0].rel_attr)->attribute_name;
      auto alias = (yyvsp[0].rel_attr)->alias;
      auto tmp = new FieldExpr(*(yyvsp[0].rel_attr), name, alias);
      tmp->set_order(FieldExpr::Order::ASC);
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back(tmp);
      free((yyvsp[0].rel_attr));
    }
#line 3277 "yacc_sql.cpp"
    break;

  case 116: /* order_list: rel_attr ASC  */
#line 1222 "yacc_sql.y"
    {
      if (0 == strcmp((yyvsp[-1].rel_attr)->attribute_name.c_str(), "*") || (yyvsp[-1].rel_attr)->func_type != FUNC_NONE) {
        LOG_ERROR("Order by * / aggregation is not supported.");
        free((yyvsp[-1].rel_attr));
        return -1;
      }
      auto name = (yyvsp[-1].rel_attr)->attribute_name;
      auto alias = (yyvsp[-1].rel_attr)->alias;
      auto tmp = new FieldExpr(*(yyvsp[-1].rel_attr), name, alias);
      tmp->set_order(FieldExpr::Order::ASC);
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back(tmp);
      free((yyvsp[-1].rel_attr));
    }
#line 3296 "yacc_sql.cpp"
    break;

  case 117: /* order_list: rel_attr DESC  */
#line 1237 "yacc_sql.y"
    {
      if (0 == strcmp((yyvsp[-1].rel_attr)->attribute_name.c_str(), "*") || (yyvsp[-1].rel_attr)->func_type != FUNC_NONE) {
        LOG_ERROR("Order by * / aggregation is not supported.");
        free((yyvsp[-1].rel_attr));
        return -1;
      }
      auto name = (yyvsp[-1].rel_attr)->attribute_name;
      auto alias = (yyvsp[-1].rel_attr)->alias;
      auto tmp = new FieldExpr(*(yyvsp[-1].rel_attr), name, alias);
      tmp->set_order(FieldExpr::Order::DESC);
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back(tmp);
      free((yyvsp[-1].rel_attr));
    }
#line 3315 "yacc_sql.cpp"
    break;

  case 118: /* order_list: order_list COMMA order_list  */
#line 1252 "yacc_sql.y"
    {
      // 有序
      if ((yyvsp[-2].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[-2].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      if ((yyvsp[0].expression_list) != nullptr) {
        for(auto &n : *(yyvsp[0].expression_list)) {
          (yyval.expression_list)->emplace_back(n);
        }
      }
      delete (yyvsp[0].expression_list);
    }
#line 3334 "yacc_sql.cpp"
    break;

  case 119: /* where: %empty  */
#line 1270 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 3342 "yacc_sql.cpp"
    break;

  case 120: /* where: WHERE condition_list  */
#line 1273 "yacc_sql.y"
                           {
      (yyval.expression_list) = (yyvsp[0].expression_list);
    }
#line 3350 "yacc_sql.cpp"
    break;

  case 121: /* condition_list: %empty  */
#line 1279 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 3358 "yacc_sql.cpp"
    break;

  case 122: /* condition_list: condition  */
#line 1282 "yacc_sql.y"
                {
      (yyval.expression_list) = new std::vector<Expression*>;
      std::vector<std::unique_ptr<Expression>> children;
      children.emplace_back((yyvsp[0].expression));
      (yyval.expression_list)->emplace_back(new ConjunctionExpr(ConjunctionExpr::Type::AND, children));
    }
#line 3369 "yacc_sql.cpp"
    break;

  case 123: /* condition_list: condition AND condition_list  */
#line 1288 "yacc_sql.y"
                                   {
      if ((yyvsp[0].expression_list)) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      std::vector<std::unique_ptr<Expression>> children;
      children.emplace_back((yyvsp[-2].expression));
      (yyval.expression_list)->emplace_back(new ConjunctionExpr(ConjunctionExpr::Type::AND, children));
    }
#line 3384 "yacc_sql.cpp"
    break;

  case 124: /* condition_list: condition OR condition_list  */
#line 1298 "yacc_sql.y"
                                  {
      if ((yyvsp[0].expression_list)) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      std::vector<std::unique_ptr<Expression>> children;
      children.emplace_back((yyvsp[-2].expression));
      (yyval.expression_list)->emplace_back(new ConjunctionExpr(ConjunctionExpr::Type::OR, children));
    }
#line 3399 "yacc_sql.cpp"
    break;

  case 125: /* condition: LBRACE condition RBRACE  */
#line 1311 "yacc_sql.y"
    {
      (yyval.expression) = (yyvsp[-1].expression);
    }
#line 3407 "yacc_sql.cpp"
    break;

  case 126: /* condition: rel_expr comp_op expression  */
#line 1315 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 3418 "yacc_sql.cpp"
    break;

  case 127: /* condition: expression comp_op rel_expr  */
#line 1322 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 3429 "yacc_sql.cpp"
    break;

  case 128: /* condition: condition comp_op rel_expr  */
#line 1329 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 3440 "yacc_sql.cpp"
    break;

  case 129: /* condition: condition comp_op expression  */
#line 1336 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 3451 "yacc_sql.cpp"
    break;

  case 130: /* condition: expression comp_op expression  */
#line 1343 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 3462 "yacc_sql.cpp"
    break;

  case 131: /* condition: rel_expr comp_op rel_expr  */
#line 1350 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 3473 "yacc_sql.cpp"
    break;

  case 132: /* condition: subquery comp_op rel_expr  */
#line 1357 "yacc_sql.y"
    {
      (yyvsp[-2].sql_node)->selection.is_subquery = true;
      auto subquery_expr = new SubQueryExpr(*(yyvsp[-2].sql_node));
      subquery_expr->set_subquery_type(SubQueryType::SINGLE_VALUE);
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>(subquery_expr),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 3487 "yacc_sql.cpp"
    break;

  case 133: /* condition: rel_expr comp_op subquery  */
#line 1367 "yacc_sql.y"
    {
      (yyvsp[0].sql_node)->selection.is_subquery = true;
      auto subquery_expr = new SubQueryExpr(*(yyvsp[0].sql_node));
      subquery_expr->set_subquery_type(SubQueryType::SINGLE_VALUE);
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>(subquery_expr)
      );
    }
#line 3501 "yacc_sql.cpp"
    break;

  case 134: /* condition: subquery comp_op subquery  */
#line 1377 "yacc_sql.y"
    {
     (yyvsp[-2].sql_node)->selection.is_subquery = true;
     (yyvsp[0].sql_node)->selection.is_subquery = true;
     auto subquery_expr_1 = new SubQueryExpr(*(yyvsp[-2].sql_node));
     auto subquery_expr_2 = new SubQueryExpr(*(yyvsp[0].sql_node));
     subquery_expr_1->set_subquery_type(SubQueryType::SINGLE_VALUE);
     subquery_expr_2->set_subquery_type(SubQueryType::SINGLE_VALUE);
     (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>(subquery_expr_1),
        std::unique_ptr<Expression>(subquery_expr_2)
     );
    }
#line 3518 "yacc_sql.cpp"
    break;

  case 135: /* condition: rel_expr IN_ subquery  */
#line 1390 "yacc_sql.y"
    {
      (yyvsp[0].sql_node)->selection.is_subquery = true;
      auto subquery_expr = new SubQueryExpr(*(yyvsp[0].sql_node));
      subquery_expr->set_subquery_type(SubQueryType::LIST_VALUE);
      (yyval.expression) = new ComparisonExpr(CompOp::IN,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>(subquery_expr)
      );
    }
#line 3532 "yacc_sql.cpp"
    break;

  case 136: /* condition: rel_expr NOT_IN_ subquery  */
#line 1400 "yacc_sql.y"
    {
      (yyvsp[0].sql_node)->selection.is_subquery = true;
      auto subquery_expr = new SubQueryExpr(*(yyvsp[0].sql_node));
      subquery_expr->set_subquery_type(SubQueryType::LIST_VALUE);
      (yyval.expression) = new ComparisonExpr(CompOp::NOT_IN,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>(subquery_expr)
      );
    }
#line 3546 "yacc_sql.cpp"
    break;

  case 137: /* condition: rel_expr IN_ record  */
#line 1410 "yacc_sql.y"
    {
      auto subquery_expr = new SubQueryExpr();
      subquery_expr->set_list_tuple(*(yyvsp[0].value_list));
      subquery_expr->set_subquery_type(SubQueryType::LIST_VALUE);
      (yyval.expression) = new ComparisonExpr(CompOp::IN,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>(subquery_expr)
      );
    }
#line 3560 "yacc_sql.cpp"
    break;

  case 138: /* condition: rel_expr NOT_IN_ record  */
#line 1420 "yacc_sql.y"
    {
      auto subquery_expr = new SubQueryExpr();
      subquery_expr->set_list_tuple(*(yyvsp[0].value_list));
      subquery_expr->set_subquery_type(SubQueryType::LIST_VALUE);
      (yyval.expression) = new ComparisonExpr(CompOp::NOT_IN,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>(subquery_expr)
      );
    }
#line 3574 "yacc_sql.cpp"
    break;

  case 139: /* rel_expr: LBRACE rel_expr RBRACE  */
#line 1433 "yacc_sql.y"
    {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3583 "yacc_sql.cpp"
    break;

  case 140: /* rel_expr: rel_expr value  */
#line 1437 "yacc_sql.y"
                     {
      if ((yyvsp[0].value)->attr_type() != AttrType::INTS && (yyvsp[0].value)->attr_type() != AttrType::FLOATS) { return -1; }
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::ADD,
        std::unique_ptr<Expression>((yyvsp[-1].expression)),
        std::make_unique<ValueExpr>(*(yyvsp[0].value))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3596 "yacc_sql.cpp"
    break;

  case 141: /* rel_expr: rel_expr '+' rel_expr  */
#line 1445 "yacc_sql.y"
                            {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::ADD,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3608 "yacc_sql.cpp"
    break;

  case 142: /* rel_expr: rel_expr '-' rel_expr  */
#line 1452 "yacc_sql.y"
                            {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::SUB,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3620 "yacc_sql.cpp"
    break;

  case 143: /* rel_expr: rel_expr '*' rel_expr  */
#line 1459 "yacc_sql.y"
                            {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::MUL,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3632 "yacc_sql.cpp"
    break;

  case 144: /* rel_expr: rel_expr '/' rel_expr  */
#line 1466 "yacc_sql.y"
                            {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::DIV,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3644 "yacc_sql.cpp"
    break;

  case 145: /* rel_expr: '-' rel_expr  */
#line 1473 "yacc_sql.y"
                                {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::SUB,
        std::make_unique<ValueExpr>(Value(0)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3656 "yacc_sql.cpp"
    break;

  case 146: /* rel_expr: rel_expr '+' expression  */
#line 1480 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::ADD,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3668 "yacc_sql.cpp"
    break;

  case 147: /* rel_expr: rel_expr '-' expression  */
#line 1487 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::SUB,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3680 "yacc_sql.cpp"
    break;

  case 148: /* rel_expr: rel_expr '*' expression  */
#line 1494 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::MUL,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3692 "yacc_sql.cpp"
    break;

  case 149: /* rel_expr: rel_expr '/' expression  */
#line 1501 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::DIV,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3704 "yacc_sql.cpp"
    break;

  case 150: /* rel_expr: expression '+' rel_expr  */
#line 1508 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::ADD,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3716 "yacc_sql.cpp"
    break;

  case 151: /* rel_expr: expression '-' rel_expr  */
#line 1515 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::SUB,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3728 "yacc_sql.cpp"
    break;

  case 152: /* rel_expr: expression '*' rel_expr  */
#line 1522 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::MUL,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3740 "yacc_sql.cpp"
    break;

  case 153: /* rel_expr: expression '/' rel_expr  */
#line 1529 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::DIV,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3752 "yacc_sql.cpp"
    break;

  case 154: /* rel_expr: rel_attr  */
#line 1536 "yacc_sql.y"
               {
      if (0 == strcmp((yyvsp[0].rel_attr)->attribute_name.c_str(), "*") && (yyvsp[0].rel_attr)->func_type != FUNC_WCOUNT) {
        (yyval.expression) = new StarExpr();
      } else {
        auto name = (yyvsp[0].rel_attr)->attribute_name;
        auto alias = (yyvsp[0].rel_attr)->alias;
        auto parm = (yyvsp[0].rel_attr)->func_parm;
        auto type = (yyvsp[0].rel_attr)->func_type;
        auto field_expr = new FieldExpr(*(yyvsp[0].rel_attr));
        if (type != FUNC_NONE) {
          auto func_expr = new FuncExpr(field_expr);
          func_expr->set_parm(parm);
          func_expr->set_type(type);
          (yyval.expression) = func_expr;
        } else {
          (yyval.expression) = field_expr;
        }
      }
      free((yyvsp[0].rel_attr));
    }
#line 3777 "yacc_sql.cpp"
    break;

  case 155: /* comp_op: EQ  */
#line 1559 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3783 "yacc_sql.cpp"
    break;

  case 156: /* comp_op: LT  */
#line 1560 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3789 "yacc_sql.cpp"
    break;

  case 157: /* comp_op: GT  */
#line 1561 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3795 "yacc_sql.cpp"
    break;

  case 158: /* comp_op: LE  */
#line 1562 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3801 "yacc_sql.cpp"
    break;

  case 159: /* comp_op: GE  */
#line 1563 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3807 "yacc_sql.cpp"
    break;

  case 160: /* comp_op: NE  */
#line 1564 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3813 "yacc_sql.cpp"
    break;

  case 161: /* comp_op: LIKE  */
#line 1565 "yacc_sql.y"
           { (yyval.comp) = LIKE_TO; }
#line 3819 "yacc_sql.cpp"
    break;

  case 162: /* comp_op: NOT_LIKE  */
#line 1566 "yacc_sql.y"
               { (yyval.comp) = NOT_LIKE_TO; }
#line 3825 "yacc_sql.cpp"
    break;

  case 163: /* comp_op: IS  */
#line 1567 "yacc_sql.y"
         { (yyval.comp) = IS_NULL; }
#line 3831 "yacc_sql.cpp"
    break;

  case 164: /* comp_op: IS_NOT  */
#line 1568 "yacc_sql.y"
             { (yyval.comp) = IS_NOT_NULL; }
#line 3837 "yacc_sql.cpp"
    break;

  case 165: /* join_stmt: INNER_JOIN ID ON condition_list  */
#line 1572 "yacc_sql.y"
                                    {
      (yyval.join_list) = new std::vector<JoinSqlNode>;
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-2].string));
      join.conditions.swap(*(yyvsp[0].expression_list));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-2].string));
    }
#line 3850 "yacc_sql.cpp"
    break;

  case 166: /* join_stmt: INNER_JOIN ID ON condition_list join_stmt  */
#line 1580 "yacc_sql.y"
                                                {
      if ((yyvsp[0].join_list) != nullptr) {
        (yyval.join_list) = (yyvsp[0].join_list);
      } else {
        (yyval.join_list) = new std::vector<JoinSqlNode>;
      }
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-3].string));
      join.conditions.swap(*(yyvsp[-1].expression_list));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-3].string));
    }
#line 3867 "yacc_sql.cpp"
    break;

  case 167: /* join_stmt: INNER_JOIN ID alias ON condition_list  */
#line 1592 "yacc_sql.y"
                                            {
      (yyval.join_list) = new std::vector<JoinSqlNode>;
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-3].string), (yyvsp[-2].string));
      join.conditions.swap(*(yyvsp[0].expression_list));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-3].string));
    }
#line 3880 "yacc_sql.cpp"
    break;

  case 168: /* join_stmt: INNER_JOIN ID alias ON condition_list join_stmt  */
#line 1600 "yacc_sql.y"
                                                      {
      if ((yyvsp[0].join_list) != nullptr) {
        (yyval.join_list) = (yyvsp[0].join_list);
      } else {
        (yyval.join_list) = new std::vector<JoinSqlNode>;
      }
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-4].string), (yyvsp[-3].string));
      join.conditions.swap(*(yyvsp[-1].expression_list));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-4].string));
    }
#line 3897 "yacc_sql.cpp"
    break;

  case 169: /* calc_stmt: CALC expression_list  */
#line 1616 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      std::reverse((yyvsp[0].expression_list)->begin(), (yyvsp[0].expression_list)->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 3908 "yacc_sql.cpp"
    break;

  case 170: /* calc_stmt: SELECT expression_list  */
#line 1622 "yacc_sql.y"
                             {             //  select 1+1;
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);    // 注意这是CALC
      std::reverse((yyvsp[0].expression_list)->begin(), (yyvsp[0].expression_list)->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 3919 "yacc_sql.cpp"
    break;

  case 171: /* expression_list: expression  */
#line 1632 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 3928 "yacc_sql.cpp"
    break;

  case 172: /* expression_list: expression alias  */
#line 1637 "yacc_sql.y"
    {
      (yyvsp[-1].expression)->set_alias((yyvsp[0].string));
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[-1].expression));
      free((yyvsp[0].string));
    }
#line 3939 "yacc_sql.cpp"
    break;

  case 173: /* expression_list: expression COMMA expression_list  */
#line 1644 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression *>;
      }
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 3952 "yacc_sql.cpp"
    break;

  case 174: /* expression_list: expression alias COMMA expression_list  */
#line 1653 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression *>;
      }
      (yyvsp[-3].expression)->set_alias((yyvsp[-2].string));
      (yyval.expression_list)->emplace_back((yyvsp[-3].expression));
      free((yyvsp[-2].string));
    }
#line 3967 "yacc_sql.cpp"
    break;

  case 175: /* expression: LBRACE expression RBRACE  */
#line 1666 "yacc_sql.y"
    {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 3976 "yacc_sql.cpp"
    break;

  case 176: /* expression: expression '+' expression  */
#line 1670 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3984 "yacc_sql.cpp"
    break;

  case 177: /* expression: expression '-' expression  */
#line 1673 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3992 "yacc_sql.cpp"
    break;

  case 178: /* expression: expression '*' expression  */
#line 1676 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 4000 "yacc_sql.cpp"
    break;

  case 179: /* expression: expression '/' expression  */
#line 1679 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 4008 "yacc_sql.cpp"
    break;

  case 180: /* expression: '-' expression  */
#line 1682 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB,
        new ValueExpr(Value(0)), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 4017 "yacc_sql.cpp"
    break;

  case 181: /* expression: value  */
#line 1686 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 4027 "yacc_sql.cpp"
    break;

  case 182: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1695 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 4041 "yacc_sql.cpp"
    break;

  case 183: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1708 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 4050 "yacc_sql.cpp"
    break;

  case 184: /* set_variable_stmt: SET ID EQ value  */
#line 1716 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 4062 "yacc_sql.cpp"
    break;


#line 4066 "yacc_sql.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, sql_string, sql_result, scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, sql_string, sql_result, scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1728 "yacc_sql.y"

//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, ParsedSqlResult *sql_result) {
  yyscan_t scanner;
  yylex_init(&scanner);
  scan_string(s, scanner);
  int result = yyparse(s, sql_result, scanner);
  yylex_destroy(scanner);
  return result;
}

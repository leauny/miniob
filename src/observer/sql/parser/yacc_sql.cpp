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
  YYSYMBOL_TABLE = 12,                     /* TABLE  */
  YYSYMBOL_TABLES = 13,                    /* TABLES  */
  YYSYMBOL_INDEX = 14,                     /* INDEX  */
  YYSYMBOL_CALC = 15,                      /* CALC  */
  YYSYMBOL_SELECT = 16,                    /* SELECT  */
  YYSYMBOL_ASC = 17,                       /* ASC  */
  YYSYMBOL_DESC = 18,                      /* DESC  */
  YYSYMBOL_SHOW = 19,                      /* SHOW  */
  YYSYMBOL_SYNC = 20,                      /* SYNC  */
  YYSYMBOL_INSERT = 21,                    /* INSERT  */
  YYSYMBOL_DELETE = 22,                    /* DELETE  */
  YYSYMBOL_UPDATE = 23,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 24,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 25,                    /* RBRACE  */
  YYSYMBOL_COMMA = 26,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 27,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 28,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 29,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 30,                     /* INT_T  */
  YYSYMBOL_STRING_T = 31,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 32,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 33,                    /* DATE_T  */
  YYSYMBOL_HELP = 34,                      /* HELP  */
  YYSYMBOL_EXIT = 35,                      /* EXIT  */
  YYSYMBOL_DOT = 36,                       /* DOT  */
  YYSYMBOL_INTO = 37,                      /* INTO  */
  YYSYMBOL_VALUES = 38,                    /* VALUES  */
  YYSYMBOL_FROM = 39,                      /* FROM  */
  YYSYMBOL_WHERE = 40,                     /* WHERE  */
  YYSYMBOL_OR = 41,                        /* OR  */
  YYSYMBOL_AND = 42,                       /* AND  */
  YYSYMBOL_SET = 43,                       /* SET  */
  YYSYMBOL_ON = 44,                        /* ON  */
  YYSYMBOL_AS = 45,                        /* AS  */
  YYSYMBOL_LOAD = 46,                      /* LOAD  */
  YYSYMBOL_DATA = 47,                      /* DATA  */
  YYSYMBOL_INFILE = 48,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 49,                   /* EXPLAIN  */
  YYSYMBOL_LENGTH = 50,                    /* LENGTH  */
  YYSYMBOL_ROUND = 51,                     /* ROUND  */
  YYSYMBOL_DATE_FORMAT = 52,               /* DATE_FORMAT  */
  YYSYMBOL_EQ = 53,                        /* EQ  */
  YYSYMBOL_LT = 54,                        /* LT  */
  YYSYMBOL_GT = 55,                        /* GT  */
  YYSYMBOL_LE = 56,                        /* LE  */
  YYSYMBOL_GE = 57,                        /* GE  */
  YYSYMBOL_NE = 58,                        /* NE  */
  YYSYMBOL_LIKE = 59,                      /* LIKE  */
  YYSYMBOL_NOT_LIKE = 60,                  /* NOT_LIKE  */
  YYSYMBOL_INNER_JOIN = 61,                /* INNER_JOIN  */
  YYSYMBOL_NULL_T = 62,                    /* NULL_T  */
  YYSYMBOL_NOT_NULL = 63,                  /* NOT_NULL  */
  YYSYMBOL_IS = 64,                        /* IS  */
  YYSYMBOL_IS_NOT = 65,                    /* IS_NOT  */
  YYSYMBOL_UNIQUE = 66,                    /* UNIQUE  */
  YYSYMBOL_IN_ = 67,                       /* IN_  */
  YYSYMBOL_NOT_IN_ = 68,                   /* NOT_IN_  */
  YYSYMBOL_EXISTS = 69,                    /* EXISTS  */
  YYSYMBOL_NOT_EXISTS = 70,                /* NOT_EXISTS  */
  YYSYMBOL_GROUP_BY = 71,                  /* GROUP_BY  */
  YYSYMBOL_ORDER_BY = 72,                  /* ORDER_BY  */
  YYSYMBOL_HAVING = 73,                    /* HAVING  */
  YYSYMBOL_74_ = 74,                       /* '+'  */
  YYSYMBOL_75_ = 75,                       /* '-'  */
  YYSYMBOL_76_ = 76,                       /* '*'  */
  YYSYMBOL_77_ = 77,                       /* '/'  */
  YYSYMBOL_UMINUS = 78,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 79,                  /* $accept  */
  YYSYMBOL_commands = 80,                  /* commands  */
  YYSYMBOL_command_wrapper = 81,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 82,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 83,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 84,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 85,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 86,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 87,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 88,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 89,          /* show_tables_stmt  */
  YYSYMBOL_show_index_stmt = 90,           /* show_index_stmt  */
  YYSYMBOL_desc_table_stmt = 91,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 92,         /* create_index_stmt  */
  YYSYMBOL_is_unique = 93,                 /* is_unique  */
  YYSYMBOL_id_list = 94,                   /* id_list  */
  YYSYMBOL_alias = 95,                     /* alias  */
  YYSYMBOL_drop_index_stmt = 96,           /* drop_index_stmt  */
  YYSYMBOL_create_table_stmt = 97,         /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 98,             /* attr_def_list  */
  YYSYMBOL_attr_def = 99,                  /* attr_def  */
  YYSYMBOL_is_nullable = 100,              /* is_nullable  */
  YYSYMBOL_number = 101,                   /* number  */
  YYSYMBOL_type = 102,                     /* type  */
  YYSYMBOL_insert_stmt = 103,              /* insert_stmt  */
  YYSYMBOL_record_list = 104,              /* record_list  */
  YYSYMBOL_record = 105,                   /* record  */
  YYSYMBOL_value_list = 106,               /* value_list  */
  YYSYMBOL_value = 107,                    /* value  */
  YYSYMBOL_delete_stmt = 108,              /* delete_stmt  */
  YYSYMBOL_update_stmt = 109,              /* update_stmt  */
  YYSYMBOL_update_list = 110,              /* update_list  */
  YYSYMBOL_subquery = 111,                 /* subquery  */
  YYSYMBOL_select_stmt = 112,              /* select_stmt  */
  YYSYMBOL_attr_list = 113,                /* attr_list  */
  YYSYMBOL_rel_attr = 114,                 /* rel_attr  */
  YYSYMBOL_rel_list = 115,                 /* rel_list  */
  YYSYMBOL_order_list = 116,               /* order_list  */
  YYSYMBOL_where = 117,                    /* where  */
  YYSYMBOL_condition_list = 118,           /* condition_list  */
  YYSYMBOL_condition = 119,                /* condition  */
  YYSYMBOL_rel_expr = 120,                 /* rel_expr  */
  YYSYMBOL_comp_op = 121,                  /* comp_op  */
  YYSYMBOL_join_stmt = 122,                /* join_stmt  */
  YYSYMBOL_calc_stmt = 123,                /* calc_stmt  */
  YYSYMBOL_expression_list = 124,          /* expression_list  */
  YYSYMBOL_expression = 125,               /* expression  */
  YYSYMBOL_load_data_stmt = 126,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 127,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 128,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 129             /* opt_semicolon  */
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
#define YYFINAL  82
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   795

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  181
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  355

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   329


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
       2,     2,    76,    74,     2,    75,     2,    77,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    78
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   219,   219,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   251,   257,   262,   268,   274,   280,
     286,   293,   299,   306,   314,   333,   336,   341,   347,   356,
     359,   365,   375,   391,   412,   427,   430,   443,   454,   472,
     475,   479,   483,   486,   487,   488,   489,   492,   500,   505,
     517,   531,   534,   545,   549,   553,   559,   567,   572,   582,
     592,   602,   615,   626,   640,   646,   657,   663,   675,   680,
     700,   779,   890,   934,   938,   945,   949,   955,   959,   965,
     973,   981,   990,   998,  1010,  1015,  1022,  1032,  1036,  1040,
    1045,  1050,  1059,  1067,  1076,  1084,  1093,  1108,  1124,  1136,
    1152,  1167,  1182,  1197,  1216,  1219,  1225,  1228,  1234,  1244,
    1256,  1260,  1267,  1274,  1281,  1288,  1295,  1302,  1311,  1320,
    1331,  1340,  1349,  1359,  1372,  1377,  1385,  1392,  1399,  1406,
    1413,  1420,  1427,  1434,  1441,  1448,  1455,  1462,  1469,  1476,
    1499,  1500,  1501,  1502,  1503,  1504,  1505,  1506,  1507,  1508,
    1512,  1520,  1532,  1540,  1555,  1562,  1571,  1576,  1583,  1592,
    1605,  1610,  1613,  1616,  1619,  1622,  1626,  1634,  1647,  1655,
    1665,  1666
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
  "ID", "SSS", "AGG", "DATE", "SEMICOLON", "CREATE", "DROP", "TABLE",
  "TABLES", "INDEX", "CALC", "SELECT", "ASC", "DESC", "SHOW", "SYNC",
  "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN",
  "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T",
  "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE", "OR", "AND",
  "SET", "ON", "AS", "LOAD", "DATA", "INFILE", "EXPLAIN", "LENGTH",
  "ROUND", "DATE_FORMAT", "EQ", "LT", "GT", "LE", "GE", "NE", "LIKE",
  "NOT_LIKE", "INNER_JOIN", "NULL_T", "NOT_NULL", "IS", "IS_NOT", "UNIQUE",
  "IN_", "NOT_IN_", "EXISTS", "NOT_EXISTS", "GROUP_BY", "ORDER_BY",
  "HAVING", "'+'", "'-'", "'*'", "'/'", "UMINUS", "$accept", "commands",
  "command_wrapper", "exit_stmt", "help_stmt", "sync_stmt", "begin_stmt",
  "commit_stmt", "rollback_stmt", "drop_table_stmt", "show_tables_stmt",
  "show_index_stmt", "desc_table_stmt", "create_index_stmt", "is_unique",
  "id_list", "alias", "drop_index_stmt", "create_table_stmt",
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

#define YYPACT_NINF (-235)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-87)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     708,    -9,    11,   581,   434,    21,    15,  -235,    -6,     4,
      32,  -235,  -235,  -235,  -235,  -235,    40,     0,   708,    49,
      42,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,    53,  -235,    70,    88,   105,  -235,  -235,  -235,
    -235,   581,   102,   109,   110,  -235,   581,  -235,  -235,   122,
     103,   111,   513,   114,   128,   129,   513,   120,   115,  -235,
     399,  -235,   137,  -235,  -235,   119,   155,   157,   121,   113,
     124,  -235,  -235,  -235,  -235,    -5,   163,  -235,   130,   247,
     618,   618,   618,  -235,  -235,   581,   168,   581,   581,   581,
     581,   151,    10,   210,   142,   181,   263,   603,   603,   603,
     618,  -235,   434,   174,   434,   513,   513,   513,   513,   162,
    -235,   434,   513,   513,   513,   513,     7,   176,   152,   153,
     187,   618,   188,   195,   186,   159,   213,  -235,   194,     9,
     200,  -235,  -235,   -21,   -21,  -235,  -235,   581,  -235,  -235,
     196,   203,   206,   209,   211,   232,  -235,   215,    39,   212,
    -235,   190,   274,   153,  -235,   201,    22,   201,    22,   618,
    -235,   618,  -235,   434,  -235,   201,    22,   201,    22,   618,
    -235,   618,  -235,   434,  -235,   218,   520,  -235,   191,    -2,
    -235,   208,   217,   228,   434,  -235,   268,  -235,  -235,  -235,
     273,   275,  -235,   380,   380,   380,  -235,  -235,  -235,  -235,
     273,   276,   434,   254,   174,   279,     1,   267,    37,  -235,
    -235,   618,   269,  -235,   484,   362,  -235,   730,   324,   705,
     590,   284,  -235,   285,  -235,  -235,  -235,  -235,   107,   195,
     283,   292,  -235,   293,   300,   301,   304,   434,  -235,    16,
     174,   291,   174,   434,   380,   308,   218,   311,   657,   295,
     632,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,   550,   520,   520,   513,   319,   319,   550,   513,   186,
    -235,  -235,   256,   339,   273,  -235,  -235,  -235,   228,   186,
     351,  -235,  -235,  -235,  -235,   520,   314,  -235,   174,  -235,
     288,    99,   338,   618,   340,  -235,  -235,  -235,   498,  -235,
     405,   238,  -235,  -235,   405,   238,   612,  -235,  -235,  -235,
    -235,  -235,   405,   238,   405,   238,   590,  -235,   341,  -235,
    -235,  -235,    98,   306,   520,  -235,   520,  -235,  -235,   380,
     308,  -235,  -235,  -235,    66,  -235,   363,  -235,   306,  -235,
     338,  -235,  -235,  -235,  -235
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    35,     0,     0,     0,     0,     0,    26,     0,     0,
       0,    27,    28,    29,    25,    24,     0,     0,     0,     0,
     180,    23,    22,    15,    16,    17,    18,     9,    10,    11,
      12,    13,    14,     8,     5,     7,     6,     4,     3,    19,
      20,    21,     0,    36,     0,     0,     0,    63,    64,    65,
      66,     0,     0,     0,     0,    67,     0,   176,   164,   166,
      94,     0,     0,     0,     0,     0,     0,    83,     0,   149,
      87,   165,   166,    33,    31,     0,     0,     0,     0,     0,
       0,   178,     1,   181,     2,     0,     0,    30,     0,     0,
       0,     0,     0,   175,    39,     0,     0,     0,     0,     0,
       0,   167,     0,     0,    94,     0,     0,     0,     0,     0,
     140,   175,     0,     0,     0,     0,     0,     0,     0,    88,
     135,     0,     0,     0,     0,     0,   167,     0,     0,   114,
       0,     0,     0,     0,     0,     0,     0,   170,     0,     0,
       0,   168,    40,   171,   172,   173,   174,     0,    95,    84,
       0,     0,     0,     0,     0,     0,   134,     0,     0,     0,
      89,    85,   104,   114,    92,   136,   141,   137,   142,   138,
     143,   139,   144,     0,    90,   145,   171,   146,   172,   147,
     173,   148,   174,     0,    32,     0,   116,    72,     0,   114,
     179,     0,     0,    45,     0,    44,     0,    41,    68,    70,
       0,     0,   169,     0,     0,     0,    96,    97,    98,   100,
       0,     0,     0,    86,     0,     0,   105,   102,    79,    93,
      91,     0,    57,    58,     0,     0,   115,   117,     0,     0,
       0,     0,    73,     0,    53,    54,    55,    56,    49,     0,
       0,     0,    52,     0,     0,     0,     0,     0,   108,     0,
       0,   103,     0,     0,     0,    61,     0,     0,     0,     0,
       0,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,     0,   116,   116,     0,     0,     0,     0,     0,     0,
      74,    76,     0,     0,     0,    51,    50,    48,    45,    42,
       0,    69,    71,    99,   101,   116,     0,   109,     0,   106,
      80,   110,    82,     0,     0,    59,    78,   120,     0,   129,
     127,     0,   119,   118,   123,   124,     0,   132,   130,   133,
     131,   128,   126,   121,   122,   125,     0,   177,     0,    46,
      43,    37,     0,   160,   116,   107,   116,   111,   112,     0,
      61,    60,    75,    77,    49,    34,     0,   161,   162,    81,
     113,    62,    47,    38,   163
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -235,  -235,   355,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,   -58,  -235,  -235,   106,
     154,    46,  -206,  -235,  -235,  -235,  -234,    55,   -20,  -235,
    -235,  -235,  -194,     2,   -82,   -98,  -198,    57,  -145,  -193,
     173,   -49,    82,  -208,  -235,     3,    -3,  -235,  -235,  -235,
    -235
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    44,   332,   101,    32,    33,   240,
     193,   287,   243,   238,    34,   222,   223,   304,    57,    35,
      36,   189,   225,   257,    68,    69,   163,   302,   187,   226,
     227,    70,   274,   217,    38,   141,   161,    39,    40,    41,
      84
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,    72,    37,    42,   245,   154,    58,    71,   251,   157,
     158,   159,   119,   105,   126,   148,   248,   110,   218,   133,
      37,    94,   305,    45,   231,    46,    73,   250,    74,    75,
     160,    76,   164,   183,   199,   200,   281,    78,   186,   174,
     134,   317,   319,    77,   232,    79,   -86,    80,    89,    82,
     120,    83,   297,    93,   299,    99,   100,    43,    85,   106,
     295,    96,   215,   111,   209,   210,   165,   167,   169,   171,
     138,   139,   140,   175,   177,   179,   181,   309,   328,   312,
     313,   318,   320,   321,    86,   120,   149,   138,   139,   140,
     120,   219,    59,    87,   143,   144,   145,   146,   124,   125,
     335,   220,   333,   213,   216,   157,   158,   159,   253,   254,
      88,   190,   166,   168,   170,   172,   337,   338,    72,   176,
     178,   180,   182,   345,   346,   347,    90,    94,   285,   286,
     174,   284,   343,    91,    92,   103,   195,   228,   107,   102,
     354,   348,    94,   349,    59,   120,   112,   120,    95,   120,
     202,   120,   108,   109,   113,   120,   301,   120,   127,   120,
     128,   120,   129,   121,   130,   220,   131,    96,   135,   285,
     286,   300,   132,   142,   136,   259,   -85,   147,   155,   162,
      72,   184,    96,   229,    47,    48,   202,    49,   173,    50,
     185,   296,   188,   186,   191,    94,    97,    98,    99,   100,
     192,   255,   194,   196,    47,    48,   156,    49,   120,    50,
     280,   122,   123,   124,   125,   104,   212,    61,   197,   198,
     203,   260,   310,   228,   228,   314,   201,   204,   322,   324,
     205,    52,    53,    54,   206,    96,   207,   148,   211,   120,
     208,   301,   221,    55,   230,   233,   228,   234,   235,   236,
     237,    52,    53,    54,   239,   115,   116,   117,   118,   105,
     150,   151,   152,    55,   122,   123,   124,   125,   311,   229,
     229,   315,   137,   241,   323,   325,   242,   117,   118,    94,
     247,   244,   246,   340,   249,   228,   153,   228,   137,   282,
     120,   330,   229,   252,   120,   256,   255,   283,    47,    48,
     214,    49,   120,    50,   120,   106,   342,   271,   289,   326,
     277,   278,   122,   123,   124,   125,   290,   298,   291,    96,
     156,    97,    98,    99,   100,   292,   293,    47,    48,   294,
      49,   229,    50,   229,   303,   215,   306,   122,   123,   124,
     125,   277,   278,   316,   327,    52,    53,    54,   261,   262,
     263,   264,   265,   266,   267,   268,   331,    55,   334,   269,
     270,   336,   275,   276,   339,   341,   344,   215,   353,   115,
     116,   117,   118,    81,    52,    53,    54,   261,   262,   263,
     264,   265,   266,   267,   268,   104,    55,    61,   269,   270,
     352,   275,   276,   288,   329,   351,   350,   258,   115,   116,
     117,   118,    47,    48,    94,    49,     0,    50,    47,    48,
       0,    49,     0,    50,     0,   261,   262,   263,   264,   265,
     266,   267,   268,     0,     0,   114,   269,   270,     0,     0,
     150,   151,   152,     0,     0,     0,     0,    47,    48,    60,
      49,    61,    50,     0,    96,     0,     0,     0,     0,    52,
      53,    54,     0,     0,     0,    52,    53,    54,    62,     0,
       0,    55,     0,     0,     0,     0,     0,    55,     0,     0,
       0,     0,     0,   115,   116,   117,   118,     0,     0,   115,
     116,   117,   118,     0,    63,    64,    65,    47,    48,   104,
      49,    61,    50,     0,     0,     0,    55,     0,     0,     0,
     194,    47,    48,   104,    49,    61,    50,     0,   224,    66,
      67,     0,     0,     0,   194,     0,    47,    48,   104,    49,
      61,    50,    62,    47,    48,   104,    49,    61,    50,     0,
       0,     0,     0,     0,    63,    64,    65,    62,     0,     0,
       0,     0,     0,     0,   224,     0,    55,     0,    63,    64,
      65,     0,     0,    47,    48,   104,    49,    61,    50,    66,
      55,     0,     0,    63,    64,    65,     0,     0,     0,     0,
      63,    64,    65,    66,   308,    55,     0,     0,     0,     0,
       0,     0,    55,     0,    47,    48,     0,    49,    66,    50,
       0,     0,     0,    47,    48,    66,    49,     0,    50,     0,
      63,    64,    65,     0,     0,    51,    47,    48,   104,    49,
      61,    50,    55,     0,   279,    47,    48,     0,    49,     0,
      50,    47,    48,     0,    49,    66,    50,     0,   194,     0,
       0,    52,    53,    54,     0,     0,     0,     0,     0,     0,
      52,    53,    54,    55,     0,     0,     0,     0,     0,     0,
       0,     0,    55,    63,    64,    65,    56,   137,     0,     0,
       0,     0,    52,    53,    54,    55,     0,     0,    52,    53,
      54,     0,     0,     0,    55,     0,     0,     0,     0,     0,
      55,     0,   307,     0,     0,   261,   262,   263,   264,   265,
     266,   267,   268,     0,     0,     0,   269,   270,     0,     0,
       0,     0,     0,     0,     0,     0,   122,   123,   124,   125,
     261,   262,   263,   264,   265,   266,   267,   268,     1,     2,
       0,   269,   270,     3,     4,     0,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    11,    12,    13,     0,     0,
       0,     0,    14,    15,     0,     0,     0,     0,     0,     0,
       0,    16,     0,     0,    17,     0,     0,    18,   261,   262,
     263,   264,   265,   266,   267,   268,     0,     0,     0,   269,
     270,   272,   273,     0,     0,     0,     0,     0,     0,   122,
     123,   124,   125,   261,   262,   263,   264,   265,   266,   267,
     268,     0,     0,     0,   269,   270
};

static const yytype_int16 yycheck[] =
{
       3,     4,     0,    12,   210,   103,     3,     4,   216,   107,
     108,   109,    70,    62,    72,     5,   214,    66,   163,    24,
      18,     5,   256,    12,    26,    14,     5,    26,    13,    14,
     112,    37,   114,    26,    25,    26,   230,     5,    40,   121,
      45,   275,   276,    39,   189,     5,    39,    47,    51,     0,
      70,     9,   250,    56,   252,    76,    77,    66,     5,    62,
      44,    45,    61,    66,    25,    26,   115,   116,   117,   118,
      90,    91,    92,   122,   123,   124,   125,   271,   284,   272,
     273,   275,   276,   277,    14,   105,    76,   107,   108,   109,
     110,   173,    95,     5,    97,    98,    99,   100,    76,    77,
     298,   183,   295,   161,   162,   203,   204,   205,    71,    72,
       5,   131,   115,   116,   117,   118,    17,    18,   121,   122,
     123,   124,   125,    25,    26,   333,    24,     5,    62,    63,
     212,    24,   326,    24,    24,    24,   134,   186,    24,    36,
     348,   334,     5,   336,   147,   165,    26,   167,    26,   169,
     147,   171,    24,    24,    39,   175,   254,   177,    39,   179,
       5,   181,     5,    26,    43,   247,    53,    45,     5,    62,
      63,   253,    48,     5,    44,   224,    39,    26,    36,     5,
     183,     5,    45,   186,     3,     4,   183,     6,    26,     8,
      38,   249,     5,    40,     6,     5,    74,    75,    76,    77,
       5,   221,    16,    44,     3,     4,    25,     6,   228,     8,
     230,    74,    75,    76,    77,     5,    26,     7,     5,    25,
      24,   224,   271,   272,   273,   274,    26,    24,   277,   278,
      24,    50,    51,    52,    25,    45,    25,     5,    26,   259,
      25,   339,    24,    62,    53,    37,   295,    30,    31,    32,
      33,    50,    51,    52,    26,    74,    75,    76,    77,   308,
      50,    51,    52,    62,    74,    75,    76,    77,   271,   272,
     273,   274,    25,     5,   277,   278,     3,    76,    77,     5,
      26,     6,     6,   303,     5,   334,    76,   336,    25,     5,
     310,   289,   295,    26,   314,    26,   316,    12,     3,     4,
      26,     6,   322,     8,   324,   308,   326,   225,    25,    53,
     228,   229,    74,    75,    76,    77,    24,    26,    25,    45,
      25,    74,    75,    76,    77,    25,    25,     3,     4,    25,
       6,   334,     8,   336,    26,    61,    25,    74,    75,    76,
      77,   259,   260,    24,     5,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,     5,    62,    44,    64,
      65,    73,    67,    68,    26,    25,    25,    61,     5,    74,
      75,    76,    77,    18,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,     5,    62,     7,    64,    65,
     344,    67,    68,   239,   288,   340,   339,   224,    74,    75,
      76,    77,     3,     4,     5,     6,    -1,     8,     3,     4,
      -1,     6,    -1,     8,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    -1,    26,    64,    65,    -1,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    45,    -1,    -1,    -1,    -1,    50,
      51,    52,    -1,    -1,    -1,    50,    51,    52,    24,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    74,    75,    76,    77,    -1,    -1,    74,
      75,    76,    77,    -1,    50,    51,    52,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      16,     3,     4,     5,     6,     7,     8,    -1,    24,    75,
      76,    -1,    -1,    -1,    16,    -1,     3,     4,     5,     6,
       7,     8,    24,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    62,    -1,    50,    51,
      52,    -1,    -1,     3,     4,     5,     6,     7,     8,    75,
      62,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,
      50,    51,    52,    75,    24,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,     3,     4,    -1,     6,    75,     8,
      -1,    -1,    -1,     3,     4,    75,     6,    -1,     8,    -1,
      50,    51,    52,    -1,    -1,    24,     3,     4,     5,     6,
       7,     8,    62,    -1,    24,     3,     4,    -1,     6,    -1,
       8,     3,     4,    -1,     6,    75,     8,    -1,    16,    -1,
      -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    50,    51,    52,    75,    25,    -1,    -1,
      -1,    -1,    50,    51,    52,    62,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    25,    -1,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    -1,    -1,    64,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,
      53,    54,    55,    56,    57,    58,    59,    60,    10,    11,
      -1,    64,    65,    15,    16,    -1,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,
      -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    46,    -1,    -1,    49,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    -1,    -1,    64,
      65,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      75,    76,    77,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    64,    65
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    11,    15,    16,    18,    19,    20,    21,    22,
      23,    27,    28,    29,    34,    35,    43,    46,    49,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    96,    97,   103,   108,   109,   112,   123,   126,
     127,   128,    12,    66,    93,    12,    14,     3,     4,     6,
       8,    24,    50,    51,    52,    62,    75,   107,   124,   125,
       5,     7,    24,    50,    51,    52,    75,    76,   113,   114,
     120,   124,   125,     5,    13,    14,    37,    39,     5,     5,
      47,    81,     0,     9,   129,     5,    14,     5,     5,   125,
      24,    24,    24,   125,     5,    26,    45,    74,    75,    76,
      77,    95,    36,    24,     5,   120,   125,    24,    24,    24,
     120,   125,    26,    39,    26,    74,    75,    76,    77,    95,
     107,    26,    74,    75,    76,    77,    95,    39,     5,     5,
      43,    53,    48,    24,    45,     5,    44,    25,   107,   107,
     107,   124,     5,   125,   125,   125,   125,    26,     5,    76,
      50,    51,    52,    76,   114,    36,    25,   114,   114,   114,
     113,   125,     5,   115,   113,   120,   125,   120,   125,   120,
     125,   120,   125,    26,   113,   120,   125,   120,   125,   120,
     125,   120,   125,    26,     5,    38,    40,   117,     5,   110,
     107,     6,     5,    99,    16,   112,    44,     5,    25,    25,
      26,    26,   124,    24,    24,    24,    25,    25,    25,    25,
      26,    26,    26,    95,    26,    61,    95,   122,   117,   113,
     113,    24,   104,   105,    24,   111,   118,   119,   120,   125,
      53,    26,   117,    37,    30,    31,    32,    33,   102,    26,
      98,     5,     3,   101,     6,   101,     6,    26,   115,     5,
      26,   122,    26,    71,    72,   107,    26,   112,   119,   120,
     125,    53,    54,    55,    56,    57,    58,    59,    60,    64,
      65,   121,    41,    42,   121,    67,    68,   121,   121,    24,
     107,   111,     5,    12,    24,    62,    63,   100,    99,    25,
      24,    25,    25,    25,    25,    44,    95,   115,    26,   115,
     113,   114,   116,    26,   106,   105,    25,    25,    24,   111,
     120,   125,   118,   118,   120,   125,    24,   105,   111,   105,
     111,   111,   120,   125,   120,   125,    53,     5,   101,    98,
     112,     5,    94,   118,    44,   115,    73,    17,    18,    26,
     107,    25,   107,   111,    25,    25,    26,   122,   118,   118,
     116,   106,   100,     5,   122
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    79,    80,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    93,    94,    94,    95,
      95,    96,    97,    97,    97,    98,    98,    99,    99,   100,
     100,   100,   101,   102,   102,   102,   102,   103,   104,   104,
     105,   106,   106,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   108,   109,   110,   110,   110,   110,   111,   112,
     112,   112,   112,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   114,   114,   114,   114,   114,   114,
     114,   114,   115,   115,   115,   115,   115,   115,   115,   115,
     116,   116,   116,   116,   117,   117,   118,   118,   118,   118,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     122,   122,   122,   122,   123,   123,   124,   124,   124,   124,
     125,   125,   125,   125,   125,   125,   125,   126,   127,   128,
     129,   129
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     4,     2,     9,     0,     1,     1,     3,     1,
       2,     5,     7,     8,     5,     0,     3,     6,     3,     0,
       1,     1,     1,     1,     1,     1,     1,     5,     1,     3,
       4,     0,     3,     1,     1,     1,     1,     1,     4,     6,
       4,     6,     4,     5,     3,     5,     3,     5,     3,     5,
       7,     9,     7,     1,     3,     1,     2,     1,     2,     3,
       3,     4,     3,     4,     1,     3,     4,     4,     4,     6,
       4,     6,     2,     3,     1,     2,     4,     5,     3,     4,
       1,     2,     2,     3,     0,     2,     0,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     5,     6,     2,     2,     1,     2,     3,     4,
       3,     3,     3,     3,     3,     2,     1,     7,     2,     4,
       0,     1
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
#line 220 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1980 "yacc_sql.cpp"
    break;

  case 24: /* exit_stmt: EXIT  */
#line 251 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1989 "yacc_sql.cpp"
    break;

  case 25: /* help_stmt: HELP  */
#line 257 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1997 "yacc_sql.cpp"
    break;

  case 26: /* sync_stmt: SYNC  */
#line 262 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 2005 "yacc_sql.cpp"
    break;

  case 27: /* begin_stmt: TRX_BEGIN  */
#line 268 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 2013 "yacc_sql.cpp"
    break;

  case 28: /* commit_stmt: TRX_COMMIT  */
#line 274 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 2021 "yacc_sql.cpp"
    break;

  case 29: /* rollback_stmt: TRX_ROLLBACK  */
#line 280 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 2029 "yacc_sql.cpp"
    break;

  case 30: /* drop_table_stmt: DROP TABLE ID  */
#line 286 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2039 "yacc_sql.cpp"
    break;

  case 31: /* show_tables_stmt: SHOW TABLES  */
#line 293 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 2047 "yacc_sql.cpp"
    break;

  case 32: /* show_index_stmt: SHOW INDEX FROM ID  */
#line 299 "yacc_sql.y"
                       {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_INDEX);
      (yyval.sql_node)->show_index.relation_name = (yyvsp[0].string);
    }
#line 2056 "yacc_sql.cpp"
    break;

  case 33: /* desc_table_stmt: DESC ID  */
#line 306 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2066 "yacc_sql.cpp"
    break;

  case 34: /* create_index_stmt: CREATE is_unique INDEX ID ON ID LBRACE id_list RBRACE  */
#line 315 "yacc_sql.y"
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
#line 2086 "yacc_sql.cpp"
    break;

  case 35: /* is_unique: %empty  */
#line 333 "yacc_sql.y"
    {
      (yyval.bools) = false;
    }
#line 2094 "yacc_sql.cpp"
    break;

  case 36: /* is_unique: UNIQUE  */
#line 336 "yacc_sql.y"
             {
      (yyval.bools) = true;
    }
#line 2102 "yacc_sql.cpp"
    break;

  case 37: /* id_list: ID  */
#line 342 "yacc_sql.y"
    {
      (yyval.field_list) = new std::vector<std::string>;
      (yyval.field_list)->push_back((yyvsp[0].string));
      free((yyvsp[0].string));
    }
#line 2112 "yacc_sql.cpp"
    break;

  case 38: /* id_list: id_list COMMA ID  */
#line 348 "yacc_sql.y"
    {
      (yyval.field_list) = (yyvsp[-2].field_list);
      (yyval.field_list)->push_back((yyvsp[0].string));
      free((yyvsp[0].string));
    }
#line 2122 "yacc_sql.cpp"
    break;

  case 39: /* alias: ID  */
#line 356 "yacc_sql.y"
     {
    (yyval.string) = common::substr((yyvsp[0].string),0,strlen((yyvsp[0].string)));
  }
#line 2130 "yacc_sql.cpp"
    break;

  case 40: /* alias: AS ID  */
#line 359 "yacc_sql.y"
          {
    (yyval.string) = common::substr((yyvsp[0].string),0,strlen((yyvsp[0].string)));
  }
#line 2138 "yacc_sql.cpp"
    break;

  case 41: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 366 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2150 "yacc_sql.cpp"
    break;

  case 42: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE  */
#line 376 "yacc_sql.y"
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
#line 2170 "yacc_sql.cpp"
    break;

  case 43: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE select_stmt  */
#line 392 "yacc_sql.y"
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
#line 2195 "yacc_sql.cpp"
    break;

  case 44: /* create_table_stmt: CREATE TABLE ID AS select_stmt  */
#line 413 "yacc_sql.y"
    {
      (yyval.sql_node) = (yyvsp[0].sql_node);
      ParsedSqlNode* p = (yyval.sql_node);
      p->set_flag(SCF_CREATE_TABLE);

      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-2].string);
      free((yyvsp[-2].string));

      create_table.select_node = &((yyval.sql_node)->selection);
    }
#line 2211 "yacc_sql.cpp"
    break;

  case 45: /* attr_def_list: %empty  */
#line 427 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 2219 "yacc_sql.cpp"
    break;

  case 46: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 431 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2233 "yacc_sql.cpp"
    break;

  case 47: /* attr_def: ID type LBRACE number RBRACE is_nullable  */
#line 444 "yacc_sql.y"
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
#line 2248 "yacc_sql.cpp"
    break;

  case 48: /* attr_def: ID type is_nullable  */
#line 455 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      if ((yyvsp[-1].number) == DATES) {
        (yyval.attr_info)->length = 10;
      } else {
        (yyval.attr_info)->length = 4;
      }
      if ((yyvsp[0].bools)) {
        (yyval.attr_info)->nullable = true;
      }
      free((yyvsp[-2].string));
    }
#line 2267 "yacc_sql.cpp"
    break;

  case 49: /* is_nullable: %empty  */
#line 472 "yacc_sql.y"
     {
       (yyval.bools) = false;
     }
#line 2275 "yacc_sql.cpp"
    break;

  case 50: /* is_nullable: NOT_NULL  */
#line 476 "yacc_sql.y"
     {
       (yyval.bools) = false;
     }
#line 2283 "yacc_sql.cpp"
    break;

  case 51: /* is_nullable: NULL_T  */
#line 479 "yacc_sql.y"
              {
       (yyval.bools) = true;
     }
#line 2291 "yacc_sql.cpp"
    break;

  case 52: /* number: NUMBER  */
#line 483 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2297 "yacc_sql.cpp"
    break;

  case 53: /* type: INT_T  */
#line 486 "yacc_sql.y"
               { (yyval.number)=INTS; }
#line 2303 "yacc_sql.cpp"
    break;

  case 54: /* type: STRING_T  */
#line 487 "yacc_sql.y"
               { (yyval.number)=CHARS; }
#line 2309 "yacc_sql.cpp"
    break;

  case 55: /* type: FLOAT_T  */
#line 488 "yacc_sql.y"
               { (yyval.number)=FLOATS; }
#line 2315 "yacc_sql.cpp"
    break;

  case 56: /* type: DATE_T  */
#line 489 "yacc_sql.y"
               { (yyval.number)=DATES; }
#line 2321 "yacc_sql.cpp"
    break;

  case 57: /* insert_stmt: INSERT INTO ID VALUES record_list  */
#line 493 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_INSERT);
      (yyval.sql_node)->insertion.relation_name = (yyvsp[-2].string);
      (yyval.sql_node)->insertion.values.swap(*(yyvsp[0].record_list));
    }
#line 2331 "yacc_sql.cpp"
    break;

  case 58: /* record_list: record  */
#line 501 "yacc_sql.y"
    {
      (yyval.record_list) = new std::vector<std::vector<Value>>;
      (yyval.record_list)->emplace_back(std::move(*(yyvsp[0].value_list)));
    }
#line 2340 "yacc_sql.cpp"
    break;

  case 59: /* record_list: record_list COMMA record  */
#line 506 "yacc_sql.y"
    {
      // 无需考虑插入顺序
      if ((yyvsp[-2].record_list) != nullptr) {
        (yyval.record_list) = (yyvsp[-2].record_list);
      } else {
      (yyval.record_list) = new std::vector<std::vector<Value>>;
      }
      (yyval.record_list)->emplace_back(std::move(*(yyvsp[0].value_list)));
    }
#line 2354 "yacc_sql.cpp"
    break;

  case 60: /* record: LBRACE value value_list RBRACE  */
#line 518 "yacc_sql.y"
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
#line 2369 "yacc_sql.cpp"
    break;

  case 61: /* value_list: %empty  */
#line 531 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2377 "yacc_sql.cpp"
    break;

  case 62: /* value_list: COMMA value value_list  */
#line 534 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2391 "yacc_sql.cpp"
    break;

  case 63: /* value: NUMBER  */
#line 545 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2400 "yacc_sql.cpp"
    break;

  case 64: /* value: FLOAT  */
#line 549 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2409 "yacc_sql.cpp"
    break;

  case 65: /* value: SSS  */
#line 553 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
      (yyloc) = (yylsp[0]);
    }
#line 2420 "yacc_sql.cpp"
    break;

  case 66: /* value: DATE  */
#line 559 "yacc_sql.y"
          {
      if (!((yyvsp[0].dates)).ok()) {
        LOG_WARN("date is invalid");
        return -1;
      }
      (yyval.value) = new Value((date)(yyvsp[0].dates));
      (yyloc) = (yylsp[0]);
    }
#line 2433 "yacc_sql.cpp"
    break;

  case 67: /* value: NULL_T  */
#line 567 "yacc_sql.y"
            {
      (yyval.value) = new Value();
      (yyval.value)->set_null();
      (yyloc) = (yylsp[0]);
    }
#line 2443 "yacc_sql.cpp"
    break;

  case 68: /* value: LENGTH LBRACE value RBRACE  */
#line 573 "yacc_sql.y"
    {
        if ((yyvsp[-1].value)->attr_type() != AttrType::CHARS) {
          LOG_ERROR("length function only support string type.");
          return -1;
        }
        (yyval.value) = new Value((int)(yyvsp[-1].value)->get_string().size());  // translate into int
        free((yyvsp[-1].value));
        (yyloc) = (yylsp[-3]);
    }
#line 2457 "yacc_sql.cpp"
    break;

  case 69: /* value: ROUND LBRACE value COMMA number RBRACE  */
#line 583 "yacc_sql.y"
    {
        if ((yyvsp[-3].value)->attr_type() != AttrType::FLOATS) {
          LOG_ERROR("round function only support float type.");
          return -1;
        }
        (yyval.value) = new Value((float)(std::round((yyvsp[-3].value)->get_float() * pow(10, (yyvsp[-1].number))) / pow(10, (yyvsp[-1].number))));
        free((yyvsp[-3].value));
        (yyloc) = (yylsp[-5]);
    }
#line 2471 "yacc_sql.cpp"
    break;

  case 70: /* value: ROUND LBRACE value RBRACE  */
#line 593 "yacc_sql.y"
    {
        if ((yyvsp[-1].value)->attr_type() != AttrType::FLOATS) {
          LOG_ERROR("round function only support float type.");
          return -1;
        }
        (yyval.value) = new Value((std::round((yyvsp[-1].value)->get_float())));
        free((yyvsp[-1].value));
        (yyloc) = (yylsp[-3]);
    }
#line 2485 "yacc_sql.cpp"
    break;

  case 71: /* value: DATE_FORMAT LBRACE value COMMA SSS RBRACE  */
#line 603 "yacc_sql.y"
    {
        if ((yyvsp[-3].value)->attr_type() != AttrType::DATES) {
          LOG_ERROR("data_format function only support date type.");
          return -1;
        }
        (yyval.value) = new Value((date)(yyvsp[-3].value)->get_date(), common::substr((yyvsp[-1].string),1,strlen((yyvsp[-1].string))-2));
        free((yyvsp[-3].value));
        (yyloc) = (yylsp[-5]);
    }
#line 2499 "yacc_sql.cpp"
    break;

  case 72: /* delete_stmt: DELETE FROM ID where  */
#line 616 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].expression_list));
      }
      free((yyvsp[-1].string));
    }
#line 2512 "yacc_sql.cpp"
    break;

  case 73: /* update_stmt: UPDATE ID SET update_list where  */
#line 627 "yacc_sql.y"
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
#line 2528 "yacc_sql.cpp"
    break;

  case 74: /* update_list: ID EQ value  */
#line 640 "yacc_sql.y"
                {
      (yyval.update_list) = new std::vector<std::pair<std::string, Expression*>>;
      (yyval.update_list)->emplace_back(make_pair((yyvsp[-2].string), new ValueExpr(*(yyvsp[0].value))));
      free((yyvsp[-2].string));
      free((yyvsp[0].value));
    }
#line 2539 "yacc_sql.cpp"
    break;

  case 75: /* update_list: update_list COMMA ID EQ value  */
#line 647 "yacc_sql.y"
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
#line 2554 "yacc_sql.cpp"
    break;

  case 76: /* update_list: ID EQ subquery  */
#line 657 "yacc_sql.y"
                     {
      (yyval.update_list) = new std::vector<std::pair<std::string, Expression*>>;
      (yyval.update_list)->emplace_back(make_pair((yyvsp[-2].string), new SubQueryExpr(*(yyvsp[0].sql_node))));
      free((yyvsp[-2].string));
      delete (yyvsp[0].sql_node);
    }
#line 2565 "yacc_sql.cpp"
    break;

  case 77: /* update_list: update_list COMMA ID EQ subquery  */
#line 664 "yacc_sql.y"
    {
      if ((yyvsp[-4].update_list) != nullptr) {
        (yyval.update_list) = (yyvsp[-4].update_list);
      } else {
        (yyval.update_list) = new std::vector<std::pair<std::string, Expression*>>;
      }
      (yyval.update_list)->emplace_back(make_pair((yyvsp[-2].string), new SubQueryExpr(*(yyvsp[0].sql_node))));
      free((yyvsp[-2].string));
    }
#line 2579 "yacc_sql.cpp"
    break;

  case 78: /* subquery: LBRACE select_stmt RBRACE  */
#line 675 "yacc_sql.y"
                              {
      (yyval.sql_node) = (yyvsp[-1].sql_node);
    }
#line 2587 "yacc_sql.cpp"
    break;

  case 79: /* select_stmt: SELECT attr_list FROM rel_list where  */
#line 681 "yacc_sql.y"
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
#line 2611 "yacc_sql.cpp"
    break;

  case 80: /* select_stmt: SELECT attr_list FROM rel_list where GROUP_BY attr_list  */
#line 701 "yacc_sql.y"
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
#line 2694 "yacc_sql.cpp"
    break;

  case 81: /* select_stmt: SELECT attr_list FROM rel_list where GROUP_BY attr_list HAVING condition_list  */
#line 780 "yacc_sql.y"
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
#line 2809 "yacc_sql.cpp"
    break;

  case 82: /* select_stmt: SELECT attr_list FROM rel_list where ORDER_BY order_list  */
#line 891 "yacc_sql.y"
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
#line 2855 "yacc_sql.cpp"
    break;

  case 83: /* attr_list: '*'  */
#line 934 "yacc_sql.y"
        {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back(new StarExpr("*"));
    }
#line 2864 "yacc_sql.cpp"
    break;

  case 84: /* attr_list: ID DOT '*'  */
#line 938 "yacc_sql.y"
                 {
      (yyval.expression_list) = new std::vector<Expression*>;
      auto tmp = new StarExpr("*");
      tmp->set_table_name((yyvsp[-2].string));
      (yyval.expression_list)->emplace_back(tmp);
      free((yyvsp[-2].string));
    }
#line 2876 "yacc_sql.cpp"
    break;

  case 85: /* attr_list: expression  */
#line 945 "yacc_sql.y"
                 {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2885 "yacc_sql.cpp"
    break;

  case 86: /* attr_list: expression alias  */
#line 949 "yacc_sql.y"
                       {
      (yyvsp[-1].expression)->set_alias((yyvsp[0].string));
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[-1].expression));
      free((yyvsp[0].string));
    }
#line 2896 "yacc_sql.cpp"
    break;

  case 87: /* attr_list: rel_expr  */
#line 955 "yacc_sql.y"
               {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2905 "yacc_sql.cpp"
    break;

  case 88: /* attr_list: rel_expr alias  */
#line 959 "yacc_sql.y"
                     {
      (yyvsp[-1].expression)->set_alias((yyvsp[0].string));
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[-1].expression));
      free((yyvsp[0].string));
    }
#line 2916 "yacc_sql.cpp"
    break;

  case 89: /* attr_list: '*' COMMA attr_list  */
#line 965 "yacc_sql.y"
                          {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      (yyval.expression_list)->emplace_back(new StarExpr("*"));
    }
#line 2929 "yacc_sql.cpp"
    break;

  case 90: /* attr_list: expression COMMA attr_list  */
#line 973 "yacc_sql.y"
                                 {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 2942 "yacc_sql.cpp"
    break;

  case 91: /* attr_list: expression alias COMMA attr_list  */
#line 981 "yacc_sql.y"
                                       {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      (yyvsp[-3].expression)->set_alias((yyvsp[-2].string));
      (yyval.expression_list)->emplace_back((yyvsp[-3].expression));
    }
#line 2956 "yacc_sql.cpp"
    break;

  case 92: /* attr_list: rel_expr COMMA attr_list  */
#line 990 "yacc_sql.y"
                               {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 2969 "yacc_sql.cpp"
    break;

  case 93: /* attr_list: rel_expr alias COMMA attr_list  */
#line 998 "yacc_sql.y"
                                     {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      (yyvsp[-3].expression)->set_alias((yyvsp[-2].string));
      (yyval.expression_list)->emplace_back((yyvsp[-3].expression));
    }
#line 2983 "yacc_sql.cpp"
    break;

  case 94: /* rel_attr: ID  */
#line 1010 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2993 "yacc_sql.cpp"
    break;

  case 95: /* rel_attr: ID DOT ID  */
#line 1015 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 3005 "yacc_sql.cpp"
    break;

  case 96: /* rel_attr: AGG LBRACE '*' RBRACE  */
#line 1022 "yacc_sql.y"
                            {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = "";
      (yyval.rel_attr)->attribute_name = "*";
      if ((yyvsp[-3].func_t) != FUNC_COUNT) {
        LOG_ERROR("Aggregation * only support count(*).");
        return -1;
      }
      (yyval.rel_attr)->func_type = FUNC_WCOUNT;  // 通配符版本的count
    }
#line 3020 "yacc_sql.cpp"
    break;

  case 97: /* rel_attr: AGG LBRACE rel_attr RBRACE  */
#line 1032 "yacc_sql.y"
                                 {
      (yyval.rel_attr) = (yyvsp[-1].rel_attr);
      (yyval.rel_attr)->func_type = (yyvsp[-3].func_t);
    }
#line 3029 "yacc_sql.cpp"
    break;

  case 98: /* rel_attr: LENGTH LBRACE rel_attr RBRACE  */
#line 1036 "yacc_sql.y"
                                    {
      (yyval.rel_attr) = (yyvsp[-1].rel_attr);
      (yyval.rel_attr)->func_type = FUNC_LENGTH;
    }
#line 3038 "yacc_sql.cpp"
    break;

  case 99: /* rel_attr: ROUND LBRACE rel_attr COMMA number RBRACE  */
#line 1040 "yacc_sql.y"
                                                {
      (yyval.rel_attr) = (yyvsp[-3].rel_attr);
      (yyval.rel_attr)->func_type = FUNC_ROUND;
      (yyval.rel_attr)->func_parm = std::to_string((yyvsp[-1].number));
    }
#line 3048 "yacc_sql.cpp"
    break;

  case 100: /* rel_attr: ROUND LBRACE rel_attr RBRACE  */
#line 1045 "yacc_sql.y"
                                   {
      (yyval.rel_attr) = (yyvsp[-1].rel_attr);
      (yyval.rel_attr)->func_type = FUNC_ROUND;
      (yyval.rel_attr)->func_parm = std::to_string(0);
    }
#line 3058 "yacc_sql.cpp"
    break;

  case 101: /* rel_attr: DATE_FORMAT LBRACE rel_attr COMMA SSS RBRACE  */
#line 1050 "yacc_sql.y"
                                                   {
      (yyval.rel_attr) = (yyvsp[-3].rel_attr);
      (yyval.rel_attr)->func_type = FUNC_DATE_FORMAT;
      (yyval.rel_attr)->func_parm = common::substr((yyvsp[-1].string),1,strlen((yyvsp[-1].string))-2);
      free((yyvsp[-1].string));
    }
#line 3069 "yacc_sql.cpp"
    break;

  case 102: /* rel_list: ID join_stmt  */
#line 1060 "yacc_sql.y"
    {
      (yyval.join_list) = (yyvsp[0].join_list);
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-1].string));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-1].string));
    }
#line 3081 "yacc_sql.cpp"
    break;

  case 103: /* rel_list: ID alias join_stmt  */
#line 1068 "yacc_sql.y"
    {
      (yyval.join_list) = (yyvsp[0].join_list);
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-2].string), (yyvsp[-1].string));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-2].string));
      free((yyvsp[-1].string));
    }
#line 3094 "yacc_sql.cpp"
    break;

  case 104: /* rel_list: ID  */
#line 1077 "yacc_sql.y"
    {
      (yyval.join_list) = new std::vector<JoinSqlNode>;
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[0].string));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[0].string));
    }
#line 3106 "yacc_sql.cpp"
    break;

  case 105: /* rel_list: ID alias  */
#line 1085 "yacc_sql.y"
    {
      (yyval.join_list) = new std::vector<JoinSqlNode>;
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-1].string), (yyvsp[0].string));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-1].string));
      free((yyvsp[0].string));
    }
#line 3119 "yacc_sql.cpp"
    break;

  case 106: /* rel_list: ID join_stmt COMMA rel_list  */
#line 1094 "yacc_sql.y"
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
#line 3138 "yacc_sql.cpp"
    break;

  case 107: /* rel_list: ID alias join_stmt COMMA rel_list  */
#line 1109 "yacc_sql.y"
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
#line 3158 "yacc_sql.cpp"
    break;

  case 108: /* rel_list: ID COMMA rel_list  */
#line 1125 "yacc_sql.y"
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
#line 3174 "yacc_sql.cpp"
    break;

  case 109: /* rel_list: ID alias COMMA rel_list  */
#line 1137 "yacc_sql.y"
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
#line 3191 "yacc_sql.cpp"
    break;

  case 110: /* order_list: rel_attr  */
#line 1153 "yacc_sql.y"
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
#line 3210 "yacc_sql.cpp"
    break;

  case 111: /* order_list: rel_attr ASC  */
#line 1168 "yacc_sql.y"
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
#line 3229 "yacc_sql.cpp"
    break;

  case 112: /* order_list: rel_attr DESC  */
#line 1183 "yacc_sql.y"
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
#line 3248 "yacc_sql.cpp"
    break;

  case 113: /* order_list: order_list COMMA order_list  */
#line 1198 "yacc_sql.y"
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
#line 3267 "yacc_sql.cpp"
    break;

  case 114: /* where: %empty  */
#line 1216 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 3275 "yacc_sql.cpp"
    break;

  case 115: /* where: WHERE condition_list  */
#line 1219 "yacc_sql.y"
                           {
      (yyval.expression_list) = (yyvsp[0].expression_list);
    }
#line 3283 "yacc_sql.cpp"
    break;

  case 116: /* condition_list: %empty  */
#line 1225 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 3291 "yacc_sql.cpp"
    break;

  case 117: /* condition_list: condition  */
#line 1228 "yacc_sql.y"
                {
      (yyval.expression_list) = new std::vector<Expression*>;
      std::vector<std::unique_ptr<Expression>> children;
      children.emplace_back((yyvsp[0].expression));
      (yyval.expression_list)->emplace_back(new ConjunctionExpr(ConjunctionExpr::Type::AND, children));
    }
#line 3302 "yacc_sql.cpp"
    break;

  case 118: /* condition_list: condition AND condition_list  */
#line 1234 "yacc_sql.y"
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
#line 3317 "yacc_sql.cpp"
    break;

  case 119: /* condition_list: condition OR condition_list  */
#line 1244 "yacc_sql.y"
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
#line 3332 "yacc_sql.cpp"
    break;

  case 120: /* condition: LBRACE condition RBRACE  */
#line 1257 "yacc_sql.y"
    {
      (yyval.expression) = (yyvsp[-1].expression);
    }
#line 3340 "yacc_sql.cpp"
    break;

  case 121: /* condition: rel_expr comp_op expression  */
#line 1261 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 3351 "yacc_sql.cpp"
    break;

  case 122: /* condition: expression comp_op rel_expr  */
#line 1268 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 3362 "yacc_sql.cpp"
    break;

  case 123: /* condition: condition comp_op rel_expr  */
#line 1275 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 3373 "yacc_sql.cpp"
    break;

  case 124: /* condition: condition comp_op expression  */
#line 1282 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 3384 "yacc_sql.cpp"
    break;

  case 125: /* condition: expression comp_op expression  */
#line 1289 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 3395 "yacc_sql.cpp"
    break;

  case 126: /* condition: rel_expr comp_op rel_expr  */
#line 1296 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 3406 "yacc_sql.cpp"
    break;

  case 127: /* condition: subquery comp_op rel_expr  */
#line 1303 "yacc_sql.y"
    {
      auto subquery_expr = new SubQueryExpr(*(yyvsp[-2].sql_node));
      subquery_expr->set_subquery_type(SubQueryType::SINGLE_VALUE);
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>(subquery_expr),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 3419 "yacc_sql.cpp"
    break;

  case 128: /* condition: rel_expr comp_op subquery  */
#line 1312 "yacc_sql.y"
    {
      auto subquery_expr = new SubQueryExpr(*(yyvsp[0].sql_node));
      subquery_expr->set_subquery_type(SubQueryType::SINGLE_VALUE);
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>(subquery_expr)
      );
    }
#line 3432 "yacc_sql.cpp"
    break;

  case 129: /* condition: subquery comp_op subquery  */
#line 1321 "yacc_sql.y"
    {
     auto subquery_expr_1 = new SubQueryExpr(*(yyvsp[-2].sql_node));
     auto subquery_expr_2 = new SubQueryExpr(*(yyvsp[0].sql_node));
     subquery_expr_1->set_subquery_type(SubQueryType::SINGLE_VALUE);
     subquery_expr_2->set_subquery_type(SubQueryType::SINGLE_VALUE);
     (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>(subquery_expr_1),
        std::unique_ptr<Expression>(subquery_expr_2)
     );
    }
#line 3447 "yacc_sql.cpp"
    break;

  case 130: /* condition: rel_expr IN_ subquery  */
#line 1332 "yacc_sql.y"
    {
      auto subquery_expr = new SubQueryExpr(*(yyvsp[0].sql_node));
      subquery_expr->set_subquery_type(SubQueryType::LIST_VALUE);
      (yyval.expression) = new ComparisonExpr(CompOp::IN,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>(subquery_expr)
      );
    }
#line 3460 "yacc_sql.cpp"
    break;

  case 131: /* condition: rel_expr NOT_IN_ subquery  */
#line 1341 "yacc_sql.y"
    {
      auto subquery_expr = new SubQueryExpr(*(yyvsp[0].sql_node));
      subquery_expr->set_subquery_type(SubQueryType::LIST_VALUE);
      (yyval.expression) = new ComparisonExpr(CompOp::NOT_IN,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>(subquery_expr)
      );
    }
#line 3473 "yacc_sql.cpp"
    break;

  case 132: /* condition: rel_expr IN_ record  */
#line 1350 "yacc_sql.y"
    {
      auto subquery_expr = new SubQueryExpr();
      subquery_expr->set_list_tuple(*(yyvsp[0].value_list));
      subquery_expr->set_subquery_type(SubQueryType::LIST_VALUE);
      (yyval.expression) = new ComparisonExpr(CompOp::IN,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>(subquery_expr)
      );
    }
#line 3487 "yacc_sql.cpp"
    break;

  case 133: /* condition: rel_expr NOT_IN_ record  */
#line 1360 "yacc_sql.y"
    {
      auto subquery_expr = new SubQueryExpr();
      subquery_expr->set_list_tuple(*(yyvsp[0].value_list));
      subquery_expr->set_subquery_type(SubQueryType::LIST_VALUE);
      (yyval.expression) = new ComparisonExpr(CompOp::NOT_IN,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>(subquery_expr)
      );
    }
#line 3501 "yacc_sql.cpp"
    break;

  case 134: /* rel_expr: LBRACE rel_expr RBRACE  */
#line 1373 "yacc_sql.y"
    {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3510 "yacc_sql.cpp"
    break;

  case 135: /* rel_expr: rel_expr value  */
#line 1377 "yacc_sql.y"
                     {
      if ((yyvsp[0].value)->attr_type() != AttrType::INTS && (yyvsp[0].value)->attr_type() != AttrType::FLOATS) { return -1; }
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::ADD,
        std::unique_ptr<Expression>((yyvsp[-1].expression)),
        std::make_unique<ValueExpr>(*(yyvsp[0].value))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3523 "yacc_sql.cpp"
    break;

  case 136: /* rel_expr: rel_expr '+' rel_expr  */
#line 1385 "yacc_sql.y"
                            {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::ADD,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3535 "yacc_sql.cpp"
    break;

  case 137: /* rel_expr: rel_expr '-' rel_expr  */
#line 1392 "yacc_sql.y"
                            {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::SUB,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3547 "yacc_sql.cpp"
    break;

  case 138: /* rel_expr: rel_expr '*' rel_expr  */
#line 1399 "yacc_sql.y"
                            {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::MUL,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3559 "yacc_sql.cpp"
    break;

  case 139: /* rel_expr: rel_expr '/' rel_expr  */
#line 1406 "yacc_sql.y"
                            {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::DIV,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3571 "yacc_sql.cpp"
    break;

  case 140: /* rel_expr: '-' rel_expr  */
#line 1413 "yacc_sql.y"
                                {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::SUB,
        std::make_unique<ValueExpr>(Value(0)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3583 "yacc_sql.cpp"
    break;

  case 141: /* rel_expr: rel_expr '+' expression  */
#line 1420 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::ADD,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3595 "yacc_sql.cpp"
    break;

  case 142: /* rel_expr: rel_expr '-' expression  */
#line 1427 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::SUB,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3607 "yacc_sql.cpp"
    break;

  case 143: /* rel_expr: rel_expr '*' expression  */
#line 1434 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::MUL,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3619 "yacc_sql.cpp"
    break;

  case 144: /* rel_expr: rel_expr '/' expression  */
#line 1441 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::DIV,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3631 "yacc_sql.cpp"
    break;

  case 145: /* rel_expr: expression '+' rel_expr  */
#line 1448 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::ADD,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3643 "yacc_sql.cpp"
    break;

  case 146: /* rel_expr: expression '-' rel_expr  */
#line 1455 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::SUB,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3655 "yacc_sql.cpp"
    break;

  case 147: /* rel_expr: expression '*' rel_expr  */
#line 1462 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::MUL,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3667 "yacc_sql.cpp"
    break;

  case 148: /* rel_expr: expression '/' rel_expr  */
#line 1469 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::DIV,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3679 "yacc_sql.cpp"
    break;

  case 149: /* rel_expr: rel_attr  */
#line 1476 "yacc_sql.y"
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
#line 3704 "yacc_sql.cpp"
    break;

  case 150: /* comp_op: EQ  */
#line 1499 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3710 "yacc_sql.cpp"
    break;

  case 151: /* comp_op: LT  */
#line 1500 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3716 "yacc_sql.cpp"
    break;

  case 152: /* comp_op: GT  */
#line 1501 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3722 "yacc_sql.cpp"
    break;

  case 153: /* comp_op: LE  */
#line 1502 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3728 "yacc_sql.cpp"
    break;

  case 154: /* comp_op: GE  */
#line 1503 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3734 "yacc_sql.cpp"
    break;

  case 155: /* comp_op: NE  */
#line 1504 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3740 "yacc_sql.cpp"
    break;

  case 156: /* comp_op: LIKE  */
#line 1505 "yacc_sql.y"
           { (yyval.comp) = LIKE_TO; }
#line 3746 "yacc_sql.cpp"
    break;

  case 157: /* comp_op: NOT_LIKE  */
#line 1506 "yacc_sql.y"
               { (yyval.comp) = NOT_LIKE_TO; }
#line 3752 "yacc_sql.cpp"
    break;

  case 158: /* comp_op: IS  */
#line 1507 "yacc_sql.y"
         { (yyval.comp) = IS_NULL; }
#line 3758 "yacc_sql.cpp"
    break;

  case 159: /* comp_op: IS_NOT  */
#line 1508 "yacc_sql.y"
             { (yyval.comp) = IS_NOT_NULL; }
#line 3764 "yacc_sql.cpp"
    break;

  case 160: /* join_stmt: INNER_JOIN ID ON condition_list  */
#line 1512 "yacc_sql.y"
                                    {
      (yyval.join_list) = new std::vector<JoinSqlNode>;
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-2].string));
      join.conditions.swap(*(yyvsp[0].expression_list));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-2].string));
    }
#line 3777 "yacc_sql.cpp"
    break;

  case 161: /* join_stmt: INNER_JOIN ID ON condition_list join_stmt  */
#line 1520 "yacc_sql.y"
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
#line 3794 "yacc_sql.cpp"
    break;

  case 162: /* join_stmt: INNER_JOIN ID alias ON condition_list  */
#line 1532 "yacc_sql.y"
                                            {
      (yyval.join_list) = new std::vector<JoinSqlNode>;
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-3].string), (yyvsp[-2].string));
      join.conditions.swap(*(yyvsp[0].expression_list));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-3].string));
    }
#line 3807 "yacc_sql.cpp"
    break;

  case 163: /* join_stmt: INNER_JOIN ID alias ON condition_list join_stmt  */
#line 1540 "yacc_sql.y"
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
#line 3824 "yacc_sql.cpp"
    break;

  case 164: /* calc_stmt: CALC expression_list  */
#line 1556 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      std::reverse((yyvsp[0].expression_list)->begin(), (yyvsp[0].expression_list)->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 3835 "yacc_sql.cpp"
    break;

  case 165: /* calc_stmt: SELECT expression_list  */
#line 1562 "yacc_sql.y"
                             {             //  select 1+1;
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);    // 注意这是CALC
      std::reverse((yyvsp[0].expression_list)->begin(), (yyvsp[0].expression_list)->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 3846 "yacc_sql.cpp"
    break;

  case 166: /* expression_list: expression  */
#line 1572 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 3855 "yacc_sql.cpp"
    break;

  case 167: /* expression_list: expression alias  */
#line 1577 "yacc_sql.y"
    {
      (yyvsp[-1].expression)->set_alias((yyvsp[0].string));
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[-1].expression));
      free((yyvsp[0].string));
    }
#line 3866 "yacc_sql.cpp"
    break;

  case 168: /* expression_list: expression COMMA expression_list  */
#line 1584 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression *>;
      }
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 3879 "yacc_sql.cpp"
    break;

  case 169: /* expression_list: expression alias COMMA expression_list  */
#line 1593 "yacc_sql.y"
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
#line 3894 "yacc_sql.cpp"
    break;

  case 170: /* expression: LBRACE expression RBRACE  */
#line 1606 "yacc_sql.y"
    {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 3903 "yacc_sql.cpp"
    break;

  case 171: /* expression: expression '+' expression  */
#line 1610 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3911 "yacc_sql.cpp"
    break;

  case 172: /* expression: expression '-' expression  */
#line 1613 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3919 "yacc_sql.cpp"
    break;

  case 173: /* expression: expression '*' expression  */
#line 1616 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3927 "yacc_sql.cpp"
    break;

  case 174: /* expression: expression '/' expression  */
#line 1619 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3935 "yacc_sql.cpp"
    break;

  case 175: /* expression: '-' expression  */
#line 1622 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB,
        new ValueExpr(Value(0)), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3944 "yacc_sql.cpp"
    break;

  case 176: /* expression: value  */
#line 1626 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 3954 "yacc_sql.cpp"
    break;

  case 177: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1635 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3968 "yacc_sql.cpp"
    break;

  case 178: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1648 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3977 "yacc_sql.cpp"
    break;

  case 179: /* set_variable_stmt: SET ID EQ value  */
#line 1656 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3989 "yacc_sql.cpp"
    break;


#line 3993 "yacc_sql.cpp"

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

#line 1668 "yacc_sql.y"

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

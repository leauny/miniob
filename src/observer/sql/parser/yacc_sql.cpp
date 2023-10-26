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
  YYSYMBOL_DESC = 17,                      /* DESC  */
  YYSYMBOL_SHOW = 18,                      /* SHOW  */
  YYSYMBOL_SYNC = 19,                      /* SYNC  */
  YYSYMBOL_INSERT = 20,                    /* INSERT  */
  YYSYMBOL_DELETE = 21,                    /* DELETE  */
  YYSYMBOL_UPDATE = 22,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 23,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 24,                    /* RBRACE  */
  YYSYMBOL_COMMA = 25,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 26,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 27,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 28,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 29,                     /* INT_T  */
  YYSYMBOL_STRING_T = 30,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 31,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 32,                    /* DATE_T  */
  YYSYMBOL_HELP = 33,                      /* HELP  */
  YYSYMBOL_EXIT = 34,                      /* EXIT  */
  YYSYMBOL_DOT = 35,                       /* DOT  */
  YYSYMBOL_INTO = 36,                      /* INTO  */
  YYSYMBOL_VALUES = 37,                    /* VALUES  */
  YYSYMBOL_FROM = 38,                      /* FROM  */
  YYSYMBOL_WHERE = 39,                     /* WHERE  */
  YYSYMBOL_AND = 40,                       /* AND  */
  YYSYMBOL_OR = 41,                        /* OR  */
  YYSYMBOL_SET = 42,                       /* SET  */
  YYSYMBOL_ON = 43,                        /* ON  */
  YYSYMBOL_AS = 44,                        /* AS  */
  YYSYMBOL_LOAD = 45,                      /* LOAD  */
  YYSYMBOL_DATA = 46,                      /* DATA  */
  YYSYMBOL_INFILE = 47,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 48,                   /* EXPLAIN  */
  YYSYMBOL_LENGTH = 49,                    /* LENGTH  */
  YYSYMBOL_ROUND = 50,                     /* ROUND  */
  YYSYMBOL_DATE_FORMAT = 51,               /* DATE_FORMAT  */
  YYSYMBOL_EQ = 52,                        /* EQ  */
  YYSYMBOL_LT = 53,                        /* LT  */
  YYSYMBOL_GT = 54,                        /* GT  */
  YYSYMBOL_LE = 55,                        /* LE  */
  YYSYMBOL_GE = 56,                        /* GE  */
  YYSYMBOL_NE = 57,                        /* NE  */
  YYSYMBOL_LIKE = 58,                      /* LIKE  */
  YYSYMBOL_NOT_LIKE = 59,                  /* NOT_LIKE  */
  YYSYMBOL_INNER_JOIN = 60,                /* INNER_JOIN  */
  YYSYMBOL_NULL_T = 61,                    /* NULL_T  */
  YYSYMBOL_NOT_NULL = 62,                  /* NOT_NULL  */
  YYSYMBOL_IS = 63,                        /* IS  */
  YYSYMBOL_IS_NOT = 64,                    /* IS_NOT  */
  YYSYMBOL_UNIQUE = 65,                    /* UNIQUE  */
  YYSYMBOL_IN_ = 66,                       /* IN_  */
  YYSYMBOL_NOT_IN_ = 67,                   /* NOT_IN_  */
  YYSYMBOL_EXISTS = 68,                    /* EXISTS  */
  YYSYMBOL_NOT_EXISTS = 69,                /* NOT_EXISTS  */
  YYSYMBOL_70_ = 70,                       /* '+'  */
  YYSYMBOL_71_ = 71,                       /* '-'  */
  YYSYMBOL_72_ = 72,                       /* '*'  */
  YYSYMBOL_73_ = 73,                       /* '/'  */
  YYSYMBOL_UMINUS = 74,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 75,                  /* $accept  */
  YYSYMBOL_commands = 76,                  /* commands  */
  YYSYMBOL_command_wrapper = 77,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 78,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 79,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 80,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 81,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 82,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 83,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 84,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 85,          /* show_tables_stmt  */
  YYSYMBOL_show_index_stmt = 86,           /* show_index_stmt  */
  YYSYMBOL_desc_table_stmt = 87,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 88,         /* create_index_stmt  */
  YYSYMBOL_is_unique = 89,                 /* is_unique  */
  YYSYMBOL_id_list = 90,                   /* id_list  */
  YYSYMBOL_alias = 91,                     /* alias  */
  YYSYMBOL_drop_index_stmt = 92,           /* drop_index_stmt  */
  YYSYMBOL_create_table_stmt = 93,         /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 94,             /* attr_def_list  */
  YYSYMBOL_attr_def = 95,                  /* attr_def  */
  YYSYMBOL_is_nullable = 96,               /* is_nullable  */
  YYSYMBOL_number = 97,                    /* number  */
  YYSYMBOL_type = 98,                      /* type  */
  YYSYMBOL_insert_stmt = 99,               /* insert_stmt  */
  YYSYMBOL_record_list = 100,              /* record_list  */
  YYSYMBOL_record = 101,                   /* record  */
  YYSYMBOL_value_list = 102,               /* value_list  */
  YYSYMBOL_value = 103,                    /* value  */
  YYSYMBOL_delete_stmt = 104,              /* delete_stmt  */
  YYSYMBOL_update_stmt = 105,              /* update_stmt  */
  YYSYMBOL_update_list = 106,              /* update_list  */
  YYSYMBOL_subquery = 107,                 /* subquery  */
  YYSYMBOL_select_stmt = 108,              /* select_stmt  */
  YYSYMBOL_attr_list = 109,                /* attr_list  */
  YYSYMBOL_rel_attr = 110,                 /* rel_attr  */
  YYSYMBOL_rel_list = 111,                 /* rel_list  */
  YYSYMBOL_where = 112,                    /* where  */
  YYSYMBOL_condition_list = 113,           /* condition_list  */
  YYSYMBOL_condition = 114,                /* condition  */
  YYSYMBOL_rel_expr = 115,                 /* rel_expr  */
  YYSYMBOL_comp_op = 116,                  /* comp_op  */
  YYSYMBOL_join_stmt = 117,                /* join_stmt  */
  YYSYMBOL_calc_stmt = 118,                /* calc_stmt  */
  YYSYMBOL_expression_list = 119,          /* expression_list  */
  YYSYMBOL_expression = 120,               /* expression  */
  YYSYMBOL_load_data_stmt = 121,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 122,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 123,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 124             /* opt_semicolon  */
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
#define YYLAST   676

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  167
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  329

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   325


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
       2,     2,    72,    70,     2,    71,     2,    73,     2,     2,
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
      65,    66,    67,    68,    69,    74
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   214,   214,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   246,   252,   257,   263,   269,   275,
     281,   288,   294,   301,   309,   328,   331,   336,   342,   351,
     354,   360,   370,   389,   392,   405,   416,   434,   437,   441,
     445,   448,   449,   450,   451,   454,   462,   467,   479,   493,
     496,   507,   511,   515,   521,   529,   534,   544,   554,   564,
     577,   588,   602,   608,   619,   625,   637,   642,   665,   669,
     673,   679,   683,   689,   697,   705,   714,   722,   734,   739,
     746,   756,   760,   764,   769,   774,   783,   791,   800,   808,
     817,   832,   848,   860,   876,   879,   885,   888,   894,   904,
     916,   920,   927,   934,   941,   948,   955,   962,   971,   980,
     989,   999,  1012,  1017,  1025,  1032,  1039,  1046,  1053,  1060,
    1067,  1074,  1081,  1088,  1095,  1102,  1109,  1116,  1163,  1164,
    1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1176,  1184,
    1199,  1206,  1215,  1220,  1227,  1236,  1249,  1254,  1257,  1260,
    1263,  1266,  1270,  1278,  1291,  1299,  1309,  1310
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
  "TABLES", "INDEX", "CALC", "SELECT", "DESC", "SHOW", "SYNC", "INSERT",
  "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN",
  "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T",
  "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE", "AND", "OR",
  "SET", "ON", "AS", "LOAD", "DATA", "INFILE", "EXPLAIN", "LENGTH",
  "ROUND", "DATE_FORMAT", "EQ", "LT", "GT", "LE", "GE", "NE", "LIKE",
  "NOT_LIKE", "INNER_JOIN", "NULL_T", "NOT_NULL", "IS", "IS_NOT", "UNIQUE",
  "IN_", "NOT_IN_", "EXISTS", "NOT_EXISTS", "'+'", "'-'", "'*'", "'/'",
  "UMINUS", "$accept", "commands", "command_wrapper", "exit_stmt",
  "help_stmt", "sync_stmt", "begin_stmt", "commit_stmt", "rollback_stmt",
  "drop_table_stmt", "show_tables_stmt", "show_index_stmt",
  "desc_table_stmt", "create_index_stmt", "is_unique", "id_list", "alias",
  "drop_index_stmt", "create_table_stmt", "attr_def_list", "attr_def",
  "is_nullable", "number", "type", "insert_stmt", "record_list", "record",
  "value_list", "value", "delete_stmt", "update_stmt", "update_list",
  "subquery", "select_stmt", "attr_list", "rel_attr", "rel_list", "where",
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

#define YYPACT_NINF (-256)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-81)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     615,    19,    15,   458,   367,    34,    20,  -256,    22,    49,
      51,  -256,  -256,  -256,  -256,  -256,    72,    47,   615,    35,
      91,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,
    -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,
    -256,  -256,   104,  -256,   114,   127,   129,  -256,  -256,  -256,
    -256,   458,   113,   115,   117,  -256,   458,  -256,  -256,   215,
     108,   125,   402,   151,   154,   162,   402,   133,   112,  -256,
     121,  -256,   472,  -256,  -256,   149,   147,   185,   167,   144,
     169,  -256,  -256,  -256,  -256,   175,   209,  -256,   179,   140,
     429,   429,   429,  -256,  -256,   458,   220,   458,   458,   458,
     458,   203,   222,   152,    18,   202,   520,   520,   520,   429,
    -256,   367,   237,   367,   402,   402,   402,   402,   229,  -256,
     367,   402,   402,   402,   402,    60,   240,   218,   217,   253,
     429,   255,   260,   233,   273,  -256,   256,    36,   257,  -256,
    -256,    30,    30,  -256,  -256,   458,  -256,   261,   266,   269,
     270,   271,  -256,   276,    98,   268,  -256,   416,    13,   217,
    -256,   342,    58,   342,    58,   429,  -256,   429,  -256,   367,
    -256,   342,    58,   342,    58,   429,  -256,   429,  -256,   367,
    -256,   280,   442,  -256,   252,    11,  -256,   272,   137,   282,
     304,  -256,  -256,  -256,   307,   305,  -256,   168,   168,   168,
    -256,  -256,  -256,  -256,   307,   319,   367,   303,   237,   326,
     -11,   312,  -256,  -256,  -256,   429,   313,  -256,   442,  -256,
     612,   263,   502,   527,   327,  -256,   329,  -256,  -256,  -256,
    -256,     9,   260,   315,   324,  -256,   325,   328,   331,   332,
     367,  -256,   308,   237,   333,   237,   334,   280,   565,   180,
     543,   442,   442,  -256,  -256,  -256,  -256,  -256,  -256,  -256,
    -256,  -256,  -256,   402,   330,   330,   451,   402,   341,  -256,
    -256,   309,   355,   307,  -256,  -256,  -256,   282,  -256,   357,
    -256,  -256,  -256,  -256,   442,  -256,   237,  -256,   429,   343,
    -256,  -256,  -256,  -256,   293,   135,   533,  -256,  -256,  -256,
    -256,   373,  -256,   293,   135,   293,   135,   367,   344,   527,
    -256,   345,  -256,  -256,   156,   322,  -256,   334,  -256,  -256,
    -256,  -256,   138,  -256,   378,  -256,  -256,  -256,  -256
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    35,     0,     0,     0,     0,     0,    26,     0,     0,
       0,    27,    28,    29,    25,    24,     0,     0,     0,     0,
     166,    23,    22,    15,    16,    17,    18,     9,    10,    11,
      12,    13,    14,     8,     5,     7,     6,     4,     3,    19,
      20,    21,     0,    36,     0,     0,     0,    61,    62,    63,
      64,     0,     0,     0,     0,    65,     0,   162,   150,   152,
      88,     0,     0,     0,     0,     0,     0,    78,     0,   137,
      81,   151,   152,    33,    31,     0,     0,     0,     0,     0,
       0,   164,     1,   167,     2,     0,     0,    30,     0,     0,
       0,     0,     0,   161,    39,     0,     0,     0,     0,     0,
       0,   153,     0,     0,     0,     0,     0,     0,     0,   128,
     161,     0,     0,     0,     0,     0,     0,     0,    82,   123,
       0,     0,     0,     0,     0,   153,     0,     0,   104,     0,
       0,     0,     0,     0,     0,   156,     0,     0,     0,   154,
      40,   157,   158,   159,   160,     0,    89,     0,     0,     0,
       0,     0,   122,     0,     0,     0,    83,    79,    98,   104,
      86,   124,   129,   125,   130,   126,   131,   127,   132,     0,
      84,   133,   157,   134,   158,   135,   159,   136,   160,     0,
      32,     0,   106,    70,     0,   104,   165,     0,     0,    43,
       0,    41,    66,    68,     0,     0,   155,     0,     0,     0,
      90,    91,    92,    94,     0,     0,     0,    80,     0,     0,
      99,    96,    77,    87,    85,     0,    55,    56,     0,   105,
     107,     0,     0,     0,     0,    71,     0,    51,    52,    53,
      54,    47,     0,     0,     0,    50,     0,     0,     0,     0,
       0,   102,     0,     0,    97,     0,    59,     0,     0,     0,
       0,   106,   106,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,     0,     0,     0,     0,     0,     0,    72,
      74,     0,     0,     0,    49,    48,    46,    43,    42,     0,
      67,    69,    93,    95,   106,   103,     0,   100,     0,     0,
      57,   110,   108,   109,   113,   114,     0,   120,   118,   121,
     119,     0,   117,   116,   111,   112,   115,     0,     0,     0,
     163,     0,    44,    37,     0,   148,   101,    59,    58,    76,
      73,    75,    47,    34,     0,   149,    60,    45,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -256,  -256,   366,  -256,  -256,  -256,  -256,  -256,  -256,  -256,
    -256,  -256,  -256,  -256,  -256,  -256,   -42,  -256,  -256,   109,
     153,    65,  -197,  -256,  -256,  -256,  -224,    71,   -26,  -256,
    -256,  -256,  -255,    37,  -107,   -91,  -200,  -134,  -232,   176,
      39,  -175,  -205,  -256,    -1,    -3,  -256,  -256,  -256,  -256
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    44,   314,   101,    32,    33,   233,
     189,   276,   236,   231,    34,   216,   217,   289,    57,    35,
      36,   185,   270,   308,    68,    69,   159,   183,   219,   220,
      70,   263,   211,    38,   139,   157,    39,    40,    41,    84
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,    72,    58,    71,   156,   244,   160,   238,   241,   298,
     300,   302,   151,   170,   243,   153,   154,   155,    94,   292,
     293,    47,    48,   290,    49,   212,    50,    45,   118,    46,
     125,    42,   273,    74,    75,    82,   224,    37,   208,    73,
     297,   299,   152,   285,   119,   287,   266,   267,    89,   209,
     182,   225,   315,    93,   321,    37,    78,    96,    76,   105,
     193,   194,   213,   110,   136,   137,   138,    52,    53,    54,
     274,   275,   214,   209,   266,   267,   311,    79,   119,    55,
     136,   137,   138,   119,    43,   179,   316,    77,   114,   115,
     116,   117,    59,    80,   141,   142,   143,   144,   -80,   170,
      83,   104,    99,   100,   186,   109,   153,   154,   155,    85,
     325,   162,   164,   166,   168,   207,   210,    72,   172,   174,
     176,   178,   203,   204,    47,    48,    94,    49,    86,    50,
     123,   124,    87,   214,    88,   119,    90,   119,    91,   119,
      92,   119,    59,   102,   196,   119,   113,   119,   103,   119,
     112,   119,   127,   161,   163,   165,   167,    60,   111,    61,
     171,   173,   175,   177,   135,    96,   227,   228,   229,   230,
      52,    53,    54,    60,   106,    61,    72,   107,   196,   222,
     323,   324,    55,    47,    48,   108,    49,   126,    50,   246,
     128,   114,   115,   116,   117,   119,   130,   269,   132,   274,
     275,   147,   148,   149,   152,   121,   122,   123,   124,   129,
      97,    98,    99,   100,   133,   250,   131,   147,   148,   149,
      94,   221,   134,   119,   150,   140,   135,   146,   145,    52,
      53,    54,   253,   254,   255,   256,   257,   258,   259,   260,
      95,    55,   158,   261,   262,   180,   264,   265,   222,   222,
     114,   115,   116,   117,   169,   181,   182,   249,   184,    96,
     295,   187,   317,   304,   306,   188,    47,    48,   119,    49,
     246,    50,   121,   122,   123,   124,   190,   119,   191,   119,
     192,   222,   195,   320,   197,    97,    98,    99,   100,   198,
     221,   221,   199,   205,   200,   201,    47,    48,   105,    49,
     202,    50,   294,   215,   223,   303,   305,   232,   226,   234,
     235,   237,    52,    53,    54,   253,   254,   255,   256,   257,
     258,   259,   260,   221,    55,   239,   261,   262,   240,   264,
     265,   242,   271,   114,   115,   116,   117,   245,   247,   278,
     104,   272,    52,    53,    54,    47,    48,   279,    49,   280,
      50,   284,   281,   296,    55,   282,   283,   307,   286,   288,
     310,   309,   313,   114,   115,   116,   117,   318,   319,   322,
      47,    48,    60,    49,    61,    50,    47,    48,    60,    49,
      61,    50,   209,   328,    81,   277,   312,   327,   326,   307,
      62,    52,    53,    54,   248,     0,    62,     0,     0,     0,
       0,     0,     0,    55,     0,    47,    48,    60,    49,    61,
      50,     0,     0,     0,   116,   117,    63,    64,    65,     0,
       0,    94,    63,    64,    65,    62,     0,     0,    55,     0,
       0,     0,    47,    48,    55,    49,     0,    50,    66,    67,
       0,   206,     0,     0,    66,    47,    48,    60,    49,    61,
      50,    63,    64,    65,    47,    48,    60,    49,    61,    50,
      96,    47,    48,    55,    49,   218,    50,     0,     0,     0,
       0,     0,     0,    66,   301,     0,     0,    94,    52,    53,
      54,    51,     0,     0,     0,     0,   121,   122,   123,   124,
      55,    63,    64,    65,     0,     0,     0,   120,     0,     0,
      63,    64,    65,    55,     0,     0,     0,    52,    53,    54,
     -79,     0,    55,    66,     0,     0,    96,     0,     0,    55,
       0,     0,    66,    47,    48,    60,    49,    61,    50,    56,
      47,    48,     0,    49,     0,    50,    47,    48,     0,    49,
       0,    50,   121,   122,   123,   124,     0,     0,     0,   307,
     268,     0,     0,     0,   253,   254,   255,   256,   257,   258,
     259,   260,     0,     0,     0,   261,   262,   135,     0,    63,
      64,    65,   121,   122,   123,   124,    52,    53,    54,     0,
       0,    55,    52,    53,    54,     0,     0,     0,    55,   291,
       0,     0,     0,     0,    55,   253,   254,   255,   256,   257,
     258,   259,   260,     0,     0,     0,   261,   262,     0,     0,
       0,     0,     0,   121,   122,   123,   124,   253,   254,   255,
     256,   257,   258,   259,   260,     1,     2,     0,   261,   262,
       3,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    11,    12,    13,     0,     0,     0,     0,    14,    15,
       0,     0,   251,   252,     0,     0,     0,    16,     0,     0,
      17,     0,     0,    18,   253,   254,   255,   256,   257,   258,
     259,   260,     0,     0,     0,   261,   262
};

static const yytype_int16 yycheck[] =
{
       3,     4,     3,     4,   111,   210,   113,   204,   208,   264,
     265,   266,   103,   120,    25,   106,   107,   108,     5,   251,
     252,     3,     4,   247,     6,   159,     8,    12,    70,    14,
      72,    12,    23,    13,    14,     0,    25,     0,    25,     5,
     264,   265,    24,   243,    70,   245,   221,   222,    51,    60,
      39,   185,   284,    56,   309,    18,     5,    44,    36,    62,
      24,    25,   169,    66,    90,    91,    92,    49,    50,    51,
      61,    62,   179,    60,   249,   250,   273,     5,   104,    61,
     106,   107,   108,   109,    65,    25,   286,    38,    70,    71,
      72,    73,    95,    46,    97,    98,    99,   100,    38,   206,
       9,    62,    72,    73,   130,    66,   197,   198,   199,     5,
     315,   114,   115,   116,   117,   157,   158,   120,   121,   122,
     123,   124,    24,    25,     3,     4,     5,     6,    14,     8,
      72,    73,     5,   240,     5,   161,    23,   163,    23,   165,
      23,   167,   145,    35,   145,   171,    25,   173,    23,   175,
      38,   177,     5,   114,   115,   116,   117,     5,    25,     7,
     121,   122,   123,   124,    24,    44,    29,    30,    31,    32,
      49,    50,    51,     5,    23,     7,   179,    23,   179,   182,
      24,    25,    61,     3,     4,    23,     6,    38,     8,   215,
       5,    70,    71,    72,    73,   221,    52,   223,    23,    61,
      62,    49,    50,    51,    24,    70,    71,    72,    73,    42,
      70,    71,    72,    73,     5,   218,    47,    49,    50,    51,
       5,   182,    43,   249,    72,     5,    24,     5,    25,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      25,    61,     5,    63,    64,     5,    66,    67,   251,   252,
      70,    71,    72,    73,    25,    37,    39,   218,     5,    44,
     263,     6,   288,   266,   267,     5,     3,     4,   294,     6,
     296,     8,    70,    71,    72,    73,    43,   303,     5,   305,
      24,   284,    25,   309,    23,    70,    71,    72,    73,    23,
     251,   252,    23,    25,    24,    24,     3,     4,   301,     6,
      24,     8,   263,    23,    52,   266,   267,    25,    36,     5,
       3,     6,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,   284,    61,     6,    63,    64,    25,    66,
      67,     5,     5,    70,    71,    72,    73,    25,    25,    24,
     301,    12,    49,    50,    51,     3,     4,    23,     6,    24,
       8,    43,    24,    23,    61,    24,    24,    16,    25,    25,
       5,    52,     5,    70,    71,    72,    73,    24,    24,    24,
       3,     4,     5,     6,     7,     8,     3,     4,     5,     6,
       7,     8,    60,     5,    18,   232,   277,   322,   317,    16,
      23,    49,    50,    51,   218,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    72,    73,    49,    50,    51,    -1,
      -1,     5,    49,    50,    51,    23,    -1,    -1,    61,    -1,
      -1,    -1,     3,     4,    61,     6,    -1,     8,    71,    72,
      -1,    25,    -1,    -1,    71,     3,     4,     5,     6,     7,
       8,    49,    50,    51,     3,     4,     5,     6,     7,     8,
      44,     3,     4,    61,     6,    23,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    23,    -1,    -1,     5,    49,    50,
      51,    23,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      61,    49,    50,    51,    -1,    -1,    -1,    25,    -1,    -1,
      49,    50,    51,    61,    -1,    -1,    -1,    49,    50,    51,
      38,    -1,    61,    71,    -1,    -1,    44,    -1,    -1,    61,
      -1,    -1,    71,     3,     4,     5,     6,     7,     8,    71,
       3,     4,    -1,     6,    -1,     8,     3,     4,    -1,     6,
      -1,     8,    70,    71,    72,    73,    -1,    -1,    -1,    16,
      23,    -1,    -1,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    -1,    -1,    63,    64,    24,    -1,    49,
      50,    51,    70,    71,    72,    73,    49,    50,    51,    -1,
      -1,    61,    49,    50,    51,    -1,    -1,    -1,    61,    24,
      -1,    -1,    -1,    -1,    61,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    52,    53,    54,
      55,    56,    57,    58,    59,    10,    11,    -1,    63,    64,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    -1,    -1,    -1,    -1,    33,    34,
      -1,    -1,    40,    41,    -1,    -1,    -1,    42,    -1,    -1,
      45,    -1,    -1,    48,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    -1,    -1,    63,    64
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    11,    15,    16,    17,    18,    19,    20,    21,
      22,    26,    27,    28,    33,    34,    42,    45,    48,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    92,    93,    99,   104,   105,   108,   118,   121,
     122,   123,    12,    65,    89,    12,    14,     3,     4,     6,
       8,    23,    49,    50,    51,    61,    71,   103,   119,   120,
       5,     7,    23,    49,    50,    51,    71,    72,   109,   110,
     115,   119,   120,     5,    13,    14,    36,    38,     5,     5,
      46,    77,     0,     9,   124,     5,    14,     5,     5,   120,
      23,    23,    23,   120,     5,    25,    44,    70,    71,    72,
      73,    91,    35,    23,   115,   120,    23,    23,    23,   115,
     120,    25,    38,    25,    70,    71,    72,    73,    91,   103,
      25,    70,    71,    72,    73,    91,    38,     5,     5,    42,
      52,    47,    23,     5,    43,    24,   103,   103,   103,   119,
       5,   120,   120,   120,   120,    25,     5,    49,    50,    51,
      72,   110,    24,   110,   110,   110,   109,   120,     5,   111,
     109,   115,   120,   115,   120,   115,   120,   115,   120,    25,
     109,   115,   120,   115,   120,   115,   120,   115,   120,    25,
       5,    37,    39,   112,     5,   106,   103,     6,     5,    95,
      43,     5,    24,    24,    25,    25,   119,    23,    23,    23,
      24,    24,    24,    24,    25,    25,    25,    91,    25,    60,
      91,   117,   112,   109,   109,    23,   100,   101,    23,   113,
     114,   115,   120,    52,    25,   112,    36,    29,    30,    31,
      32,    98,    25,    94,     5,     3,    97,     6,    97,     6,
      25,   111,     5,    25,   117,    25,   103,    25,   114,   115,
     120,    40,    41,    52,    53,    54,    55,    56,    57,    58,
      59,    63,    64,   116,    66,    67,   116,   116,    23,   103,
     107,     5,    12,    23,    61,    62,    96,    95,    24,    23,
      24,    24,    24,    24,    43,   111,    25,   111,    25,   102,
     101,    24,   113,   113,   115,   120,    23,   101,   107,   101,
     107,    23,   107,   115,   120,   115,   120,    16,   108,    52,
       5,    97,    94,     5,    90,   113,   111,   103,    24,    24,
     103,   107,    24,    24,    25,   117,   102,    96,     5
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    75,    76,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    89,    90,    90,    91,
      91,    92,    93,    94,    94,    95,    95,    96,    96,    96,
      97,    98,    98,    98,    98,    99,   100,   100,   101,   102,
     102,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     104,   105,   106,   106,   106,   106,   107,   108,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   110,   110,
     110,   110,   110,   110,   110,   110,   111,   111,   111,   111,
     111,   111,   111,   111,   112,   112,   113,   113,   113,   113,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   117,   117,
     118,   118,   119,   119,   119,   119,   120,   120,   120,   120,
     120,   120,   120,   121,   122,   123,   124,   124
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     4,     2,     9,     0,     1,     1,     3,     1,
       2,     5,     7,     0,     3,     6,     3,     0,     1,     1,
       1,     1,     1,     1,     1,     5,     1,     3,     4,     0,
       3,     1,     1,     1,     1,     1,     4,     6,     4,     6,
       4,     5,     3,     5,     3,     5,     3,     5,     1,     1,
       2,     1,     2,     3,     3,     4,     3,     4,     1,     3,
       4,     4,     4,     6,     4,     6,     2,     3,     1,     2,
       4,     5,     3,     4,     0,     2,     0,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     5,
       2,     2,     1,     2,     3,     4,     3,     3,     3,     3,
       3,     2,     1,     7,     2,     4,     0,     1
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
#line 215 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1933 "yacc_sql.cpp"
    break;

  case 24: /* exit_stmt: EXIT  */
#line 246 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1942 "yacc_sql.cpp"
    break;

  case 25: /* help_stmt: HELP  */
#line 252 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1950 "yacc_sql.cpp"
    break;

  case 26: /* sync_stmt: SYNC  */
#line 257 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1958 "yacc_sql.cpp"
    break;

  case 27: /* begin_stmt: TRX_BEGIN  */
#line 263 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1966 "yacc_sql.cpp"
    break;

  case 28: /* commit_stmt: TRX_COMMIT  */
#line 269 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 1974 "yacc_sql.cpp"
    break;

  case 29: /* rollback_stmt: TRX_ROLLBACK  */
#line 275 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 1982 "yacc_sql.cpp"
    break;

  case 30: /* drop_table_stmt: DROP TABLE ID  */
#line 281 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1992 "yacc_sql.cpp"
    break;

  case 31: /* show_tables_stmt: SHOW TABLES  */
#line 288 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 2000 "yacc_sql.cpp"
    break;

  case 32: /* show_index_stmt: SHOW INDEX FROM ID  */
#line 294 "yacc_sql.y"
                       {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_INDEX);
      (yyval.sql_node)->show_index.relation_name = (yyvsp[0].string);
    }
#line 2009 "yacc_sql.cpp"
    break;

  case 33: /* desc_table_stmt: DESC ID  */
#line 301 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2019 "yacc_sql.cpp"
    break;

  case 34: /* create_index_stmt: CREATE is_unique INDEX ID ON ID LBRACE id_list RBRACE  */
#line 310 "yacc_sql.y"
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
#line 2039 "yacc_sql.cpp"
    break;

  case 35: /* is_unique: %empty  */
#line 328 "yacc_sql.y"
    {
      (yyval.bools) = false;
    }
#line 2047 "yacc_sql.cpp"
    break;

  case 36: /* is_unique: UNIQUE  */
#line 331 "yacc_sql.y"
             {
      (yyval.bools) = true;
    }
#line 2055 "yacc_sql.cpp"
    break;

  case 37: /* id_list: ID  */
#line 337 "yacc_sql.y"
    {
      (yyval.field_list) = new std::vector<std::string>;
      (yyval.field_list)->push_back((yyvsp[0].string));
      free((yyvsp[0].string));
    }
#line 2065 "yacc_sql.cpp"
    break;

  case 38: /* id_list: id_list COMMA ID  */
#line 343 "yacc_sql.y"
    {
      (yyval.field_list) = (yyvsp[-2].field_list);
      (yyval.field_list)->push_back((yyvsp[0].string));
      free((yyvsp[0].string));
    }
#line 2075 "yacc_sql.cpp"
    break;

  case 39: /* alias: ID  */
#line 351 "yacc_sql.y"
     {
    (yyval.string) = common::substr((yyvsp[0].string),0,strlen((yyvsp[0].string)));
  }
#line 2083 "yacc_sql.cpp"
    break;

  case 40: /* alias: AS ID  */
#line 354 "yacc_sql.y"
          {
    (yyval.string) = common::substr((yyvsp[0].string),0,strlen((yyvsp[0].string)));
  }
#line 2091 "yacc_sql.cpp"
    break;

  case 41: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 361 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2103 "yacc_sql.cpp"
    break;

  case 42: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE  */
#line 371 "yacc_sql.y"
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
#line 2123 "yacc_sql.cpp"
    break;

  case 43: /* attr_def_list: %empty  */
#line 389 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 2131 "yacc_sql.cpp"
    break;

  case 44: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 393 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2145 "yacc_sql.cpp"
    break;

  case 45: /* attr_def: ID type LBRACE number RBRACE is_nullable  */
#line 406 "yacc_sql.y"
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
#line 2160 "yacc_sql.cpp"
    break;

  case 46: /* attr_def: ID type is_nullable  */
#line 417 "yacc_sql.y"
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
#line 2179 "yacc_sql.cpp"
    break;

  case 47: /* is_nullable: %empty  */
#line 434 "yacc_sql.y"
     {
       (yyval.bools) = false;
     }
#line 2187 "yacc_sql.cpp"
    break;

  case 48: /* is_nullable: NOT_NULL  */
#line 438 "yacc_sql.y"
     {
       (yyval.bools) = false;
     }
#line 2195 "yacc_sql.cpp"
    break;

  case 49: /* is_nullable: NULL_T  */
#line 441 "yacc_sql.y"
              {
       (yyval.bools) = true;
     }
#line 2203 "yacc_sql.cpp"
    break;

  case 50: /* number: NUMBER  */
#line 445 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2209 "yacc_sql.cpp"
    break;

  case 51: /* type: INT_T  */
#line 448 "yacc_sql.y"
               { (yyval.number)=INTS; }
#line 2215 "yacc_sql.cpp"
    break;

  case 52: /* type: STRING_T  */
#line 449 "yacc_sql.y"
               { (yyval.number)=CHARS; }
#line 2221 "yacc_sql.cpp"
    break;

  case 53: /* type: FLOAT_T  */
#line 450 "yacc_sql.y"
               { (yyval.number)=FLOATS; }
#line 2227 "yacc_sql.cpp"
    break;

  case 54: /* type: DATE_T  */
#line 451 "yacc_sql.y"
               { (yyval.number)=DATES; }
#line 2233 "yacc_sql.cpp"
    break;

  case 55: /* insert_stmt: INSERT INTO ID VALUES record_list  */
#line 455 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_INSERT);
      (yyval.sql_node)->insertion.relation_name = (yyvsp[-2].string);
      (yyval.sql_node)->insertion.values.swap(*(yyvsp[0].record_list));
    }
#line 2243 "yacc_sql.cpp"
    break;

  case 56: /* record_list: record  */
#line 463 "yacc_sql.y"
    {
      (yyval.record_list) = new std::vector<std::vector<Value>>;
      (yyval.record_list)->emplace_back(std::move(*(yyvsp[0].value_list)));
    }
#line 2252 "yacc_sql.cpp"
    break;

  case 57: /* record_list: record_list COMMA record  */
#line 468 "yacc_sql.y"
    {
      // 无需考虑插入顺序
      if ((yyvsp[-2].record_list) != nullptr) {
        (yyval.record_list) = (yyvsp[-2].record_list);
      } else {
      (yyval.record_list) = new std::vector<std::vector<Value>>;
      }
      (yyval.record_list)->emplace_back(std::move(*(yyvsp[0].value_list)));
    }
#line 2266 "yacc_sql.cpp"
    break;

  case 58: /* record: LBRACE value value_list RBRACE  */
#line 480 "yacc_sql.y"
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
#line 2281 "yacc_sql.cpp"
    break;

  case 59: /* value_list: %empty  */
#line 493 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2289 "yacc_sql.cpp"
    break;

  case 60: /* value_list: COMMA value value_list  */
#line 496 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2303 "yacc_sql.cpp"
    break;

  case 61: /* value: NUMBER  */
#line 507 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2312 "yacc_sql.cpp"
    break;

  case 62: /* value: FLOAT  */
#line 511 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2321 "yacc_sql.cpp"
    break;

  case 63: /* value: SSS  */
#line 515 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
      (yyloc) = (yylsp[0]);
    }
#line 2332 "yacc_sql.cpp"
    break;

  case 64: /* value: DATE  */
#line 521 "yacc_sql.y"
          {
      if (!((yyvsp[0].dates)).ok()) {
        LOG_WARN("date is invalid");
        return -1;
      }
      (yyval.value) = new Value((date)(yyvsp[0].dates));
      (yyloc) = (yylsp[0]);
    }
#line 2345 "yacc_sql.cpp"
    break;

  case 65: /* value: NULL_T  */
#line 529 "yacc_sql.y"
            {
      (yyval.value) = new Value();
      (yyval.value)->set_null();
      (yyloc) = (yylsp[0]);
    }
#line 2355 "yacc_sql.cpp"
    break;

  case 66: /* value: LENGTH LBRACE value RBRACE  */
#line 535 "yacc_sql.y"
    {
        if ((yyvsp[-1].value)->attr_type() != AttrType::CHARS) {
          LOG_ERROR("length function only support string type.");
          return -1;
        }
        (yyval.value) = new Value((int)(yyvsp[-1].value)->get_string().size());  // translate into int
        free((yyvsp[-1].value));
        (yyloc) = (yylsp[-3]);
    }
#line 2369 "yacc_sql.cpp"
    break;

  case 67: /* value: ROUND LBRACE value COMMA number RBRACE  */
#line 545 "yacc_sql.y"
    {
        if ((yyvsp[-3].value)->attr_type() != AttrType::FLOATS) {
          LOG_ERROR("round function only support float type.");
          return -1;
        }
        (yyval.value) = new Value((float)(std::round((yyvsp[-3].value)->get_float() * pow(10, (yyvsp[-1].number))) / pow(10, (yyvsp[-1].number))));
        free((yyvsp[-3].value));
        (yyloc) = (yylsp[-5]);
    }
#line 2383 "yacc_sql.cpp"
    break;

  case 68: /* value: ROUND LBRACE value RBRACE  */
#line 555 "yacc_sql.y"
    {
        if ((yyvsp[-1].value)->attr_type() != AttrType::FLOATS) {
          LOG_ERROR("round function only support float type.");
          return -1;
        }
        (yyval.value) = new Value((std::round((yyvsp[-1].value)->get_float())));
        free((yyvsp[-1].value));
        (yyloc) = (yylsp[-3]);
    }
#line 2397 "yacc_sql.cpp"
    break;

  case 69: /* value: DATE_FORMAT LBRACE value COMMA SSS RBRACE  */
#line 565 "yacc_sql.y"
    {
        if ((yyvsp[-3].value)->attr_type() != AttrType::DATES) {
          LOG_ERROR("data_format function only support date type.");
          return -1;
        }
        (yyval.value) = new Value((date)(yyvsp[-3].value)->get_date(), common::substr((yyvsp[-1].string),1,strlen((yyvsp[-1].string))-2));
        free((yyvsp[-3].value));
        (yyloc) = (yylsp[-5]);
    }
#line 2411 "yacc_sql.cpp"
    break;

  case 70: /* delete_stmt: DELETE FROM ID where  */
#line 578 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].expression_list));
      }
      free((yyvsp[-1].string));
    }
#line 2424 "yacc_sql.cpp"
    break;

  case 71: /* update_stmt: UPDATE ID SET update_list where  */
#line 589 "yacc_sql.y"
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
#line 2440 "yacc_sql.cpp"
    break;

  case 72: /* update_list: ID EQ value  */
#line 602 "yacc_sql.y"
                {
      (yyval.update_list) = new std::vector<std::pair<std::string, Expression*>>;
      (yyval.update_list)->emplace_back(make_pair((yyvsp[-2].string), new ValueExpr(*(yyvsp[0].value))));
      free((yyvsp[-2].string));
      free((yyvsp[0].value));
    }
#line 2451 "yacc_sql.cpp"
    break;

  case 73: /* update_list: update_list COMMA ID EQ value  */
#line 609 "yacc_sql.y"
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
#line 2466 "yacc_sql.cpp"
    break;

  case 74: /* update_list: ID EQ subquery  */
#line 619 "yacc_sql.y"
                     {
      (yyval.update_list) = new std::vector<std::pair<std::string, Expression*>>;
      (yyval.update_list)->emplace_back(make_pair((yyvsp[-2].string), new SubQueryExpr(*(yyvsp[0].sql_node))));
      free((yyvsp[-2].string));
      delete (yyvsp[0].sql_node);
    }
#line 2477 "yacc_sql.cpp"
    break;

  case 75: /* update_list: update_list COMMA ID EQ subquery  */
#line 626 "yacc_sql.y"
    {
      if ((yyvsp[-4].update_list) != nullptr) {
        (yyval.update_list) = (yyvsp[-4].update_list);
      } else {
        (yyval.update_list) = new std::vector<std::pair<std::string, Expression*>>;
      }
      (yyval.update_list)->emplace_back(make_pair((yyvsp[-2].string), new SubQueryExpr(*(yyvsp[0].sql_node))));
      free((yyvsp[-2].string));
    }
#line 2491 "yacc_sql.cpp"
    break;

  case 76: /* subquery: LBRACE select_stmt RBRACE  */
#line 637 "yacc_sql.y"
                              {
      (yyval.sql_node) = (yyvsp[-1].sql_node);
    }
#line 2499 "yacc_sql.cpp"
    break;

  case 77: /* select_stmt: SELECT attr_list FROM rel_list where  */
#line 643 "yacc_sql.y"
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
      std::reverse((yyval.sql_node)->selection.relations.begin(), (yyval.sql_node)->selection.relations.end());
    }
#line 2524 "yacc_sql.cpp"
    break;

  case 78: /* attr_list: '*'  */
#line 665 "yacc_sql.y"
        {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back(new StarExpr("*"));
    }
#line 2533 "yacc_sql.cpp"
    break;

  case 79: /* attr_list: expression  */
#line 669 "yacc_sql.y"
                 {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2542 "yacc_sql.cpp"
    break;

  case 80: /* attr_list: expression alias  */
#line 673 "yacc_sql.y"
                       {
      (yyvsp[-1].expression)->set_alias((yyvsp[0].string));
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[-1].expression));
      free((yyvsp[0].string));
    }
#line 2553 "yacc_sql.cpp"
    break;

  case 81: /* attr_list: rel_expr  */
#line 679 "yacc_sql.y"
               {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2562 "yacc_sql.cpp"
    break;

  case 82: /* attr_list: rel_expr alias  */
#line 683 "yacc_sql.y"
                     {
      (yyvsp[-1].expression)->set_alias((yyvsp[0].string));
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[-1].expression));
      free((yyvsp[0].string));
    }
#line 2573 "yacc_sql.cpp"
    break;

  case 83: /* attr_list: '*' COMMA attr_list  */
#line 689 "yacc_sql.y"
                          {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      (yyval.expression_list)->emplace_back(new StarExpr("*"));
    }
#line 2586 "yacc_sql.cpp"
    break;

  case 84: /* attr_list: expression COMMA attr_list  */
#line 697 "yacc_sql.y"
                                 {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 2599 "yacc_sql.cpp"
    break;

  case 85: /* attr_list: expression alias COMMA attr_list  */
#line 705 "yacc_sql.y"
                                       {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      (yyvsp[-3].expression)->set_alias((yyvsp[-2].string));
      (yyval.expression_list)->emplace_back((yyvsp[-3].expression));
    }
#line 2613 "yacc_sql.cpp"
    break;

  case 86: /* attr_list: rel_expr COMMA attr_list  */
#line 714 "yacc_sql.y"
                               {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 2626 "yacc_sql.cpp"
    break;

  case 87: /* attr_list: rel_expr alias COMMA attr_list  */
#line 722 "yacc_sql.y"
                                     {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      (yyvsp[-3].expression)->set_alias((yyvsp[-2].string));
      (yyval.expression_list)->emplace_back((yyvsp[-3].expression));
    }
#line 2640 "yacc_sql.cpp"
    break;

  case 88: /* rel_attr: ID  */
#line 734 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2650 "yacc_sql.cpp"
    break;

  case 89: /* rel_attr: ID DOT ID  */
#line 739 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2662 "yacc_sql.cpp"
    break;

  case 90: /* rel_attr: AGG LBRACE '*' RBRACE  */
#line 746 "yacc_sql.y"
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
#line 2677 "yacc_sql.cpp"
    break;

  case 91: /* rel_attr: AGG LBRACE rel_attr RBRACE  */
#line 756 "yacc_sql.y"
                                 {
      (yyval.rel_attr) = (yyvsp[-1].rel_attr);
      (yyval.rel_attr)->func_type = (yyvsp[-3].func_t);
    }
#line 2686 "yacc_sql.cpp"
    break;

  case 92: /* rel_attr: LENGTH LBRACE rel_attr RBRACE  */
#line 760 "yacc_sql.y"
                                    {
      (yyval.rel_attr) = (yyvsp[-1].rel_attr);
      (yyval.rel_attr)->func_type = FUNC_LENGTH;
    }
#line 2695 "yacc_sql.cpp"
    break;

  case 93: /* rel_attr: ROUND LBRACE rel_attr COMMA number RBRACE  */
#line 764 "yacc_sql.y"
                                                {
      (yyval.rel_attr) = (yyvsp[-3].rel_attr);
      (yyval.rel_attr)->func_type = FUNC_ROUND;
      (yyval.rel_attr)->func_parm = std::to_string((yyvsp[-1].number));
    }
#line 2705 "yacc_sql.cpp"
    break;

  case 94: /* rel_attr: ROUND LBRACE rel_attr RBRACE  */
#line 769 "yacc_sql.y"
                                   {
      (yyval.rel_attr) = (yyvsp[-1].rel_attr);
      (yyval.rel_attr)->func_type = FUNC_ROUND;
      (yyval.rel_attr)->func_parm = std::to_string(0);
    }
#line 2715 "yacc_sql.cpp"
    break;

  case 95: /* rel_attr: DATE_FORMAT LBRACE rel_attr COMMA SSS RBRACE  */
#line 774 "yacc_sql.y"
                                                   {
      (yyval.rel_attr) = (yyvsp[-3].rel_attr);
      (yyval.rel_attr)->func_type = FUNC_DATE_FORMAT;
      (yyval.rel_attr)->func_parm = common::substr((yyvsp[-1].string),1,strlen((yyvsp[-1].string))-2);
      free((yyvsp[-1].string));
    }
#line 2726 "yacc_sql.cpp"
    break;

  case 96: /* rel_list: ID join_stmt  */
#line 784 "yacc_sql.y"
    {
      (yyval.join_list) = (yyvsp[0].join_list);
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-1].string));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-1].string));
    }
#line 2738 "yacc_sql.cpp"
    break;

  case 97: /* rel_list: ID alias join_stmt  */
#line 792 "yacc_sql.y"
    {
      (yyval.join_list) = (yyvsp[0].join_list);
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-2].string), (yyvsp[-1].string));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-2].string));
      free((yyvsp[-1].string));
    }
#line 2751 "yacc_sql.cpp"
    break;

  case 98: /* rel_list: ID  */
#line 801 "yacc_sql.y"
    {
      (yyval.join_list) = new std::vector<JoinSqlNode>;
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[0].string));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[0].string));
    }
#line 2763 "yacc_sql.cpp"
    break;

  case 99: /* rel_list: ID alias  */
#line 809 "yacc_sql.y"
    {
      (yyval.join_list) = new std::vector<JoinSqlNode>;
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-1].string), (yyvsp[0].string));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-1].string));
      free((yyvsp[0].string));
    }
#line 2776 "yacc_sql.cpp"
    break;

  case 100: /* rel_list: ID join_stmt COMMA rel_list  */
#line 818 "yacc_sql.y"
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
#line 2795 "yacc_sql.cpp"
    break;

  case 101: /* rel_list: ID alias join_stmt COMMA rel_list  */
#line 833 "yacc_sql.y"
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
#line 2815 "yacc_sql.cpp"
    break;

  case 102: /* rel_list: ID COMMA rel_list  */
#line 849 "yacc_sql.y"
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
#line 2831 "yacc_sql.cpp"
    break;

  case 103: /* rel_list: ID alias COMMA rel_list  */
#line 861 "yacc_sql.y"
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
#line 2848 "yacc_sql.cpp"
    break;

  case 104: /* where: %empty  */
#line 876 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 2856 "yacc_sql.cpp"
    break;

  case 105: /* where: WHERE condition_list  */
#line 879 "yacc_sql.y"
                           {
      (yyval.expression_list) = (yyvsp[0].expression_list);
    }
#line 2864 "yacc_sql.cpp"
    break;

  case 106: /* condition_list: %empty  */
#line 885 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 2872 "yacc_sql.cpp"
    break;

  case 107: /* condition_list: condition  */
#line 888 "yacc_sql.y"
                {
      (yyval.expression_list) = new std::vector<Expression*>;
      std::vector<std::unique_ptr<Expression>> children;
      children.emplace_back((yyvsp[0].expression));
      (yyval.expression_list)->emplace_back(new ConjunctionExpr(ConjunctionExpr::Type::AND, children));
    }
#line 2883 "yacc_sql.cpp"
    break;

  case 108: /* condition_list: condition AND condition_list  */
#line 894 "yacc_sql.y"
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
#line 2898 "yacc_sql.cpp"
    break;

  case 109: /* condition_list: condition OR condition_list  */
#line 904 "yacc_sql.y"
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
#line 2913 "yacc_sql.cpp"
    break;

  case 110: /* condition: LBRACE condition RBRACE  */
#line 917 "yacc_sql.y"
    {
      (yyval.expression) = (yyvsp[-1].expression);
    }
#line 2921 "yacc_sql.cpp"
    break;

  case 111: /* condition: rel_expr comp_op expression  */
#line 921 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 2932 "yacc_sql.cpp"
    break;

  case 112: /* condition: expression comp_op rel_expr  */
#line 928 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 2943 "yacc_sql.cpp"
    break;

  case 113: /* condition: condition comp_op rel_expr  */
#line 935 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 2954 "yacc_sql.cpp"
    break;

  case 114: /* condition: condition comp_op expression  */
#line 942 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 2965 "yacc_sql.cpp"
    break;

  case 115: /* condition: expression comp_op expression  */
#line 949 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 2976 "yacc_sql.cpp"
    break;

  case 116: /* condition: rel_expr comp_op rel_expr  */
#line 956 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 2987 "yacc_sql.cpp"
    break;

  case 117: /* condition: rel_expr comp_op subquery  */
#line 963 "yacc_sql.y"
    {
      auto subquery_expr = new SubQueryExpr(*(yyvsp[0].sql_node));
      subquery_expr->set_subquery_type(SubQueryType::SINGLE_VALUE);
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>(subquery_expr)
      );
    }
#line 3000 "yacc_sql.cpp"
    break;

  case 118: /* condition: rel_expr IN_ subquery  */
#line 972 "yacc_sql.y"
    {
      auto subquery_expr = new SubQueryExpr(*(yyvsp[0].sql_node));
      subquery_expr->set_subquery_type(SubQueryType::LIST_VALUE);
      (yyval.expression) = new ComparisonExpr(CompOp::IN,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>(subquery_expr)
      );
    }
#line 3013 "yacc_sql.cpp"
    break;

  case 119: /* condition: rel_expr NOT_IN_ subquery  */
#line 981 "yacc_sql.y"
    {
      auto subquery_expr = new SubQueryExpr(*(yyvsp[0].sql_node));
      subquery_expr->set_subquery_type(SubQueryType::LIST_VALUE);
      (yyval.expression) = new ComparisonExpr(CompOp::IN,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>(subquery_expr)
      );
    }
#line 3026 "yacc_sql.cpp"
    break;

  case 120: /* condition: rel_expr IN_ record  */
#line 990 "yacc_sql.y"
    {
      auto subquery_expr = new SubQueryExpr();
      subquery_expr->set_list_tuple(*(yyvsp[0].value_list));
      subquery_expr->set_subquery_type(SubQueryType::LIST_VALUE);
      (yyval.expression) = new ComparisonExpr(CompOp::IN,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>(subquery_expr)
      );
    }
#line 3040 "yacc_sql.cpp"
    break;

  case 121: /* condition: rel_expr NOT_IN_ record  */
#line 1000 "yacc_sql.y"
    {
      auto subquery_expr = new SubQueryExpr();
      subquery_expr->set_list_tuple(*(yyvsp[0].value_list));
      subquery_expr->set_subquery_type(SubQueryType::LIST_VALUE);
      (yyval.expression) = new ComparisonExpr(CompOp::NOT_IN,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>(subquery_expr)
      );
    }
#line 3054 "yacc_sql.cpp"
    break;

  case 122: /* rel_expr: LBRACE rel_expr RBRACE  */
#line 1013 "yacc_sql.y"
    {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3063 "yacc_sql.cpp"
    break;

  case 123: /* rel_expr: rel_expr value  */
#line 1017 "yacc_sql.y"
                     {
      if ((yyvsp[0].value)->attr_type() != AttrType::INTS && (yyvsp[0].value)->attr_type() != AttrType::FLOATS) { return -1; }
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::ADD,
        std::unique_ptr<Expression>((yyvsp[-1].expression)),
        std::make_unique<ValueExpr>(*(yyvsp[0].value))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3076 "yacc_sql.cpp"
    break;

  case 124: /* rel_expr: rel_expr '+' rel_expr  */
#line 1025 "yacc_sql.y"
                            {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::ADD,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3088 "yacc_sql.cpp"
    break;

  case 125: /* rel_expr: rel_expr '-' rel_expr  */
#line 1032 "yacc_sql.y"
                            {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::SUB,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3100 "yacc_sql.cpp"
    break;

  case 126: /* rel_expr: rel_expr '*' rel_expr  */
#line 1039 "yacc_sql.y"
                            {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::MUL,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3112 "yacc_sql.cpp"
    break;

  case 127: /* rel_expr: rel_expr '/' rel_expr  */
#line 1046 "yacc_sql.y"
                            {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::DIV,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3124 "yacc_sql.cpp"
    break;

  case 128: /* rel_expr: '-' rel_expr  */
#line 1053 "yacc_sql.y"
                                {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::SUB,
        std::make_unique<ValueExpr>(Value(0)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3136 "yacc_sql.cpp"
    break;

  case 129: /* rel_expr: rel_expr '+' expression  */
#line 1060 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::ADD,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3148 "yacc_sql.cpp"
    break;

  case 130: /* rel_expr: rel_expr '-' expression  */
#line 1067 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::SUB,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3160 "yacc_sql.cpp"
    break;

  case 131: /* rel_expr: rel_expr '*' expression  */
#line 1074 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::MUL,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3172 "yacc_sql.cpp"
    break;

  case 132: /* rel_expr: rel_expr '/' expression  */
#line 1081 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::DIV,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3184 "yacc_sql.cpp"
    break;

  case 133: /* rel_expr: expression '+' rel_expr  */
#line 1088 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::ADD,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3196 "yacc_sql.cpp"
    break;

  case 134: /* rel_expr: expression '-' rel_expr  */
#line 1095 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::SUB,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3208 "yacc_sql.cpp"
    break;

  case 135: /* rel_expr: expression '*' rel_expr  */
#line 1102 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::MUL,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3220 "yacc_sql.cpp"
    break;

  case 136: /* rel_expr: expression '/' rel_expr  */
#line 1109 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::DIV,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3232 "yacc_sql.cpp"
    break;

  case 137: /* rel_expr: rel_attr  */
#line 1116 "yacc_sql.y"
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

          if (type != FUNC_NONE) {
              std::string ans{};
              switch (type) {
                case FUNC_MIN: ans += "min(" + name + ')'; break;
                case FUNC_MAX: ans += "max(" + name + ')'; break;
                case FUNC_AVG: ans += "avg(" + name + ')'; break;
                case FUNC_SUM: ans += "sum(" + name + ')'; break;
                case FUNC_COUNT:
                case FUNC_WCOUNT: ans += "count(" + name + ')'; break;
                case FUNC_ROUND: {
                  if (parm.empty()) {
                    ans += "round(" + name + ')';
                  } else {
                    ans += "round(" + name + "," + parm + ')';
                  }
                } break;
                case FUNC_LENGTH: ans += "length(" + name + ')'; break;
                case FUNC_DATE_FORMAT: ans += "data_format(" + name + "," + parm + ')'; break;
                default:
                  LOG_WARN("Wrong func type.");
              }
              func_expr->set_name(ans);
          }
          (yyval.expression) = func_expr;
        } else {
          (yyval.expression) = field_expr;
        }
      }
      free((yyvsp[0].rel_attr));
    }
#line 3281 "yacc_sql.cpp"
    break;

  case 138: /* comp_op: EQ  */
#line 1163 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3287 "yacc_sql.cpp"
    break;

  case 139: /* comp_op: LT  */
#line 1164 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3293 "yacc_sql.cpp"
    break;

  case 140: /* comp_op: GT  */
#line 1165 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3299 "yacc_sql.cpp"
    break;

  case 141: /* comp_op: LE  */
#line 1166 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3305 "yacc_sql.cpp"
    break;

  case 142: /* comp_op: GE  */
#line 1167 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3311 "yacc_sql.cpp"
    break;

  case 143: /* comp_op: NE  */
#line 1168 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3317 "yacc_sql.cpp"
    break;

  case 144: /* comp_op: LIKE  */
#line 1169 "yacc_sql.y"
           { (yyval.comp) = LIKE_TO; }
#line 3323 "yacc_sql.cpp"
    break;

  case 145: /* comp_op: NOT_LIKE  */
#line 1170 "yacc_sql.y"
               { (yyval.comp) = NOT_LIKE_TO; }
#line 3329 "yacc_sql.cpp"
    break;

  case 146: /* comp_op: IS  */
#line 1171 "yacc_sql.y"
         { (yyval.comp) = IS_NULL; }
#line 3335 "yacc_sql.cpp"
    break;

  case 147: /* comp_op: IS_NOT  */
#line 1172 "yacc_sql.y"
             { (yyval.comp) = IS_NOT_NULL; }
#line 3341 "yacc_sql.cpp"
    break;

  case 148: /* join_stmt: INNER_JOIN ID ON condition_list  */
#line 1176 "yacc_sql.y"
                                    {
      (yyval.join_list) = new std::vector<JoinSqlNode>;
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-2].string));
      join.conditions.swap(*(yyvsp[0].expression_list));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-2].string));
    }
#line 3354 "yacc_sql.cpp"
    break;

  case 149: /* join_stmt: INNER_JOIN ID ON condition_list join_stmt  */
#line 1184 "yacc_sql.y"
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
#line 3371 "yacc_sql.cpp"
    break;

  case 150: /* calc_stmt: CALC expression_list  */
#line 1200 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      std::reverse((yyvsp[0].expression_list)->begin(), (yyvsp[0].expression_list)->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 3382 "yacc_sql.cpp"
    break;

  case 151: /* calc_stmt: SELECT expression_list  */
#line 1206 "yacc_sql.y"
                             {             //  select 1+1;
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);    // 注意这是CALC
      std::reverse((yyvsp[0].expression_list)->begin(), (yyvsp[0].expression_list)->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 3393 "yacc_sql.cpp"
    break;

  case 152: /* expression_list: expression  */
#line 1216 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 3402 "yacc_sql.cpp"
    break;

  case 153: /* expression_list: expression alias  */
#line 1221 "yacc_sql.y"
    {
      (yyvsp[-1].expression)->set_alias((yyvsp[0].string));
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[-1].expression));
      free((yyvsp[0].string));
    }
#line 3413 "yacc_sql.cpp"
    break;

  case 154: /* expression_list: expression COMMA expression_list  */
#line 1228 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression *>;
      }
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 3426 "yacc_sql.cpp"
    break;

  case 155: /* expression_list: expression alias COMMA expression_list  */
#line 1237 "yacc_sql.y"
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
#line 3441 "yacc_sql.cpp"
    break;

  case 156: /* expression: LBRACE expression RBRACE  */
#line 1250 "yacc_sql.y"
    {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 3450 "yacc_sql.cpp"
    break;

  case 157: /* expression: expression '+' expression  */
#line 1254 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3458 "yacc_sql.cpp"
    break;

  case 158: /* expression: expression '-' expression  */
#line 1257 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3466 "yacc_sql.cpp"
    break;

  case 159: /* expression: expression '*' expression  */
#line 1260 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3474 "yacc_sql.cpp"
    break;

  case 160: /* expression: expression '/' expression  */
#line 1263 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3482 "yacc_sql.cpp"
    break;

  case 161: /* expression: '-' expression  */
#line 1266 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB,
        new ValueExpr(Value(0)), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3491 "yacc_sql.cpp"
    break;

  case 162: /* expression: value  */
#line 1270 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 3501 "yacc_sql.cpp"
    break;

  case 163: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1279 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3515 "yacc_sql.cpp"
    break;

  case 164: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1292 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3524 "yacc_sql.cpp"
    break;

  case 165: /* set_variable_stmt: SET ID EQ value  */
#line 1300 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3536 "yacc_sql.cpp"
    break;


#line 3540 "yacc_sql.cpp"

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

#line 1312 "yacc_sql.y"

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

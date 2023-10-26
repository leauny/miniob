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
  YYSYMBOL_MIX_SUB = 7,                    /* MIX_SUB  */
  YYSYMBOL_AGG = 8,                        /* AGG  */
  YYSYMBOL_DATE = 9,                       /* DATE  */
  YYSYMBOL_SEMICOLON = 10,                 /* SEMICOLON  */
  YYSYMBOL_CREATE = 11,                    /* CREATE  */
  YYSYMBOL_DROP = 12,                      /* DROP  */
  YYSYMBOL_TABLE = 13,                     /* TABLE  */
  YYSYMBOL_TABLES = 14,                    /* TABLES  */
  YYSYMBOL_INDEX = 15,                     /* INDEX  */
  YYSYMBOL_CALC = 16,                      /* CALC  */
  YYSYMBOL_SELECT = 17,                    /* SELECT  */
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
  YYSYMBOL_AND = 41,                       /* AND  */
  YYSYMBOL_OR = 42,                        /* OR  */
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
  YYSYMBOL_67_ = 67,                       /* '+'  */
  YYSYMBOL_68_ = 68,                       /* '-'  */
  YYSYMBOL_69_ = 69,                       /* '*'  */
  YYSYMBOL_70_ = 70,                       /* '/'  */
  YYSYMBOL_UMINUS = 71,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 72,                  /* $accept  */
  YYSYMBOL_commands = 73,                  /* commands  */
  YYSYMBOL_command_wrapper = 74,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 75,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 76,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 77,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 78,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 79,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 80,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 81,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 82,          /* show_tables_stmt  */
  YYSYMBOL_show_index_stmt = 83,           /* show_index_stmt  */
  YYSYMBOL_desc_table_stmt = 84,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 85,         /* create_index_stmt  */
  YYSYMBOL_is_unique = 86,                 /* is_unique  */
  YYSYMBOL_id_list = 87,                   /* id_list  */
  YYSYMBOL_alias = 88,                     /* alias  */
  YYSYMBOL_drop_index_stmt = 89,           /* drop_index_stmt  */
  YYSYMBOL_create_table_stmt = 90,         /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 91,             /* attr_def_list  */
  YYSYMBOL_attr_def = 92,                  /* attr_def  */
  YYSYMBOL_is_nullable = 93,               /* is_nullable  */
  YYSYMBOL_number = 94,                    /* number  */
  YYSYMBOL_type = 95,                      /* type  */
  YYSYMBOL_insert_stmt = 96,               /* insert_stmt  */
  YYSYMBOL_record_list = 97,               /* record_list  */
  YYSYMBOL_record = 98,                    /* record  */
  YYSYMBOL_value_list = 99,                /* value_list  */
  YYSYMBOL_value = 100,                    /* value  */
  YYSYMBOL_delete_stmt = 101,              /* delete_stmt  */
  YYSYMBOL_update_stmt = 102,              /* update_stmt  */
  YYSYMBOL_update_list = 103,              /* update_list  */
  YYSYMBOL_subquery = 104,                 /* subquery  */
  YYSYMBOL_select_stmt = 105,              /* select_stmt  */
  YYSYMBOL_attr_list = 106,                /* attr_list  */
  YYSYMBOL_rel_attr = 107,                 /* rel_attr  */
  YYSYMBOL_rel_list = 108,                 /* rel_list  */
  YYSYMBOL_where = 109,                    /* where  */
  YYSYMBOL_condition_list = 110,           /* condition_list  */
  YYSYMBOL_condition = 111,                /* condition  */
  YYSYMBOL_rel_expr = 112,                 /* rel_expr  */
  YYSYMBOL_comp_op = 113,                  /* comp_op  */
  YYSYMBOL_join_stmt = 114,                /* join_stmt  */
  YYSYMBOL_calc_stmt = 115,                /* calc_stmt  */
  YYSYMBOL_expression_list = 116,          /* expression_list  */
  YYSYMBOL_expression = 117,               /* expression  */
  YYSYMBOL_load_data_stmt = 118,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 119,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 120,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 121             /* opt_semicolon  */
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
#define YYLAST   627

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  162
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  320

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   322


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
       2,     2,    69,    67,     2,    68,     2,    70,     2,     2,
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
      65,    66,    71
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   211,   211,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   243,   249,   254,   260,   266,   272,
     278,   285,   291,   298,   306,   325,   328,   333,   339,   348,
     351,   357,   367,   386,   389,   402,   413,   431,   434,   438,
     442,   445,   446,   447,   448,   451,   459,   464,   476,   490,
     493,   504,   508,   512,   518,   526,   531,   541,   551,   561,
     574,   585,   599,   605,   616,   622,   634,   639,   662,   666,
     670,   676,   680,   686,   694,   702,   711,   719,   731,   736,
     743,   753,   757,   761,   766,   771,   780,   788,   797,   805,
     814,   829,   845,   857,   873,   876,   882,   885,   891,   901,
     913,   917,   924,   931,   938,   945,   952,   962,   967,   975,
     982,   989,   996,  1003,  1010,  1017,  1024,  1031,  1038,  1045,
    1052,  1059,  1066,  1113,  1114,  1115,  1116,  1117,  1118,  1119,
    1120,  1121,  1122,  1125,  1133,  1148,  1155,  1164,  1169,  1176,
    1185,  1198,  1203,  1206,  1209,  1212,  1215,  1219,  1227,  1240,
    1248,  1258,  1259
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
  "ID", "SSS", "MIX_SUB", "AGG", "DATE", "SEMICOLON", "CREATE", "DROP",
  "TABLE", "TABLES", "INDEX", "CALC", "SELECT", "DESC", "SHOW", "SYNC",
  "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN",
  "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T",
  "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE", "AND", "OR",
  "SET", "ON", "AS", "LOAD", "DATA", "INFILE", "EXPLAIN", "LENGTH",
  "ROUND", "DATE_FORMAT", "EQ", "LT", "GT", "LE", "GE", "NE", "LIKE",
  "NOT_LIKE", "INNER_JOIN", "NULL_T", "NOT_NULL", "IS", "IS_NOT", "UNIQUE",
  "'+'", "'-'", "'*'", "'/'", "UMINUS", "$accept", "commands",
  "command_wrapper", "exit_stmt", "help_stmt", "sync_stmt", "begin_stmt",
  "commit_stmt", "rollback_stmt", "drop_table_stmt", "show_tables_stmt",
  "show_index_stmt", "desc_table_stmt", "create_index_stmt", "is_unique",
  "id_list", "alias", "drop_index_stmt", "create_table_stmt",
  "attr_def_list", "attr_def", "is_nullable", "number", "type",
  "insert_stmt", "record_list", "record", "value_list", "value",
  "delete_stmt", "update_stmt", "update_list", "subquery", "select_stmt",
  "attr_list", "rel_attr", "rel_list", "where", "condition_list",
  "condition", "rel_expr", "comp_op", "join_stmt", "calc_stmt",
  "expression_list", "expression", "load_data_stmt", "explain_stmt",
  "set_variable_stmt", "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-227)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-81)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     547,    -6,    30,   398,   337,    19,    14,  -227,    -7,     0,
      42,  -227,  -227,  -227,  -227,  -227,    44,    11,   547,    61,
      72,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,    80,  -227,    76,    88,   110,  -227,  -227,  -227,
    -227,   398,   107,   108,   109,  -227,   398,  -227,  -227,    57,
     102,   115,   389,   116,   122,   124,   389,   123,   111,  -227,
     308,  -227,   407,  -227,  -227,   113,   151,   161,   125,   120,
     121,  -227,  -227,  -227,  -227,   156,   170,  -227,   137,    91,
     450,   450,   450,  -227,  -227,   398,   181,   398,   398,   398,
     398,   174,   182,   162,   312,   129,    28,    28,    28,   450,
    -227,   337,   183,   337,   389,   389,   389,   389,   176,  -227,
     337,   389,   389,   389,   389,    -4,   189,   171,   166,   203,
     450,   205,   211,   173,   229,  -227,   214,    26,   216,  -227,
    -227,     6,     6,  -227,  -227,   398,  -227,   220,   221,   223,
     233,   234,  -227,   239,    43,   241,  -227,   419,    12,   166,
    -227,   321,    29,   321,    29,   450,  -227,   450,  -227,   337,
    -227,   321,    29,   321,    29,   450,  -227,   450,  -227,   337,
    -227,   249,   411,  -227,   212,     1,  -227,   238,   132,   251,
     273,  -227,  -227,  -227,   278,   276,  -227,    15,    15,    15,
    -227,  -227,  -227,  -227,   278,   277,   337,   258,   183,   280,
     -15,   272,  -227,  -227,  -227,   450,   274,  -227,   411,  -227,
     544,   237,   557,   487,   298,  -227,   295,  -227,  -227,  -227,
    -227,    -8,   211,   284,   286,  -227,   297,   301,   303,   304,
     337,  -227,   279,   183,   309,   183,   310,   249,   497,   168,
     460,   411,   411,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,   389,   389,   389,   322,  -227,  -227,   285,
     339,   278,  -227,  -227,  -227,   251,  -227,   342,  -227,  -227,
    -227,  -227,   411,  -227,   183,  -227,   450,   323,  -227,  -227,
    -227,  -227,   201,   187,   201,   187,   201,   187,   337,   324,
     487,  -227,   326,  -227,  -227,    97,   291,  -227,   310,  -227,
    -227,  -227,  -227,    66,  -227,   349,  -227,  -227,  -227,  -227
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    35,     0,     0,     0,     0,     0,    26,     0,     0,
       0,    27,    28,    29,    25,    24,     0,     0,     0,     0,
     161,    23,    22,    15,    16,    17,    18,     9,    10,    11,
      12,    13,    14,     8,     5,     7,     6,     4,     3,    19,
      20,    21,     0,    36,     0,     0,     0,    61,    62,    63,
      64,     0,     0,     0,     0,    65,     0,   157,   145,   147,
      88,     0,     0,     0,     0,     0,     0,    78,     0,   132,
      81,   146,   147,    33,    31,     0,     0,     0,     0,     0,
       0,   159,     1,   162,     2,     0,     0,    30,     0,     0,
       0,     0,     0,   156,    39,     0,     0,     0,     0,     0,
       0,   148,     0,     0,     0,     0,     0,     0,     0,   123,
     156,     0,     0,     0,     0,     0,     0,     0,    82,   118,
       0,     0,     0,     0,     0,   148,     0,     0,   104,     0,
       0,     0,     0,     0,     0,   151,     0,     0,     0,   149,
      40,   152,   153,   154,   155,     0,    89,     0,     0,     0,
       0,     0,   117,     0,     0,     0,    83,    79,    98,   104,
      86,   119,   124,   120,   125,   121,   126,   122,   127,     0,
      84,   128,   152,   129,   153,   130,   154,   131,   155,     0,
      32,     0,   106,    70,     0,   104,   160,     0,     0,    43,
       0,    41,    66,    68,     0,     0,   150,     0,     0,     0,
      90,    91,    92,    94,     0,     0,     0,    80,     0,     0,
      99,    96,    77,    87,    85,     0,    55,    56,     0,   105,
     107,     0,     0,     0,     0,    71,     0,    51,    52,    53,
      54,    47,     0,     0,     0,    50,     0,     0,     0,     0,
       0,   102,     0,     0,    97,     0,    59,     0,     0,     0,
       0,   106,   106,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,     0,     0,     0,     0,    72,    74,     0,
       0,     0,    49,    48,    46,    43,    42,     0,    67,    69,
      93,    95,   106,   103,     0,   100,     0,     0,    57,   110,
     108,   109,   113,   114,   116,   111,   112,   115,     0,     0,
       0,   158,     0,    44,    37,     0,   143,   101,    59,    58,
      76,    73,    75,    47,    34,     0,   144,    60,    45,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -227,  -227,   338,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,   -51,  -227,  -227,    82,
     133,    53,  -194,  -227,  -227,  -227,   138,    47,   -20,  -227,
    -227,  -227,    67,   103,  -105,   -94,  -203,  -141,  -226,   150,
      68,  -113,  -206,  -227,    -1,    -3,  -227,  -227,  -227,  -227
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    44,   305,   101,    32,    33,   233,
     189,   274,   236,   231,    34,   216,   217,   287,    57,    35,
      36,   185,   268,    37,    68,    69,   159,   183,   219,   220,
      70,   263,   211,    38,   139,   157,    39,    40,    41,    84
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,    72,    58,    71,   244,   241,   156,    42,   160,   151,
     238,   243,   153,   154,   155,   170,   271,    94,   212,   118,
      60,   125,   179,    61,    73,   290,   291,   224,    74,    75,
      76,    47,    48,    60,    49,   -80,    61,    50,   208,    77,
     283,   182,   285,    45,   225,    46,   209,    78,    89,    79,
     119,   193,   194,    93,   272,   273,   306,    96,    80,   105,
      43,    82,    94,   110,   213,   147,   148,   149,   203,   204,
     136,   137,   138,   209,   214,    99,   100,   302,    63,    64,
      65,   307,    83,    95,   119,    85,   136,   137,   138,   119,
      55,    86,    59,    87,   141,   142,   143,   144,   123,   124,
     316,   170,    96,   153,   154,   155,   207,   210,   264,   265,
     186,   162,   164,   166,   168,    88,   135,    72,   172,   174,
     176,   178,   314,   315,    97,    98,    99,   100,   272,   273,
     104,    90,    91,    92,   109,   214,   264,   265,   102,   103,
     106,   119,    59,   119,   196,   119,   107,   119,   108,   111,
     112,   119,   126,   119,   135,   119,   127,   119,    97,    98,
      99,   100,   227,   228,   229,   230,   128,    60,   129,   131,
      61,    47,    48,   130,    49,   133,    72,    50,   196,   222,
     132,   134,   161,   163,   165,   167,   140,   146,   158,   171,
     173,   175,   177,   152,   180,   246,   121,   122,   123,   124,
     145,   119,   169,   267,    47,    48,   182,    49,   184,   181,
      50,   187,   147,   148,   149,   250,   188,   190,    52,    53,
      54,   253,   254,   255,   256,   257,   258,   259,   260,   119,
      55,   150,   261,   262,   191,   114,   115,   116,   117,   192,
      47,    48,   195,    49,   197,   198,    50,   199,   222,   222,
     221,    52,    53,    54,   121,   122,   123,   124,   200,   201,
     293,   295,   297,    55,   202,   223,   308,   205,   114,   115,
     116,   117,   119,   215,   119,   226,   119,   232,   234,   222,
     311,   235,   237,   239,   240,   242,   249,    52,    53,    54,
     253,   254,   255,   256,   257,   258,   259,   260,   245,    55,
     247,   261,   262,   269,   114,   115,   116,   117,   270,   276,
     277,    47,    48,    94,    49,    47,    48,    50,    49,   221,
     221,    50,   278,   282,    47,    48,   279,    49,   280,   281,
      50,   292,   294,   296,   113,   284,   286,   152,   300,   298,
      47,    48,    60,    49,   301,    61,    50,   304,   309,   310,
     221,   313,   209,    96,   319,   317,    81,   303,    52,    53,
      54,    62,    52,    53,    54,   275,   318,   312,   248,   299,
      55,    52,    53,    54,    55,   114,   115,   116,   117,   114,
     115,   116,   117,    55,     0,   288,     0,    63,    64,    65,
     116,   117,    47,    48,    60,    49,     0,    61,    50,    55,
       0,    47,    48,     0,    49,    66,    67,    50,     0,     0,
       0,     0,    94,    62,    47,    48,    60,    49,     0,    61,
      50,     0,    51,     0,    94,     0,     0,     0,     0,     0,
       0,     0,     0,   120,     0,   218,     0,     0,     0,    63,
      64,    65,     0,     0,     0,   206,   -79,     0,    52,    53,
      54,    55,    96,    47,    48,     0,    49,    66,     0,    50,
      55,    63,    64,    65,    96,     0,    56,     0,     0,     0,
       0,     0,     0,    55,   121,   122,   123,   124,     0,    66,
       0,     0,     0,     0,     0,   135,   121,   122,   123,   124,
      47,    48,     0,    49,     0,     0,    50,     0,     0,     0,
      52,    53,    54,     0,     0,     0,     0,     0,     0,     0,
       0,   266,    55,   253,   254,   255,   256,   257,   258,   259,
     260,     0,   289,     0,   261,   262,     0,   121,   122,   123,
     124,     0,     0,     0,     0,     0,     0,    52,    53,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
     253,   254,   255,   256,   257,   258,   259,   260,     1,     2,
       0,   261,   262,     3,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    11,    12,    13,     0,     0,     0,
       0,    14,    15,     0,     0,   251,   252,     0,     0,     0,
      16,     0,     0,    17,     0,     0,    18,   253,   254,   255,
     256,   257,   258,   259,   260,     0,     0,     0,   261,   262,
     253,   254,   255,   256,   257,   258,   259,   260,     0,     0,
       0,   261,   262,     0,   121,   122,   123,   124
};

static const yytype_int16 yycheck[] =
{
       3,     4,     3,     4,   210,   208,   111,    13,   113,   103,
     204,    26,   106,   107,   108,   120,    24,     5,   159,    70,
       5,    72,    26,     8,     5,   251,   252,    26,    14,    15,
      37,     3,     4,     5,     6,    39,     8,     9,    26,    39,
     243,    40,   245,    13,   185,    15,    61,     5,    51,     5,
      70,    25,    26,    56,    62,    63,   282,    45,    47,    62,
      66,     0,     5,    66,   169,    50,    51,    52,    25,    26,
      90,    91,    92,    61,   179,    69,    70,   271,    50,    51,
      52,   284,    10,    26,   104,     5,   106,   107,   108,   109,
      62,    15,    95,     5,    97,    98,    99,   100,    69,    70,
     306,   206,    45,   197,   198,   199,   157,   158,   221,   222,
     130,   114,   115,   116,   117,     5,    25,   120,   121,   122,
     123,   124,    25,    26,    67,    68,    69,    70,    62,    63,
      62,    24,    24,    24,    66,   240,   249,   250,    36,    24,
      24,   161,   145,   163,   145,   165,    24,   167,    24,    26,
      39,   171,    39,   173,    25,   175,     5,   177,    67,    68,
      69,    70,    30,    31,    32,    33,     5,     5,    43,    48,
       8,     3,     4,    53,     6,     5,   179,     9,   179,   182,
      24,    44,   114,   115,   116,   117,     5,     5,     5,   121,
     122,   123,   124,    25,     5,   215,    67,    68,    69,    70,
      26,   221,    26,   223,     3,     4,    40,     6,     5,    38,
       9,     6,    50,    51,    52,   218,     5,    44,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,   249,
      62,    69,    64,    65,     5,    67,    68,    69,    70,    25,
       3,     4,    26,     6,    24,    24,     9,    24,   251,   252,
     182,    50,    51,    52,    67,    68,    69,    70,    25,    25,
     263,   264,   265,    62,    25,    53,   286,    26,    67,    68,
      69,    70,   292,    24,   294,    37,   296,    26,     5,   282,
     300,     3,     6,     6,    26,     5,   218,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    26,    62,
      26,    64,    65,     5,    67,    68,    69,    70,    13,    25,
      24,     3,     4,     5,     6,     3,     4,     9,     6,   251,
     252,     9,    25,    44,     3,     4,    25,     6,    25,    25,
       9,   263,   264,   265,    26,    26,    26,    25,    53,    17,
       3,     4,     5,     6,     5,     8,     9,     5,    25,    25,
     282,    25,    61,    45,     5,   308,    18,   275,    50,    51,
      52,    24,    50,    51,    52,   232,   313,   300,   218,   266,
      62,    50,    51,    52,    62,    67,    68,    69,    70,    67,
      68,    69,    70,    62,    -1,   247,    -1,    50,    51,    52,
      69,    70,     3,     4,     5,     6,    -1,     8,     9,    62,
      -1,     3,     4,    -1,     6,    68,    69,     9,    -1,    -1,
      -1,    -1,     5,    24,     3,     4,     5,     6,    -1,     8,
       9,    -1,    24,    -1,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    24,    -1,    -1,    -1,    50,
      51,    52,    -1,    -1,    -1,    26,    39,    -1,    50,    51,
      52,    62,    45,     3,     4,    -1,     6,    68,    -1,     9,
      62,    50,    51,    52,    45,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    67,    68,    69,    70,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    25,    67,    68,    69,    70,
       3,     4,    -1,     6,    -1,    -1,     9,    -1,    -1,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    62,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    25,    -1,    64,    65,    -1,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      53,    54,    55,    56,    57,    58,    59,    60,    11,    12,
      -1,    64,    65,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    41,    42,    -1,    -1,    -1,
      43,    -1,    -1,    46,    -1,    -1,    49,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    -1,    -1,    64,    65,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    64,    65,    -1,    67,    68,    69,    70
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    12,    16,    17,    18,    19,    20,    21,    22,
      23,    27,    28,    29,    34,    35,    43,    46,    49,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    89,    90,    96,   101,   102,   105,   115,   118,
     119,   120,    13,    66,    86,    13,    15,     3,     4,     6,
       9,    24,    50,    51,    52,    62,    68,   100,   116,   117,
       5,     8,    24,    50,    51,    52,    68,    69,   106,   107,
     112,   116,   117,     5,    14,    15,    37,    39,     5,     5,
      47,    74,     0,    10,   121,     5,    15,     5,     5,   117,
      24,    24,    24,   117,     5,    26,    45,    67,    68,    69,
      70,    88,    36,    24,   112,   117,    24,    24,    24,   112,
     117,    26,    39,    26,    67,    68,    69,    70,    88,   100,
      26,    67,    68,    69,    70,    88,    39,     5,     5,    43,
      53,    48,    24,     5,    44,    25,   100,   100,   100,   116,
       5,   117,   117,   117,   117,    26,     5,    50,    51,    52,
      69,   107,    25,   107,   107,   107,   106,   117,     5,   108,
     106,   112,   117,   112,   117,   112,   117,   112,   117,    26,
     106,   112,   117,   112,   117,   112,   117,   112,   117,    26,
       5,    38,    40,   109,     5,   103,   100,     6,     5,    92,
      44,     5,    25,    25,    26,    26,   116,    24,    24,    24,
      25,    25,    25,    25,    26,    26,    26,    88,    26,    61,
      88,   114,   109,   106,   106,    24,    97,    98,    24,   110,
     111,   112,   117,    53,    26,   109,    37,    30,    31,    32,
      33,    95,    26,    91,     5,     3,    94,     6,    94,     6,
      26,   108,     5,    26,   114,    26,   100,    26,   111,   112,
     117,    41,    42,    53,    54,    55,    56,    57,    58,    59,
      60,    64,    65,   113,   113,   113,    24,   100,   104,     5,
      13,    24,    62,    63,    93,    92,    25,    24,    25,    25,
      25,    25,    44,   108,    26,   108,    26,    99,    98,    25,
     110,   110,   112,   117,   112,   117,   112,   117,    17,   105,
      53,     5,    94,    91,     5,    87,   110,   108,   100,    25,
      25,   100,   104,    25,    25,    26,   114,    99,    93,     5
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    72,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    86,    87,    87,    88,
      88,    89,    90,    91,    91,    92,    92,    93,    93,    93,
      94,    95,    95,    95,    95,    96,    97,    97,    98,    99,
      99,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     101,   102,   103,   103,   103,   103,   104,   105,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   107,   107,
     107,   107,   107,   107,   107,   107,   108,   108,   108,   108,
     108,   108,   108,   108,   109,   109,   110,   110,   110,   110,
     111,   111,   111,   111,   111,   111,   111,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   114,   114,   115,   115,   116,   116,   116,
     116,   117,   117,   117,   117,   117,   117,   117,   118,   119,
     120,   121,   121
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
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     5,     2,     2,     1,     2,     3,
       4,     3,     3,     3,     3,     3,     2,     1,     7,     2,
       4,     0,     1
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
#line 212 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1917 "yacc_sql.cpp"
    break;

  case 24: /* exit_stmt: EXIT  */
#line 243 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1926 "yacc_sql.cpp"
    break;

  case 25: /* help_stmt: HELP  */
#line 249 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1934 "yacc_sql.cpp"
    break;

  case 26: /* sync_stmt: SYNC  */
#line 254 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1942 "yacc_sql.cpp"
    break;

  case 27: /* begin_stmt: TRX_BEGIN  */
#line 260 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1950 "yacc_sql.cpp"
    break;

  case 28: /* commit_stmt: TRX_COMMIT  */
#line 266 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 1958 "yacc_sql.cpp"
    break;

  case 29: /* rollback_stmt: TRX_ROLLBACK  */
#line 272 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 1966 "yacc_sql.cpp"
    break;

  case 30: /* drop_table_stmt: DROP TABLE ID  */
#line 278 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1976 "yacc_sql.cpp"
    break;

  case 31: /* show_tables_stmt: SHOW TABLES  */
#line 285 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 1984 "yacc_sql.cpp"
    break;

  case 32: /* show_index_stmt: SHOW INDEX FROM ID  */
#line 291 "yacc_sql.y"
                       {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_INDEX);
      (yyval.sql_node)->show_index.relation_name = (yyvsp[0].string);
    }
#line 1993 "yacc_sql.cpp"
    break;

  case 33: /* desc_table_stmt: DESC ID  */
#line 298 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2003 "yacc_sql.cpp"
    break;

  case 34: /* create_index_stmt: CREATE is_unique INDEX ID ON ID LBRACE id_list RBRACE  */
#line 307 "yacc_sql.y"
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
#line 2023 "yacc_sql.cpp"
    break;

  case 35: /* is_unique: %empty  */
#line 325 "yacc_sql.y"
    {
      (yyval.bools) = false;
    }
#line 2031 "yacc_sql.cpp"
    break;

  case 36: /* is_unique: UNIQUE  */
#line 328 "yacc_sql.y"
             {
      (yyval.bools) = true;
    }
#line 2039 "yacc_sql.cpp"
    break;

  case 37: /* id_list: ID  */
#line 334 "yacc_sql.y"
    {
      (yyval.field_list) = new std::vector<std::string>;
      (yyval.field_list)->push_back((yyvsp[0].string));
      free((yyvsp[0].string));
    }
#line 2049 "yacc_sql.cpp"
    break;

  case 38: /* id_list: id_list COMMA ID  */
#line 340 "yacc_sql.y"
    {
      (yyval.field_list) = (yyvsp[-2].field_list);
      (yyval.field_list)->push_back((yyvsp[0].string));
      free((yyvsp[0].string));
    }
#line 2059 "yacc_sql.cpp"
    break;

  case 39: /* alias: ID  */
#line 348 "yacc_sql.y"
     {
    (yyval.string) = common::substr((yyvsp[0].string),0,strlen((yyvsp[0].string)));
  }
#line 2067 "yacc_sql.cpp"
    break;

  case 40: /* alias: AS ID  */
#line 351 "yacc_sql.y"
          {
    (yyval.string) = common::substr((yyvsp[0].string),0,strlen((yyvsp[0].string)));
  }
#line 2075 "yacc_sql.cpp"
    break;

  case 41: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 358 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2087 "yacc_sql.cpp"
    break;

  case 42: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE  */
#line 368 "yacc_sql.y"
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
#line 2107 "yacc_sql.cpp"
    break;

  case 43: /* attr_def_list: %empty  */
#line 386 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 2115 "yacc_sql.cpp"
    break;

  case 44: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 390 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2129 "yacc_sql.cpp"
    break;

  case 45: /* attr_def: ID type LBRACE number RBRACE is_nullable  */
#line 403 "yacc_sql.y"
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
#line 2144 "yacc_sql.cpp"
    break;

  case 46: /* attr_def: ID type is_nullable  */
#line 414 "yacc_sql.y"
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
#line 2163 "yacc_sql.cpp"
    break;

  case 47: /* is_nullable: %empty  */
#line 431 "yacc_sql.y"
     {
       (yyval.bools) = false;
     }
#line 2171 "yacc_sql.cpp"
    break;

  case 48: /* is_nullable: NOT_NULL  */
#line 435 "yacc_sql.y"
     {
       (yyval.bools) = false;
     }
#line 2179 "yacc_sql.cpp"
    break;

  case 49: /* is_nullable: NULL_T  */
#line 438 "yacc_sql.y"
              {
       (yyval.bools) = true;
     }
#line 2187 "yacc_sql.cpp"
    break;

  case 50: /* number: NUMBER  */
#line 442 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2193 "yacc_sql.cpp"
    break;

  case 51: /* type: INT_T  */
#line 445 "yacc_sql.y"
               { (yyval.number)=INTS; }
#line 2199 "yacc_sql.cpp"
    break;

  case 52: /* type: STRING_T  */
#line 446 "yacc_sql.y"
               { (yyval.number)=CHARS; }
#line 2205 "yacc_sql.cpp"
    break;

  case 53: /* type: FLOAT_T  */
#line 447 "yacc_sql.y"
               { (yyval.number)=FLOATS; }
#line 2211 "yacc_sql.cpp"
    break;

  case 54: /* type: DATE_T  */
#line 448 "yacc_sql.y"
               { (yyval.number)=DATES; }
#line 2217 "yacc_sql.cpp"
    break;

  case 55: /* insert_stmt: INSERT INTO ID VALUES record_list  */
#line 452 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_INSERT);
      (yyval.sql_node)->insertion.relation_name = (yyvsp[-2].string);
      (yyval.sql_node)->insertion.values.swap(*(yyvsp[0].record_list));
    }
#line 2227 "yacc_sql.cpp"
    break;

  case 56: /* record_list: record  */
#line 460 "yacc_sql.y"
    {
      (yyval.record_list) = new std::vector<std::vector<Value>>;
      (yyval.record_list)->emplace_back(std::move(*(yyvsp[0].value_list)));
    }
#line 2236 "yacc_sql.cpp"
    break;

  case 57: /* record_list: record_list COMMA record  */
#line 465 "yacc_sql.y"
    {
      // 无需考虑插入顺序
      if ((yyvsp[-2].record_list) != nullptr) {
        (yyval.record_list) = (yyvsp[-2].record_list);
      } else {
      (yyval.record_list) = new std::vector<std::vector<Value>>;
      }
      (yyval.record_list)->emplace_back(std::move(*(yyvsp[0].value_list)));
    }
#line 2250 "yacc_sql.cpp"
    break;

  case 58: /* record: LBRACE value value_list RBRACE  */
#line 477 "yacc_sql.y"
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
#line 2265 "yacc_sql.cpp"
    break;

  case 59: /* value_list: %empty  */
#line 490 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2273 "yacc_sql.cpp"
    break;

  case 60: /* value_list: COMMA value value_list  */
#line 493 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2287 "yacc_sql.cpp"
    break;

  case 61: /* value: NUMBER  */
#line 504 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2296 "yacc_sql.cpp"
    break;

  case 62: /* value: FLOAT  */
#line 508 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2305 "yacc_sql.cpp"
    break;

  case 63: /* value: SSS  */
#line 512 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
      (yyloc) = (yylsp[0]);
    }
#line 2316 "yacc_sql.cpp"
    break;

  case 64: /* value: DATE  */
#line 518 "yacc_sql.y"
          {
      if (!((yyvsp[0].dates)).ok()) {
        LOG_WARN("date is invalid");
        return -1;
      }
      (yyval.value) = new Value((date)(yyvsp[0].dates));
      (yyloc) = (yylsp[0]);
    }
#line 2329 "yacc_sql.cpp"
    break;

  case 65: /* value: NULL_T  */
#line 526 "yacc_sql.y"
            {
      (yyval.value) = new Value();
      (yyval.value)->set_null();
      (yyloc) = (yylsp[0]);
    }
#line 2339 "yacc_sql.cpp"
    break;

  case 66: /* value: LENGTH LBRACE value RBRACE  */
#line 532 "yacc_sql.y"
    {
        if ((yyvsp[-1].value)->attr_type() != AttrType::CHARS) {
          LOG_ERROR("length function only support string type.");
          return -1;
        }
        (yyval.value) = new Value((int)(yyvsp[-1].value)->get_string().size());  // translate into int
        free((yyvsp[-1].value));
        (yyloc) = (yylsp[-3]);
    }
#line 2353 "yacc_sql.cpp"
    break;

  case 67: /* value: ROUND LBRACE value COMMA number RBRACE  */
#line 542 "yacc_sql.y"
    {
        if ((yyvsp[-3].value)->attr_type() != AttrType::FLOATS) {
          LOG_ERROR("round function only support float type.");
          return -1;
        }
        (yyval.value) = new Value((float)(std::round((yyvsp[-3].value)->get_float() * pow(10, (yyvsp[-1].number))) / pow(10, (yyvsp[-1].number))));
        free((yyvsp[-3].value));
        (yyloc) = (yylsp[-5]);
    }
#line 2367 "yacc_sql.cpp"
    break;

  case 68: /* value: ROUND LBRACE value RBRACE  */
#line 552 "yacc_sql.y"
    {
        if ((yyvsp[-1].value)->attr_type() != AttrType::FLOATS) {
          LOG_ERROR("round function only support float type.");
          return -1;
        }
        (yyval.value) = new Value((std::round((yyvsp[-1].value)->get_float())));
        free((yyvsp[-1].value));
        (yyloc) = (yylsp[-3]);
    }
#line 2381 "yacc_sql.cpp"
    break;

  case 69: /* value: DATE_FORMAT LBRACE value COMMA SSS RBRACE  */
#line 562 "yacc_sql.y"
    {
        if ((yyvsp[-3].value)->attr_type() != AttrType::DATES) {
          LOG_ERROR("data_format function only support date type.");
          return -1;
        }
        (yyval.value) = new Value((date)(yyvsp[-3].value)->get_date(), common::substr((yyvsp[-1].string),1,strlen((yyvsp[-1].string))-2));
        free((yyvsp[-3].value));
        (yyloc) = (yylsp[-5]);
    }
#line 2395 "yacc_sql.cpp"
    break;

  case 70: /* delete_stmt: DELETE FROM ID where  */
#line 575 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].expression_list));
      }
      free((yyvsp[-1].string));
    }
#line 2408 "yacc_sql.cpp"
    break;

  case 71: /* update_stmt: UPDATE ID SET update_list where  */
#line 586 "yacc_sql.y"
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
#line 2424 "yacc_sql.cpp"
    break;

  case 72: /* update_list: ID EQ value  */
#line 599 "yacc_sql.y"
                {
      (yyval.update_list) = new std::vector<std::pair<std::string, Expression*>>;
      (yyval.update_list)->emplace_back(make_pair((yyvsp[-2].string), new ValueExpr(*(yyvsp[0].value))));
      free((yyvsp[-2].string));
      free((yyvsp[0].value));
    }
#line 2435 "yacc_sql.cpp"
    break;

  case 73: /* update_list: update_list COMMA ID EQ value  */
#line 606 "yacc_sql.y"
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
#line 2450 "yacc_sql.cpp"
    break;

  case 74: /* update_list: ID EQ subquery  */
#line 616 "yacc_sql.y"
                     {
      (yyval.update_list) = new std::vector<std::pair<std::string, Expression*>>;
      (yyval.update_list)->emplace_back(make_pair((yyvsp[-2].string), new SubQueryExpr(*(yyvsp[0].sql_node))));
      free((yyvsp[-2].string));
      delete (yyvsp[0].sql_node);
    }
#line 2461 "yacc_sql.cpp"
    break;

  case 75: /* update_list: update_list COMMA ID EQ subquery  */
#line 623 "yacc_sql.y"
    {
      if ((yyvsp[-4].update_list) != nullptr) {
        (yyval.update_list) = (yyvsp[-4].update_list);
      } else {
        (yyval.update_list) = new std::vector<std::pair<std::string, Expression*>>;
      }
      (yyval.update_list)->emplace_back(make_pair((yyvsp[-2].string), new SubQueryExpr(*(yyvsp[0].sql_node))));
      free((yyvsp[-2].string));
    }
#line 2475 "yacc_sql.cpp"
    break;

  case 76: /* subquery: LBRACE select_stmt RBRACE  */
#line 634 "yacc_sql.y"
                              {
      (yyval.sql_node) = (yyvsp[-1].sql_node);
    }
#line 2483 "yacc_sql.cpp"
    break;

  case 77: /* select_stmt: SELECT attr_list FROM rel_list where  */
#line 640 "yacc_sql.y"
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
#line 2508 "yacc_sql.cpp"
    break;

  case 78: /* attr_list: '*'  */
#line 662 "yacc_sql.y"
        {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back(new StarExpr("*"));
    }
#line 2517 "yacc_sql.cpp"
    break;

  case 79: /* attr_list: expression  */
#line 666 "yacc_sql.y"
                 {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2526 "yacc_sql.cpp"
    break;

  case 80: /* attr_list: expression alias  */
#line 670 "yacc_sql.y"
                       {
      (yyvsp[-1].expression)->set_alias((yyvsp[0].string));
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[-1].expression));
      free((yyvsp[0].string));
    }
#line 2537 "yacc_sql.cpp"
    break;

  case 81: /* attr_list: rel_expr  */
#line 676 "yacc_sql.y"
               {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2546 "yacc_sql.cpp"
    break;

  case 82: /* attr_list: rel_expr alias  */
#line 680 "yacc_sql.y"
                     {
      (yyvsp[-1].expression)->set_alias((yyvsp[0].string));
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[-1].expression));
      free((yyvsp[0].string));
    }
#line 2557 "yacc_sql.cpp"
    break;

  case 83: /* attr_list: '*' COMMA attr_list  */
#line 686 "yacc_sql.y"
                          {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      (yyval.expression_list)->emplace_back(new StarExpr("*"));
    }
#line 2570 "yacc_sql.cpp"
    break;

  case 84: /* attr_list: expression COMMA attr_list  */
#line 694 "yacc_sql.y"
                                 {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 2583 "yacc_sql.cpp"
    break;

  case 85: /* attr_list: expression alias COMMA attr_list  */
#line 702 "yacc_sql.y"
                                       {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      (yyvsp[-3].expression)->set_alias((yyvsp[-2].string));
      (yyval.expression_list)->emplace_back((yyvsp[-3].expression));
    }
#line 2597 "yacc_sql.cpp"
    break;

  case 86: /* attr_list: rel_expr COMMA attr_list  */
#line 711 "yacc_sql.y"
                               {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 2610 "yacc_sql.cpp"
    break;

  case 87: /* attr_list: rel_expr alias COMMA attr_list  */
#line 719 "yacc_sql.y"
                                     {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression*>;
      }
      (yyvsp[-3].expression)->set_alias((yyvsp[-2].string));
      (yyval.expression_list)->emplace_back((yyvsp[-3].expression));
    }
#line 2624 "yacc_sql.cpp"
    break;

  case 88: /* rel_attr: ID  */
#line 731 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2634 "yacc_sql.cpp"
    break;

  case 89: /* rel_attr: ID DOT ID  */
#line 736 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2646 "yacc_sql.cpp"
    break;

  case 90: /* rel_attr: AGG LBRACE '*' RBRACE  */
#line 743 "yacc_sql.y"
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
#line 2661 "yacc_sql.cpp"
    break;

  case 91: /* rel_attr: AGG LBRACE rel_attr RBRACE  */
#line 753 "yacc_sql.y"
                                 {
      (yyval.rel_attr) = (yyvsp[-1].rel_attr);
      (yyval.rel_attr)->func_type = (yyvsp[-3].func_t);
    }
#line 2670 "yacc_sql.cpp"
    break;

  case 92: /* rel_attr: LENGTH LBRACE rel_attr RBRACE  */
#line 757 "yacc_sql.y"
                                    {
      (yyval.rel_attr) = (yyvsp[-1].rel_attr);
      (yyval.rel_attr)->func_type = FUNC_LENGTH;
    }
#line 2679 "yacc_sql.cpp"
    break;

  case 93: /* rel_attr: ROUND LBRACE rel_attr COMMA number RBRACE  */
#line 761 "yacc_sql.y"
                                                {
      (yyval.rel_attr) = (yyvsp[-3].rel_attr);
      (yyval.rel_attr)->func_type = FUNC_ROUND;
      (yyval.rel_attr)->func_parm = std::to_string((yyvsp[-1].number));
    }
#line 2689 "yacc_sql.cpp"
    break;

  case 94: /* rel_attr: ROUND LBRACE rel_attr RBRACE  */
#line 766 "yacc_sql.y"
                                   {
      (yyval.rel_attr) = (yyvsp[-1].rel_attr);
      (yyval.rel_attr)->func_type = FUNC_ROUND;
      (yyval.rel_attr)->func_parm = std::to_string(0);
    }
#line 2699 "yacc_sql.cpp"
    break;

  case 95: /* rel_attr: DATE_FORMAT LBRACE rel_attr COMMA SSS RBRACE  */
#line 771 "yacc_sql.y"
                                                   {
      (yyval.rel_attr) = (yyvsp[-3].rel_attr);
      (yyval.rel_attr)->func_type = FUNC_DATE_FORMAT;
      (yyval.rel_attr)->func_parm = common::substr((yyvsp[-1].string),1,strlen((yyvsp[-1].string))-2);
      free((yyvsp[-1].string));
    }
#line 2710 "yacc_sql.cpp"
    break;

  case 96: /* rel_list: ID join_stmt  */
#line 781 "yacc_sql.y"
    {
      (yyval.join_list) = (yyvsp[0].join_list);
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-1].string));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-1].string));
    }
#line 2722 "yacc_sql.cpp"
    break;

  case 97: /* rel_list: ID alias join_stmt  */
#line 789 "yacc_sql.y"
    {
      (yyval.join_list) = (yyvsp[0].join_list);
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-2].string), (yyvsp[-1].string));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-2].string));
      free((yyvsp[-1].string));
    }
#line 2735 "yacc_sql.cpp"
    break;

  case 98: /* rel_list: ID  */
#line 798 "yacc_sql.y"
    {
      (yyval.join_list) = new std::vector<JoinSqlNode>;
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[0].string));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[0].string));
    }
#line 2747 "yacc_sql.cpp"
    break;

  case 99: /* rel_list: ID alias  */
#line 806 "yacc_sql.y"
    {
      (yyval.join_list) = new std::vector<JoinSqlNode>;
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-1].string), (yyvsp[0].string));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-1].string));
      free((yyvsp[0].string));
    }
#line 2760 "yacc_sql.cpp"
    break;

  case 100: /* rel_list: ID join_stmt COMMA rel_list  */
#line 815 "yacc_sql.y"
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
#line 2779 "yacc_sql.cpp"
    break;

  case 101: /* rel_list: ID alias join_stmt COMMA rel_list  */
#line 830 "yacc_sql.y"
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
#line 2799 "yacc_sql.cpp"
    break;

  case 102: /* rel_list: ID COMMA rel_list  */
#line 846 "yacc_sql.y"
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
#line 2815 "yacc_sql.cpp"
    break;

  case 103: /* rel_list: ID alias COMMA rel_list  */
#line 858 "yacc_sql.y"
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
#line 2832 "yacc_sql.cpp"
    break;

  case 104: /* where: %empty  */
#line 873 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 2840 "yacc_sql.cpp"
    break;

  case 105: /* where: WHERE condition_list  */
#line 876 "yacc_sql.y"
                           {
      (yyval.expression_list) = (yyvsp[0].expression_list);
    }
#line 2848 "yacc_sql.cpp"
    break;

  case 106: /* condition_list: %empty  */
#line 882 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 2856 "yacc_sql.cpp"
    break;

  case 107: /* condition_list: condition  */
#line 885 "yacc_sql.y"
                {
      (yyval.expression_list) = new std::vector<Expression*>;
      std::vector<std::unique_ptr<Expression>> children;
      children.emplace_back((yyvsp[0].expression));
      (yyval.expression_list)->emplace_back(new ConjunctionExpr(ConjunctionExpr::Type::AND, children));
    }
#line 2867 "yacc_sql.cpp"
    break;

  case 108: /* condition_list: condition AND condition_list  */
#line 891 "yacc_sql.y"
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
#line 2882 "yacc_sql.cpp"
    break;

  case 109: /* condition_list: condition OR condition_list  */
#line 901 "yacc_sql.y"
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
#line 2897 "yacc_sql.cpp"
    break;

  case 110: /* condition: LBRACE condition RBRACE  */
#line 914 "yacc_sql.y"
    {
      (yyval.expression) = (yyvsp[-1].expression);
    }
#line 2905 "yacc_sql.cpp"
    break;

  case 111: /* condition: rel_expr comp_op expression  */
#line 918 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 2916 "yacc_sql.cpp"
    break;

  case 112: /* condition: expression comp_op rel_expr  */
#line 925 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 2927 "yacc_sql.cpp"
    break;

  case 113: /* condition: condition comp_op rel_expr  */
#line 932 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 2938 "yacc_sql.cpp"
    break;

  case 114: /* condition: condition comp_op expression  */
#line 939 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 2949 "yacc_sql.cpp"
    break;

  case 115: /* condition: expression comp_op expression  */
#line 946 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 2960 "yacc_sql.cpp"
    break;

  case 116: /* condition: rel_expr comp_op rel_expr  */
#line 953 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp),
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
    }
#line 2971 "yacc_sql.cpp"
    break;

  case 117: /* rel_expr: LBRACE rel_expr RBRACE  */
#line 963 "yacc_sql.y"
    {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 2980 "yacc_sql.cpp"
    break;

  case 118: /* rel_expr: rel_expr value  */
#line 967 "yacc_sql.y"
                     {
      if ((yyvsp[0].value)->attr_type() != AttrType::INTS && (yyvsp[0].value)->attr_type() != AttrType::FLOATS) { return -1; }
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::ADD,
        std::unique_ptr<Expression>((yyvsp[-1].expression)),
        std::make_unique<ValueExpr>(*(yyvsp[0].value))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 2993 "yacc_sql.cpp"
    break;

  case 119: /* rel_expr: rel_expr '+' rel_expr  */
#line 975 "yacc_sql.y"
                            {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::ADD,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3005 "yacc_sql.cpp"
    break;

  case 120: /* rel_expr: rel_expr '-' rel_expr  */
#line 982 "yacc_sql.y"
                            {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::SUB,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3017 "yacc_sql.cpp"
    break;

  case 121: /* rel_expr: rel_expr '*' rel_expr  */
#line 989 "yacc_sql.y"
                            {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::MUL,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3029 "yacc_sql.cpp"
    break;

  case 122: /* rel_expr: rel_expr '/' rel_expr  */
#line 996 "yacc_sql.y"
                            {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::DIV,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3041 "yacc_sql.cpp"
    break;

  case 123: /* rel_expr: '-' rel_expr  */
#line 1003 "yacc_sql.y"
                                {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::SUB,
        std::make_unique<ValueExpr>(Value(0)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3053 "yacc_sql.cpp"
    break;

  case 124: /* rel_expr: rel_expr '+' expression  */
#line 1010 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::ADD,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3065 "yacc_sql.cpp"
    break;

  case 125: /* rel_expr: rel_expr '-' expression  */
#line 1017 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::SUB,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3077 "yacc_sql.cpp"
    break;

  case 126: /* rel_expr: rel_expr '*' expression  */
#line 1024 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::MUL,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3089 "yacc_sql.cpp"
    break;

  case 127: /* rel_expr: rel_expr '/' expression  */
#line 1031 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::DIV,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3101 "yacc_sql.cpp"
    break;

  case 128: /* rel_expr: expression '+' rel_expr  */
#line 1038 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::ADD,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3113 "yacc_sql.cpp"
    break;

  case 129: /* rel_expr: expression '-' rel_expr  */
#line 1045 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::SUB,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3125 "yacc_sql.cpp"
    break;

  case 130: /* rel_expr: expression '*' rel_expr  */
#line 1052 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::MUL,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3137 "yacc_sql.cpp"
    break;

  case 131: /* rel_expr: expression '/' rel_expr  */
#line 1059 "yacc_sql.y"
                              {
      (yyval.expression) = new ArithmeticExpr(ArithmeticExpr::Type::DIV,
        std::unique_ptr<Expression>((yyvsp[-2].expression)),
        std::unique_ptr<Expression>((yyvsp[0].expression))
      );
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));  // 设置名称
    }
#line 3149 "yacc_sql.cpp"
    break;

  case 132: /* rel_expr: rel_attr  */
#line 1066 "yacc_sql.y"
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
#line 3198 "yacc_sql.cpp"
    break;

  case 133: /* comp_op: EQ  */
#line 1113 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3204 "yacc_sql.cpp"
    break;

  case 134: /* comp_op: LT  */
#line 1114 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3210 "yacc_sql.cpp"
    break;

  case 135: /* comp_op: GT  */
#line 1115 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3216 "yacc_sql.cpp"
    break;

  case 136: /* comp_op: LE  */
#line 1116 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3222 "yacc_sql.cpp"
    break;

  case 137: /* comp_op: GE  */
#line 1117 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3228 "yacc_sql.cpp"
    break;

  case 138: /* comp_op: NE  */
#line 1118 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3234 "yacc_sql.cpp"
    break;

  case 139: /* comp_op: LIKE  */
#line 1119 "yacc_sql.y"
           { (yyval.comp) = LIKE_TO; }
#line 3240 "yacc_sql.cpp"
    break;

  case 140: /* comp_op: NOT_LIKE  */
#line 1120 "yacc_sql.y"
               { (yyval.comp) = NOT_LIKE_TO; }
#line 3246 "yacc_sql.cpp"
    break;

  case 141: /* comp_op: IS  */
#line 1121 "yacc_sql.y"
         { (yyval.comp) = IS_NULL; }
#line 3252 "yacc_sql.cpp"
    break;

  case 142: /* comp_op: IS_NOT  */
#line 1122 "yacc_sql.y"
             { (yyval.comp) = IS_NOT_NULL; }
#line 3258 "yacc_sql.cpp"
    break;

  case 143: /* join_stmt: INNER_JOIN ID ON condition_list  */
#line 1125 "yacc_sql.y"
                                    {
      (yyval.join_list) = new std::vector<JoinSqlNode>;
      JoinSqlNode join;
      join.relation_name = new TableExpr((yyvsp[-2].string));
      join.conditions.swap(*(yyvsp[0].expression_list));
      (yyval.join_list)->emplace_back(join);
      free((yyvsp[-2].string));
    }
#line 3271 "yacc_sql.cpp"
    break;

  case 144: /* join_stmt: INNER_JOIN ID ON condition_list join_stmt  */
#line 1133 "yacc_sql.y"
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
#line 3288 "yacc_sql.cpp"
    break;

  case 145: /* calc_stmt: CALC expression_list  */
#line 1149 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      std::reverse((yyvsp[0].expression_list)->begin(), (yyvsp[0].expression_list)->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 3299 "yacc_sql.cpp"
    break;

  case 146: /* calc_stmt: SELECT expression_list  */
#line 1155 "yacc_sql.y"
                             {             //  select 1+1;
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);    // 注意这是CALC
      std::reverse((yyvsp[0].expression_list)->begin(), (yyvsp[0].expression_list)->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 3310 "yacc_sql.cpp"
    break;

  case 147: /* expression_list: expression  */
#line 1165 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 3319 "yacc_sql.cpp"
    break;

  case 148: /* expression_list: expression alias  */
#line 1170 "yacc_sql.y"
    {
      (yyvsp[-1].expression)->set_alias((yyvsp[0].string));
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[-1].expression));
      free((yyvsp[0].string));
    }
#line 3330 "yacc_sql.cpp"
    break;

  case 149: /* expression_list: expression COMMA expression_list  */
#line 1177 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression *>;
      }
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 3343 "yacc_sql.cpp"
    break;

  case 150: /* expression_list: expression alias COMMA expression_list  */
#line 1186 "yacc_sql.y"
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
#line 3358 "yacc_sql.cpp"
    break;

  case 151: /* expression: LBRACE expression RBRACE  */
#line 1199 "yacc_sql.y"
    {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 3367 "yacc_sql.cpp"
    break;

  case 152: /* expression: expression '+' expression  */
#line 1203 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3375 "yacc_sql.cpp"
    break;

  case 153: /* expression: expression '-' expression  */
#line 1206 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3383 "yacc_sql.cpp"
    break;

  case 154: /* expression: expression '*' expression  */
#line 1209 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3391 "yacc_sql.cpp"
    break;

  case 155: /* expression: expression '/' expression  */
#line 1212 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3399 "yacc_sql.cpp"
    break;

  case 156: /* expression: '-' expression  */
#line 1215 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB,
        new ValueExpr(Value(0)), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3408 "yacc_sql.cpp"
    break;

  case 157: /* expression: value  */
#line 1219 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 3418 "yacc_sql.cpp"
    break;

  case 158: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1228 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3432 "yacc_sql.cpp"
    break;

  case 159: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1241 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3441 "yacc_sql.cpp"
    break;

  case 160: /* set_variable_stmt: SET ID EQ value  */
#line 1249 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3453 "yacc_sql.cpp"
    break;


#line 3457 "yacc_sql.cpp"

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

#line 1261 "yacc_sql.y"

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

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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "rclang.y"

// #define YYDEBUG 1
#include <stdio.h>

extern char *yytext;
int yylex(void);

void yyerror(const char *str) {
    fprintf(stderr, "error: %s\n", str);
}

int yywrap() {
    return 1;
}


#line 88 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 18 "rclang.y"

#include "ast.h"

#line 127 "y.tab.c"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    STRUCT = 258,                  /* STRUCT  */
    IF = 259,                      /* IF  */
    ELSE = 260,                    /* ELSE  */
    AUTO = 261,                    /* AUTO  */
    TYPEDEF = 262,                 /* TYPEDEF  */
    EXTERN = 263,                  /* EXTERN  */
    STATIC = 264,                  /* STATIC  */
    REGISTER = 265,                /* REGISTER  */
    CONST = 266,                   /* CONST  */
    VOLATILE = 267,                /* VOLATILE  */
    VOID = 268,                    /* VOID  */
    CHAR = 269,                    /* CHAR  */
    SHORT = 270,                   /* SHORT  */
    INT = 271,                     /* INT  */
    LONG = 272,                    /* LONG  */
    FLOAT = 273,                   /* FLOAT  */
    DOUBLE = 274,                  /* DOUBLE  */
    SIGNED = 275,                  /* SIGNED  */
    UNSIGNED = 276,                /* UNSIGNED  */
    GOTO = 277,                    /* GOTO  */
    CONTINUE = 278,                /* CONTINUE  */
    RETURN = 279,                  /* RETURN  */
    BREAK = 280,                   /* BREAK  */
    IDENTIFIER = 281,              /* IDENTIFIER  */
    CONSTANT = 282,                /* CONSTANT  */
    STRING_LITERAL = 283           /* STRING_LITERAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define STRUCT 258
#define IF 259
#define ELSE 260
#define AUTO 261
#define TYPEDEF 262
#define EXTERN 263
#define STATIC 264
#define REGISTER 265
#define CONST 266
#define VOLATILE 267
#define VOID 268
#define CHAR 269
#define SHORT 270
#define INT 271
#define LONG 272
#define FLOAT 273
#define DOUBLE 274
#define SIGNED 275
#define UNSIGNED 276
#define GOTO 277
#define CONTINUE 278
#define RETURN 279
#define BREAK 280
#define IDENTIFIER 281
#define CONSTANT 282
#define STRING_LITERAL 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "rclang.y"

    translation_unit *translation_unit;
    external_declaration external_declaration;
    function_definition function_definition;

    identifier ident;
    expression *expr;
    
    type_qualifier tq;
    type_specifier ts;
    storage_class_specifier scs;

    declaration *declaration;
    declaration_list *declaration_list;
    declaration_specifiers *decl_specifiers;
    pointer *pointer;
    declarator *declarator;
    direct_declarator *direct_declarator;

    initializer *initializer;
    init_declarator_list *init_declarator_list;
    init_declarator init_declarator;

    parameter_type_list parameter_type_list;
    parameter_list *parameter_list;
    parameter_declaration parameter_declaration;

    statement_list *statement_list;
    statement *statement;
    compound_statement *compound_statement;
    jump_statement *jump_statement;

#line 236 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STRUCT = 3,                     /* STRUCT  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_ELSE = 5,                       /* ELSE  */
  YYSYMBOL_AUTO = 6,                       /* AUTO  */
  YYSYMBOL_TYPEDEF = 7,                    /* TYPEDEF  */
  YYSYMBOL_EXTERN = 8,                     /* EXTERN  */
  YYSYMBOL_STATIC = 9,                     /* STATIC  */
  YYSYMBOL_REGISTER = 10,                  /* REGISTER  */
  YYSYMBOL_CONST = 11,                     /* CONST  */
  YYSYMBOL_VOLATILE = 12,                  /* VOLATILE  */
  YYSYMBOL_VOID = 13,                      /* VOID  */
  YYSYMBOL_CHAR = 14,                      /* CHAR  */
  YYSYMBOL_SHORT = 15,                     /* SHORT  */
  YYSYMBOL_INT = 16,                       /* INT  */
  YYSYMBOL_LONG = 17,                      /* LONG  */
  YYSYMBOL_FLOAT = 18,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 19,                    /* DOUBLE  */
  YYSYMBOL_SIGNED = 20,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 21,                  /* UNSIGNED  */
  YYSYMBOL_GOTO = 22,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 23,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 24,                    /* RETURN  */
  YYSYMBOL_BREAK = 25,                     /* BREAK  */
  YYSYMBOL_IDENTIFIER = 26,                /* IDENTIFIER  */
  YYSYMBOL_CONSTANT = 27,                  /* CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 28,            /* STRING_LITERAL  */
  YYSYMBOL_29_ = 29,                       /* ';'  */
  YYSYMBOL_30_ = 30,                       /* ','  */
  YYSYMBOL_31_ = 31,                       /* '='  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '('  */
  YYSYMBOL_34_ = 34,                       /* ')'  */
  YYSYMBOL_35_ = 35,                       /* '{'  */
  YYSYMBOL_36_ = 36,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_translation_unit = 38,          /* translation_unit  */
  YYSYMBOL_external_declaration = 39,      /* external_declaration  */
  YYSYMBOL_declaration = 40,               /* declaration  */
  YYSYMBOL_init_declarator_list = 41,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 42,           /* init_declarator  */
  YYSYMBOL_initializer = 43,               /* initializer  */
  YYSYMBOL_function_definition = 44,       /* function_definition  */
  YYSYMBOL_declaration_specifiers = 45,    /* declaration_specifiers  */
  YYSYMBOL_storage_class_specifier = 46,   /* storage_class_specifier  */
  YYSYMBOL_type_qualifier = 47,            /* type_qualifier  */
  YYSYMBOL_type_qualifier_list = 48,       /* type_qualifier_list  */
  YYSYMBOL_type_specifier = 49,            /* type_specifier  */
  YYSYMBOL_declarator = 50,                /* declarator  */
  YYSYMBOL_pointer = 51,                   /* pointer  */
  YYSYMBOL_direct_declarator = 52,         /* direct_declarator  */
  YYSYMBOL_identifier = 53,                /* identifier  */
  YYSYMBOL_parameter_type_list = 54,       /* parameter_type_list  */
  YYSYMBOL_parameter_list = 55,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 56,     /* parameter_declaration  */
  YYSYMBOL_declaration_list = 57,          /* declaration_list  */
  YYSYMBOL_statement = 58,                 /* statement  */
  YYSYMBOL_statement_list = 59,            /* statement_list  */
  YYSYMBOL_compound_statement = 60,        /* compound_statement  */
  YYSYMBOL_jump_statement = 61,            /* jump_statement  */
  YYSYMBOL_expression = 62,                /* expression  */
  YYSYMBOL_assignment_expression = 63,     /* assignment_expression  */
  YYSYMBOL_primary_expression = 64         /* primary_expression  */
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
typedef yytype_int8 yy_state_t;

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   314

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  108

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


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
      33,    34,    32,     2,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
       2,    31,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   106,   106,   109,   115,   119,   126,   130,   138,   141,
     147,   151,   158,   166,   167,   172,   173,   177,   181,   185,
     189,   194,   198,   205,   208,   211,   214,   217,   223,   226,
     232,   233,   237,   240,   243,   246,   249,   252,   255,   258,
     261,   267,   271,   278,   281,   284,   287,   293,   298,   303,
     309,   318,   325,   331,   334,   340,   344,   351,   354,   362,
     367,   375,   378,   384,   389,   394,   399,   407,   412,   416,
     420,   425,   435,   436,   442,   446,   449,   452,   458
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
  "\"end of file\"", "error", "\"invalid token\"", "STRUCT", "IF", "ELSE",
  "AUTO", "TYPEDEF", "EXTERN", "STATIC", "REGISTER", "CONST", "VOLATILE",
  "VOID", "CHAR", "SHORT", "INT", "LONG", "FLOAT", "DOUBLE", "SIGNED",
  "UNSIGNED", "GOTO", "CONTINUE", "RETURN", "BREAK", "IDENTIFIER",
  "CONSTANT", "STRING_LITERAL", "';'", "','", "'='", "'*'", "'('", "')'",
  "'{'", "'}'", "$accept", "translation_unit", "external_declaration",
  "declaration", "init_declarator_list", "init_declarator", "initializer",
  "function_definition", "declaration_specifiers",
  "storage_class_specifier", "type_qualifier", "type_qualifier_list",
  "type_specifier", "declarator", "pointer", "direct_declarator",
  "identifier", "parameter_type_list", "parameter_list",
  "parameter_declaration", "declaration_list", "statement",
  "statement_list", "compound_statement", "jump_statement", "expression",
  "assignment_expression", "primary_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-59)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     245,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,     3,     8,
      61,   -59,   -59,   -59,    57,   273,   273,   273,   186,   -21,
      -4,   -59,   -59,     3,   -59,    24,   -59,   -59,   -59,    26,
     -59,   156,   -59,   -59,   -59,    94,   -59,    57,   186,   -59,
      -4,   216,   -59,   -59,   -59,   -59,     8,    -9,   186,   -59,
       5,    15,    19,    31,   -59,   125,   -59,   274,   -59,   -59,
      22,   -59,   -59,   -59,     8,    30,    35,   -59,   -59,   -59,
     -59,    -9,   -59,   -59,   -59,   -59,   -59,    55,   -59,   -59,
      33,   -59,   -59,   -59,   278,   -59,   -59,   -59,   -59,   273,
     -24,   -59,   -59,    -9,   -59,   -59,   -59,   -59
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    26,    23,    24,    25,    27,    28,    29,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    51,    43,     0,
       0,     2,     5,     4,     0,    18,    22,    20,     0,     0,
      42,    47,    30,    44,    45,     0,     1,     3,     6,     0,
       8,    10,    17,    21,    19,     0,    57,     0,     0,    16,
      41,     0,    31,    46,    48,     7,     0,     0,     0,    14,
       0,     0,     0,     0,    66,     0,    61,     0,    59,    60,
      10,    58,    15,    50,    56,     0,    52,    53,     9,    77,
      76,     0,    11,    75,    12,    74,    13,     0,    68,    71,
       0,    72,    69,    64,     0,    65,    62,    55,    49,     0,
       0,    67,    70,     0,    63,    54,    78,    73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -59,   -59,    65,     1,   -59,    32,   -59,   -59,     0,   -59,
       4,   -59,   -59,   -17,    10,    62,   -49,   -59,   -59,    -7,
      -3,   -58,    56,   -25,   -59,    14,   -53,   -59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    20,    21,    46,    39,    40,    82,    23,    47,    25,
      26,    33,    27,    28,    29,    30,    31,    75,    76,    77,
      48,    66,    67,    68,    69,    90,    91,    85
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      24,    22,    35,    49,    84,    17,   103,    41,    83,    96,
     106,    87,    19,    83,     6,     7,    59,    17,    79,    80,
      24,    22,    32,    72,    81,    42,    43,    44,    34,    51,
      70,    17,    83,    86,    17,    18,    96,    52,    58,    70,
      18,    19,    65,    53,    88,    17,    79,    80,    89,    71,
     107,    74,    81,    57,    83,    55,    56,    97,    54,    71,
      92,    36,   102,   103,    98,    99,    71,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,   101,    37,    38,    17,    78,    18,
      19,    50,   105,    18,    19,   100,     0,     0,     0,    74,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    60,    61,    62,    63,
       0,    94,     0,     0,     0,     0,     0,     0,     0,    45,
      64,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    60,    61,    62,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      45,    93,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    57,     0,     0,
       0,    45,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    45,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     0,     0,     0,
       0,    17,     0,     0,     0,     0,     0,    18,    19,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     0,    60,    61,    62,    63,
      60,    61,    62,    63,     0,     0,     0,     0,     0,    45,
      95,     0,     0,    45,   104
};

static const yytype_int8 yycheck[] =
{
       0,     0,    19,    28,    57,    26,    30,    24,    57,    67,
      34,    60,    33,    62,    11,    12,    41,    26,    27,    28,
      20,    20,    18,    48,    33,    25,    26,    27,    18,    33,
      47,    26,    81,    58,    26,    32,    94,    33,    41,    56,
      32,    33,    45,    33,    29,    26,    27,    28,    29,    48,
     103,    51,    33,    31,   103,    29,    30,    74,    34,    58,
      29,     0,    29,    30,    34,    30,    65,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    26,    29,    20,    29,    26,    56,    32,
      33,    29,    99,    32,    33,    81,    -1,    -1,    -1,    99,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    35,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    32,    33,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    22,    23,    24,    25,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    35,
      36,    -1,    -1,    35,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    26,    32,    33,
      38,    39,    40,    44,    45,    46,    47,    49,    50,    51,
      52,    53,    47,    48,    51,    50,     0,    39,    29,    41,
      42,    50,    45,    45,    45,    35,    40,    45,    57,    60,
      52,    33,    47,    51,    34,    29,    30,    31,    57,    60,
      22,    23,    24,    25,    36,    57,    58,    59,    60,    61,
      50,    40,    60,    34,    45,    54,    55,    56,    42,    27,
      28,    33,    43,    53,    63,    64,    60,    53,    29,    29,
      62,    63,    29,    36,    59,    36,    58,    50,    34,    30,
      62,    29,    29,    30,    36,    56,    34,    63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    38,    39,    39,    40,    40,    41,    41,
      42,    42,    43,    44,    44,    44,    44,    45,    45,    45,
      45,    45,    45,    46,    46,    46,    46,    46,    47,    47,
      48,    48,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    50,    50,    51,    51,    51,    51,    52,    52,    52,
      52,    53,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    60,    60,    60,    60,    61,    61,    61,
      61,    61,    62,    62,    63,    64,    64,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     3,     1,     3,
       1,     3,     1,     4,     3,     3,     2,     2,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     2,     2,     3,     1,     3,     4,
       3,     1,     1,     1,     3,     2,     1,     1,     2,     1,
       1,     1,     2,     4,     3,     3,     2,     3,     2,     2,
       3,     2,     1,     3,     1,     1,     1,     1,     3
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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
      yychar = yylex ();
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* translation_unit: external_declaration  */
#line 106 "rclang.y"
                           {
        (yyval.translation_unit) = new_translation_unit((yyvsp[0].external_declaration), NULL);
    }
#line 1669 "y.tab.c"
    break;

  case 3: /* translation_unit: translation_unit external_declaration  */
#line 109 "rclang.y"
                                            {
        (yyval.translation_unit) = new_translation_unit((yyvsp[0].external_declaration), (yyvsp[-1].translation_unit));
    }
#line 1677 "y.tab.c"
    break;

  case 4: /* external_declaration: function_definition  */
#line 115 "rclang.y"
                          {
        (yyval.external_declaration).op = ED_FUNCTION_DEFINITION;
        (yyval.external_declaration).decl.func = (yyvsp[0].function_definition);
    }
#line 1686 "y.tab.c"
    break;

  case 5: /* external_declaration: declaration  */
#line 119 "rclang.y"
                  {
        (yyval.external_declaration).op = ED_DECLARATION;
        (yyval.external_declaration).decl.decl = (yyvsp[0].declaration);
    }
#line 1695 "y.tab.c"
    break;

  case 6: /* declaration: declaration_specifiers ';'  */
#line 126 "rclang.y"
                                 {
        (yyval.declaration) = malloc(sizeof(declaration));
        (yyval.declaration)->specifiers = (yyvsp[-1].decl_specifiers);
    }
#line 1704 "y.tab.c"
    break;

  case 7: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 130 "rclang.y"
                                                      {
        (yyval.declaration) = malloc(sizeof(declaration));
        (yyval.declaration)->specifiers = (yyvsp[-2].decl_specifiers);
        (yyval.declaration)->init_decls = (yyvsp[-1].init_declarator_list);
    }
#line 1714 "y.tab.c"
    break;

  case 8: /* init_declarator_list: init_declarator  */
#line 138 "rclang.y"
                      {
        (yyval.init_declarator_list) = new_init_declarator_list((yyvsp[0].init_declarator), NULL);
    }
#line 1722 "y.tab.c"
    break;

  case 9: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 141 "rclang.y"
                                               {
        (yyval.init_declarator_list) = new_init_declarator_list((yyvsp[0].init_declarator), (yyvsp[-2].init_declarator_list));
    }
#line 1730 "y.tab.c"
    break;

  case 10: /* init_declarator: declarator  */
#line 147 "rclang.y"
                 {
        (yyval.init_declarator).decl = (yyvsp[0].declarator);
        (yyval.init_declarator).init = NULL;
    }
#line 1739 "y.tab.c"
    break;

  case 11: /* init_declarator: declarator '=' initializer  */
#line 151 "rclang.y"
                                 {
        (yyval.init_declarator).decl = (yyvsp[-2].declarator);
        (yyval.init_declarator).init = (yyvsp[0].initializer);
    }
#line 1748 "y.tab.c"
    break;

  case 12: /* initializer: assignment_expression  */
#line 158 "rclang.y"
                            {
        printf("assignment\n");
        (yyval.initializer) = malloc(sizeof(initializer));
        (yyval.initializer)->expr = (yyvsp[0].expr);
    }
#line 1758 "y.tab.c"
    break;

  case 14: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 167 "rclang.y"
                                                           {
        (yyval.function_definition).specifiers = (yyvsp[-2].decl_specifiers);
        (yyval.function_definition).declarator = (yyvsp[-1].declarator);
        (yyval.function_definition).statement = (yyvsp[0].compound_statement);
    }
#line 1768 "y.tab.c"
    break;

  case 17: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 177 "rclang.y"
                                                     {
        declaration_specifier spec = {.tag = DS_STORAGE_CLASS_SPECIFIER, .specifier = {.sc = (yyvsp[-1].scs)}};
        (yyval.decl_specifiers) = new_declaration_specifiers(spec, (yyvsp[0].decl_specifiers));
    }
#line 1777 "y.tab.c"
    break;

  case 18: /* declaration_specifiers: storage_class_specifier  */
#line 181 "rclang.y"
                              {
        declaration_specifier spec = {.tag = DS_STORAGE_CLASS_SPECIFIER, .specifier = {.sc = (yyvsp[0].scs)}};
        (yyval.decl_specifiers) = new_declaration_specifiers(spec, NULL);
    }
#line 1786 "y.tab.c"
    break;

  case 19: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 185 "rclang.y"
                                            {
        declaration_specifier spec = {.tag = DS_TYPE_SPECIFIER, .specifier = {.s = (yyvsp[-1].ts)}};
        (yyval.decl_specifiers) = new_declaration_specifiers(spec, (yyvsp[0].decl_specifiers));
    }
#line 1795 "y.tab.c"
    break;

  case 20: /* declaration_specifiers: type_specifier  */
#line 189 "rclang.y"
                     {
        printf("found type %d\n", (yyvsp[0].ts).tag);
        declaration_specifier spec = {.tag = DS_TYPE_SPECIFIER, .specifier = {.s = (yyvsp[0].ts)}};
        (yyval.decl_specifiers) = new_declaration_specifiers(spec, NULL);
    }
#line 1805 "y.tab.c"
    break;

  case 21: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 194 "rclang.y"
                                            {
        declaration_specifier spec = {.tag = DS_TYPE_QUALIFIER, .specifier = {.q = (yyvsp[-1].tq)}};
        (yyval.decl_specifiers) = new_declaration_specifiers(spec, (yyvsp[0].decl_specifiers));
    }
#line 1814 "y.tab.c"
    break;

  case 22: /* declaration_specifiers: type_qualifier  */
#line 198 "rclang.y"
                     {
        declaration_specifier spec = {.tag = DS_TYPE_QUALIFIER, .specifier = {.q = (yyvsp[0].tq)}};
        (yyval.decl_specifiers) = new_declaration_specifiers(spec, NULL);
    }
#line 1823 "y.tab.c"
    break;

  case 23: /* storage_class_specifier: TYPEDEF  */
#line 205 "rclang.y"
              {
        (yyval.scs) = SCS_TYPEDEF;
    }
#line 1831 "y.tab.c"
    break;

  case 24: /* storage_class_specifier: EXTERN  */
#line 208 "rclang.y"
             {
        (yyval.scs) = SCS_EXTERN;
    }
#line 1839 "y.tab.c"
    break;

  case 25: /* storage_class_specifier: STATIC  */
#line 211 "rclang.y"
             {
        (yyval.scs) = SCS_STATIC;
    }
#line 1847 "y.tab.c"
    break;

  case 26: /* storage_class_specifier: AUTO  */
#line 214 "rclang.y"
           {
        (yyval.scs) = SCS_AUTO;
    }
#line 1855 "y.tab.c"
    break;

  case 27: /* storage_class_specifier: REGISTER  */
#line 217 "rclang.y"
               {
        (yyval.scs) = SCS_REGISTER;
    }
#line 1863 "y.tab.c"
    break;

  case 28: /* type_qualifier: CONST  */
#line 223 "rclang.y"
            {
        (yyval.tq) = TQ_CONST;
    }
#line 1871 "y.tab.c"
    break;

  case 29: /* type_qualifier: VOLATILE  */
#line 226 "rclang.y"
               {
        (yyval.tq) = TQ_VOLATILE;
    }
#line 1879 "y.tab.c"
    break;

  case 32: /* type_specifier: VOID  */
#line 237 "rclang.y"
           {
        (yyval.ts).tag = TS_VOID;
    }
#line 1887 "y.tab.c"
    break;

  case 33: /* type_specifier: CHAR  */
#line 240 "rclang.y"
           {
        (yyval.ts).tag = TS_CHAR;
    }
#line 1895 "y.tab.c"
    break;

  case 34: /* type_specifier: SHORT  */
#line 243 "rclang.y"
            {
        (yyval.ts).tag = TS_SHORT;
    }
#line 1903 "y.tab.c"
    break;

  case 35: /* type_specifier: INT  */
#line 246 "rclang.y"
          {
        (yyval.ts).tag = TS_INT;
    }
#line 1911 "y.tab.c"
    break;

  case 36: /* type_specifier: LONG  */
#line 249 "rclang.y"
           {
        (yyval.ts).tag = TS_LONG;
    }
#line 1919 "y.tab.c"
    break;

  case 37: /* type_specifier: FLOAT  */
#line 252 "rclang.y"
            {
        (yyval.ts).tag = TS_FLOAT;
    }
#line 1927 "y.tab.c"
    break;

  case 38: /* type_specifier: DOUBLE  */
#line 255 "rclang.y"
             { 
        (yyval.ts).tag = TS_DOUBLE; 
    }
#line 1935 "y.tab.c"
    break;

  case 39: /* type_specifier: SIGNED  */
#line 258 "rclang.y"
             {
        (yyval.ts).tag = TS_SIGNED;
    }
#line 1943 "y.tab.c"
    break;

  case 40: /* type_specifier: UNSIGNED  */
#line 261 "rclang.y"
               {
        (yyval.ts).tag = TS_UNSIGNED;
    }
#line 1951 "y.tab.c"
    break;

  case 41: /* declarator: pointer direct_declarator  */
#line 267 "rclang.y"
                                {
        (yyval.declarator)->pointer = (yyvsp[-1].pointer);
        (yyval.declarator)->direct_decl = (yyvsp[0].direct_declarator);
    }
#line 1960 "y.tab.c"
    break;

  case 42: /* declarator: direct_declarator  */
#line 271 "rclang.y"
                        {
        (yyval.declarator)->pointer = NULL;
        (yyval.declarator)->direct_decl = (yyvsp[0].direct_declarator);
    }
#line 1969 "y.tab.c"
    break;

  case 43: /* pointer: '*'  */
#line 278 "rclang.y"
          {
        (yyval.pointer) = new_pointer(NULL);
    }
#line 1977 "y.tab.c"
    break;

  case 44: /* pointer: '*' type_qualifier_list  */
#line 281 "rclang.y"
                               {
        (yyval.pointer) = new_pointer(NULL);
    }
#line 1985 "y.tab.c"
    break;

  case 45: /* pointer: '*' pointer  */
#line 284 "rclang.y"
                  {
        (yyval.pointer) = new_pointer((yyvsp[0].pointer));
    }
#line 1993 "y.tab.c"
    break;

  case 46: /* pointer: '*' type_qualifier_list pointer  */
#line 287 "rclang.y"
                                      {
        (yyval.pointer) = new_pointer((yyvsp[0].pointer));
    }
#line 2001 "y.tab.c"
    break;

  case 47: /* direct_declarator: identifier  */
#line 293 "rclang.y"
                 {
        (yyval.direct_declarator) = malloc(sizeof(direct_declarator));
        (yyval.direct_declarator)->tag = DDECL_IDENTIFIER;
        (yyval.direct_declarator)->op.identifier_decl = (yyvsp[0].ident);
    }
#line 2011 "y.tab.c"
    break;

  case 48: /* direct_declarator: '(' declarator ')'  */
#line 298 "rclang.y"
                         {
        (yyval.direct_declarator) = malloc(sizeof(direct_declarator));
        (yyval.direct_declarator)->tag = DDECL_DECLARATOR;
        (yyval.direct_declarator)->op.decl = (yyvsp[-1].declarator);
    }
#line 2021 "y.tab.c"
    break;

  case 49: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 303 "rclang.y"
                                                    {
        (yyval.direct_declarator) = malloc(sizeof(direct_declarator));
        (yyval.direct_declarator)->tag = DDECL_FUNCTION;
        (yyval.direct_declarator)->op.function_decl.function = (yyvsp[-3].direct_declarator);
        (yyval.direct_declarator)->op.function_decl.param_types = (yyvsp[-1].parameter_type_list);
    }
#line 2032 "y.tab.c"
    break;

  case 50: /* direct_declarator: direct_declarator '(' ')'  */
#line 309 "rclang.y"
                                {
        (yyval.direct_declarator) = malloc(sizeof(direct_declarator));
        (yyval.direct_declarator)->tag = DDECL_FUNCTION;
        (yyval.direct_declarator)->op.function_decl.function = (yyvsp[-2].direct_declarator);

    }
#line 2043 "y.tab.c"
    break;

  case 51: /* identifier: IDENTIFIER  */
#line 318 "rclang.y"
                 {
        printf("found identifier: %s\n", yytext);
        (yyval.ident) = new_identifier(yytext);
    }
#line 2052 "y.tab.c"
    break;

  case 52: /* parameter_type_list: parameter_list  */
#line 325 "rclang.y"
                     {
        (yyval.parameter_type_list).params = (yyvsp[0].parameter_list);
    }
#line 2060 "y.tab.c"
    break;

  case 53: /* parameter_list: parameter_declaration  */
#line 331 "rclang.y"
                            {
        (yyval.parameter_list) = new_parameter_list((yyvsp[0].parameter_declaration), NULL);
    }
#line 2068 "y.tab.c"
    break;

  case 54: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 334 "rclang.y"
                                               {
        (yyval.parameter_list) = new_parameter_list((yyvsp[0].parameter_declaration), (yyvsp[-2].parameter_list));
    }
#line 2076 "y.tab.c"
    break;

  case 55: /* parameter_declaration: declaration_specifiers declarator  */
#line 340 "rclang.y"
                                        {
        (yyval.parameter_declaration).specifiers = (yyvsp[-1].decl_specifiers);
        (yyval.parameter_declaration).decl = (yyvsp[0].declarator);
    }
#line 2085 "y.tab.c"
    break;

  case 56: /* parameter_declaration: declaration_specifiers  */
#line 344 "rclang.y"
                             {
        (yyval.parameter_declaration).specifiers = (yyvsp[0].decl_specifiers);
        (yyval.parameter_declaration).decl = NULL;
    }
#line 2094 "y.tab.c"
    break;

  case 57: /* declaration_list: declaration  */
#line 351 "rclang.y"
                  {
        (yyval.declaration_list) = new_declaration_list((yyvsp[0].declaration), NULL);
    }
#line 2102 "y.tab.c"
    break;

  case 58: /* declaration_list: declaration_list declaration  */
#line 354 "rclang.y"
                                   {
        (yyval.declaration_list) = new_declaration_list((yyvsp[0].declaration), (yyvsp[-1].declaration_list));
    }
#line 2110 "y.tab.c"
    break;

  case 59: /* statement: compound_statement  */
#line 362 "rclang.y"
                         {
        (yyval.statement) = malloc(sizeof(statement));
        (yyval.statement)->tag = STMT_COMPOUND;
        (yyval.statement)->stmt.compound = (yyvsp[0].compound_statement);
    }
#line 2120 "y.tab.c"
    break;

  case 60: /* statement: jump_statement  */
#line 367 "rclang.y"
                     {
        (yyval.statement) = malloc(sizeof(statement));
        (yyval.statement)->tag = STMT_JUMP;
        (yyval.statement)->stmt.jump = (yyvsp[0].jump_statement);
    }
#line 2130 "y.tab.c"
    break;

  case 61: /* statement_list: statement  */
#line 375 "rclang.y"
                {
        (yyval.statement_list) = new_statement_list((yyvsp[0].statement), NULL);
    }
#line 2138 "y.tab.c"
    break;

  case 62: /* statement_list: statement_list statement  */
#line 378 "rclang.y"
                               {
        (yyval.statement_list) = new_statement_list((yyvsp[0].statement), (yyvsp[-1].statement_list));
    }
#line 2146 "y.tab.c"
    break;

  case 63: /* compound_statement: '{' declaration_list statement_list '}'  */
#line 384 "rclang.y"
                                              {
        (yyval.compound_statement) = malloc(sizeof(compound_statement));
        (yyval.compound_statement)->declarations = (yyvsp[-2].declaration_list);
        (yyval.compound_statement)->statements = (yyvsp[-1].statement_list);
    }
#line 2156 "y.tab.c"
    break;

  case 64: /* compound_statement: '{' declaration_list '}'  */
#line 389 "rclang.y"
                               {
        (yyval.compound_statement) = malloc(sizeof(compound_statement));
        (yyval.compound_statement)->declarations = (yyvsp[-1].declaration_list);
        (yyval.compound_statement)->statements = NULL;
    }
#line 2166 "y.tab.c"
    break;

  case 65: /* compound_statement: '{' statement_list '}'  */
#line 394 "rclang.y"
                             {
        (yyval.compound_statement) = malloc(sizeof(compound_statement));
        (yyval.compound_statement)->declarations = NULL;
        (yyval.compound_statement)->statements = (yyvsp[-1].statement_list);
    }
#line 2176 "y.tab.c"
    break;

  case 66: /* compound_statement: '{' '}'  */
#line 399 "rclang.y"
              {
        (yyval.compound_statement) = malloc(sizeof(compound_statement));
        (yyval.compound_statement)->declarations = NULL;
        (yyval.compound_statement)->statements = NULL;
    }
#line 2186 "y.tab.c"
    break;

  case 67: /* jump_statement: GOTO identifier ';'  */
#line 407 "rclang.y"
                          {
        (yyval.jump_statement) = malloc(sizeof(jump_statement));
        (yyval.jump_statement)->tag = JUMP_GOTO;
        (yyval.jump_statement)->jump.goto_ident = (yyvsp[-1].ident);
    }
#line 2196 "y.tab.c"
    break;

  case 68: /* jump_statement: CONTINUE ';'  */
#line 412 "rclang.y"
                   {
        (yyval.jump_statement) = malloc(sizeof(jump_statement));
        (yyval.jump_statement)->tag = JUMP_CONTINUE;
    }
#line 2205 "y.tab.c"
    break;

  case 69: /* jump_statement: BREAK ';'  */
#line 416 "rclang.y"
                {
        (yyval.jump_statement) = malloc(sizeof(jump_statement));
        (yyval.jump_statement)->tag = JUMP_BREAK;
    }
#line 2214 "y.tab.c"
    break;

  case 70: /* jump_statement: RETURN expression ';'  */
#line 420 "rclang.y"
                            {
        (yyval.jump_statement) = malloc(sizeof(jump_statement));
        (yyval.jump_statement)->tag = JUMP_RETURN;
        (yyval.jump_statement)->jump.return_expr = (yyvsp[-1].expr);
    }
#line 2224 "y.tab.c"
    break;

  case 71: /* jump_statement: RETURN ';'  */
#line 425 "rclang.y"
                 {
        (yyval.jump_statement) = malloc(sizeof(jump_statement));
        (yyval.jump_statement)->tag = JUMP_RETURN;
        (yyval.jump_statement)->jump.return_expr = NULL;
    }
#line 2234 "y.tab.c"
    break;

  case 73: /* expression: expression ',' assignment_expression  */
#line 436 "rclang.y"
                                           {
        (yyval.expr) = new_multi_expression((yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2242 "y.tab.c"
    break;

  case 75: /* primary_expression: identifier  */
#line 446 "rclang.y"
                 {
        (yyval.expr) = new_identifier_expression((yyvsp[0].ident));
    }
#line 2250 "y.tab.c"
    break;

  case 76: /* primary_expression: STRING_LITERAL  */
#line 449 "rclang.y"
                     {
        (yyval.expr) = new_string_literal_expression(yytext);
    }
#line 2258 "y.tab.c"
    break;

  case 77: /* primary_expression: CONSTANT  */
#line 452 "rclang.y"
               {
        printf("%s\n", yytext);
        (yyval.expr) = malloc(sizeof(expression));
        (yyval.expr)->tag = EXPR_INTEGER;
        (yyval.expr)->op.integer_expr = 10;
    }
#line 2269 "y.tab.c"
    break;

  case 78: /* primary_expression: '(' expression ')'  */
#line 458 "rclang.y"
                         {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 2277 "y.tab.c"
    break;


#line 2281 "y.tab.c"

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
          = {yyssp, yytoken};
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
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
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

#line 463 "rclang.y"


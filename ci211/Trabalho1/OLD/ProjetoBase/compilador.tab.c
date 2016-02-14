/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "compilador.y"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"

int num_vars, niv_lex, dec_var_global, num_params;
int simb_buscado;
int i;
int var_atrib;
char rotulo[10];
int retorno_rot;
int ref;
int func;
int num_params_proc, curr_par, num_ref_vars, curr_proc_func;
int tipo_var;
int is_boolean;
int num_vars2;


/* Line 371 of yacc.c  */
#line 90 "compilador.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "compilador.tab.h".  */
#ifndef YY_YY_COMPILADOR_TAB_H_INCLUDED
# define YY_YY_COMPILADOR_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAM = 258,
     ABRE_PARENTESES = 259,
     FECHA_PARENTESES = 260,
     VIRGULA = 261,
     PONTO_E_VIRGULA = 262,
     DOIS_PONTOS = 263,
     PONTO = 264,
     T_BEGIN = 265,
     T_END = 266,
     VAR = 267,
     IDENT = 268,
     ATRIBUICAO = 269,
     NUMERO = 270,
     MAIS = 271,
     MENOS = 272,
     OR = 273,
     MULT = 274,
     DIV = 275,
     AND = 276,
     IGUAL = 277,
     DIFF = 278,
     MAIOR = 279,
     MENOR = 280,
     MAIOR_IGUAL = 281,
     MENOR_IGUAL = 282,
     DO = 283,
     WHILE = 284,
     IF = 285,
     THEN = 286,
     ELSE = 287,
     PROCEDURE = 288,
     LOWER_THAN_ELSE = 289,
     FUNCTION = 290,
     LABEL = 291,
     GOTO = 292,
     READ = 293,
     WRITE = 294,
     TRUE = 295,
     FALSE = 296,
     BOOLEAN = 297,
     INTEGER = 298
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_COMPILADOR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 199 "compilador.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   145

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  76
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNRULES -- Number of states.  */
#define YYNSTATES  200

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,    14,    19,    20,    21,    26,    27,
      30,    33,    34,    35,    43,    44,    45,    46,    57,    58,
      59,    65,    66,    69,    71,    72,    73,    78,    79,    83,
      84,    89,    93,    95,    99,   100,   104,   106,   108,   109,
     113,   114,   117,   119,   120,   121,   128,   130,   132,   136,
     138,   142,   144,   148,   152,   154,   156,   157,   162,   164,
     166,   168,   170,   172,   173,   179,   184,   188,   190,   192,
     196,   198,   200,   203,   206,   207,   213,   216,   217,   218,
     219,   226,   227,   231,   232,   236,   238,   239,   244,   245,
     249,   251,   254,   255,   256,   260,   261,   265,   266,   270,
     271,   275,   276,   280,   281,   285,   289,   293,   297,   299,
     303,   307,   311,   313,   315,   319,   321,   323,   325,   326,
     330,   334
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    -1,    46,     3,    13,     4,    80,     5,
       7,    47,     9,    -1,    69,    71,    48,    81,    -1,    -1,
      -1,    49,    51,    50,    48,    -1,    -1,    33,    52,    -1,
      35,    55,    -1,    -1,    -1,    13,    53,    59,     7,    47,
      54,     7,    -1,    -1,    -1,    -1,    13,    56,    59,     8,
      78,     7,    57,    47,    58,     7,    -1,    -1,    -1,     4,
      60,    62,    61,     5,    -1,    -1,     7,    63,    -1,    63,
      -1,    -1,    -1,    12,    64,    66,    62,    -1,    -1,    65,
      66,    62,    -1,    -1,    67,    68,     8,    78,    -1,    68,
       6,    13,    -1,    13,    -1,    36,    70,     7,    -1,    -1,
      70,     6,    15,    -1,    15,    -1,    72,    -1,    -1,    73,
      12,    74,    -1,    -1,    74,    75,    -1,    75,    -1,    -1,
      -1,    76,    79,     8,    78,    77,     7,    -1,    42,    -1,
      43,    -1,    79,     6,    13,    -1,    13,    -1,    80,     6,
      13,    -1,    13,    -1,    10,    82,    11,    -1,    83,     7,
      82,    -1,    83,    -1,    85,    -1,    -1,    15,    84,     8,
      85,    -1,    99,    -1,    96,    -1,    92,    -1,    81,    -1,
      91,    -1,    -1,    38,    86,     4,    87,     5,    -1,    39,
       4,    89,     5,    -1,    87,     6,    88,    -1,    88,    -1,
      13,    -1,    89,     6,    90,    -1,    90,    -1,    13,    -1,
      37,    15,    -1,    93,    95,    -1,    -1,    30,   106,    94,
      31,    85,    -1,    32,    85,    -1,    -1,    -1,    -1,    29,
      97,   106,    28,    98,    85,    -1,    -1,    13,   100,   101,
      -1,    -1,    14,   106,   102,    -1,   103,    -1,    -1,     4,
     105,   104,     5,    -1,    -1,   105,     6,   106,    -1,   106,
      -1,   114,   107,    -1,    -1,    -1,    22,   108,   114,    -1,
      -1,    23,   109,   114,    -1,    -1,    24,   110,   114,    -1,
      -1,    25,   111,   114,    -1,    -1,    26,   112,   114,    -1,
      -1,    27,   113,   114,    -1,   114,    16,   115,    -1,   114,
      17,   115,    -1,   114,    18,   115,    -1,   115,    -1,   115,
      19,   116,    -1,   115,    20,   116,    -1,   115,    21,   116,
      -1,   116,    -1,    15,    -1,     4,   106,     5,    -1,   117,
      -1,    40,    -1,    41,    -1,    -1,    13,   118,   119,    -1,
       4,   105,     5,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    31,    31,    31,    52,    61,    63,    61,    70,    74,
      75,    80,    89,    79,   114,   124,   134,   113,   157,   159,
     156,   193,   197,   198,   199,   203,   203,   204,   204,   210,
     210,   218,   225,   238,   239,   244,   249,   261,   265,   265,
     270,   273,   274,   277,   280,   277,   293,   294,   297,   305,
     314,   315,   319,   322,   323,   326,   328,   327,   347,   348,
     349,   350,   351,   352,   352,   353,   357,   358,   361,   386,
     387,   390,   416,   431,   440,   439,   457,   458,   465,   471,
     464,   490,   489,   512,   511,   533,   549,   547,   551,   554,
     555,   558,   561,   563,   563,   569,   569,   575,   575,   581,
     581,   587,   587,   593,   593,   600,   601,   602,   603,   606,
     607,   608,   609,   612,   616,   617,   618,   619,   623,   622,
     661,   675
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "ABRE_PARENTESES",
  "FECHA_PARENTESES", "VIRGULA", "PONTO_E_VIRGULA", "DOIS_PONTOS", "PONTO",
  "T_BEGIN", "T_END", "VAR", "IDENT", "ATRIBUICAO", "NUMERO", "MAIS",
  "MENOS", "OR", "MULT", "DIV", "AND", "IGUAL", "DIFF", "MAIOR", "MENOR",
  "MAIOR_IGUAL", "MENOR_IGUAL", "DO", "WHILE", "IF", "THEN", "ELSE",
  "PROCEDURE", "LOWER_THAN_ELSE", "FUNCTION", "LABEL", "GOTO", "READ",
  "WRITE", "TRUE", "FALSE", "BOOLEAN", "INTEGER", "$accept", "programa",
  "$@1", "bloco", "parte_subrotinas", "$@2", "$@3", "proc_ou_func",
  "procedimento", "$@4", "$@5", "funcao", "$@6", "$@7", "$@8",
  "param_formais0", "$@9", "$@10", "param_formais", "param_formais1",
  "$@11", "$@12", "param_formais2", "$@13", "lista_params",
  "parte_declara_rot", "lista_rots", "parte_declara_vars", "var", "$@14",
  "declara_vars", "declara_var", "$@15", "$@16", "tipo", "lista_id_var",
  "lista_idents", "comando_composto", "comandos", "comando", "$@17",
  "comando_sem_rotulo", "$@18", "lista_param_leit", "ident_leit",
  "lista_param_impr", "ident_impr", "desvio", "comando_condicional",
  "if_then", "$@19", "cond_else", "comando_repetitivo", "$@20", "$@21",
  "atrib_proc", "$@22", "atrib_proc2", "$@23", "chama_proc", "$@24",
  "lista_de_parametros", "expressao", "expressao_simples1", "$@25", "$@26",
  "$@27", "$@28", "$@29", "$@30", "expressao_simples", "termo", "fator",
  "ident_func", "$@31", "func_chamada", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    46,    45,    47,    49,    50,    48,    48,    51,
      51,    53,    54,    52,    56,    57,    58,    55,    60,    61,
      59,    59,    62,    62,    62,    64,    63,    65,    63,    67,
      66,    68,    68,    69,    69,    70,    70,    71,    73,    72,
      72,    74,    74,    76,    77,    75,    78,    78,    79,    79,
      80,    80,    81,    82,    82,    83,    84,    83,    85,    85,
      85,    85,    85,    86,    85,    85,    87,    87,    88,    89,
      89,    90,    91,    92,    94,    93,    95,    95,    97,    98,
      96,   100,    99,   102,   101,   101,   104,   103,   103,   105,
     105,   106,   107,   108,   107,   109,   107,   110,   107,   111,
     107,   112,   107,   113,   107,   114,   114,   114,   114,   115,
     115,   115,   115,   116,   116,   116,   116,   116,   118,   117,
     119,   119
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     9,     4,     0,     0,     4,     0,     2,
       2,     0,     0,     7,     0,     0,     0,    10,     0,     0,
       5,     0,     2,     1,     0,     0,     4,     0,     3,     0,
       4,     3,     1,     3,     0,     3,     1,     1,     0,     3,
       0,     2,     1,     0,     0,     6,     1,     1,     3,     1,
       3,     1,     3,     3,     1,     1,     0,     4,     1,     1,
       1,     1,     1,     0,     5,     4,     3,     1,     1,     3,
       1,     1,     2,     2,     0,     5,     2,     0,     0,     0,
       6,     0,     3,     0,     3,     1,     0,     4,     0,     3,
       1,     2,     0,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     3,     3,     3,     1,     3,
       3,     3,     1,     1,     3,     1,     1,     1,     0,     3,
       3,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,    51,     0,     0,
       0,    34,    50,     0,     0,    40,    36,     0,     3,     5,
      37,     0,     0,    33,     0,     0,    43,    35,     0,     4,
       0,     0,     6,    39,    42,     0,    81,    56,    78,     0,
       0,    63,     0,    61,     0,    54,    55,    62,    60,    77,
      59,    58,    11,     9,    14,    10,     5,    41,    49,     0,
      88,     0,     0,     0,   118,   113,   116,   117,    74,    92,
     108,   112,   115,    72,     0,     0,    52,     0,     0,    73,
      21,    21,     7,     0,     0,     0,     0,    82,    85,     0,
       0,     0,   121,     0,     0,     0,     0,    93,    95,    97,
      99,   101,   103,    91,     0,     0,     0,     0,    71,     0,
      70,    53,    76,    18,     0,     0,    48,    46,    47,    44,
      86,    90,    83,    57,    79,   114,     0,   119,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   109,   110,
     111,    68,     0,    67,    65,     0,    24,    34,     0,     0,
       0,     0,    84,     0,     0,    75,    94,    96,    98,   100,
     102,   104,    64,     0,    69,    27,    25,    19,    23,    29,
      12,     0,    45,    89,    87,    80,   120,    66,    22,    29,
       0,    24,     0,     0,    15,    24,    20,    28,    32,     0,
      13,    34,    26,     0,     0,    16,    31,    30,     0,    17
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    14,    24,    25,    56,    32,    53,    80,
     183,    55,    81,   191,   198,   114,   146,   180,   167,   168,
     179,   169,   181,   182,   189,    15,    17,    19,    20,    21,
      33,    34,    35,   149,   119,    59,     8,    43,    44,    45,
      61,    46,    74,   142,   143,   109,   110,    47,    48,    49,
      93,    79,    50,    62,   153,    51,    60,    87,   152,    88,
     151,   120,   121,   103,   132,   133,   134,   135,   136,   137,
      69,    70,    71,    72,    92,   127
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -179
static const yytype_int16 yypact[] =
{
    -179,    10,    11,  -179,     6,    46,    61,  -179,    33,    83,
      76,    55,  -179,    77,    84,    85,  -179,    75,  -179,    86,
    -179,    87,    79,  -179,    88,    40,  -179,  -179,    -4,  -179,
      89,    90,  -179,    91,  -179,    92,  -179,  -179,  -179,     0,
      93,  -179,    96,  -179,    95,    94,  -179,  -179,  -179,    63,
    -179,  -179,  -179,  -179,  -179,  -179,    86,  -179,  -179,    71,
       4,    99,     0,     0,  -179,  -179,  -179,  -179,  -179,    36,
      45,  -179,  -179,  -179,   105,    97,  -179,    -4,     7,  -179,
     108,   108,  -179,   100,    41,     0,     0,  -179,  -179,     7,
      98,   109,   111,   101,     0,     0,     0,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,     0,     0,     0,   103,  -179,    37,
    -179,  -179,  -179,  -179,   110,   112,  -179,  -179,  -179,  -179,
     113,  -179,  -179,  -179,  -179,  -179,     0,  -179,     7,    45,
      45,    45,     0,     0,     0,     0,     0,     0,  -179,  -179,
    -179,  -179,    80,  -179,  -179,    97,     9,    55,    41,   114,
       0,   117,  -179,     7,    82,  -179,    39,    39,    39,    39,
      39,    39,  -179,   103,  -179,   106,  -179,  -179,  -179,  -179,
    -179,   116,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
     119,     9,   115,   118,  -179,     9,  -179,  -179,  -179,    72,
    -179,    55,  -179,   120,    41,  -179,  -179,  -179,   122,  -179
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -179,  -179,  -179,  -142,    74,  -179,  -179,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,    50,  -179,  -179,  -178,   -38,
    -179,  -179,   -45,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
    -179,   102,  -179,  -179,  -146,  -179,  -179,   121,    59,  -179,
    -179,   -77,  -179,  -179,   -26,  -179,    -7,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
    -179,    13,   -39,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
    -105,   -27,   -34,  -179,  -179,  -179
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -44
static const yytype_int16 yytable[] =
{
      68,   112,   171,   187,    63,   170,    28,   192,    85,    36,
       3,    37,   123,    64,     4,    65,   165,    28,    86,     5,
      36,   166,   -27,    90,    91,    38,    39,   156,   157,   158,
     159,   160,   161,    40,    41,    42,    38,    39,     9,    10,
      66,    67,   144,   145,    40,    41,    42,   122,   197,   195,
       6,   155,    94,    95,    96,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   104,   105,   106,   129,   130,   131,
     138,   139,   140,    30,     7,    31,   175,    83,   193,    84,
     194,    22,    23,   117,   118,   162,   163,   176,   150,    12,
      11,    13,    16,    18,    27,    78,    -8,   -38,    28,    26,
      75,    77,    52,    54,   -43,    58,    76,    89,    73,   107,
     108,   173,   113,   116,   125,   126,   141,   147,   166,   150,
     148,   172,   174,   184,   186,   190,   124,   178,   188,   199,
      82,   115,   128,   196,   185,    57,   111,   177,   164,   154,
       0,     0,     0,     0,     0,    29
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-179)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      39,    78,   148,   181,     4,   147,    10,   185,     4,    13,
       0,    15,    89,    13,     3,    15,     7,    10,    14,    13,
      13,    12,    13,    62,    63,    29,    30,   132,   133,   134,
     135,   136,   137,    37,    38,    39,    29,    30,     5,     6,
      40,    41,     5,     6,    37,    38,    39,    86,   194,   191,
       4,   128,    16,    17,    18,    16,    17,    18,    22,    23,
      24,    25,    26,    27,    19,    20,    21,    94,    95,    96,
     104,   105,   106,    33,    13,    35,   153,     6,     6,     8,
       8,     6,     7,    42,    43,     5,     6,     5,     6,    13,
       7,    36,    15,     9,    15,    32,    10,    12,    10,    12,
       4,     7,    13,    13,    13,    13,    11,     8,    15,     4,
      13,   150,     4,    13,     5,     4,    13,     7,    12,     6,
       8,     7,     5,     7,     5,     7,    28,   165,    13,     7,
      56,    81,    31,    13,   179,    33,    77,   163,   145,   126,
      -1,    -1,    -1,    -1,    -1,    24
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    46,     0,     3,    13,     4,    13,    80,     5,
       6,     7,    13,    36,    47,    69,    15,    70,     9,    71,
      72,    73,     6,     7,    48,    49,    12,    15,    10,    81,
      33,    35,    51,    74,    75,    76,    13,    15,    29,    30,
      37,    38,    39,    81,    82,    83,    85,    91,    92,    93,
      96,    99,    13,    52,    13,    55,    50,    75,    13,    79,
     100,    84,    97,     4,    13,    15,    40,    41,   106,   114,
     115,   116,   117,    15,    86,     4,    11,     7,    32,    95,
      53,    56,    48,     6,     8,     4,    14,   101,   103,     8,
     106,   106,   118,    94,    16,    17,    18,    22,    23,    24,
      25,    26,    27,   107,    19,    20,    21,     4,    13,    89,
      90,    82,    85,     4,    59,    59,    13,    42,    43,    78,
     105,   106,   106,    85,    28,     5,     4,   119,    31,   115,
     115,   115,   108,   109,   110,   111,   112,   113,   116,   116,
     116,    13,    87,    88,     5,     6,    60,     7,     8,    77,
       6,   104,   102,    98,   105,    85,   114,   114,   114,   114,
     114,   114,     5,     6,    90,     7,    12,    62,    63,    65,
      47,    78,     7,   106,     5,    85,     5,    88,    63,    64,
      61,    66,    67,    54,     7,    66,     5,    62,    13,    68,
       7,    57,    62,     6,     8,    47,    13,    78,    58,     7
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1787 of yacc.c  */
#line 31 "compilador.y"
    { niv_lex = 0; desloc = 0; num_vars = 0; simb_buscado = -1; var_atrib =-1; num_rot=-1; dec_var_global=1;
             geraCodigo (NULL, "INPP",0,NULL); 
             }
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 36 "compilador.y"
    {

	     int i =topo_tabela-1;
	     int num_vars1=0;
	     while (i!=-1)
	     {
//printf("%s ",tab_simb[i].nome);
	     	if (tab_simb[i].tipo==0)
		  num_vars1++;
		i--;
	     }
	     geraCodigoInt (NULL, "DMEM",1,num_vars1,0);
             geraCodigo (NULL, "PARA",0,NULL);
             }
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 61 "compilador.y"
    { niv_lex+=1; desloc=0; geraRotulo(rotulo); empilhaRotulo(num_rot); geraCodigo (NULL, "DSVS",1,rotulo);  }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 63 "compilador.y"
    {
                  retorno_rot = desempilhaRotulo();
		  niv_lex--;
                  concatenaRotulo(retorno_rot,rotulo);  
                  geraCodigo (rotulo, "NADA",0,NULL);
                  }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 80 "compilador.y"
    { 
              geraRotulo(rotulo); empilhaRotulo(num_rot); insereSimbolo(token, 1, niv_lex, desloc, rotulo, 0); 
              geraCodigo (rotulo, "NADA",0,NULL);
              geraCodigoInt (NULL, "ENPR",1,niv_lex,0);
              }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 89 "compilador.y"
    {
              retorno_rot = desempilhaRotulo();
              concatenaRotulo(retorno_rot,rotulo); 
              simb_buscado = buscaSimbolo(rotulo,1); 
              int num_vars2=0;

	     int i =topo_tabela-1;
	     while (tab_simb[i].tipo!=1 || tab_simb[i].niv_lex!=niv_lex)
	     {
		  if (tab_simb[i].tipo==0)
		    num_vars2++;
		  topo_tabela--;
		i--;
	     }              



              geraCodigoInt (NULL, "DMEM",1,num_vars2,0);
              geraCodigoInt (NULL, "RTPR",2,tab_simb[simb_buscado].niv_lex,tab_simb[simb_buscado].num_param); 
              }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 114 "compilador.y"
    { 
              geraRotulo(rotulo); empilhaRotulo(num_rot); insereSimbolo(token, 3, niv_lex, desloc, rotulo, 0); 
              geraCodigo (rotulo, "NADA",0,NULL);
              geraCodigoInt (NULL, "ENPR",1,niv_lex,0);
              }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 124 "compilador.y"
    {
	      int i =topo_tabela-1;
	      while (tab_simb[i].tipo!=3 || tab_simb[i].niv_lex!=niv_lex)
	      {
		i--;
	      }
	      tab_simb[i].desloc = -4 - (tab_simb[i].num_param);

	      }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 134 "compilador.y"
    {
              retorno_rot = desempilhaRotulo();
              concatenaRotulo(retorno_rot,rotulo); 
              simb_buscado = buscaSimbolo(rotulo,1); 
              int num_vars2=0;

	     int i =topo_tabela-1;
	     while (tab_simb[i].tipo!=3 || tab_simb[i].niv_lex!=niv_lex)
	     {
		  if (tab_simb[i].tipo==0)
		    num_vars2++;
		  topo_tabela--;
		i--;
	     }


              geraCodigoInt (NULL, "DMEM",1,num_vars2,0);
              geraCodigoInt (NULL, "RTPR",2,tab_simb[simb_buscado].niv_lex,tab_simb[simb_buscado].num_param); 
              }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 157 "compilador.y"
    {num_params=0; }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 159 "compilador.y"
    { 
		int i =topo_tabela;
		int desl = -4;
                int achou = 0;
	        while (achou!=1)
	        {  
		  if (tab_simb[i].tipo==1 || tab_simb[i].tipo==3)
		  { 
		    achou = 1;
		  }
		  else
		    i--;
		  if (tab_simb[i].tipo==2)
		  { 
		    tab_simb[i].desloc = desl;
		    desl--;
		  }
	        }   
                int idx=0;
		int idx_p = i; 
		tab_simb[i].indices = malloc(num_params*sizeof(int));
                tab_simb[i].num_param = num_params;
		while (i!=topo_tabela-1)
	        { 
		  i++;
		  if (tab_simb[i].tipo==2)
		  {
		    tab_simb[idx_p].indices[idx] = tab_simb[i].num_param;
		    idx++;
		  }
	        }   
	        num_params = 0;
		}
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 203 "compilador.y"
    { ref=1; }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 204 "compilador.y"
    { ref=0; }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 210 "compilador.y"
    { }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 213 "compilador.y"
    {
              }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 221 "compilador.y"
    { insereSimbolo(token, 2, niv_lex, desloc, "0", ref); 

		num_params++;
              }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 226 "compilador.y"
    { 
                insereSimbolo(token, 2, niv_lex, desloc, "0", ref); 
		num_params++;
              }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 247 "compilador.y"
    { geraRotulo(rotulo); insereSimbolo(token, 4, niv_lex, 0, rotulo, 0); 
              }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 250 "compilador.y"
    { 
                geraRotulo(rotulo); insereSimbolo(token, 4, niv_lex, 0, rotulo, 0); 
              }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 265 "compilador.y"
    { }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 266 "compilador.y"
    {
              geraCodigoInt (NULL, "AMEM",1,num_vars,0);
              num_vars =0;
              }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 277 "compilador.y"
    { num_vars2 =0; }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 280 "compilador.y"
    {
		int i=topo_tabela;
                int contador=0;
	      while(contador!=num_vars2+1)
		{
		tab_simb[i].num_param = tipo_var;
		contador++;
		i--;
		}
              }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 293 "compilador.y"
    { tipo_var=1; }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 294 "compilador.y"
    { tipo_var=0; }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 300 "compilador.y"
    { insereSimbolo(token, 0, niv_lex, desloc, "0", 0); 
                desloc++; 
                num_vars++;
		num_vars2++; 
              }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 306 "compilador.y"
    { 
                insereSimbolo(token, 0, niv_lex, desloc, "0", 0); 
                desloc++; 
                num_vars++; 
		num_vars2++; 
              }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 328 "compilador.y"
    {
	   simb_buscado = buscaSimbolo(token,0); 
	   int i = 0;
           int num_locais = 0;
           while (i!=topo_tabela)
	        { 
		  if (tab_simb[i].tipo==0 && tab_simb[i].niv_lex==niv_lex)
		  {
		    num_locais++;
		  }
                  i++;
	        }
           geraCodigo (tab_simb[simb_buscado].rot, "NADA",0,NULL);
	   geraCodigoInt (NULL, "ENRT",2,niv_lex,num_locais);  
               
         }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 352 "compilador.y"
    {  }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 362 "compilador.y"
    { 
		    geraCodigo (NULL, "LEIT",0,NULL);
		    
		    simb_buscado = buscaSimbolo(token,0);  
		    if (simb_buscado != -1)
                    {
		      if (tab_simb[simb_buscado].tipo==0 || (tab_simb[simb_buscado].tipo==2 && tab_simb[simb_buscado].num_param==0))
		        geraCodigoInt(NULL,"ARMZ",2,tab_simb[simb_buscado].niv_lex,tab_simb[simb_buscado].desloc);
	    	      else if (tab_simb[simb_buscado].tipo==2 && tab_simb[simb_buscado].num_param==1)
	                geraCodigoInt(NULL,"ARMI",2,tab_simb[simb_buscado].niv_lex,tab_simb[simb_buscado].desloc);
	    	      else
	              {
		        printf("erro \n");
		        exit(1);
	              }
	             }
                     else
                     {
	               printf("erro, nao achou\n");
	               exit(1);
	             }
		   }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 391 "compilador.y"
    { 
		    simb_buscado = buscaSimbolo(token,0);  
		    if (simb_buscado != -1)
                    {
		      if (tab_simb[simb_buscado].tipo==0 || (tab_simb[simb_buscado].tipo==2 && tab_simb[simb_buscado].num_param==0))
		        geraCodigoInt(NULL,"CRVL",2,tab_simb[simb_buscado].niv_lex,tab_simb[simb_buscado].desloc);
	    	      else if (tab_simb[simb_buscado].tipo==2 && tab_simb[simb_buscado].num_param==1)
	                geraCodigoInt(NULL,"CRVI",2,tab_simb[simb_buscado].niv_lex,tab_simb[simb_buscado].desloc);
	    	      else
	              {
		        printf("erro xxx\n");
		        exit(1);
	              }
	             }
                     else
                     {
	               printf("erro, nao achou\n");
	               exit(1);
	             }

		     geraCodigo (NULL, "IMPR",0,NULL);
		   }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 417 "compilador.y"
    { 
	  simb_buscado = buscaSimbolo(token,0);
          if (simb_buscado==-1)
	      {
		printf("erro, label nao existe\n");
		exit(1);
	      } 
	  geraCodigoInt (tab_simb[simb_buscado].rot, "DSVR",3,tab_simb[simb_buscado].niv_lex,niv_lex);

	}
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 432 "compilador.y"
    { 
                       retorno_rot = desempilhaRotulo();
                       concatenaRotulo(retorno_rot,rotulo);
                       geraCodigo (rotulo, "NADA",0,NULL); 
                     }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 440 "compilador.y"
    {
           geraRotulo(rotulo);
           empilhaRotulo(num_rot);
           geraCodigo (NULL, "DSVF",1,rotulo); 
           geraRotulo(rotulo);
         }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 447 "compilador.y"
    {
           retorno_rot = desempilhaRotulo();
           empilhaRotulo(retorno_rot+1);
           concatenaRotulo(retorno_rot+1,rotulo);
           geraCodigo (NULL, "DSVS",1,rotulo); 
           concatenaRotulo(retorno_rot,rotulo);
           geraCodigo (rotulo, "NADA",0,NULL); 
         }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 465 "compilador.y"
    { 
                                  geraRotulo(rotulo);
                                  geraCodigo (rotulo, "NADA",0,NULL); 
				}
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 471 "compilador.y"
    {
                                  geraRotulo(rotulo);
                                  empilhaRotulo(num_rot);
                                  geraCodigo (NULL, "DSVF",1,rotulo); 
                                  
				}
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 478 "compilador.y"
    {
                                  retorno_rot = desempilhaRotulo();
                                  concatenaRotulo(retorno_rot-1,rotulo);
                                  geraCodigo (NULL, "DSVS",1,rotulo); 
                                  concatenaRotulo(retorno_rot,rotulo);
                                  geraCodigo (rotulo, "NADA",0,NULL); 
                                  
                                  
				}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 490 "compilador.y"
    {
              var_atrib = buscaSimbolo(token,0); 
              if (var_atrib==-1)
	      {
		printf("erro, variavel nao existe\n");
		exit(1);
	      }
	      else
	      {
	        if (tab_simb[var_atrib].tipo==1)
		{
		  insereSimbolo("", 5, num_params_proc, curr_par, "", var_atrib);
		  num_params_proc = tab_simb[var_atrib].num_param;
		  curr_par = 0;
		}
	      }
            }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 512 "compilador.y"
    { imprimeTabSimb(); }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 513 "compilador.y"
    { 
	      if (tab_simb[var_atrib].num_param==1 && is_boolean==0)
	     {
		printf("erro, variavel é booleana.\n");
		exit(1);
	     }
	      if (tab_simb[var_atrib].tipo==0 || tab_simb[var_atrib].tipo==3 || (tab_simb[var_atrib].tipo==2 && tab_simb[var_atrib].num_param==0))
		{
                geraCodigoInt (NULL, "ARMZ",2,tab_simb[var_atrib].niv_lex,tab_simb[var_atrib].desloc); 

		}
	      else if (tab_simb[var_atrib].tipo==2 && tab_simb[var_atrib].num_param==1)
	        geraCodigoInt (NULL, "ARMI",2,tab_simb[var_atrib].niv_lex,tab_simb[var_atrib].desloc); 
	      else
	      {
		printf("erro, variavel nao foi passada por referencia\n");
		exit(1);
	      }
	is_boolean=0;
            }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 534 "compilador.y"
    {
	     if (curr_par!=num_params_proc) 
	     {
		printf("erro, procedimento com numero diferente de parametros\n");
		exit(1);
	     }
	     topo_tabela--;
	     curr_par = tab_simb[topo_tabela].desloc;
	     num_params_proc = tab_simb[topo_tabela].niv_lex;
	     geraCodigoInt (tab_simb[var_atrib].rot, "CHPR",4,niv_lex,0);
	    }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 549 "compilador.y"
    { 
	    }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 554 "compilador.y"
    { curr_par++; }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 555 "compilador.y"
    { curr_par++; }
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 563 "compilador.y"
    { is_boolean = 1; }
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 565 "compilador.y"
    {
             geraCodigo (NULL, "CMIG",0,NULL); 
           }
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 569 "compilador.y"
    { is_boolean = 1; }
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 571 "compilador.y"
    {
             geraCodigo (NULL, "CMDG",0,NULL); 
           }
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 575 "compilador.y"
    { is_boolean = 1; }
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 577 "compilador.y"
    {
             geraCodigo (NULL, "CMMA",0,NULL); 
           }
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 581 "compilador.y"
    { is_boolean = 1; }
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 583 "compilador.y"
    {
             geraCodigo (NULL, "CMME",0,NULL); 
           }
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 587 "compilador.y"
    { is_boolean = 1; }
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 589 "compilador.y"
    {
             geraCodigo (NULL, "CMAG",0,NULL); 
           }
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 593 "compilador.y"
    { is_boolean = 1; }
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 595 "compilador.y"
    {
             geraCodigo (NULL, "CMEG",0,NULL); 
           }
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 600 "compilador.y"
    { geraCodigo (NULL, "SOMA",0,NULL); }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 601 "compilador.y"
    { geraCodigo (NULL, "SUBT",0,NULL); }
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 602 "compilador.y"
    { geraCodigo (NULL, "OR",0,NULL); }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 606 "compilador.y"
    { geraCodigo (NULL, "MULT",0,NULL); }
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 607 "compilador.y"
    { geraCodigo (NULL, "DIVI",0,NULL); }
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 608 "compilador.y"
    { geraCodigo (NULL, "AND",0,NULL); }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 613 "compilador.y"
    { 
         geraCodigo (NULL, "CRCT",1,token);
       }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 618 "compilador.y"
    { geraCodigo (NULL, "CRCT",1,"1"); }
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 619 "compilador.y"
    { geraCodigo (NULL, "CRCT",1,"0"); }
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 623 "compilador.y"
    { 
		 simb_buscado = buscaSimbolo(token,0);
		   if (simb_buscado != -1)
		   {
			if (tab_simb[simb_buscado].tipo==0 || (tab_simb[simb_buscado].tipo==2 && tab_simb[simb_buscado].num_param==0))
                          if (tab_simb[topo_tabela-1].tipo==5 && tab_simb[tab_simb[topo_tabela-1].num_param].indices[curr_par]==0)
			  	geraCodigoInt(NULL,"CRVL",2,tab_simb[simb_buscado].niv_lex,tab_simb[simb_buscado].desloc);
			  else if (tab_simb[topo_tabela-1].tipo==5 && tab_simb[tab_simb[topo_tabela-1].num_param].indices[curr_par]==1)
				geraCodigoInt(NULL,"CREN",2,tab_simb[simb_buscado].niv_lex,tab_simb[simb_buscado].desloc);
			  else
				geraCodigoInt(NULL,"CRVL",2,tab_simb[simb_buscado].niv_lex,tab_simb[simb_buscado].desloc);
		    	else if (tab_simb[simb_buscado].tipo==2 && tab_simb[simb_buscado].num_param==1)
			{
				if (tab_simb[topo_tabela-1].tipo==5 && tab_simb[tab_simb[topo_tabela-1].num_param].indices[curr_par]==1)
					geraCodigoInt(NULL,"CRVL",2,tab_simb[simb_buscado].niv_lex,tab_simb[simb_buscado].desloc);
				else 
					geraCodigoInt(NULL,"CRVI",2,tab_simb[simb_buscado].niv_lex,tab_simb[simb_buscado].desloc);
			}

			else if (tab_simb[simb_buscado].tipo==3)
			{
			  insereSimbolo("", 5, num_params_proc, curr_par, "", simb_buscado);
			  num_params_proc = tab_simb[simb_buscado].num_param;
		  	  curr_par = 0;
			  func = simb_buscado;
			  geraCodigoInt (NULL, "AMEM",1,1,0);
			}
		   }
		   else
		   {
		     printf("erro, nao achou\n");
		     exit(1);
		   }
		}
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 662 "compilador.y"
    { topo_tabela--;
		printf("topo da tabela: %d %d\n",tab_simb[topo_tabela].desloc,tab_simb[topo_tabela].niv_lex);
		if (curr_par!=num_params_proc) 
	          	{
		   	  printf("erro, funcao com numero diferente de parametros\n");
		    	  exit(1);
	          	}
			else
		  	  geraCodigoInt (tab_simb[func].rot, "CHPR",4,niv_lex,0);
		curr_par = tab_simb[topo_tabela].desloc;
		num_params_proc = tab_simb[topo_tabela].niv_lex;

	      }
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 675 "compilador.y"
    {
		if (tab_simb[simb_buscado].tipo==3)
		  {
			topo_tabela--;
			if (curr_par!=num_params_proc) 
	          	{
		   	  printf("erro, funcao com numero diferente de parametros\n");
		    	  exit(1);
	          	}
			else
		  	  geraCodigoInt (tab_simb[func].rot, "CHPR",4,niv_lex,0); 
			curr_par = tab_simb[topo_tabela].desloc;
			num_params_proc = tab_simb[topo_tabela].niv_lex;
		  }
	      }
    break;


/* Line 1787 of yacc.c  */
#line 2348 "compilador.tab.c"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 693 "compilador.y"


main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }


/* -------------------------------------------------------------------
 *  Inicia a Tabela de S\EDmbolos
 * ------------------------------------------------------------------- */
topo_tabela=0;
topo_rot =0;
is_boolean=0;
tab_simb = malloc(sizeof(elem_tabela)*30);
for (i=0; i<30; i++)
  tab_simb[i].tipo=-1;
  
tab_rot = malloc(sizeof(int)*30);

   yyin=fp;
   yyparse();

   return 0;
}


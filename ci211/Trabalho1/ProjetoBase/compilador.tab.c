/* A Bison parser, made by GNU Bison 3.0.2.  */

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compilador.y" /* yacc.c:339  */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"


int num_vars; 		//N�mero de vari�veis declaradas (para aloca��o AMEN)
int num_vars2;		//Auxiliar
int nLexico; 		//n�vel l�xico atual
int nDesloc; 		//deslocamento da vari�vel
int nVarsAloc; 		//N�mero de vars para aloca��o
int tipoVar;		//Tipo da vari�vel (aqui apenas int)

int buscaSimbolo;	//Auxiliar para busca de s�mbolos na TS
int is_boolean;		//Auxiliar para a an�lise de tipos

int auxRotuloEntradaW;	//R�tulo de entrada while
int auxRotuloSaidaW;	//R�tulo de sa�da do while

int auxRotuloDesvioI;	//R�tulo else do if
int auxRotuloSaidaI;	//R�tulo de sa�da do if

int auxRotuloEntradaP;	//Rotulo de entrada do procedimento
int auxRotuloSaidaP; 	//Rotulo de saida do procedimento, para que o bloco nao seja executado

int nLexicoCham;	//N�vel l�xico do procedimento ou fun��o chamadores de procedimentos e fun��es

#line 96 "compilador.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    FUNCTION = 270,
    PROCEDURE = 271,
    MAIOR = 272,
    MENOR = 273,
    MAIOR_IGUAL = 274,
    MENOR_IGUAL = 275,
    IGUAL = 276,
    AND = 277,
    DIFF = 278,
    DIV = 279,
    FALSE = 280,
    TRUE = 281,
    MULT = 282,
    MAIS = 283,
    MENOS = 284,
    OR = 285,
    INTEGER = 286,
    BOOLEAN = 287,
    WHILE = 288,
    DO = 289,
    IF = 290,
    THEN = 291,
    ELSE = 292,
    LOWER_THAN_ELSE = 293,
    LABEL = 294,
    NUMERO = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMPILADOR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 188 "compilador.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   97

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    43,    43,    43,    78,    82,    86,    77,    94,    95,
      98,   104,   110,   114,   114,   119,   122,   123,   126,   129,
     126,   144,   145,   148,   155,   164,   165,   168,   169,   173,
     195,   172,   217,   220,   221,   223,   225,   224,   233,   234,
     235,   236,   239,   247,   255,   256,   259,   260,   270,   280,
     290,   300,   310,   322,   326,   330,   339,   342,   346,   350,
     359,   362,   373,   377,   378,   383,   391,   401,   390,   427,
     448,   447,   462,   461,   474
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "ABRE_PARENTESES",
  "FECHA_PARENTESES", "VIRGULA", "PONTO_E_VIRGULA", "DOIS_PONTOS", "PONTO",
  "T_BEGIN", "T_END", "VAR", "IDENT", "ATRIBUICAO", "FUNCTION",
  "PROCEDURE", "MAIOR", "MENOR", "MAIOR_IGUAL", "MENOR_IGUAL", "IGUAL",
  "AND", "DIFF", "DIV", "FALSE", "TRUE", "MULT", "MAIS", "MENOS", "OR",
  "INTEGER", "BOOLEAN", "WHILE", "DO", "IF", "THEN", "ELSE",
  "LOWER_THAN_ELSE", "LABEL", "NUMERO", "$accept", "programa", "$@1",
  "bloco", "$@2", "$@3", "$@4", "parte_declara_rot", "lista_rots",
  "parte_declara_vars", "var", "$@5", "declara_vars", "declara_var", "$@6",
  "$@7", "tipo", "lista_id_var", "lista_idents", "declara_sub_rotina",
  "declara_procedimento", "$@8", "$@9", "comando_composto", "comandos",
  "comando", "$@10", "comando_sem_rotulo", "atribuicao_var",
  "atrib_direita", "expressao", "expressao_simples1", "expressao_simples",
  "termo", "fator", "repetitivo", "$@11", "$@12", "condicional", "if_then",
  "$@13", "cond_else", "$@14", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF -91

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-91)))

#define YYTABLE_NINF -19

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -91,     3,    25,   -91,    10,    31,    34,   -91,    40,    54,
      49,    24,   -91,    26,    55,   -91,   -91,    51,   -91,    53,
      27,   -91,   -91,   -91,    56,   -91,    57,   -91,    58,   -91,
     -91,    59,   -91,    61,   -91,    60,   -91,   -91,    36,    62,
      -9,   -91,    63,    28,    24,   -91,   -91,    -4,   -91,   -91,
      64,    70,   -91,   -91,    65,   -91,   -91,    41,   -91,   -91,
     -91,   -91,   -91,    -4,    -4,   -91,   -91,   -91,   -91,   -91,
      20,   -16,   -91,    72,   -91,    -9,    -4,   -91,   -91,    74,
      75,   -91,    78,    48,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,   -91,    -4,    -4,    -4,    -8,   -91,   -91,
      -8,   -91,   -91,    52,   -91,    -8,   -10,   -10,   -10,   -10,
     -10,   -10,   -16,   -16,   -16,   -91,   -91,   -91,   -91,   -91,
      -8,   -91,   -91
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,    26,     0,     0,
       0,     9,    25,     0,     0,     4,    11,     0,     3,    15,
       0,     8,     5,    12,     0,    10,    28,    18,     0,     6,
      27,    14,    17,     0,    29,     0,    16,    24,     0,     0,
       0,     7,     0,     0,     9,    43,    66,    45,    36,    39,
       0,     0,    35,    38,     0,    40,    41,    74,    23,    21,
      22,    19,    30,    45,    45,    61,    65,    64,    62,    70,
      46,    56,    60,     0,    32,    34,    45,    72,    69,     0,
       0,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,     0,     0,     0,     0,    33,    42,
       0,    20,    31,     0,    63,     0,    49,    50,    51,    52,
      47,    48,    53,    54,    55,    59,    58,    57,    37,    73,
       0,    71,    68
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -91,   -91,   -91,    43,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,    66,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,    50,    13,   -91,   -91,   -90,   -91,   -91,
     -47,   -91,   -33,   -78,   -62,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    14,    19,    26,    35,    15,    17,    22,
      23,    24,    31,    32,    33,    79,    61,    38,     8,    29,
      30,    39,    80,    49,    50,    51,    73,    52,    53,    54,
      69,    93,    70,    71,    72,    55,    63,   103,    56,    57,
      83,    78,   100
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      64,    40,    40,     3,    45,    45,    94,   118,    95,    65,
     119,    96,   112,   113,   114,   121,    81,    82,    90,    91,
      92,    66,    67,     5,    46,    46,    47,    47,     4,    99,
     122,    48,   115,   116,   117,     6,    68,    84,    85,    86,
      87,    88,    42,    89,    43,     9,    10,     7,    90,    91,
      92,   106,   107,   108,   109,   110,   111,    20,    21,    59,
      60,    11,    12,    13,    18,   -13,    16,    25,    27,    44,
      40,    34,   -18,    28,    37,    74,    58,    75,    77,    76,
      97,   101,   102,   104,   105,    41,   120,    62,    98,     0,
       0,     0,     0,     0,     0,     0,     0,    36
};

static const yytype_int8 yycheck[] =
{
       4,    10,    10,     0,    13,    13,    22,    97,    24,    13,
     100,    27,    90,    91,    92,   105,    63,    64,    28,    29,
      30,    25,    26,    13,    33,    33,    35,    35,     3,    76,
     120,    40,    94,    95,    96,     4,    40,    17,    18,    19,
      20,    21,     6,    23,     8,     5,     6,    13,    28,    29,
      30,    84,    85,    86,    87,    88,    89,     6,     7,    31,
      32,     7,    13,    39,     9,    12,    40,    40,    12,     7,
      10,    13,    13,    16,    13,    11,    13,     7,    37,    14,
       8,     7,     7,     5,    36,    35,    34,    44,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    43,     0,     3,    13,     4,    13,    59,     5,
       6,     7,    13,    39,    44,    48,    40,    49,     9,    45,
       6,     7,    50,    51,    52,    40,    46,    12,    16,    60,
      61,    53,    54,    55,    13,    47,    54,    13,    58,    62,
      10,    64,     6,     8,     7,    13,    33,    35,    40,    64,
      65,    66,    68,    69,    70,    76,    79,    80,    13,    31,
      32,    57,    44,    77,     4,    13,    25,    26,    40,    71,
      73,    74,    75,    67,    11,     7,    14,    37,    82,    56,
      63,    71,    71,    81,    17,    18,    19,    20,    21,    23,
      28,    29,    30,    72,    22,    24,    27,     8,    65,    71,
      83,     7,     7,    78,     5,    36,    73,    73,    73,    73,
      73,    73,    74,    74,    74,    75,    75,    75,    68,    68,
      34,    68,    68
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    43,    42,    45,    46,    47,    44,    48,    48,
      49,    49,    50,    52,    51,    51,    53,    53,    55,    56,
      54,    57,    57,    58,    58,    59,    59,    60,    60,    62,
      63,    61,    64,    65,    65,    66,    67,    66,    68,    68,
      68,    68,    69,    70,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    73,    73,    73,    73,    74,    74,    74,
      74,    75,    75,    75,    75,    75,    77,    78,    76,    79,
      81,    80,    83,    82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     9,     0,     0,     0,     7,     3,     0,
       3,     1,     1,     0,     3,     0,     2,     1,     0,     0,
       6,     1,     1,     3,     1,     3,     1,     1,     0,     0,
       0,     7,     3,     3,     2,     1,     0,     4,     1,     1,
       1,     1,     3,     1,     2,     0,     0,     2,     2,     2,
       2,     2,     2,     3,     3,     3,     1,     3,     3,     3,
       1,     1,     1,     3,     1,     1,     0,     0,     6,     2,
       0,     5,     0,     3,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
        case 2:
#line 43 "compilador.y" /* yacc.c:1646  */
    {
		
		num_vars 	= 0;
		nLexico		= 0;
		nDesloc		= 0;

             	geraCodigo (NULL, "INPP");
             }
#line 1364 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 54 "compilador.y" /* yacc.c:1646  */
    {

		// Percorre TS e conta o n�mero de vars para desalocar
		int nVarsDesaloc = 0;
		
		//Nao da pra usar for =(
		int i = topoTS;
		while (i >= 0)
		{
			if(TS[i].tipo == 0)
			{
				nVarsDesaloc++;
			}
			i--;
		}
		
		//Transforma nVarsDesloc em char
		geraCodigo1Param(NULL, "DMEN", nVarsDesaloc);
             	geraCodigo (NULL, "PARA"); 
             }
#line 1389 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 78 "compilador.y" /* yacc.c:1646  */
    {
		}
#line 1396 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 82 "compilador.y" /* yacc.c:1646  */
    {
		}
#line 1403 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 86 "compilador.y" /* yacc.c:1646  */
    {
		}
#line 1410 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 90 "compilador.y" /* yacc.c:1646  */
    {
		}
#line 1417 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 101 "compilador.y" /* yacc.c:1646  */
    {
		InsereTS(token, 1, nLexico, nDesloc, NULL, GeraNovoRotulo());
	}
#line 1425 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 105 "compilador.y" /* yacc.c:1646  */
    {
		InsereTS(token, 1, nLexico, nDesloc, NULL, GeraNovoRotulo());
	}
#line 1433 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 114 "compilador.y" /* yacc.c:1646  */
    { }
#line 1439 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 115 "compilador.y" /* yacc.c:1646  */
    {
			geraCodigo1Param(NULL, "AMEM", num_vars);
			num_vars = 0;
		}
#line 1448 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 126 "compilador.y" /* yacc.c:1646  */
    {  nVarsAloc = 0; }
#line 1454 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 129 "compilador.y" /* yacc.c:1646  */
    {
			//Atualiza o tipo de vari�vel na tabela
			int i 		= topoTS;
			int cont 	= 0;

			while (cont <= nVarsAloc)
			{
				TS[i].info.infoVar.tipoVar = tipoVar;
				cont++;
				i--;
			}
              }
#line 1471 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 144 "compilador.y" /* yacc.c:1646  */
    { tipoVar = 0; }
#line 1477 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 145 "compilador.y" /* yacc.c:1646  */
    { tipoVar = 1;}
#line 1483 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 149 "compilador.y" /* yacc.c:1646  */
    {
		      	InsereTS(token, 0, nLexico, nDesloc, 0, -1);
		 	nDesloc++;
		      	num_vars++;
			nVarsAloc++;
		}
#line 1494 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 156 "compilador.y" /* yacc.c:1646  */
    { 
			InsereTS(token, 0, nLexico, nDesloc, 0, -1);
			nDesloc++;
			num_vars++;
			nVarsAloc++;
		}
#line 1505 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 173 "compilador.y" /* yacc.c:1646  */
    {
		char auxRotulo[3];

		auxRotuloSaidaP 	= GeraNovoRotulo();
		auxRotuloEntradaP   	= GeraNovoRotulo();

		InsereTR(auxRotuloSaidaP);

		FormataRotulo(auxRotuloSaidaP, auxRotulo);
		geraCodigoParamRot(NULL, "DSVS", auxRotulo);

		FormataRotulo(auxRotuloEntradaP, auxRotulo);
		geraCodigo(auxRotulo, "NADA");

		geraCodigo1Param(NULL, "ENPR", nLexico);
		
		nLexico++;
		nDesloc = 0;

	}
#line 1530 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 195 "compilador.y" /* yacc.c:1646  */
    {
		char auxRotulo[3];
		geraCodigo2Params(NULL, "RTPR", nLexicoCham, 0);

		FormataRotulo(TR[topoTR], auxRotulo);
		geraCodigo(auxRotulo, "NADA");

		RemoveTR();

		// Retirar par�metros e vari�veis e retornar ao nivel lexico anterior
		int i = topoTS;

		while (TS[i].nLexico == nLexico)
		{
			RetiraTS();
		}

		nLexico--;

	}
#line 1555 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 225 "compilador.y" /* yacc.c:1646  */
    {
                 buscaSimbolo = BuscaTS(token, 1);
                 geraCodigo(FormataRotulo(TS[buscaSimbolo].info.infoLabel.nRotulo),
                         "NADA");
         }
#line 1565 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 240 "compilador.y" /* yacc.c:1646  */
    {
                 geraCodigo2Params(NULL, "ARMZ", TS[buscaSimbolo].nLexico,
                        TS[buscaSimbolo].nDesloc);
	}
#line 1574 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 248 "compilador.y" /* yacc.c:1646  */
    {
		fprintf(stdout, "IDENT: %s", token); fflush(stdout);
		buscaSimbolo = BuscaTS(token, 0);
		is_boolean = 0;
	}
#line 1584 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 261 "compilador.y" /* yacc.c:1646  */
    {
		if (is_boolean == 1)
		{
			fprintf(stdout, "ERRO: opera��o inteira com booleanos"); fflush(stdout);
			exit(1);
		}
		geraCodigo(NULL, "CMIG");
		is_boolean = 1;
	}
#line 1598 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 271 "compilador.y" /* yacc.c:1646  */
    {
		if (is_boolean == 1)
		{
			fprintf(stdout, "ERRO: opera��o inteira com booleanos"); fflush(stdout);
			exit(1);
		}
		geraCodigo(NULL, "CMDG");
		is_boolean = 1;
	}
#line 1612 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 281 "compilador.y" /* yacc.c:1646  */
    {
		if (is_boolean == 1)
		{
			fprintf(stdout, "ERRO: opera��o inteira com booleanos"); fflush(stdout);
			exit(1);
		}
		geraCodigo(NULL, "CMMA");
		is_boolean = 1;
	}
#line 1626 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 291 "compilador.y" /* yacc.c:1646  */
    {
		if (is_boolean == 1)
		{
			fprintf(stdout, "ERRO: opera��o inteira com booleanos"); fflush(stdout);
			exit(1);
		}
		geraCodigo(NULL, "CMME");
		is_boolean = 1;
	}
#line 1640 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 301 "compilador.y" /* yacc.c:1646  */
    {
		if (is_boolean == 1)
		{
			fprintf(stdout, "ERRO: operacao inteiro com booleanos");fflush(stdout);
			exit(1);
		}
		geraCodigo(NULL, "CMAG");
		is_boolean = 1;
	}
#line 1654 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 311 "compilador.y" /* yacc.c:1646  */
    {
		if (is_boolean == 1)
		{
			fprintf(stdout, "ERRO: Opera��o inteira com booleanos"); fflush(stdout);
			exit(1);
		}
		geraCodigo(NULL, "CMEG");
		is_boolean = 1;
	}
#line 1668 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 323 "compilador.y" /* yacc.c:1646  */
    {
		geraCodigo(NULL, "SOMA");	
	}
#line 1676 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 327 "compilador.y" /* yacc.c:1646  */
    {
		geraCodigo(NULL, "SUBT");
	}
#line 1684 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 331 "compilador.y" /* yacc.c:1646  */
    {
		if (is_boolean == 0)
		{
			fprintf(stdout, "ERRO: Opera��o l�gica com inteiros"); fflush(stdout);
			exit(1);
		}
		geraCodigo(NULL, "DISJ");
	}
#line 1697 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 343 "compilador.y" /* yacc.c:1646  */
    {
		geraCodigo(NULL, "MULT");
	}
#line 1705 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 347 "compilador.y" /* yacc.c:1646  */
    {
		geraCodigo(NULL, "DIVI");
	}
#line 1713 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 351 "compilador.y" /* yacc.c:1646  */
    {
		if (is_boolean == 0)
		{
			fprintf(stdout, "ERRO: Opera��o l�gica com inteiros"); fflush(stdout);
			exit(1);
		}
		geraCodigo(NULL, "CONJ");
	}
#line 1726 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 363 "compilador.y" /* yacc.c:1646  */
    {
                 int buscaSimbolo = BuscaTS(token, 0);
                 geraCodigo2Params(NULL, "CRVL", TS[buscaSimbolo].nLexico,
                                         TS[buscaSimbolo].nDesloc);
                 if (TS[buscaSimbolo].info.infoVar.tipoVar == 1)
                 {
                         is_boolean = 1;
                 }
         }
#line 1740 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 374 "compilador.y" /* yacc.c:1646  */
    {
		geraCodigoParamRot(NULL, "CRCT", token);
	}
#line 1748 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 379 "compilador.y" /* yacc.c:1646  */
    {
		is_boolean = 1;
		geraCodigoParamRot(NULL, "CRCT", token);
	}
#line 1757 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 384 "compilador.y" /* yacc.c:1646  */
    {
		is_boolean = 1;
		geraCodigoParamRot(NULL, "CRCT", token);
	}
#line 1766 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 391 "compilador.y" /* yacc.c:1646  */
    {
		char auxRotulo[3];

		auxRotuloEntradaW = GeraNovoRotulo();
		InsereTR(auxRotuloEntradaW);

		FormataRotulo(TR[topoTR], auxRotulo);
		geraCodigo(auxRotulo, "NADA");
	}
#line 1780 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 401 "compilador.y" /* yacc.c:1646  */
    {
		char auxRotulo[3];

		auxRotuloSaidaW = GeraNovoRotulo();
		
		InsereTR(auxRotuloSaidaW);
		
		FormataRotulo(TR[topoTR], auxRotulo);
		geraCodigoParamRot(NULL, "DSVF", auxRotulo);
	}
#line 1795 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 413 "compilador.y" /* yacc.c:1646  */
    {
		char auxRotulo[3];

		FormataRotulo(TR[topoTR-1], auxRotulo);
		geraCodigoParamRot(NULL, "DSVS", auxRotulo);

		FormataRotulo(TR[topoTR], auxRotulo);
		geraCodigo(auxRotulo, "NADA");

		RemoveTR();
		RemoveTR();
	}
#line 1812 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 428 "compilador.y" /* yacc.c:1646  */
    {
		char auxRotulo[3];

		FormataRotulo(TR[topoTR], auxRotulo);
		geraCodigo(auxRotulo, "NADA");

		if (TR[topoTR] == auxRotuloSaidaI)
		{
			RemoveTR();
			RemoveTR();
		}
		else
		{
			RemoveTR();
		}

	}
#line 1834 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 448 "compilador.y" /* yacc.c:1646  */
    {
		char auxRotulo[3];

		auxRotuloDesvioI = GeraNovoRotulo();
		InsereTR(auxRotuloDesvioI);

		FormataRotulo(TR[topoTR], auxRotulo);

		geraCodigoParamRot(NULL, "DSVF", auxRotulo);
	}
#line 1849 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 462 "compilador.y" /* yacc.c:1646  */
    {
		char auxRotulo[3];

		auxRotuloSaidaI = GeraNovoRotulo();
		InsereTR();

		FormataRotulo(TR[topoTR], auxRotulo);
		geraCodigoParamRot(NULL, "DSVS", auxRotulo);
		
		FormataRotulo(TR[topoTR-1], auxRotulo);
		geraCodigo(auxRotulo, "NADA");
	}
#line 1866 "compilador.tab.c" /* yacc.c:1646  */
    break;


#line 1870 "compilador.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 477 "compilador.y" /* yacc.c:1906  */


main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   int i;

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
 *  Inicia a Tabela de S�mbolos
 * ------------------------------------------------------------------- */
	topoTS = -1;
	TS = malloc(32*sizeof(TabelaSimbolos));
	
/**********************************************************************
	Inicia tabela de r�tulos
**********************************************************************/
	ultimoRotulo = -1;
	topoTR = -1;
	TR = malloc(16*sizeof(int)); // o normal � ter menos r�tulo do que vari�vel

   yyin=fp;
   yyparse();

   return 0;
}


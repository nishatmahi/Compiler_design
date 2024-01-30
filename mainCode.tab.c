
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "mainCode.y"

 /* C declaration-contains header, functions and other c variables.*/
	#include<stdio.h>
	#include<stdlib.h>
	#include<conio.h>
	#include<string.h>
	#include<math.h>

    /* structure for storing variables.*/ 
    typedef struct variable{
        char *name; // this is for the name of the variable
        int type; /* indicates data type- 0:int,1:double,2:char* */
        int* ival;  // this is a integer pointer for storing array element
        double* dval;   // this is a double pointer for storing double array element
        char** sval; // this is string pointer for storing string type value array
        int size;   // this is for geting the size of that array
        int isArray;    // 1 for array and 0 for normal variable
    }tmp;

    int temporay = -1; // this is check the expression will return a integer type value or a real type value

    struct variable var[2000];
    int varCnt = 0;


    int *temporayIntegerArray;
    int temporayArrayLength = 0;
    double *temporaryDoubleArray;
    char **temporaryCharArray;

    int temporaryInteger = -1;
    double temporaryDouble = -1.0;
    char* temporaryChar;
    double choiceValue; /* stores the value of choice to check in options. */

    int ifelseCondtionMatchNumber = 0; // this is for checking which conditon has been matched

    typedef struct functionStruct{
        char *FuncName;
        tmp *varPtr; 
        int varCnt ;
        int retType ; 
    }pre;

    struct functionStruct fvar[200];
    int fvarCnt = 0;
    int functionNotCorrect = 0;
    char* temporaryFunctionName;
    int temporaryFunctionReturnType = 0;

    struct variable* temVarPointer;
    int temVarPointerCount  = 0;

    int currentFunction = 0;
    int functionRejected = 0;
  

     /* Print value of a varible  */
        void showValueOfTheVariable (int id){
            if (var[id].isArray) {
       
    } else {
        // Print the value based on the variable type
        if (var[id].type == 0){
            printf("%d\n", var[id].ival[0]);
        }
        else if (var[id].type == 1){
            printf("%lf\n", var[id].dval[0]);
        }
        else {
            printf("%s\n", var[id].sval[0]);
        }
    }
        }

    // this is checking it is an real type expression or double type k = 1 mean int k = 2 mean real
        void setTemporaryValue(int k){
            temporay = k;
        }
        int getTemporaryValue(){
            return temporay;
        } 

    /* Checks if a variable is already declared. */
        int checkExistance(char *varName){
            for(int i = 0 ; i<varCnt; i++){
                if(strcmp(var[i].name,varName)==0){
                    return 1;
                }
            }
            return 0;
        }
    
    /* Get the index of variable that is called. If not found return -1. */
        int getVariableIndex(char *varName){
            for(int i = 0 ; i<varCnt; i++){
                if(strcmp(var[i].name,varName)==0){
                    return i;
                }
            }
            return -1;
        }
    
    // this will return function variable index
        int getFunctionIndex(char *varName){
            for(int i = 0 ; i<fvarCnt; i++){
                if(strcmp(fvar[i].FuncName,varName)==0){
                    return i;
                }
            }
            return -1;
        }

    

    // create a new integer type variable or array varibale of integer type
         void createNewIntegerTypeVarible (char *varname,void* value,int type,int id,int size,int isArray){
            var[id].name = varname;
            var[id].size = size;
            var[id].isArray = isArray;
            
            int *x = ((int*)value);
            var[id].ival = malloc(size*sizeof(int));
            for(int i=0;i<size;i++){
                var[id].ival[i] = x[i];
            }
            var[id].type = 0;
        }
    
    // create a new real type variable or array varibale of real type
        void createNewRealTypeVarible (char *varname,void* value,int type,int id,int size,int isArray){
            var[id].name = varname;
            var[id].size = size;
            var[id].isArray = isArray;
            
            double* x = ((double*)value);
            var[id].dval = malloc(size*sizeof(double));
            for(int i=0;i<size;i++){
                var[id].dval[i] = x[i];
            }
            var[id].type = 1;
        }
    
    // create a new string type variable or array variable of string type
        void createNewStringTypeVariable (char *varname,void* value,int type,int id,int size,int isArray){
            var[id].name = varname;
            var[id].size = size;
            var[id].isArray = isArray;
            
            char **s =((char**)value);
            var[id].sval = malloc(size*sizeof(char**));
            for(int i=0;i<size;i++){
                var[id].sval[i] = s[i];
            }
            var[id].type = 2;
        }
    
   

    // take input form the user 
        void takeInputFromUser (int id){
            if (var[id].type==0){
                scanf("%d",&var[id].ival[0]);
                printf("Scanned Integer value is: %d\n",var[id].ival[0]);
            }
            else if (var[id].type==1){
                scanf("%lf",&var[id].dval[0]);
                printf("Scanned Double value is: %lf\n",var[id].dval[0]);
            }
            else {
                char demoStr[2000];
                scanf("%s",&var[id].sval[0]);
                printf("Scanned String value is: %s\n",var[id].sval);
            }
        }
    

    // Error Handleing function

    void assignmentError (char *varName){
        printf("Your are trying to assign wrong value type in wrong type of varibale\n");
    }

   
   
    /* Flex handling */
    extern FILE *yyin, *yyout;
	int yylex();
	int yyparse();
	int yyerror(char *s);



/* Line 189 of yacc.c  */
#line 267 "mainCode.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     REAL = 259,
     STRING = 260,
     INT_ARRAY = 261,
     DOUBLE_ARRAY = 262,
     STRING_ARRAY = 263,
     EOL = 264,
     VARIABLE = 265,
     INPUT = 266,
     EQL = 267,
     NOTEQL = 268,
     LESSEQL = 269,
     GREATEREQL = 270,
     SHOW = 271,
     APPEND = 272,
     AND = 273,
     OR = 274,
     MXOR = 275,
     MAND = 276,
     MOR = 277,
     NOT = 278,
     MNOT = 279,
     SIN = 280,
     COS = 281,
     TAN = 282,
     SQRT = 283,
     LOG = 284,
     LOG2 = 285,
     LN = 286,
     DOUBLEMINUS = 287,
     DOUBLEPLUS = 288,
     VOID = 289,
     IF = 290,
     ELIF = 291,
     ELSE = 292,
     FOR = 293,
     IN = 294,
     SCOPE = 295,
     WHILE = 296,
     SWITCH = 297,
     CASE = 298,
     DEFAULT = 299,
     DEFINE = 300,
     CALL = 301,
     ARROW = 302,
     COMMENT = 303,
     POP = 304,
     SORT = 305
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 195 "mainCode.y"

	int integer;
    double real;
    char* string;



/* Line 214 of yacc.c  */
#line 361 "mainCode.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 373 "mainCode.tab.c"

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
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   614

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  214

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    57,     2,     2,
      58,    59,    55,    53,    60,    54,     2,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,     2,
      51,    61,    52,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    63,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,     2,    65,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    36,    40,    42,
      46,    48,    53,    57,    59,    63,    70,    77,    81,    83,
      94,    96,   100,   102,   106,   110,   112,   114,   116,   122,
     124,   128,   130,   132,   136,   143,   144,   146,   149,   151,
     156,   159,   161,   169,   182,   197,   205,   213,   215,   218,
     220,   225,   228,   230,   238,   240,   242,   244,   247,   250,
     254,   258,   262,   266,   270,   274,   278,   282,   286,   290,
     294,   298,   302,   306,   309,   313,   318,   323,   328,   333,
     338,   343,   346
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      68,     0,    -1,    69,    -1,    -1,    69,    70,    -1,     9,
      -1,    48,    -1,    73,    -1,    71,    -1,    75,    -1,    86,
      -1,    92,    -1,    93,    -1,    94,    -1,    76,    -1,    82,
      -1,    16,    58,    72,    59,    -1,    72,    60,    10,    -1,
      10,    -1,    72,    60,     5,    -1,     5,    -1,    11,    58,
      74,    59,    -1,    74,    60,    10,    -1,    10,    -1,    10,
      61,   100,    -1,    10,    62,     3,    63,    61,   100,    -1,
      10,    62,     3,    63,    61,     5,    -1,    10,    61,     5,
      -1,    77,    -1,    45,    78,    58,    79,    59,    47,    81,
      64,    70,    65,    -1,    10,    -1,    79,    60,    80,    -1,
      80,    -1,    10,    66,     6,    -1,    10,    66,     7,    -1,
       6,    -1,     7,    -1,    34,    -1,    46,    83,    58,    84,
      59,    -1,    10,    -1,    84,    60,    85,    -1,    85,    -1,
      10,    -1,    35,    87,    88,    -1,    58,   100,    59,    64,
      69,    65,    -1,    -1,    90,    -1,    90,    89,    -1,    89,
      -1,    37,    64,    69,    65,    -1,    90,    91,    -1,    91,
      -1,    36,    58,   100,    59,    64,    69,    65,    -1,    38,
      10,    39,    40,    58,     3,    66,     3,    59,    64,    69,
      65,    -1,    38,    10,    39,    40,    58,     3,    66,     3,
      66,     3,    59,    64,    69,    65,    -1,    41,    58,   100,
      59,    64,    69,    65,    -1,    42,    58,    95,    59,    64,
      96,    65,    -1,    10,    -1,    98,    97,    -1,    97,    -1,
      44,    64,    69,    65,    -1,    98,    99,    -1,    99,    -1,
      43,    58,   100,    59,    64,    69,    65,    -1,     3,    -1,
       4,    -1,    10,    -1,    53,   100,    -1,    54,   100,    -1,
     100,    53,   100,    -1,   100,    54,   100,    -1,   100,    55,
     100,    -1,   100,    56,   100,    -1,   100,    57,   100,    -1,
     100,    51,   100,    -1,   100,    52,   100,    -1,   100,    14,
     100,    -1,   100,    15,   100,    -1,   100,    12,   100,    -1,
     100,    13,   100,    -1,   100,    18,   100,    -1,   100,    19,
     100,    -1,   100,    20,   100,    -1,    23,   100,    -1,    58,
     100,    59,    -1,    25,    58,   100,    59,    -1,    26,    58,
     100,    59,    -1,    27,    58,   100,    59,    -1,    29,    58,
     100,    59,    -1,    30,    58,   100,    59,    -1,    28,    58,
     100,    59,    -1,    10,    33,    -1,    10,    32,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   226,   226,   230,   231,   235,   236,   237,   238,   239,
     241,   243,   244,   245,   246,   247,   254,   258,   268,   278,
     282,   291,   295,   309,   326,   387,   421,   437,   463,   475,
     494,   507,   508,   511,   529,   550,   554,   559,   566,   591,
     601,   602,   605,   618,   621,   633,   634,   635,   636,   638,
     656,   657,   660,   679,   686,   699,   712,   718,   732,   733,
     736,   747,   748,   751,   774,   780,   785,   803,   807,   811,
     815,   819,   823,   827,   832,   836,   840,   844,   848,   852,
     856,   860,   864,   868,   872,   876,   881,   885,   889,   893,
     897,   901,   920
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "REAL", "STRING", "INT_ARRAY",
  "DOUBLE_ARRAY", "STRING_ARRAY", "EOL", "VARIABLE", "INPUT", "EQL",
  "NOTEQL", "LESSEQL", "GREATEREQL", "SHOW", "APPEND", "AND", "OR", "MXOR",
  "MAND", "MOR", "NOT", "MNOT", "SIN", "COS", "TAN", "SQRT", "LOG", "LOG2",
  "LN", "DOUBLEMINUS", "DOUBLEPLUS", "VOID", "IF", "ELIF", "ELSE", "FOR",
  "IN", "SCOPE", "WHILE", "SWITCH", "CASE", "DEFAULT", "DEFINE", "CALL",
  "ARROW", "COMMENT", "POP", "SORT", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'('", "')'", "','", "'='", "'['", "']'", "'{'", "'}'",
  "':'", "$accept", "program", "starting", "mainRules", "show",
  "showExpression", "input", "inputExpression", "declaration",
  "function_block", "module_declare", "funtion_name", "function_variable",
  "single_var", "return_type", "function_call", "user_module_name",
  "user_parameters", "single_param", "if_blocks", "if_block", "else_block",
  "single_else", "elif_block", "single_elif", "for_block", "while_block",
  "switch_block", "choice_variable", "options", "default", "optionlist",
  "option", "expression", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,    60,    62,    43,    45,    42,    47,    37,    40,    41,
      44,    61,    91,    93,   123,   125,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    71,    72,    72,    72,
      72,    73,    74,    74,    75,    75,    75,    75,    76,    77,
      78,    79,    79,    80,    80,    81,    81,    81,    82,    83,
      84,    84,    85,    86,    87,    88,    88,    88,    88,    89,
      90,    90,    91,    92,    92,    93,    94,    95,    96,    96,
      97,    98,    98,    99,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     3,     1,     3,
       1,     4,     3,     1,     3,     6,     6,     3,     1,    10,
       1,     3,     1,     3,     3,     1,     1,     1,     5,     1,
       3,     1,     1,     3,     6,     0,     1,     2,     1,     4,
       2,     1,     7,    12,    14,     7,     7,     1,     2,     1,
       4,     2,     1,     7,     1,     1,     1,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     4,     4,     4,     4,     4,
       4,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     4,     8,     7,     9,    14,
      28,    15,    10,    11,    12,    13,     0,     0,     0,     0,
       0,    45,     0,     0,     0,    30,     0,    39,     0,    64,
      65,    27,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,     0,    23,     0,    20,    18,     0,
       0,     0,     0,    43,    48,    46,    51,     0,     0,    57,
       0,     0,     0,    92,    91,    83,     0,     0,     0,     0,
       0,     0,    67,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,    16,     0,     0,     0,     3,    47,    50,     0,
       0,     0,     0,     0,    32,    42,     0,    41,     0,     0,
       0,     0,     0,     0,    84,    78,    79,    76,    77,    80,
      81,    82,    74,    75,    69,    70,    71,    72,    73,     0,
      22,    19,    17,     3,     0,     0,     0,     3,     0,     0,
       0,     0,    38,     0,    85,    86,    87,    90,    88,    89,
      26,    25,     0,     0,    49,     0,     0,     0,     0,     0,
      59,     0,    62,    33,    34,     0,    31,    40,    44,     3,
       0,    55,     0,     3,    56,    58,    61,    35,    36,    37,
       0,     0,     0,     0,     0,     0,    52,     0,     0,     0,
      60,     0,     3,     0,     3,    29,     0,     0,     0,    53,
       3,    63,     0,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    15,    16,    59,    17,    56,    18,    19,
      20,    36,   113,   114,   190,    21,    38,   116,   117,    22,
      31,    63,    64,    65,    66,    23,    24,    25,    70,   169,
     170,   171,   172,    53
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -106
static const yytype_int16 yypact[] =
{
    -106,    14,    -5,  -106,  -106,   -43,   -42,   -35,   -24,    19,
     -19,    15,    79,    81,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,   255,    87,    82,     5,
     300,     8,    57,   300,    88,  -106,    43,  -106,    44,  -106,
    -106,  -106,    -1,   300,    45,    46,    48,    50,    53,    54,
     300,   300,   300,   530,    52,  -106,    10,  -106,  -106,    12,
     319,    58,    59,  -106,  -106,     8,  -106,    91,   329,  -106,
      62,   114,   117,  -106,  -106,   548,   300,   300,   300,   300,
     300,   300,    -3,    -3,   347,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,    67,
    -106,   126,  -106,     7,    74,   300,  -106,  -106,  -106,    83,
      75,    78,    77,    17,  -106,  -106,    20,  -106,   377,   395,
     404,   425,   452,   473,  -106,   -29,   -29,   -29,   -29,   548,
     548,   557,   -29,   -29,    -3,    -3,  -106,  -106,  -106,   292,
    -106,  -106,  -106,  -106,   482,    72,   141,  -106,    41,    80,
      98,   114,  -106,   117,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,   530,    84,    86,  -106,    85,   124,    89,    93,    95,
    -106,    41,  -106,  -106,  -106,     1,  -106,  -106,  -106,  -106,
     143,  -106,   300,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
      94,   145,   -57,   500,   166,    -5,  -106,    99,   150,   100,
    -106,   102,  -106,   109,  -106,  -106,   187,   107,   208,  -106,
    -106,  -106,   229,  -106
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -106,  -106,  -105,   -47,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,    22,  -106,  -106,  -106,  -106,    21,  -106,
    -106,  -106,   113,  -106,   116,  -106,  -106,  -106,  -106,  -106,
      13,  -106,    23,   -30
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      60,   145,   197,    68,     4,     5,     6,   187,   188,   198,
      57,     7,   141,    75,     3,    58,    28,   142,    26,    27,
      82,    83,    84,    29,    94,    95,    96,    97,    98,    32,
       8,    73,    74,     9,    30,   189,    10,    11,   162,    33,
      12,    13,   166,    14,    61,    62,   118,   119,   120,   121,
     122,   123,    96,    97,    98,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   100,
     101,   102,   103,    34,   191,   144,   150,   151,   194,   152,
     153,     4,     5,     6,   167,   168,   173,   174,     7,    35,
      54,    37,    55,     4,     5,     6,    67,   206,    69,   208,
       7,    71,    72,    76,    77,   212,    78,     8,    79,   161,
       9,    80,    81,    10,    11,    99,   105,    12,    13,     8,
      14,   111,     9,   106,   112,    10,    11,   115,   139,    12,
      13,   109,    14,     4,     5,     6,   140,   164,   143,   147,
       7,   146,   148,   149,   165,   175,   192,   182,   201,   178,
     179,   180,   193,   203,     4,     5,     6,   183,   195,     8,
     184,     7,     9,   202,   204,    10,    11,   205,   207,    12,
      13,   210,    14,   176,   177,     4,     5,     6,   107,     0,
       8,   108,     7,     9,   185,     0,    10,    11,     0,   181,
      12,    13,     0,    14,   186,     0,     4,     5,     6,     0,
       0,     8,     0,     7,     9,     0,     0,    10,    11,     0,
     196,    12,    13,     0,    14,     0,     0,     4,     5,     6,
       0,     0,     8,     0,     7,     9,     0,     0,    10,    11,
       0,   200,    12,    13,     0,    14,     0,     0,     4,     5,
       6,     0,     0,     8,     0,     7,     9,     0,     0,    10,
      11,     0,   209,    12,    13,     0,    14,     0,    39,    40,
      41,     0,     0,     0,     8,    42,     0,     9,     0,     0,
      10,    11,     0,   211,    12,    13,     0,    14,    43,     0,
      44,    45,    46,    47,    48,    49,     0,     0,     0,     0,
       0,     0,     0,     0,   213,    39,    40,   160,     0,     0,
       0,     0,    42,    39,    40,     0,     0,     0,    50,    51,
      42,     0,     0,    52,     0,    43,     0,    44,    45,    46,
      47,    48,    49,    43,     0,    44,    45,    46,    47,    48,
      49,    85,    86,    87,    88,     0,     0,    89,    90,    91,
       0,    85,    86,    87,    88,    50,    51,    89,    90,    91,
      52,     0,     0,    50,    51,     0,     0,     0,    52,    85,
      86,    87,    88,     0,     0,    89,    90,    91,     0,     0,
      92,    93,    94,    95,    96,    97,    98,     0,   104,     0,
      92,    93,    94,    95,    96,    97,    98,     0,   110,    85,
      86,    87,    88,     0,     0,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,     0,   124,    85,    86,    87,
      88,     0,     0,    89,    90,    91,    85,    86,    87,    88,
       0,     0,    89,    90,    91,     0,     0,     0,    92,    93,
      94,    95,    96,    97,    98,     0,   154,    85,    86,    87,
      88,     0,     0,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,   155,    92,    93,    94,    95,    96,
      97,    98,     0,   156,    85,    86,    87,    88,     0,     0,
      89,    90,    91,     0,     0,     0,    92,    93,    94,    95,
      96,    97,    98,     0,   157,    85,    86,    87,    88,     0,
       0,    89,    90,    91,    85,    86,    87,    88,     0,     0,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,   158,    85,    86,    87,    88,     0,     0,    89,    90,
      91,     0,     0,     0,    92,    93,    94,    95,    96,    97,
      98,     0,   159,    92,    93,    94,    95,    96,    97,    98,
       0,   163,    85,    86,    87,    88,     0,     0,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,     0,   199,
      85,    86,    87,    88,     0,     0,     0,     0,    91,    85,
      86,    87,    88,     0,     0,     0,     0,     0,     0,     0,
       0,    92,    93,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
      93,    94,    95,    96,    97,    98,     0,     0,    92,    93,
      94,    95,    96,    97,    98
};

static const yytype_int16 yycheck[] =
{
      30,   106,    59,    33,     9,    10,    11,     6,     7,    66,
       5,    16,     5,    43,     0,    10,    58,    10,    61,    62,
      50,    51,    52,    58,    53,    54,    55,    56,    57,    10,
      35,    32,    33,    38,    58,    34,    41,    42,   143,    58,
      45,    46,   147,    48,    36,    37,    76,    77,    78,    79,
      80,    81,    55,    56,    57,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    59,
      60,    59,    60,    58,   179,   105,    59,    60,   183,    59,
      60,     9,    10,    11,    43,    44,     6,     7,    16,    10,
       3,    10,    10,     9,    10,    11,    39,   202,    10,   204,
      16,    58,    58,    58,    58,   210,    58,    35,    58,   139,
      38,    58,    58,    41,    42,    63,    58,    45,    46,    35,
      48,    59,    38,    64,    10,    41,    42,    10,    61,    45,
      46,    40,    48,     9,    10,    11,    10,    65,    64,    64,
      16,    58,    64,    66,     3,    47,     3,    58,   195,    65,
      64,    66,   182,     3,     9,    10,    11,    64,    64,    35,
      65,    16,    38,    64,    64,    41,    42,    65,    59,    45,
      46,    64,    48,   151,   153,     9,    10,    11,    65,    -1,
      35,    65,    16,    38,   171,    -1,    41,    42,    -1,    65,
      45,    46,    -1,    48,   171,    -1,     9,    10,    11,    -1,
      -1,    35,    -1,    16,    38,    -1,    -1,    41,    42,    -1,
      65,    45,    46,    -1,    48,    -1,    -1,     9,    10,    11,
      -1,    -1,    35,    -1,    16,    38,    -1,    -1,    41,    42,
      -1,    65,    45,    46,    -1,    48,    -1,    -1,     9,    10,
      11,    -1,    -1,    35,    -1,    16,    38,    -1,    -1,    41,
      42,    -1,    65,    45,    46,    -1,    48,    -1,     3,     4,
       5,    -1,    -1,    -1,    35,    10,    -1,    38,    -1,    -1,
      41,    42,    -1,    65,    45,    46,    -1,    48,    23,    -1,
      25,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,     3,     4,    -1,    -1,    -1,    53,    54,
      10,    -1,    -1,    58,    -1,    23,    -1,    25,    26,    27,
      28,    29,    30,    23,    -1,    25,    26,    27,    28,    29,
      30,    12,    13,    14,    15,    -1,    -1,    18,    19,    20,
      -1,    12,    13,    14,    15,    53,    54,    18,    19,    20,
      58,    -1,    -1,    53,    54,    -1,    -1,    -1,    58,    12,
      13,    14,    15,    -1,    -1,    18,    19,    20,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    -1,    59,    -1,
      51,    52,    53,    54,    55,    56,    57,    -1,    59,    12,
      13,    14,    15,    -1,    -1,    18,    19,    20,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    12,    13,    14,
      15,    -1,    -1,    18,    19,    20,    12,    13,    14,    15,
      -1,    -1,    18,    19,    20,    -1,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    12,    13,    14,
      15,    -1,    -1,    18,    19,    20,    51,    52,    53,    54,
      55,    56,    57,    -1,    59,    51,    52,    53,    54,    55,
      56,    57,    -1,    59,    12,    13,    14,    15,    -1,    -1,
      18,    19,    20,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    -1,    59,    12,    13,    14,    15,    -1,
      -1,    18,    19,    20,    12,    13,    14,    15,    -1,    -1,
      18,    19,    20,    51,    52,    53,    54,    55,    56,    57,
      -1,    59,    12,    13,    14,    15,    -1,    -1,    18,    19,
      20,    -1,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    -1,    59,    51,    52,    53,    54,    55,    56,    57,
      -1,    59,    12,    13,    14,    15,    -1,    -1,    18,    19,
      20,    51,    52,    53,    54,    55,    56,    57,    -1,    59,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    20,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    68,    69,     0,     9,    10,    11,    16,    35,    38,
      41,    42,    45,    46,    48,    70,    71,    73,    75,    76,
      77,    82,    86,    92,    93,    94,    61,    62,    58,    58,
      58,    87,    10,    58,    58,    10,    78,    10,    83,     3,
       4,     5,    10,    23,    25,    26,    27,    28,    29,    30,
      53,    54,    58,   100,     3,    10,    74,     5,    10,    72,
     100,    36,    37,    88,    89,    90,    91,    39,   100,    10,
      95,    58,    58,    32,    33,   100,    58,    58,    58,    58,
      58,    58,   100,   100,   100,    12,    13,    14,    15,    18,
      19,    20,    51,    52,    53,    54,    55,    56,    57,    63,
      59,    60,    59,    60,    59,    58,    64,    89,    91,    40,
      59,    59,    10,    79,    80,    10,    84,    85,   100,   100,
     100,   100,   100,   100,    59,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,    61,
      10,     5,    10,    64,   100,    69,    58,    64,    64,    66,
      59,    60,    59,    60,    59,    59,    59,    59,    59,    59,
       5,   100,    69,    59,    65,     3,    69,    43,    44,    96,
      97,    98,    99,     6,     7,    47,    80,    85,    65,    64,
      66,    65,    58,    64,    65,    97,    99,     6,     7,    34,
      81,    69,     3,   100,    69,    64,    65,    59,    66,    59,
      65,    70,    64,     3,    64,    65,    69,    59,    69,    65,
      64,    65,    69,    65
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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

/* Line 1455 of yacc.c  */
#line 226 "mainCode.y"
    {;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 230 "mainCode.y"
    {/*this is for nothing*/;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 235 "mainCode.y"
    {;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 236 "mainCode.y"
    {;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 237 "mainCode.y"
    {;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 238 "mainCode.y"
    {;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 239 "mainCode.y"
    {;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 242 "mainCode.y"
    {ifelseCondtionMatchNumber=0;;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 243 "mainCode.y"
    {;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 244 "mainCode.y"
    {;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 245 "mainCode.y"
    {;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 246 "mainCode.y"
    {;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 247 "mainCode.y"
    {;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 254 "mainCode.y"
    {;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 259 "mainCode.y"
    {
                    int id = getVariableIndex((yyvsp[(3) - (3)].string));
                    if (id!=-1){
                        showValueOfTheVariable(id);
                    }
                    else {
                        printf("Variable is not declared yet\n");
                    }
                ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 269 "mainCode.y"
    {
                    int id = getVariableIndex((yyvsp[(1) - (1)].string));
                    if (id!=-1){
                        showValueOfTheVariable(id);
                    }
                    else {
                        printf("Variable is not declared yet\n");
                    }
                ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 279 "mainCode.y"
    {
                    printf("%s\n",(yyvsp[(3) - (3)].string));
                ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 283 "mainCode.y"
    {
                    printf("%s\n",(yyvsp[(1) - (1)].string));
                ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 291 "mainCode.y"
    {;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 296 "mainCode.y"
    {
        int ch = checkExistance((yyvsp[(3) - (3)].string));
        if (ch){
            int id = getVariableIndex((yyvsp[(3) - (3)].string));
            takeInputFromUser(id);
        }
        else {
           char value[2000]="\n";
           createNewStringTypeVariable((yyvsp[(3) - (3)].string),&value,2,varCnt,1,0);
            printf("Automatically defined as a string. The variable is %s\n", var[varCnt - 1].name);
            takeInputFromUser(varCnt - 1);
        }
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 310 "mainCode.y"
    {
        int ch = checkExistance((yyvsp[(1) - (1)].string));
        if (ch){
            int id = getVariableIndex((yyvsp[(1) - (1)].string));
            takeInputFromUser(id);
        }
        else {
           char value[2000]="\n";
            createNewStringTypeVariable((yyvsp[(1) - (1)].string),&value,2,varCnt,1,0);
            printf("Automatically defined as a string. The variable is %s\n", var[varCnt - 1].name);
            takeInputFromUser(varCnt - 1);
        }
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 327 "mainCode.y"
    {
                    int k = checkExistance((yyvsp[(1) - (3)].string));
                    if (k){
                        // this variable has been declared already
                        if (getTemporaryValue()==1){
                            // this is integer
                            int id = getVariableIndex((yyvsp[(1) - (3)].string));
                            if (var[id].type==2 || var[id].isArray){
                                assignmentError((yyvsp[(1) - (3)].string));
                            }
                            else {
                                if (var[id].type==1){
                                    printf("Implicitly convert the value into real type and assign the value\n");
                                    var[id].dval[0] = (yyvsp[(3) - (3)].real);
                                }
                                else {
                                    var[id].ival[0] = (yyvsp[(3) - (3)].real);
                                }
                            }
                        }
                        else {
                            // this is real type
                            int id = getVariableIndex((yyvsp[(1) - (3)].string));
                            if (var[id].type==2 || var[id].isArray){
                                assignmentError((yyvsp[(1) - (3)].string));
                            }
                            else {
                                if (var[id].type==0){
                                    printf("Implicitly convert the integer type variable into real type and assign the value\n");
                                    var[id].dval = malloc(1*sizeof(double));
                                    var[id].dval[0] = (yyvsp[(3) - (3)].real);
                                    var[id].type = 1;
                                    var[id].ival = NULL;
                                }
                                else {
                                    var[id].dval[0] = (yyvsp[(3) - (3)].real);
                                }
                            }
                        }
                        setTemporaryValue(-1);
                    }
                    else {
                        // this is a new variable
                        if (getTemporaryValue()==1){
                            // this is interger
                            int value = (yyvsp[(3) - (3)].real);
                            createNewIntegerTypeVarible((yyvsp[(1) - (3)].string),&value,0,varCnt,1,0);
                            printf("New Integer type variable has been declared\n");
                            varCnt++;
                        }
                        else {
                            // this is real type
                            double value = (yyvsp[(3) - (3)].real);
                            createNewRealTypeVarible((yyvsp[(1) - (3)].string),&value,1,varCnt,1,0);
                            printf("New Double type variable has been declared\n");
                            varCnt++;
                        }
                        setTemporaryValue(-1);
                    }
                ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 388 "mainCode.y"
    {
                    int id = getVariableIndex((yyvsp[(1) - (6)].string));
                    int t = getTemporaryValue();
                    int idx = (yyvsp[(3) - (6)].integer);
                    if (t==1){
                        if (var[id].type==0){
                            if (var[id].size<=idx){
                                printf("Index out of bound\n");
                            }
                            else {
                                var[id].ival[idx] = (yyvsp[(6) - (6)].real);
                            }
                        }
                        else {
                            printf("Type does not matched\n");
                        }
                    }
                    else if (t==2){
                        if (var[id].type==2){
                            printf("Type does not matched\n");
                        }
                        else {
                            if (var[id].size<=idx){
                                printf("Index out of bound\n");
                            }
                            else {
                                var[id].dval[idx] = (yyvsp[(6) - (6)].real);
                            }
                        }
                    }

                    setTemporaryValue(-1);
                ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 422 "mainCode.y"
    {
                    int id = getVariableIndex((yyvsp[(1) - (6)].string));
                    int idx = (yyvsp[(3) - (6)].integer);
                    if (var[id].type!=2){
                        printf("Type does not matched\n");
                    }
                    else {
                        if (var[id].size<=idx){
                            printf("Out of bound\n");
                        }
                        else {
                            var[id].sval[idx] = (yyvsp[(6) - (6)].string);
                        }
                    }
                ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 438 "mainCode.y"
    {
                    int k = checkExistance((yyvsp[(1) - (3)].string));
                    if (k){
                        int id = getVariableIndex((yyvsp[(1) - (3)].string));
                        if (var[id].type!=2){
                            assignmentError((yyvsp[(1) - (3)].string));
                        }
                        else {
                            var[id].sval[0] = (yyvsp[(3) - (3)].string);
                        }
                    }
                    else{
                        char *value = (yyvsp[(3) - (3)].string);
                        createNewStringTypeVariable((yyvsp[(1) - (3)].string),&value,2,varCnt,1,0);
                        varCnt++;
                        printf("New string type variable has been declared\n");
                    }
                ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 464 "mainCode.y"
    {
                    if (!functionNotCorrect){
                        printf("New Function Declared-\n");
                        // for (int i=0;i<fvar[fvarCnt-1].varCnt;i++){
                        //     printf("%s\n", fvar[fvarCnt-1].varPtr[i].name);
                        // }
                    }
                ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 476 "mainCode.y"
    {
                    
                    fvar[fvarCnt].FuncName = temporaryFunctionName;
                    fvar[fvarCnt].varCnt = temVarPointerCount;

                    fvar[fvarCnt].varPtr = realloc(fvar[fvarCnt].varPtr, temVarPointerCount*sizeof(var[0]));
                    for (int i=0;i<temVarPointerCount; i++){
                        fvar[fvarCnt].varPtr[i] = temVarPointer[i];
                    }
                    fvar[fvarCnt].retType = temporaryFunctionReturnType;
                    

                    temVarPointerCount = 0;

                    fvarCnt++;
                ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 495 "mainCode.y"
    {
                    int id = getFunctionIndex((yyvsp[(1) - (1)].string));
                    if (id!=-1){
                        printf("Function is already decared\n");
                        functionNotCorrect = 1;
                    }
                    else {
                        temporaryFunctionName = (yyvsp[(1) - (1)].string);
                    }
                ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 512 "mainCode.y"
    {
                    int id = getVariableIndex((yyvsp[(1) - (3)].string));
                    if (id!=-1) {
                        printf("this variable is already declared\n");
                    }
                    else {
                        int value = 0;
                        createNewIntegerTypeVarible((yyvsp[(1) - (3)].string),&value,0,varCnt,1,0);
                         
                        temVarPointerCount++;

                        temVarPointer = realloc(temVarPointer,temVarPointerCount*sizeof(var[0]));
                        temVarPointer[temVarPointerCount-1] = var[varCnt];
                        varCnt++;

                    }
                ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 530 "mainCode.y"
    {
                    int id = getVariableIndex((yyvsp[(1) - (3)].string));
                    if (id!=-1) {
                        printf("this variable is already declared\n");
                    }
                    else {
                        double value = 0;
                        createNewRealTypeVarible ((yyvsp[(1) - (3)].string),&value,1,varCnt,1,0);
                        temVarPointerCount++;

                        temVarPointer = realloc(temVarPointer,temVarPointerCount*sizeof(var[0]));
                        temVarPointer[temVarPointerCount-1] = var[varCnt];
                        varCnt++;
                        
                    }
                ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 551 "mainCode.y"
    {
               temporaryFunctionReturnType = 1;
            ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 555 "mainCode.y"
    {
                temporaryFunctionReturnType = 2;
            ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 560 "mainCode.y"
    {
                temporaryFunctionReturnType = 0;
            ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 567 "mainCode.y"
    {
                    functionRejected = 0;
                    int id = currentFunction;
                    if (fvar[id].varCnt!=temVarPointerCount){
                        functionRejected = 1;
                    }
                    else {
                        for (int i=0;i<temVarPointerCount;i++){
                            if (fvar[id].varPtr[i].type!=temVarPointer[i].type){
                                functionRejected = 1;
                                break;
                            }
                        }
                    }
                    
                    if(functionRejected){
                        printf("Function was not called as declared\n");
                    }
                    else{
                        printf("Function called Successfully.\n");
                    }
                ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 592 "mainCode.y"
    {
                    int id = getFunctionIndex((yyvsp[(1) - (1)].string));
                    if(id==-1){printf(" No Function Exist with this name.");}
                    else{
                        currentFunction = id;
                    }
                ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 606 "mainCode.y"
    {
                    int id = getVariableIndex((yyvsp[(1) - (1)].string));
                    // printf("%d\n",id);
                    temVarPointerCount++;
                    temVarPointer = realloc(temVarPointer,temVarPointerCount*sizeof(var[0]));
                    temVarPointer[temVarPointerCount-1] = var[getVariableIndex((yyvsp[(1) - (1)].string))];
                ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 618 "mainCode.y"
    {;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 622 "mainCode.y"
    {
                    int isTrue = (fabs((yyvsp[(2) - (6)].real))>1e-9);
                    if(isTrue){
                        printf("Condition in if block is true.\n");
                        ifelseCondtionMatchNumber = 1;
                    }
                    else{
                        printf("Condition in if block is false.\n");
                    }
                ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 639 "mainCode.y"
    {
                    if(ifelseCondtionMatchNumber){
                        printf("Condition already fulfilled.Ignoring else block.\n");
                    }
                    else{
                        int isTrue =1;
                        if(isTrue){
                            printf("Condition in else block is true.\n");
                            ifelseCondtionMatchNumber = 1;
                        }
                        else{
                            printf("Condition in else block is false.\n");
                        }
                    }  
                ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 661 "mainCode.y"
    {
                    if(ifelseCondtionMatchNumber){
                        printf("Condition already fulfilled.Ignoring elif block.\n");
                    }
                    else{
                            int isTrue = (fabs((yyvsp[(3) - (7)].real))>1e-9);
                            if(isTrue){
                                printf("Condition in elif block is true.\n");
                                ifelseCondtionMatchNumber = 1;
                            }
                            else{
                                printf("Condition in elif block is false.\n");
                            }
                        }
                ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 680 "mainCode.y"
    {
                int s = (yyvsp[(6) - (12)].integer);
                int e = (yyvsp[(8) - (12)].integer);
                int len = (e-s);
                printf("The inner block will iterate :%d times\n",len);
            ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 687 "mainCode.y"
    {
                int s = (yyvsp[(6) - (14)].integer);
                int e = (yyvsp[(8) - (14)].integer);
                int len = 0;
                int inc = (yyvsp[(10) - (14)].integer);
                for (int i=s;i<e;i+=inc){
                    len++;
                }
                printf("The inner block will iterate :%d times\n",len);
            ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 700 "mainCode.y"
    {
                int val = (yyvsp[(3) - (7)].real);
                if (val){
                    printf("The expression given inside while is True\n");
                }
                else {
                    printf("The expression given inside while is false\n");
                }
            ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 713 "mainCode.y"
    {
                    ifelseCondtionMatchNumber = 0;
                ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 719 "mainCode.y"
    {
                    int id = getVariableIndex((yyvsp[(1) - (1)].string));
                    if(id==-1) printf("No such variable");
                    else if(var[id].type==2){
                        printf("can't assign string in choices.");
                    }
                    else if(var[id].type==0) choiceValue = var[id].ival[0];
                    else choiceValue = var[id].dval[0];
                ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 737 "mainCode.y"
    {
                    if(ifelseCondtionMatchNumber){
                        printf("Condition already fulfilled.Ignoring default option.\n");
                        }
                    else{
                        printf("Executing Default Option.No match found.\n");
                    }
                ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 752 "mainCode.y"
    {
                    if(ifelseCondtionMatchNumber){
                        printf("Condition already fulfilled.Ignoring current option\n");
                        }
                    else{
                        int isTrue = (fabs((yyvsp[(3) - (7)].real)-choiceValue)<1e-9);
                            if(isTrue){
                                printf("Option matched.\n");
                                ifelseCondtionMatchNumber = 1;
                            }
                            else{
                                printf("Condition of current option doesn't match.\n");
                            }
                    }
                ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 775 "mainCode.y"
    {
                    (yyval.real) = (yyvsp[(1) - (1)].integer);
                    if(getTemporaryValue()==-1)
                        setTemporaryValue(1);
                ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 781 "mainCode.y"
    {
                    (yyval.real) = (yyvsp[(1) - (1)].real);
                    setTemporaryValue(2);
                ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 786 "mainCode.y"
    {
                    int id = getVariableIndex((yyvsp[(1) - (1)].string));
                    if(id==-1) {
                        printf("Varibale does not exits\n");
                    }
                    else if(var[id].type==2){
                        printf("It is not a numaric variable\n");
                    }
                    else if(var[id].type==0) {
                        (yyval.real) = var[id].ival[0];
                        setTemporaryValue(1);
                    }
                    else{
                        (yyval.real) = var[id].dval[0];
                        setTemporaryValue(2);
                    }
                ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 804 "mainCode.y"
    {
                    (yyval.real) = (yyvsp[(2) - (2)].real);
                ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 808 "mainCode.y"
    {
                    (yyval.real) = -(yyvsp[(2) - (2)].real);
                ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 812 "mainCode.y"
    {
                    (yyval.real) = (yyvsp[(1) - (3)].real) + (yyvsp[(3) - (3)].real);
                ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 816 "mainCode.y"
    {
                    (yyval.real) = (yyvsp[(1) - (3)].real) - (yyvsp[(3) - (3)].real);
                ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 820 "mainCode.y"
    {
                    (yyval.real) = (yyvsp[(1) - (3)].real) * (yyvsp[(3) - (3)].real);
                ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 824 "mainCode.y"
    {
                    (yyval.real) = (yyvsp[(1) - (3)].real) / (yyvsp[(3) - (3)].real);
                ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 828 "mainCode.y"
    {

                    (yyval.real) = (int)(yyvsp[(1) - (3)].real) % (int)(yyvsp[(3) - (3)].real);
                ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 833 "mainCode.y"
    {
                    (yyval.real) = ((yyvsp[(1) - (3)].real) < (yyvsp[(3) - (3)].real));
                ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 837 "mainCode.y"
    {
                    (yyval.real) = ((yyvsp[(1) - (3)].real) > (yyvsp[(3) - (3)].real));
                ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 841 "mainCode.y"
    {
                    (yyval.real) = ((yyvsp[(1) - (3)].real) <= (yyvsp[(3) - (3)].real));
                ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 845 "mainCode.y"
    {
                    (yyval.real) = ((yyvsp[(1) - (3)].real) >= (yyvsp[(3) - (3)].real));
                ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 849 "mainCode.y"
    {
                    (yyval.real) = ((yyvsp[(1) - (3)].real) == (yyvsp[(3) - (3)].real));
                ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 853 "mainCode.y"
    {
                    (yyval.real) = ((yyvsp[(1) - (3)].real) != (yyvsp[(3) - (3)].real));
                ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 857 "mainCode.y"
    {
                    (yyval.real) = ( (yyvsp[(1) - (3)].real) && (yyvsp[(3) - (3)].real));
                ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 861 "mainCode.y"
    {
                    (yyval.real) = ((yyvsp[(1) - (3)].real) || (yyvsp[(3) - (3)].real));
                ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 865 "mainCode.y"
    {
                    (yyval.real) = ((int)(yyvsp[(1) - (3)].real) ^ (int)(yyvsp[(3) - (3)].real));
                ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 869 "mainCode.y"
    {
                    (yyval.real) = !(yyvsp[(2) - (2)].real);
                ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 873 "mainCode.y"
    {
                    (yyval.real) = (yyvsp[(2) - (3)].real);
                ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 877 "mainCode.y"
    {
                    (yyval.real) = sin((yyvsp[(3) - (4)].real));

                ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 882 "mainCode.y"
    {
                    (yyval.real) = cos((yyvsp[(3) - (4)].real));
                ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 886 "mainCode.y"
    {
                    (yyval.real) = tan((yyvsp[(3) - (4)].real));
                ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 890 "mainCode.y"
    {
                    (yyval.real) = log10((yyvsp[(3) - (4)].real));
                ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 894 "mainCode.y"
    {
                    (yyval.real) = log2((yyvsp[(3) - (4)].real));
                ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 898 "mainCode.y"
    {
                    (yyval.real) = sqrt((yyvsp[(3) - (4)].real));
                ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 902 "mainCode.y"
    {
                    int id = getVariableIndex((yyvsp[(1) - (2)].string));
                    if(id==-1) {
                        printf("Variable Does not exit\n");
                    }
                    else if(var[id].type==2) {
                        printf("This is not a numeric variable\n");
                    }
                    else if(var[id].type==1) printf("can't increment real.\n");
                    else {
                        var[id].ival[0]++;
                        (yyval.real) = var[id].ival[0];
                        if (getTemporaryValue()==-1){
                            setTemporaryValue(1);
                        }
                    }
                
                ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 921 "mainCode.y"
    {
                    int id = getVariableIndex((yyvsp[(1) - (2)].string));
                    if(id==-1) {
                        printf("Variable Does not exit\n");
                    }
                    else if(var[id].type==2) {
                        printf("This is not a numeric variable\n");
                    }
                    else if(var[id].type==1) printf("can't decrement real.\n");
                    else {
                        var[id].ival[0]--;
                        (yyval.real) = var[id].ival[0];
                        if (getTemporaryValue()==-1){
                            setTemporaryValue(1);
                        }
                    }
                ;}
    break;



/* Line 1455 of yacc.c  */
#line 2831 "mainCode.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 941 "mainCode.y"





int main(int argc, char **argv){

    FILE *fpt;
	fpt=freopen("input.txt","r", stdin);
	yyin = fpt;
	yyout=freopen("output.txt", "w", stdout);
    printf("\n\nProgram completed\n\n\n");
	yyparse();
	return 0;
} 


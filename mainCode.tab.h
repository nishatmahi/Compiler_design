
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 195 "mainCode.y"

	int integer;
    double real;
    char* string;



/* Line 1676 of yacc.c  */
#line 110 "mainCode.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;



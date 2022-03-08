/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     STRUCT = 258,
     IF = 259,
     ELSE = 260,
     AUTO = 261,
     TYPEDEF = 262,
     EXTERN = 263,
     STATIC = 264,
     REGISTER = 265,
     CONST = 266,
     VOLATILE = 267,
     VOID = 268,
     CHAR = 269,
     SHORT = 270,
     INT = 271,
     LONG = 272,
     FLOAT = 273,
     DOUBLE = 274,
     SIGNED = 275,
     UNSIGNED = 276,
     GOTO = 277,
     CONTINUE = 278,
     RETURN = 279,
     BREAK = 280,
     IDENTIFIER = 281,
     CONSTANT = 282,
     STRING_LITERAL = 283
   };
#endif
/* Tokens.  */
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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 33 "rclang.y"
{
    char *n;
    int d;
}
/* Line 1529 of yacc.c.  */
#line 110 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


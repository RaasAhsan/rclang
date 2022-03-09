/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 53 "y.tab.h"

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

#line 162 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

%{
#include <stdio.h>

int yylex(void);

void yyerror(const char *str) {
    fprintf(stderr, "error: %s\n", str);
}
%}

%token STRUCT
%token BREAK
%token ELSE
%token RETURN
%token IF
%token AUTO TYPEDEF EXTERN STATIC REGISTER
%token CONST VOLATILE

%token VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED

%token IDENTIFIER
%token INTEGER_CONSTANT
%token STRING_LITERAL

%start translation_unit

%%

translation_unit
    : external_declaration
    | translation_unit external_declaration
    ;

external_declaration
    : function_definition
    | declaration
    ;

declaration
    : declaration_specifiers ';'
    | declaration_specifiers init_declarator_list ';'
    ;

init_declarator_list
    : init_declarator
    | init_declarator_list ',' init_declarator
    ;

init_declarator
    : declarator
    | declarator '=' initializer
    ;

initializer
    : assignment_expression
    ;

function_definition
    : declaration_specifiers declarator declaration_list compound_statement 
    | declaration_specifiers declarator compound_statement 
    | declarator declaration_list compound_statement 
    | declarator compound_statement
    ;

declaration_specifiers
    : storage_class_specifier declaration_specifiers
    | storage_class_specifier
    | type_specifier declaration_specifiers
    | type_specifier 
    | type_qualifier declaration_specifiers
    | type_qualifier
    ;

storage_class_specifier
    : TYPEDEF
    | EXTERN
    | STATIC
    | AUTO
    | REGISTER
    ;

type_qualifier
    : CONST
    | VOLATILE
    ;

type_specifier
    : VOID
    | CHAR
    | SHORT
    | INT
    | LONG
    | FLOAT
    | DOUBLE
    | SIGNED
    | UNSIGNED
    ;

declarator
    : IDENTIFIER
    ;

declaration_list
    : declaration
    | declaration_list declaration
    ;

/* Statements */

statement
    : compound_statement
    ;

statement_list
    : statement
    | statement_list statement
    ;

compound_statement
    : '{' declaration_list statement_list '}'
    | '{' declaration_list '}'
    | '{' statement_list '}'
    | '{' '}'
    ;

/* Expressions */

expression
    : assignment_expression
    | expression ',' assignment_expression
    ;

assignment_expression
    : primary_expression
    ;

primary_expression
    : IDENTIFIER
    | STRING_LITERAL
    | '(' expression ')'
    ;

%%

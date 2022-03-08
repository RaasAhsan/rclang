%{
#include <stdio.h>

extern char *yytext;
int yylex(void);

void yyerror(const char *str) {
    fprintf(stderr, "error: %s\n", str);
}

int yywrap() {
    return 1;
}

%}

%code requires {
#include "ast.h"
}

%token STRUCT
%token IF ELSE
%token AUTO TYPEDEF EXTERN STATIC REGISTER
%token CONST VOLATILE

%token VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED

%token GOTO CONTINUE RETURN BREAK

%token IDENTIFIER
%token CONSTANT
%token STRING_LITERAL

%start translation_unit

%union {
    char *n;
    int d;
    identifier ident;
}

%type <n> translation_unit external_declaration
%type <ident> identifier

%%

translation_unit
    : external_declaration {
    }
    | translation_unit external_declaration
    ;

external_declaration
    : function_definition {
        printf("Processed function definition.\n");
        printf("Stuff\n");
    }
    | declaration
    ;

declaration
    : declaration_specifiers ';'
    | declaration_specifiers init_declarator_list ';' {
        
    }
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

type_qualifier_list
    : type_qualifier
    | type_qualifier_list type_qualifier
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
    : pointer direct_declarator
    | direct_declarator
    ;

pointer
    : '*' 
    | '*' type_qualifier_list  
    | '*' pointer
    | '*' type_qualifier_list pointer
    ;

direct_declarator
    : identifier
    | '(' declarator ')'
    | direct_declarator '(' parameter_type_list ')'
    | direct_declarator '(' ')'
    ;

identifier
    : IDENTIFIER {
        printf("%s\n", yytext);
        $$ = new_identifier(yytext);
    }
    ;

parameter_type_list
    : parameter_list
    ;

parameter_list
    : parameter_declaration
    | parameter_list ',' parameter_declaration
    ;

parameter_declaration
    : declaration_specifiers declarator
    | declaration_specifiers
    ;

declaration_list
    : declaration
    | declaration_list declaration
    ;

/* Statements */

statement
    : compound_statement
    | jump_statement
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

jump_statement
    : GOTO identifier ';'
    | CONTINUE ';'
    | BREAK ';'
    | RETURN expression ';'
    | RETURN ';'
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
    : identifier
    | STRING_LITERAL
    | CONSTANT
    | '(' expression ')'
    ;

%%

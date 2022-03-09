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
    translation_unit translation_unit;

    identifier ident;
    expression *expr;
    
    type_qualifier tq;
    type_specifier ts;
    storage_class_specifier scs;

    declaration declaration;
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
}

%type <translation_unit> translation_unit
%type <ident> identifier
%type <expr> expression assignment_expression primary_expression

%type <tq> type_qualifier;
%type <ts> type_specifier;
%type <scs> storage_class_specifier;

%type <declaration> declaration;
%type <declarator> declarator;
%type <decl_specifiers> declaration_specifiers;
%type <pointer> pointer;
%type <direct_declarator> direct_declarator;

%type <parameter_declaration> parameter_declaration;
%type <parameter_type_list> parameter_type_list;
%type <parameter_list> parameter_list;

%type <initializer> initializer;
%type <init_declarator_list> init_declarator_list;
%type <init_declarator> init_declarator;

%%

translation_unit
    : external_declaration
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
    : declaration_specifiers ';' {
        $$.specifiers = $1;
    }
    | declaration_specifiers init_declarator_list ';' {
        $$.specifiers = $1;
        $$.init_decls = $2;
    }
    ;

init_declarator_list
    : init_declarator {
        $$ = new_init_declarator_list($1, NULL);
    }
    | init_declarator_list ',' init_declarator {
        $$ = new_init_declarator_list($3, $1);
    }
    ;

init_declarator
    : declarator {
        $$.decl = $1;
        $$.init = NULL;
    }
    | declarator '=' initializer {
        $$.decl = $1;
        $$.init = $3;
    }
    ;

initializer
    : assignment_expression {
        $$->expr = $1;
    }
    ;

function_definition
    : declaration_specifiers declarator declaration_list compound_statement 
    | declaration_specifiers declarator compound_statement 
    | declarator declaration_list compound_statement 
    | declarator compound_statement
    ;

declaration_specifiers
    : storage_class_specifier declaration_specifiers {
        declaration_specifier spec = {.tag = DS_STORAGE_CLASS_SPECIFIER, .specifier = {.sc = $1}};
        $$ = new_declaration_specifiers(spec, $2);
    }
    | storage_class_specifier {
        declaration_specifier spec = {.tag = DS_STORAGE_CLASS_SPECIFIER, .specifier = {.sc = $1}};
        $$ = new_declaration_specifiers(spec, NULL);
    }
    | type_specifier declaration_specifiers {
        declaration_specifier spec = {.tag = DS_TYPE_SPECIFIER, .specifier = {.s = $1}};
        $$ = new_declaration_specifiers(spec, $2);
    }
    | type_specifier {
        declaration_specifier spec = {.tag = DS_TYPE_SPECIFIER, .specifier = {.s = $1}};
        $$ = new_declaration_specifiers(spec, NULL);
    }
    | type_qualifier declaration_specifiers {
        declaration_specifier spec = {.tag = DS_TYPE_QUALIFIER, .specifier = {.q = $1}};
        $$ = new_declaration_specifiers(spec, $2);
    }
    | type_qualifier {
        declaration_specifier spec = {.tag = DS_TYPE_QUALIFIER, .specifier = {.q = $1}};
        $$ = new_declaration_specifiers(spec, NULL);
    }
    ;

storage_class_specifier
    : TYPEDEF {
        $$ = SCS_TYPEDEF;
    }
    | EXTERN {
        $$ = SCS_EXTERN;
    }
    | STATIC {
        $$ = SCS_STATIC;
    }
    | AUTO {
        $$ = SCS_AUTO;
    }
    | REGISTER {
        $$ = SCS_REGISTER;
    }
    ;

type_qualifier
    : CONST {
        $$ = TQ_CONST;
    }
    | VOLATILE {
        $$ = TQ_VOLATILE;
    }
    ;

type_qualifier_list
    : type_qualifier
    | type_qualifier_list type_qualifier
    ;

type_specifier
    : VOID {
        $$.tag = TS_VOID;
    }
    | CHAR {
        $$.tag = TS_CHAR;
    }
    | SHORT {
        $$.tag = TS_SHORT;
    }
    | INT {
        $$.tag = TS_INT;
    }
    | LONG {
        $$.tag = TS_LONG;
    }
    | FLOAT {
        $$.tag = TS_FLOAT;
    }
    | DOUBLE { 
        $$.tag = TS_DOUBLE; 
    }
    | SIGNED {
        $$.tag = TS_SIGNED;
    }
    | UNSIGNED {
        $$.tag = TS_UNSIGNED;
    }
    ;

declarator
    : pointer direct_declarator {
        $$->pointer = $1;
        $$->direct_decl = $2;
    }
    | direct_declarator {
        $$->pointer = NULL;
        $$->direct_decl = $1;
    }
    ;

pointer
    : '*' {
        $$ = new_pointer(NULL);
    }
    | '*' type_qualifier_list  {
        $$ = new_pointer(NULL);
    }
    | '*' pointer {
        $$ = new_pointer($2);
    }
    | '*' type_qualifier_list pointer {
        $$ = new_pointer($3);
    }
    ;

direct_declarator
    : identifier {
        $$->tag = DDECL_IDENTIFIER;
        $$->op.identifier_decl = $1;
    }
    | '(' declarator ')' {
        $$->tag = DDECL_DECLARATOR;
        $$->op.decl = $2;
    }
    | direct_declarator '(' parameter_type_list ')' {
        $$->tag = DDECL_FUNCTION;
        $$->op.function_decl.function = $1;
        $$->op.function_decl.param_types = $3;
    }
    | direct_declarator '(' ')' {
        $$->tag = DDECL_FUNCTION;
        $$->op.function_decl.function = $1;

    }
    ;

identifier
    : IDENTIFIER {
        printf("%s\n", yytext);
        $$ = new_identifier(yytext);
    }
    ;

parameter_type_list
    : parameter_list {
        $$.params = $1;
    }
    ;

parameter_list
    : parameter_declaration {
        $$ = new_parameter_list($1, NULL);
    }
    | parameter_list ',' parameter_declaration {
        $$ = new_parameter_list($3, $1);
    }
    ;

parameter_declaration
    : declaration_specifiers declarator {
        $$.specifiers = $1;
        $$.decl = $2;
    }
    | declaration_specifiers {
        $$.specifiers = $1;
        $$.decl = NULL;
    }
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
    | expression ',' assignment_expression {
        $$ = new_multi_expression($1, $3);
    }
    ;

assignment_expression
    : primary_expression
    ;

primary_expression
    : identifier {
        $$ = new_identifier_expression($1);
    }
    | STRING_LITERAL {
        $$ = new_string_literal_expression(yytext);
    }
    | CONSTANT
    | '(' expression ')' {
        $$ = $2;
    }
    ;

%%

%{
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

%}

%code requires {
#include "ast.h"
}

%define parse.error verbose

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
}

%type <translation_unit> translation_unit
%type <external_declaration> external_declaration
%type <function_definition> function_definition

%type <ident> identifier
%type <expr> expression assignment_expression primary_expression

%type <tq> type_qualifier
%type <ts> type_specifier
%type <scs> storage_class_specifier

%type <declaration> declaration
%type <declaration_list> declaration_list
%type <declarator> declarator
%type <decl_specifiers> declaration_specifiers
%type <pointer> pointer
%type <direct_declarator> direct_declarator

%type <parameter_declaration> parameter_declaration
%type <parameter_type_list> parameter_type_list
%type <parameter_list> parameter_list

%type <initializer> initializer
%type <init_declarator_list> init_declarator_list
%type <init_declarator> init_declarator

%type <statement_list> statement_list
%type <statement> statement
%type <compound_statement> compound_statement
%type <jump_statement> jump_statement

%%

translation_unit
    : external_declaration {
        $$ = new_translation_unit($1, NULL);
    }
    | translation_unit external_declaration {
        $$ = new_translation_unit($2, $1);
    }
    ;

external_declaration
    : function_definition {
        $$.op = ED_FUNCTION_DEFINITION;
        $$.decl.func = $1;
    }
    | declaration {
        $$.op = ED_DECLARATION;
        $$.decl.decl = $1;
    }
    ;

declaration
    : declaration_specifiers ';' {
        $$ = malloc(sizeof(declaration));
        $$->specifiers = $1;
    }
    | declaration_specifiers init_declarator_list ';' {
        $$ = malloc(sizeof(declaration));
        $$->specifiers = $1;
        $$->init_decls = $2;
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
        printf("assignment\n");
        $$ = malloc(sizeof(initializer));
        $$->expr = $1;
    }
    ;

function_definition
    : declaration_specifiers declarator declaration_list compound_statement 
    | declaration_specifiers declarator compound_statement {
        $$.specifiers = $1;
        $$.declarator = $2;
        $$.statement = $3;
    }
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
        printf("found type %d\n", $1.tag);
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
        $$ = malloc(sizeof(direct_declarator));
        $$->tag = DDECL_IDENTIFIER;
        $$->op.identifier_decl = $1;
    }
    | '(' declarator ')' {
        $$ = malloc(sizeof(direct_declarator));
        $$->tag = DDECL_DECLARATOR;
        $$->op.decl = $2;
    }
    | direct_declarator '(' parameter_type_list ')' {
        $$ = malloc(sizeof(direct_declarator));
        $$->tag = DDECL_FUNCTION;
        $$->op.function_decl.function = $1;
        $$->op.function_decl.param_types = $3;
    }
    | direct_declarator '(' ')' {
        $$ = malloc(sizeof(direct_declarator));
        $$->tag = DDECL_FUNCTION;
        $$->op.function_decl.function = $1;

    }
    ;

identifier
    : IDENTIFIER {
        printf("found identifier: %s\n", yytext);
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
    : declaration {
        $$ = new_declaration_list($1, NULL);
    }
    | declaration_list declaration {
        $$ = new_declaration_list($2, $1);
    }
    ;

/* Statements */

statement
    : compound_statement {
        $$ = malloc(sizeof(statement));
        $$->tag = STMT_COMPOUND;
        $$->stmt.compound = $1;
    }
    | jump_statement {
        $$ = malloc(sizeof(statement));
        $$->tag = STMT_JUMP;
        $$->stmt.jump = $1;
    }
    ;

statement_list
    : statement {
        $$ = new_statement_list($1, NULL);
    }
    | statement_list statement {
        $$ = new_statement_list($2, $1);
    }
    ;

compound_statement
    : '{' declaration_list statement_list '}' {
        $$ = malloc(sizeof(compound_statement));
        $$->declarations = $2;
        $$->statements = $3;
    }
    | '{' declaration_list '}' {
        $$ = malloc(sizeof(compound_statement));
        $$->declarations = $2;
        $$->statements = NULL;
    }
    | '{' statement_list '}' {
        $$ = malloc(sizeof(compound_statement));
        $$->declarations = NULL;
        $$->statements = $2;
    }
    | '{' '}' {
        $$ = malloc(sizeof(compound_statement));
        $$->declarations = NULL;
        $$->statements = NULL;
    }
    ;

jump_statement
    : GOTO identifier ';' {
        $$ = malloc(sizeof(jump_statement));
        $$->tag = JUMP_GOTO;
        $$->jump.goto_ident = $2;
    }
    | CONTINUE ';' {
        $$ = malloc(sizeof(jump_statement));
        $$->tag = JUMP_CONTINUE;
    }
    | BREAK ';' {
        $$ = malloc(sizeof(jump_statement));
        $$->tag = JUMP_BREAK;
    }
    | RETURN expression ';' {
        $$ = malloc(sizeof(jump_statement));
        $$->tag = JUMP_RETURN;
        $$->jump.return_expr = $2;
    }
    | RETURN ';' {
        $$ = malloc(sizeof(jump_statement));
        $$->tag = JUMP_RETURN;
        $$->jump.return_expr = NULL;
    }
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
    | CONSTANT {
        printf("%s\n", yytext);
        $$ = malloc(sizeof(expression));
        $$->tag = EXPR_INTEGER;
        $$->op.integer_expr = 10;
    }
    | '(' expression ')' {
        $$ = $2;
    }
    ;

%%

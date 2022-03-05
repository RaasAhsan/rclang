%{
#include <stdio.h>

int yylex(void);

void yyerror(const char *str) {
    fprintf(stderr, "error: %s\n", str);
}
%}

%token AUTO
%token DOUBLE
%token INT
%token STRUCT
%token BREAK
%token ELSE
%token LONG
%token RETURN
%token IF

%token IDENTIFIER
%token INTEGER_CONSTANT
%token STRING_LITERAL

%%
return: RETURN ;
%%

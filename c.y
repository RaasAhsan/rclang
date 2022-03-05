%{
#include <stdio.h>
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

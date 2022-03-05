DIGIT             [0-9]
NONDIGIT          [A-Za-z_]
NONZERO_DIGIT     [1-9]
OCTAL_DIGIT       [0-7]

DECIMAL_CONSTANT  {NONZERO_DIGIT}({DIGIT})*
OCTAL_CONSTANT    0({OCTAL_DIGIT})*

IDENTIFIER        {NONDIGIT}({NONDIGIT}|{DIGIT})*

/* Newline and backslash are not allowed either */
STRING_LITERAL    \"[^\\"]*\"

WHITESPACE        [ \t\n]

%{
#include <stdio.h>
#include "y.tab.h"
%}

%%
return                             { return RETURN; }
register                           { return REGISTER; }
typedef                            { return TYPEDEF; }
auto                               { return AUTO; }
static                             { return STATIC; }
extern                             { return EXTERN; }
volatile                           { return VOLATILE; }
const                              { return CONST; }
void                               { return VOID; } 
char                               { return CHAR; } 
short                              { return SHORT; } 
int                                { return INT; } 
long                               { return LONG; } 
float                              { return FLOAT; }
double                             { return DOUBLE; } 
signed                             { return SIGNED; } 
unsigned                           { return UNSIGNED; }

{IDENTIFIER}                       { return IDENTIFIER; }

{DECIMAL_CONSTANT}                 { return INTEGER_CONSTANT; }
{OCTAL_CONSTANT}                   { return INTEGER_CONSTANT; }

{STRING_LITERAL}                   { return STRING_LITERAL; }

"("                                { return '('; }
")"                                { return ')'; }
"{"                                { return '{'; }
"}"                                { return '}'; }
";"                                { return ';'; }
"*"                                { return '*'; }
","                                { return ','; }
"="                                { return '='; }


{WHITESPACE}                       {}

%%

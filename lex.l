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
int                                { return INT; }
return                             { return RETURN; }

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

{WHITESPACE}                       {}

%%

#include <stdio.h>

// extern int yylex();
extern FILE* yyin;
extern int yyparse();
extern int yylex();
extern char *yytext;

extern int yydebug;

int main() {
    FILE *f = fopen("examples/main.c", "r");
    if (f == NULL) {
        perror("Failed to open file");
        return 1;
    }

    // yydebug = 1;

    yyin = f;
    yyparse();

    // int token;
    // while ((token = yylex())) {
    //     printf("%d: %s\n", token, yytext);
    // }

    fclose(f);

    return 0;
}

#include <stdio.h>

// extern int yylex();
extern FILE* yyin;
extern int yyparse();

int yywrap() {
    return 1;
}

int main() {
    FILE *f = fopen("examples/main.c", "r");
    if (f == NULL) {
        perror("Failed to open file");
        return 1;
    }

    yyin = f;
    yyparse();

    fclose(f);

    return 0;
}

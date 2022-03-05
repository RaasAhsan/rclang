#include <stdio.h>

extern int yylex();
extern FILE* yyin;

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
    int token;
    while ((token = yylex())) {
        printf("%d\n", token);
    }

    fclose(f);

    return 0;
}

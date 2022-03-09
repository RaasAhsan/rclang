#include <stdio.h>

#include "symtab.h"

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
    // yyparse();

    // int token;
    // while ((token = yylex())) {
    //     printf("%d: %s\n", token, yytext);
    // }

    symbol_table table;
    symbol_table_init(&table, NULL);
    symbol_table_insert(&table, "a", 3);
    symbol_table_insert(&table, "b", 8);

    symbol_table table2;
    symbol_table_init(&table2, &table);
    symbol_table_insert(&table2, "c", 3);
    symbol_table_insert(&table2, "b", 9);

    symbol_table_debug(&table2);

    fclose(f);

    return 0;
}

#ifndef SYMTAB_H
#define SYMTAB_H

#define TABLE_SIZE 32

#include <stdlib.h>

typedef struct symbol_table symbol_table;
typedef struct symbol_chain symbol_chain;
typedef struct symbol_entry symbol_entry;

struct symbol_table {
    symbol_chain *buckets[TABLE_SIZE];
    symbol_table *parent;
};

struct symbol_entry {
    char *key;
    int data;
};

struct symbol_chain {
    symbol_entry entry;
    symbol_chain *next;
};

void symbol_table_init(symbol_table *table, symbol_table *parent);
void symbol_table_insert(symbol_table *table, char *key, int data);
int symbol_table_search(symbol_table *table, char *key);
void symbol_table_debug(symbol_table *table);

#endif
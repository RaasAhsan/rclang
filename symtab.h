#ifndef SYMTAB_H
#define SYMTAB_H

#define TABLE_SIZE 32
#define ST_DECLARATIONS 0
#define ST_TAGS 1
#define ST_TYPEDEFS 2

#include <stdlib.h>

#include "ast.h"

typedef struct symbol_table symbol_table;
typedef struct symbol_list symbol_list;
typedef struct symbol_entry symbol_entry;
typedef struct declaration_symbol_entry declaration_symbol_entry;

struct symbol_table {
    symbol_list *symbols[3][TABLE_SIZE];
    symbol_table *parent;
};

struct symbol_entry {
    char *identifier;
};

struct declaration_symbol_entry {
    char *identifier;
    type type;
};

struct tag_symbol_entry {
    char *identifier;
    enum {
        TAG_STRUCT,
        TAG_UNION,
        TAG_ENUM
    } tag_type;
    union {

    } *tag_data;
};

struct typedef_symbol_entry {
    char *identifier;
    void *type;
};

struct symbol_list {
    symbol_entry *entry;
    symbol_list *next;
};

void symbol_table_init(symbol_table *table, symbol_table *parent);
void symbol_table_insert(symbol_table *table, int index, symbol_entry *new_entry);
symbol_entry *symbol_table_search(symbol_table *table, int index, char *identifier);
symbol_entry *symbol_table_search_nearest(symbol_table *table, int index, char *identifier);

void symbol_table_insert_declaration(symbol_table *table, declaration_symbol_entry *new_entry);
declaration_symbol_entry *symbol_table_search_declaration(symbol_table *table, char *identifier);
declaration_symbol_entry *symbol_table_search_nearest_declaration(symbol_table *table, char *identifier);

void symbol_table_debug(symbol_table *table);

#endif
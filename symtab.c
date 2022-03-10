#include "symtab.h"

#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define FNV1A_OFFSET_BASIS 2166136261
#define FNV1A_PRIME 16777619

uint32_t fnv1a_hash(char *input) {
    uint32_t hash = FNV1A_OFFSET_BASIS;
    for (size_t i = 0; i < strlen(input); i++) {
        uint8_t c = input[i];
        hash ^= c;
        hash *= FNV1A_PRIME;
    }
    return hash;
}

uint32_t hash_bucket(char *input) {
    return fnv1a_hash(input) % TABLE_SIZE;
}

void symbol_table_init(symbol_table *table, symbol_table *parent) {
    for (int t = 0; t < 3; t++) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table->symbols[t][i] = NULL;
        }
    }
    table->parent = parent;
}

void symbol_table_insert(symbol_table *table, int index, symbol_entry *new_entry) {
    symbol_list *new_list = malloc(sizeof(symbol_list));
    new_list->entry = new_entry;
    new_list->next = NULL;

    int hash = hash_bucket(new_entry->identifier);
    symbol_list *bucket = table->symbols[index][hash];
    if (bucket == NULL) {
        table->symbols[index][hash] = new_list;
        return;
    }

    while (1) {
        if (strcmp(bucket->entry->identifier, new_entry->identifier) == 0) {
            bucket->entry = new_entry;
            return;
        } else if (bucket->next == NULL) {
            bucket->next = new_list;
            return;
        }
        bucket = bucket->next;
    }
}

symbol_entry *symbol_table_search(symbol_table *table, int index, char *identifier) {
    symbol_entry *near_value = symbol_table_search_nearest(table, index, identifier);
    if (near_value == NULL && table->parent != NULL) {
        return symbol_table_search(table->parent, index, identifier);
    } else {
        return near_value;
    }
}

symbol_entry *symbol_table_search_nearest(symbol_table *table, int index, char *identifier) {
    int hash = hash_bucket(identifier);
    symbol_list *bucket = table->symbols[index][hash];
    while (bucket != NULL) {
        if (strcmp(bucket->entry->identifier, identifier) == 0) {
            return bucket->entry;
        }
        bucket = bucket->next;
    }
    return NULL;
}

void symbol_table_debug_list(symbol_list *symbols[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        symbol_list *bucket = symbols[i];
        while (bucket != NULL) {
            printf("Key: %s\n", bucket->entry->identifier);
            bucket = bucket->next;
        }
    }
}

// TODO: replace these with macros?

void symbol_table_insert_declaration(symbol_table *table, declaration_symbol_entry *new_entry) {
    symbol_table_insert(table, ST_DECLARATIONS, (symbol_entry*) new_entry);
}

declaration_symbol_entry *symbol_table_search_declaration(symbol_table *table, int index, char *identifier) {
    return (declaration_symbol_entry*) symbol_table_search_declaration(table, ST_DECLARATIONS, identifier);
}

declaration_symbol_entry *symbol_table_search_nearest_declaration(symbol_table *table, int index, char *identifier) {
    return (declaration_symbol_entry*) symbol_table_search_nearest_declaration(table, ST_DECLARATIONS, identifier);
}

void symbol_table_debug(symbol_table *table) {
    for (int i = 0; i < 3; i++) {
        symbol_table_debug_list(table->symbols[i]);
    }
    if (table->parent != NULL) {
        printf("|\n");
        symbol_table_debug(table->parent);
    }
}

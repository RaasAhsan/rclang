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
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->buckets[i] = NULL;
    }
    table->parent = parent;
}

void symbol_table_insert(symbol_table *table, char *key, int data) {
    symbol_entry entry = {.key = key, .data = data};
    symbol_chain *new_chain = malloc(sizeof(symbol_chain));
    new_chain->entry = entry;
    new_chain->next = NULL;

    int hash = hash_bucket(key);
    symbol_chain *bucket = table->buckets[hash];
    if (bucket == NULL) {
        table->buckets[hash] = new_chain;
        return;
    }

    while (1) {
        if (strcmp(bucket->entry.key, key) == 0) {
            bucket->entry.data = data;
            return;
        } else if (bucket->next == NULL) {
            bucket->next = new_chain;
            return;
        }
        bucket = bucket->next;
    }
}

int symbol_table_search(symbol_table *table, char *key) {
    int hash = hash_bucket(key);
    symbol_chain *bucket = table->buckets[hash];
    while (bucket != NULL) {
        if (strcmp(bucket->entry.key, key) == 0) {
            return bucket->entry.data;
        }
        bucket = bucket->next;
    }
    if (table->parent != NULL) {
        return symbol_table_search(table->parent, key);
    } else {
        return -1;
    }
}

void symbol_table_debug(symbol_table *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        symbol_chain *chain = table->buckets[i];
        while (chain != NULL) {
            printf("Key: %s, Data: %d\n", chain->entry.key, chain->entry.data);
            chain = chain->next;
        }
    }
    if (table->parent != NULL) {
        printf("|\n");
        symbol_table_debug(table->parent);
    }
}

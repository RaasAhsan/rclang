
#include <stdio.h>
#include <stdint.h>

#include "ast.h"
#include "symtab.h"

symbol_table *symtable;

void scope() {
    symbol_table *next = malloc(sizeof(symbol_table));
    symbol_table_init(next, symtable);
    symtable = next;
}

// Precondition: symtable is not root
void descope() {
    symtable = symtable->parent;
}

type typecheck_expression(expression *expr) {
    declaration_symbol_entry *entry;
    switch (expr->tag) {
        case EXPR_IDENTIFIER:
            entry = symbol_table_search_declaration(symtable, expr->op.identifier_expr.name);
            if (entry == NULL) {
                fprintf(stderr, "type error: undefined identifier\n");
                exit(1);
            } else {

            }
            break;
        default: 
            fprintf(stderr, "type error: unhandled expression case\n");
            exit(1);
            break;
    }
}

void typecheck_compound_statement(compound_statement *stmt) {
    scope();

    descope();
}

void typecheck_declaration(declaration *decl) {

}


const unsigned int TS_MAPPING_VOID = 1 << TS_VOID;
const unsigned int TS_MAPPING_CHAR = 1 << TS_CHAR;
const unsigned int TS_MAPPING_SHORT = 1 << TS_SHORT;
const unsigned int TS_MAPPING_INT = 1 << TS_INT;
const unsigned int TS_MAPPING_LONG = 1 << TS_LONG;
const unsigned int TS_MAPPING_FLOAT = 1 << TS_FLOAT;
const unsigned int TS_MAPPING_DOUBLE = 1 << TS_DOUBLE;
const unsigned int TS_MAPPING_SIGNED = 1 << TS_SIGNED;
const unsigned int TS_MAPPING_UNSIGNED = 1 << TS_UNSIGNED;
const unsigned int TS_MAPPING_STRUCT_OR_UNION = 1 << TS_STRUCT_OR_UNION;
const unsigned int TS_MAPPING_ENUM = 1 << TS_ENUM;
const unsigned int TS_MAPPING_TYPEDEF_NAME = 1 << TS_TYPEDEF_NAME;

// Bitmap

const unsigned int TS_BITMAP_VOID = TS_MAPPING_VOID;

const unsigned int TS_BITMAP_CHAR = TS_MAPPING_CHAR;
const unsigned int TS_BITMAP_SIGNED_CHAR = TS_MAPPING_SIGNED | TS_MAPPING_CHAR;

const unsigned int TS_BITMAP_UNSIGNED_CHAR = TS_MAPPING_UNSIGNED | TS_MAPPING_CHAR;

const unsigned int TS_BITMAP_SHORT = TS_MAPPING_SHORT;
const unsigned int TS_BITMAP_SIGNED_SHORT = TS_MAPPING_SIGNED | TS_MAPPING_SHORT;
const unsigned int TS_BITMAP_SIGNED_SHORT_INT = TS_MAPPING_SIGNED | TS_MAPPING_SHORT | TS_MAPPING_INT;

const unsigned int TS_BITMAP_UNSIGNED_SHORT = TS_MAPPING_UNSIGNED | TS_MAPPING_SHORT;
const unsigned int TS_BITMAP_UNSIGNED_SHORT_INT = TS_MAPPING_UNSIGNED | TS_MAPPING_SHORT | TS_MAPPING_INT;

const unsigned int TS_BITMAP_INT = TS_MAPPING_INT;
const unsigned int TS_BITMAP_SIGNED = TS_MAPPING_SIGNED;
const unsigned int TS_BITMAP_SIGNED_INT = TS_MAPPING_SIGNED | TS_MAPPING_INT;
const unsigned int TS_BITMAP_NONE = 0;

const unsigned int TS_BITMAP_UNSIGNED = TS_MAPPING_UNSIGNED;
const unsigned int TS_BITMAP_UNSIGNED_INT = TS_MAPPING_UNSIGNED | TS_MAPPING_INT;

const unsigned int TS_BITMAP_LONG = TS_MAPPING_LONG;
const unsigned int TS_BITMAP_SIGNED_LONG = TS_MAPPING_SIGNED | TS_MAPPING_LONG;
const unsigned int TS_BITMAP_LONG_INT = TS_MAPPING_LONG | TS_MAPPING_INT;
const unsigned int TS_BITMAP_SIGNED_LONG_INT = TS_MAPPING_SIGNED | TS_MAPPING_LONG | TS_MAPPING_INT;

const unsigned int TS_BITMAP_UNSIGNED_LONG = TS_MAPPING_UNSIGNED | TS_MAPPING_LONG;
const unsigned int TS_BITMAP_UNSIGNED_LONG_INT = TS_MAPPING_UNSIGNED | TS_MAPPING_LONG | TS_MAPPING_INT;

const unsigned int TS_BITMAP_FLOAT = TS_MAPPING_FLOAT;
const unsigned int TS_BITMAP_DOUBLE = TS_MAPPING_DOUBLE;
const unsigned int TS_BITMAP_LONG_DOUBLE = TS_MAPPING_LONG | TS_MAPPING_DOUBLE;

const unsigned int TS_BITMAP_STRUCT_OR_UNION = TS_MAPPING_STRUCT_OR_UNION;
const unsigned int TS_BITMAP_ENUM = TS_MAPPING_ENUM;
const unsigned int TS_BITMAP_TYPEDEF_NAME = TS_MAPPING_TYPEDEF_NAME;

type *get_type_from_specifiers(declaration_specifiers *specifiers) {
    uint16_t bitmap;
    union {

    } data;

    declaration_specifiers *curr = specifiers;
    while (curr != NULL) {
        switch (curr->specifier.tag) {
            case DS_TYPE_SPECIFIER: {
                unsigned long bit = (unsigned int) curr->specifier.specifier.s.tag;
                bitmap |= (1 << bit);
            }
            default: break;
        }
        curr = curr->next;
    }

    type *t = malloc(sizeof(type));
    switch (bitmap) {
        case TS_BITMAP_VOID:
            t->tag = TYPE_VOID;
            break;
        // TODO: char and signed char the same ?
        case TS_BITMAP_CHAR:
            t->tag = TYPE_CHAR;
            break;
        case TS_BITMAP_SIGNED_CHAR:
            t->tag = TYPE_SIGNED_CHAR;
            break;
        case TS_BITMAP_UNSIGNED_CHAR:
            t->tag = TYPE_UNSIGNED_CHAR;
            break;
        case TS_BITMAP_SHORT:
        case TS_BITMAP_SIGNED_SHORT:
        case TS_BITMAP_SIGNED_SHORT_INT:
            t->tag = TYPE_SHORT;
            break;
        case TS_BITMAP_UNSIGNED_SHORT:
        case TS_BITMAP_UNSIGNED_SHORT_INT:
            t->tag = TYPE_UNSIGNED_SHORT;
            break;
        case TS_BITMAP_INT:
        case TS_BITMAP_SIGNED_INT:
        case TS_BITMAP_SIGNED:
        case TS_BITMAP_NONE:
            t->tag = TYPE_INT;
            break;
        case TS_BITMAP_UNSIGNED_INT:
        case TS_BITMAP_UNSIGNED:
            t->tag = TYPE_UNSIGNED_INT;
            break;
        case TS_BITMAP_LONG:
        case TS_BITMAP_LONG_INT:
        case TS_BITMAP_SIGNED_LONG_INT:
        case TS_BITMAP_SIGNED_LONG:
            t->tag = TYPE_LONG;
            break;
        case TS_BITMAP_UNSIGNED_LONG:
        case TS_BITMAP_UNSIGNED_LONG_INT:
            t->tag = TYPE_UNSIGNED_LONG;
            break;
        case TS_BITMAP_FLOAT:
            t->tag = TYPE_FLOAT;
            break;
        case TS_BITMAP_DOUBLE:
            t->tag = TYPE_DOUBLE;
            break;
        case TS_BITMAP_LONG_DOUBLE:
            t->tag = TYPE_LONG_DOUBLE;
            break;
        case TS_STRUCT_OR_UNION:
            t->tag = TYPE_STRUCT_OR_UNION;
            break;
        case TS_ENUM:
            t->tag = TYPE_ENUM;
            break;
        case TS_TYPEDEF_NAME:
            t->tag = TYPE_TYPEDEF;
            break;
        default:
            free(t);
            t = NULL;
            break;
    }

    return t;
}

type_list *get_type_list_from_parameters(parameter_list *params) {
    if (params == NULL) {
        return NULL;
    }

    // TODO: might need to look at declarator to see if is a function type

    return new_type_list(get_type_from_specifiers(params->decl.specifiers), get_type_list_from_parameters(params->next));
}

void typecheck_function_definition(function_definition fd) {
    switch (fd.declarator->direct_decl->tag) {
        case DDECL_FUNCTION: {
            identifier function_name = fd.declarator->direct_decl->op.function_decl.function->op.identifier_decl;
            type *return_type = get_type_from_specifiers(fd.specifiers);
            type_list *argument_types = get_type_list_from_parameters(fd.declarator->direct_decl->op.function_decl.param_types.params);

            declaration_symbol_entry *entry = malloc(sizeof(declaration_symbol_entry));
            entry->identifier = function_name.name;
            entry->type = new_function_type(return_type, argument_types);

            symbol_table_insert_declaration(symtable, entry);

            break;
        }
        default:
            fprintf(stderr, "expected function declarator\n");
            exit(1);
    }

    scope();

    typecheck_compound_statement(fd.statement);

    descope();
}

void typecheck_external_declaration(external_declaration decl) {
    switch (decl.op) {
        case ED_DECLARATION:
            printf("declaration\n");
            typecheck_declaration(decl.decl.decl);
            break;
        case ED_FUNCTION_DEFINITION:
            printf("function definition\n");
            typecheck_function_definition(decl.decl.func);
            break;
        default: break;
    }
}

void typecheck_translation_unit(translation_unit *unit) {
    symtable = malloc(sizeof(symbol_table));
    symbol_table_init(symtable, NULL);

    while (unit != NULL) {
        typecheck_external_declaration(unit->decl);
        unit = unit->next;
    }
}

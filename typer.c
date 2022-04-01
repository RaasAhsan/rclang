
#include <stdio.h>

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

type *get_type_from_specifiers(declaration_specifiers *specifiers) {
    return NULL;
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

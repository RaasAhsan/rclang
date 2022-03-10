
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

void typecheck_function_definition(function_definition fd) {
    scope();

    typecheck_compound_statement(fd.statement);

    descope();
}

void typecheck_external_declaration(external_declaration decl) {
    switch (decl.op) {
        case ED_DECLARATION:
            typecheck_declaration(decl.decl.decl);
            break;
        case ED_FUNCTION_DEFINITION:
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

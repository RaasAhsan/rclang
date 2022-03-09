#include "ast.h"

#include <stdlib.h>

identifier new_identifier(char *name) {
    identifier ident = {
        .name = name
    };
    return ident;
}

expression *new_identifier_expression(identifier ident) {
    expression *expr = (expression*) malloc(sizeof(expression));
    expr->tag = EXPR_IDENTIFIER;
    expr->op.identifier_expr = ident;
    return expr;
}

expression *new_string_literal_expression(char* name) {
    expression *expr = (expression*) malloc(sizeof(expression));
    expr->tag = EXPR_STRING;
    expr->op.string_expr = name;
    return expr;
}

expression *new_multi_expression(expression *left, expression *right) {
    expression *expr = (expression*) malloc(sizeof(expression));
    expr->tag = EXPR_MULTI;
    expr->op.multi_expr.left = left;
    expr->op.multi_expr.right = right;
    return expr;
}

declaration_specifiers *new_declaration_specifiers(declaration_specifier spec, declaration_specifiers *next) {
    declaration_specifiers *head = (declaration_specifiers*) malloc(sizeof(declaration_specifiers));
    head->specifier = spec;
    head->next = next;
    return head;
}

init_declarator_list *new_init_declarator_list(init_declarator decl, init_declarator_list *next) {
    init_declarator_list *head = (init_declarator_list*) malloc(sizeof(init_declarator_list));
    head->decl = decl;
    head->next = next;
    return head;
}

parameter_list *new_parameter_list(parameter_declaration decl, parameter_list *next) {
    parameter_list *head = (parameter_list*) malloc(sizeof(parameter_list));
    head->decl = decl;
    head->next = next;
    return head;
}

pointer *new_pointer(pointer *next) {
    pointer *ptr = (pointer*) malloc(sizeof(pointer));
    ptr->next = next;
    return ptr;
}

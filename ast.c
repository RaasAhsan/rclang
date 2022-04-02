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

declaration_list *new_declaration_list(declaration decl, declaration_list *next) {
    declaration_list *head = (declaration_list*) malloc(sizeof(declaration_list));
    head->decl = decl;
    head->next = next;
    return head;
}

statement_list *new_statement_list(statement *statement, statement_list *next) {
    statement_list *head = (statement_list*) malloc(sizeof(statement_list));
    head->stmt = statement;
    head->next = next;
    return head;
}

translation_unit *new_translation_unit(external_declaration decl, translation_unit *next) {
    translation_unit *head = (translation_unit*) malloc(sizeof(translation_unit));
    head->decl = decl;
    head->next = next;
    return head;
}

pointer *new_pointer(pointer *next) {
    pointer *ptr = (pointer*) malloc(sizeof(pointer));
    ptr->next = next;
    return ptr;
}

type_list *new_type_list(type *type, type_list *next) {
    type_list *list = (type_list*) malloc(sizeof(type_list));
    list->type = type;
    list->next = next;
    return list;
}

type *new_function_type(type *return_type, type_list *argument_types) {
    type *t = (type*) malloc(sizeof(type));
    t->tag = TYPE_FUNCTION;
    t->data.function.return_type = return_type;
    t->data.function.argument_types = argument_types;
    return t;
}

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
    expr->tag = identifier_expr;
    expr->op.identifier_expr = ident;
    return expr;
}

expression *new_string_literal_expression(char* name) {
    expression *expr = (expression*) malloc(sizeof(expression));
    expr->tag = string_expr;
    expr->op.string_expr = name;
    return expr;
}

expression *new_double_expression(expression *left, expression *right) {
    expression *expr = (expression*) malloc(sizeof(expression));
    expr->tag = double_expr;
    expr->op.double_expr.left = left;
    expr->op.double_expr.right = right;
    return expr;
}

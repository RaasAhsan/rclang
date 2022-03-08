
// Reference:
// 1. https://lambda.uta.edu/cse5317/notes/node26.html
// 2. https://www.reddit.com/r/C_Programming/comments/lzq2t2/how_to_make_an_ast_in_c/

#ifndef AST_H
#define AST_H

typedef struct statement statement;
typedef struct statement_list statement_list;

typedef struct expression expression;
typedef struct expression_list expression_list;

typedef struct declaration declaration;
typedef struct declaration_list declaration_list;

typedef struct module {

} module;

typedef struct identifier {
    char *name;
} identifier;

// Expressions

#define unary_expr(name) struct { \
    expression *value; \
} name

#define binary_expr(name) struct { \
    expression *left; \
    expression *right; \
} name

#define projection_expr(name) struct { \
    expression *base; \
    identifier member; \
} name

struct expression_list {
    expression *expr;
    expression_list *next;
};

struct expression {
    enum {
        integer_expr,
        string_expr,
        identifier_expr,
        add_expr,
        subtract_expr,
        multiply_expr,
        divide_expr,
        modulo_expr,
        dereference_expr,
        reference_expr,
        double_expr
    } tag;
    union {
        int integer_expr;
        char *string_expr;
        identifier identifier_expr;
        binary_expr(add_expr);
        binary_expr(subtract_expr);
        binary_expr(multiply_expr);
        binary_expr(divide_expr);
        binary_expr(modulo_expr);
        unary_expr(dereference_expr);
        unary_expr(reference_expr);
        unary_expr(preincrement_expr);
        unary_expr(predecrement_expr);
        unary_expr(postincrement_expr);
        unary_expr(postdecrement_expr);
        unary_expr(sizeof_expr);
        struct {
            expression *func;
            expression_list args;
        } call_expr;
        projection_expr(direct_projection_expr);
        projection_expr(indirect_projection_expr);
        binary_expr(double_expr);
    } op;
};

// Statements

typedef struct {
    declaration_list *declarations;
    statement_list *statements;
} compound_statement;

typedef struct {
    enum {
        goto_stmt,
        continue_stmt,
        break_stmt,
        return_stmt
    } tag;
    union {
        identifier goto_stmt;
        expression* return_stmt;
    } op;
} jump_statement;

struct statement {
    enum {
        compound_stmt,
        jump_stmt
    } tag;
    union {
        jump_statement *jump_stmt;
        compound_statement *compound_stmt;
    } op;
};

struct statement_list {
    statement *stmt;
    statement_list *next;
};

identifier new_identifier(char *name);

expression *new_identifier_expression(identifier ident);
expression *new_string_literal_expression(char* name);
expression *new_double_expression(expression *left, expression *right);

#endif


// Reference:
// 1. https://lambda.uta.edu/cse5317/notes/node26.html
// 2. https://www.reddit.com/r/C_Programming/comments/lzq2t2/how_to_make_an_ast_in_c/

#ifndef AST_H
#define AST_H

typedef struct statement statement;
typedef struct statement_list statement_list;

typedef struct expression expression;
typedef struct expression_list expression_list;

typedef struct function_definition function_definition;

typedef struct declaration declaration;
typedef struct declaration_list declaration_list;

typedef struct declarator declarator;
typedef struct direct_declarator direct_declarator;

typedef struct declaration_specifiers declaration_specifiers;

typedef struct pointer pointer;

typedef struct init_declarator_list init_declarator_list;
typedef struct init_declarator init_declarator;
typedef struct initializer initializer;

typedef struct parameter_type_list parameter_type_list;
typedef struct parameter_list parameter_list;
typedef struct parameter_declaration parameter_declaration;

typedef enum type_qualifier type_qualifier;
typedef struct type_specifier type_specifier;
typedef enum storage_class_specifier storage_class_specifier;

typedef struct identifier {
    char *name;
} identifier;

// Declarations

struct declaration {
    declaration_specifiers *specifiers;
    init_declarator_list *init_decls;
};

struct parameter_declaration {
    declaration_specifiers *specifiers;
    declarator *decl;
};

struct parameter_type_list {
    parameter_list *params;
};

struct parameter_list {
    parameter_declaration decl;
    parameter_list *next;
};

struct declarator {
    pointer *pointer;
    direct_declarator *direct_decl;
};

struct pointer {
    // type_qualifier_list *qualifiers;
    pointer *next;
};


enum type_qualifier {
    TQ_CONST,
    TQ_VOLATILE
};

struct type_specifier {
    enum {
        TS_VOID,
        TS_CHAR,
        TS_SHORT,
        TS_INT,
        TS_LONG,
        TS_FLOAT,
        TS_DOUBLE,
        TS_SIGNED,
        TS_UNSIGNED,
    } tag;
};

enum storage_class_specifier {
    SCS_TYPEDEF,
    SCS_EXTERN,
    SCS_STATIC,
    SCS_AUTO,
    SCS_REGISTER
};

typedef struct declaration_specifier {
    enum {
        DS_TYPE_SPECIFIER,
        DS_TYPE_QUALIFIER,
        DS_STORAGE_CLASS_SPECIFIER
    } tag;
    union {
        type_specifier s;
        type_qualifier q;
        storage_class_specifier sc;
    } specifier;
} declaration_specifier;

struct declaration_specifiers {
    declaration_specifier specifier;
    declaration_specifiers *next;
};

struct init_declarator {
    declarator *decl;
    initializer *init;
};

struct init_declarator_list {
    init_declarator decl;
    init_declarator_list *next;
};

struct initializer {
    expression *expr;
};

struct direct_declarator {
    enum {
        DDECL_IDENTIFIER,
        DDECL_DECLARATOR,
        DDECL_FUNCTION
    } tag;
    union {
        identifier identifier_decl;
        declarator *decl;
        struct {
            direct_declarator *function;
            parameter_type_list param_types;
        } function_decl;
    } op;
};


struct function_definition {

};

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
        EXPR_INTEGER,
        EXPR_STRING,
        EXPR_IDENTIFIER,
        EXPR_ADD,
        EXPR_SUBTRACT,
        EXPR_MULTIPLY,
        EXPR_DIVIDE,
        EXPR_MODULO,
        EXPR_DEREFERENCE,
        EXPR_REFERENCE,
        EXPR_MULTI
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
        binary_expr(multi_expr);
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

// Module

typedef struct translation_unit {

} translation_unit;

typedef struct external_declaration {
    enum {
        ED_DECLARATION,
        ED_FUNCTION_DEFINITION
    } op;
    struct {
        declaration decl;
        function_definition func;
    } decl;
} external_declaration;

// builders

identifier new_identifier(char *name);

expression *new_identifier_expression(identifier ident);
expression *new_string_literal_expression(char* name);
expression *new_multi_expression(expression *left, expression *right);

pointer *new_pointer(pointer *next);

declaration_specifiers *new_declaration_specifiers(declaration_specifier spec, declaration_specifiers *next);
init_declarator_list *new_init_declarator_list(init_declarator decl, init_declarator_list *next);
parameter_list *new_parameter_list(parameter_declaration decl, parameter_list *next);

#endif

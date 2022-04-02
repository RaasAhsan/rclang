
// Reference:
// 1. https://lambda.uta.edu/cse5317/notes/node26.html
// 2. https://www.reddit.com/r/C_Programming/comments/lzq2t2/how_to_make_an_ast_in_c/

#ifndef AST_H
#define AST_H

typedef struct translation_unit translation_unit;
typedef struct external_declaration external_declaration;

typedef struct statement statement;
typedef struct statement_list statement_list;
typedef struct jump_statement jump_statement;
typedef struct compound_statement compound_statement;

typedef struct expression expression;
typedef struct argument_expression_list argument_expression_list;

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

typedef struct type_qualifier_list type_qualifier_list;
typedef enum type_qualifier type_qualifier;
typedef struct type_specifier type_specifier;
typedef enum storage_class_specifier storage_class_specifier;

typedef struct type type;
typedef struct type_list type_list;

typedef struct identifier {
    char *name;
} identifier;

// Declarations

struct declaration {
    declaration_specifiers *specifiers;
    init_declarator_list *init_decls;
};

struct declaration_list {
    declaration *decl;
    declaration_list *next;
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

struct type_qualifier_list {
    type_qualifier tq;
    type_qualifier_list *next;
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
        TS_STRUCT_OR_UNION,
        TS_ENUM,
        TS_TYPEDEF_NAME
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
    declaration_specifiers *specifiers;
    declarator *declarator;
    compound_statement *statement;
};

// Expressions

#define unary_expr(name) expression *name

#define binary_expr(name) struct { \
    expression *left; \
    expression *right; \
} name

#define projection_expr(name) struct { \
    expression *base; \
    identifier member; \
} name

struct argument_expression_list {
    expression *expr;
    argument_expression_list *next;
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
        EXPR_MULTI,
        EXPR_PRE_INC,
        EXPR_PRE_DEC,
        EXPR_POST_INC,
        EXPR_POST_DEC,
        EXPR_DIRECT_PROJ,
        EXPR_INDIRECT_PROJ,
        EXPR_CALL,
        EXPR_ARRAY_INDEX
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
            argument_expression_list *args;
        } call_expr;
        binary_expr(array_index_expr);
        projection_expr(direct_projection_expr);
        projection_expr(indirect_projection_expr);
        binary_expr(multi_expr);
    } op;
};

// Statements

struct compound_statement {
    declaration_list *declarations;
    statement_list *statements;
};

struct jump_statement {
    enum {
        JUMP_GOTO,
        JUMP_CONTINUE,
        JUMP_BREAK,
        JUMP_RETURN
    } tag;
    union {
        identifier goto_ident;
        expression* return_expr;
    } jump;
};

struct statement {
    enum {
        STMT_COMPOUND,
        STMT_JUMP
    } tag;
    union {
        jump_statement *jump;
        compound_statement *compound;
    } stmt;
};

struct statement_list {
    statement *stmt;
    statement_list *next;
};

// Module

struct external_declaration {
    enum {
        ED_DECLARATION,
        ED_FUNCTION_DEFINITION
    } op;
    struct {
        declaration *decl;
        function_definition func;
    } decl;
};

struct translation_unit {
    external_declaration decl;
    translation_unit *next;
};

// types

struct type {
    enum {
        TYPE_VOID,
        TYPE_CHAR,
        TYPE_SIGNED_CHAR,
        TYPE_UNSIGNED_CHAR,
        TYPE_SHORT,
        TYPE_UNSIGNED_SHORT,
        TYPE_INT,
        TYPE_UNSIGNED_INT,
        TYPE_LONG,
        TYPE_UNSIGNED_LONG,
        TYPE_FLOAT,
        TYPE_DOUBLE,
        TYPE_LONG_DOUBLE,
        TYPE_STRUCT_OR_UNION,
        TYPE_ENUM,
        TYPE_TYPEDEF,
        TYPE_POINTER,
        TYPE_QUALIFIED,
        TYPE_FUNCTION
    } tag;
    union {
        identifier tag_name;
        identifier typedef_name;
        type *pointer_base_type;
        struct {
            type *base_type;
            type_qualifier_list *qualifiers;
        } qualified;
        struct {
            type *return_type;
            type_list *argument_types;
        } function;
    } data;
};

struct type_list {
    type *type;
    type_list *next;
};

// builders

identifier new_identifier(char *name);

expression *new_identifier_expression(identifier ident);
expression *new_string_literal_expression(char* name);
expression *new_multi_expression(expression *left, expression *right);

pointer *new_pointer(pointer *next);

declaration_specifiers *new_declaration_specifiers(declaration_specifier spec, declaration_specifiers *next);
init_declarator_list *new_init_declarator_list(init_declarator decl, init_declarator_list *next);
parameter_list *new_parameter_list(parameter_declaration decl, parameter_list *next);
declaration_list *new_declaration_list(declaration *decl, declaration_list *next);
statement_list *new_statement_list(statement *statement, statement_list *next);
translation_unit *new_translation_unit(external_declaration decl, translation_unit *next);

type_list *new_type_list(type *type, type_list *type_list);
type *new_function_type(type *return_type, type_list *argument_types);

#endif

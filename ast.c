#include "ast.h"

identifier new_identifier(char *name) {
    identifier ident = {
        .name = name
    };
    return ident;
}

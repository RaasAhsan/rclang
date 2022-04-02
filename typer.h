#ifndef TYPER_H
#define TYPER_H

#include "ast.h"

void typecheck_translation_unit(translation_unit *unit);

void typecheck_statement(statement *stmt);

void typecheck_jump_statement(jump_statement *stmt);

void typecheck_compound_statement(compound_statement *stmt);

void typecheck_declaration(declaration decl);

type *typecheck_expression(expression *expr);

#endif
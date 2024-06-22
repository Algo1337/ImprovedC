#ifndef VARIABLES_H
#define VARIABLES_H

#include "../../iclibs/ic/string/str.h"
#include "../global.h"
#include "../types.h"

typedef enum VAR_ERR_T {
    NO_VAR_ERR                  = 0x63800000,
    INVALID_VAR_TYPE_ERR        = 0x63800001,
    MISSING_VAR_TYPE_ERR        = 0x63800002,
    INVALID_VAR_NAME_ERR        = 0x63800003,
    MISSING_VAR_NAME_ERR        = 0x63800004,
    INVALID_VAR_EXPR_OPRTR_ERR  = 0x63800004,
    MISSING_VAR_EXPR_OPRTR_ERR  = 0x63800005,
    INVALID_VAR_VALUE_ERR       = 0x63800006,
    MISSING_VAR_VALUE_ERR       = 0x63800007,

    INCOMPLETED_STRING_ERR      = 0x63800008,
    INCOMPLETED_VALUE_ERR       = 0x63800009,
    EMPTY_STR_VALUE_ERR         = 0x63800010
} VAR_ERR_T;

typedef struct Variable {
    DATA_T      type; // If not declared (1) then check if its already in use
    char        *name;
    char        *value;

    String      *info;
    char        **args;

    char        *cgen;
    VAR_ERR_T   err;
    char        *msg;
} Variable;

Variable *new_variable(char *var_data);

/* Variable Parsing Functions */
VAR_ERR_T get_variable_type(Variable *var);
VAR_ERR_T get_variable_name(Variable *var);
VAR_ERR_T get_variable_expression(Variable *var);
VAR_ERR_T get_variable_value(Variable *var);

/* Variable Editing Functions */
VAR_ERR_T __SetNewValue(Variable *var, char *data);
VAR_ERR_T __AppendValue(Variable *var, char *data);

void SetVarError(Variable *var, VAR_ERR_T err, char *msg);
void __dieVar(Variable *var);
void debug_types();

#endif
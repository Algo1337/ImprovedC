#ifndef VARIABLES_H
#define VARIABLES_H

#include "../../iclibs/ic/string/str.h"
#include "../types.h"

typedef struct Variable {
    int         declaration; // If type is declared
    DATA_T      type; // If not declared (1) then check if its already in use
    char        *var_name;
    char        *value;

    
} Variable;

Variable *new_variable(char *var_data);
VAR_ERR_T __SetNewValue(Variable *var, char *data);
VAR_ERR_T __StrAppend(Variable *var, char *data);
void __dieVar(Variable *var);

#endif
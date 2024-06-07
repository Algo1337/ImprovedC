/*
*   [ VARIABLE PARSING LIBRARY FOR 'IC' ]
* - Variable Parsing Library For ImprovedC Programming Language
*   any attempt to modify must leave, must leave this message here
*
* - All possible ways to create a variable in ImprovedC
*
* - Todo: All variables that arent string/char * must be on the stack unless returned.
*         Heap variables must be freed if not returned
*
*       string foo;         ->      char *foo;
*       foo = "Test";       ->      char *foo = "Test";
*       foo += "ing This";  ->      strcat(foo_var->value, foo);
*       
*       string bar = "New";
*
*   @author:    Algorithm // Jeffery
*   @github:    https://github.com/AdvancedAlgorithm
*   @discord:   data_t
*   @since:     6/3/2024
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "variables.h"

/* Parsing lines starting with a type */
// Only accepting 'inline' variables
Variable *new_variable(char* var_data) {
    Variable *var       = (Variable *)malloc(sizeof(Variable));
    var->cgen           = (char *)malloc(strlen(var_data) + 1);
    var->info           = string(var_data);
    long arg_count      = (long)var->info->Utils(var->info, _COUNTCH, ' ') + 1;
    var->args           = (char **)var->info->Utils(var->info, _SPLIT, ' ');

    if(!var->info->Utils(var->info, _ENDSWITH, ";")) {
        printf("[ X ] Error, Missing a semi-colon ';' at end of line....!\n");
        return var;
    }

    /*
    *   TODO:
    *           - Ensure variable has been previously declared when modifying
    *           - Ensure variable isn't duplicated upon declaring one
    *   If a TYPE is found, then a variable is being declared.
    *   If type is not found then user is modifying a variable
    */
    VAR_ERR_T err_check = get_variable_type(var, var->args[0]);
    if(err_check != NO_VAR_ERR) {
        // check for existing variable and modify it
        return var;
    }

    err_check = get_variable_name(var);
    if(err_check == INVALID_VAR_NAME_ERR) {
        SetVarError(var, err_check, "Error, Invalid Variable Name!");
    }

    if(arg_count > 2) {
        err_check = get_variable_expression(var);
        if(err_check != NO_VAR_ERR) {
            SetVarError(var, err_check, "Error, Invalid Expression!");
        }
    }

    if(arg_count > 3) {
        err_check = get_variable_value(var, var->info, var->args);
        if(err_check != NO_VAR_ERR) {
            SetVarError(var, err_check, "Error, Invalid Value!");
        }
    }

    printf("%s\n", var->cgen);

    return var;
}

VAR_ERR_T get_variable_type(Variable *var) {
    DATA_T chk = str2type(var->args[0]);
    if((long)chk == (long)NULL_VAR)
        return INVALID_VAR_TYPE_ERR;

    var->type = chk; // Set Type To Variable
    strcat(var->cgen, (char *)type_to_cgen(chk));  // Start cGEN
    return NO_VAR_ERR;
}

VAR_ERR_T get_variable_name(Variable *var) {
    // ensure user isn't using an existing name
    var->name = var->args[1];
    strcat(var->cgen, " ");
    strcat(var->cgen, var->args[1]);
    return NO_VAR_ERR;
}

VAR_ERR_T get_variable_expression(Variable *var) {
    // TODO: check if expression is valid
    strcat(var->cgen, " ");
    strcat(var->cgen, var->args[2]);
    return NO_VAR_ERR;
}

VAR_ERR_T get_variable_value(Variable *var) {
    long quotes = (long)var->info->Utils(var->info, _COUNTCH, '"');
    if(var->type == STRING) {
        if((quotes < 2))
            return INCOMPLETED_STRING_ERR;
        // validateString()
    }

    if(var->args[3] == NULL) return EMPTY_STR_VALUE_ERR;

    var->value = (char *)malloc(strlen(var->args[3]) + 1);
    memset(var->value, '\0', strlen(var->args[3]) + 1);
    strcpy(var->value, var->args[3]);

    strcat(var->cgen, " ");
    strcat(var->cgen, var->args[3]);

    return NO_VAR_ERR;
}

// Incase of variable re-use with hardcoded strings
VAR_ERR_T __SetNewValue(Variable *var, char *data) {
    if(data == NULL) 
        return EMPTY_STR_VALUE_ERR;

    if(!var->value) {
        printf("MEMORY CRASH: %d!\n", MEMORY_ERR);
        exit(0);
    }

    free(var->value);
    return NO_VAR_ERR;
}

// Strings Only
VAR_ERR_T __AppendValue(Variable *var, char *data) {
    if(data == NULL)
        return EMPTY_STR_VALUE_ERR;

    if(!var->value) {
        printf("MEMORY CRASH: %d!\n", MEMORY_ERR);
        exit(0);
    }

    int i = 0;
    while(var->value[i++] != '\0')
        continue;

    var->value = (char *)realloc(var->value, sizeof(char *) * (i + strlen(data) + 1));
    strncat(var->value, data, strlen(data));

    return NO_VAR_ERR;
}

void SetVarError(Variable *var, VAR_ERR_T err, char *msg) {
    var->err = err;
    var->msg = strdup(msg);
}

void __dieVar(Variable *var) {
    if(var->name)
        free(var->name);

    if(var->value);
        free(var->value);

    free(var->args);
    free(var->info);
}

void debug_types() {
    int i = 0;
    while(TYPES_STR[i] != NULL)
        printf("[%d] %s\n", TYPES[i], TYPES_STR[i++]);
}

int validateString(const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\\') {
            switch (str[++i]) {
                case '"':
                case '\'':
                case '\\':
                    break;
                default:
                    return 0;
            }
        } else if (str[i] == '\"' || str[i] == '\'') {
            return 0;
        }
        i++;
    }
    return 1;
}
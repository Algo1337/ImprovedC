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
    Variable *var = (Variable *)malloc(sizeof(Variable *));
    String *v_info = string(var_data);

    if(!v_info->Utils(v_info, _ENDSWITH, ';')) {
        printf("\x1b[31m[ X ] Error, Missing a semi-colon ';' at end of line....!\n");
        exit(0);
    }

    long arg_count = (long)v_info->Utils(v_info, _COUNTCH, ' ');
    char **args = (char **)v_info->Utils(v_info, _SPLIT, ' ');

    switch(arg_count) {
        case 1: { // FOR ERRS ONLY
            printf("[ X ] Error, Invalid variable line. Missing variable name....!");
            exit(0);
            break;
        }
        case 2: { // Variable Declared (string foo;)
            break;
        }
        case 3: { // Variable Set/Append Value (foo = "t"; foo += "est";)
            break;
        }
        case 4: { // Variable declaration with value
            break;
        }
        default: {
            break;
        }
    }

    return var;
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
    var->var_name = data;
    return NO_VAR_ERR;
}

// Strings Only
VAR_ERR_T __StrAppend(Variable *var, char *data) {
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

// Ensure both side types 
// += 4;
// i + 4;
int __IntMathematic(Variable *var, char *data) {

}

void __dieVar(Variable *var) {
    if(var->var_name)
        free(var->var_name);

    if(var->value);
        free(var->value);
}
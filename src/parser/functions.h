#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../types.h"

typedef struct Function {
    int         declared;     // Creation Check
    DATA_T      type;         // Return Type
    char        *name;        // foo()
    char        **arguments;  // Function Arguments: (string name, integer age)
    char        **stack_vars; // Stack Variables: [char name, int age]
    char        **code_block; // Function Code Block Lines

    FNC_ERR_T   err;          // Incase Of Errors
    char        *msg;         // Decent Human Comprehensive String Of The Error Msg
} Function;

Function *new_function(char *fnc_block);
void set_fnc_err(Function *fnc, FNC_ERR_T err_t, char *e);

#endif
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../types.h"
#include "../../iclibs/ic/string/str.h"

typedef enum FNC_ERR_T {
    NO_FNC_ERR                              = 0x5000000,
    MISSING_FNC_NAME_ERR                    = 0x5000001,

    MISSING_ARG_OPENING_PARATHENSIS_ERR     = 0x5000002,
    MISSING_ARG_CLOSING_PARATHENSIS_ERR     = 0x5000003,

    INVALID_ARG_TYPE_ERR                    = 0x5000004,
    MISSING_ARG_TYPE_ERR                    = 0x5000005,

    INVALID_ARG_NAME_ERR                    = 0x5000006,
    MISSING_ARG_NAME_ERR                    = 0x5000007,

    MISSING_STACK_OPENING_BRACKET_ERR       = 0x5000008,
    MISSING_STACK_CLOSING_BRACKET_ERR       = 0x5000009,

    INVALID_STACK_ARGUMENT_ERR              = 0x5000010,
    MISSING_FNC_OPENING_BRACKET_ERR         = 0x5000011,
    MISSING_FNC_CLOSING_BREAKET_ERR         = 0x5000012,

    FNC_CREATION_ATTEMPT_ERR                = 0x5000013,
    STRUCT_CREATION_ATTEMPT_ERR             = 0x5000014
} FNC_ERR_T;

typedef struct Function {
    DATA_T      type;         // Return Type
    char        *name;        // foo()
    char        **arguments;  // Function Arguments: (string name, integer age)
    char        **stack_vars; // Stack Variables: [char name, int age]
    char        **code_block; // Function Code Block Lines
    String      *info;

    FNC_ERR_T   err;          // Incase Of Errors
    char        *msg;         // Decent Human Comprehensive String Of The Error Msg
} Function;

Function *new_function(char *fnc_block);
void set_fnc_err(Function *fnc, FNC_ERR_T err_t, char *e);

#endif
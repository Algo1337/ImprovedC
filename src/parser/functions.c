#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "functions.h"

Function *new_function(char *fnc_block) {
    Function *fnc   = (Function *)malloc(sizeof(Function *));
    fnc->info       = string(fnc_block);
    Array *arr      = __str2array(fnc->info, ' ');
    rm_empty_elements(arr);

    if(!fnc->info->Utils(fnc->info, _ENDSWITHCH, (char)'{')) {
        // multi-line function
    }

    // inline function (fn person() [] {} )
    return fnc;
}

// Validating function name ensuring users 
// aren't using a built=in function name
int validate_fnc_name(char *name) {

}

// Only accepting arguments inside of ( )
int parse_fnc_args(char *arguments) {

}

// Only accepting arguments insde of [ ]
int parse_stack_args(char *stack_args) {

}

// Parsing whats inside of the function
int parse_fnc_body(char *fnc_block) {

}

void set_fnc_err(Function *fnc, FNC_ERR_T err_t, char *e) {
    fnc->err = err_t;
    fnc->msg = e;
}
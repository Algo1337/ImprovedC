#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "types.h"

// DATA_T str2type(char *data) {
//     if(data == NULL)
//         return NULL_VAR;

//     int i = 0;
//     while(str_types[i] != NULL) {
//         if(strcmp(str_types[i], data))
//             return data_types[i];
//         i++;
//     }

//     return NULL_VAR;
// }

DATA_T TYPES[] = { VOID, VOID_PTR, CHAR, CHAR_PTR, CHAR_DPTR, INT, INT_PTR, FLOAT,
                        STRING, INTEGER, ARRAY, MAP, F32, F64, DF64 };

char *TYPES_STR[] = {
    "void",
    "void *",
    "char",
    "char *",
    "char **",
    "int",
    "int *",
    "float",
    "string",
    "integer",
    "Array",
    "Map",
    "F32",
    "F64",
    "DF64",
    "\0"
};

char *type_to_cgen(DATA_T t) {
    int i = 0;
    while(TYPES[i] != NULL) {
        if(t == TYPES[i])
            return TYPES_STR[i];
        i++;
    }

    return NULL;
}

DATA_T str2type(char *t) {
    int i = 0;
    while(TYPES_STR[i] != NULL) {
        if(strcmp(t, TYPES_STR[i]) == 0) {
            return TYPES[i];
        }
        i++;
    }

    return NULL_VAR;
}
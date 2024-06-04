#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "types.h"

DATA_T str2type(char *data) {
    if(data == NULL)
        return NULL_VAR;

    String *raw_datatype = string(data);
    char *type = raw_datatype->Utils(raw_datatype, _TOLOWERCASE);

    if(strcmp(type, "string") == 0) {
        return STRING;
    } else if(strcmp(type, "integer") == 0) {
        return INTEGER;
    } else {
        return INVALID_TYPE_ERR;
    }

    return NULL_VAR;
}

// TODO: CHANGE HARDCODED VALUES
char *type_to_cgen(DATA_T t) {
    switch(t) {
        case NULL_VAR:      return (char *)"NULL_VAR";
        case VOID:          return (char *)"VOID";
        case VOID_PTR:      return (char *)"VOID_PTR";
        case CHAR:          return (char *)"CHAR";
        case CHAR_PTR:      return (char *)"CHAR_PTR";
        case CHAR_DPTR:     return (char *)"CHAR_DPTR";
        case INT:           return (char *)"INT";

        case STRING:        return (char *)"STRING";
        case INTEGER:       return (char *)"INTEGER";
        case ARRAY:         return (char *)"ARRAY";
        case MAP:           return (char *)"MAP";
        case FLOAT:         return (char *)"FLOAT";
        case DOUBLE:        return (char *)"DOULBE";
    }

    return (char *)0;
}

char *type2str(DATA_T t) {
    switch(t) {
        case NULL_VAR:      return (char *)"NULL_VAR";
        case VOID:          return (char *)"VOID";
        case VOID_PTR:      return (char *)"VOID_PTR";
        case CHAR:          return (char *)"CHAR";
        case CHAR_PTR:      return (char *)"CHAR_PTR";
        case CHAR_DPTR:     return (char *)"CHAR_DPTR";
        case INT:           return (char *)"INT";

        case STRING:        return (char *)"STRING";
        case INTEGER:       return (char *)"INTEGER";
        case ARRAY:         return (char *)"ARRAY";
        case MAP:           return (char *)"MAP";
        case FLOAT:         return (char *)"FLOAT";
        case DOUBLE:        return (char *)"DOULBE";
    }

    return (char *)0;
}
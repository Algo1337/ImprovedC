#ifndef STRUCTS_H
#define STRUCTS_H

#include "../../iclibs/ic/string/str.h"

typedef struct ICS {
    char    *name;
    char    *fields;
} ICS;

ICS *new_struct(char *struct_block);

#endif
#pragma once
#ifndef Array_H
#define Array_H

typedef struct Array {
    char    **arr;
    long    idx;
    
    int    (*Append) (struct Array *a, char *data);
} Array;

Array *new_array(char **arr);
int __append(Array *a, char *data);

#endif
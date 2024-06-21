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
int __remove(Array *a, int idx);
int __merge(Array *a, char **arr);
long count_empty_elements(Array *a);
void rm_empty_elements(Array *a);
void *malloc_element(size_t sz);

#endif
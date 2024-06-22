/*
*       [ C String Array Library ]
*
*   @author: Algorithm
*   @github: @AdvancedAlgorithm
*   @description: This software is release "AS-IS" for public use. 
*                 any bugs or issues must be reported for fixures.
*
*   LIST OF FEAUTRES
*   new_array       ( new_string(char *arr) )               Array      DONE
*   Append          ( a->Append(Array *a, char *data) )    int         DONE
*   Remove          ( a->Remove(Array *a, int idx) )       int         DONE
*   Merge           ( a->Merge(Array *a, char **arr) )     int         DONE
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "arr.h"

Array *new_array(char **arr) {
    Array *a = (Array *)malloc(sizeof(Array *));
    if(arr == NULL) return a;

    /* Count Elements In Array */
    while(arr[a->idx++] != NULL)
        continue;

    /* Check for Empty Array Since While Loop Counts Elements */
    if(a->idx == 1 && arr[0] == NULL)
        a->idx = 0;

    if(a->idx > 0) {
        a->arr = (char **)malloc(sizeof(char *) * a->idx);
        memset(a->arr, '\0', sizeof(char *) * a->idx);

        for(int i = 0; i < a->idx; i++) 
            if(arr[i])
                a->arr[i] = strdup(arr[i]);
    } else {
        a->arr = (char **)malloc(sizeof(char *) * 1);
        memset(a->arr, '\0', sizeof(char *) * 1);
    }
    
    a->Append = __append;

    return a;
}

int __append(Array *a, char *data) {
    if(a == NULL) return 0;

    if(a->idx == 0) {
        a->arr[a->idx] = (char *)malloc(strlen(data) + 1);
        memset(a->arr[a->idx], '\0', strlen(data) + 1);
        strcpy(a->arr[a->idx++], data);
        return 1;
    }
    
    a->arr = (char **)realloc(a->arr, sizeof(char *) * (a->idx + 1));
    
    a->arr[a->idx-1] = (char *)malloc(sizeof(char) * (strlen(data) + 1));
    if(a->arr[a->idx-1] == NULL) return 0;

    memset(a->arr[a->idx-1], '\0', sizeof(char) * (strlen(data) + 1));
    strcpy(a->arr[a->idx-1], data);
    return 1;
}

int __remove(Array *a, int idx) {
    if(a == NULL || idx == 0)
        return 0;

    char *new = (char **)malloc((a->idx) + 1);
    memset(new, '\0', (a->idx) + 1);

    for(int i = 0; i < a->idx; i++)
        if(i != idx)
            new[i] = a->arr[i];

    if(idx <= a->idx)
        return 1;

    memset(a->idx, '\0', (a->idx) + 1);
    a->arr = new;
    a->idx--;

    return 0;    
}

int __merge(Array *a, char **arr) {
    if(a == NULL)
        return 0;

    int i = 0;
    while(arr[i++] != NULL)
        continue;

    a->arr = (char *)realloc(a->arr, a->idx + i);
    i = 0;
    while(arr[i] != NULL)
        strcpy(a->arr[i++], arr);

    return 1;
}

void rm_empty_elements(Array *a) {
    if(a->arr == NULL)
        return;

    char **args = (char **)malloc(a->idx);
    int i = 0;
    while(a->arr[i] != NULL) {
        if(&a->arr[i] != " ") {
            args[i] = (char *)malloc_ch(strlen(a->arr[i]) + 1);
            strcpy(args[i], a->arr[i]);
        }
    }

    free(a->arr);
    a->arr = args;
}

void *malloc_element(size_t sz) {
    return malloc(sz);
}
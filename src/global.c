#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "global.h"

void err_n_exit(char *msg) {
    printf("%s", msg);
    exit(1);
}
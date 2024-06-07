#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../iclibs/ic/string/str.h"

int main() {
    String *s = string("foo = \"Test\";");
    char *g = (char *)s->Utils(s, _GETSUBSTR, '"', '"');
    printf("%s", g);
    return 0;
}
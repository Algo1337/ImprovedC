#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../iclibs/file.h"

int main() {
	File *f = open_file("run.ic");
	if(f->content == NULL) {
		return 1;
	}
	printf("%s", f->content);
	return 0;
}

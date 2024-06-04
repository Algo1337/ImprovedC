#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "src/core.h"

int main(int argc, char *argv[]) {
	if(argc != 2)
		err_n_exit("[ X ] Error, no 'ic' or 'c' file provided...\r\n");

	char *file = (char *)argv[1];
	ImprovedC *ic = parse(file);
	return 0;
}

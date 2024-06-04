#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "core.h"

ImprovedC *parse(char *filep) {
	ImprovedC *ic 	= (ImprovedC *)malloc(sizeof(ImprovedC *));

	String *ic_file = string(filep);
	if(!(long)ic_file->Utils(ic_file, _ENDSWITH, ".ic")) {
		err_n_exit("[ X ] Error, Invalid .ic filename provided....!\n");
	} else if((long)ic_file->Utils(ic_file, _ENDSWITH, ".c")) {
		// get args and use with GCC
	}

	ic->Filepath 	= filep;
	ic->src_file 	= open_file(filep);
    if(!ic->src_file)
            return ic;

	String *src_code = string(ic->src_file->Content);
	printf("%s", ic->src_file->Content);

	return ic;
}

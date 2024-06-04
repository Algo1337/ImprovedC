#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "core.h"

ImprovedC *analyze_file(char *filep) {
	ImprovedC *ic 		= (ImprovedC *)malloc(sizeof(ImprovedC *));

	String *ic_file 	= string(filep);
	if(!(long)ic_file->Utils(ic_file, _ENDSWITH, ".ic")) {
		err_n_exit("[ X ] Error, Invalid .ic filename provided....!\n");
	} else if((long)ic_file->Utils(ic_file, _ENDSWITH, ".c")) {
		// get args and use with GCC
	}

	ic->Filepath 		= filep;
	ic->src_file 		= open_file(filep);
    if(!ic->src_file)
            return ic;

	FILE_ERR_T *file_err = parse(ic);
	if(!file_err == NO_FILE_ERR)
		err_n_exit("[ x ] Error, An error occured while reading file content....!");

	return ic;
}

FILE_ERR_T parse(ImprovedC *ic) {
	String *src_code 	= string(ic->src_file->Content);
	long line_count 	= (long)src_code->Utils(src_code, _COUNTCH, '\n');
	char **lines 		= (char **)src_code->Utils(src_code, _SPLIT, '\n');

	for(int i = 0; i < line_count; i++) {
		if(lines[i] == NULL)
			continue;

		if((long)src_code->Utils(src_code, _STARTSWITH, "fnc")) {
			printf("Function Found. Line #%d: %s\n", i, lines[i]);
		} else if((long)src_code->Utils(src_code, _STARTSWITH, "struct")) {
			printf("Struct Found. Line #%d: %s\n", i, lines[i]);
		}
	}

	return NO_FILE_ERR;
}
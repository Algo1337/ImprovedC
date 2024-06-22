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

	ic->var_idx			= 0;
	ic->vars			= (Variable **)malloc(sizeof(Variable *) * 1);
	memset(ic->vars, '\0', 2);

	FILE_ERR_T file_err = parse(ic);
	if(!file_err == NO_FILE_ERR)
		err_n_exit("[ x ] Error, An error occured while reading file content....!");

	return ic;
}

FILE_ERR_T parse(ImprovedC *ic) {
	String *src_code 	= string(ic->src_file->Content);
	long line_count 	= (long)src_code->Utils(src_code, _COUNTCH, '\n');
	char **lines 		= (char **)src_code->Utils(src_code, _SPLIT, '\n');
	
	// TODO:
	//		 - Add a 3-4 point checksum if line don't start with the following
	//			keywords (datatype, fnc, struct)
	
	for(int i = 0; i < line_count; i++) {
		if(lines[i] == NULL)
			continue;

		String *line_info = string(lines[i]);
		line_info->Utils(line_info, _STRIP);
		char **args = line_info->Utils(line_info, _SPLIT, ' ');

		// random lines are function calls and variable modification

		// New Variable Found
		if(str2type(args[0]) != NULL_VAR && strlen(lines[i]) != 0) {
			VAR_ERR_T err = (ic, new_variable(lines[i]));

			if(err != NO_VAR_ERR)
				printf("Error\n");
				
		} else if((long)src_code->Utils(src_code, _STARTSWITH, "fnc")) {
			printf("Function Found. Line #%d: %s\n", i, lines[i]);
		} else if((long)src_code->Utils(src_code, _STARTSWITH, "struct")) {
			printf("Struct Found. Line #%d: %s\n", i, lines[i]);
		} 

		if(is_var_declared(ic, args[0]) == 1) {
			printf("Variable Modification Found: %s\n", args[0]);
		}

		free(line_info);
	}

	// die(ic);

	return NO_FILE_ERR;
}

int VariableCount(ImprovedC *c) {
	int i = 0;
	while(c->vars[i] != NULL) {
		i++;
	}

	return i;
}

VAR_ERR_T is_datatype_valid(char *typ) {
	int i = 0;
	while(TYPES[i] != NULL) {
		if(TYPES[i] == typ) {
			return 1;
		}
		i++;
	}

	return 0;
}

VAR_ERR_T is_var_declared(ImprovedC *c, char *var_name) {
	int i = 0;
	while(c->vars[i] != NULL) {
		if(strcmp(c->vars[i]->name, var_name) == 0) {
			return 1;
		}
		i++;
	}

	return 0;
}

VAR_ERR_T append_new_variable(ImprovedC *c, Variable *var) {
	if(c->var_idx == 0) {
		c->vars[c->var_idx] = (Variable *)var;
		c->var_idx++;
		return NO_VAR_ERR;
	}

	c->vars = (Variable **)realloc(c->vars, sizeof(Variable *) * (c->var_idx + 1));
	c->vars[c->var_idx] = (Variable *)var;
	c->var_idx++;

	return NO_VAR_ERR;
}

FNC_ERR_T is_fnc_declared(ImprovedC *c, char *fnc_name) {

}

FNC_ERR_T append_new_fnc(ImprovedC *c, Function *fnc) {

}

STRUCT_ERR_T is_struct_declared(char *struct_name) {
	
}

void die(ImprovedC *c) {
	if(c->vars != NULL)
		free(c->vars);

	if(c->cGEN != NULL)
		free(c->cGEN);
		
	if(c->src_files != NULL)
		free(c->src_files);
}
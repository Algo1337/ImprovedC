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

	FILE_ERR_T file_err = parse(ic);
	if(!file_err == NO_FILE_ERR)
		err_n_exit("[ x ] Error, An error occured while reading file content....!");

	return ic;
}

FILE_ERR_T parse(ImprovedC *ic) {
	String *src_code 	= string(ic->src_file->Content);
	long line_count 	= (long)src_code->Utils(src_code, _COUNTCH, '\n');
	char **lines 		= (char **)src_code->Utils(src_code, _SPLIT, '\n');
	
	Variable *var = new_variable(lines[1]);
	Variable *var2 = new_variable(lines[2]);
	
	Variable *var3 = new_variable(lines[3]);
	Variable *var4 = new_variable(lines[5]);
	append_new_variable(ic, var);
	append_new_variable(ic, var2);
	append_new_variable(ic, var3);
	append_new_variable(ic, var4);

	long cnt = VariableCount(ic);
	printf("Variable Count: %ld\n", cnt);

	printf("%s", ic->vars[0]->name);
	printf("%s", ic->vars[1]->name);


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

		if(str2type(args[0]) != NULL_VAR) {
			// modify variable
		}


		if((long)src_code->Utils(src_code, _STARTSWITH, "fnc")) {
			printf("Function Found. Line #%d: %s\n", i, lines[i]);
		} else if((long)src_code->Utils(src_code, _STARTSWITH, "struct")) {
			printf("Struct Found. Line #%d: %s\n", i, lines[i]);
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
	printf("%d\n", VariableCount(c));
	if(c->vars == NULL) {
		c->vars = (Variable **)malloc(sizeof(Variable *) * (2 + 1));
		memset(c->vars, '\0', sizeof(Variable *) * (2 + 1));
		c->vars[0] = var;
		return NO_VAR_ERR;
	}

	int cnt = VariableCount(c) + 1;
	c->vars = (Variable **)realloc(c->vars, sizeof(Variable *) * (cnt + 1));
	c->vars[cnt] = var;

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
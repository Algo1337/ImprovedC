#ifndef CORE_H
#define CORE_H

/* IC's Built-in */
#include "global.h"
#include "types.h"
#include "../iclibs/file/file.h"
#include "../iclibs/ic/string/str.h"
#include "../iclibs/ic/array/arr.h"

/* Parser Lib */
#include "parser/structs.h"
#include "parser/variables.h"
#include "parser/functions.h"

typedef struct ImprovedC {
	char 	*Filepath;
	char 	**src_files;

	/* Current Settings/Check Values */
	File 	*src_file;
	char 	*cGEN;

	Variable **vars;
} ImprovedC;

ImprovedC *analyze_file();
FILE_ERR_T parse(ImprovedC *ic);

// Variable Methods
int VariableCount(ImprovedC *c);
VAR_ERR_T is_var_declared(ImprovedC *c, char *var_name);
VAR_ERR_T append_new_variable(ImprovedC *c, Variable *var);

// Function Parsing Methods
FNC_ERR_T is_fnc_declared(ImprovedC *c, char *fnc_name);
FNC_ERR_T append_new_fnc(ImprovedC *c, Function *fnc);

void die(ImprovedC *c);
#endif


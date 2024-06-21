#ifndef STR_H
#define STR_H

#include <stdarg.h>

typedef enum STRING_EDIT_T {
	_NONE,

	// Count/Check ENUM

	_STRLENGTH,
	_STRIP,
	_TRIM,
	_COUNTCH,
	_COUNTSTR,
	_STARTSWITH,
	_ENDSWITH,
	_ENDSWITHCH,
	_ISLOWERCASE,
	_ISUPPERCASE,

	// MODIFICATION ENUM
	_NEW,
	_APPEND,
	_REMOVE,
	_REPLACE,
	_RMCHAR,
	_SPLIT,
	_TOLOWERCASE,
	_TOUPPERCASE,
	_GETSUBSTR,
} STRING_EDIT_T;

typedef struct String {
	char 	*Data;
	long 	sz;

	void *	(*Utils)		(struct String *s, STRING_EDIT_T mode, ...);
} String;

String *string(char *data);
long __length(String *s);
long __Strip(String *s);
long __Trim(String *s, char ch);
long __CountChar(String *s, char ch);
long __CountSubstr(String *s, char *substr);
long __StartsWith(String *s, const char *str);
long __EndsWith(String *s, const char *str);
long __EndsWithCh(String *s, const char ch);
long __IsLowercase(String *s);
int __IsUppercase(String *s);
char *__ToLowercase(String *s);
char *__ToUppercase(String *s);
int __RmChar(String *s, const char chr);
long __Replace(String *s, char *substr, char *replacement);
char *get_va_arg_str(va_list a);
char get_va_arg_char(va_list a);
char *__get_substr(String *s, char start, char end);
char **__SplitChar(String *s, char delim);
void *__edit_str(String *s, STRING_EDIT_T mode, ...);
void __updateString(String *s, char *new_data);
char *malloc_ch(int sz);

#endif
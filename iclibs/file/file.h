#ifndef FILE_H
#define FILE_H

#include <stdio.h>

typedef struct File {
	char 	*Filepath;
    char    *Extension;
	char 	*Content;

	FILE	*FD;
} File;

File *open_file(const char *filep);
long get_file_content_sz(File *f);

#endif

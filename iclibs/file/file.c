#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "file.h"

File *open_file(const char *filep) {
	File *f 	= (File *)malloc(sizeof(File *));
	f->FD 		= fopen(filep, "r+");
	if(!f->FD)
		return f;

	long sz = get_file_content_sz(f);

	f->Content = (char *)malloc(sizeof(char *) * (sz + 1));
	memset(f->Content, '\0', sz + 1);
	fread(f->Content, sz, 1, f->FD);

	return f;
}

long get_file_content_sz(File *f) {
	fseek(f->FD, 0L, SEEK_END);
	long sz = ftell(f->FD);
	fseek(f->FD, 0L, SEEK_SET);

	return sz;
}


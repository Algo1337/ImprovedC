.PHONY: all

all: build

rm_gch:
	rm src/*.gch; rm src/parser/*.gch; rm src/parser/types/*.gch; rm iclibs/file/*.gch; rm iclibs/string/*.gch

build:
	gcc -Winvalid-pch imp.c \
	src/*.c \
	src/parser/*.c \
	iclibs/file/*.c \
	iclibs/string/*.c \
	-o ic -g3 -ggdb

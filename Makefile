# mylinalg - Simple Linear Algebra Library
# AUTHOR: @datsleepyguy

SRC = gael.c
OBJ = $(SRC:.c=.o)
CC = /usr/bin/gcc
CFLAGS = -Wall -Werror -02
CDFLAGS = -Wall -Werror -g

lu :
	cc $(CDFLAGS) lu_decompose.c -o bin/lu_decompose.o

init.o : init.h
	cc -c $(CFLAGS) init.c

main : init.h
	cc $(CDFLAGS) init.o main.c -o bin/main.o

test :
	init.o main.o

clean :
	rm gael.o

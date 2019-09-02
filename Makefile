# mylinalg - Simple Linear Algebra Library
# AUTHOR: @datsleepyguy

SRC = gael.c
OBJ = $(SRC:.c=.o)
CC = /usr/bin/gcc
CFLAGS = -Wall -Werror -g

gael.o : gael.h
	$(CC) -c $(CFLAGS) $(SRC)

clean :
	rm gael.o

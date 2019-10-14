# mylinalg - Simple Linear Algebra Library
# AUTHOR: @datsleepyguy

CC = gcc
CFLAGS = -fPIC -Wall -Werror
CDFLAGS = $(CFLAGS) -g
LDFLAGS = -shared
NAME = mylinalg
TARGET_LIB = lib$(NAME).so
LPATH := $(shell pwd)

SRC := $(wildcard src/*.c)
FILENAMES := $(basename $(notdir $(SRC)))
OBJS := $(wildcard bin/*.o)

all:
	for i in $(FILENAMES); do \
		$(CC) $(CFLAGS) -o bin/$$i.o -c src/$$i.c; \
	done
	$(CC) $(LDFLAGS) -o $(TARGET_LIB) $(OBJS) -lm

test:
	$(CC) $(CDFLAGS) -L$(LPATH) test.c -l$(NAME) -o test

clean :
	rm -f $(OBJ) libmylinalg.so

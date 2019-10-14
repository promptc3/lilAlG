# mylinalg - Simple Linear Algebra Library
# AUTHOR: @datsleepyguy

CC = gcc
CFLAGS = -fPIC -Wall -Werror
CDFLAGS = $(CFLAGS) -g
LDFLAGS = -shared
NAME = mylinalg
TARGET_LIB = lib$(NAME).so
LPATH := $(shell pwd)

TEST := $(wildcard tests/*.c)

SRC := $(wildcard src/*.c)
FILENAMES := $(basename $(notdir $(SRC)))
OBJS := $(wildcard bin/*.o)

all:
	for i in $(FILENAMES); do \
		$(CC) $(CFLAGS) -o bin/$$i.o -c src/$$i.c; \
	done
	$(CC) $(LDFLAGS) -o $(TARGET_LIB) $(OBJS) -lm

test:
	$(CC) $(CFLAGS) -L$(LPATH) -Wl,-rpath=$(LPATH) $(TEST) -l$(NAME) -o tests/test
	./tests/test
clean :
	rm -f $(OBJ) libmylinalg.so

# Exercise 1 Makefile
# Ignacio Utrilla - 2017

OBJ_DIR=obj

CC=gcc
OFLAGS=-Wall -c
CFLAGS=-Wall -o
BIN=e1.bin



DEP=$(wildcard *.h)

SRCS=$(wildcard *.c)
OBJS=$(patsubst %c,%o,$(SRCS) )

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(BIN) $^

$(OBJS): $(SRCS) $(DEP)
	$(CC) $(OFLAGS) $^

build:
	mkdir $(OBJ_DIR)

clean:
	rm -f $(wildcard *.o) $(wildcard *.gch) $(BIN) 

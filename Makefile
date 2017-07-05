# Exercise 1 Makefile
# Ignacio Utrilla - 2017

CC=gcc
OFLAGS=-Wall -c
CFLAGS=-Wall -o
BIN=e1.bin

SRCS=main.c functions.c
OBJS=$(patsubst %c,%o,$(SRCS) )

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(BIN) $^

main.o: main.c
	$(CC) $(OFLAGS) $^

functions.o: functions.c functions.h
	$(CC) $(OFLAGS) $^

build:
	mkdir $(OBJS_DIR)

clean:
	rm -f $(wildcard *.o) $(wildcard *.gch) $(BIN) 

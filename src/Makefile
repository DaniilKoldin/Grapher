CC=gcc
CFLAGS=-Wall -Wextra -Werror
BUILD=../build/

all: graph

graph:
	$(CC) $(CFLAGS) rpn.c parse_func.c structs.c calc.c graph.c -o $(BUILD)graph -lm



clean:
	rm -rf *.o $(BUILD)graph

rebuild: clean all
# List of all C programs to compile
PROGS := Exercise_4_1.c Exercise_4_3.c

# Compiler to use
CC := gcc

# Flags for the compiler
CFLAGS := -Wall -std=c99 -g

# Default target: compile all programs
all: $(PROGS:.c=)

# Rule to compile each program
Exercise_4_1: Exercise_4_1.c
	$(CC) $(CFLAGS) Exercise_4_1.c -o Exercise_4_1

Exercise_4_2: Exercise_4_3.c
	$(CC) $(CFLAGS) Exercise_4_3.c -o Exercise_4_3

# Target to run a specific program
run_4_1: Exercise_4_1
	./Exercise_4_1

run_4_2: Exercise_4_3
	./Exercise_4_3

# Target to clean up compiled files
clean:
	rm -f Exercise_4_1 Exercise_4_3

# Phony targets (targets that don't correspond to actual files)
.PHONY: all clean run_4_1 run_4_3


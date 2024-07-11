#all:
#	cc demo.c -o demo
#execute:
#	./demo

#clean:
#	rm -rf
#

# List of all C programs to compile (Exercise_1_1.c to Exercise_1_13.c)
PROGS := Exercise_3_1.c Exercise_3_2.c Exercise_3_3.c

# Compiler to use
CC := gcc

# Flags for the compiler
CFLAGS := -Wall -std=c99 -g

# Default target: compile all programs
all: $(PROGS:.c=)

# Rule to compile each program
Exercise_%: Exercise_%.c
	$(CC) $(CFLAGS) $< -o $@ 

# Target to run a specific program
run_%: Exercise_%
	./$*

# Target to clean up compiled files
clean:
	rm -f $(PROGS:.c=)

# Phony targets (targets that don't correspond to actual files)
.PHONY: all clean






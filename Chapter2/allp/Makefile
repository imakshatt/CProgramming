#all:
#	cc demo.c -o demo
#execute:
#	./demo

#clean:
#	rm -rf
#

# List of all C programs to compile (Exercise_1_1.c to Exercise_1_13.c)
PROGS := Exercise_2_1.c Exercise_2_2.c Exercise_2_4.c Exercise_2_5.c Exercise_2_10.c

# Compiler to use
CC := gcc

# Flags for the compiler
CFLAGS := -Wall -std=c99

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






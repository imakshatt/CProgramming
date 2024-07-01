# List of all C programs to compile (Exercise_1_1.c to Exercise_1_13.c)
PROGS := Exercise_1_1.c Exercise_1_4.c Exercise_1_5.c Exercise_1_6.c Exercise_1_7 \
	 Exercise_1_8.c Exercise_1_9.c Exercise_1_10.c Exercise_1_12.c Exercise_1_13.c Exercise_1_14.c

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



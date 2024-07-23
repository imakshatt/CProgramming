# Verify Expression `c=getchar()!=EOF` Exercise

This program verifies that the expression `c=getchar()!=EOF` is either 0 or 1. It continuously takescharacter input from the user and checks if the input is not the End of File (EOF) marker. The result is printed as `1` if the condition is true and `0` if the condition is false. The program allows the user to repeat the process based on their choice.

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Usage](#usage)
- [Example](#example)
- [Author](#author)

## Description
The program performs the following steps:
1. Takes character input from the user using `getchar()`.
2. Checks if the input character is not equal to the End of File (EOF).
3. Prints `1` if the condition is true, otherwise prints `0`.
4. Prompts the user to decide if they want to repeat the process.
5. Continues to repeat based on the user's choice.

## Features
- Verifies the expression `c=getchar()!=EOF`.
- Continuously prompts the user for input until they choose to exit.

## Usage
1. Compile the program using a C compiler, e.g., `gcc -o Exercise_1_6 Exercise_1_6.c`.
2. Run the compiled program, e.g., `./Exercise_1_6`.
3. Enter characters and observe the output.
4. Choose whether to repeat the process by entering 'y' or 'Y' to continue, or any other key to exit

## Run the Program using MAKEFILE
1. Go to ROOT directory (cd CProgramming)
2. Run the below command.
3. make run_exercise EXERCISE="Chapter1/Exercise_1.6/Exercise_1_6.c"

## Example
a
1
Do you want to generate another table? (y/n): y
b
1
Do you want to generate another table? (y/n): y
Ctrl+D (or Ctrl+Z in Windows)
0
Do you want to generate another table? (y/n): n

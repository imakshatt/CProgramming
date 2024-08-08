# Hexadecimal to Integer Converter

This program converts a string of hexadecimal digits (including an optional `0x` or `0X` prefix) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Usage](#usage)
- [Example](#example)
- [Author](#author)

## Description
The program takes a hexadecimal string as input from the user and converts it to its decimal equivalent. The input string can optionally start with `0x` or `0X`. The program performs error handling to ensure valid hexadecimal input and allows the user to repeat the process until they choose to exit.

## Features
- Converts a hexadecimal string to its decimal equivalent.
- Handles both uppercase and lowercase hexadecimal digits.
- Supports optional `0x` or `0X` prefix.
- Error handling for invalid inputs.
- Prompts the user to repeat the process.

## Usage
1. Compile the program using a C compiler, e.g., `gcc -o hex_to_int hex_to_int.c ../error_handling.c`.
2. Run the compiled program, e.g., `./hex_to_int`.
3. Enter a valid hexadecimal number when prompted.
4. View the converted decimal value.
5. Choose whether to convert another number by entering 'y' or 'Y' to continue, or any other key to exit.

## Run the Program using MAKEFILE
1. Go to ROOT directory (cd CProgramming)
2. Run the below command.
3. make run_exercise EXERCISE="Chapter1/Exercise_1.4/Exercise_1_4.c"

## Example
Enter a hexadecimal number (with optional 0x or 0X prefix): 0x1A3F
Hexadecimal Equivalent: 6719
Do you want to continue? (y/n): y
Enter a hexadecimal number (with optional 0x or 0X prefix): 1a3f
Hexadecimal Equivalent: 6719
Do you want to continue? (y/n): n

## Error Handling
This program includes custom error handling through an external error handling module (`error_handling.h`). The errors handled include:
- **ERROR_INVALID_INPUT:** Triggered when the input is invalid or empty.
- **ERROR_INVALID_HEX_CHARACTER:** Triggered when the input contains characters that are not valid hexadecimal digits.

Ensure to include the `error_handling.h` and `error_handling.c` files in your project directory to handle errors appropriately.


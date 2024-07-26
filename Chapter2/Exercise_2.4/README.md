# Squeeze Program

## Description
This program removes all characters in a string `s1` that match any character in another string `s2`. The program includes error handling for various input errors such as invalid input, empty strings, and duplicate characters in `s2`.

## Author
- **Name**: Akshat Darji
- **Created**: 4 July 2024
- **Modified**: 4 July 2024

## Requirements
- C compiler
- Standard C libraries (`stdio.h`, `string.h`)
- Custom error handling module (`error_handling.h`)

## Usage
1. **Compile the program**:
    gcc -o Exercise_2_4 Exercise_2_4.c ../../error_handling.c

2. **Run the program**:
    ./Exercise_2_4

3. **Program Interaction**:
    - The program will prompt the user to enter the main string `s1`.
    - The program will then prompt the user to enter the string `s2` containing characters to remove from `s1`.
    - The program will validate the input and process the strings to remove characters in `s1` that match any in `s2`.
    - The modified string will be printed.
    - The user will be asked if they want to continue and can enter 'y' to continue or 'n' to exit.

## Example
### Input:


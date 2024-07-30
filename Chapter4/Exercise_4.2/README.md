# atof Program with Scientific Notation Handling

## Description
This program extends the `atof` function to handle scientific notation of the form `123.45e-6`, where a floating-point number may be followed by 'e' or 'E' and an optionally signed exponent. It converts the string representation of a floating-point number into its equivalent double-precision floating-point value.

## Author
- **Name**: Akshat Darji
- **Created**: 16 July 2024
- **Modified**: 16 July 2024

## Input String Format
- The input string should represent a floating-point number in the following formats:
  - Standard floating-point format: `123.45e-23`
  - Scientific notation: `123.45e-6` or `123.45E+6`
  - Scientific notation with optional sign: `123.45e-6`, `123.45e+6`, `123.45E-6`
  - Scientific notation with other sign not valid: '123.45e$2', '125-4.e4'

## Requirements
- C compiler
- Standard C libraries (`stdio.h`, `ctype.h`, `math.h`, `string.h`)
- Custom error handling module (`error_handling.h`)

## Usage
1. **Compile the program**:
    ```sh
    gcc -o Exercise_4_2 Exercise_4_2.c.c ../../error_handling.c -lm -g
    ```

2. **Run the program**:
    ```sh
    ./Exercise_4_2
    ```

3. **Program Interaction**:
    - The program prompts the user to enter a floating-point number as a string.
    - It validates the input string format to ensure it conforms to allowed formats.
    - The program then converts the string to a double-precision floating-point number using the extended `atof` function.
    - The converted double value is displayed.
    - The user is asked if they want to convert another string. Enter 'y' for yes or 'n' for no.

## Example
Enter a floating-point number as a string: 123.45e-6
Converted double value: 0.000123
Do you want to convert another string? (y/n): y
Enter a floating-point number as a string: 456.78E+3
Converted double value: 456780.000000
Do you want to convert another string? (y/n): n



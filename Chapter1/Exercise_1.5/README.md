# Fahrenheit to Celsius Reverse Table Generator

This program dynamically generates a reverse table converting Fahrenheit to Celsius based on user inputs for the upper limit, lower limit, and step size. It allows the user to continue generating tables until they choose to exit.

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Usage](#usage)
- [Example](#example)
- [Author](#author)

## Description
The program takes three inputs from the user:
1. Upper limit of the Fahrenheit values (must be an integer).
2. Lower limit of the Fahrenheit values (must be an integer).
3. Step size for the Fahrenheit values (must be an integer).

Using these inputs, it generates a reverse table converting the specified range of Fahrenheit valuesto Celsius. After displaying the table, the user is prompted to decide if they want to generate another table or exit the program.

## Features
- Dynamic user input for the range and step size.
- Continues to prompt the user until they choose to exit.
- Displays the table in a formatted manner.

## Usage
1. Compile the program using a C compiler, e.g., `gcc -o Exercise_1_5 Exercise_1_5.c`.
2. Run the compiled program, e.g., `./Exercise_1_5`.
3. Follow the prompts to enter the upper limit, lower limit, and step size.
4. View the generated table.
5. Choose whether to generate another table or exit.

## Run the Program using MAKEFILE
1. Go to ROOT directory (cd CProgramming)
2. Run the below command.
3. make run_exercise EXERCISE="Chapter1/Exercise_1.5/Exercise_1_5.c"

## Example
Enter the lower limit (in Celsius)->MUST BE AN INT VALUE: 0
Enter the Upper limit (in Celsius)->MUST BE AN INT VALUE: 100
Enter the step size ->MUST BE AN INT VALUE: 20
Fahrenheit Celsius
100 37.78
80 26.67
60 15.56
40 4.44
20 -6.67
0 -17.78

Do you want to generate another table? (y/n): y
Enter the lower limit (in Celsius)->MUST BE AN INT VALUE: -40
Enter the Upper limit (in Celsius)->MUST BE AN INT VALUE: 50
Enter the step size ->MUST BE AN INT VALUE: 10
Fahrenheit Celsius
50 10.00
40 4.44
30 -1.11
20 -6.67
10 -12.22
0 -17.78
-10 -23.33
-20 -28.89
-30 -34.44
-40 -40.00

Do you want to generate another table? (y/n): n

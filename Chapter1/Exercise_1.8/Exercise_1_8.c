/**
 * Exercise_1_8: Write a program to count blanks, tabs, and new lines.
 * Author: Akshat Darji
 * Created: 24 Jun 2024
 * Modified: 24 Jun 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>

/** FUNCTION PROTOTYPES */
void countBlanks(int *iBlank);
void countTabs(int *iTabs);
void countLines(int *iLines);

/** MAIN PROGRAM */
/*
 * main: Initializes counters and calls functions to count blanks, tabs, and lines in the text stream.
 */
int main() {
    int iBlank = 0; /* Variable for counting blanks */
    int iTabs = 0;  /* Variable for counting tabs */
    int iLines = 0; /* Variable for counting lines */
    int iC; /* Variable for storing characters read from input */

    printf("Enter text (Ctrl+D to end input):\n");

    /* Read characters and count blanks, tabs, and lines */
    while ((iC = getchar()) != EOF) { /* Termination Condition */
        if (iC == ' ') { /* Checks if character is a blank space */
            iBlank++; /* Increment blank counter */
        } 
	else if (iC == '\t') { /* Checks if character is a tab */
            iTabs++; /* Increment tab counter */
        } 
	else if (iC == '\n') { /* Checks if character is a new line */
            iLines++; /* Increment line counter */
        }
    }

    /* Print the results */
    printf("Total # of Blanks: %d\n", iBlank); /* Printing the number of blanks */
    printf("Total # of Tabs: %d\n", iTabs); /* Printing the number of tabs */
    printf("Total # of Lines: %d\n", iLines); /* Printing the number of lines */

    return 0;
}

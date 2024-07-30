/**
Exercise_3_4: In a two's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why not. Modify it to print that value correctly, regardless of the machine on which it runs.
Author: Akshat Darji
Created: 10 July 2024
Modified: 10 July 2024
*/

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h>
#include <limits.h> /*For INT_MIN*/
#include "../../error_handling.h"

/** MACRO DEFINITIONS */
#define MAX_STRING_LENGTH 1000

/** FUNCTION PROTOTYPES */
void itoa(int iN, char cS[]); /* Function which converts the number into the char string */
void reverse(char cS[]);  /* Resulting char string is reversed using this function */

/** MAIN PROGRAM */
/*
 * main: Takes the number and converts that number into the character string
*/

int main() {
    char cS[MAX_STRING_LENGTH];  /* Array to store the resulting string */
    int iN;                      /* Number to be converted */
    char choice;                 /* Variable to store the user's choice for continuation */

    do {
        printf("Enter an integer to convert to a string: ");
        if (scanf("%d", &iN) != 1) {
            handle_error(ERROR_INVALID_INPUT);  /* Handle invalid input error */
            while (getchar() != '\n'); /* Clear input buffer */
            return 1;
        }

        itoa(iN, cS);  /* Call the itoa function to convert the number to a string */

        printf("Converted string: %s\n", cS);  /* Print the resulting string */

        printf("Do you want to convert another number? (y/n): ");
        if (scanf(" %c", &choice) != 1) {
            handle_error(ERROR_INVALID_INPUT);  /* Handle invalid input error */
            while (getchar() != '\n'); /* Clear input buffer */
            return 1;
        }

        /* Clear the input buffer to avoid issues with leftover newline characters */
        while (getchar() != '\n');

    } while (choice == 'y' || choice == 'Y');  /* Continue if the user chooses 'y' or 'Y' */

    return 0;  /* Exit the program */
}

/*
 * itoa(): Converts an integer to a string representation
 * Author: Akshat Darji
 * Created: 10 Jun 2024
 * Modified: 10 Jun 2024
*/

void itoa(int iN, char cS[]) {
    int iI, iSign; /* Initialize i for traversing the number and sign to check whether the number is positive or                       negative */
    if (iN == INT_MIN) {  /*case for the most negative value */
        strcpy(cS, "-2147483648");
        return;
    }

    if(iN >= INT_MAX){
    	handle_error(INT_OUT_OF_RANGE);
	return;
    }

    if ((iSign = iN) < 0) {    /* Check if number is negative */
        iN = -iN;   /* Make number positive */
    }
    iI = 0;  /* Initialize i with zero */
    while (iN > 0) {   /* Termination condition */
        cS[iI] = iN % 10 + '0'; /* Break the number into digits and store them in cS */
        iI++; /* Increment the pointer of cS to the next position */
        iN = iN / 10;  /* Delete the last digit from the number */
    }
    if (iSign < 0) {   /* If the number was negative, add the '-' sign */
        cS[iI] = '-';
        iI++;  /* Increment i by one to traverse into the cS */
    }
    cS[iI] = '\0';   /* Null-terminate the string */
    reverse(cS);   /* Reverse the string to get the correct order */
}

/*
 * reverse(): Reverses the given string
 * Author: Akshat Darji
 * Created: 10 Jun 2024
 * Modified: 10 Jun 2024
*/

void reverse(char cS[]) {
    char cT[1000];   /* Array to store the reversed string */
    int iLen = strlen(cS); /* Find the length of the input string */
    int iIndex = 0;  /* Index for traversing cT */

    for (int iJ = iLen - 1; iJ >= 0; iJ--) {   /* Loop to reverse the string */
        cT[iIndex++] = cS[iJ]; /* Copy characters from cS to cT in reverse order */
    }
    cT[iIndex] = '\0'; /* Null-terminate the reversed string */

    strcpy(cS, cT); /* Copy the reversed string back to cS */
}

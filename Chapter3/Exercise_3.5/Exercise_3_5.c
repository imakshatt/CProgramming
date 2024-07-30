/**
Exercise_3_5: Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s. In particular, itob(n,s,16) formats s as a hexadecimal integer in s.
Author: Akshat Darji
Created: 11 July 2024
Modified: 11 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include "../../error_handling.h"

/** MARCO DEFINATIONS */
#define MAX_STRING_LENGTH 1000


/** FUNCTION PROTOTYPES */
void itob(int iN, char s[], int base); /*function which takes the Number, char string and base to co                                         nvert iN into Base B*/
void reverse(char s[]);                /*Function to reverse the char s[]*/

/** MAIN PROGRAM */
/*
 * main: takes the number and base from the user and sends to the function itob that convert iN to base B
*/

int main() {
    int iN, base;  /* Initializing the iN and base as int type */
    char choice;   /* Variable to store the user's choice for continuation */

    do {
        printf("Enter the number: ");  /* Prompt the user to enter the number */
        if (scanf("%d", &iN) != 1) {  /* Read the number from user and handle invalid input */
            handle_error(ERROR_INVALID_INPUT);  /* Handle invalid input error */
            while (getchar() != '\n'); /* Clear input buffer */
            return 1;
        }

        char s[MAX_STRING_LENGTH];  /* Array to store the resulting string */

        printf("Enter the base to convert the number to (2-36): ");
        if (scanf("%d", &base) != 1 || base < 2 || base > 36) {  /* Read the base from the user and validate it */
            handle_error(ERROR_INVALID_INPUT);  /* Handle invalid input error */
            while (getchar() != '\n'); /* Clear input buffer */
            return 1;
        }

        itob(iN, s, base);  /* Call the itob function with iN, s, and base */

        printf("Converted string: %s\n", s);  /* Print the resulting string */

        printf("Do you want to convert another number? (y/n): ");
        if (scanf(" %c", &choice) != 1) {  /* Read user's choice for continuation */
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
 * itob(): It accepts the number, answer string s[] and the base b to convert the iN into base B
 * Author: Akshat Darji
 * Created: 11 July 2024
 * Modified: 11 July 2024
*/

void itob(int iN, char s[], int base) {
    int index = 0;  /* Index for traversing into the result string s[] */
    int iRemainder = 0; /* It stores the remainder after the modulo operation */

    if (base < 2 || base > 36) {  /* Test case for validating the base */
        s[0] = '\0';   /* If base is not valid then return the NULL string as an answer */
        return;
    }

    /* Handle negative numbers for bases other than 10 */
    int sign = iN;
    if (iN < 0) {
        iN = -iN;
    }

    while (iN > 0) {  /* Termination Condition */
        iRemainder = iN % base;   /* Modulo operation to find the remainder */
        if (iRemainder >= 10) {   /* If remainder is >=10 then convert it into A...Z */
            s[index] = iRemainder - 10 + 'A';  /* Converting into A...Z */
        } else {
            s[index] = iRemainder + '0';
        }
        index++;  /* Incrementing the index to traverse into the char string s[] */
        iN = iN / base;   /* Divide the iN by base to remove the remainder */
    }

    if (sign < 0) { /* If the original number was negative */
        s[index++] = '-';
    }

    s[index] = '\0';  /* Null-terminate the resulting string */
    reverse(s);   /* Reverse the resulting string to get the correct representation */
}

/*
 * reverse: Reverses the string s[]
 * Author: Akshat Darji
 * Created: 11 July 2024
 * Modified: 11 July 2024
 */
void reverse(char s[]) {
    int len = strlen(s);  /* Finding the length of the char string s[] */
    for (int i = 0, j = len - 1; i < j; i++, j--) {  /* Reverse the string */
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

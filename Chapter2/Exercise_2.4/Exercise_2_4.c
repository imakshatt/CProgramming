/**
 * Program to remove all characters in s1 that match any character in the string s2
 * Author: Akshat Darji
 * Created: 4 July 2024
 * Modified: 4 July 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h>
#include "../../error_handling.h" /* Include the error handling header */

/** MACRO DEFINITIONS */
#define MAX_STRING_LENGTH 1000 /*Defining the Max string length for s1 and s2*/

/** FUNCTION PROTOTYPES */
void squeeze(char s1[], char s2[]); /*Squeeze function to remove s2 char from s1*/
int contains_duplicates(char s2[]); /*For error handling to check there is duplicate char in s2 ?*/

/** MAIN PROGRAM */
/*
 * main: Demonstrates the squeeze function by removing characters in s1 that match any in s2
 */
int main() {
    char choice; /*For taking the choice from user that whether the user wants to continue or not*/

    do {
        char cS1[MAX_STRING_LENGTH]; /* Initializing the main string */
        char cS2[MAX_STRING_LENGTH]; /* Initializing the string with characters to remove */

        printf("Enter the main string: "); 
        if (scanf("%999s", cS1) != 1) { /*Check input is correct or not*/
            handle_error(ERROR_INVALID_INPUT); /*Error Handling*/
            return 1;
        }

        printf("Enter the string with characters to remove: ");
        if (scanf("%999s", cS2) != 1) { /*Check input is correct or not*/
            handle_error(ERROR_INVALID_INPUT); /*Error Handling*/
            return 1;
        }

        if (strlen(cS1) == 0) { /*Check if the length of cS1 is 0 then handle the error*/
            handle_error(ERROR_EMPTY_STRING); /*Error Handling*/
            return 1;
        }

        if (strlen(cS2) == 0) { /*Check if the length of cS2 is 0 then handle the error*/
            handle_error(ERROR_EMPTY_STRING); /*Error Handling*/
            return 1;
        }

	if (strlen(cS1) >= MAX_STRING_LENGTH) { /*If string length exceed MAX length as defined*/
            handle_error(ERROR_INPUT_TOO_LONG);  /* Handle input too long error */
            return 1;
        }

	if (strlen(cS2) >= MAX_STRING_LENGTH) { /*If string length exceed MAX length as defined*/
            handle_error(ERROR_INPUT_TOO_LONG);  /* Handle input too long error */
            return 1;
        }


        squeeze(cS1, cS2); /*Calling the function with arguments cS1 and cS2*/
        printf("Modified String: %s\n", cS1); /*Pritnting the answer*/

        printf("Do you want to continue? (y/n): "); /*ASking user if they want to continue or not*/
        if (scanf(" %c", &choice) != 1) { /*Input check*/
            handle_error(ERROR_INVALID_INPUT); /*Error Handling*/
            return 1;
        }
    } while (choice == 'y' || choice == 'Y'); /*End of Do-While loop*/

    return 0;
} /*End of main function*/


/*
 * squeeze(cS1, cS2): Removes all characters in s1 that match any character in s2
 * Parameters:
 *   s1 - The main string from which characters will be removed
 *   s2 - The string containing characters to remove from s1
 *   Author: Akshat Darji
 *   Created: 4 July 2024
 *   Modified: 25 July 2024
 */
void squeeze(char s1[], char s2[]) {
    int iI, iJ, iK; /* Declare loop counters */
    int iFound; /* Flag to indicate if a character match is found */

    for (iI = 0, iJ = 0; s1[iI] != '\0'; iI++) { /* Loop through each character in s1 */
        iFound = 0; /* Reset the found flag */
        for (iK = 0; s2[iK] != '\0'; iK++) { /* Loop through each character in s2 */
            if (s1[iI] == s2[iK]) { /* Check if characters match */
                iFound = 1; /* Set the found flag if there's a match */
                break; /* Exit the inner loop */
            }
        }
        if (!iFound) { /* If no match was found */
            s1[iJ] = s1[iI]; /* Copy the character to the new position */
            iJ++; /* Increment the new position index */
        }
    }
    s1[iJ] = '\0'; /* Null-terminate the modified string */
}

/*
 * contains_duplicates: Checks if the string s2 contains duplicate characters
 * Parameters:
 *   s2 - The string to check for duplicates
 * Returns:
 *   1 if duplicates are found, 0 otherwise
 *   Author: Akshat Darji
 *   Created: 25 July 2024
 *   Modified: 25 July 2024
 */
int contains_duplicates(char s2[]) {
    int iLen = strlen(s2);
    for (int iI = 0; iI < iLen; iI++) {
        for (int iJ = iI + 1; iJ < iLen; iJ++) {
            if (s2[iI] == s2[iJ]) {
                return 1; /* Duplicate found */
            }
        }
    }
    return 0; /* No duplicates */
}

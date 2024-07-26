/**
Exercise_2_5: Write the function any(s1,s2), which returns the first location in a string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library function strpbrk does the same job but returns a pointer to the location.)
Author: Akshat Darji
Created: 8 July 2024
Modified: 8 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h> /*I/P and o/p*/
#include<string.h> /*For string operation like finding the len of str*/
#include "../../error_handling.h" /*Custom error validation file*/

/** MARCO DEFINATIONS */
#define MAX_STRING_LENGTH 1000

/** FUNCTION PROTOTYPES */
int any(char cS1[], char cS2[]); //it return the the index of the founded char from s1 into s2 

/** MAIN PROGRAM */
/*
 * main: takes two string and call the function any(s1, s2) to get the index of an matched element
*/

int main() {
    char choice;  /* Variable to store the user's choice for continuation */

    do {
        char cS1[MAX_STRING_LENGTH];  /* Buffer for the first string */
        char cS2[MAX_STRING_LENGTH];  /* Buffer for the second string */

        printf("Enter the first string: ");
        if (fgets(cS1, sizeof(cS1), stdin) == NULL) { /* Read input for the first string */
            handle_error(ERROR_INVALID_INPUT); /* Handle error if reading fails */
        }
        cS1[strcspn(cS1, "\n")] = '\0';  /* Remove newline character if present */

        printf("Enter the second string: ");
        if (fgets(cS2, sizeof(cS2), stdin) == NULL) { /* Read input for the second string */
            handle_error(ERROR_INVALID_INPUT); /* Handle error if reading fails */
        }
        cS2[strcspn(cS2, "\n")] = '\0';  /* Remove newline character if present */

        if (strlen(cS1) == 0) { /* Check if the length of cS1 is 0 */
            handle_error(ERROR_EMPTY_STRING); /* Handle error for empty string */
        }

        if (strlen(cS2) == 0) { /* Check if the length of cS2 is 0 */
            handle_error(ERROR_EMPTY_STRING); /* Handle error for empty string */
        }

        int iPosition = any(cS1, cS2);  /* Call the any() function with s1 and s2 */

        if (iPosition != -1) { /* Check if a match is found */
            printf("Position of the matched element: %d\n", iPosition);  /* Print position if a match is found */
        } else {
            printf("No matched element found.\n");  /* Inform the user if no match is found */
        }

        printf("Do you want to continue? (y/n): ");
        if (scanf(" %c", &choice) != 1) {  /* Read user's choice for continuation */
            handle_error(ERROR_INVALID_INPUT); /* Handle error if reading fails */
        }

        // Clear the input buffer to avoid issues with leftover newline characters
        while (getchar() != '\n');

    } while (choice == 'y' || choice == 'Y');  /* Continue if the user chooses 'y' or 'Y' */

    return 0;  /* Exit the program */
}
/*
 * any(cS1, cS2): Takes two string and find the index of matched element from string cS1 using string cS2
 * Author: Akshat Darji
 * Created: 8 July 2024
 * Modified: 8 July 2024
*/

int any(char s1[], char s2[]){
	int iI, iJ; /*Intializing the i and j pointer for traversing into the string*/
	int iFound = 0; /*For keep track of match found in cS1 or not*/
	int iPos = -1; /*For maintaining the position of matched character*/
	int iLenS1 = strlen(s1); /*Finding the length of cS1*/
	int iLenS2 = strlen(s2); /*Finding the length of cS2*/
	for(iI=0; iI<iLenS1; iI++){ /*Traversing into string1 cS1*/
		for(iJ=0;iJ<iLenS2;iJ++){ /*Traversing into string2 cS2*/
			if(s1[iI]==s2[iJ]){ /*Check the ith element matche with jth element of cS2*/
				iFound = 1; /*If it is then Update Found to 1*/
				iPos = iI+1; /*Store the position of that character in cS1*/
				break;
			}
		}
		if(iFound == 1){ /*Now if found the character then break because we need the1stPOS*/
			break; /*break the loop*/
		}
	}
	return iPos; /*Retrun the position of that matched character*/
}

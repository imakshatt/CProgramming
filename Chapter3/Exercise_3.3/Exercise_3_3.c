/**
Exercise_3_3: Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.
Author: Akshat Darji
Created: 10 July 2024
Modified: 10 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>
#include<ctype.h> /*For use of isalnum function*/
#include "../../error_handling.h"

/** MARCO DEFINATIONS */
#define MAX_STRING_LENGTH 1000

/** FUNCTION PROTOTYPES */
void expand(char s1[], char s2[]); /*expands the shorthand notations like a-z to abcd ....z*/
is_valid_shorthand(char s[]);

/** MAIN PROGRAM */
/*
 * main: Takes s1[] as an input and pass it to the function expand() to expand it to actual output as mentioned
*/


int main() {
    char cS1[MAX_STRING_LENGTH];  /* Input string */
    char cS2[MAX_STRING_LENGTH];  /* Output string */
    char choice;                 /* Variable to store the user's choice for continuation */

    do {
        printf("Enter a string to expand (e.g., a-z0-9, up to 1000 characters): ");
        if (fgets(cS1, sizeof(cS1), stdin) == NULL) {  /*Taking input string from user (NULL check)*/
            handle_error(ERROR_INVALID_INPUT);  /* Handle invalid input error */
            return 1;
        }
        cS1[strcspn(cS1, "\n")] = '\0';  /* Remove newline character if present */

        /* Check for input length exceeding maximum allowed length */
        if (strlen(cS1) >= MAX_STRING_LENGTH) {
            handle_error(ERROR_INPUT_TOO_LONG);  /* Handle input too long error */
            return 1;
        }

        /* Check if the input shorthand notation is valid */
        if (!is_valid_shorthand(cS1)) {
            handle_error(ERROR_INVALID_INPUT);  /* Handle invalid shorthand notation error */
            return 1;
        }

        expand(cS1, cS2);  /* Call the expand function */

        printf("Expanded string: %s\n", cS2);  /* Print the resulting string */

        printf("Do you want to expand another string? (y/n): ");
        if (scanf(" %c", &choice) != 1) {
            handle_error(ERROR_INVALID_INPUT);  /* Handle invalid input error */
            while (getchar() != '\n'); /* Clear input buffer */
            return 1;
        }

        /* Clear the input buffer to avoid issues with leftover newline characters */
        while (getchar() != '\n');

    } while (choice == 'y' || choice == 'Y');  /* Continue if the user chooses 'y' or 'Y' */

    return 0;  /* Exit the program */
} /* End of main */


/*
 * expand(char s1[], char s2[]): takes s1 as an argument and expand it into char string s2[].
 * Author: Akshat Darji
 * Created: 10 July 2024
 * Modified: 10 July 2024
*/

void expand(char s1[], char s2[]){
	int iString1 = 0;  /*for traversing into the string1*/
	int iString2 = 0;  /*for traversing into the string2*/
	int iLenString1 = strlen(s1);  /*finding the length of String1 for termination condition*/
	int iJ; /*for traversing when desh comes*/
	
	while(iString1<iLenString1){   /*termination condition*/
		if(s1[iString1]==45){   /*checks whether the character is '-'*/
			for(iJ=s1[iString1-1]; iJ<=s1[iString1+1]; iJ++){   /*now get the start and end index*/
				s2[iString2]=iJ;  /*put the elements in between range of start and end*/
				iString2++;   /*increament the iString2 to go to next position in s2[]*/
			}
		}
		iString1++;  /*for traversing into the s1[]*/
	}
	s2[iString2] = '\0';  /*at the end put the null character in the s2[] for the termination of string*/
} /*End of function*/


/*
 * is_valid_shorthand(char s[]): checks if the input shorthand notation is valid
 * Author: Akshat Darji
 * Created: 21 July 2024
 * Modified: 21 July 2024
 */
int is_valid_shorthand(char s[]) {
    int iLen = strlen(s);
    if (s[0] == '-' || s[iLen - 1] == '-') {
        return 0;  /* Invalid if starts or ends with '-' */
    }
    for (int i = 0; i < iLen; i++) {
        if (!isalnum(s[i]) && s[i] != '-') {
            return 0;  /* Invalid if contains non-alphanumeric characters except '-' */
        }
        if (s[i] == '-' && (i == 0 || i == iLen - 1 || s[i + 1] == '-')) {
            return 0;  /* Invalid if '-' is at the start, end, or followed by another '-' */
        }
    }
    return 1;
}

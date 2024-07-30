/**
Exercise_4_1: Write the function strindex(s,t) which returns the position of the rightmost occurrence of t in s, or -1 if there is none.
Author: Akshat Darji
Created: 12 July 2024
Modified: 12 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
int strindex(char s[], char t); /*Takes the character string and character t, and finds the righmost occurance of char t from the given character string*/


/** MAIN PROGRAM */
/*
 * main: Prompts the user for a string and a character, then finds the rightmost occurrence of
 *       the character in the string using the strindex function.
*/

int main() {
    char s[1000]; /* Array to store the input string */
    char t;       /* Variable to store the character to find */
    char choice;  /* Variable to store the user's choice for continuation */

    do {
        printf("Enter the string: ");  /* Prompt the user to enter the string */
        if (fgets(s, sizeof(s), stdin) == NULL) { /* Read the string from the user and handle input error */
            handle_error(ERROR_INVALID_INPUT); /* Handle invalid input error */
            return 1;
        }
        s[strcspn(s, "\n")] = '\0';    /* Remove the newline character from the input */

        printf("Enter the character to find: ");  /* Prompt the user to enter the character */
        t = getchar();                            /* Read the character from the user */
        if (t == '\n') {  /* Handle case where no character is entered */
            handle_error(ERROR_INVALID_INPUT); /* Handle invalid input error */
            return 1;
        }
        while (getchar() != '\n');                /* Clear the input buffer */

        int iPosOfChar = strindex(s, t);  /* Call the strindex function and store the result */

        printf("Rightmost occurrence of '%c': %d\n", t, iPosOfChar);  /* Print the result */

        printf("Do you want to search another character? (y/n): ");  /* Prompt for continuation */
        choice = getchar();  /* Read user's choice */
        while (getchar() != '\n');  /* Clear the input buffer */

    } while (choice == 'y' || choice == 'Y');  /* Continue if the user chooses 'y' or 'Y' */

    return 0;  /* Exit the program */
}


/*
 * strindex(s,t): accepts the char s[] and character to find the rightmost occurance of char in str
 * Author: Akshat Darji
 * Created: 12 July 2024
 * Modified: 12 July 2024
*/

int strindex(char s[], char t){ /*taking the character string and character t*/
	int found = 0; /*Stores the value of rightmost position of char t in given s[]*/
	int len = strlen(s); /*Finding the length of char s[]*/

	for(int i=len-1; i>=0;i--){ /*Decrement loop to start the i pointer from n-1 pos of char s*/
		if(s[i]==t){ /*checks that s[i] is matched with given char t*/
			found = i; /*If matched then store that position into found*/
			break; /*Break*/
		}
	}
	return found;  /*Return the answer*/
}

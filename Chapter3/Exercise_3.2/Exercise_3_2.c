/**
Exercise_3_2: Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters.
Author: Akshat Darji
Created: 9 July 2024
Modified: 9 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>
#include "../../error_handling.h"

/** MARCO DEFINATIONS */
#define MAX_STRING_LENGTH 100

/** FUNCTION PROTOTYPES */
void escape(char s[], char t[]); //Takes S and T and updated char string copied to char t[]

/** MAIN PROGRAM */
/*
 * main: takes string t and put the real characters in place of tab and newLine
*/

int main() {
    char cS[MAX_STRING_LENGTH];  /* Input string */
    char cT[MAX_STRING_LENGTH];  /* Output string */
    char choice;                /* Variable to store the user's choice for continuation */

    do {
        printf("Enter a string to be converted (up to 1000 characters): ");
        if (fgets(cS, sizeof(cS), stdin) == NULL) {
            handle_error(ERROR_INVALID_INPUT);  /* Handle invalid input error */
            return 1;
        }
        cS[strcspn(cS, "\n")] = '\0';  /* Remove newline character if present */

        /* Check for input length exceeding maximum allowed length */
        if (strlen(cS) >= MAX_STRING_LENGTH) {
            handle_error(ERROR_INPUT_TOO_LONG);  /* Handle input too long error */
            return 1;
        }

        escape(cS, cT);  /* Call the escape function */

        printf("Converted string: %s\n", cT);  /* Print the resulting string */

        printf("Do you want to convert another string? (y/n): ");
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

//if any functions then mention like below
/*
 * escape(char s[], char t[]): takes char s[] and performing the operation and store it in char t[]
 * Author: Akshat Darji
 * Created: 9 July 2024
 * Modified: 10 July 2024
*/

void escape(char s[], char t[]){
	char iC;
	int iI, iJ; /*for traversing in the string*/
	iI=iJ=0; /*initially i and j marked as zero*/
	while((s[iI])!='\0'){  /*terminaton condition*/
		switch(s[iI]){   /*checks the s[i] and accordingly performs the cases*/
			case '\n':         /*case for the new line character*/
				t[iJ] = '\\';    /*at jth position of t[j] put '/'*/
				iJ++;            /*then increase the pointer*/
				t[iJ] = 'n';     /*and then again put the 'n' on t[j]th pos*/
				break;
			case '\t':              /*case for the tab */
				t[iJ] = '\\';
				iJ++;
				t[iJ] = 't';
				
				break;
			default:
				t[iJ]=s[iI];  /*default case for simple words*/
				break;
		}
		iI++;   //increasing the both pointers
		iJ++;
	}
	t[iJ] = '\0';

}

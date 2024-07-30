/**
Exercise_3_6: Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough.
Author: Akshat Darji
Created: 11 July 2024
Modified: 11 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>
#include<limits.h> /*For use of INT_MAX and INT_MIN*/
#include "../../error_handling.h"

/** MARCO DEFINATIONS */
#define MAX_STRING_LENGTH 1000

/** FUNCTION PROTOTYPES */
void itoa(int iN, char s[], int iWidth);
void reverse(char s[], int iWidth);

/** MAIN PROGRAM */
/*
 * main: takes three arguments iN, iWidth and character string to fill the padding as per the user width
*/


int main() {
    int iN;             /* Variable to store the user's input integer */
    int iWidth;         /* Variable to store the user's input field width */
    char choice;        /* Variable to store the user's choice for continuation */
    char cS[MAX_STRING_LENGTH]; /* Array to store the resulting string */

    do {
        printf("Enter the number: ");  /* Prompt the user to enter the number */
        if (scanf("%d", &iN) != 1) {   /* Read the number from user and handle invalid input */
            handle_error(ERROR_INVALID_INPUT);  /* Handle invalid input error */
            while (getchar() != '\n'); /* Clear input buffer */
            return 1;
        }

	if(iN < INT_MIN || iN > INT_MAX){ /*check for int range*/
		handle_error(INT_OUT_OF_RANGE); /*handle the error*/
		while(getchar() != '\n'); /*Clering the buffer*/
		return 1;
	}


        printf("Enter the minimum field width: ");  /* Prompt the user to enter the field width */
        if (scanf("%d", &iWidth) != 1 || iWidth < 0) { /* Read the field width and validate it */
            handle_error(ERROR_INVALID_INPUT);  /* Handle invalid input error */
            while (getchar() != '\n'); /* Clear input buffer */
            return 1;
        }
	
	printf("Converted string with width %d: is ", iWidth);
        itoa(iN, cS, iWidth);  /* Call the itoa function with iN, s, and iWidth */

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
 * itoa: Converts the integer iN to a string with a minimum field width iWidth
 * Author: Akshat Darji
 * Created: 21 Jun 2024
 * Modified: 21 Jun 2024
*/

void itoa(int iN, char cS[], int iWidth){
	int iIndex, iSign; /* Initialize i for traversing the number and sign to check whether the n                              umber is positive or negative */
	if((iSign=iN)<0){ /* Check if number is negative */
		iN = -iN; /* Make number positive */
	}
	iIndex = 0; /* Initialize i with zero */
	while(iN>0){  /* Termination condition */
		cS[iIndex] = iN % 10 + '0'; /* Break the number into digits and store them in cS */
		iIndex++; /* Increment the pointer of cS to the next position */
		iN = iN/10; /* Delete the last digit from the number */
	}
	if(iSign < 0){ /* If the number was negative, add the '-' sign */
		cS[iIndex] = '-';
		iIndex++; /* Increment i by one to traverse into the cS */
	}
	cS[iIndex] = '\0'; /* Null-terminate the string */
	reverse(cS, iWidth); /* Reverse the string to get the correct order */

}

/*
 * reverse: Reverses the string s[] in place and adds padding if necessary
 * Author: Akshat Darji
 * Created: 21 Jun 2024
 * Modified: 21 Jun 2024
*/

void reverse(char s[], int iWidth){
        char t[1000];   /*reverse number stored into the t[]*/
        int len = strlen(s); /*finding the length of the char strind s[] and store it in len*/
        int index = 0;  /*initialize index with zero*/
	int iActualWidth = iWidth - len; /*Finding the actual width*/
        for(int j=len-1;j>=0;j--){   /*starting the loop from the last pos of s[]*/
                t[index] = s[j]; /*and copy the character one by one in the t[index] position*/
                index++; /*increment the index to traverse into the t[]*/
        }
        t[index] = '\0'; /*at the end put the null charater for the string termination*/
	char ans[1000]; /*Answer string to store the final answer*/
	//printf("%s\n", t);
	int iI = 0; /*Initializw the pointer with zero*/
	for(int i=0;i<iActualWidth;i++){ /*run the loop till actualwidth*/
		ans[i] = '-';  /*Till the actualwidth put the '-' in ans[]*/
		//iI++;
	}
	for(int j=iActualWidth;j<iWidth;j++){ /*From actualwidth to the iWdith run the loop*/
		ans[j] = t[j-iActualWidth]; /*Put the digits stored in t[] to get --125*/
	}
	ans[iWidth] = '\0'; /*Terminate the string*/
	printf("%s\n", ans); /*Printing the result*/
}

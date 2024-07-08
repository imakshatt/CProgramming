/**
Exercise_2_10: Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else. 
Author: Akshat Darji
Created: 8 July 2024
Modified: 8 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */

/** MAIN PROGRAM */
/*
 * main: Takes the string of characters for typeconversion UPPER to LOWER without using if Else
*/


int main(){
	int iC;
	int iN;
	while((iC=getchar())!=EOF){
		iN = (iC>=65 && iC<=90) ? (iC + 'a' - 'A') : iC;
		putchar(iN);
	}
	return 0;
}



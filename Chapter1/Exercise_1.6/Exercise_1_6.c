/**
Exercise_1.6: verify that the expression c=getchar()!=EOF is 0 or 1
Author: Akshat Darji
Created: 24 Jun 2024
Modified: 24 JUn 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */


/** MAIN PROGRAM */
/*
 * main: takes the character and checks the condition
*/


int main(){
	char choice;
	do{
		if(getchar()!=EOF){ /*Termination condition*/
                	printf("1"); /*Printing 1 if the expression is valid*/
        	}
        	else{
                	printf("0"); /*Else printing 0 if the expression is not valid*/
        	}

		printf("Do you want to generate another table? (y/n): ");
		scanf("%c", &choice);
	}while(choice=='y' || choice=='Y');
	return 0;
}


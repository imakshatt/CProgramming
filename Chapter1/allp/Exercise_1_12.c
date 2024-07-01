/**
Exercise_1_12: write a program that prints its input one word per line
Author: Akshat Darji
Created: 25 Jun 2024
Modified: 25 JUn 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */


/** MAIN PROGRAM */
/*
 * main: using state keep track in words in the text stream
*/


int main(){
	int iC;
	while((iC=getchar())!=EOF){
		if(iC==' ' || iC=='\t' || iC=='\n'){
			printf("\n");
			continue;
		}
		else{
			putchar(iC);
		}
	}
}

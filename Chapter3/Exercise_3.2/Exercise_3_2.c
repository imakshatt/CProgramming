/**
Exercise_3_2: Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters.
Author: Akshat Darji
Created: 8 July 2024
Modified: 8 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
void escape(char s[], char t[]);

/** MAIN PROGRAM */
/*
 * main: takes string t and put the real characters in place of tab and newLine
*/


int main(){
	int iC;
	while((iC=getchar())!=EOF){
		switch(iC){
			case '\n':
				printf("\\");
				printf("n");
			case '\t':
				printf("\\");
				printf("t");
			default:
				putchar(iC);
		}
	}
	return 0;
}


//if any functions then mention like below
/*
 * functionName: detail of that function like what it accepts
 * Author: Akshat Darji
 * Created: 21 Jun 2024
 * Modified: 21 Jun 2024
*/

void functionName(){

}

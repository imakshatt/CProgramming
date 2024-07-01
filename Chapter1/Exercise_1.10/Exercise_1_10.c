/**                                                             Exercise_1_10: write a program to copy its input to output, replaceing each tab by \t, each backspace by \b, and each backslash by \\. This makes tab and backspaces visible in an unambigious way.
Author: Akshat Darji                                            Created: 24 Jun 2024                                            Modified: 24 JUn 2024                                           */

/** REQUIRED HEADER FILES */
#include<stdio.h>
#define BLANK '_'

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */


/** MAIN PROGRAM */                                             /*                                                               * main: 
*/

int main(){
        int iC;
	while((iC=getchar())!=EOF){
		if(iC=='\t'){
			putchar('\\');
			putchar('t');
		}
		else if(iC=='\b'){
			putchar('\\');
			putchar('b');
		}
		else if(iC=='\\'){
			putchar('\\');
		}
		putchar(iC);
	}
}/*END MAIN*/

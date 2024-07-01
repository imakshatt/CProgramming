/**                                                             Exercise_1_9: write a program to copy its input to its output, replacing each string of one or more blanks by a single blank
Author: Akshat Darji                                            Created: 24 Jun 2024                                            Modified: 24 JUn 2024                                           */

/** REQUIRED HEADER FILES */
#include<stdio.h>
#define BLANK '_'

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */


/** MAIN PROGRAM */                                             /*                                                               * main: remove the extra space from the given string
*/


int main(){
        int iC, b;
	b = BLANK;
	while((iC=getchar())!=EOF){
		if(iC==' '){
			if(b!=' '){
				putchar(iC);
			}
		}
		else{
			putchar(iC);
		}
		b=iC;
	}
}/*END MAIN*/



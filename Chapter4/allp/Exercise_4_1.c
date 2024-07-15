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
int strindex(char s[], char t);

/** MAIN PROGRAM */
/*
 * main: finds the rightmost occurace of char t in the char s[].
*/


int main(){
	char s[] = "Prerequisite";
	char t = 't';

	int iPosOfChar = strindex(s, t);
	printf("%d\n", iPosOfChar);
	return 0;
}

/*
 * strindex(s,t): accepts the char s[] and character to find the rightmost occurance of char in str
 * Author: Akshat Darji
 * Created: 12 July 2024
 * Modified: 12 July 2024
*/

int strindex(char s[], char t){
	int found = 0;
	int len = strlen(s);

	for(int i=len-1; i>=0;i--){
		if(s[i]==t){
			found = i;
			break;
		}
	}
	return found;
}

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
 * main: finds the rightmost occurace of char t in the char s[].
*/


int main(){
	char s[] = "Prerequisite"; /*String from user in which i have to find the char t*/
	char t = 't'; /*Character t*/

	int iPosOfChar = strindex(s, t); /*Call the function strindex and store the ans in iPosOfC*/
	printf("%d\n", iPosOfChar); /*Print the ans*/
	return 0;
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

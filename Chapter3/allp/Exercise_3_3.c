/**
Exercise_3_3: Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.
Author: Akshat Darji
Created: 10 July 2024
Modified: 10 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>
/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
void expand(char s1[], char s2[]); //expands the shorthand notations like a-z to abcd ....z

/** MAIN PROGRAM */
/*
 * main: Takes s1[] as an input and pass it to the function expand() to expand it to actual output as mentioned
*/


int main(){
	char s1[] = "a-z0-9";  //Input String s1
	char s2[1000];	       //Output String s2, expanded version of s1 is copied to s2
	expand(s1, s2);        //Function takes s1 and s2 to do expansion of s1
	printf("%s\n", s2);    //Print the Output
	return 0;
}

/*
 * expand(char s1[], char s2[]): takes s1 as an argument and expand it into char string s2[].
 * Author: Akshat Darji
 * Created: 10 July 2024
 * Modified: 10 July 2024
*/

void expand(char s1[], char s2[]){
	int iString1 = 0;  //for traversing into the string1
	int iString2 = 0;  //for traversing into the string2
	int iLenString1 = strlen(s1);  //finding the length of String1 for termination condition
	int iJ; //for traversing when desh comes
	
	while(iString1<iLenString1){   //termination condition
		if(s1[iString1]==45){   //checks whether the character is '-'
			for(iJ=s1[iString1-1]; iJ<=s1[iString1+1]; iJ++){   //now get the start and end index
				s2[iString2]=iJ;  //put the elements in between range of start and end
				iString2++;   //increament the iString2 to go to next position in s2[]
			}
		}
		iString1++;  //for traversing into the s1[]
	}
	s2[iString2] = '\0';  //at the end put the null character in the s2[] for the termination of string
}

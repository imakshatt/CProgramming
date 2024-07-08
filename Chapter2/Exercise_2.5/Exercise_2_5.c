/**
Exercise_2_5: Write the function any(s1,s2), which returns the first location in a string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library function strpbrk does the same job but returns a pointer to the location.)
Author: Akshat Darji
Created: 8 July 2024
Modified: 8 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
int any(char s1[], char s2[]); //it return the the index of the founded char from s1 into s2 

/** MAIN PROGRAM */
/*
 * main: takes two string and call the function any(s1, s2) to get the index of an matched element
*/


int main(){
	char s1[] = "c programming"; //String-1
	char s2[] = "perl"; // String-2

	int iPosition = any(s1, s2);  //Passing the s1 and s2 into function any()
	printf("Position of matched element: %d", iPosition); //print the position of the matched index
	return 0;
}


/*
 * any(s1, s2): Takes two string and find the index of matched element from string s11 using string s2
 * Author: Akshat Darji
 * Created: 8 July 2024
 * Modified: 8 July 2024
*/

int any(char s1[], char s2[]){
	int i, j;
	int found = 0;
	int pos = -1;
	int iLenS1 = strlen(s1);
	int iLenS2 = strlen(s2);
	for(i=0; i<iLenS1; i++){
		for(j=0;j<iLenS2;j++){
			if(s1[i]==s2[j]){
				found = 1;
				pos = i+1;
				break;
			}
		}
		if(found == 1){
			break;
		}
	}
	return pos;
}

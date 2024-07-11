/**
Exercise_3_2: Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters.
Author: Akshat Darji
Created: 9 July 2024
Modified: 9 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
void escape(char s[], char t[]); //Takes S and T and updated char string copied to char t[]

/** MAIN PROGRAM */
/*
 * main: takes string t and put the real characters in place of tab and newLine
*/


int main(){
	char s[]= "Hello guys	joshi	is";  //Main char string to be converted in real char
	char t[1000]; //answer string
	escape(s, t); //function takes s and t
	printf("%s\n", t); //print the resulting string
	return 0;
}


//if any functions then mention like below
/*
 * escape(char s[], char t[]): takes char s[] and performing the operation and store it in char t[]
 * Author: Akshat Darji
 * Created: 9 July 2024
 * Modified: 10 July 2024
*/

void escape(char s[], char t[]){
	char iC;
	int i, j; //for traversing in the string
	i=j=0; //initially i and j marked as zero
	while((s[i])!='\0'){  //terminaton condition
		switch(s[i]){   //checks the s[i] and accordingly performs the cases
			case '\n':         //case for the new line character
				t[j] = '\\';    //at jth position of t[j] put '/'
				j++;            //then increase the pointer
				t[j] = 'n';     //and then again put the 'n' on t[j]th pos
				break;
			case '\t':              //case for the tab 
				t[j] = '\\';
				j++;
				t[j] = 't';
				
				break;
			default:
				t[j]=s[i];  //default case for simple words
				break;
		}
		i++;   //increasing the both pointers
		j++;
	}
	t[j] = '\0';

}

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
void escape(char s[], char t[]);

/** MAIN PROGRAM */
/*
 * main: takes string t and put the real characters in place of tab and newLine
*/


int main(){
	char s[]= "Hello guys	joshi	is";
	char t[1000];
	escape(s, t);
	printf("%s\n", t);
	return 0;
}


//if any functions then mention like below
/*
 * functionName: detail of that function like what it accepts
 * Author: Akshat Darji
 * Created: 21 Jun 2024
 * Modified: 21 Jun 2024
*/

void escape(char s[], char t[]){
	char c;
	int i, j;
	i=j=0;
	while((s[i])!='\0'){
		switch(s[i]){
			case '\n':
				t[j] = '\\';
				j++;
				t[j] = 'n';
				
				break;
			case '\t':
				t[j] = '\\';
				j++;
				t[j] = 't';
				
				break;
			default:
				t[j]=s[i];
				break;
		}
		i++;
		j++;
	}
	t[j] = '\0';

}

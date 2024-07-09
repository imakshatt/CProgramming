/**
Exercise_3_2: Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters.
Author: Akshat Darji
Created: 8 July 2024
Modified: 8 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#define MAXLINE 1000
/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
void escape(char s[], char t[]);
int mgetline(char line[], int maxline);

/** MAIN PROGRAM */
/*
 * main: takes string t and put the real characters in place of tab and newLine
*/


int main(){
	char s[MAXLINE], t[MAXLINE];

	mgetline(t, MAXLINE);
	escape(t,s);
	printf("%s", s);
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
	int i, j;
	i=j=0;
	while(t[i] != '\0'){
		switch(t[i]){
			case '\t':
				s[j] = '\\';
				j++;
				s[j] = 't';
				break;
			case '\n':
				s[j] = '\\';
				j++;
				s[j] = 'n';
				break;
			default:
				s[j] = t[i];
				break;
		}
		i++;
		j++;
	}
	s[j] = '\0';
}

int mgetline(char s[], int lim){
	int i, c;

	for(i=0;i<lim-1 && (c=getchar())!=EOF; i++){
		s[i]=c;
	}
	s[i] = '\0';
}

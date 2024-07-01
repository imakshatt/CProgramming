/**
Exercise_1_14: Write a program to print a histogram of the frequencies of different characters in its input
Author: Akshat Darji
Created: 25 Jun 2024
Modified: 25 JUn 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */


/** MAIN PROGRAM */
/*
 * main: Use HAshing to keep track of characters and then print the histogram of that frequency
*/


int main(){
	int iC;
	int iCharacters[26];
	for(int i=0;i<26;i++){
		iCharacters[i] = 0;
	}

	while((iC=getchar())!=EOF){
		if(iC>=65 && iC<=90){
			iCharacters[iC-'A']++;
		}
		else if(iC>=97 && iC<=122){
			iCharacters[iC-'a']++;
		}
	}
	for(int i=0;i<26;i++){
		printf("%d ", iCharacters[i]);
	}
	printf("\n");

	for(int i=0;i<26;i++){
		if(iCharacters[i]>0){
			printf("%c: ", i+97);
			for(int j=0;j<iCharacters[i];j++){
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}


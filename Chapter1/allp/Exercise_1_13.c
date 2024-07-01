/**
Exercise_1_13: write a program to print the histrogram of the length of words in its input.
Author: Akshat Darji
Created: 21 Jun 2024
Modified: 21 JUn 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */


/** MAIN PROGRAM */
/*
 * main: detail overview of main function
*/



int main(){
	int iC;
	int iFlag = 0;
	int iContainer = 0;
	while((iC=getchar())!=EOF){
		iFlag++;
		if(iC==' ' || iC=='\n' || iC=='\t'){
			iContainer = iFlag;
			iFlag = 0;
			iContainer = iContainer-1;
                        printf("%d: ", iContainer);
			for(int i=0;i<iContainer;i++){
				printf("*");
			}
			printf("\n");
		}
                /*iContainer=0;
		}
		iContainer = iContainer-1;
		printf("%d: ", iContainer);
		for(int i=0;i<iContainer;i++){
			printf("*");
		}
		iContainer=0;*/
	}
}

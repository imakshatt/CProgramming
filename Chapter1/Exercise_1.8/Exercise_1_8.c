/**
Exercise_1_8: Write a program to count blanks, tabs and new line
Author: Akshat Darji
Created: 24 Jun 2024
Modified: 24 JUn 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
void blankCount(int iBlank, int iC);
void tabsCount(int iTabs, int iC);
void lineCount(int iLines, int iC);


/** MAIN PROGRAM */
/*
 * main: Initialize the iBlank, iTabs and iLines with the Zero and pass it through the corresponding function blankCount(), tabsCount() and lineCount() for count the blank, tabs and lines
*/


int main(){
	int iBlank;
	int iTabs;
	int iLines;
	int iC;
	
	iBlank = 0;
	iTabs = 0;
	iLines = 0;

	while((iC=getchar())!=EOF){
		if(iC==' '){
			iBlank++;
		}
		else if(iC=='\t'){
			iTabs++;
		}
		else if(iC=='\n'){
			iLines++;
		}
	}
	printf("Total # of Blanks are: %d\n", iBlank);
	printf("Total # of Tabs are: %d\n", iTabs);
	printf("Total # of Lines are: %d\n", iLines);

	return 0;
}

//Functions if any
/*
 * blankCount(): To count the blank in the text stream
 * Author: Akshat Darji
 * Created: 24 Jun 2024
 * Modified: 24 Jun 2024
*/
void blankCount(int iBlank, int iC){
	while((iC=getchar())!=EOF){
		if(iC==' '){
			iBlank++;
		}
	}
	printf("Total Blanks in the text Stream: ");
	printf("%d\n", iBlank);
}

/*
 * tabsCount(): To count the tabs in the text stream
 * Author: Akshat Darji
 * Created: 24 Jun 2024
 * Modified: 24 Jun 2024
*/
void tabsCount(int iTabs, int iC){
        while((iC=getchar())!=EOF){
                if(iC=='\t'){
                        iTabs++;
     	         }
        }
	printf("Total Tabs in the text Stream: ");
        printf("%d\n", iTabs);
}

/*
 * lineCount(): To count the # of lines in the text stream
 * Author: Akshat Darji
 * Created: 24 Jun 2024
 * Modified: 24 Jun 2024
*/
void lineCount(int iLines, int iC){
        while((iC=getchar())!=EOF){
                if(iC=='\n'){
                        iLines++;
                 }
        }
	printf("Total Lines in the text Stream: ");
        printf("%d\n", iLines);
}

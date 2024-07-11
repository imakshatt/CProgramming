/**
Exercise_3_6: Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough.
Author: Akshat Darji
Created: 11 July 2024
Modified: 11 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
void itoa(int iN, char s[], int iWidth);
void reverse(char s[], int iWidth);

/** MAIN PROGRAM */
/*
 * main: takes three arguments
*/


int main(){
	char s[1000];
	int iN = 4567;
	int iWidth = 7;
	itoa(iN, s, iWidth);
	return 0;
}


//if any functions then mention like below
/*
 * functionName: detail of that function like what it accepts
 * Author: Akshat Darji
 * Created: 21 Jun 2024
 * Modified: 21 Jun 2024
*/

void itoa(int iN, char s[], int iWidth){
	int index, sign;
	if((sign=iN)<0){
		iN = -iN;
	}
	index = 0;
	while(iN>0){
		s[index] = iN % 10 + '0';
		index++;
		iN = iN/10;
	}
	if(sign < 0){
		s[index] = '-';
		index++;
	}
	s[index] = '\0';
	reverse(s, iWidth);

}


void reverse(char s[], int iWidth){
        char t[1000];   //reverse number stored into the t[]
        int len = strlen(s); //finding the length of the char strind s[] and store it in len
        int index = 0;  //initialize index with zero
        for(int j=len-1;j>=0;j--){   //starting the loop from the last pos of s[]
                t[index] = s[j]; //and copy the character one by one in the t[index] position
                index++; //increment the index to traverse into the t[]
        }
        //t[index] = '\0'; //at the end put the null charater for the string termination
        
	int iIndex = 0;
	for(int i=0;i<len;i++){
		t[i+iWidth] = t[i];
		iIndex++;
	}
	int iActualWidth = (len - iWidth);
	for(int i=0;i<iActualWidth;i++){
		t[i] = '-';
		iIndex++;
	}
	t[iIndex] = '\0';
	printf("%s\n", t);
}

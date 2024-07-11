/**
Exercise_3_5: Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s. In particular, itob(n,s,16) formats s as a hexadecimal integer in s.
Author: Akshat Darji
Created: 11 July 2024
Modified: 11 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<ctype.h>
#include<string.h>

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
void itob(int iN, char s[], int base); /*function which takes the Number, char string and base to convert iN
					 into Base B*/
void reverse(char s[]);                /*Function to reverse the char s[]*/

/** MAIN PROGRAM */
/*
 * main: takes the number and base from the user and sends to the function itob that convert iN to base B
*/


int main(){
	int iN, base;  /*initializing the iN and base as int type*/
	printf("Enter the Number: "); /*Printing the msg for user as intended to take the number*/
	scanf("%d", &iN); /*Takes the number from user and stores it into iN*/
	char s[1000]; /*answer string*/
	printf("\nEnter the base that converts iN into Base b: "); /*Printing the message for Base*/
	scanf("%d", &base); /*taking the base from the user and srote in base*/
	itob(iN, s, base); /*sends the iN, s and base to the function itob()*/
	return 0;	
}

/*
 * itob(): It accepts the number, answer string s[] and the base b to convert the iN into base B
 * Author: Akshat Darji
 * Created: 11 July 2024
 * Modified: 11 July 2024
*/

void itob(int iN, char s[], int base){ /*Taking the NUmber, char string and base */
	int index = 0;  /*for traversing into the result string s[]*/
	int iRemainder = 0; /*It stores the reminder after the modulo operation i.e. 255%16 result*/
	if(base < 2 || base > 36){  /*Test case for validating the base terminates if wrong test case*/
		s[0] = '\0';   /*If my base is not valid then return the NULL string as an answer*/
		return;
	}

	while(iN>0){  /*Termination Condition*/
		iRemainder = iN % base;   /*Modulo operation to find the reminder*/
		if(iRemainder>=10){   /*If reminder is >=10 then convert it into the A......F*/
			//convert into char
			s[index] = iRemainder + 'A' - 10;  /*Converting into A>......F*/ 
		}
		else{
			s[index] = iRemainder + '0';
		}
		index++;  /*Incrementing the index to traverse into the char string s[]*/
		iN = iN/base;   /*Divide the iN by base for delete the INT remainder*/
	}
	reverse(s);   /*Sends the char s[] to reverse function to convert LSB to MSB*/
}

void reverse(char s[]){
        char t[1000];   //reverse number stored into the t[]
        int len = strlen(s); //finding the length of the char strind s[] and store it in len
        int index = 0;  //initialize index with zero
        for(int j=len-1;j>=0;j--){   //starting the loop from the last pos of s[]
                t[index] = s[j]; //and copy the character one by one in the t[index] position
                index++; //increment the index to traverse into the t[]
        }
        t[index] = '\0'; //at the end put the null charater for the string termination
        printf("%s\n", t); //printing the answer.
}

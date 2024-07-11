/**
Exercise_3_4: In a two's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why not. Modify it to print that value correctly, regardless of the machine on which it runs.
Author: Akshat Darji
Created: 10 July 2024
Modified: 10 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<ctype.h>
#include<string.h>

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
void itoa(int n, char s[]); //function which converts the number into the char sring
void reverse(char s[]);  //resulting char string is reversed using this function

/** MAIN PROGRAM */
/*
 * main: main takes the number and converts that number into the character string
*/


int main(){
	char s[1000]; //to store the answer resulting char string of N = -128
        int n = -128;  //number which is entered by user to be converted into the char string
        itoa(n, s); //pass the number and s[] as an argument to convert the number into the char string
}

/*
 * itoa(): it accepts the number to be converted into the character string and char s[] string to store the ans
 * Author: Akshat Darji
 * Created: 10 Jun 2024
 * Modified: 10 Jun 2024
*/

void itoa(int n, char s[]){  //takes the number and s[]
	 int i, sign;  //initialize i for traversing to the number and sign to check whether the number is + or -
        if((sign=n)<0){     //check if number is lesser then goes into the if condition
                n = -n;   //make number positive by n = -(-128) == 128
        }
        i = 0;  //here initialize i with zero 
        while(n>0){   //termination condition
                s[i] = n % 10 + '0';  //breaks the number into one char like 128 into 8, 2, 1 and store in s[i]
                i++; //increment the pointer of s[] to the next position
                n = n/10;  //here we delete the last digit from the number 
        }
        if(sign < 0){   //at the end if sign is -ve then at the last position put the '-' sign
                s[i] = '-';
                i++;  //increment the i by one to traverse into the s[]
        }
        s[i] = '\0';   //at the last index put the null character for the string termination
        reverse(s);   //at the end reverse the entire s[] to get the answer
}


/*                                                                                                                * reverse(): it accepts the char s[] to reverse the answer string
 * Author: Akshat Darji
 * Created: 10 Jun 2024                                                                                           * Modified: 10 Jun 2024
*/

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

/**
Exercise_2_2: write a loop euivalant to the for loop above without && and ||.
Author: Akshat Darji
Created: 4 July 2024
Modified: 4 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */


/** MAIN PROGRAM */
/*
 * main: Using a for loop without using && and || Equivalant to below snippet
 * for(i=0;i<lim-1 && (c=getchar())!='\n' && c != EOF; i++){
 *	s[i] = c;
 * }
*/


int main(){
	int iLim = 10; //Limit of the loop
	char s[iLim]; //empty string array S 
	int i; //For the loop iteration
	int iC;
	for(i=0;i<iLim-1;i++){
		if(iC=getchar()!='\n'){
			if(iC != EOF){
				s[i] = iC;
			}
		}
	}
	return 0;

}


//if any functions then mention like below
/*
 * functionName: detail of that function like what it accepts
 * Author: Akshat Darji
 * Created: 21 Jun 2024
 * Modified: 21 Jun 2024
*/

/*void functionName(){

}*/

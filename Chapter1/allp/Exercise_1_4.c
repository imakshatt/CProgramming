/**
Write a Program  to print the corresponding Celsius to Fahrenheit table.
Author: Akshat Darji
Created: 21 Jun 2024
Modified: 21 JUn 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>


/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
void CelToFah(int iLower, int iUpper, int iStep);

/** MAIN PROGRAM */
/*
 * main: Takes Lower limit, Upper limit, step size and pass it to the CelToFah() function for print the table of Cel to Fah
*/


int main(){
	int iLower = 0;
	int iUpper = 300;
	int iStep = 20;
	printf("Celcius\tFahrenheit\n");

	CelToFah(iLower, iUpper, iStep);
}/*End of main Function*/


//if any functions then mention like below
/*
 * CelToFah(): takes the lower limit, upper limit, step size for the table
 * Author: Akshat Darji
 * Created: 21 Jun 2024
 * Modified: 21 Jun 2024
*/

void CelToFah(int iLower, int iUpper, int iStep){
	float fFah; /*Takes the Fahrenheit Value*/
	float fCel; /*Takes the Celcius Value*/

	fCel=iLower;
	while(fCel <= iUpper){
		fFah = (9*fCel/5) + 32;
		printf("%3.0f\t%6.1f\n", fCel, fFah);
		fCel = fCel + iStep;
	}	
}


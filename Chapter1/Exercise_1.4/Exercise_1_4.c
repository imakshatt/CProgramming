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
void CelToFah(int iLower, int iUpper, int iStep); /*Converts Cel to Fah*/

/** MAIN PROGRAM */
/*
 * main: Takes Lower limit, Upper limit, step size and pass it to the CelToFah() function for print the table of Cel to Fah
*/


int main(){
	int iLower, iUpper, iStep; /*Define iLower, iUpper and iStep(int type)*/
	char choice; /*For taking 'Y' or 'N', for program execution*/

	do{
		printf("Enter the lower limit (in Celsius)->MUST BE AN INT VALUE: ");
		scanf("%d", &iLower); /*Taking the lower limit from user and stored in iLower*/

		printf("Enter the Upper limit (in Celsius)->MUST BE AN INT VALUE: ");
		scanf("%d", &iUpper); /*Taking the Upper limit from user and stored in iUpper*/

		printf("Enter the step size ->MUST BE AN INT VALUE: "); 
		scanf("%d", &iStep); /*Taking the steps from user and stored in iStep*/

		printf("Celsius\tFahrenheit\n");
        	CelToFah(iLower, iUpper, iStep); /*Calling the function*/

        	// Asking user if they want to continue
        	printf("Do you want to generate another table? (y/n): ");
        	scanf(" %c", &choice); /*Takes choice press 'y' or 'Y' if continue else press 'n'*/


	}while(choice == 'y' || choice == 'Y'); /*End of Do-While Loop*/

	return 0;
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

	fCel=iLower; /*Stores the lower limit in the fCel*/
	while(fCel <= iUpper){  /*Termination condition we have to go through till UPPER limit*/
		fFah = (9*fCel/5) + 32; /*Equation to convert cel to fah*/
		printf("%3.0f\t%6.1f\n", fCel, fFah); /*Pritnting the values*/
		fCel = fCel + iStep; /*Increment by steps that we take from user*/
	}	
} /*End of Function*/


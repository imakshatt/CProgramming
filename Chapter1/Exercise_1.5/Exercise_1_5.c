/**
Exercise_1_5: Modify the temprature conversion program to print the table in reverse order.
Author: Akshat Darji
Created: 24 Jun 2024
Modified: 24 JUn 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
void reverseFahtoCel(int iUpper, int iLower, int iStep);

/** MAIN PROGRAM */
/*
 * main: takes the value of iUpper, iLower and iStep and passed to the function reverseFahtoCel for the reverse table.
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

                printf("Fahrenheit\tCelsius\n");
                reverseFahtoCel(iUpper, iLower, iStep); /*Calling the function*/

                // Asking user if they want to continue
                printf("Do you want to generate another table? (y/n): ");
                scanf(" %c", &choice); /*Takes choice press 'y' or 'Y' if continue else press 'n'*/


        }while(choice == 'y' || choice == 'Y'); /*End of Do-While Loop*/

        return 0;
} /*End of main*/


//if any functions then mention like below
/*
 * reverseFahtoCel(): takes the lower limit, upper limit, step size for the Revrese table
 * Author: Akshat Darji
 * Created: 24 Jun 2024
 * Modified: 24 Jun 2024
*/

void reverseFahtoCel(int iUpper, int iLower, int iStep){
	float fFah; /*Takes the Fahrenheit Value*/
	float fCel; /*Takes the Celcius Value*/

	for(int i=iUpper ; i>=iLower ; i--){ /*Decrementing LOOP*/
		fCel = 5 * (i-32) / 9;  /*Equation to convert FAh to Cel*/
		printf("%3.0f\t%6.2f\n", fFah, fCel); /*Printing the values*/
	}
} /*End of Function*/

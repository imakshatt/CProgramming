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
	int iUpper = 300;
	int iLower = 0;
	int iStep = 20;

	printf("Fahrenheit\tCelcius\n");
	void reverseFahtoCel(iUpper, iLower, iStep);
	return 0;

}


//if any functions then mention like below
/*
 * reverseFahtoCel(): takes the lower limit, upper limit, step size for the Revrese table
 * Author: Akshat Darji
 * Created: 24 Jun 2024
 * Modified: 24 Jun 2024
*/

void reverseFahtoCel(int iUpper, int iLower, int iStep){
	float fFah;
	float fCel;

	for(int i=iUpper ; i>=iLower ; i--){
		fCel = 5 * (i-32) / 9;
		printf("%3.0f\t%6.2f\n", fFah, fCel);
	}
}

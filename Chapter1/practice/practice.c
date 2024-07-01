/**
This File is created to Practice the Logics of code for demo purposes 
practice file with coading standards
Author: Akshat Darji
Created: 21 Jun 2024
Modified: 21 Jun 2024
*/

/** REQUIRED HEADER FILES */
#include<stdio.h>


/** MARCO DEFINATIONS */

/** FUNCTION PROTOTYPES */
void ConvertFahrenheitToCelsius(int upper, int lower, int step);

/** MAIN PROGRAM */
/*
main: Accept Upper limit, lower limit and step size and show the table till upper limit that shows fahrenheit to celsius till lower limit to upper limit
*/


int main(){
        int iLower; /*contains the lower limit of the table*/
	int iUpper; /* contains the upper limit of the table */
	int iStep; /* Contains step size */

	/*
	 * get lower limit, upper limit and step value and pass it to fun
	*/

	iLower = 0;
	iUpper = 300;
	iStep = 20;

	ConvertFahrenheitToCelsius(iLower, iUpper, iStep);
	return 0;
	
	
}/**End main()*/


/*
 * ConvertFahrenheitToCelsius: Show the table of fahrenheit to celsius
 * Author: Akshat Darji
 * Created: 21 Jun 2024
 * Modified: 21 Jun 2024
*/

void ConvertFahrenheitToCelsius(int iLower, int iUpper, int iStep){
	int iFahrenheit; /*Contains the Fahrenheit value*/
	int iCelsius;

	iFahrenheit = iLower;
	while(iFahrenheit <= iUpper){
		iCelsius = 5 * (iFahrenheit - 32) / 9;
		printf("%d\t%d\n", iFahrenheit, iCelsius);
		iFahrenheit = iFahrenheit + iStep;
	}
}

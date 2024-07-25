/*
 * This program is to print the corresponding Celsius to Fahrenheit table.
 * Author: Manthan Nagar
 * Created: 21 June 2024
 * Modified: 24 July 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>
#include "../error_handling.h"



/** MAIN PROGRAM */
/*
 * main: convert the given Celsius to Fahrenhieit 
 */

int main(){

	float fLower; /*Lower limit of temperature scale */ 
	float fUpper; /*Upper limit of temperature scale */
	float fStep; /* Step size */
	
	printf("Enter the lower limit of temperature scale (in Fahrenheit): ");
    	if (scanf("%f", &fLower) != 1) {
        	handle_error(ERROR_INVALID_INPUT);
        	return 1;  
    	}

    
	printf("Enter the upper limit of temperature scale (in Fahrenheit): ");
   	if (scanf("%f", &fUpper) != 1) {
        	handle_error(ERROR_INVALID_INPUT);
        	return 1;  
    	}

    	
    	printf("Enter the step size (in Fahrenheit): ");
    	if (scanf("%f", &fStep) != 1) {
        	handle_error(ERROR_INVALID_INPUT);
        	return 1;  
    	}

    	// Check if step size is zero or negative
    	if (fStep <= 0) {
        	handle_error(ERROR_INVALID_INPUT);
        	return 1;  
    	}

    	// Check if step size is greater than upper limit
    	if ((fStep > fUpper - fLower) && (fUpper > fLower) ) {
        	handle_error(ERROR_STEP_TOO_LARGE);
        	return 1;  
   	}

    	// Check if upper limit is greater than or equal to lower limit
    	if (fUpper < fLower) {
        	handle_error(ERROR_OUT_OF_RANGE);
        	return 1;  
    	}

    	// Print header for temperature conversion table
    	printf("\nFahrenheit    Celsius\n");
    	printf("---------------------\n");

    	// Convert and print temperatures
    	float fFahr = fLower;
    	while (fFahr <= fUpper) {
        	float fCelsius = (5.0 / 9.0) * (fFahr - 32.0);
        	printf("%6.2f       %6.2f\n", fFahr, fCelsius);
        	fFahr = fFahr + fStep;
    	}

    return 0;
}


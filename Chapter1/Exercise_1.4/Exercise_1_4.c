/**
 * Write a Program to print the corresponding Celsius to Fahrenheit table.
 * Author: Akshat Darji
 * Created: 21 Jun 2024
 * Modified: 21 Jun 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>                    /* Standard I/O library */
#include "../../error_handling.h"        /* Error handling header */

/** FUNCTION PROTOTYPES */
void CelToFah(int iLower, int iUpper, int iStep); /* Converts Cel to Fah */

/** MAIN PROGRAM */
/*
 * main: Takes Lower limit, Upper limit, step size and passes it to the CelToFah() function to print the table of Cel to Fah
 */
int main() {
    int iLower, iUpper, iStep;        /* Define iLower, iUpper and iStep (int type) */
    char choice;                      /* For taking 'Y' or 'N', for program execution */

    do {
        printf("Enter the lower limit (in Celsius)->MUST BE AN INT VALUE: "); /* User Guidance */
        if (scanf("%d", &iLower) != 1) {      /* Read lower limit and check for invalid input */
            handle_error(ERROR_INVALID_INPUT);    /* Handle invalid input error */
            return 1;                /* Exit program */
        }

        printf("Enter the upper limit (in Celsius)->MUST BE AN INT VALUE: "); /* User Guidance */
        if (scanf("%d", &iUpper) != 1) {      /* Read upper limit and check for invalid input */
            handle_error(ERROR_INVALID_INPUT);   /* Handle invalid input error */
            return 1;   /* Exit program */
        }

        printf("Enter the step size ->MUST BE AN INT VALUE: "); /* User Guidance */
        if (scanf("%d", &iStep) != 1) {         /* Read step size and check for invalid input */
            handle_error(ERROR_INVALID_INPUT);  /* Handle invalid input error */
            return 1;                           /* Exit program */
        }

        if (iStep <= 0) {      /* Check if step size is zero or negative */
            handle_error(ERROR_INVALID_INPUT);     /* Handle invalid input error */
            return 1;     /* Exit program */
        }

        if (iStep > (iUpper - iLower) && (iUpper > iLower)) { /* Check if step size is greater than the range */
            handle_error(ERROR_STEP_TOO_LARGE);    /* Handle step too large error */
            return 1;                              /* Exit program */
        }

        if (iUpper < iLower) {   /* Check if upper limit is less than lower limit */
            handle_error(ERROR_OUT_OF_RANGE);  /* Handle out of range error */
            return 1;                         /* Exit program */
        }

        printf("Celsius\tFahrenheit\n");   /* User Guidance */
        CelToFah(iLower, iUpper, iStep);  /* Call the function to print the table */

        printf("Do you want to generate another table? (y/n): ");  /* User Wants to continue or Not */
        scanf(" %c", &choice);       /* Read user's choice */

    } while (choice == 'y' || choice == 'Y');  /** Loop until user chooses to stop **/

    return 0;                    
} /* End of main Function */


/*
 * CelToFah(): takes the lower limit, upper limit, step size for the table
 * Author: Akshat Darji
 * Created: 21 Jun 2024
 * Modified: 21 Jun 2024
 */
void CelToFah(int iLower, int iUpper, int iStep) {
    float fFah;                           /* Takes the Fahrenheit Value */
    float fCel;                           /* Takes the Celsius Value */

    fCel = iLower;                        /* Stores the lower limit in fCel */
    while (fCel <= iUpper) {              /* Loop until fCel reaches upper limit */
        fFah = (9 * fCel / 5) + 32;       /* Convert Celsius to Fahrenheit */
        printf("%3.0f\t%6.1f\n", fCel, fFah); /* Print the values */
        fCel = fCel + iStep;              /* Increment by step size */
    }
} /* End of Function */

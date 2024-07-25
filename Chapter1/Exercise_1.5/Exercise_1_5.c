/**
 * Exercise_1_5: Modify the temperature conversion program to print the table in reverse order.
 * Author: Akshat Darji
 * Created: 24 Jun 2024
 * Modified: 24 Jun 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include "../../error_handling.h" /* Include the error handling header */

/** FUNCTION PROTOTYPES */
void reverseFahtoCel(int iUpper, int iLower, int iStep); /* Function to print the table in reverse order */

/** MAIN PROGRAM */
/*
 * main: Takes values for iUpper, iLower, and iStep and passes them to reverseFahtoCel for reverse table printing.
 */
int main() {
    int iLower, iUpper, iStep; /* Define iLower, iUpper, and iStep (int type) */
    char choice;              /* For taking 'Y' or 'N', for program execution */

    do {
        printf("Enter the lower limit (in Celsius)->MUST BE AN INT VALUE: ");
        if (scanf("%d", &iLower) != 1) {         /* Read lower limit and check for invalid input */
            handle_error(ERROR_INVALID_INPUT);   /* Handle invalid input error */
            return 1;                            /* Exit program */
        }

        printf("Enter the upper limit (in Celsius)->MUST BE AN INT VALUE: ");
        if (scanf("%d", &iUpper) != 1) {         /* Read upper limit and check for invalid input */
            handle_error(ERROR_INVALID_INPUT);   /* Handle invalid input error */
            return 1;                            /* Exit program */
        }

        printf("Enter the step size ->MUST BE AN INT VALUE: ");
        if (scanf("%d", &iStep) != 1) {           /* Read step size and check for invalid input */
            handle_error(ERROR_INVALID_INPUT);    /* Handle invalid input error */
            return 1;                             /* Exit program */
        }

        if (iStep <= 0) {       /* Check if step size is zero or negative */
            handle_error(ERROR_INVALID_INPUT);   /* Handle invalid input error */
            return 1;                            /* Exit program */
        }

        if (iUpper < iLower) {                   /* Check if upper limit is less than lower limit */
            handle_error(ERROR_OUT_OF_RANGE);    /* Handle out of range error */
            return 1;                            /* Exit program */
        }

        printf("Fahrenheit\tCelsius\n");         /* Print table header */
        reverseFahtoCel(iUpper, iLower, iStep);  /* Call the function to print the table */

        printf("Do you want to generate another table? (y/n): ");
        scanf(" %c", &choice);                                       /* Read user's choice */

    } while (choice == 'y' || choice == 'Y');                       /* Loop until user chooses to stop */

    return 0;                                                         /* End of main function */
} /* End of main */

/*
 * reverseFahtoCel(): takes the upper limit, lower limit, step size to print the table in reverse order
 * Author: Akshat Darji
 * Created: 24 Jun 2024
 * Modified: 24 Jun 2024
 */
void reverseFahtoCel(int iUpper, int iLower, int iStep) {
    float fFah; /* Takes the Fahrenheit Value */
    float fCel; /* Takes the Celsius Value */

    for (int i = iUpper; i >= iLower; i -= iStep) {   /* Decrementing loop by step size */
        fFah = i;                 /* Fahrenheit value from loop variable */
        fCel = (5.0 * (fFah - 32.0)) / 9.0;     /* Corrected equation to convert Fahrenheit to Celsius */
        printf("%3.0f\t%6.2f\n", fFah, fCel);                       /* Print the values */
    }
} /* End of Function */

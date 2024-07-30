#include "error_handling.h"
#include <stdio.h>

// Function definitions
void handle_error(int error_code) {
    switch (error_code) {
        case ERROR_NONE:
            break;  // No error
        case ERROR_INVALID_INPUT:
            printf("Error %d: Invalid input entered.\n", ERROR_INVALID_INPUT);
            break;
        case ERROR_OUT_OF_RANGE:
            printf("Error %d: Input out of range.\n", ERROR_OUT_OF_RANGE);
            break;
        case ERROR_STEP_TOO_LARGE:
            printf("Error %d: Step size greater than upper bound.\n", ERROR_STEP_TOO_LARGE);
            break;
	case ZERO_DEVISION_ERROR:
	    printf("Error %d: Zero devision error\n", ZERO_DEVISION_ERROR);
	    break;
	case ERROR_INVALID_HEX_CHARACTER:
	    printf("Error %d: Invalid Input String (Your String Must be in Hexadecimal format)\n", ERROR_INVALID_HEX_CHARACTER);
	    break;
	case ERROR_EMPTY_STRING:
	    printf("Error %d: Invalid Input (String is Empty)\n", ERROR_EMPTY_STRING);
	    break;
	case ERROR_DUPLICATE_CHARACTERS:
	    printf("Error %d: Can not proceed because cS1 does not contains duplicate characters and you give the duplicate characters in cS2 to remove\n", ERROR_DUPLICATE_CHARACTERS);
	    break;
	case ERROR_INVALID_SIZE:
	    printf("Error %d: Invalid array size.\n", ERROR_INVALID_SIZE);
	    break;
	case ERROR_INPUT_TOO_LONG:
	    printf("Error %d: Input exceeds maximum allowed length.\n", ERROR_INPUT_TOO_LONG);
	    break;
	case INT_OUT_OF_RANGE:
	    printf("Error %d: Entered number is not in range.\n", INT_OUT_OF_RANGE);
	    break;
	case ERROR_INVALID_FORMAT:
	    printf("Error %d: Invalid format. Please ensure the input is a valid.\n",  ERROR_INVALID_FORMAT);
	    break;
        default:
            printf("Error: Unknown error.\n");
            break;
    }
}

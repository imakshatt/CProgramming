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
        default:
            printf("Error: Unknown error.\n");
            break;
    }
}

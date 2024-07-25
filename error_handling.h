#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

// Define error codes
#define ERROR_NONE 0
#define ERROR_INVALID_INPUT 1
#define ERROR_OUT_OF_RANGE 2
#define ERROR_STEP_TOO_LARGE 3
#define ZERO_DEVISION_ERROR 4
#define ERROR_INVALID_HEX_CHARACTER 5

// Function prototypes
void handle_error(int error_code);

#endif /* ERROR_HANDLING_H */

#ifndef ERROR_HANDLING_H /*Check for macro defination*/
#define ERROR_HANDLING_H /*If not then define that macro*/

// Define error codes
#define ERROR_NONE 0
#define ERROR_INVALID_INPUT 1
#define ERROR_OUT_OF_RANGE 2
#define ERROR_STEP_TOO_LARGE 3
#define ZERO_DEVISION_ERROR 4
#define ERROR_INVALID_HEX_CHARACTER 5
#define ERROR_EMPTY_STRING 6
#define ERROR_DUPLICATE_CHARACTERS 7
#define ERROR_INVALID_SIZE 8 /*For array exceed*/
#define ERROR_INPUT_TOO_LONG 9 /*For String exceed*/
#define INT_OUT_OF_RANGE 10/*For Handling the error of MAX INT (Out of range prob)*/
#define ERROR_INVALID_FORMAT 11 /*for exercise_4_2 to validate input notation*/


// Function prototypes
void handle_error(int error_code);

#endif /* ERROR_HANDLING_H */

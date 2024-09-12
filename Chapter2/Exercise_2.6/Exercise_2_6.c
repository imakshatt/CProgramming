/**
 * Exercise_2_6: Write a function setbits(x, p, n, y) that returns x with the n bits 
 * that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.
 * Author: Akshat Darji
 * Created: 26 Jun 2024
 * Modified: 26 Jun 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>

/** FUNCTION PROTOTYPES */
unsigned setbits(unsigned x, int p, int n, unsigned y);

/** MAIN PROGRAM */
/*
 * main: Tests the setbits function with example values.
 * Returns 0 if successful.
 */
int main(void)
{
    unsigned x = 12, y = 18;
    int p = 1, n = 3;
    unsigned result;

    
    result = setbits(x, p, n, y);


    if (result == (unsigned)-1) {
        printf("Negative values are not allowed.\n");
    }
    
    else if (result == (unsigned)-2) {
        printf("N should be greater than P + 1.\n");
    }
    else {
        printf("%u\n", result);
    }

    return 0;
}

/*
 * unsigned setbits(unsigned x, int p, int n, unsigned y): 
 * This function returns x with the n bits that begin at position p set to the 
 * rightmost n bits of y, leaving the other bits unchanged.
 * 
 * Parameters:
 * - x: the unsigned integer where bits will be modified.
 * - p: the position (from the right) where the modification starts.
 * - n: the number of bits to replace.
 * - y: the unsigned integer whose rightmost n bits will replace those in x.
 * Author: Akshat Darji
 * Created: 21 Jun 2024
 * Modified: 26 Jun 2024
 */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
   
    if ((int)x < 0 || (int)y < 0) {
        return (unsigned)-1;  // Return error code if negative values are detected
    }

    if (n < p + 1) {
        return (unsigned)-2;  // Return error code for insufficient bits
    }

    return (x & ~(~(~0U << n) << (p + 1 - n))) | ((y & ~(~0U << n)) << (p + 1 - n));
}

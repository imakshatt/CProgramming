/**
 * Exercise_2_7: Write a function invert(x,p,n) that returns x with the n bits 
 * that begin at position p inverted (i.e., 1 changed into 0 and vice versa), 
 * leaving the others unchanged.
 * Author: Akshat Darji
 * Created: 26 Jun 2024
 * Modified: 26 Jun 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>

/** FUNCTION PROTOTYPES */
unsigned invert(unsigned x, int p, int n);

/** MAIN PROGRAM */
/*
 * main: Tests the invert function with example values.
 */
int main(void)
{
    unsigned x = 15;
    int p = 1, n = 4;
    unsigned result;

    result = invert(x, p, n);

    printf("%u\n", result);

    return 0;
}

/*
 * unsigned invert(unsigned x, int p, int n): 
 * This function returns x with the n bits that begin at position p inverted.
 * Author: Akshat Darji
 * Created: 21 Jun 2024
 * Modified: 26 Jun 2024
 */
unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0U << n) << (p + 1 - n));
}

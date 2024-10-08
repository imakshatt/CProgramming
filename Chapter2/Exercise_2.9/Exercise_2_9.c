/**
 * Exercise_2_9: In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Explain why. Use this observation to write a faster version of bitcount.
 * Author: Akshat Darji
 * Created: 26 Jun 2024
 * Modified: 26 Jun 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>

/** FUNCTION PROTOTYPES */
int bitcount(unsigned x);


/** MAIN PROGRAM */
/*
 * main: Tests the invert function with example values.
 */
int main(void)
{
    unsigned x = 11;
    unsigned result;
    result = bitcount(x);
    printf("%d\n",result);
}

/*
 * int bitcount(unsigned x): 
 * Author: Akshat Darji
 * Created: 21 Jun 2024
 * Modified: 26 Jun 2024
 */
int bitcount(unsigned x)
{
    int b;

    for(b=0; x!=0; x &= x-1)
        ++b;

    return b;
}


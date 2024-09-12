/**
 * Exercise_2_8: Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions.
 * Author: Akshat Darji
 * Created: 26 Jun 2024
 * Modified: 26 Jun 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>

/** FUNCTION PROTOTYPES */
unsigned rightrot(unsigned x,int n);


/** MAIN PROGRAM */
/*
 * main: Tests the invert function with example values.
 */
int main(void)
{
    unsigned x = 15;
    int n = -3;
    unsigned result;
    result = rightrot(x,n);
    printf("%u\n", result);

    return 0;
}


/*
 * unsigned rightrot(unsigned x,int n): 
 * Author: Akshat Darji
 * Created: 21 Jun 2024
 * Modified: 26 Jun 2024
 */
unsigned rightrot(unsigned x,int n)
{
    int wordlength(void);
    unsigned rbit;/* rightmost bit */
    
    rbit = x << (wordlength() - n);
    x = x >> n;
    x = x | rbit;
    
    return x;
}


int wordlength(void)
{
    int i;
    unsigned v = (unsigned) ~0;

    for(i=1;(v=v>>1)>0;i++)
        ;
    return i;
}

/**
Exercise_2_1: Write a Program to determine the ranges of Char, short, int and long variables both signed and unsigned by printing te appropriate values from standard headers and by direct cimutation
Author: Akshat Darji
Created: 26 Jun 2024
Modified: 26 JUn 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<float.h>
#include<limits.h>

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */


/** MAIN PROGRAM */
/*
 * main: Check the ranges of all data types, MAX and MIN ranges
*/


int main(){
	printf("Signed Ranges\n");
	printf("Signed Character MAX range: %d\n", SCHAR_MAX);
	printf("Signed Character MIN range: %d\n", SCHAR_MIN);
	printf("Signed Short MAX range: %d\n", SHRT_MAX);
	printf("Signed Short MIN range: %d\n", SHRT_MIN);
	printf("Signed INT MAX range: %d\n", INT_MAX);
	printf("Signed INT MIN range: %d\n", INT_MIN);
	printf("Signed LONG MAX range: %ld\n", LONG_MAX);
	printf("Signed LONG MIN range: %ld\n", LONG_MIN);
	printf("Signed LONG LONG MAX range: %lld\n", LLONG_MAX);
	printf("Signed LONG LONG MIN range: %lld\n", LLONG_MIN);
	printf("Signed FLOAT MAX range: %E\n", FLT_MAX);
	printf("Signed FLOAT MIN range: %E\n", FLT_MIN);
	printf("Signed DOUBLE MAX range: %E\n", DBL_MAX);
	printf("Signed DOUBLE MIN range: %E\n", DBL_MIN);
	printf("Signed LONG DOUBLE MAX range: %LE\n", LDBL_MAX);
	printf("Signed LONG DOUBLE MIN range: %LE\n", LDBL_MIN);
	

	printf("Unsigned INT\n");
	printf("Unsigned Character MAX range: %u", UCHAR_MAX);
	return 0;
	

}

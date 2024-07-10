/**
Exercise_3_1: Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time.
Author: Akshat Darji
Created: 8 July 2024
Modified: 8 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<time.h>
/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
int binarysearch(int x, int arr[], int n);

/** MAIN PROGRAM */
/*
 * main: Binary Search with optimization.
*/


int main(){
	int arr[] = {5,4,3,2,1};
	int index;
	clock_t start, end;

	start = clock();
	
	index = binarysearch(2, arr, 5);

	end = clock(); 

	double timed = (double)(end-start)/(CLOCKS_PER_SEC);

	printf("%f",timed);	
	return 0;
}

int binarysearch(int x, int arr[], int n){
	int low = 0;
	int high = n-1;
	int mid = (low + high)/2;

	while(low < high && x != arr[mid]){
		if(x > arr[mid]){
			low = mid + 1;
		}
		else{
			high = mid -1;
		}
		mid = (low + high)/2;
	}
	if(x == arr[mid]){
		return mid;
	}
	else{
		return -1;
	}
}


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
int binarysearch(int x, int arr[], int n); //x refers to the element which we have to find
					   //n is the size of an array

/** MAIN PROGRAM */
/*
 * main: Binary Search with optimization.
*/


int main(){
	int arr[] = {5,4,3,2,1};  //array of 5 elements
	int index; //to get the index of the founded element
	clock_t start, end;  //to measure the time

	start = clock();  //start the clock
	
	index = binarysearch(2, arr, 5); //binary search function and pass the arguments

	end = clock(); //end the clock

	double timed = (double)(end-start)/(CLOCKS_PER_SEC); //calculate the time and store it in timed

	printf("%f",timed);	
	return 0;
}

/*                                                                                                   * binarysearch(int x, int arr[], int n): takes X, arr and size of an array
 * Author: Akshat Darji
 * Created: 9 July 2024                                                                              * Modified: 9 July 2024                                                                            */

int binarysearch(int x, int arr[], int n){
	int low = 0;   //lower index of an array starts with 0
	int high = n-1; //higher index of an array placed at N-1
	int mid = (low + high)/2; //find the middle element

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


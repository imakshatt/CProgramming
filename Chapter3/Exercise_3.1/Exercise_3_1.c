/*
Exercise_3_1: Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time.
Author: Akshat Darji
Created: 8 July 2024
Modified: 8 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<time.h>
#include "../../error_handling.h"

/** MARCO DEFINATIONS */
#define MAX_SIZE 10

/** FUNCTION PROTOTYPES */
int binarysearch(int x, int arr[], int n); //x refers to the element which we have to find
					   //n is the size of an array

/** MAIN PROGRAM */
/*
 * main: Binary Search with optimization.
*/

int main() {
    int iArr[MAX_SIZE];  /* Array to store user input elements */
    int iSize = 0;       /* Number of elements in the array */
    int iTarget;         /* Element to search for */
    int iIndex;          /* Index of the found element */
    char choice;        /* Variable to store the user's choice for continuation */

    do {
        printf("Enter the number of elements in the array (up to %d): ", MAX_SIZE);
        if (scanf("%d", &iSize) != 1 || iSize <= 0 || iSize > MAX_SIZE) {
            handle_error(ERROR_INVALID_SIZE);  /* Handle invalid size error */
            while (getchar() != '\n'); /*Clear input buffer*/
            continue;
        }

        printf("Enter %d elements (sorted):\n", iSize);
        for (int iI = 0; iI < iSize; iI++) {
            if (scanf("%d", &iArr[iI]) != 1) {
                handle_error(ERROR_INVALID_INPUT);  /* Handle invalid input error */
                while (getchar() != '\n'); // Clear input buffer
                return 1;
            }
        }

        printf("Enter the value to search for: ");
        if (scanf("%d", &iTarget) != 1) {
            handle_error(ERROR_INVALID_INPUT);  /* Handle invalid input error */
            while (getchar() != '\n'); // Clear input buffer
            return 1;
        }

        clock_t start = clock();  /* Start the clock */
        iIndex = binarysearch(iTarget, iArr, iSize);  /* Call the binarysearch function */
        clock_t end = clock();  /* End the clock */

        double dTimed = (double)(end - start) / CLOCKS_PER_SEC;  /* Calculate the elapsed time */

        if (iIndex != -1) {
            printf("Element %d found at index %d\n", iTarget, iIndex);  /* Print index if found */
        } else {
            printf("Element %d not found in the array.\n", iTarget);  /* Inform if not found */
        }

        printf("Time taken for the search: %f seconds\n", dTimed);  /* Print the time taken */

        printf("Do you want to perform another search? (y/n): ");
        if (scanf(" %c", &choice) != 1) {
            handle_error(ERROR_INVALID_INPUT);  /* Handle invalid input error */
            while (getchar() != '\n'); // Clear input buffer
            return 1;
        }

        // Clear the input buffer to avoid issues with leftover newline characters
        while (getchar() != '\n');

    } while (choice == 'y' || choice == 'Y');  /* Continue if the user chooses 'y' or 'Y' */

    return 0;  /* Exit the program */
}
/*                                                                                                   * binarysearch(int x, int arr[], int n): takes X, arr and size of an array
 * Parameters:
 *   x - The element to search for
 *   arr - The array to search in
 *   n - The size of the array
 *Returns:
 *   The index of the element if found, otherwise -1
 * Author: Akshat Darji
 * Created: 9 July 2024                                                                              * Modified: 9 July 2024                                                                            */

int binarysearch(int x, int arr[], int n){

	if (arr == NULL || n <= 0) {
        	handle_error(ERROR_INVALID_INPUT);  /* Handle invalid array or size error */
        	return -1;
    	}
	int low = 0;   /*lower index of an array starts with 0*/
	int high = n-1; /*higher index of an array placed at N-1*/
	int mid = (low + high)/2; /*find the middle element*/

	while(low < high && x != arr[mid]){    /*Termination Condition*/
		if(x > arr[mid]){ /*If x is greater than mid element then*/
			low = mid + 1; /*Go to the right half of array*/
		}
		else{
			high = mid -1; /*Go to the left half of array*/
		}
		mid = (low + high)/2; /*Again devide the array if match not found*/
	}
	if(x == arr[mid]){  /*Best case when my middle element is the search element*/
		return mid;  
	}
	else{
		return -1; /*When element not founds retrun -1*/
	}
}


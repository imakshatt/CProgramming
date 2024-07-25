/**
Exercise_2_3: Write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.
Author: Akshat Darji
Created: 4 July 2024
Modified: 4 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>
#include<math.h>
#include "../../error_handling.h" /* Include the error handling header */

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
void htoi(char cStringArray[], int iLen); /*Function to convert Hex to Int*/


/** MAIN PROGRAM */
/*
 * main: It takes the hexadecimal string which only accepts the required format like allowed character is from '0' to '9' or 'A' to 'F' in small case as well 
*/


int main() {
    char choice;
    do {
        char cStr[1000];  // For taking input Hexadecimal String
        printf("Enter a hexadecimal number (with optional 0x or 0X prefix): ");
        
        if (scanf("%999s", cStr) != 1) { /* Error Validation for correct input */
            handle_error(ERROR_INVALID_INPUT); /* Handling the error */
            return 1; 
        }

        int iLen = strlen(cStr); // This function finds the length of the string

        if (iLen == 0) {  /* If length of cStr is zero then */
            handle_error(ERROR_INVALID_INPUT); /* Handle that error: string cannot be empty */
            return 1; 
        }

        if (iLen > 1 && (cStr[0] == '0') && (cStr[1] == 'x' || cStr[1] == 'X')) {
            memmove(cStr, cStr + 2, strlen(cStr) - 1);  /* Adjust string to remove prefix */
            iLen -= 2;  /* Adjust length to exclude the prefix */
        }

        for (int i = 0; i < iLen; i++) { /* Check for valid Hexadecimal string as per format */
            if (!((cStr[i] >= '0' && cStr[i] <= '9') || 
                  (cStr[i] >= 'A' && cStr[i] <= 'F') ||
                  (cStr[i] >= 'a' && cStr[i] <= 'f'))) {
                handle_error(ERROR_INVALID_HEX_CHARACTER); /* If not, then handle the error */
                return 1;
            }
        }

        htoi(cStr, iLen); /*This function is used to convert Hex to Decimal equivalent*/
        
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

//if any functions then mention like below
/*
 * htoi(cStringArray, len): takes string array and len that converted in the decimal equivalent
 * Author: Akshat Darji
 * Created: 4 July 2024
 * Modified: 4 July 2024
*/

void htoi(char cStringArray[], int iLen){
	int iBase = 16; /*Taking base 16 as static because this is static conversation*/
	int iAns = 0; /*Initialize the ans to zero*/
	int iNum; /*For maintaining the Number*/
	int iExpo; /*Maintaininf the power (10^pow)*/
	for(int i=iLen-1;i>=0;i--){ /*Starting from the Len-1 (EOF-1 of string)*/
		if(cStringArray[i]>='0' && cStringArray[i] <= '9'){ /*Check for Num*/
			iExpo = (iLen - 1) - i; /*Maintaining the equation fot the Power*/
			iAns += (cStringArray[i]-'0') * pow(iBase, iExpo); /*Store the ans*/
		}
		else if(cStringArray[i]>='A' && cStringArray[i]<='F'){ /*Check for 'A' to 'F'*/
			//iNum = ChartoInt(cStringArray[i]);
			iExpo = (iLen - 1) - i; /*IF it is then maintaing the power*/
			iNum = cStringArray[i] - 'A' + 10; /*Convert it to Int*/
			iAns += iNum * pow(iBase, iExpo);	/*Store the answer*/ 
		}
		else if(cStringArray[i]>='a' && cStringArray[i]<='f'){  /*Check for 'a' to 'f'*/
			//iNum = ChartoIntS(cStringArray[i]);
			iExpo = (iLen - 1) - i; /*If it is then maintaining the power*/
			iNum = cStringArray[i] - 'a' + 10; /*Convert it to INT*/
			iAns += iNum * pow(iBase, iExpo); /*Store the ans*/
		}
	}
	printf("\nHexadecimal Equivalent: %d\n", iAns);  /*Printing the answer*/
}


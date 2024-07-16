/**
Exercise_4_2: Extend atof to handle scientific notation of the form 123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent.
Author Akshat Darji
Created: 16 July 2024
Modified: 16 Juy 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
double atof(char s[]); /*Initialization of the function atof() with argument char s[]*/

/** MAIN PROGRAM */
/*
 * main: Taking the character string from user and pass it to the atof functin which performs the scientific calculations on the given string like 125.45e-3 into 125.45 * 10^-6
*/


int main(){
	char s[] = "123.45e+4"; /*Char String given by the User*/
	double dAnswer; /*To store the Answer initialie dAnswer of double type*/
	dAnswer = atof(s);  //call the function and stores the retrun double value in dAnswer
	printf("%f\n", dAnswer); /*Prints the answer*/
	return 0;
}

/*
 * atof(char s[]): Takes the char string and performs Extension of atof function which can also handle scientific notations
 * Author: Akshat Darji
 * Created: 16 July 2024
 * Modified: 16 July 2024
*/

double atof(char s[]){  /*Taking the char s[] to store the s*/
	int iJ=0;  /*For while loop iteration*/
	int iPosofJ=0;
	double dNumber; /*Stores the Number still e occurs in the char s[]*/
	
	while(s[iJ]!='e'){  /*Termination condition*/
		iPosofJ++; /*Incrementing the iPosofJ pointer*/
		double dVal, dPower; /*Initialize the dVal and dPower for stores the double value*/
		int iSign, i; /*iSign for taking the map of Sign in the string like +ve or -ve*/

		for(i=0;isspace(s[i]);i++); /*Check for the space and increment i pointer*/

		iSign = (iSign=='-' ? -1 : 1); /*if iSign is -ve then stores -1 in iSign or 1*/

		if(s[i]=='+' || s[i]=='-'){  /*Condition to check the sign if there is sign either =                                               ve or -ve then simply increment the i Pointer*/
			i++;
		}	
		for(dVal=0.0;isdigit(s[i]);i++){ /*If s[i] is digit then update dVal*/
			dVal = 10.0 * dVal + (s[i]-'0'); /*Eqn to convert string to double*/
		}
		if(s[i]=='.'){ /*If there is '.' in s[] then simply incrementing the i pointer*/
			i++;
		}
		for(dPower=1.0; isdigit(s[i]); i++){ /*After Point maintain the Power i.e how many
						       digits after '.' to get dNumber*/
			dVal = 10.0 * dVal + (s[i] - '0'); /*Conversion of str to double*/
			dPower = dPower * 10;   /*Maintaining the power*/
		}
		dNumber = iSign * dVal/dPower;  /*Storing the Final double Number into dNumber*/
		break; /*Breaks the Loop because we only have to go still 'e' || 'E'*/
	}
	
	int iPointer; /*For maintain the track after we find 'e' or 'E'*/
	int iAfterSign; /*For keep track of signs after finding 'e' || 'E'*/
	int iAfterNum = 0;  
	int iExponent; /*Stores the Exponent like if e-5 then stores the 5 in double*/
	double iFinalAnswer; /*For storing the Final Answer*/
	int iFound = 0; /*For finding the pos of 'e' || 'E' in the char s[]*/

	for(int i=0;i<strlen(s); i++){  /*Finding the pos of 'e' or 'E'*/
		if(s[i]=='e' || s[i]=='E'){
			break; /*Once we are at 'e' || 'E' then break the loop*/
		}
		iFound++; /*Otherwise Increment the iFound Pointer*/
	}
	for(iPointer=iFound; isspace(s[iPointer]); iPointer++);   /*Space*/
	if(s[iPointer]=='e' || s[iPointer]=='E'){ /*If 'e' || 'E' occurs then*/
		iPointer++; /*Incrementing the iPointer*/
	}
	
	iAfterSign = (s[iPointer] == '-') ? -1 : 1; /*Storing the Sign after 'e' || 'E' in 
						      iAfterSign*/

	if(s[iPointer]=='-' || s[iPointer]=='+'){ /*If '-' or '+' is there in s[] then*/
		iPointer++; /*Incrementing the iPointer*/
	}
	
	for(iExponent=0.0; isdigit(s[iPointer]); iPointer++){ /*Storing the value after 'e-'*/
		iExponent = 10.0 * iExponent + (s[iPointer] - '0'); /*str to double conversion*/
	}
	
	if(iAfterSign == 1){  /*If Sign is -ve then*/
		iFinalAnswer = dNumber * pow(10, iExponent); /*dNumber * 10^+iExponent*/
	}
	else{
		iFinalAnswer = dNumber * pow(10, -(iExponent)); /*dNumber * 10 ^ -iExponent*/
	}
	return iFinalAnswer; /*Retur the iFinalAnswer*/
		
}


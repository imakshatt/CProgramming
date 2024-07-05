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

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
void htoi(char cStringArray[], int iLen);


/** MAIN PROGRAM */
/*
 * main: detail overview of main function
*/


int main(){
	char cStr[1000];  //For taking input Hexadecimal String	
	scanf("%s", cStr);
	int iLen = strlen(cStr); //This function finds the length of the string
	char cStringArray[iLen]; //Making StringArray of len as an Hexa String
	for(int i=0;i<iLen;i++){
		cStringArray[i] = cStr[i];
	}
	htoi(cStringArray, iLen); //This function is used to convert Hexa to Decimal equivalent

}


//if any functions then mention like below
/*
 * htoi(cStringArray, len): takes string array and len that converted in the decimal equivalent
 * Author: Akshat Darji
 * Created: 4 July 2024
 * Modified: 4 July 2024
*/

void htoi(char cStringArray[], int iLen){
	int iBase = 16;
	int iAns = 0;
	int iNum;
	int iExpo;
	for(int i=iLen-1;i>=0;i--){
		if(cStringArray[i]>='0' && cStringArray[i] <= '9'){
			iExpo = (iLen - 1) - i;
			iAns += (cStringArray[i]-'0') * pow(iBase, iExpo);	
		}
		else if(cStringArray[i]>='A' && cStringArray[i]<='Z'){
			//iNum = ChartoInt(cStringArray[i]);
			iExpo = (iLen - 1) - i;
			iNum = cStringArray[i] - 'A' + 10;
			iAns += iNum * pow(iBase, iExpo);	
		}
		else if(cStringArray[i]>='a' && cStringArray[i]<='z'){
			//iNum = ChartoIntS(cStringArray[i]);
			iExpo = (iLen - 1) - i;
			iNum = cStringArray[i] - 'a' + 10;
			iAns += iNum * pow(iBase, iExpo);
		}
	}
	printf("\nHexadecimal Equivalent: %d", iAns);
}

/*int ChartoInt(char m){
	return m - 'A' + 10;
}
int ChattoIntS(char m){
	return m - 'a' + 10;
}*/


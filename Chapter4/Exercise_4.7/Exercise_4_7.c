
/**
Exercise_4_5: Add access to library functions like sin, exp, and pow.
Author: Akshat Darji
Created: 26 July 2024
Modified: 26 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

/** MARCO DEFINATIONS */
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

/** FUNCTION PROTOTYPES */
int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void peek(void);
void duplicatetop(void);
void swapTopTwo(void);
void clearStack(void);
void performSin(void);
void performExp(void);
void performPow(void);
void ungets(char s[]);

void printInstructions(void);


/** MAIN PROGRAM */
/*
 * main: A manu driven program which handles various cases such as addition, mutliplication, divi
 * modulo, print top element, duplicate top element, swap top two elements and clear the stack
 * Here below are some notations that are useful
 * Print Top Element use 'P': i.e. 2 3 + 5 * P
 * Duplicate Top Element use 'D': i.e. 2 3 D
 * swap top 2 Elements use 'S': i.e. 2 3 S
 * clear the stack use 'C' 
*/


int main(){

	printInstructions(); /*Printing the instructions for the user*/
	int type;
	double op2;
	char s[MAXOP];

	while((type=getop(s)) != EOF){
		switch(type){
			case NUMBER: /*if type == '0' then this case performs*/
				push(atof(s)); /*converting s into double and push to stack*/
				break; /*break the case*/

			case '+':   /*If type == '+' then we have to perform Addition*/
				push(pop() + pop()); /*Pop first 2 ele and perform '+'*/
				break; /*Break the case*/

			case '*': /*If type == '*' then we have to perform Multiplication*/
				push(pop() * pop()); /*pop first 2 ele and perform '*'*/
				break;

			case '-': /*If type == '-' then perform Substraction*/
				/*As in Substraction Sign and order metters hense use op2*/
				op2 = pop(); /*store top ele of stack in op2*/
				push(pop() - op2); /*Now pop last ele and perform '-'*/
				break; 

			case '/': /*If type == '/' then perform Division*/
				/*As in Division Sign and order merrers*/
				/*And also encounter zero division error*/
				op2 = pop(); /*Store first element of stack in op2*/
				if(op2 != 0.0){ /*Chekc if op2==0 then '/' Not possible*/
					push(pop() / op2); /*Perform '/'*/
				}
				else{
					printf("Error: Zero Division Error\n"); /*Error Handling*/
				}
				break;

			case '%': /*If type == '%' then perform Division*/
				/*As in Modulo Sign and order merrers*/
				/*And also encounter zero division error*/
				op2 = pop(); /*Store first element of stack in op2*/
				if(op2 != 0.0){ /*Chekc if op2==0 then '%' Not possible*/
					push((int)pop() % (int)op2);
				}
				else{
					printf("Error: Zero Division Error"); /*Error Handling*/
				}
				break;

			case 'P': /*To print top element of the stack*/
				peek(); 
				break;
			case 'D': /*To Duplicate top elelent of the stack*/
				duplicatetop();
				break;
			case 'S': /*To Swap top 2 element of the stack*/
				swapTopTwo();
				break;
			case 'C': /*To clear the stack*/
				clearStack();
				break;
			case 's': /*To perform Sin operation like 2 s so that is sin(2)*/
				performSin();
				break;
			case 'e': /*To perform Exponential Operation i.e. 2 e so exp(2)*/
				performExp();
				break;
			case 'p': /*To perform Power operation i.w 2 4 p then it is 2^4 pow(2,4)*/
				performPow();
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("Error: Unknown Command %s\n", s);
				break;

		}
	}
	return 0;
}

/*
 * printInstructions(): This function is used to print the basic instructions for the user
 * Author: Akshat Darji
 * Created: 26 July 2024
 * Modified: 26 July 2024
*/

void printInstructions(void){
	printf("Welcome the Calculator!\n");
    	printf("You can perform the following operations:\n");
    	printf(" - Addition: +\n");
    	printf(" - Subtraction: -\n");
    	printf(" - Multiplication: *\n");
    	printf(" - Division: /\n");
    	printf(" - Modulo: %%\n");
    	printf(" - Print Top Element: P\n");
    	printf(" - Duplicate Top Element: D\n");
    	printf(" - Swap Top 2 Elements: S\n");
    	printf(" - Clear the Stack: C\n");
	printf(" - For performing Sin Operation: s\n");
	printf(" - For performing Exponential Operation: e\n");
	printf(" - For performing Power Operation: p\n");
    	printf("Enter your commands followed by Enter:\n");
}

/*
 * getop(char s[]): This function is used to read the operators and operands from i/p
 * Author: Akshat Darji
 * Created: 26 July 2024
 * Modified: 26 July 2024
*/

int getop(char s[]){
	int i,c;

	while((s[0] = c = getch()) == ' ' || c == '\t');  /*For Skipping Space and Tab*/

	s[1] = '\0'; /*Make s[1] as EOF for temp*/

	if(!isdigit(c) && c !='.' && c != '-'){ /*Case for Handling Non Digit Char
	                                          If !isdigit(c) then retrun that operator*/
		return c;  /*Retrun to main and stored in type*/
	}

	i=0; /*Initializing i as ZERO*/
 
	/*For Handle Negative Character*/
	/*Because there are 2 possibilities One is -Ve Operand and -ve is also Operator*/
	if(c == '-'){  /*Check as C is '-' or not*/
		char next = getch();  /*If it is then store the next value in next variable*/
		if(isdigit(next) || next == '.'){ /*Now check for that NEXT value like isdigit & .*/
			s[++i] = c = next; /*then store that in s[]*/
		}
		else{
			ungetch(next); /*Otherwise handling the space using ungetch()*/
			return c; /*And if that is operator then return That Sign*/
		}
	}

	if(isdigit(c)){ /*This is the case for handling Digit*/
		while(isdigit(s[++i] = c = getch())); /*continue until we get digit*/
	}

	if(c == '.'){ /*For fractional part*/
		while(isdigit(s[++i] = c = getch()));
	}

	/*if(c == '-' || isdigit(c)){
		while(isdigit(s[++i] = c = getch()));
	}
	if(strcmp(s, "-") == 0){
		return '-';
	}*/

	s[i] = '\0'; /*At the End at ith location in s[] mark as EOF*/

	if(c != EOF){  /*If C is not an EOF then*/
		ungetch(c); /*Handle it in Buffer*/
	}
	return NUMBER; /*At the End Retrun the number stored in s[] as '0' for switch case*/
}


/*
 * getch(void): to read the character from the i/p string
 * Author: Akshat Darji
 * Created: 26 July 2024
 * Modified: 26 July 2024
*/

char buf[BUFSIZE]; /*Initialize the buffer array to store the non-numeric char*/
int bufp = 0; /*Initialize buf pointer to zero*/
int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar(); /*Check is bufp is zero then only it read the char from the input string and if bufp is 1 then it clears the buffer first then only read it*/
}


/*
 * ungetch(int c): to store the non-numeric value in the buf[]
 * Author: Akshat Darji
 * Created: 26 July 2024
 * Modified: 26 July 2024
*/

void ungetch(int c){
	if(bufp >= BUFSIZE){
		printf("Ungetch: too many characters\n");
	}	
	else{
		buf[bufp++] = c;
	}
}


/*
 * ungets(char s[]): to push back an entire string onto the buffer
 * Author: Akshat Darji
 * Created: 30 July 2024
 */
void ungets(char s[]) { /*ungets is used to put entire string into the buffer*/
    int iLen = strlen(s); /*Finding the length of string*/
    while (iLen > 0) { /*Traverse through the entire input string */
        ungetch(s[--iLen]); /*Putting the values into the buffer (Entire string)*/
    }
}


/*
 * push(double f): This function push the value into the stack val[]
 * Author: Akshat Darji
 * Created: 26 July 2024
 * Modified: 26 July 2024
*/
int sp = 0; /*Pointer to traverse into the stack*/
double val[MAXVAL]; /*Initialize the stack*/
void push(double f){ /*Cahce the value*/
	if(sp < MAXVAL){ /*Check for the overflow condition*/
		val[sp++] = f; /*If not then only push the value into the stack*/
	}
	else{
		printf("Error: Stack Full, can't push %g\n", f); /*Else error*/
	}
}

/*
 * pop(): This function delete the top element from the stack
 * Author: Akshat Darji
 * Created: 26 July 2024
 * Modified: 26 July 2024
*/

double pop(){
	if(sp > 0){ /*Check for underdflow condition */
		return val[--sp]; /*if there is values then delete top element*/
	}
	else{
		printf("Error: Stack is Empty\n");
		return 0.0;
	}
}

/*
 * peek(void): This function is used to print the top element of stack without popping
 * Author: Akshat Darji
 * Created: 26 July 2024
 * Modified: 26 July 2024
*/

void peek(void){
	if(sp > 0){ /*Checking for underflow condition*/
		printf("Top Element: %.8g\n", val[sp-1]); /*Print the TOP Element*/
	}
	else{
		printf("Error: Stack is Empty can't print top element\n");
	}
}

/*
 * duplicatetop(void): This function is used to duplicate the top element
 * Author: Akshat Darji
 * Created: 26 July 2024
 * Modified: 26 July 2024
*/

void duplicatetop(void){
	if(sp > 0 && sp < MAXVAL){ /*Checking for overflow and underflow condition*/
		double dTop = val[sp-1]; /*Store the top element of stack*/
		push(dTop);
	}
	else if(sp == 0){
		printf("Error: Stack is Empty can't duplicate.\n");
	}
	else{
		printf("Error: Stack Overflow, can't duplicate.\n");
	}
}

/*
 * swapTopTwo(void): This function is used to swap top 2 elements of stack 
 * Author: Akshat Darji
 * Created: 26 July 2024
 * Modified: 26 July 2024
*/

void swapTopTwo(void){
    if(sp >= 2){ /*For swapping we need atleast 2 elements*/
        double dTemp = val[sp-1]; /*Store top element into the temp variable*/
        val[sp-1] = val[sp-2]; /*Then instead of top element store the second top element*/
        val[sp-2] = dTemp; /*Instead of second top store the top element*/
	printf("First Element: %.8g\n", val[sp-1]);
	printf("Second Element: %.8g\n", val[sp-2]);
    }
    else{
        printf("Error: Not enough elements to swap.\n");
    }
}

/*
 * clearStack(void): This function is used clear the stack                                           * Author: Akshat Darji
 * Created: 26 July 2024
 * Modified: 26 July 2024
*/

void clearStack(void){
	sp=0;
}

/*
 * performSin(void): This function used to perform Sin Operation
 * Author: Akshat Darji
 * Created: 26 July 2024
 * Modified: 26 July 2024
*/
void performSin(void){
	if(sp>0){ /*Check for underflow condition*/
		double dValue = pop(); /*store the top element into the value variable*/
		push(sin(dValue)); /*Push then sin(dValue) into the stack*/
	}
	else{
		printf("Error: Not Enough elements to perform SIN operation.\n");
	}
}

/*
 * performExp(void): This function used to perform Exponential Operation
 * Author: Akshat Darji
 * Created: 26 July 2024
 * Modified: 26 July 2024
*/
void performExp(void){ 
        if(sp>0){ /*Check for underflow condition*/
                double dValue = pop(); /*store the top element into the value variable*/
                push(exp(dValue)); /*Push then exp(dValue) into the stack*/
        }
        else{
                printf("Error: Not Enough elements to perform SIN operation.\n");
        }
}

/*
 * performSin(void): This function used to perform Sin Operation
 * Author: Akshat Darji
 * Created: 26 July 2024
 * Modified: 26 July 2024
*/
void performPow(void){
        if(sp>=2){ /*For power operation atleast we need 2 char into the stack*/
                double dExponent = pop(); /*Store the top element into the dExponent*/
		double dBase = pop(); /*Store the second top element into the dBase*/
                push(pow(dBase, dExponent)); /*Push the pow(dBase, dExponent) value into the stack*/
        }
        else{
                printf("Error: Not Enough elements to perform SIN operation.\n");
        }
}

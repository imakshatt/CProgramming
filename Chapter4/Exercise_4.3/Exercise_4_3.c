/**
Exercise_4_3: Given the basic framework, it's straightforward to extend the calculator. Add the modulus (%) operator and provisions for negative numbers.
Author: Akshat Darji
Created: 18 July 2024
Modified: 18 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

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

/** MAIN PROGRAM */
/*
 * main: detail overview of main function
*/


int main(){
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
			case '%':
				op2 = pop();
				if(op2 != 0.0){
					push((int)pop() % (int)op2);
				}
				else{
					printf("Error: Zero Division Error");
				}
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
 * getop(char s[]): detail of that function like what it accepts
 * Author: Akshat Darji
 * Created: 18 July 2024
 * Modified: 18 July 2024
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
 * getch(void): detail of that function like what it accepts
 * Author: Akshat Darji
 * Created: 19 July 2024
 * Modified: 19 July 2024
*/

char buf[BUFSIZE];
int bufp = 0;
int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/*
 * ungetch(int c): detail of that function like what it accepts
 * Author: Akshat Darji
 * Created: 19 July 2024
 * Modified: 19 July 2024
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
 * push(double f): detail of that function like what it accepts
 * Author: Akshat Darji
 * Created: 19 July 2024
 * Modified: 19 July 2024
*/
int sp = 0;
double val[MAXVAL];
void push(double f){
	if(sp < MAXVAL){
		val[sp++] = f;
	}
	else{
		printf("Error: Stack Full, can't push %g\n", f);
	}
}

/*
 * pop(): detail of that function like what it accepts
 * Author: Akshat Darji
 * Created: 19 July 2024
 * Modified: 19 July 2024
*/

double pop(){
	if(sp > 0){
		return val[--sp];
	}
	else{
		printf("Error: Stack is Empty\n");
		return 0.0;
	}
}



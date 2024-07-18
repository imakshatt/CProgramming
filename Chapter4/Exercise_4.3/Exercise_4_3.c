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
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0){
					push(pop() / op2);
				}
				else{
					printf("Error: Zero Division Error\n");
				}
			case '%':
				op2 = pop();
				if(op2 != 0.0){
					push(pop() % op2);
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

	s[1] = '\0';

	if(!isdigit(c) && c !='.' && c != '-'){
		return c;
	}

	i=0;

	if(isdigit(c)){
		while(isdigit(s[++i] = c = getch()));
	}

	if(c == '.'){
		while(isdigit(s[++i] = c = getch()));
	}

	if(c == '-' || isdigit(c)){
		while(isdigit(s[++i] = c = getch()));
	}
	if(strcmp(s, "-") == 0){
		return '-';
	}

	s[i] = '\0';

	if(c != EOF){
		ungetch(c);
	}
	return NUMBER;


}

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAXOP 100     /*Character string length*/
#define NUMBER '0'    /*Number or not */
#define MAXVAL 100    /*Stack size*/
#define BUFSIZE 100



int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);


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


int sp = 0;

double val[MAXVAL];

//push
void push(double f){
	//overflow condition
	if(sp < MAXVAL){
		//sp++;
		val[sp++] = f;		
	}
	else{
		printf("Error: Stack Full, can't push %g\n", f);
	}
}

//pop
double pop(){
	if(sp > 0){
		//sp--;
		return val[--sp];
	}
	else{
		printf("Error: Stack Empty\n");
		return 0.0;
	}
}


int getop(char s[]){
	int i,c;

	while((s[0] = c = getch()) == ' ' || c == '\t');

	s[1] = '\0';

	if(!isdigit(c) && c != '.' && c != '-'){
		return c;
	}

	i = 0;
	if(isdigit(c)){
		while(isdigit(s[++i] = c = getch()));
	}

	if(c == '.'){
		while(isdigit(s[++i] = c = getch()));
	}
	s[i] = '\0';

	if(c != EOF){
		ungetch(c);
	}
	return NUMBER;

}


char buf[BUFSIZE];
int bufp = 0;
int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
	if(bufp >= BUFSIZE){
		printf("Ungetch: too many characters\n");
	}
	else{
		buf[bufp++] = c;
	}
}


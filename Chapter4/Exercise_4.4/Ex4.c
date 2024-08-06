/**
Exercise_4_4: Add the commands to print the top elements of the stack without popping, to duplicate it, and to swap the top two elements. Add a command to clear the stack.
Author: Akshat Darji
Created: 26 July 2024
Modified: 26 July 2024
*/

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/** MACRO DEFINITIONS */
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
void printInstructions(void);

/** GLOBAL VARIABLES */
int sp = 0; /* Pointer to traverse into the stack */
double val[MAXVAL]; /* Initialize the stack */
char buf[BUFSIZE]; /* Initialize the buffer array to store the non-numeric char */
int bufp = 0; /* Initialize buf pointer to zero */

/** MAIN PROGRAM */
int main() {
    printInstructions(); /* Printing the instructions for the user */
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER: /* If type == '0' then this case performs */
                push(atof(s)); /* Converting s into double and push to stack */
                break; /* Break the case */

            case '+':   /* If type == '+' then we have to perform Addition */
                if (sp < 2) {
                    printf("Error: Not enough elements in stack for addition.\n");
                } else {
                    push(pop() + pop()); /* Pop first 2 elements and perform '+' */
                }
                break; /* Break the case */

            case '*': /* If type == '*' then we have to perform Multiplication */
                if (sp < 2) {
                    printf("Error: Not enough elements in stack for multiplication.\n");
                } else {
                    push(pop() * pop()); /* Pop first 2 elements and perform '*' */
                }
                break;

            case '-': /* If type == '-' then perform Subtraction */
                /* As in Subtraction Sign and order matters hence use op2 */
                if (sp < 2) {
                    printf("Error: Not enough elements in stack for subtraction.\n");
                } else {
                    op2 = pop(); /* Store top element of stack in op2 */
                    push(pop() - op2); /* Now pop last element and perform '-' */
                }
                break;

            case '/': /* If type == '/' then perform Division */
                /* As in Division Sign and order matters */
                /* And also encounter zero division error */
                if (sp < 2) {
                    printf("Error: Not enough elements in stack for division.\n");
                } else {
                    op2 = pop(); /* Store first element of stack in op2 */
                    if (op2 != 0.0) { /* Check if op2 == 0 then '/' Not possible */
                        push(pop() / op2); /* Perform '/' */
                    } else {
                        printf("Error: Zero Division Error\n"); /* Error Handling */
                    }
                }
                break;

            case '%': /* If type == '%' then perform Modulo */
                /* As in Modulo Sign and order matters */
                /* And also encounter zero division error */
                if (sp < 2) {
                    printf("Error: Not enough elements in stack for modulo.\n");
                } else {
                    op2 = pop(); /* Store first element of stack in op2 */
                    if (op2 != 0.0) { /* Check if op2 == 0 then '%' Not possible */
                        push((int) pop() % (int) op2);
                    } else {
                        printf("Error: Zero Division Error\n"); /* Error Handling */
                    }
                }
                break;

            case 'P': /* To print top element of the stack */
                peek();
                break;
            case 'D': /* To Duplicate top element of the stack */
                duplicatetop();
                break;
            case 'S': /* To Swap top 2 element of the stack */
                swapTopTwo();
                break;
            case 'C': /* To clear the stack */
                clearStack();
                break;
            case '\n':
                if (sp > 0) {
                    printf("\t%.8g\n", pop());
                }
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

void printInstructions(void) {
    printf("Welcome to the Calculator!\n");
    printf("You can perform the following operations:\n");
    printf(" - Addition: + (Requires at least 2 elements in the stack)\n");
    printf(" - Subtraction: - (Requires at least 2 elements in the stack)\n");
    printf(" - Multiplication: * (Requires at least 2 elements in the stack)\n");
    printf(" - Division: / (Requires at least 2 elements in the stack, Division by zero is not allowed)\n");
    printf(" - Modulo: %% (Requires at least 2 elements in the stack, Division by zero is not allowed)\n");
    printf(" - Print Top Element: P (Prints the top element of the stack without popping it)\n");
    printf(" - Duplicate Top Element: D (Duplicates the top element of the stack)\n");
    printf(" - Swap Top 2 Elements: S (Swaps the top two elements of the stack)\n");
    printf(" - Clear the Stack: C (Clears all elements from the stack)\n");
    printf("Enter your commands followed by Enter:\n");
    printf("\nError Handling:\n");
    printf(" - If there aren't enough elements in the stack for operation, an error message will be displayed.\n");
    printf(" - Division and modulo operations will display an error message if there is an attempt to divide by zero.\n");
    printf(" - If you try to print, duplicate, or swap elements when the stack is empty, an error message will be displayed.\n");
    printf(" - The stack can hold up to %d elements. Attempting to push more elements will result in an overflow error.\n", MAXVAL);
    printf(" - Unknown commands will be reported as errors.\n");
}

/*
 * getop(char s[]): This function is used to read the operators and operands from i/p
 * Author: Akshat Darji
 * Created: 26 July 2024
 * Modified: 26 July 2024
*/

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t');  /* For Skipping Space and Tab */

    s[1] = '\0'; /* Make s[1] as EOF for temp */

    if (!isdigit(c) && c != '.' && c != '-') { /* Case for Handling Non Digit Char
	                                              If !isdigit(c) then return that operator */
        return c;  /* Return to main and stored in type */
    }

    i = 0; /* Initializing i as ZERO */

    /* For Handle Negative Character */
    /* Because there are 2 possibilities One is -Ve Operand and -ve is also Operator */
    if (c == '-') {  /* Check as C is '-' or not */
        char next = getch();  /* If it is then store the next value in next variable */
        if (isdigit(next) || next == '.') { /* Now check for that NEXT value like isdigit & . */
            s[++i] = c = next; /* then store that in s[] */
        } else {
            ungetch(next); /* Otherwise handling the space using ungetch() */
            return c; /* And if that is operator then return That Sign */
        }
    }

    if (isdigit(c)) { /* This is the case for handling Digit */
        while (isdigit(s[++i] = c = getch())); /* continue until we get digit */
    }

    if (c == '.') { /* For fractional part */
        while (isdigit(s[++i] = c = getch()));
    }

    s[i] = '\0'; /* At the End at ith location in s[] mark as EOF */

    if (c != EOF) {  /* If C is not an EOF then */
        ungetch(c); /* Handle it in Buffer */
    }
    return NUMBER; /* At the End Return the number stored in s[] as '0' for switch case */
}

/*
 * getch(void): to read the character from the i/p string
 * Author: Akshat Darji
 * Created: 26 July 2024
 * Modified: 26 July 2024
*/

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar(); /* Check if bufp is zero then only it reads the char from the input string and if bufp is 1 then it clears the buffer first then only read it */
}

/*
 * ungetch(int c): to store the non-numeric value in the buf[]
 * Author: Akshat Darji
 * Created: 26 July 2024
 * Modified: 26 July 2024
*/

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("Ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

/*
 * push(double f): This function push the value into the stack val[]
 * Author: Akshat Darji
 * Created: 26 July 2024
 * Modified: 26 July 2024
*/

void push(double f) { /* Cache the value */
    if (sp < MAXVAL) { /* Check for the overflow condition */
        val[sp++] = f; /* If not then only push the value into the stack */
    } else {
        printf("Error: Stack Full, can't push %g\n", f); /* Else error */
    }
}

/*
 * pop(): This function delete the top element from the stack
 * Author: Akshat Darji
 * Created: 26 July 2024
 * Modified: 26 July 2024
*/

double pop(void) {
    if (sp > 0) { /* Check for underflow condition */
        return val[--sp]; /* if there are values then delete top element */
    } else {
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

void peek(void) {
    if (sp > 0) { /* Checking for underflow condition */
        printf("Top Element: %.8g\n", val[sp-1]); /* Print the TOP Element */
    } else {
        printf("Error: Stack is Empty can't print top element\n");
    }
}

/*
 * duplicatetop(void): This function is used to duplicate the top element
 * Author: Akshat Darji
 * Created: 26 July 2024
 * Modified: 26 July 2024
*/

void duplicatetop(void) {
    if (sp > 0 && sp < MAXVAL) { /* Checking for overflow and underflow condition */
        double dTop = val[sp-1]; /* Store the top element of stack */
        push(dTop); /* Push that again into stack to duplicate that */
    } else if (sp == 0) {
        printf("Error: Stack is Empty can't duplicate.\n");
    } else {
        printf("Error: Stack Overflow, can't duplicate.\n");
    }
}

/*
 * swapTopTwo(void): This function is used to swap top 2 elements of stack 
 * Author: Akshat Darji
 * Created: 26 July 2024
 * Modified: 26 July 2024
*/

void swapTopTwo(void) {
    if (sp >= 2) { /* For swapping we need at least 2 elements */
        double dTemp = val[sp-1]; /* Store top element into the temp variable */
        val[sp-1] = val[sp-2]; /* Then instead of top element store the second top element */
        val[sp-2] = dTemp; /* Instead of second top store the top element */
        printf("First Element: %.8g\n", val[sp-1]); 
        printf("Second Element: %.8g\n", val[sp-2]);
    } else {
        printf("Error: Not enough elements to swap.\n");
    }
}

/*
 * clearStack(void): This function is used to clear the stack
 * Author: Akshat Darji
 * Created: 26 July 2024
 * Modified: 26 July 2024
*/

void clearStack(void) {
    sp = 0;
}

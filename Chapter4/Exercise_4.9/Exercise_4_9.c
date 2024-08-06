                                                                                                    /**                                                                                                 Exercise_4_9: Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what their properties ought to be if an EOF is pushed back, then implement your design.
Author: Akshat Darji
Created: 30 July 2024
Modified: 30 July 2024
*/

/** REQUIRED HEADER FILES */
#include<stdio.h>

/** MARCO DEFINATIONS */
#define BUFSIZE 100

/** FUNCTION PROTOTYPES */
void ungetch(int c);
int getch(void);
void test_pushed_back_EOF();


/** MAIN PROGRAM */                                                                                 /*                                                                                                   * main: In exercise 4-3 getch and ungetch is not capable of pushing EOF properly so we need to improve these problem and has to generate new getch() and ungetch()  such that it can push EOF properly so for that reason here main calls one function test_pushed_back_EOF to ensure that the EOF handled correctly in that function we ungetch the EOF.                         
*/
int main(){
	test_pushed_back_EOF();
	return 0;
}


int buf[BUFSIZE]; /*Here instead of char buf[BUFSIZE] to handle EOF i use int buf*/
int bufp = 0;
/*
 * getch(void): to read the character from the i/p string
 * Author: Akshat Darji
 * Created: 30 July 2024
 * Modified: 30 July 2024
*/

int getch(){
	return (bufp>0) ? buf[--bufp] : getchar();
}


/*
 * ungetch(int c): to store the non-numeric value in the buf[]
 * Update: Here i have to handle EOF also so instead of char i use int in buf
 * Author: Akshat Darji
 * Created: 30 July 2024
 * Modified: 30 July 2024
*/

void ungetch(int c){
	if(bufp>=BUFSIZE){
		printf("Error: To many characters for ungetch.\n");
	}
	else{
		buf[bufp++] = c;
	}
}

/*
 * test_pushed_back_EOF(): To check EOF is handled correctly or not
 * Author: Akshat Darji
 * Created: 30 July 2024
 * Modified: 30 July 2024
*/

void test_pushed_back_EOF() {
    printf("Test: Push Back and Read EOF\n");

    // Push back EOF
    ungetch(EOF);

    // Read using getch
    int c = getch();

    if (c == EOF) {
        printf("EOF handled correctly\n");
    } else {
        printf("Failed to handle EOF, got: %d\n", c);
    }
}

#include <stdio.h>

#define BUFSIZE 100

int buf[BUFSIZE]; /* Buffer for ungetch */
int bufp = 0;     /* Next free position in buf */

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

void test_pushed_back_eof() {
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

int main() {
    test_pushed_back_eof();
    return 0;
}

//Another way to For Input and Output

#include<stdio.h>

int main(){
	int c;
	while((c = getchar()) != EOF){
		putchar(c);
	}
	return 0;
}

#include<stdio.h>

int main(){
	printf("Three different ways to print value of i\n");
	int i = 3;
	printf("Address of i is: %p\n", &i);
	printf("Value of i is: %d\n", i);
	printf("Value of i is: %d\n", *(&i));
	return 0;
}

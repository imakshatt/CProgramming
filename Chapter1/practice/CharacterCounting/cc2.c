//Another way to count the characters using for loop
//Use of double and precision float


#include<stdio.h>

int main(){
	double nc;
	for(nc = 0;getchar()!=EOF;++nc);
	printf("%.2f\n",nc);
	return 0;
	
}


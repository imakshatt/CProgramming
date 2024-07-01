//Line counting

#include<stdio.h>

int main(){
	long c, n1;
	n1 = 0;
	while( (c=getchar()) != EOF){
		if(c=='\n'){
			n1++;
		}
	}
	printf("%ld\n", n1);
	return 0;

}

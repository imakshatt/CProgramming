//Character Counting 1st Version

#include<stdio.h>

int main(){
	long counter;
	counter = 0;

	while(getchar()!=EOF){
		++counter;
	}
	printf("%ld\n", counter);
	return 0;

}

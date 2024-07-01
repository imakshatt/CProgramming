//Type Conversion


#include<stdio.h>

int main(){
	int iC;
	int iN, i;

	iN = 0;
	while((iC=getchar())!=EOF){
		if(iC>='0' && iC<='9'){
			iN = 10*iN + (iC-'0');
		}
	}
	printf("%d: ", iN);
	printf("Size of iN: %ld", sizeof(iN));
	return 0;
}


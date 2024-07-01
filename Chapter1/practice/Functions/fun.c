//Use of Functions in C

#include<stdio.h>

int pow(int iM, int iN){
	int iAns = 1;
	for(int i=1;i<=iN;i++){
		iAns = iAns * iM;
	}
	return iAns;
}

int main(){
	int iM, iN;
	iM = 2;
	iN = 3;
	int iAns = pow(iM, iN);
	printf("%d\n", iAns);
	return 0;
}


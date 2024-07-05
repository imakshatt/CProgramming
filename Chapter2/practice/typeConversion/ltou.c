//Lower to Upper
//
#include<stdio.h>

int main(){
	int iC, iN;
	while((iC=getchar())!=EOF){
		if(iC>=97 && iC<=122){
			iN =  iC + 'A' - 'a';
			putchar(iN);
		}
		else{
			putchar(iC);
		}
	}
	return 0;
}

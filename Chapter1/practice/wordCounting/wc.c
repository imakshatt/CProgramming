#include<stdio.h>

#define IN 1 /*IN word*/
#define OUT 0 /*OUT word*/


int main(){
	int iC, iNl, iNc, iNw;
	int iState;
	iState = OUT; /*initially it is not in word*/

	iC=iNl=iNc=iNw=0;
	while((iC=getchar())!=EOF){
		++iNc;
		if(iC=='\n'){
			++iNl;
		}
		if(iC==' ' || iC=='\n' || iC=='\t'){
			iState=OUT;
		}
		else if(iState==OUT){
			iState=IN;
			++iNw;
		}
	}
	printf("%d\t%d\t%d\n", iNl, iNc, iNw);
	return 0;
}



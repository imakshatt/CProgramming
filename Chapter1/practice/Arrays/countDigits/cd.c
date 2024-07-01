//Count Digits, white spaces and others


#include<stdio.h>


int main(){

	int iC, iWhite, iOther;
	iWhite=iOther=0;
	int iNdigit[10];
	for(int i=0;i<10;i++){
		iNdigit[i]=0;
	}

	while((iC=getchar())!=EOF){
		if(iC >= '0' && iC <= '9'){
			iNdigit[iC-'0']++;
		}
		else if(iC==' ' || iC=='\n' || iC=='\t'){
			iWhite++;
		}
		else{
			iOther++;
		}
	}
	printf("Digits: ");
	for(int i=0;i<10;i++){
		printf("%d ", iNdigit[i]);
	}

	printf("\nWhite Spaces: ");
	printf("%d", iWhite);
	printf("\nOthers: ");
	printf("%d", iOther);
	return 0;
}

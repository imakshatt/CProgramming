//Upper to Lower (Charatcter Type conversation)
//

#include<stdio.h>

int main(){
	int iC, iNC;
	while((iC=getchar())!=EOF){
		if(iC>=65 && iC<=90){
			iNC = iC + 'a' - 'A';
			putchar(iNC);
		}
		else{
			putchar(iC);
		}
	}
	return 0;
}


#include<stdio.h>
#include<ctype.h>
#include<string.h>

void itoa(int n, char s[]);

int main(){

	char s[1000];
	int n = -128;
	itoa(n, s);

	//printf("%s\n", s);
}

/*void reverse(char s[]){
	int c, i, j;
	for(i=0, j=strlen(s)-1; i<j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}*/
void reverse(char s[]){
	char t[1000];
	int len = strlen(s);
	int index = 0;
	for(int j=len-1;j>=0;j--){
		t[index] = s[j];
		index++;
	}
	t[index] = '\0';
	printf("%s\n", t);
}

/*void itoa(int n, char s[]){
	int i, sign;
	if((sign=n)<0){
		n=-n;
	}
	i=0;
	do{
		s[i] = n%10 + '0';
		i++;
	}while((n/=10)>0);

	if(sign < 0){
		s[i] = '-';
		i++;
	}
	s[i] = '\0';
	reverse(s);
}*/

void itoa(int n, char s[]){

	int i, sign;
	if((sign=n)<0){
		n = -n;
	}
	i = 0;
	while(n>0){
		s[i] = n % 10 + '0';
		i++;
		n = n/10;
	}
	if(sign < 0){
		s[i] = '-';
		i++;
	}
	s[i] = '\0';
	reverse(s);
}

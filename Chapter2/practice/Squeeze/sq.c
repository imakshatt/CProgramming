//Remove all 'C' from the char s[]

#include<stdio.h>

int main(){
	char c = 'l';
	char s[] = "Hello";
	squeeze(s, c);
	printf("%s", s);
	return 0;
}

void squeeze(char s[], char c){
	int i, j;
	for(i=j=0;s[i]!='\0';i++){
		if(s[i]!=c){
			s[j]=s[i];
			j++;
		}
	}
	s[j]='\0';
}

#include<stdio.h>
#include<string.h>

void htoi(char cp[], int len);

int main(){
	
	char str[1000];
	scanf("%s", str);
	int len = strlen(str);
	printf("Length of the string: %d\n", len);	
	char cp[len];
	for(int i=0;i<len;i++){
		cp[i] = str[i];
	}

	for(int j=0;j<len;j++){
		printf("%c ", cp[j]);
	}
	htoi(cp, len);
	return 0;
}


void htoi(char cp[], int len){
        printf("\nThis Function Calls");
}

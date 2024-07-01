#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(){
	float fFah;
	float fCel;
	printf("Fahrenheit\tCelcius\n");
	fFah = LOWER;
	while(fFah <= UPPER){
		fCel = 5 * (fFah - 32) / 9;
		printf("%3.0f\t%6.1f\n", fFah, fCel);
		fFah = fFah + STEP;
	}
	return 0;
	
}

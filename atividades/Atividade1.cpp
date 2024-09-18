#include <stdio.h>
#include <stdlib.h>

float numeros[6];

int main(){
	
	float sum;
	for(int i = 0; i<6; i++){
		printf("digite o numero %d: ", 1+i);
		scanf("%f", &numeros[i]);
	}
	for(int i = 0; i<6; i++){
		printf("\nnumero %i: %.1f", 1+i,numeros[i]);
		sum += numeros[i];
	}
	
	printf("\nmedia = %.2f", sum/6);
	return 0;
}



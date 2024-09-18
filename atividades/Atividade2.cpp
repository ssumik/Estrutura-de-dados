#include <stdio.h>
#include <stdlib.h>

typedef struct software{
	char name[10];
	char manufacturer[10];
	char licenseType;
	float version;
}Software;

Software software[10];


void addSoftware(int i){
	printf("digite o nome do software: ");
	scanf(" %s", &software[i].name);
	printf("digite o fabricante do software: ");
	scanf(" %s", &software[i].manufacturer);
	printf("digite o tipo de lincen�a do software: ");
	scanf(" %c", &software[i].licenseType);
	printf("digite a vers�o do software: ");
	scanf(" %f", &software[i].version);
}

int main(){
	for(int i = 0; i<2; i++){
		addSoftware(i);
	}
	for(int i = 0; i<2; i++){
		printf("\ndados %i: \nnome: %s \nfabricante: %s \ntipo de licenca: %c \nversao do software: %.1f", 1+i, software[i].name, software[i].manufacturer,software[i].licenseType,software[i].version);
	}
	
	return 0;
}



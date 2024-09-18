#include <stdio.h>
#include <stdlib.h>

typedef struct number{
	int num;
	struct number *prox;
}Number;

Number *inicio;

void addNumber(int toAddNumber){
	Number *num = (Number*) malloc(sizeof(Number));
	num->num = toAddNumber;
	num->prox = inicio;
	inicio = num;
}

void showNum(){
	if(inicio == NULL){
        printf("Lista vazia!\n");
    }else{
        Number *aux = inicio;
        while (aux != NULL)
        {
            printf("%i\n", aux->num);
            aux = aux->prox;
        }
        
    }
}

int main(){
	int voltas;
	printf("quantos numeros deseja escrever?: ");
	scanf("%i", &voltas);
	for(int i = 0; i<voltas; i++){
		int n;
		printf("digite um numero: ");
		scanf("%i", &n);
		addNumber(n);
	}
	showNum();
	return 0;
}



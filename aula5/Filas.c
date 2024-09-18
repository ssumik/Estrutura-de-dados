#include <stdio.h>
#include <stdlib.h>

struct pessoa
{
	int senha;
	struct pessoa *prox;
};

typedef struct pessoa Pessoa;

Pessoa *fila;

void add(int senha){
    Pessoa *p = (Pessoa*) malloc(sizeof(Pessoa));
    p->senha = senha;
    p->prox = NULL;

    if(fila==NULL){
        fila = p;
    }else{
        Pessoa *auxFila = fila;
        while(auxFila->prox!=NULL){
            auxFila = auxFila->prox;
        }
        auxFila->prox = p;
    }
}

void imprime(Pessoa *p){
    if(p!=NULL){
        printf("Senha da pessoa: %d\n", p->senha);
        imprime(p->prox);
    }
}

void rem(){
    if(fila==NULL){
        printf("fila vazia.");
    }else{
        fila = fila->prox;
    }
}

int main(){
    add(5);
	add(8);
	add(10);
	add(22);
   

    Pessoa *filaAux = fila;
    imprime(filaAux);

    printf("\n");
    printf("\n");

    rem();
    filaAux = fila;

    imprime(filaAux);

    return 0;
}
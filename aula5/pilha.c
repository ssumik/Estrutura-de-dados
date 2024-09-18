#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa
{
	int senha;
	struct pessoa *prox;
}Pessoa;

Pessoa *pilha;

void add(int senha){
    Pessoa *p = (Pessoa*) malloc(sizeof(Pessoa));
    p->senha = senha;
    p->prox = pilha;
    pilha = p;
}

void imprime(Pessoa *p){
    if(p!=NULL){
        printf("Senha da pessoa: %d\n", p->senha);
        imprime(p->prox);
    }
}

void rem(Pessoa *p){
    if(pilha==NULL){
        printf("fila vazia.");
    }else{
        pilha = p->prox;
    }
}

int main(){

    add(100);
    add(200);
    add(300);

    Pessoa *pilhaAux = pilha;    
    imprime(pilhaAux);
    
    rem(pilha);
    printf("\n");
    pilhaAux = pilha;
    imprime(pilhaAux);
    return 0;
}
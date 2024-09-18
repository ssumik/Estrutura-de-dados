#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    char nome[20];
    int idade;
    struct lista *prox;
}Lista;

int main(){
    Lista *inicio = NULL;
    Lista *fim = NULL;
    Lista *aux;
    int i;

    for(i = 0; i < 3; i++){
        Lista *novo = (Lista*) malloc(sizeof(Lista));
        printf("Digite o nome: ");
        scanf("%s", novo->nome);
        fflush(stdin);
        printf("Digite a idade: ");
        scanf("%d", &novo->idade);
        fflush(stdin);

        if(inicio == NULL){
            inicio = novo;
            fim = inicio;
            novo->prox = NULL;
        }else{
            novo->prox = inicio;
            inicio = novo;
        }
    }

    for (i = 0; i < 2; i++){
        Lista *novo = (Lista*) malloc(sizeof(Lista));
        printf("Digite o nome: ");
        scanf("%s", novo->nome);
        fflush(stdin);
        printf("Digite a idade: ");
        scanf("%d", &novo->idade);
        fflush(stdin);
        
        if(fim == NULL){
            inicio = novo;
            fim = inicio;
            novo->prox = NULL;
        }else{
            fim->prox = novo;
            fim = novo;
        }
    }

    if(inicio == NULL){
        printf("Lista vazia!\n");
    }else{
        aux = inicio;
        while (aux != NULL)
        {
            printf("%s, %i\n", aux->nome, aux->idade);
            aux = aux->prox;
        }
        
    }

    return 0;
}
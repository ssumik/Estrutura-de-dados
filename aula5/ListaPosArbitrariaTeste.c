#include <stdio.h>
#include <stdlib.h>

typedef struct numero{
    int num;
    struct numero *proximo;
}Numero;

Numero *primeiro;

int lenght = 0;

void pushIndex(int num, int index){
    Numero *n = (Numero*) malloc(sizeof(Numero));
    n->num = num;
    if(index>lenght){
        printf("Posicao invalida.\n");
    }else{
        if(index==0){
            n->proximo=primeiro;
            primeiro=n;
        }else{
            int i = 0;
            Numero *auxPrimeiro = primeiro;
            while(i!=index-1){
                auxPrimeiro = auxPrimeiro->proximo;
                i++;
            }
            n->proximo = auxPrimeiro->proximo;
            auxPrimeiro = n;
        }
        lenght++;
    }
}

void imprime(Numero *p){
    if(p!=NULL){
        printf("%d\n", p->num);
        imprime(p->proximo);
    }
}

void popIndex(int index){
    if(index>lenght){
        printf("Posicao invalida.");
    }else{
        if(index==0){
            primeiro = primeiro->proximo;
        }else{
            Numero *aux= primeiro;
            int i = 0;
            while(i!=index-1){
                aux = aux->proximo;
                i++;
            }
            aux->proximo=aux->proximo->proximo;
            lenght--;
        }
    }
}

int main(){
    pushIndex(1,0);
    pushIndex(2,0);
    pushIndex(3,0);
    pushIndex(4,0);
    pushIndex(5,0);
    pushIndex(6,0);
    pushIndex(7,0);
    pushIndex(8,0);
    pushIndex(9,0);

    popIndex(8);
    Numero *primeiroAux = primeiro;
    imprime(primeiroAux);
    printf("\ntamanho da lenght: %d", lenght);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct DinamicPile {
   int num;
   DinamicPile *next;
} Pile;

Pile *topo = NULL;
Pile *aux = NULL;

void push(int n) {
    Pile *newPile = (Pile*)malloc(sizeof(Pile));

    newPile->num = n;
    newPile->next= topo;
    topo = newPile;
}

void pop() {
    if(topo != NULL) {
        Pile *garbage;
        garbage = topo;
        printf("Deletando %d...\n", topo->num);
        topo = topo->next;
        free(garbage);
        return;
    }
    printf("Nenhum elemento para deletar!\n");
}

void printPile() {
    aux = topo;
    while (aux != NULL) {
        printf("%d\n", aux->num);
        aux = aux->next;
    }
}

int main() {
    int opt;
    int n;

    do {
        printf("Selecione uma opção\n");
        printf("[1] Adicionar numero\n");
        printf("[2] Remover numero\n");
        printf("[3] Mostra numeros\n");
        printf("[4] Sair\n");
        printf(">> ");
        scanf("%d", &opt);
        fflush(stdin);

        switch (opt) {
        case 1:
            printf("Digite um numero para adicionar na pilha\n>> ");
            scanf("%d", &n);
            push(n);
            break;

        case 2:
            pop();
            break;

        case 3:
            printPile();
            break;

        case 4:
            printf("Saindo...");
            break;
        
        default:
            printf("Opcao invalida");
            break;
        }
    } while(opt != 4);

    return 0;
}
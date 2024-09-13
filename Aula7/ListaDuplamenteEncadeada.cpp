#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

typedef struct list {
    list *previous;
    int num;
    list *next;
} LIST;

int main() {
    setlocale(LC_ALL, "Portuguese");

    LIST *firstElement = NULL;
    LIST *lastElement = NULL;
    LIST *aux = NULL;
    LIST *previousElement = NULL;
    LIST *newElement = NULL;
    int opt;
    int finded;

    do{
        system("cls");
        printf("Selecione uma opcao:\n");
        printf("[1] - Inserir no inicio\n");
        printf("[2] - Inserir no final\n");
        printf("[3] - Imprimir a lista\n");
        printf("[4] - Imprimir lista reversa\n");
        printf("[5] - Remover da lista\n");
        printf("[6] - Limpar lista\n");
        printf("[7] - Sair\n");
        printf(">> ");
        scanf("%d", &opt);
        fflush(stdin);
        system("cls");

        switch(opt){
            case 1:
                newElement = (LIST*) malloc(sizeof(LIST));
                printf("Digite um valor:\n>> ");
                scanf("%d", &newElement->num);
                fflush(stdin);

                if(firstElement == NULL) {
                    firstElement = newElement;
                    lastElement = firstElement;
                    newElement->previous = NULL;
                    newElement->next = NULL;
                    printf("Primeiro item inserido!");
                    getch();
                    break;
                }

                firstElement->previous = newElement;
                newElement->next = firstElement;
                firstElement = newElement;
                printf("Numero inserido no inicio da lista!");
                getch();
                break;

            case 2:
                newElement = (LIST*) malloc(sizeof(LIST));
                printf("Digite um valor:\n>>");
                scanf("%d", &newElement->num);
                fflush(stdin);

                if(firstElement == NULL) {
                    firstElement = newElement;
                    lastElement = firstElement;
                    newElement->next = NULL;
                    printf("Primeiro item inserido!");
                    getch();
                    break;
                }

                lastElement->next = newElement;
                newElement->previous = lastElement;
                lastElement = newElement;
                printf("Numero inserido no fim da lista!");
                getch();
                break;

            case 3:
                printf("Imprimindo lista:\n");
                aux = firstElement;

                if(firstElement == NULL) {
                    printf("A lista está vazia!");
                    getch();
                    break;
                }

                while(aux != NULL) {
                    printf("%d\n", aux->num);
                    aux = aux->next;
                }
                getch();
                break;

            case 4:
                printf("Imprimindo lista reversa:\n");
                aux = lastElement;

                if(lastElement == NULL) {
                    printf("A lista está vazia!");
                    getch();
                    break;
                }

                while(aux != NULL) {
                    printf("%d\n", aux->num);
                    aux = aux->previous;
                }
                getch();
                break;

            case 5:
                if(firstElement == NULL) {
                    printf("A lista está vazia!");
                    getch();
                    break;
                }

                int number;
                printf("Digite um valor para deletar:\n>> ");
                scanf("%d", &number);
                
                aux = firstElement;
                previousElement = NULL;
                finded = 0;

                while(aux != NULL) {
                    if(aux->num == number) {
                        finded++;

                        if(aux == firstElement) {
                            firstElement = firstElement->next;
                            firstElement->previous = NULL;
                            aux = firstElement;
                            continue;
                        }

                        if(aux == lastElement) {
                            previousElement->next = NULL;
                            lastElement = previousElement;
                            aux = NULL;
                            continue;
                        }

                        previousElement->next = aux->next;
                        aux = aux->next;
                        aux->previous = previousElement;
                        continue;
                    }

                    previousElement = aux;
                    aux = aux->next;
                }

                printf("%d numeros foram removidos da lista!", finded);
                getch();
                break;

            case 6:
                if(firstElement == NULL) {
                    printf("Lista vazia!");
                    getch();
                    break;
                }

                firstElement = NULL;
                lastElement = NULL;
                break;

            case 7:
                printf("Saindo...");
                getch();
                break;
                
            default:
                printf("Opcao invalida!");
                getch();
                break;
        }
    }while(opt != 7);

    return 0;
}
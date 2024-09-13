#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

typedef struct list {
    int num;
    list *next;
} LIST;

int main() {
    setlocale(LC_ALL, "Portuguese");

    LIST *firstElement = NULL;
    LIST *lastElement = NULL;
    LIST *aux = NULL;
    LIST *previous = NULL;
    LIST *list = NULL;
    int opt;
    int finded;


    do{
        system("cls");
        printf("Selecione uma opcao:\n");
        printf("[1] - Inserir no inicio\n");
        printf("[2] - Inserir no final\n");
        printf("[3] - Imprimira lista\n");
        printf("[4] - Remover da lista\n");
        printf("[5] - Limpar lista\n");
        printf("[6] - Sair\n");
        printf(">> ");
        scanf("%d", &opt);
        fflush(stdin);
        system("cls");

        switch(opt){
            case 1:
                list = (LIST*) malloc(sizeof(LIST));
                printf("Digite um valor:\n>> ");
                scanf("%d", &list->num);
                fflush(stdin);

                if(firstElement == NULL) {
                    firstElement = list;
                    lastElement = firstElement;
                    list->next = NULL;
                    printf("Primeiro item inserido!");
                    getch();
                    break;
                }

                list->next = firstElement;
                firstElement = list;
                printf("Numero inserido no inicio da lista!");
                getch();
                break;

            case 2:
                list = (LIST*) malloc(sizeof(LIST));
                printf("Digite um valor:\n>>");
                scanf("%d", &list->num);
                fflush(stdin);

                if(firstElement == NULL) {
                    firstElement = list;
                    lastElement = firstElement;
                    list->next = NULL;
                    printf("Primeiro item inserido!");
                    getch();
                    break;
                }

                lastElement->next = list;
                lastElement = list;
                lastElement->next = NULL;
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
                if(firstElement == NULL) {
                    printf("A lista está vazia!");
                    getch();
                    break;
                }

                int number;
                printf("Digite um valor para deletar:\n>> ");
                scanf("%d", &number);
                
                aux = firstElement;
                previous = NULL;
                finded = 0;

                while(aux != NULL) {
                    if(aux->num == number) {
                        finded++;

                        if(aux == firstElement) {
                            firstElement = firstElement->next;
                            aux = firstElement;
                            continue;
                        }

                        if(aux == lastElement) {
                            previous->next = NULL;
                            lastElement = previous;
                            aux = NULL;
                            continue;
                        }

                        previous->next = aux->next;
                        aux = aux->next;
                        continue;
                    }

                    previous = aux;
                    aux = aux->next;
                }

                printf("%d numeros foram removidos da lista!", finded);
                getch();
                break;

            case 5:
                if(firstElement == NULL) {
                    printf("Lista vazia!");
                    getch();
                    break;
                }

                firstElement = NULL;
                lastElement = NULL;
                break;

            case 6:
                printf("Saindo...");
                getch();
                break;
                
            default:
                printf("Opcao invalida!");
                getch();
                break;
        }
    }while(opt != 6);

    return 0;
}
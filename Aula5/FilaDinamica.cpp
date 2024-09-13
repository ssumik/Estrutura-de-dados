#include <stdio.h>
#include <stdlib.h>

typedef struct QueueElement {
    int number;
    QueueElement *nextElement;
} QElement;

QElement *firstElement = NULL;
QElement *lastElement = NULL;

void addElement(int n) {
    QElement *elementToAdd = (QElement*) malloc(sizeof(QElement));
    elementToAdd->number = n;
    elementToAdd->nextElement = NULL;

    if(firstElement == NULL) {
        firstElement = elementToAdd;
        lastElement = firstElement;
        return;
    }

    lastElement->nextElement = elementToAdd;
    lastElement = elementToAdd;
}

void removeElement() {
    if (firstElement == NULL) {
        printf("A fila esta vazia!\n");
        return;
    }

    QElement *garbage = firstElement;

    if (firstElement->nextElement == NULL) {
        printf("Deletando o numero %d, o ultimo da fila.\n", firstElement->number);
        firstElement = NULL;
        lastElement = firstElement;
        free(garbage);
        return;
    }
    
    printf("Deletando o numero %d da fila.\n", firstElement->number);
    firstElement = firstElement->nextElement;
    free(garbage);
}

void printQueue(QElement *elementToPrint) {
    if (elementToPrint == NULL) {
        return;
    }

    printf("%d\n", elementToPrint->number);
    printQueue(elementToPrint->nextElement);
}

int main() {
    int opt, n;

    do {
        printf("Selecione uma opcao:\n");
        printf("[1] Adicionar numero\n[2] Remover numero\n[3] Mostrar fila\n[4] Sair\n\n>> ");
        scanf("%d", &opt);
        fflush(stdin);

        switch(opt) {
            case 1:
                printf("Informe o numero (inteiro) que deseja adicionar a fila:\n>> ");
                scanf("%d", &n);
                addElement(n);
                break;

            case 2:
                removeElement();
                break;
            
            case 3:
                printQueue(firstElement);
                break;

            case 4:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }

    } while(opt != 4); 

    return 0;
}
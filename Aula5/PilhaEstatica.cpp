#include <stdio.h>
#include <stdlib.h>

char pilha[7];
int i, topo = 0;

void push(char aux) {
    pilha[topo] = aux;
    topo++;
}

void pop() {
    topo--;
    pilha[topo] = '\0';
}

void imprime() {
    for (i = 6; i >= 0; i--)
    {
        printf("\n[%i] %c", i, pilha[i]);
    }
    printf("\n");
}

int main(void) {
    push('c');
    imprime();
    return 0;
}
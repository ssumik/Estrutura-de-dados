#include <stdio.h>

int par(int n) {
    return ((n%2) == 0);
}

int main() {

    int numero = -1;

    printf("Digite um numero inteiro:\n>> ");
    scanf("%d", &numero);

    printf("\n\nO numero %d is %d (0 = fale ou 1 = true)", numero, par(numero));

    return 0;
}
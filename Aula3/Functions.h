#include <stdio.h>

// Imprime na tela apenas os numeros pares
void apenasPares(int n) {
    for(int i = 0; i <= n; i++) {
        if (i%2==0) {
            if(i!=n) {
                printf("%d - ", i);
                continue;
            }
            printf("%d", i);
        }
    }
}

int sqrt(int n) {
    return n*n;
}

// Retorna a quantidade de caracteres de uma string
int stringLen(char string[]) {
    int stringTamanho = 0;
    for(int i = 0; string[i] != '\0'; i++) {
        stringTamanho++;
    }
    return stringTamanho;
}

int restoDaDivisao(int n1, int n2) {
    return n1%n2;
}

int soma(int n1, int n2) {
    return n1+n2;
}

int subtracao(int n1, int n2) {
    return n1-n2;
}

int dobroMaisTriplo(int n1, int n2) {
    return 2*n1 + 3*n2;
}

int multiplicacao(int n1, int n2) {
    return n1*n2;
}

float calcularProcentagem(float num, float procentagem) {
    return num*procentagem/100;
}

int parOuMultiploDeSeis(int num) {
    if(num%2 == 0) {
        return 1;
    }
    if(num%6 == 0 && num >=6) {
        return 1;
    }
    return 0;
}

int calcularFatorial(int num) {
    int fatorial = 1;
    for(int i = num; i > 0; i--) {
        fatorial *= i;
    }
    return fatorial;
}
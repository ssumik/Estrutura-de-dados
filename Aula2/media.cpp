#include <stdio.h>
int cont = 0;
void notaValida(float n) {
    cont += !(n >= 0 && n <= 10);
}
int mediaFinal(float n1, float n2, float n3) {
    if (cont > 0) {
        printf("Verifique os valores inseridos!\n");
        printf("Notas invalidas: %d\n", cont);
        return 1;
    }
    printf("Media: %.1f", (n1+n2+n3)/3);
    return 0;
}
int main() {
    float n1, n2, n3;
    int run = 1;

    while (run == 1) {
        cont = 0;
        printf("Digite a nota 1\n>> ");
        scanf("%f", &n1);
        notaValida(n1);

        printf("Digite a nota 2\n>> ");
        scanf("%f", &n2);
        notaValida(n2);

        printf("Digite a nota 3\n>> ");
        scanf("%f", &n3);
        notaValida(n3);

        run = mediaFinal(n1, n2, n3);
    }
    return 0;
}
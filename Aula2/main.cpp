#include <stdio.h>
#include <string.h>

// Criando a primeira estrutura
typedef struct dotCoordenates {
    char nome[20];
    float x;
    float y;
} dotCoord; // typedef define 'dotCoord' como um tipo 'dotCoordenates'

typedef struct car {
    char *marca;
    char *nome;
    float km;
} car;

int main(void) {
    // Declarando variavel dotCoordenates
    dotCoord dot; // var dot do tipo 'dotCoord' que representa a struct 'dotCoordenates'
    car car; // var car do tipo 'car' que representa a struct 'car'

    // Atribuindo valores
    strcpy(dot.nome, "Ponto 1");
    dot.x = 0.0;
    dot.y = 0.0;

    // Acessando os valores
    printf("Nome do Ponto: %s\nValor de X = %.1f\nVlore de Y = %.1f\n", dot.nome, dot.x, dot.y);

    // Entrada de dados
    printf("Defina um valor para X\n>> ");
    scanf("%f", &dot.x);

    printf("Defina um valor para Y\n>> ");
    scanf("%f", &dot.y);

    printf("Nome do Ponto: %s\nValor de X = %.1f\nVlore de Y = %.1f", dot.nome, dot.x, dot.y);

    printf("Digite a marca de um carro\n>> ");
    scanf("%s", &car.marca);

    printf("Digite o nome de um carro desta marca\n>> ");
    scanf("%s", &car.nome);

    printf("Digite a quilometragem rodada\n>> ");
    scanf("%f", &car.km);

    printf("Marca: %s\nNome: %s\nKms: %.2f", car.marca, car.nome, car.km);

    return 0;
}
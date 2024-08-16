#include <stdio.h>

#include "Functions.h"

// Estrutura do ex_07 e ex_08
typedef struct dados {
    char character;
    float floatNum;
    int integer;
    double doubleNum;
} dado;

typedef struct folhaPagamento {
    char *nome = "Lucas Montano";
    float salario = 1500.00;
    float taxaDescontoINSS = 8;
} folhaPagamento;

int somaDosQuadrados(int n) {
    int resultado = 0;
    for(int i = 1; i <= n; i++) {
        resultado += sqrt(i);
    }
    return resultado;
}

void ordenaTamanhoString(char string1[], char string2[], char string3[]) {
    // Armazena o tamanho das strings
    int a = stringLen(string1), b = stringLen(string2), c = stringLen(string3), x;
    if(a > b) {
        x = b;
        b = a;
        a = x;
    }
    if(a > c) {
        x = c;
        c = a;
        a = x;
    }
    if(b > c) {
        x = c;
        c = b;
        b = x;
    }
    printf("%d, %d, %d", a, b, c);
}

dado alteraDadosEstrutura(dado data) {
    data.character += 5;
    data.floatNum += 1.3;
    data.integer += 3;
    data.doubleNum += 5.22222222222;
    return data;
}

void calcularSalarioLiquido(folhaPagamento folha) {
    float valorTaxa = calcularProcentagem(folha.salario, folha.taxaDescontoINSS);
    float salarioLiquido = folha.salario - valorTaxa;
    printf("Nome do funcionario: %s\nSalario bruto: %.2f\nValor do INSS: %.2f(%.1f%%)\nSalario liquido: %.2f\n", folha.nome, folha.salario, valorTaxa, folha.taxaDescontoINSS, salarioLiquido);
}

float calcularTaxaDescontoINSS(float salario) {
    if(salario <= 1000) {
        return 8;
    }
    if(salario <= 1500) {
        return 8.5;
    }
    return 9;
}

int main() {
    // exe_01. Declarar um conjunto de variáveis inteiras, reais e char.
    int integer, num1 = 20, num2 = 3;
    float real;
    char selection;
    dado dado;
    folhaPagamento fp;

    // Menu
    printf("Selecione uma das opcoes:\n");
    printf("[a] ex_02\n");
    printf("[b] ex_03\n");
    printf("[c] ex_04\n");
    printf("[d] ex_05\n");
    printf("[e] ex_07\n");
    printf("[f] ex_08\n");
    printf("[g] ex_09\n");
    printf("[h] ex_10\n");
    printf("[i] ex_11\n");
    printf("[j] ex_12\n");
    printf("[k] ex_13\n");
    printf(">> ");
    scanf("%c", &selection);
    fflush(stdin);

    // Switch para navegar entre exercícios
    switch (selection)
    {
    case 'a': case 'A':
        /* ex_02
         * Construir um loop para realizar 10 interações e imprimir somente os números pares das interações.
         */
        apenasPares(10);
        break;
    
    case 'b': case 'B':
        /* ex_03
         * Calcular o somatório dos quadrados dos valores de um até n.
         */
        printf("Digite um numero maior do que 0\n>> ");
        scanf("%d", &integer);
        printf("As somas dos quadrados de 1 ate %d e %d", integer, somaDosQuadrados(integer));
        break;
    
    case 'c': case 'C':
        /* ex_04 
         * Um programa declara três strings. Escrever um código que mostre de forma ordenada a quantidade de caracteres de cada uma.
         */
        ordenaTamanhoString("pc", "rgb", "HDMI");
        break;
    
    case 'd': case 'D':
        /* ex_05 
         * Construir uma função que retorne o resto de uma divisão entre dois números inteiros.
         */
        printf("Resto da divisao de %d por %d e %d", num1, num2, restoDaDivisao(num1, num2));
        break;

    case 'e': case 'E':
        /* ex_07 
         * Elabore um programa que contenha uma estrutura com pelo menos um dado char, um dado float, um dado int e um dado double. 
         * Receba os valores digitados pelo usuário, e exiba em tela todos os dados.
         */
        printf("Digite um caractere: ");
        scanf("%c", &dado.character);
        printf("Digite um numero float: ");
        scanf("%f", &dado.floatNum);
        printf("Digite um numero inteiro: ");
        scanf("%d", &dado.integer);
        printf("Digite um numero double: ");
        scanf("%lf", &dado.doubleNum);
        printf("Os dados digitados foram:\n");
        printf("Char: %c\nFloat: %f\nInt: %d\nDouble: %lf", dado.character, dado.floatNum, dado.integer, dado.doubleNum);
        break;
    
    case 'f': case 'F':
        /* ex_08
         * Elabore uma função que receba uma estrutura como parâmetro, 
         * altere os valores dos membros da estrutura e devolva para a função principal imprimir esses valores alterados.
         */
        dado.character = 'a';
        dado.floatNum = 1.5;
        dado.integer = 2;
        dado.doubleNum = 2.5555555555555555555;
        printf("Dados antes:\nChar: %c\nFloat: %f\nInt: %d\nDouble: %lf", dado.character, dado.floatNum, dado.integer, dado.doubleNum);
        dado = alteraDadosEstrutura(dado);
        printf("Dados depois:\nChar: %c\nFloat: %f\nInt: %d\nDouble: %lf", dado.character, dado.floatNum, dado.integer, dado.doubleNum);
        break;
    
    case 'g': case 'G':
        /* ex_09
         * Um programa que contém duas variáveis inteiras e cada uma destas variáveis deve ter um valor atribuído.
         * Escrever um programa que mostre os seguintes resultados:
         * A soma das duas variáveis.
         * A diferença entre as duas variáveis.
         * O dobro da primeira mais o triplo da segunda variável.
         * A multiplicação das duas variáveis.
         */
        printf("Soma de %d e %d: %d\n",num1, num2, soma(num1, num2));
        printf("Diferenca de %d e %d: %d\n", num1, num2, subtracao(num1, num2));
        printf("O dobro de %d mais o triplo de %d: %d\n", num1, num2, dobroMaisTriplo(num1, num2));
        printf("A multiplicacao de %d por %d: %d\n", num1, num2, multiplicacao(num1, num2));
        break;
    
    case 'h': case 'H':
        /* ex_10
         * Uma folha de pagamento simplificada contém os itens: 
         * Nome do Funcionário, Salário e Taxa de Desconto de INSS. Criar um programa que considere uma taxa de desconto de 8% e mostre no vídeo:
         * Nome do Funcionário.
         * Salário bruto.
         * Valor do INSS.
         * Salário líquido.
         */
        calcularSalarioLiquido(fp);
        break;
    
    case 'i': case 'I':
        /* ex_11
         * Baseando no item anterior, escreva um programa que define uma taxa de desconto de acordo com o seguinte critério:
         * Salário até R$ 1.000,00 – desconto de 8%
         * Salário entre R$ 1.000,01 e 1.500,00 – desconto de 8,5%
         * Salário acima de R$ 1.500,00 – desconto de 9%
         */
        fp.salario = 1500.01;
        fp.taxaDescontoINSS = calcularTaxaDescontoINSS(fp.salario);
        calcularSalarioLiquido(fp);
        break;
    
    case 'j': case 'J':
        /* ex_012
         * Criar um programa que receba um número “X” inteiro e mostre no vídeo somente os números pares ou múltiplos de 6, entre zero e X.
         */
        printf("Digite um numero inteiro: ");
        scanf("%d", &integer);
        printf("Os numeros pares e/ou divisiveis por 6 sao:\n");
        for(int i = 0; i <= integer; i++) {
            if(parOuMultiploDeSeis(i)) {
                if(i != integer) {
                    printf("%d - ", i);
                    continue;
                }
                printf("%d", i);
            }
        }
        break;
    
    case 'k': case 'K':
        /* ex_13
         * Escrever um programa que calcule o número fatorial de um número.
         */
        printf("Digite um numero para caluclar o fatorial: ");
        scanf("%d", &integer);
        printf("O fatorial de %d e %d\n", integer, calcularFatorial(integer));
        break;
    
    default:
        printf("Opcao invalida!!");
        break;

    }

    return 0;
}
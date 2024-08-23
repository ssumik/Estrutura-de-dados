#include <stdio.h>
#include <math.h>

/*
 * Utilizando pointeiros
 */

void fatorialDe(int num, int *fatorial) {
	*fatorial = 1;
	for(int i = num; i > 0; i--) {
		*fatorial *= i;
	}
}

void areaCirc(int raio, float *area) {
	*area = 3.14 * pow(raio, 2);
}

void bhaskara(int a, int b, int c, float *x1, float *x2) {
	*x1 = (-b + sqrt(pow(b, 2)-4*a*c))/(2*a);
	*x2 = (-b - sqrt(pow(b, 2)-4*a*c))/(2*a);
}

int main() {
	int opt, num, fatorial, raio, a =1, b =-5, c =6;
	float areaCirculo, x1, x2;

	printf("Selecione uma das opcoes abaixo:\n");
	printf("[1] Fatorial\n[2] Area do circulo\n[3] Bhaskara\n");
	printf(">> ");
	scanf("%d", &opt);
	fflush(stdin);

	switch (opt) {
		case 1:
			printf("Digite um numero para descobrir o fatorial\n>> ");
			scanf("%d", &num);
			fflush(stdin);
			fatorialDe(num, &fatorial);
			printf("Fatorial de %d: %d\n", num, fatorial);
			break;
		
		case 2:
			printf("Digite o raio de um circulo em milimetros\n>> ");
			scanf("%d", &raio);
			fflush(stdin);
			areaCirc(raio, &areaCirculo);
			printf("Area do circulo com raio %dmm: %.2f\n", raio, areaCirculo);
			break;

		case 3:
			printf("Bhaskara--------\nA: %d\nB: %d\nC: %d\n", a, b, c);
			bhaskara(a, b, c, &x1, &x2);
			printf("X1 = %f\nX2 = %f", x1, x2);
			break;
		
		default:
			printf("Opcao invalida!");
			break;
	}
	return 0;
}

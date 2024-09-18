#include <stdio.h>
#include <stdlib.h>

typedef struct dicipline{
	int classroom;
    char dayOfWeek[10];
    char className[10];
    int semester;
	struct dicipline *prox;
}Dicipline;


Dicipline *inicio;
Dicipline *fim;

void addClass(){
	Dicipline *cl = (Dicipline*) malloc(sizeof(Dicipline));
		printf("digite a sala:");
		scanf("%i", &cl->classroom);
		printf("digite o dia da semana: ");
		scanf("%s", &cl->dayOfWeek);
		printf("digite o nome da materia: ");
		scanf("%s", &cl->className);
		printf("digite o semestre: ");
		scanf("%i", &cl->semester);

    if(inicio == NULL){
        inicio = cl;
        fim = cl;
    }else{
        fim->prox = cl;
        fim = cl;
    }
}

void showData(){
	if(inicio == NULL){
        printf("Lista vazia!\n");
    }else{
        Dicipline *aux = inicio;
        while (aux != NULL)
        {
            printf("\n");
            printf("sala: %i\n", aux->classroom);
            printf("materia: %s\n", aux->className);
            printf("dia da semana: %s\n", aux->dayOfWeek);
            printf("semestre: %i\n", aux->semester);
            aux = aux->prox;
        }
        
    }
}

int main(){
	int voltas;
	printf("Quantas materias deseja registrar?: ");
	scanf("%i", &voltas);
	for(int i = 0; i<voltas; i++){
		addClass();
	}
    printf("\ndados:");
	showData();
	return 0;
}



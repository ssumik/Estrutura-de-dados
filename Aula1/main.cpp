#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main(void) {
    cout << "Teste de iostring\n";

    char l = 'A';
    switch (l) {
        case 'a': case 'A':
            printf("letra A\n");
            break;
        
        default:
            break;
    }

    char nome[] = "Pedro";
    for (int i = 0; i < sizeof nome; i++) {
        printf("%c\n", nome[i]);
    }

    printf("-----------------------------");

    if (sizeof nome > 5) { // Nome com mais de 4 letras
        for(int i = sizeof nome - 1; i >= 0; i--) {
            printf("%c\n", nome[i]);
        }
    }
    
    int j = 0;
    while (j < 10) {    
        printf("%d, ", j+1);
        j++;
    }
    
    
}
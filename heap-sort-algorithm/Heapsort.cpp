#include <stdio.h>
#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int aux=0;

    int binaryTree[8] = {12, 3, 9, 14, 10, 18, 8, 23};

    /* for(int i = 0; i < 4; i++) {
        binaryTree[i] = rand() % 101;
        printf("%d - ", binaryTree[i]);
    } */

    for(int j = 0; j < 8; j++) {
        if(binaryTree[2*j+1] <= binaryTree[j]) {
            aux = binaryTree[2*j+1];
            binaryTree[2*j+1] = binaryTree[j];
            binaryTree[j] = aux;
        }

        if(binaryTree[2*j+2] <= binaryTree[j]) {
            aux = binaryTree[2*j+2];
            binaryTree[2*j+2] = binaryTree[j];
            binaryTree[j] = aux;
        }
    }

    for(int k = 0; k < 8; k++) {
        printf("%d ", binaryTree[k]);
    }

    return 0;
}
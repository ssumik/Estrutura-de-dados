#include <stdio.h>
#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()

int aux=0;

void MIN_HEAP (int *binaryTree) {
    for(int j = 0; j < 8; j++) {
        if(binaryTree[2*j+1] <= binaryTree[j] && 2*j+1 < 8) {
            aux = binaryTree[2*j+1];
            binaryTree[2*j+1] = binaryTree[j];
            binaryTree[j] = aux;
        }

        if(binaryTree[2*j+2] <= binaryTree[j] && 2*j+2 < 8) {
            aux = binaryTree[2*j+2];
            binaryTree[2*j+2] = binaryTree[j];
            binaryTree[j] = aux;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int binaryTree[8] = {12, 3, 9, 14, 10, 18, 8, 23};
    //                  3, 12, 9, 14, 10, 18, 8, 23

    /* for(int i = 0; i < 8; i++) {
        binaryTree[i] = rand() % 101;
        printf("%d - ", binaryTree[i]);
    } */

    MIN_HEAP(binaryTree);

    for(int k = 0; k < 8; k++) {
        printf("%d ", binaryTree[k]);
    }

    //hello rapaz
    return 0;
}

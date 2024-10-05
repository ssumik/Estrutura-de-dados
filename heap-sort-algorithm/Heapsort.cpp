#include <stdio.h>
#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()

int aux=0;

void printBinaryTree(int *binaryTree) {
    for(int k = 0; k < 8; k++) {
        if (k == 7) {
            printf("%d\n", binaryTree[k]);
            return;
        }
        
        printf("%d ", binaryTree[k]);
    }
}

void MIN_HEAP (int *binaryTree) {
    
    int change = 0;
    do {
        change = 0;
        for(int j = 0; j < 8; j++) {
            if(binaryTree[2*j+1] <= binaryTree[j] && 2*j+1 < 8) {
                aux = binaryTree[2*j+1];
                binaryTree[2*j+1] = binaryTree[j];
                binaryTree[j] = aux;
                change = 1;
            }

            if(binaryTree[2*j+2] <= binaryTree[j] && 2*j+2 < 8) {
                aux = binaryTree[2*j+2];
                binaryTree[2*j+2] = binaryTree[j];
                binaryTree[j] = aux;
                change = 1;
            }
            printf("Change: %d\n", change);
        }
    } while (change != 0);
    
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int binaryTree[8] = {3, 12, 9, 14, 10, 18, 8, 23};
    //3, 12, 9, 14, 10, 18, 8, 23
    //43, 40, 55, 15, 84, 45, 71, 97

    for(int i = 0; i < 8; i++) {
        binaryTree[i] = rand() % 101;
    }

    printBinaryTree(binaryTree);
    MIN_HEAP(binaryTree);
    printBinaryTree(binaryTree);

    //hello rapaz
    return 0;
}

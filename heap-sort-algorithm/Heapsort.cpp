#include <stdio.h>
#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()

// Função para imprimir a árvore binária
void printBinaryTree(int *binaryTree, int LEN) {
    for(int k = 0; k < LEN; k++) {  // Corrigido o limite de impressão
        if (k == LEN - 1) {
            printf("%d\n", binaryTree[k]);
        } else {
            printf("%d ", binaryTree[k]);
        }
    }
}

// Função para aplicar a lógica Min-Heap
void MIN_HEAP(int *binaryTree, int LEN) {
    int aux = 0;
    int change;
    do {
        change = 0;
        for (int j = 0; j <= LEN / 2 - 1; j++) {
            int left = 2 * j + 1;
            int right = 2 * j + 2;

            if (left < LEN && binaryTree[left] < binaryTree[j]) {
                aux = binaryTree[left];
                binaryTree[left] = binaryTree[j];
                binaryTree[j] = aux;
                change = 1;
            }

            if (right < LEN && binaryTree[right] < binaryTree[j]) {
                aux = binaryTree[right];
                binaryTree[right] = binaryTree[j];
                binaryTree[j] = aux;
                change = 1;
            }
        }
    } while (change != 0);
}

// Função para organizar o heap em ordem crescente
void MIN_HEAP_ORGANIZATION(int *binaryTree, int *binaryTreeOrganized, int LEN) {
    int originalLen = LEN;
    for (int i = 0; i < originalLen; i++) {  // Ajustado o limite da iteração
        MIN_HEAP(binaryTree, LEN);
        binaryTreeOrganized[i] = binaryTree[0];  // Copia a raiz (menor valor)
        binaryTree[0] = binaryTree[LEN - 1];     // Move o último elemento para a raiz
        LEN--;  // Reduz o tamanho da heap
    }
}

// Função para imprimir um vetor
void imprime_vetor(int *vetor, int total) {
    for(int i = 0; i < total; i++) {
        printf("\nVetor[%d] = %d", i, vetor[i]);
    }
    printf("\n");
}

void gerar_vetor(int *vetor, int n, int opt) {
    int j, aux;
    switch (opt) {
        case 1: // Ordenado
            for(int i = 0; i < n; i++) {
                vetor[i] = i;
            }
            break;
    
        case 2: // Decrescente
            j = n - 1;
            for(int i = 0; i < n; i++) {
                vetor[i] = j--;
            }
            break;

        case 3: // Aleatório
            for(int i = 0; i < n; i++) {
                vetor[i] = i;
            }

            srand(time(0));
            for(int i = 0; i < n; i++) {
                j = rand() % n;
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
            break;
    }
}

int main() {
    const int n = 20;  // Tamanho do vetor
    int vetor[n];

    // Gera vetor aleatório
    gerar_vetor(vetor, n, 3);
    
    // Imprime o vetor gerado
    imprime_vetor(vetor, n);

    int binaryTreeOrganized[n];  // Ajustado o tamanho para n

    // Organiza o vetor usando Min-Heap
    printBinaryTree(vetor, n);
    printf("\n");
    MIN_HEAP_ORGANIZATION(vetor, binaryTreeOrganized, n);
    printBinaryTree(binaryTreeOrganized, n);

    printf("\nFinalizado!!!\n");

    return 0;
}
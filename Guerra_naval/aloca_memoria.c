#include "aloca_memoria.h"
#include<stdio.h>
#include<stdlib.h>

int *aloca_vetor(int num){
    int *vetor = (int*)malloc(num * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memória para as linhas da matriz.\n");
        return NULL;
    }

    return vetor;
}

int **aloca_matriz(int linhas, int colunas){

    int **matriz = (int**)malloc(linhas * sizeof(int*));
    if (matriz == NULL) {
        printf("Erro ao alocar memória para as linhas da matriz.\n");
        return NULL;
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória para as colunas da matriz.\n");
            return NULL;
        }
    }

    return matriz;
}

void free_matriz(int **matriz, int linhas){

    if(matriz == NULL) {
        return; // Verifica se a matriz é nula
    }

    for (int i = 0; i < linhas; i++) {
        free(matriz[i]); // Libera cada linha da matriz
    }

    free(matriz); // Libera o ponteiro para a matriz
}

void free_vetor(int *vetor){
    if(vetor == NULL) {
        return; // Verifica se a matriz é nula
    }
    free(vetor);
}

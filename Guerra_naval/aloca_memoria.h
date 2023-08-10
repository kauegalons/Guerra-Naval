#ifndef __ALOCAMEMORIA_H_
#define __ALOCAMEMORIA_H_

int **aloca_matriz(int linhas, int colunas);
int *aloca_vetor(int num);
void free_matriz(int **matriz, int linhas);
void free_vetor(int *vetor);

#endif
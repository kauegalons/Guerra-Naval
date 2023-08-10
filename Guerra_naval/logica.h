#ifndef __FUNCAO_H_
#define __FUNCAO_H_

void inicializa_tabuleiro(int **tabuleiro, int linhas, int colunas);

void inicia_navios(int **localizazao_navio, int navios, int max);

void dar_tiro(int *tiro, int **tabuleiro, int minimo, int maximo);
void dar_tiroPc(int *tiro_pc, int **tabuleiro, int maximo);

int acertou(int *tiro, int **localizacao_navio, int quant_navio);
void alteraTabuleiro(int *tiro, int **localizacao_navio, int **tabuleiro, int quant_navios);

void dica(int *tiro_jogador, int **localizacao_navioPc, int quant_navios);



#endif
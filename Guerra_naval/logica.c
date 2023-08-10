#include "logica.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

void inicializa_tabuleiro(int **tabuleiro, int linhas, int colunas){

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            tabuleiro[i][j] = -1;
        }
    }

}

void inicia_navios(int **localizazao_navio, int navios, int max){

    int anterior;

    for(int i = 0; i < navios; i++){

        localizazao_navio[i][0] = rand() % max;
        localizazao_navio[i][1] = rand() % max;

        for(anterior=0 ; anterior < i ; anterior++){
            if((localizazao_navio[i][0] == localizazao_navio[anterior][0]) && (localizazao_navio[i][1] == localizazao_navio[anterior][1])){
                do{
                    localizazao_navio[i][0] = rand() % max;
                    localizazao_navio[i][1] = rand() % max;
                }while((localizazao_navio[i][0] == localizazao_navio[anterior][0]) && (localizazao_navio[i][1] == localizazao_navio[anterior][1]));
            }
        }
    }
}

void dar_tiro(int *tiro_jogador, int **tabuleiroPc, int minimo, int maximo){

    //temos que decrementar um numero do elemento, pois o usuario nao ve linha nem coluna zero
    
    do{    
        do{
            fflush(stdin);
            printf("Linha: ");
            scanf("%d", &tiro_jogador[0]);

            tiro_jogador[0]--;

            if(tiro_jogador[0] < minimo || tiro_jogador[0] > maximo){
                printf("\033[0;31m");
                printf("Linha invalida. Tente novamente\n");
                printf("\033[0m");

            }
            
        }while(tiro_jogador[0] < minimo || tiro_jogador[0] > maximo);

        do{
            printf("Coluna: ");
            scanf("%d", &tiro_jogador[1]);

            
            tiro_jogador[1]--;

            if(tiro_jogador[1] < minimo || tiro_jogador[1] > maximo){
                printf("\033[0;31m");
                printf("Coluna invalida. Tente novamente\n");
                printf("\033[0m");
            }
            
        }while(tiro_jogador[1] < minimo || tiro_jogador [1] > maximo);

        if(tabuleiroPc[tiro_jogador[0]][tiro_jogador[1]] != -1){
            printf("\033[0;31m");
            printf("\nCoordenada ja jogada. Tente novamente\n\n");
            printf("\033[0m");
        }

    }while(tabuleiroPc[tiro_jogador[0]][tiro_jogador[1]] != -1);
            
}

void dar_tiroPc(int *tiro_pc, int **tabuleiro, int maximo){

    //temos que decrementar um numero do elemento, pois o usuario nao ve linha nem coluna zero
    
    do{    
        
        tiro_pc[0] = (rand() % maximo) + 1;
        tiro_pc[0]--;

        tiro_pc[1] = (rand() % maximo) + 1;
        tiro_pc[1]--;

    }while(tabuleiro[tiro_pc[0]][tiro_pc[1]] != -1);
            
}

int acertou(int *tiro, int **localizacao_navio, int quant_navio){

    int cont = 0;
    for(int i = 0; i < quant_navio; i++){
        if(tiro[0] == localizacao_navio[i][0] && tiro[1] == localizacao_navio[i][1]){
            return 1;
        }
    }
    return 0;
}

void alteraTabuleiro(int *tiro, int **localizacao_navio, int **tabuleiro, int quant_navios){
        if(acertou(tiro, localizacao_navio, quant_navios)){
            tabuleiro[tiro[0]][tiro[1]] = 1;
        }
        else{
            tabuleiro[tiro[0]][tiro[1]] = 0;
        }
}

void dica(int *tiro_jogador, int **localizacao_navioPc, int quant_navios){
        int linha = 0, coluna = 0;
        //conta quantos navios há na linha tiro[0]
        for(int i = 0; i < quant_navios; i++){
            if(localizacao_navioPc[i][0] == tiro_jogador[0]){
                linha++;
            }
            if(localizacao_navioPc[i][1] == tiro_jogador[1]){
                coluna++;
            }
        }
        printf("Dica: \nLinha %d -> %d navios\nColuna %d -> %d navios\n", tiro_jogador[0]+1, linha, tiro_jogador[1]+1, coluna);
}

#include "func_imprime.h"
#include<stdio.h>
#include<stdlib.h>


void imprime_menu(){

    printf("MENU\n");
    printf("1 - Facil\n");
    printf("2 - Dificil\n");
    printf("3 - Registro de jogos anteriores\n");
    printf("4 - Sair\n");
}

void mostra_tabuleiro(int **tabuleiro){

    printf("\t1 \t2 \t3 \t4 \t5");
    printf("\n");
    
    for(int i = 0; i < 5; i++){
        printf("%d", i + 1);
        for(int j = 0; j < 5; j++){ 


            if(tabuleiro[i][j] == -1){
                
                printf("\033[0;34m"); 
                printf("\t~");
                printf("\033[0m"); 
            }
            else if(tabuleiro[i][j] == 0){
                printf("\t*");
            }
            else if(tabuleiro[i][j] == 1){
                printf("\033[0;31m");
                printf("\tX");
                printf("\033[0m"); 
            }
        }
        printf("\n");
    }
}

void mostraTabuleiroDificil(int **tabuleiro){

    printf("\t1 \t2 \t3 \t4 \t5 \t6 \t7 \t8 \t9 \t10");
    printf("\n");

    for(int i = 0; i < 10; i++){
        printf("%d", i + 1);
        for(int j = 0; j < 10; j++){
            if(tabuleiro[i][j] == -1){
                printf("\033[0;34m"); 
                printf("\t~");
                printf("\033[0m"); 
            }
            else if(tabuleiro[i][j] == 0){
                printf("\t*");
            }
            else if(tabuleiro[i][j] == 1){
                printf("\033[0;31m");
                printf("\tX");
                printf("\033[0m"); 
            }
        }
        printf("\n");
    }
}

void imprime_legenda(){

    printf("Legenda:\n");
    printf("* - Tiro errado\n");
    printf("~ - Mar\n");
    printf("X - Navio destruido\n\n");


}

void imprime_vencedor(){
        printf("WW      WW  IIIIIII  NN     NN  NNN    NN  EEEEEEE  RRRRRR\n");
        printf("WW      WW    II     NNN    NN  NNNN   NN  EE       RR   RR\n");
        printf("WW   W  WW    II     NN N   NN  NN NN  NN  EEEEE    RRRRRR\n");
        printf(" WW WWW WW    II     NN  N  NN  NN  NN NN  EE       RR  RR\n");
        printf("  WW   WW   IIIIIII  NN   NNNN  NN   NNNN  EEEEEEE  RR   RR\n");
        printf("\n\n");
}

void imprime_perdedor(){

    printf("HH     HH   OOOO   RRRRRR     RRRRRR   IIIIIII   VV     VV  EEEEEEEE  LLL          \n");
    printf("HH     HH  OO  OO  RR   RR    RR   RR    II      VV     VV  EE        LLL          \n");
    printf("HHHHHHHHH OO    OO RRRRRR     RRRRRR     II       VV   VV   EEEEE     LLL          \n");
    printf("HH     HH OO    OO RR  RR     RR  RR     II        VV VV    EE        LLL          \n");
    printf("HH     HH  OO  OO  RR   RR    RR   RR    II         VVV     EEEEEEE   LLLLLLLLLL   \n");
    printf("HH     HH   OOOO   RR    RR   RR    RR IIIIIII       VV     EEEEEEE   LLLLLLLLLL   \n");
    printf("\n\n");

}
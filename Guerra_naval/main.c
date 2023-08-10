#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<unistd.h>

#include "logica.h"
#include "func_imprime.h"
#include "aloca_memoria.h"
#include "registra_arquivo.h"

int main(){


    while(true){

        
        srand(time(NULL));
        int opcao;
        int **tabuleiro, **tabuleiroPc, **localizacao_navio, **localizacao_navioPc;
        int *tiro_jogador, *tiro_pc;

        int acertos_jogador = 0;
        int acertos_maquina = 0;
        int tentativas = 0;
        char *nome = (char*) malloc(55*sizeof(char));

        system("cls");

        do{
            imprime_menu();
            scanf("%d", &opcao);

            if(opcao < 1 || opcao > 4){
                printf("Opcao invalida. Tente novamente\n\n");
            }
        }while(opcao < 1 || opcao > 4);
        

        switch(opcao){
            case 4:
                printf("Voce saiu!");
                exit(1);

            case 3:
                system("cls");
                printf("Historico de partidas\n\n");
                imprime_registro();
                printf("Pressione qualquer tecla para voltar ao menu");
                fflush(stdin);
                getchar();
                break;
            
            case 1:

                tabuleiro = aloca_matriz(5, 5); //aloca memoria para o tabuleiro do jogador
                tabuleiroPc = aloca_matriz(5, 5); // aloca memoria para o tabuleiro da maquina
                tiro_jogador = aloca_vetor(2); //aloca memori
                tiro_pc = aloca_vetor(2);
                localizacao_navio = aloca_matriz(3, 2); //cria uma matriz para armazenar a posição de 3 navios
                localizacao_navioPc = aloca_matriz(3, 2); //cria uma matriz para armazenar a posição de 3 navios

                inicializa_tabuleiro(tabuleiro, 5, 5); //preenche com -1
                inicializa_tabuleiro(tabuleiroPc, 5, 5); //preenche com -1
                inicia_navios(localizacao_navio, 3, 5); //gera coordenadas aleatorias de 3 navios, ira gerar entra coordenada 0 e 4;
                inicia_navios(localizacao_navioPc, 3, 5); //gera coordenadas aleatorias de 3 navios 0 e 4;

                system("cls");
                printf("Aperte qualquer tecla para iniciar...");
                fflush(stdin);
                getchar();
                system("cls");
                
                printf("Digite seu nome/nick: ");
                scanf("%s", nome);
                system("cls");

                while(true){
         
                    int flag = 0;
                    imprime_legenda();
                    printf("Navios inimigos destruidos: %d\n", acertos_jogador);
                    printf("Navios aliados abatidos: %d\n", acertos_maquina);
                    printf("Tentativas: %d\n\n", tentativas);
                    printf("\033[0;32m");
                    printf("Seu tabuleiro\n");
                    printf("\033[0m");        
                    mostra_tabuleiro(tabuleiro);

                    printf("\033[0;31m");
                    printf("\nTabuleiro do adversario\n");
                    printf("\033[0m");
                    mostra_tabuleiro(tabuleiroPc);

                    printf("\n");
                    dar_tiro(tiro_jogador, tabuleiroPc, 0, 4);
                    dar_tiroPc(tiro_pc, tabuleiro, 4);

                    if(acertou(tiro_jogador, localizacao_navioPc, 3)){
                        acertos_jogador++;
                        printf("\033[0;32m");
                        printf("Voce Acertou!\n\n");
                        printf("\033[0m");
                    }
                    else{
                        printf("\033[0;31m");
                        printf("Voce Errou!\n\n");
                        printf("\033[0m");
                        flag = 1;
                    }
                    tentativas++;
                    if(acertos_jogador == 3){
                        sleep(1.5);
                        system("cls");
                        imprime_vencedor();
                        printf("Pressione qualquer tecla para voltar ao menu...");
                        fflush(stdin);
                        getchar();
                        break;
                    }

                    printf("Adversario esta jogando...\n");
                    sleep(2);

                    if(acertou(tiro_pc, localizacao_navio, 3)){
                        acertos_maquina++;
                        printf("\033[0;32m");
                        printf("Adversario acertou seu navio!\n\n");
                        printf("\033[0m");
                    }
                    else{
                        printf("\033[0;31m");
                        printf("Adversario errou!\n\n");
                        printf("\033[0m");
                    }

                    if(acertos_maquina == 3){
                        sleep(1.5);
                        system("cls");
                        imprime_perdedor();
                        printf("Pressione qualquer tecla para voltar ao menu...");
                        fflush(stdin);
                        getchar();
                        break;
                    }

                    alteraTabuleiro(tiro_jogador, localizacao_navioPc, tabuleiroPc, 3);
                    alteraTabuleiro(tiro_pc, localizacao_navio, tabuleiro, 3);
                    sleep(1.5);
                    system("cls");

                    printf("Seu turno!");
                    sleep(1.3);
                    system("cls");

                    if(flag == 1){
                        dica(tiro_jogador, localizacao_navioPc, 3);
                        printf("\n");
                    }
                }

                registra_vitoria(nome, tentativas, acertos_jogador);

                free_matriz(tabuleiro, 5); 
                free_matriz(tabuleiroPc, 5); 
                free_matriz(localizacao_navio, 3); 
                free_matriz(localizacao_navioPc, 3); 
                free_vetor(tiro_jogador);
                free_vetor(tiro_pc);

                break;

            case 2:

                tabuleiro = aloca_matriz(10, 10); //aloca memoria para o tabuleiro do jogador
                tabuleiroPc = aloca_matriz(10, 10); // aloca memoria para o tabuleiro da maquina
                tiro_jogador = aloca_vetor(2); //aloca memori
                tiro_pc = aloca_vetor(2);
                localizacao_navio = aloca_matriz(6, 2); //cria uma matriz para armazenar a posição de 3 navios
                localizacao_navioPc = aloca_matriz(6, 2); //cria uma matriz para armazenar a posição de 3 navios

                inicializa_tabuleiro(tabuleiro, 10, 10); //preenche com -1
                inicializa_tabuleiro(tabuleiroPc, 10, 10); //preenche com -1
                inicia_navios(localizacao_navio, 6, 10); //gera coordenadas aleatorias de 6 navios
                inicia_navios(localizacao_navioPc, 6, 10); //gera coordenadas aleatorias de 6 navios
                acertos_jogador = 0;
                acertos_maquina = 0;
                tentativas = 0;

                system("cls");
                printf("Aperte qualquer tecla para iniciar...");
                fflush(stdin);
                getchar();
                system("cls");
                
                printf("Digite seu nome/nick: ");
                scanf("%s", nome);
                system("cls");

                while(true){

                    int flag = 0;
                    imprime_legenda();
                    printf("Navios inimigos destruidos: %d\n", acertos_jogador);
                    printf("Navios aliados abatidos: %d\n", acertos_maquina);
                    printf("Tentativas: %d\n\n", tentativas);
                    printf("\033[0;32m");
                    printf("Seu tabuleiro\n");
                    printf("\033[0m");        
                    mostraTabuleiroDificil(tabuleiro);

                    printf("\033[0;31m");
                    printf("\nTabuleiro do adversario\n");
                    printf("\033[0m");
                    mostraTabuleiroDificil(tabuleiroPc);

                    printf("\n");
                    dar_tiro(tiro_jogador, tabuleiroPc, 0, 9); //parametro 0 e 9 sao para definir o maximo que o user pode jogar
                    dar_tiroPc(tiro_pc, tabuleiro, 9);

                    if(acertou(tiro_jogador, localizacao_navioPc, 6)){
                        acertos_jogador++;
                        printf("\033[0;32m");
                        printf("Voce Acertou!\n\n");
                        printf("\033[0m");
                    }
                    else{
                        printf("\033[0;31m");
                        printf("Voce Errou!\n\n");
                        printf("\033[0m");
                        flag = 1;
                    }
                    tentativas++;
                    if(acertos_jogador == 6){
                        sleep(1.5);
                        system("cls");
                        imprime_vencedor();
                        printf("Pressione qualquer tecla para voltar ao menu...");
                        fflush(stdin);
                        getchar();
                        break;
                    }

                    printf("Adversario esta jogando...\n");
                    sleep(2);

                    if(acertou(tiro_pc, localizacao_navio, 6)){
                        acertos_maquina++;
                        printf("\033[0;32m");
                        printf("Adversario acertou seu navio!\n\n");
                        printf("\033[0m");
                    }
                    else{
                        printf("\033[0;31m");
                        printf("Adversario errou!\n\n");
                        printf("\033[0m");
                    }

                    if(acertos_maquina == 6){
                        sleep(1.5);
                        system("cls");
                        imprime_perdedor();
                        printf("Pressione qualquer tecla para voltar ao menu...");
                        fflush(stdin);
                        getchar();
                        break;
                    }

                    alteraTabuleiro(tiro_jogador, localizacao_navioPc, tabuleiroPc, 6);
                    alteraTabuleiro(tiro_pc, localizacao_navio, tabuleiro, 6);
                    sleep(1.5);
                    system("cls");

                    printf("Seu turno!");
                    sleep(1.3);
                    system("cls");

                    if(flag == 1){
                        dica(tiro_jogador, localizacao_navioPc, 6);
                        printf("\n");
                    }
                }

                registra_vitoria(nome, tentativas, acertos_jogador);

                free_matriz(tabuleiro, 5); 
                free_matriz(tabuleiroPc, 5); 
                free_matriz(localizacao_navio, 3); 
                free_matriz(localizacao_navioPc, 3); 
                free_vetor(tiro_jogador);
                free_vetor(tiro_pc);

                break;


        }    
    }

    return 0;   
}

//projeto finalizado

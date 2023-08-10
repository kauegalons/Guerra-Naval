#include "registra_arquivo.h"
#include<stdio.h>
#include<stdlib.h>


void registra_vitoria(char *nome, int tentativas, int acertos_jogador){
    FILE *arquivo;
    
    // Abrir o arquivo para escrita
    arquivo = fopen("Jogadores.txt", "a");
    
    // Verificar se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    // Gravar o nome no arquivo

    if(acertos_jogador == 3 || acertos_jogador == 6){
        fprintf(arquivo, "Vitoria!\nJogador: %s\nTentativas: %d\n\n", nome, tentativas);
    }
    else{
        fprintf(arquivo, "Derrota!\nJogador: %s\nTentativas: %d\n\n", nome, tentativas);
    }
    
    // Fechar o arquivo
    fclose(arquivo);
}


void imprime_registro(){
    FILE *arquivo;
    char linha[100];

    // Abrir o arquivo para leitura
    arquivo = fopen("Jogadores.txt", "r");

    // Verificar se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Ler e exibir o conteúdo do arquivo linha por linha
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    // Fechar o arquivo
    fclose(arquivo);
}
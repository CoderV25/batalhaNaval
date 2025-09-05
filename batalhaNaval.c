#include <stdio.h>

// Tabuleiro 

#define LINHAS 10
#define COLUNAS 10

int main (){

    // Tabuleiro
    int tabuleiro[LINHAS][COLUNAS];
    int agua = 0;

    // Navios

    int navio = 3;

    // Navio 1 (Horizontal)
    int navio1_Linha_Inicial = 2;
    int navio1_Coluna_Inicial = 2;


    // Navio 2 (Vertical)
    int navio2_Linha_Inicial = 5;
    int navio2_Coluna_Inicial = 5;


    // Navio 3 (Diagonal 1)
    int navio3_Linha_Inicial = 7;
    int navio3_Coluna_Inicial = 7;

    // Navio 4 (Diagonal 2)

    int navio4_Linha_Inicial = 7;
    int navio4_Coluna_Inicial = 2;
    
    // Tamanho do Tabuleiro.
    for (int i = 0; i < LINHAS; i ++){

        for(int j = 0; j < COLUNAS; j++){
            tabuleiro[i][j] = agua;

        }
    }

    // Posicionamento do Navio 1. (Horizontal)

    // Verifica se o navio não sai dos limites do Tabuleiro.
    if(navio1_Coluna_Inicial + 3 > COLUNAS){
        printf("Erro: o navio sai dos limites do Tabuleiro! \n");
        return 1;

    } else {
        for (int i = 0; i < 3; i++){
            
            // Posiciona o navio na horizontal a partir da linha e coluna inicial.
            tabuleiro[2][2 + i] = navio;
        }
    }

    // Posicionamento do Navio 2. (Vertical)

    //Verifica se o navio não sai dos limites do Tabuleiro.
    if(navio2_Linha_Inicial + navio > LINHAS){
        printf("Erro: o navio sai dos limites do Tabuleiro! \n");
        return 1;
    }

    //Verifica se alguma posição está ocupada.
    for(int i = 0; i < navio; i++){

        if(tabuleiro[navio2_Linha_Inicial + i][navio2_Coluna_Inicial] == navio){
            printf("Erro: Um navio já está ocupando esta posição. \n");
            return 1;
        }
    }

    // Se as verificações não mostrou erros, o navio será posicionado

    for(int i = 0; i < navio; i ++){

        // Posiciona o navio na vertical a partir da linha e coluna inicial.
        tabuleiro[navio2_Linha_Inicial + i][navio2_Coluna_Inicial] = navio;
    }


    //Posicionamento Navio 3. (Diagonal 1)

    //Verifica se o navio não sai dos limites do Tabuleiro.
    if(navio3_Linha_Inicial + navio > LINHAS && navio3_Coluna_Inicial + navio > COLUNAS){
        printf("Erro: o navio sai dos limites do Tabuleiro! \n");
        return 1;
    }

    //Verifica se alguma posição está ocupada.
    for(int i = 0; i < navio; i++){

        if(tabuleiro[navio3_Linha_Inicial + i][navio3_Coluna_Inicial + i] == navio){
            printf("Erro: Um navio já está ocupando esta posição. \n");
            return 1;
        }
    }

    // Se as verificações não mostrou erros, o navio será posicionado

    for(int i = 0; i < navio; i ++){

        // Posiciona o navio na vertical a partir da linha e coluna inicial.
        tabuleiro[navio3_Linha_Inicial + i][navio3_Coluna_Inicial + i] = navio;
    }

    //Posicionamento Navio 4. (Diagonal 2)

    //Verifica se o navio não sai dos limites do Tabuleiro.
    if(navio4_Linha_Inicial - navio > LINHAS && navio4_Coluna_Inicial - navio > COLUNAS){
        printf("Erro: o navio sai dos limites do Tabuleiro! \n");
        return 1;
    }

    //Verifica se alguma posição está ocupada.
    for(int i = 0; i < navio; i++){

        if(tabuleiro[navio4_Linha_Inicial - i][navio4_Coluna_Inicial - i] == navio){
            printf("Erro: Um navio já está ocupando esta posição. \n");
            return 1;
        }
    }

    // Se as verificações não mostrou erros, o navio será posicionado

    for(int i = 0; i < navio; i ++){

        // Posiciona o navio na vertical a partir da linha e coluna inicial.
        tabuleiro[navio4_Linha_Inicial - i][navio4_Coluna_Inicial - i] = navio;
    }

    // Exibindo o Tabuleiro

    printf("=== TABULEIRO BATALHA NAVAL ===");

    for(int i = 0; i < LINHAS; i++){

        for(int j = 0; j < COLUNAS; j++){

            printf("%d ", tabuleiro[i][j]);

        }

        printf("\n");

    }
    
    return 0;
}
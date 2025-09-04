
#include <stdio.h>


int main (){

    // Tabuleiro
    int tabuleiro[10][10];
    int agua = 0;

    // Navios

    int navio = 3;

    // Navio 1 (Horizontal)
    int navio1_Linha_Inicial = 2;
    int navio1_Coluna_Inicial = 2;


    // Navio 2 (Vertical)
    int navio2_Linha_Inicial = 5;
    int navio2_Coluna_Inicial = 5;

    
    // Tamanho do Tabuleiro.
    for (int i = 0; i < 10; i ++){

        for(int j = 0; j < 10; j++){
            tabuleiro[i][j] = agua;

        }
    }

    // Posicionamento do Navio 1. (Horizontal)

    // Verifica se o navio não sai dos limites do Tabuleiro.
    if(navio1_Coluna_Inicial + 3 > 10){
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
    if(navio2_Linha_Inicial + 3 > 10){
        printf("Erro: o navio sai dos limites do Tabuleiro! \n");
        return 1;
    }

    //Verifica se alguma posição está ocupada.
    for(int i = 0; i < 3; i++){

        if(tabuleiro[navio2_Linha_Inicial + i][navio2_Coluna_Inicial] == navio){
            printf("Erro: Um navio já está ocupando esta posição. \n");
            return 1;
        }
    }

    // Se as verificações não mostrou erros, o navio será posicionado

    for(int i = 0; i < 3; i ++){

        // Posiciona o navio na vertical a partir da linha e coluna inicial.
        tabuleiro[navio2_Linha_Inicial + i][navio2_Coluna_Inicial] = navio;
    }

    // Exibindo o Tabuleiro

    printf("=== TABULEIRO BATALHA NAVAL === \n");

    for(int i = 0; i < 10; i++){

        for(int j = 0; j < 10; j++){

            printf("%d ", tabuleiro[i][j]);

        }

        printf("\n");

    }
    

    return 0;
}
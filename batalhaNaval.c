#include <stdio.h>
#include <stdbool.h>

// Tabuleiro 

#define LINHAS 10
#define COLUNAS 10

// Navio

#define NAVIO 3
#define AGUA 0
#define EFEITO 5

// Tamanho da Habilidade
#define HABILIDADE 5

// Protótipos das Funções

void exibirTabuleiro(int tabuleiro[LINHAS][COLUNAS]);

void aplicarHabilidade(int tabuleiro[LINHAS][COLUNAS],
                       int habilidade[HABILIDADE][HABILIDADE],
                       int linha, int coluna);

int main (){

    // Tamanho do Tabuleiro
    int tabuleiro[LINHAS][COLUNAS];
    

    // Tabuleiro inicializado com Água
    for (int i = 0; i < LINHAS; i ++){

        for(int j = 0; j < COLUNAS; j++){
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posicionamento dos Navios

    // Navio 1 (Horizontal)
    int navio1_Linha_Inicial = 2;
    int navio1_Coluna_Inicial = 2;

    // Posicionamento do Navio 1. (Horizontal)

    // Verifica se o navio não sai dos limites do Tabuleiro.
    if(navio1_Coluna_Inicial + NAVIO <= COLUNAS){
        for (int i = 0; i < 3; i++){
            
            // Posiciona o navio na horizontal a partir da linha e coluna inicial.
            tabuleiro[navio1_Linha_Inicial][navio1_Coluna_Inicial + i] = NAVIO;
        }

    } else {
        printf("Erro: o navio 1 sai dos limites do Tabuleiro! \n");
        return 1;
        
    }

    // Navio 2 (Vertical)
    int navio2_Linha_Inicial = 5;
    int navio2_Coluna_Inicial = 5;

     // Posicionamento do Navio 2. (Vertical)

    //Verifica se alguma posição está ocupada.
    for(int i = 0; i < NAVIO; i++){

        if(tabuleiro[navio2_Linha_Inicial + i][navio2_Coluna_Inicial] == NAVIO){
            printf("Erro navio 2: Um navio já está ocupando esta posição. \n");
            return 1;
        }
    }
    //Verifica se o navio não sai dos limites do Tabuleiro.
    if(navio2_Linha_Inicial + NAVIO <= LINHAS){
        for(int i = 0; i < NAVIO; i ++){

        // Posiciona o navio na vertical a partir da linha e coluna inicial.
        tabuleiro[navio2_Linha_Inicial + i][navio2_Coluna_Inicial] = NAVIO;
    }  
    } else{
        printf("Erro: o navio 2 sai dos limites do Tabuleiro! \n");
        return 1;
    }


    // Navio 3 (Diagonal 1)
    int navio3_Linha_Inicial = 7;
    int navio3_Coluna_Inicial = 7;

    //Posicionamento Navio 3. (Diagonal 1)


    //Verifica se alguma posição está ocupada.
    for(int i = 0; i < NAVIO; i++){

        if(tabuleiro[navio3_Linha_Inicial + i][navio3_Coluna_Inicial + i] == NAVIO){
            printf("Erro navio 3: Um navio já está ocupando esta posição. \n");
            return 1;
        }
    }

    //Verifica se o navio não sai dos limites do Tabuleiro.
    if(navio3_Linha_Inicial + NAVIO <= LINHAS && navio3_Coluna_Inicial + NAVIO <= COLUNAS){
        for(int i = 0; i < NAVIO; i ++){

        // Posiciona o navio na vertical a partir da linha e coluna inicial.
        tabuleiro[navio3_Linha_Inicial + i][navio3_Coluna_Inicial + i] = NAVIO;
    }
    } else{
        printf("Erro: o navio 3 sai dos limites do Tabuleiro! \n");
        return 1;
    }

    // Navio 4 (Diagonal 2)

    int navio4_Linha_Inicial = 7;
    int navio4_Coluna_Inicial = 2;

    //Verifica se alguma posição está ocupada.
    for(int i = 0; i < NAVIO; i++){

        if(tabuleiro[navio4_Linha_Inicial - i][navio4_Coluna_Inicial - i] == NAVIO){
            printf("Erro navio 4: Um navio já está ocupando esta posição. \n");
            return 1;
        }
    }

    //Verifica se o navio não sai dos limites do Tabuleiro.
    if(navio4_Linha_Inicial - NAVIO <= LINHAS && navio4_Coluna_Inicial - NAVIO <= COLUNAS){

        for(int i = 0; i < NAVIO; i ++){

        // Posiciona o navio na vertical a partir da linha e coluna inicial.
        tabuleiro[navio4_Linha_Inicial - i][navio4_Coluna_Inicial - i] = NAVIO;
    }
        
    } else{
        printf("Erro: o navio 4 sai dos limites do Tabuleiro! \n");
        return 1;
    }
    

    // Habilidades
    int habilidadeCone[HABILIDADE][HABILIDADE];
    int habilidadeCruz[HABILIDADE][HABILIDADE];
    int habilidadeOctaedro[HABILIDADE][HABILIDADE];
    int centro = HABILIDADE / 2;

    // Matriz Habilidade Cone
    for(int i = 0; i < HABILIDADE; i++){

        for(int j = 0; j < HABILIDADE; j++){

            if(j >= centro - i && j <= centro + i && i <= centro){
                habilidadeCone[i][j] = 1;
            } else {
                habilidadeCone[i][j] = AGUA;
            }

        }

    }

    // Matriz Habilidade Cruz
    for(int i = 0; i < HABILIDADE; i++){

        for(int j = 0; j < HABILIDADE; j++){

            if(i == centro || j == centro){
                habilidadeCruz[i][j] = 1;
            } else {
                habilidadeCruz[i][j] = AGUA;
            }

        }

    }

    // Matriz Habilidade Octaedro
    for (int i = 0; i < HABILIDADE; i++)
    {
        for(int j = 0; j < HABILIDADE; j++){
            int distLinha = i > centro ? i - centro : centro - i;
            int distColuna = j > centro ? j - centro : centro - j;

            if(distLinha + distColuna <= centro){
                habilidadeOctaedro[i][j] = 1;
            } else {
                habilidadeOctaedro[i][j] = AGUA;
            }
        }
    }
    

    // Posições das Habilidades
    int coneLinha = 1;
    int coneColuna = 4;
    int cruzLinha = 7;
    int cruzColuna = 2;
    int octaedroLinha = 4;
    int octaedroColuna = 4;

    aplicarHabilidade(tabuleiro, habilidadeCone, coneLinha, coneColuna);
    aplicarHabilidade(tabuleiro, habilidadeCruz, cruzLinha, cruzColuna);
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, octaedroLinha, octaedroColuna);

    // Tabuleiro Final
    printf("=== TABULEIRO BATALHA NAVAL ===\n");
    printf("Legenda: %d = Agua, %d = Navio, %d = Efeito de Habilidade\n\n", AGUA, NAVIO, EFEITO);
    exibirTabuleiro(tabuleiro);

    
    return 0;
}

// Exibir o estado atual do Tabuleiro

void exibirTabuleiro(int tabuleiro[LINHAS][COLUNAS]){

    printf("=== TABULEIRO BATALHA NAVAL ===\n");

    for(int i = 0; i < LINHAS; i++){

        for(int j = 0; j < COLUNAS; j++){

            printf("%d ", tabuleiro[i][j]);

        }

        printf("\n");

    }
}

// Aplicar Habilidade
void aplicarHabilidade(int tabuleiro[LINHAS][COLUNAS],
                       int habilidade[HABILIDADE][HABILIDADE],
                       int linha, int coluna) {
    int centroHabilidade = HABILIDADE / 2;

    for (int i = 0; i < HABILIDADE; i++) {
        for (int j = 0; j < HABILIDADE; j++) {
            
            if (habilidade[i][j] == 1) {
                int alvoLinha = linha - centroHabilidade + i;
                int alvoColuna = coluna - centroHabilidade + j;

                if (alvoLinha >= 0 && alvoLinha < LINHAS && alvoColuna >= 0 && alvoColuna < COLUNAS) {
                    
                    tabuleiro[alvoLinha][alvoColuna] = EFEITO;
                }
            }
        }
    }
}
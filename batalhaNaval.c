#include <stdio.h>
#include <stdlib.h>
//define tamanho do tabuleiro
#define Tamanho_T 10 
//define tamanho do navio
#define Tamanho_N 3 
// define quantas linhas tem na demosntração da habilidade
#define linha 3 
// define quantas colunas tem na demonstração da habilidade
#define coluna 5 

//para exibir o tabuleriro apenas com os navios
void exibirTabuleiro(int tabuleiro[Tamanho_T][Tamanho_T]){
    printf("\nTabuleiro com os navios: \n\n");
    for (int i = 0; i < Tamanho_T; i++)
    {
        for (int j = 0; j < Tamanho_T; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

//para exibir o tabuleiro com os navios e as habilidades
void exibirTabuleiroF (int tabuleiro[Tamanho_T] [Tamanho_T]){
    printf("\nTabuleiro Final: \n\n");
    for (int i = 0; i < Tamanho_T; i++)
    {
        for (int j = 0; j < Tamanho_T; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
}

//para exibir as demonstrações das habilidades
void exibirHabilidade (char* nome, int habilidade[linha][coluna]){
    printf("\nMatriz da Habilidade: %s\n\n", nome);
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            printf("%d ", habilidade[i][j]);
        }
        printf("\n");
    }
}

//verificar e posicionar os navios no tabuleiro
void posicionarNavio(int tabuleiro[Tamanho_T][Tamanho_T], int lin, int col, int dx, int dy){
    for (int i = 0; i < Tamanho_N; i++)
    {
        int l = lin + i * dx;
        int c = col + i * dy;
        if (l >= 0 && l < Tamanho_T && c >= 0 && c < Tamanho_T)
        {
            tabuleiro[l][c] = 3;
        }
        
    }
    
}

//para fazer a habilidade de cone
void criarCone(int habilidade[linha][coluna]){
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            habilidade[i][j] = (j >= 2 -i && j <= 2 + i) ? 1 : 0;
        }
        
    }
}

//para fazer a habilidade de cruz
void criarCruz (int habilidade[linha][coluna]){
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            habilidade[i][j] = (i == linha/2 || j == coluna/ 2) ? 1: 0;  
        }
    }
}

//para fazer a habilidade de octaedro
void criarOctaedro(int habilidade[linha][coluna]){
    int centro_L = linha / 2;
    int centro_C = coluna / 2;

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            habilidade[i][j] = (abs(i - centro_L) + abs(j - centro_C) <= 1) ? 1 : 0;
        }
    }
}

//para colocar e veificar a habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[Tamanho_T][Tamanho_T], int habilidade[linha][coluna], int origem_L, int origem_C){
    int lin_O = linha / 2;
    int col_O = coluna / 2;

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            int l = origem_L - lin_O + i;
            int c = origem_C - col_O + j;

            if (l >= 0 && l < Tamanho_T && c >= 0 && c < Tamanho_T)
            {
                if (habilidade[i][j] == 1)
                {
                    tabuleiro[l][c] = 1;
                }
                
            }
            
        }
        
    }
    
}

int main(){
    int tabuleiro[Tamanho_T][Tamanho_T] = {0}; //incia o tabuleiro com valor de zero em todo ele
// posicionando os navios
   posicionarNavio(tabuleiro, 2, 4, 0, 1); 
   posicionarNavio(tabuleiro, 5, 1, 1, 0);
   posicionarNavio(tabuleiro, 6, 6, 1, 1);
   posicionarNavio(tabuleiro, 0, 4, 1, -1);
//exibindo apenas os navios no tabuleiro
   exibirTabuleiro(tabuleiro);
//varives para conter a habilidades
    int cone[linha][coluna];
    int cruz[linha][coluna];
    int octaedro[linha][coluna];
//criando cada habilidade
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);
//exibindo cada habilidade
    exibirHabilidade("Cone", cone);
    exibirHabilidade("cruz", cruz);
    exibirHabilidade("Octaedro", octaedro);
//colocando ela no tabuleiro final
    aplicarHabilidade(tabuleiro, cone, 2, 6);
    aplicarHabilidade(tabuleiro, cruz, 6, 6);
    aplicarHabilidade(tabuleiro, octaedro, 5, 2);
//exibindo o tabuleiro com as habilidades e os navios 
    exibirTabuleiroF(tabuleiro);

    return 0;
}

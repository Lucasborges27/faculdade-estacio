#include <stdio.h>

int main() {
//USANDO LINHAS DO CODIGO DO XADREZ MONTEI ESSE CODIGO DO BATALHA NAVAL COMO DECLARAR O TABULEIRO E ETC.
char tabuleiro[10][10]; // FALA QUE MEU TABULEIRO VAI SER 10X10
int i, j; // VARIAVEIS PARA A LINHA E COLUNA
int linha_navio_horizontal = 2; // LINHA DO NAVIO HORIZONTAL 
int coluna_navio_horizontal = 3; // COLUNA DO NAVIO HORIZONTAL 
int linha_navio_vertical = 5; // LINHA DO NAVIO VERTICAL
int coluna_navio_vertical = 7; // COLUNA DO NAVIO VERTICAL
    // Inicializa o tabuleiro com '.'
    for (i = 0; i < 10; i++) { 
    for (j = 0; j < 10; j++) {
    tabuleiro[i][j] = '.';  // Preenche todo o tabuleiro com '.' USEI PONTOS POIS FICA MELHOR VISUALMENTE
        }
    }
    // Posiciona navio horizontal
    for (i = 0; i < 3; i++) {
    tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] = 'N'; 
    } 
    // Posiciona navio vertical
    for (i = 0; i < 3; i++) {
    tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = 'N'; 
    } 
    // Imprime o tabuleiro
        printf("   ");
    for (j = 0; j < 10; j++) {
        printf("%d ", j); // IMPRIME O NOME DAS COLUNAS
    }
        printf("\n"); // IMPRIME O NOME DAS COLUNAS

    for (i = 0; i < 10; i++) {
        printf("%2d ", i); // IMPRIME O NOME DAS LINHAS
    for (j = 0; j < 10; j++) {
        printf("%c ", tabuleiro[i][j]); // IMPRIME O TABULEIRO
        }
        printf("\n"); // IMPRIME O NOME DAS LINHAS
    }
    return 0;
}

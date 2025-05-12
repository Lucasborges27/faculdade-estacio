#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void moverTorre(char tabuleiro[8][8], int posX, int posY); 
void moverBispo(char tabuleiro[8][8], int posX, int posY, int newX, int newY, int passos);
void moverRainha(char tabuleiro[8][8], int posX, int posY, int newY);
void imprimirTabuleiro(char tabuleiro[8][8]);
int main() {
char tabuleiro[8][8];
char peca;
char linha1[] = {'T', '.', 'B', 'Q', '.', '.', '.', '.'};
int i, j;
int posX = 7, posY = -1;
    
    // Inicializando o tabuleiro
    for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
        tabuleiro[i][j] = '.';  // Preenche todo o tabuleiro com pontos (casas)
        }
    }

    // Colocando as peças na última linha (linha 7)
    for (j = 0; j < 8; j++) {
        tabuleiro[7][j] = linha1[j];
    }

    // Colocando o Cavalo na posição inicial (7,1) manualmente
        tabuleiro[7][1] = 'C';

    // O tabuleiro definitivamente montado e impresso com as peças na posição inicial
            printf("Bem-vindo ao xadrez de bruxo!!!\n\n");

    do {
            printf("Tabuleiro:\n");
            imprimirTabuleiro(tabuleiro);

        // SELECIONE QUAL PEÇA QUER MOVER
            printf("Pressione cada tecla em sequência para ver o movimento da peça (T, C, B, Q): \n");
            printf("Ou pressione S para sair do jogo.\n");
            scanf(" %c", &peca);

    switch (peca) {
case 'T': {
            system("clear");
            printf("Você escolheu a Torre (Cinco casas para a Direita).\n");
        posX = 7; //LOCALIZAÇÃO DA TORRE NA LINHA 7
        posY = -1; // LOCALIZAÇÃO DA POSIÇÃO -1
    for (j = 0; j < 8; j++) { //PROCURA A POSIÇÃO DA TORRE NA LINHA 7 DO TABULEIRO
    if (tabuleiro[posX][j] == 'T') {
        posY = j;
    break;
        }
    }
    if (posY != -1 && posY + 5 < 8) { // Verifica se a torre está na linha 7 e se o movimento é válido
            moverTorre(tabuleiro, posX, posY); // Chama a função para mover a torre
    } else { 
            printf("Torre não encontrada ou movimento inválido.\n");
    }
}
    break;
    case 'B': {
            system("clear");
            printf("Você escolheu o Bispo (5 casas na diagonal direita).\n");
    for (j = 0; j < 8; j++) { // PROCURA A POSIÇÃO DO BISPO NA LINHA 7 DO TABULEIRO
    if (tabuleiro[7][j] == 'B') {
        posY = j; // LOCALIZAÇÃO DO BISPO NA LINHA 7
    break;
                }
            }
    if (posY != -1) { // Verifica se o bispo está na linha 7
                // Remove o bispo da posição original
                // Movimento recursivo do bispo
            moverBispo(tabuleiro, 7, posY, 7, posY, 0); // Chama a função para mover o bispo
  } else {
            printf("Bispo não encontrado.\n");
            }
        }
    break;
    case 'Q': {  
            system("clear");
            printf("Você escolheu a Rainha (8 casas para a esquerda).\n");
        
    for (j = 0; j < 8; j++) { // PROCURA A POSIÇÃO DA RAINHA NA LINHA 7 DO TABULEIRO
    if (tabuleiro[7][j] == 'Q') {  
        posY = j; // LOCALIZAÇÃO DA RAINHA NA LINHA 7
    break;
                }
            }
    if (posY != -1) { // Verifica se a rainha está na linha 7
                // Remove a rainha da posição original
                // Atualiza a posição da rainha
                // Movimento recursivo da rainha para a esquerda
            moverRainha(tabuleiro, 7, posY, posY - 8);
  } else {
            printf("Rainha não encontrada.\n");
            }
        }
    break;
    case 'C': {
            system("clear");
            printf("Você escolheu o Cavalo (2 casas para cima e 1 para a direita).\n");

            // Atualizando a posição inicial do cavalo para (7, 1)
        posX = 7; // Cavalo começa na linha 7
        posY = 1; // Cavalo começa na coluna 1

            // Movimento do cavalo
int newX = posX - 2; // 2 casas para cima
int newY = posY + 1; // 1 casa para a direita
            // Verifica se a nova posição está dentro dos limites do tabuleiro
    if (newX >= 0 && newY < 8) {
        tabuleiro[posX][posY] = '.';  // Remove da posição inicial
        tabuleiro[newX][newY] = 'C';  // Coloca na nova posição
            system("clear");
            printf("Movimento realizado: Cavalo movido para (%d, %d)\n", newX, newY);
  } else {
            printf("Movimento inválido: fora dos limites do tabuleiro.\n");
            }
        }
    break;
    case 'S':
            system("clear");
            printf("Saindo do jogo...\n");
    break;

    default:
            system("clear");
            printf("Peça inválida. Escolha entre T, C, B ou Q.\n");
        } // FECHA O SWITCH
   }while (peca != 'S'); 
    return 0;
    // FIM DO JOGO
}
// FUNÇÕES
//OQUE CADA FUNÇÃO FAZ
// imprime o tabuleiro de xadrez na tela
void imprimirTabuleiro(char tabuleiro[8][8]) { 
    for (int i = 0; i < 8; i++) { 
    for (int j = 0; j < 8; j++) { 
            printf("%c ", tabuleiro[i][j]);
        }
            printf("\n");
    }
}
void moverTorre(char tabuleiro[8][8], int posX, int posY) { 
int novaY = posY + 5; // Nova posição da torre (5 casas para a direita)
    if (novaY < 8) { 
        tabuleiro[posX][posY] = '.'; // Remove a torre da posição original
        tabuleiro[posX][novaY] = 'T';// Coloca a torre na posição final
    }
            printf("Movimento da Torre (5 casas para a direita) .\n");
}
void moverBispo(char tabuleiro[8][8], int posX, int posY, int newX, int newY, int passos) { 
    if (passos < 6) {  // Vai andar exatamente até o passo 5 (chega em 2,7 no passo 6)
            printf("Movendo Bispo para (%d, %d)\n", newX, newY); // Imprime a nova posição do bispo
        // Realiza o movimento
        tabuleiro[posX][posY] = '.'; // Remove da posição inicial
        tabuleiro[newX][newY] = 'B'; // Coloca na nova posição
int proxX = newX - 1; // Próxima posição na diagonal
int proxY = newY + 1; // Próxima posição na diagonal

            moverBispo(tabuleiro, newX, newY, proxX, proxY, passos + 1); // Chama recursivamente para o próximo movimento
    }else {
            printf("Movimento do Bispo finalizado.\n");
    }
}
void moverRainha(char tabuleiro[8][8], int posX, int posY, int newY) {
    if (newY >= 0 && newY < 8) {
            printf("Movendo Rainha para (%d, %d)\n", posX, newY);   // Imprime a nova posição da rainha
        // Realiza o movimento
        tabuleiro[posX][posY] = '.';  // Remove da posição inicial
        tabuleiro[posX][newY] = 'Q';  // Coloca na nova posição
            moverRainha(tabuleiro, posX, newY, newY - 1);  // Chama recursivamente para o próximo movimento
    } else {
            printf("Movimento da Rainha finalizado.\n");
    }
}

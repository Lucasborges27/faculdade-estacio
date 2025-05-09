#include <stdio.h>
#include <stdlib.h>
int main(){
char tabuleiro[8][8];
char peca;
char linha1[] = {'T', '.', 'B', 'Q', '.', '.', '.', '.'};
int i, j; 
int posX = 7, posY = -1;
int newX = posX;
int newY = posY;
int passos = 0;
    // Inicializando o tabuleiro
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            tabuleiro[i][j] = '.';  // Preenche todo o tabuleiro com pontos QUE SERIA AS CASAS
        }
    }
    // Colocando as peças na última linha (linha 7)
    for (j = 0; j < 8; j++) {
        tabuleiro[7][j] = linha1[j];
    }
    // Colocando o Cavalo na posição inicial (0,1) MANUALMENTE
    tabuleiro[0][1] = 'C';
//O TABULEIRO DEFINITIVAMENTE MONTADO E IMPRESSO COM AS PEÇAS NA POSIÇÃO INICIAL
           printf("Bem-vindo ao xadrez de bruxo!!!");
           printf("\n\n");
          
    do{ 
        printf("Tabuleiro:\n");
    for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
           printf("%c ", tabuleiro[i][j]);
        }
           printf("\n");
    }
//SELECIONE QUAL PEÇA QUER MOVER 
        printf("Pressione cada tecla em sequencia para ver o movimento da peça (T, C, B, Q): \n");
        printf("Ou pressione S para sair do jogo.\n");
        scanf(" %c", &peca);
    switch (peca){
case 'T':{ //USO DO FOR
        system("clear");
        printf("Você escolheu a Torre (Cinco casas para a Direita).\n");
    for (j = 0; j < 8; j++) {
    if (tabuleiro[posX][j] == peca) { //VERIFICA SE A PEÇA TA NA POSIÇÃO INDICADA E SE SIM EXECUTA O MOVIMENTO INDICADO
        posY = j; //SALVEI A POSIÇÃO DA PEÇA
    break;
           }
    }
    if (posY == -1) { 
        printf("Torre não encontrada no tabuleiro.\n");
  } else if (peca == 'T') {
// Movimento da torre cinco casas para a direita
        newY = posY + 5;
    if (newY < 8) {
        tabuleiro[posX][posY] = '.';  // Remove a peça da posição inicial
        tabuleiro[posX][newY] = 'T'; // Coloca a peça na nova posição
        system("clear");
        printf("Movimento realizado: Torre movida 5 Casas para a direita  (%d, %d).\n", posX, newY);
  } else {
        printf("Movimento inválido: fora dos limites do tabuleiro.\n");
    }
           }
}//FECHA O CASE T
    break;
case 'B': {
    if (peca == 'B') { //USO OBRIGATORIO DO...WHILE
       system("clear");
       printf("Você escolheu o Bispo (5 casas na diagonal direita).\n");
    posY = -1;
    for (j = 0; j < 8; j++) {
    if (tabuleiro[7][j] == 'B') {
        posY = j;
    break;
        }
    }
    if (posY == -1) {
        printf("Bispo não encontrado.\n");
  } else {
        newX = 7;
        newY = posY;
        passos = 0;
    do {
        newX--; // Sobe
        newY++; // Vai pra direita
        passos++;

    if (newX >= 0 && newY < 8) {
                printf("Movimento %d: Cima, Direita (%d, %d)\n", passos, newX, newY);
    } else {
                printf("Movimento interrompido: limite do tabuleiro alcançado.\n");
    break;
    }
} while (passos < 5);

    if (newX >= 0 && newY < 8) {
        tabuleiro[7][posY] = '.';       // Remove da posição antiga
        tabuleiro[newX][newY] = 'B';       // Coloca na nova posição
                printf("Bispo movido para (%d, %d).\n", newX, newY);
        }
    }
}
}
    break;
case 'Q': { //USO DO IF PORQUE DE QUALQUER JEITO NÃO IA ANDAR PRA LUGAR NENHUM 
    if (peca == 'Q') {
        system("clear");
        printf("Você escolheu a Rainha (8 casas para a esquerda sai do numero de casa do tabuleiro).\n");
//Rainha oito casas para a esquerda. (Erro inesperado)
        newX = posX;
        newY = posY - 8; // RAINHA VAI 8 CASAS PRA ESQUERDA
    if (newY >= 0) {
        tabuleiro[posX][posY] = '.'; // Remove a peça da posição inicial
        tabuleiro[newX][newY] = 'Q'; // Coloca a peça na nova posição
        printf("Movimento realizado: Rainha movida 8 casas para a esquerda (%d, %d).\n", newX, newY);
  } else {
        printf("MOVIMENTO NÃO PERMITIDO: fora dos limites do tabuleiro\n");
    }
}
break;
}//FECHA O CASE Q
    
break;
case 'C':{ // USO DO FOR E WHILE 
    system("clear");
    printf("Você escolheu o Cavalo (2 Casas para baixo e 1 para a esquerda).\n");

    posX = 0;     // Cavalo começa na linha 0
    posY = 1;
    // FOR OBRIGATORIO PARA ACHAR O CAVALO NA 0,1
    for (j = 0; j < 8; j++) {
        if (tabuleiro[posX][j] == 'C') {
    posY = j;
            // WHILE aninhado
    int passos = 0;
    newX = posX;
    newY = posY;
            while (passos < 1) { // só um movimento do cavalo
    newX += 2;       // 2 pra baixo
    newY -= 1;       // 1 pra esquerda
    passos++;
            }
            break; 
        }
    }
    if (posY == -1) {
        printf("Cavalo não encontrado na linha 0.\n");
    } else if (newX < 8 && newY >= 0) {
    tabuleiro[posX][posY] = '.';      // remove da posição antiga
    tabuleiro[newX][newY] = 'C';      // coloca na nova
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

    
 }//FECHA O SWITCH
}while (peca != 'S');
    return 0;
    //FIM DO JOGO
}


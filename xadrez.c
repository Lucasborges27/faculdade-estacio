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
    //TABULEIRO BASEADO NA IDEIA DE UMA MATRIZ 8X8
    for (j = 0; j < 8; j++) {
        tabuleiro[7][j] = linha1[j];
    }
    // PREENCHER OS ESPAÇOS SEM USO COM UM PONTINHO
    for (i = 0; i < 7; i++) {
    for (j = 0; j < 8; j++) {
            tabuleiro[i][j] = '.';
        }
    }

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
        printf("Selecione a peça que deseja mover (T, B, Q): \n");
        scanf(" %c", &peca);
    switch (peca){
case 'T':{
        system("clear");
        printf("Você escolheu a Torre.\n");
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
    if (peca == 'B') {
       system("clear");
       printf("Você escolheu o Bispo.\n");
    posY = -1;
    for (j = 0; j < 8; j++) {
    if (tabuleiro[posX][j] == 'B') {
        posY = j;
    break;
        }
    }

    if (posY == -1) {
        printf("Bispo não encontrado.\n");
  } else {
        newX = posX;
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
        tabuleiro[posX][posY] = '.';       // Remove da posição antiga
        tabuleiro[newX][newY] = 'B';       // Coloca na nova posição
                printf("Bispo movido para (%d, %d).\n", newX, newY);
        }
    }
}
}
    break;
case 'Q': {
    if (peca == 'Q') {
        system("clear");
        printf("Você escolheu a Rainha.\n");
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
}//FECHA O CASE Q
    break;
    case 'S':
        printf("Saindo do jogo...\n");
    break;
default:
        printf("Peça inválida. Escolha entre T, B ou Q.\n");
    break;
    
 }//FECHA O SWITCH
//IMPRIME O TABULEIRO NOVAMENTE
    printf("Tabuleiro atualizado:\n");
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}while (peca != 'S');
    printf("Saindo do jogo...\n");
    return 0;
    //FIM DO JOGO
}


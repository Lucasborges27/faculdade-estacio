#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Constantes Globais -- 
#define MAX_TROPAS 5
#define MAX_STRING 100
//Criar uma struct chamada Territorio que armazenará informações como nome, cor do exército e quantidade de tropas. O sistema permitirá o cadastro de 5 territórios e exibirá seus dados logo após o preenchimento.

// --- DEFINIÇÃO DA ESTRUTURA (STRUCT) ---
struct territorio {
    char nome[MAX_STRING];
    char cor[MAX_STRING];
    char quantidade[MAX_STRING];
    int tropas;
};

// --- função para limpar o buffer de entrada ---
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- função principal (main) --- 
int main() {
    struct territorio territorios[MAX_TROPAS];
    int i;

    // --- Loop para cadastro dos territórios ---
    for (i = 0; i < MAX_TROPAS; i++) {
        printf("Cadastro do território %d:\n", i + 1);
        
        printf("Nome: ");
        fgets(territorios[i].nome, MAX_STRING, stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = 0; // Remove newline

        printf("Cor do exército: ");
        fgets(territorios[i].cor, MAX_STRING, stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = 0; // Remove newline

        printf("Quantidade de tropas: ");
        fgets(territorios[i].quantidade, MAX_STRING, stdin);
        territorios[i].quantidade[strcspn(territorios[i].quantidade, "\n")] = 0; // Remove newline

        territorios[i].tropas = atoi(territorios[i].quantidade); // Converte string para inteiro
    }
system("clear"); // Limpa a tela para melhor visualização
    // --- Exibição dos dados cadastrados ---
    printf("\nTerritórios cadastrados:\n");
    for (i = 0; i < MAX_TROPAS; i++) {
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exército: %s\n", territorios[i].cor);
        printf("Quantidade de tropas: %s (%d)\n", territorios[i].quantidade, territorios[i].tropas);
    }

    return 0;
}

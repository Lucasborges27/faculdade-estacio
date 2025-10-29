



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100
#define HASH_TAM 10

typedef struct Sala {
    char nome[TAM];
    char pista[TAM];
    struct Sala *esq;
    struct Sala *dir;
} Sala;

typedef struct NoPista {
    char pista[TAM];
    struct NoPista *esq;
    struct NoPista *dir;
} NoPista;

typedef struct Hash {
    char pista[TAM];
    char suspeito[TAM];
    struct Hash *prox;
} Hash;

Sala* criaSala(const char *nome, const char *pista) {
    Sala *nova = (Sala*)malloc(sizeof(Sala));
    strcpy(nova->nome, nome);
    strcpy(nova->pista, pista);
    nova->esq = nova->dir = NULL;
    return nova;
}

NoPista* inserirPistaBST(NoPista *raiz, const char *pista) {
    if (!pista || strlen(pista) == 0) return raiz;
    if (!raiz) {
        NoPista *novo = (NoPista*)malloc(sizeof(NoPista));
        strcpy(novo->pista, pista);
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (strcmp(pista, raiz->pista) < 0)
        raiz->esq = inserirPistaBST(raiz->esq, pista);
    else if (strcmp(pista, raiz->pista) > 0)
        raiz->dir = inserirPistaBST(raiz->dir, pista);
    return raiz;
}

int funcaoHash(const char *chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++)
        soma += chave[i];
    return soma % HASH_TAM;
}

void inserirHash(Hash *tabela[], const char *pista, const char *suspeito) {
    int pos = funcaoHash(pista);
    Hash *novo = (Hash*)malloc(sizeof(Hash));
    strcpy(novo->pista, pista);
    strcpy(novo->suspeito, suspeito);
    novo->prox = tabela[pos];
    tabela[pos] = novo;
}

const char* buscarSuspeito(Hash *tabela[], const char *pista) {
    int pos = funcaoHash(pista);
    for (Hash *aux = tabela[pos]; aux; aux = aux->prox)
        if (strcmp(aux->pista, pista) == 0)
            return aux->suspeito;
    return NULL;
}

Sala* montarMansao() {
    Sala *hall = criaSala("Hall de Entrada", "Pegadas de lama");
    hall->esq = criaSala("Biblioteca", "Livro rasgado com anotações");
    hall->dir = criaSala("Sala de Jantar", "Taça de vinho com batom");
    hall->esq->esq = criaSala("Escritório", "Envelope com dinheiro");
    hall->esq->dir = criaSala("Sala de Música", "Partitura manchada de sangue");
    hall->dir->esq = criaSala("Cozinha", "Faca suja");
    hall->dir->dir = criaSala("Jardim", "Luvas enterradas");
    hall->dir->esq->esq = criaSala("Despensa", "Frasco de veneno vazio");
    return hall;
}

void montarTabelaHash(Hash *tabela[]) {
    for (int i = 0; i < HASH_TAM; i++) tabela[i] = NULL;
    inserirHash(tabela, "Pegadas de lama", "Sr. Green");
    inserirHash(tabela, "Livro rasgado com anotações", "Sra. White");
    inserirHash(tabela, "Taça de vinho com batom", "Sra. Scarlet");
    inserirHash(tabela, "Envelope com dinheiro", "Coronel Mustard");
    inserirHash(tabela, "Partitura manchada de sangue", "Sra. Scarlet");
    inserirHash(tabela, "Faca suja", "Coronel Mustard");
    inserirHash(tabela, "Luvas enterradas", "Sr. Green");
    inserirHash(tabela, "Frasco de veneno vazio", "Sra. White");
}

void explorarMansao(Sala *atual, NoPista **arvorePistas, Hash *tabela[]) {
    if (!atual) return;
    printf("\nVocê está em: %s\n", atual->nome);
    if (strlen(atual->pista) > 0) {
        printf("Você encontrou uma pista: \"%s\"\n", atual->pista);
        *arvorePistas = inserirPistaBST(*arvorePistas, atual->pista);
        const char *sus = buscarSuspeito(tabela, atual->pista);
        if (sus) printf("Essa pista parece estar ligada a %s...\n", sus);
    } else printf("Nenhuma pista aqui.\n");

    char escolha;
    printf("Escolha o caminho (E-esquerda, D-direita, S-sair): ");
    scanf(" %c", &escolha);

    if (escolha == 'E' || escolha == 'e')
        explorarMansao(atual->esq, arvorePistas, tabela);
    else if (escolha == 'D' || escolha == 'd')
        explorarMansao(atual->dir, arvorePistas, tabela);
    else if (escolha == 'S' || escolha == 's')
        printf("\nExploração encerrada.\n");
    else {
        printf("Opção inválida! Tente novamente.\n");
        explorarMansao(atual, arvorePistas, tabela);
    }
}

void exibirPistas(NoPista *raiz) {
    if (!raiz) return;
    exibirPistas(raiz->esq);
    printf("- %s\n", raiz->pista);
    exibirPistas(raiz->dir);
}

int contarPistasSuspeito(NoPista *raiz, Hash *tabela[], const char *suspeito) {
    if (!raiz) return 0;
    int count = 0;
    const char *sus = buscarSuspeito(tabela, raiz->pista);
    if (sus && strcmp(sus, suspeito) == 0) count++;
    return count + contarPistasSuspeito(raiz->esq, tabela, suspeito)
                 + contarPistasSuspeito(raiz->dir, tabela, suspeito);
}

void liberarSalas(Sala *sala) {
    if (!sala) return;
    liberarSalas(sala->esq);
    liberarSalas(sala->dir);
    free(sala);
}

void liberarPistas(NoPista *raiz) {
    if (!raiz) return;
    liberarPistas(raiz->esq);
    liberarPistas(raiz->dir);
    free(raiz);
}

void liberarHash(Hash *tabela[]) {
    for (int i = 0; i < HASH_TAM; i++) {
        Hash *aux = tabela[i];
        while (aux) {
            Hash *temp = aux;
            aux = aux->prox;
            free(temp);
        }
    }
}

int main() {
    Sala *mansao = montarMansao();
    NoPista *pistas = NULL;
    Hash *tabela[HASH_TAM];
    montarTabelaHash(tabela);

    printf("=== Detective Quest: A Verdade na Mansão ===\n");
    explorarMansao(mansao, &pistas, tabela);

    printf("\n=== Pistas Coletadas ===\n");
    if (!pistas) printf("Nenhuma pista foi coletada.\n");
    else exibirPistas(pistas);

    char suspeito[TAM];
    printf("\nQuem você acha que é o culpado? ");
    scanf(" %[^\n]", susp    int qtd = contarPistasSuspeito(pistas, tabela, suspeito);

    printf("\n=== Resultado da Investigação ===\n");
    if (qtd >= 2)
        printf("Você acertou! %s foi o culpado, com %d pistas incriminatórias.\n", suspeito, qtd);
    else if (qtd == 1)
        printf("%s parece suspeito, mas há apenas uma pista — insuficiente para condenar.\n", suspeito);
    else
        printf("Nenhuma pista aponta para %s. Acusação incorreta.\n", suspeito);

    liberarSalas(mansao);
    liberarPistas(pistas);
    liberarHash(tabela);
    return 0;
}








                                                                             [ Wrote 201 lines ]
^G Help          ^O Write Out     ^W Where Is      ^K Cut           ^T Execute       ^C Location      M-U Undo         M-A Set Mark     M-] To Bracket   M-Q Previous
^X Exit          ^R Read File     ^\ Replace       ^U Paste         ^J Justify       ^/ Go To Line    M-E Redo         M-6 Copy         ^Q Where Was     M-W Next

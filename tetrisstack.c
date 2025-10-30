#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILA 5
#define MAX_PILHA 3

typedef struct {
    char tipo; // 'I', 'O', 'T', 'L'
    int id;    // identificador único
} Peca;

// --- FILA CIRCULAR ---
typedef struct {
    Peca fila[MAX_FILA];
    int frente;
    int tras;
    int tamanho;
} Fila;

void inicializarFila(Fila *f) {
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
}

int estaCheiaFila(Fila *f) {
    return f->tamanho == MAX_FILA;
}

int estaVaziaFila(Fila *f) {
    return f->tamanho == 0;
}

void enqueue(Fila *f, Peca p) {
    if (estaCheiaFila(f)) return;
    f->tras = (f->tras + 1) % MAX_FILA;
    f->fila[f->tras] = p;
    f->tamanho++;
}

Peca dequeue(Fila *f) {
    Peca p = {'X', -1};
    if (estaVaziaFila(f)) return p;
    p = f->fila[f->frente];
    f->frente = (f->frente + 1) % MAX_FILA;
    f->tamanho--;
    return p;
}

void exibirFila(Fila *f) {
    printf("Fila de peças:\t");
    if (estaVaziaFila(f)) {
        printf("(vazia)\n");
        return;
    }
    for (int i = 0; i < f->tamanho; i++) {
        int idx = (f->frente + i) % MAX_FILA;
        printf("[%c %d] ", f->fila[idx].tipo, f->fila[idx].id);
    }
    printf("\n");
}

// --- PILHA ---
typedef struct {
    Peca pilha[MAX_PILHA];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int estaCheiaPilha(Pilha *p) {
    return p->topo == MAX_PILHA - 1;
}

int estaVaziaPilha(Pilha *p) {
    return p->topo == -1;
}

void push(Pilha *p, Peca piece) {
    if (estaCheiaPilha(p)) return;
    p->topo++;
    p->pilha[p->topo] = piece;
}

Peca pop(Pilha *p) {
    Peca piece = {'X', -1};
    if (estaVaziaPilha(p)) return piece;
    piece = p->pilha[p->topo];
    p->topo--;
    return piece;
}

void exibirPilha(Pilha *p) {
    printf("Pilha de reserva\t(Topo -> Base): ");
    if (estaVaziaPilha(p)) {
        printf("(vazia)\n");
        return;
    }
    for (int i = p->topo; i >= 0; i--) {
        printf("[%c %d] ", p->pilha[i].tipo, p->pilha[i].id);
    }
    printf("\n");
}

// --- GERAR PEÇA ---
Peca gerarPeca(int id) {
    Peca p;
    char tipos[] = {'I', 'O', 'T', 'L'};
    p.tipo = tipos[rand() % 4];
    p.id = id;
    return p;
}

// --- TROCA ENTRE FILA E PILHA ---
void trocarFrenteTopo(Fila *f, Pilha *p) {
    if (estaVaziaFila(f) || estaVaziaPilha(p)) {
        printf("Troca impossível: fila ou pilha vazia.\n");
        return;
    }
    Peca tmp = f->fila[f->frente];
    f->fila[f->frente] = p->pilha[p->topo];
    p->pilha[p->topo] = tmp;
    printf("Peça da frente da fila trocada com o topo da pilha.\n");
}

void trocaMultipla(Fila *f, Pilha *p) {
    if (f->tamanho < 3 || p->topo < 2) {
        printf("Troca múltipla impossível: fila ou pilha não têm peças suficientes.\n");
        return;
    }
    for (int i = 0; i < 3; i++) {
        int idxFila = (f->frente + i) % MAX_FILA;
        Peca tmp = f->fila[idxFila];
        f->fila[idxFila] = p->pilha[p->topo - i];
        p->pilha[p->topo - i] = tmp;
    }
    printf("Troca múltipla realizada entre os 3 primeiros da fila e 3 da pilha.\n");
}

// --- PROGRAMA PRINCIPAL ---
int main() {
    srand(time(NULL));
    Fila fila;
    Pilha pilha;
    int id_counter = 0;

    inicializarFila(&fila);
    inicializarPilha(&pilha);

    // Inicializa fila
    for (int i = 0; i < MAX_FILA; i++) {
        enqueue(&fila, gerarPeca(id_counter++));
    }

    int opcao;
    do {
        printf("\n=== Estado atual ===\n");
        exibirFila(&fila);
        exibirPilha(&pilha);

        printf("\nOpções disponíveis:\n");
        printf("1 - Jogar peça da frente da fila\n");
        printf("2 - Enviar peça da fila para a pilha de reserva\n");
        printf("3 - Usar peça da pilha de reserva\n");
        printf("4 - Trocar peça da frente da fila com o topo da pilha\n");
        printf("5 - Trocar os 3 primeiros da fila com as 3 peças da pilha\n");
        printf("0 - Sair\n");
        printf("Opção escolhida: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: {
                Peca jogada = dequeue(&fila);
                if (jogada.id != -1)
                    printf("Peça %c (ID: %d) jogada.\n", jogada.tipo, jogada.id);
                enqueue(&fila, gerarPeca(id_counter++));
                break;
            }
            case 2: {
                if (!estaVaziaFila(&fila) && !estaCheiaPilha(&pilha)) {
                    Peca reservada = dequeue(&fila);
                    push(&pilha, reservada);
                    printf("Peça %c (ID: %d) enviada para a pilha de reserva.\n", reservada.tipo, reservada.id);
                    enqueue(&fila, gerarPeca(id_counter++));
                } else {
                    printf("Não é possível reservar: fila vazia ou pilha cheia.\n");
                }
                break;
            }
            case 3: {
                Peca usada = pop(&pilha);
                if (usada.id != -1)
                    printf("Peça reservada %c (ID: %d) usada.\n", usada.tipo, usada.id);
                break;
            }
            case 4:
                trocarFrenteTopo(&fila, &pilha);
                break;
            case 5:
                trocaMultipla(&fila, &pilha);
                break;
            case 0:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}

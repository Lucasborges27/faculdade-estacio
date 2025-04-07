#include <stdio.h>

int main(){
int populacao = 13;
int pib = 12;

if (populacao > pib){
        printf("CARTA 1 VENCEU");
} else if(populacao < pib){
        printf("CARTA 2 VENCEU");
}else {
        printf("EMPATE");
}

return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
%d: Imprime um inteiro no formato decimal.
%i: Equivalente a %d.
%f: Imprime um número de ponto flutuante no formato padrão.
%e: Imprime um número de ponto flutuante na notação científica.
%c: Imprime um único caractere.
%s: Imprime uma cadeia (string) de caracteres.
*/

int main(){
char estado [50], codigo[4], nomedacidade[50];
long long int populacao;
int turisticos;
double area, pib;

char estado2 [50], codigo2[4], nomedacidade2[50];
long long int populacao2;
int turisticos2;
double area2, pib2;

//COLETANDO DADOS DA CARTA 1 
printf("Bem vindo ao Super Trunfo\n");
printf("vamos coletar alguns dados da Carta 1 okay?\n");
printf("Digite o ESTADO: ");
fgets(estado,50,stdin); 

printf("Digite o CODIGO da carta (EX: A01): ");
scanf(" %3s", codigo);
getchar(); 

printf("Digite o NOME DA CIDADE: ");
fgets(nomedacidade,50,stdin); 

printf("Digite a POPULAÇÃO da cidade: ");
scanf(" %lld", &populacao);
getchar();

printf("Digite a ÁREA TERRITORIAL (Km2): ");
scanf("%lf", &area);
getchar();

printf("Digite o PIB (Produto Interno Bruto da cidade): ");
scanf("%lf", &pib);
getchar();

printf("Digite o número de pontos turísticos: ");
scanf("%d", &turisticos);
getchar();

system("clear");

//COLETANDO DADOS DA CARTA 2
printf("Ótimo! Agora vamos coletar alguns dados da Carta 2, pode ser?\n");
printf("Digite o ESTADO: ");
fgets(estado2,50,stdin); 
printf("Digite o CODIGO da carta (EX: A01):" );
scanf(" %3s", codigo2);
getchar();
printf("Digite o NOME DA CIDADE:");
fgets(nomedacidade2,50,stdin); 
printf("Digite a POPULAÇÃO da cidade: ");
scanf(" %lld", &populacao2);
getchar();
printf("Digite a ÁREA TERRITORIAL (Km2):  ");
scanf("%lf", &area2);
getchar();
printf("Digite o PIB (Produto Interno Bruto da cidade):  ");
scanf("%lf", &pib2);
getchar();
printf("Digite o número de pontos turísticos:  ");
scanf("%d", &turisticos2);

system("clear");

double densidade1 = (area > 0) ? (double)populacao / area : 0;
double densidade2 = (area2 > 0) ? (double)populacao2 / area2 : 0;
double percapita1 = (populacao > 0) ? pib / populacao : 0;
double percapita2 = (populacao2 > 0) ? pib2 / populacao2 : 0;
double pib_em_bilhoes = pib / 1.0e9; 
double pib_em_bilhoes2 = pib2 / 1.0e9; 
double super_poder = (double)populacao + area + pib + turisticos + percapita1 -densidade1;
double super_poder2 = (double)populacao2 + area2 + pib2 + turisticos2 + percapita2 -densidade2;

//APÓS A COLETA DOS DADOS DA CARTA 1 VAMOS A IMPRESSÃO PARA O USUARIO
printf("ESSA É A NOSSA CARTA 1.\n");
estado[strcspn(estado, "\n")] = 0;
printf("Estado: %s\n", estado);
printf("Código: %s\n", codigo);
nomedacidade[strcspn(nomedacidade, "\n")] = 0;
printf("Nome da Cidade: %s\n", nomedacidade);
printf("População: %lld\n" , populacao);
printf("Área: %.2lf KM²\n", area);
printf("PIB: %.2lf Bilhões de Reais\n",  pib_em_bilhoes);
printf("Número de Pontos Turísticos: %d\n", turisticos);
printf("Densidade Populacional: %.2lf hab/km²\n", densidade1);
printf("PIB per Capita: %.2lf reais\n", percapita1);
printf("Super Poder é: %.2lf\n", super_poder);

printf("\n\n"); //APENAS PARA DAR UM ESPAÇO ENTRE A IMPRESSÃO DAS CARTAS NO TERMINAL

//APÓS A COLETA DOS DADOS DA CARTA 2 VAMOS A IMPRESSÃO PARA O USUARIO
printf("ESSA É A CARTA 2. \n");
estado2[strcspn(estado2, "\n")] = 0;
printf("Estado: %s\n", estado2);
printf("Código da carta: %s\n", codigo2);
nomedacidade2[strcspn(nomedacidade2, "\n")] = 0;
printf("Nome da Cidade: %s\n", nomedacidade2);
printf("População: %lld\n", populacao2);
printf("Área: %.2lf KM²\n", area2);
printf("PIB: %.2lf Bilhões de Reais\n",  pib_em_bilhoes2);
printf("Número de Pontos Turísticos: %d\n", turisticos2);
printf("Densidade Populacional: %.2lf hab/km²\n", densidade2);
printf("PIB per Capita: %.2lf reais\n", percapita2);
printf("Super Poder é: %.2lf\n", super_poder2);


printf("\n\n");

printf("Comparação de cartas:\n");
//CARTA VENCEDORA PARA POPULAÇÃO
if (populacao > populacao2){
    printf("População: 🏆 Carta 1 venceu (1)\n");
} else if(populacao < populacao2){
    printf("População: 🏆 Carta 2 venceu (0)\n");
}else {
           printf("RESULTADO: EMPATE 🤝\n");
}
//CARTA VENCEDORA PARA AREA
if (area > area2){
    printf("Área: 🏆 Carta 1 venceu (1)\n");
} else if(area < area2){
    printf("Área: 🏆 Carta 2 venceu (0)\n");
}else {
           printf("RESULTADO: EMPATE 🤝\n");
}
//CARTA VENCEDORA PARA PIB
if (pib > pib2){
    printf("Pib: 🏆 Carta 1 venceu (1)\n");
} else if(pib < pib2){
    printf("Pib: 🏆 Carta 2 venceu (0)\n");
}else {
           printf("RESULTADO: EMPATE 🤝\n");
}
//CARTA VENCEDORA PARA PONTOS TURISTICOS
if (turisticos > turisticos2){
    printf("Pontos Turísticos: 🏆 Carta 1 venceu (1)\n");
} else if(turisticos < turisticos2){
    printf("Pontos Turísticos: 🏆 Carta 2 venceu (0)\n");
}else {
           printf("RESULTADO: EMPATE 🤝\n");
}
//CARTA VENCEDORA PARA DENSIDADE POPULACIONAL
if (densidade1 > densidade2){
    printf("Densidade Populacional: 🏆 Carta 1 venceu (1)\n");
} else if(densidade1 < densidade2){
    printf("Densidade Populacional: 🏆 Carta 2 venceu (0)\n");
}else {
           printf("RESULTADO: EMPATE 🤝\n");
}
//CARTA VENCEDORA PARA PIB PER CAPITA
if (percapita1 > percapita2){
    printf("PIB per Capita: 🏆 Carta 1 venceu (1)\n");
} else if(percapita1 < percapita2){
    printf("PIB per Capita: 🏆 Carta 2 venceu (0)\n");
}else {
           printf("RESULTADO: EMPATE 🤝\n");
}
//CARTA VENCEDORA PARA SUPER PODER
if (super_poder > super_poder2){
    printf("Super Poder: 🏆 Carta 1 venceu (1)\n");
} else if(super_poder < super_poder2){
    printf("Super Poder: 🏆 Carta 2 venceu (0)\n");
}else {
           printf("RESULTADO: EMPATE 🤝\n");
}


printf("\n\n");


// COMPARATIVO ENTRE AS CARTAS INTERNAMENTE 
printf("Comparação de cartas (Atributo: População):\n");
printf("Carta 1 - %s: %lld\n", estado, populacao);
printf("Carta 2 - %s: %lld\n", estado2, populacao2);
if (populacao > populacao2){
    printf("🏆 Carta vencedora: %s\n", estado);
} else if(populacao < populacao2){
    printf("🏆 Carta vencedora: %s\n", estado2);
}else {
           printf("RESULTADO: EMPATE 🤝\n");
}

return 0;

}
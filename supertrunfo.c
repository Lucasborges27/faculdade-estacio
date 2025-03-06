#include <stdio.h>
    

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
int populacao , turisticos;
float area, pib;

char estado2 [50], codigo2[4], nomedacidade2[50];
int populacao2 , turisticos2;
float area2, pib2;


//COLETANDO DADOS DA CARTA 1 
printf("Bem vindo ao Super Trunfo\n");
printf("vamos coletar alguns dados da Carta 1 okay?\n");
printf("Digite o ESTADO\n");
fgets(estado,50,stdin); //USADO O FGETS PARA ESTADOS OU CIDADES COM MAIS DE UMA PALAVRA
printf("Digite o CODIGO da carta (INICIAL DO ESTADO + NUMERO DE 01 A 04)\n");
scanf(" %3s", &codigo);
getchar(); //limpar o \n do meu fgets para não ocupar o buffer do scanf
printf("Digite o NOME DA CIDADE\n");
fgets(nomedacidade,50,stdin);
printf("Digite a POPULAÇÃO da cidade \n");
scanf(" %d",&populacao);
printf("Digite a ÁREA TERRITORIAL (Km2)\n");
scanf("%f",&area);
printf("Digite o PIB (Produto Interno Bruto da cidade)\n");
scanf("%f",&pib);
printf("Digite o número de pontos turísticos\n");
scanf("%d",&turisticos);


//COLETANDO DADOS DA CARTA 2
printf("Ótimo! Agora vamos coletar alguns dados da Carta 2, pode ser?\n");
printf("Digite o ESTADO\n");
fgets(estado2,50,stdin); //USADO O FGETS PARA ESTADOS OU CIDADES COM MAIS DE UMA PALAVRA
printf("Digite o CODIGO da carta (INICIAL DO ESTADO + NUMERO DE 01 A 04)\n");
scanf(" %3s", &codigo2);
getchar(); //limpar o \n do meu fgets para não ocupar o buffer do scanf
printf("Digite o NOME DA CIDADE\n");
fgets(nomedacidade2,50,stdin);
printf("Digite a POPULAÇÃO da cidade \n");
scanf(" %d",&populacao2);
printf("Digite a ÁREA TERRITORIAL (Km2)\n");
scanf("%f",&area2);
printf("Digite o PIB (Produto Interno Bruto da cidade)\n");
scanf("%f",&pib2);
printf("Digite o número de pontos turísticos\n");
scanf("%d",&turisticos2);



//APÓS A COLETA DOS DADOS DA CARTA 1 VAMOS A IMPRESSÃO PARA O USUARIO

printf("ESSA É A NOSSA CARTA 1:\n");
estado[strcspn(estado, "\n")] = 0;
printf("Estado: %s\n", estado);
printf("Código: %s\n", codigo);
nomedacidade[strcspn(nomedacidade, "\n")] = 0;
printf("Nome da Cidade: %s\n", nomedacidade);
printf("População: %d\n" , populacao);
printf("Área: %.2f\n", area);
printf("PIB: %.2f\n", pib);
printf("Número de Pontos Turísticos: %d\n", turisticos);


//APÓS A COLETA DOS DADOS DA CARTA 2 VAMOS A IMPRESSÃO PARA O USUARIO
printf("AGORA VAMOS PARA A CARTA 2!!! \n");
printf("ESSA É A NOSSA CARTA 2:\n");
estado2[strcspn(estado2, "\n")] = 0;
printf("Estado: %s\n", estado2);
printf("Código: %s\n", codigo2);
nomedacidade2[strcspn(nomedacidade2, "\n")] = 0;
printf("Nome da Cidade: %s\n", nomedacidade2);
printf("População: %d\n", populacao2);
printf("Área: %.2f\n", area2);
printf("PIB: %.2f\n", pib2);
printf("Número de Pontos Turísticos: %d\n", turisticos2);




}

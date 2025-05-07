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
long long int populacao, populacao2;
int turisticos, turisticos2;
double area, pib, area2, pib2;      
double valor1_carta1 = 0, valor1_carta2 = 0;
double valor2_carta1 = 0, valor2_carta2 = 0;

char estado2 [50], codigo2[4], nomedacidade2[50];
int opcao, final;
int atributos, atributo1, atributo2;
int escolha1, escolha2;


    while(1) {
      printf("======🏳️🌍MENU PRINCIPAL🌍🏳️======\n");
      printf("1. Iniciar Jogo🏁\n");
      printf("2. Ver Regras📑\n");
      printf("3. Sair👋🏽\n");
      printf("Escolha uma opção: \n");
      scanf("%d", &opcao);
      getchar();

    switch (opcao) {
    case 1:
      system("clear");
//COLETANDO DADOS DA CARTA 1 
      printf("\n=========================================\n");
      printf("🃏🎮        INICIANDO O JOGO...        🎮🃏\n");
      printf("=========================================\n");
      printf("🚀 Bem-vindo ao *SUPER TRUNFO* 🌎\n\n");
      printf("📝 Vamos coletar alguns dados da 📄 *Carta 1*, beleza?\n\n");
      printf("Digite o ESTADO: ");
      fgets(estado,50,stdin); 
      printf("Digite o CODIGO da carta (EX: A01): ");
      scanf("%3s", codigo);
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
      //COLETANDO DADOS DA CARTA 
      printf("Ótimo! Agora vamos coletar alguns dados da Carta 2, pode ser?\n");
      printf("Digite o ESTADO: ");
      fgets(estado2,50,stdin); 
      printf("Digite o CODIGO da carta (EX: A01): ");
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
}   else if(pib < pib2){
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
      printf("Densidade Populacional: 🏆 Carta 2 venceu (0)\n");
    } else if(densidade1 < densidade2){
      printf("Densidade Populacional: 🏆 Carta 1 venceu (1)\n");
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
      printf("\n\n");
//PARTE DO CODIGO QUE PRECISA SER AVALIADA ATÉ O FIM PARA FUNCIONAR A ULTIMA ETAPA DA TAREFA 
while (1) {
  printf("\n╔════════════════════════════════════════════╗\n");
  printf("║   🌍 Escolha um atributo para comparar:     ║\n");
  printf("╠════════════════════════════════════════════╣\n");
  printf("║ 1️⃣  População                             ║\n");
  printf("║ 2️⃣  Área                                  ║\n");
  printf("║ 3️⃣  PIB                                   ║\n");
  printf("║ 4️⃣  Número de pontos turísticos          ║\n");
  printf("║ 5️⃣  Densidade demográfica                ║\n");
  printf("║ 6️⃣  Proximo---->                           ║\n");
  printf("║ 7️⃣  Encerrar ❌                           ║\n");
  printf("╚════════════════════════════════════════════╝\n");
  scanf("%d", &atributos);
  getchar();

  switch (atributos) {
      case 1:
          system("clear");
          printf("CIDADES\n");
          printf("1º CIDADES: %s e %s\n", estado, estado2);
          printf("2º Atributo escolhido: População\n");
          printf("3º %s : %lld e %s : %lld\n",
                 nomedacidade, populacao, nomedacidade2, populacao2);
          if (populacao > populacao2)
              printf("4º A carta 1 Venceu🏆!!!\n");
          else if (populacao < populacao2)
              printf("4º A carta 2 Venceu🏆!!!\n");
          else
              printf("4º Empate!\n");
          break;

      case 2:
          system("clear");
          printf("Área\n");
          printf("1º CIDADES: %s e %s\n", estado, estado2);
          printf("2º Atributo escolhido: Área\n");
          printf("3º %s : %lf e %s : %lf\n",
                 nomedacidade, area, nomedacidade2, area2);
          if (area > area2)
              printf("4º A carta 1 Venceu🏆!!!\n");
          else if (area < area2)
              printf("4º A carta 2 Venceu🏆!!!\n");
          else
              printf("4º Empate!\n");
          break;

      case 3:
          system("clear");
          printf("PIB\n");
          printf("1º CIDADES: %s e %s\n", estado, estado2);
          printf("2º Atributo escolhido: PIB\n");
          printf("3º %s : %lf e %s : %lf\n",
                 nomedacidade, pib, nomedacidade2, pib2);
          if (pib > pib2)
              printf("4º A carta 1 Venceu🏆!!!\n");
          else if (pib < pib2)
              printf("4º A carta 2 Venceu🏆!!!\n");
          else
              printf("4º Empate!\n");
          break;

      case 4:
          system("clear");
          printf("Número de pontos turísticos\n");
          printf("1º CIDADES INFORMADAS: %s e %s\n",
                 estado, estado2);
          printf("2º ATRIBUTOS ESCOLHIDOS: Número de pontos turísticos\n");
          printf("3º %s : %d e %s : %d\n",
                 nomedacidade, turisticos, nomedacidade2, turisticos2);
          if (turisticos > turisticos2)
              printf("4º A carta 1 Venceu🏆!!!\n");
          else if (turisticos < turisticos2)
              printf("4º A carta 2 Venceu🏆!!!\n");
          else
              printf("4º Empate!\n");
          break;

      case 5:
          system("clear");
          printf("Densidade demográfica\n");
          printf("1º CIDADES INFORMADAS: %s e %s\n",
                 estado, estado2);
          printf("2º ATRIBUTO ESCOLHIDO: Densidade demográfica\n");
          printf("3º %s : %lf e %s : %lf\n",
                 nomedacidade, densidade1, nomedacidade2, densidade2);
          if (densidade1 > densidade2)
              printf("4º A carta 2 Venceu🏆!!!\n");
          else if (densidade1 < densidade2)
              printf("4º A carta 1 Venceu🏆!!!\n");
          else
              printf("4º Empate!\n");
          break;

      case 6: {
          int atributo1, atributo2;
          double valor1_carta1, valor1_carta2;
          double valor2_carta1, valor2_carta2;

          // Primeiro atributo
          while (1) {
              printf("\n╔════════════════════════════════════════════════════╗\n");
              printf("║    🧠Escolha o Primeiro Atributo para a Disputa:    ║\n");
              printf("╠════════════════════════════════════════════════════╣\n");
              printf("║  1️⃣  População                                    ║\n");
              printf("║  2️⃣  Área                                         ║\n");
              printf("║  3️⃣  PIB                                          ║\n");
              printf("║  4️⃣  Número de pontos turísticos                 ║\n");
              printf("║  5️⃣  Densidade demográfica                       ║\n");
              printf("╚════════════════════════════════════════════════════╝\n");
              scanf("%d", &atributo1); getchar();
              if (atributo1 >= 1 && atributo1 <= 5) break;
              printf("❌ Opção inválida! Tente novamente.\n");
          }

          // Segundo atributo
          while (1) {
              printf("\n╔════════════════════════════════════════════════════╗\n");
              printf("║    🧠Escolha o Segundo Atributo para a Disputa:     ║\n");
              printf("╠════════════════════════════════════════════════════╣\n");
              printf("║  1️⃣  População                                    ║\n");
              printf("║  2️⃣  Área                                         ║\n");
              printf("║  3️⃣  PIB                                          ║\n");
              printf("║  4️⃣  Número de pontos turísticos                 ║\n");
              printf("║  5️⃣  Densidade demográfica                       ║\n");
              printf("╚════════════════════════════════════════════════════╝\n");
              scanf("%d", &atributo2); getchar();
              if (atributo2 < 1 || atributo2 > 5) {
                  printf("❌ Opção inválida! Tente novamente.\n");
              } else if (atributo2 == atributo1) {
                system("clear");
                  printf("❌ Você já escolheu esse atributo! Escolha outro.\n");
              } else {
                  break;
              }
          }

          // Mapeamento valores
          switch (atributo1) {
              case 1: valor1_carta1 = populacao; valor1_carta2 = populacao2; break;
              case 2: valor1_carta1 = area;      valor1_carta2 = area2;      break;
              case 3: valor1_carta1 = pib;       valor1_carta2 = pib2;       break;
              case 4: valor1_carta1 = turisticos;valor1_carta2 = turisticos2;break;
              case 5: valor1_carta1 = densidade1;valor1_carta2 = densidade2;break;
          }
          switch (atributo2) {
              case 1: valor2_carta1 = populacao; valor2_carta2 = populacao2; break;
              case 2: valor2_carta1 = area;      valor2_carta2 = area2;      break;
              case 3: valor2_carta1 = pib;       valor2_carta2 = pib2;       break;
              case 4: valor2_carta1 = turisticos;valor2_carta2 = turisticos2;break;
              case 5: valor2_carta1 = densidade1;valor2_carta2 = densidade2;break;
          }

          // Resultado
          {system("clear");
              double soma1 = valor1_carta1 + valor2_carta1;
              double soma2 = valor1_carta2 + valor2_carta2;
              printf("\nO nome dos dois países: %s e %s\n", estado, estado2);
              printf("Atributos: %d e %d\n", atributo1, atributo2);
              printf("Carta 1: %.2lf e %.2lf\n", valor1_carta1, valor2_carta1);
              printf("Carta 2: %.2lf e %.2lf\n", valor1_carta2, valor2_carta2);
              if (soma1 > soma2) printf("🏆 Carta 1 Venceu!!!\n");
              else if (soma1 < soma2) printf("🏆 Carta 2 Venceu!!!\n");
              else printf("🤝 Empate!\n");
          }

          printf("\nPressione Enter para continuar...");
          getchar();
          system("clear");
          break;
      }
case 7:{
printf("Encerrando....");
return 0;
    }
      default:
          system("clear");
          printf("❌ Opção inválida! Tente novamente.\n");
          break;
  }
}

//PARTE FORA DA LINHA DE ANALISE NÃO MECHER EM NADA ATE O FIM DAI
    case 2:{
      system("clear");
      printf("\n=========================================\n");
      printf("📜📑          REGRAS DO JOGO           📑📜\n");
      printf("=========================================\n\n");
      printf("1️⃣  INSIRA OS DADOS DA CARTA:\n");
      printf("    ➤ Cada jogador deve informar:\n");
      printf("       • 🌎 Estado\n");
      printf("       • 🧾 Código\n");
      printf("       • 🏙️ Nome da Cidade\n");
      printf("       • 👥 População\n");
      printf("       • 🌐 Área (km²)\n");
      printf("       • 💰 PIB (Produto Interno Bruto)\n");
      printf("       • 📸 Número de Pontos Turísticos\n\n");
      printf("2️⃣  A CARTA COM MAIOR NÚMERO VENCE:\n");
      printf("    ➤ Nas categorias:\n");
      printf("       • População 👥\n");
      printf("       • Área 🌐\n");
      printf("       • PIB 💰\n");
      printf("       • Pontos Turísticos 📸\n");
      printf("      → Vence a carta com o MAIOR valor.\n\n");
      printf("3️⃣  NA DENSIDADE POPULACIONAL:\n");
      printf("    ➤ Neste caso específico, vence quem tiver o *MENOR número*,\n");
      printf("      ou seja, o estado menos densamente povoado.\n\n");
      printf("🧠 Use sua estratégia para vencer cada rodada!\n");
      printf("🎮 Boa sorte, comandante do Super Trunfo!\n\n");
      printf("=========================================\n\n");
      break;
    }
    case 3:{
      system("clear");
      printf("Saindo...\n");
    return 0;
    }
    default:{
      printf("Opção inválida. Tente novamente.\n");
      break;
       }
    }
  }
}

  


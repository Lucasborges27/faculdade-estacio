#include <stdio.h>
int main(){
float notaA, notaB, notaC;
int N = 3; //USEI PARA A DIVISÃO PORQUE A QUANTIDADE DE NOTAS QUE DEVEM INSERIR SERÁ SEMPRE 3

//RECEBER INFORMAÇÕES DO USUARIO.
printf("DIGITE A PRIMEIRA NOTA:\n  ");
scanf("%f",&notaA);
printf("DIGITE A SEGUNDA NOTA:\n   ");
scanf("%f",&notaB);
printf("DIGITE A TERCEIRA NOTA:\n   ");
scanf("%f",&notaC);
system("clear");

//EFETUAR AS OPERAÇÕES MATEMATICAS
float soma = notaA + notaB + notaC;
float media = soma / 3; //A DIVISÃO DA SOMA POR 3 SERÁ A MEDIA DAS NOTAS 
printf("A MÉDIA É: %.2f\n", media);



}


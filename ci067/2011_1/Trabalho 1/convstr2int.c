/*************************
	8.(convstr2int)  Escreva um programa que leia uma string 
	que representa um número inteiro na base 10 e gere o 
	valor inteiro correspondente. Faça isto sem usar as 
	funções atoi() e scanf().
*************************/

/************************
	Flaviene Scheidt de Cristo
	FSC10
	GRR20101915
************************/

#include <sdtio.h>
/***************
	Programa Principal
***************/
main(){
	/*** Declara variáveis ***/
	char numero;
	int converte;
	/*** Converte ***/
	gets(numero);
	converte = (int)numero;
	printf("%d", &converte);
}
/*************************
	8.(convstr2int)  Escreva um programa que leia uma string 
	que representa um n�mero inteiro na base 10 e gere o 
	valor inteiro correspondente. Fa�a isto sem usar as 
	fun��es atoi() e scanf().
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
	/*** Declara vari�veis ***/
	char numero;
	int converte;
	/*** Converte ***/
	gets(numero);
	converte = (int)numero;
	printf("%d", &converte);
}
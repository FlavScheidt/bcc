/*************************
	6.(prnabnt)  Escreva um programa que leia um nome completo e 
	imprima o sobrenome comtodas as letras mai�sculas, �,�(v�rgula) 
	e em seguida o restante do nome. Exemplo: Armando Luiz Nicolini 
	Delgado ==> DELGADO, Armando Luiz Nicolini
*************************/

/*************************
	Flaviene Scheidt de Cristo
	FSC10
	GRR20101915
************************/

#include <stdio.h>
#include <ctype.h>
/***************
	Fun��es
***************/
int le(int, int); /* L� a string e retorna o tamanho */
char get_sobrenome(int, int, int, int); /* Obtem apenas o sobrenome e joga no vetor sobrenome */
/***************
	Programa Principal
***************/
main(){
	/*** Declara Vari�veis e Vetores ***/
	char sobrenome[152];
	char nome [150];
	int tam, i, espa�o, fim, l);
	/*** Le string ***/
	le(nome, sobrenome);
	/*** Obtem sobrenome ***/
	get_sobrenome(nome, sobrenome, l, fim);
	/*** Deixa o sobrenome em letras mai�sculas e formata sa�da ***/
	toupper(sobrenome);
	sobrenome[l] = ",";
	sobrenome[l+1] = " ";
	fim --;
	l = l+2;
	for (i=0; i<=fim; i++) {
		sobrenome[l] = nome[i];
		l++;
	}
	printf("%c", &sobrenome);
}
/***************
	Fun��es
***************/
int le(v[100], tam) {
	printf("Digite nome completo");
	gets(nome);
	tam = strlen(nome);
	return tam;
}
char get_sobrenome(char v[150], char v2[152], int fim, int l) {
	espaco = 0;
	i = tam;
	while ((i<=tam)  || (espaco == 0) {
		if (nome[i] == " ") {
			espa�o = 1;
			fim = i+1;
		}
		i--;
	}
	l = 0;
	for (j = fim, j<=tam, j++) {
		nome[j] = sobrenome[l];
		l++;
	}
}
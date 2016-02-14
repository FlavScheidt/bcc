/************************************************
	Flaviene Scheidt de Cristo
	GRR20101915
	fsc10

	Daniele Ito
	GRR2010
	di10
************************************************/
#include "PatTree.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/***********************
	FUNÇÕES
***********************/
/*************
	Carrega Dicionário
*************/
Arvore CarregaDicionario(FILE *dicionario)
{
	Arvore t;
	ChaveTipo *le = (char *) malloc(20*sizeof(char));
	do
	{
		fgets(le, 19*sizeof(char), dicionario);
		t = Insere(*le, &t);
	}while (*le != EOF);
	return t;
}

/***********************
	PROGRAMA PRINCIPAL
***********************/
int main(int argc, char* argv[])
{
	Arvore *t = (Arvore *) malloc(sizeof(Arvore));
	FILE *dicionario;
	dicionario = fopen(argv[1], "r+");
	*t = CarregaDicionario(dicionario);
	fclose(dicionario);
	FILE *teclas;
	teclas = fopen(argv[2], "r+");
	fclose(teclas);
}

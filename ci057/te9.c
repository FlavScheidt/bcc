/************************************************
	Flaviene Scheidt de Cristo
	GRR20101915
	fsc10

	Daniele Ito
	GRR2010
	di10
************************************************/
#include <"PatTree.h">

/***********************
	FUNÇÕES
***********************/
/*************
	Carrega Dicionário
*************/
Arvore CarregaDicionario(FILE *dicionario)
{
	Arvore t;
	ChaveTipo le = (char) malloc(20*sizeof(char));
	while (dicionario != EOF)
	{
		fgets(le, 19*sizeof(char), dicionario);
		t = Insere(le, *t);
	}
}

/***********************
	PROGRAMA PRINCIPAL
***********************/
int Main(int argc, char* argv[])
{
	Arvore t = (Arvore) malloc(sizeof(Arvore));
	File *dicionario;
	dicionario = fopen(argv[1], r+);
	t = CarregaDicionario(dicionario);
	fclose(dicionario);
	File *teclas;
	teclas = fopen(argv[2], r+);
	fclose(teclas);
}

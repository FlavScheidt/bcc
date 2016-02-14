/************************************************
	Flaviene Scheidt de Cristo
	GRR20101915
	fsc10

	Daniele Ito
	GRR2010
	di10

	Biblioteca que implementa árvores
	Patricia, conforme apresentado
	no livro ZIVIANI, Nivio. Projetos
	de algoritmos: com implementações
	em Pascal e C. 2 ed. rev. e ampl.
	São Paulo: Cengage Learning, 2009.
************************************************/

#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/***********************
	Declarações
************************/

#define D 8; //8 bits
/***** Estruturas *****/
typedef unsigned char ChaveTipo;
typedef unsigned char IndexAmp;
typedef unsigned char Dib;
typedef enum
{
	/* A PatTree possui dois tipos de nodos, 
	o interno - que possuitTree.h:65: error: expected ‘)’ before ‘*’ token
	Te9.c:18: error: expected ‘)’ before ‘*’ token

 a posição de diferenciação 
	e o externo, que são as folhas, ou seja, contém
	a palavra completa */
	Interno, Externo
} NoTipo;
typedef struct PatNo* Arvore;
typedef struct PatNo
{
	NoTipo nt; //Escolhe o tipo de nodo
	union
	{
		struct
		{
			IndexAmp Index; //Índice de diferenciação
			Arvore Esq, Dir;//Ramos
		}NInterno; //Define nós interno
		ChaveTipo Chave;
	}NO;
}PatNo;

/***** Funções *****/
Dib Bit(IndexAmp i, ChaveTipo k);
//Retorna o valor do bit de acordo com a posição, serve para comparação
short EExterno(Arvore p);
//Verifica se é nó externo
Arvore CriaNoInt(int i, Arvore *Esq, Arvore *Dir);
//Cria nó interno, com i sendo o índice de diferenciação
Arvore CriaNoExt(ChaveTipo k);
//Cria folha
ChaveTipo Pesquisa(ChaveTipo k, Arvore t);
//Procura chave na árovere
Arvore InsereEntre(ChaveTipo k, Arvore *t, int i);
//Função recursiva que refaz a árvore incluindo o novo elemento
Arvore Insere(ChaveTipo k, Arvore *t);
//Função geral de inserção
Arvore CarregaDicionario(FILE *dicionario);

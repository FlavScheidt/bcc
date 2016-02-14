/*************************
	(mescla)   Um programa recebe pela linha de comando nome de 2 arquivos de texto, e 3 pares de inteiros representando coordenadas (linha,caracter) em um arquivo de texto (ASCII). Exemplo:
	mescla texto-01 texto-02 19 21 3 12 8 46
	O programa deve copiar um bloco de texto do 2o arquivo no 1o arquivo, a partir da coordenada indicada no 1o par de inteiros, sobrescrevendo o conteúdo a partir desta posição. O bloco do 2o arquivo é definido pelos dois pares de coordenadas restantes. Após copiar o bloco, espaços em branco devem ser preenchidos ao redor. Finalmente, o resultado deve ser salvo em um 3o arquivo, cujo nome é arbitrário, sendo que uma mensagem final do programa deve indicar este nome.
*************************/
/************************
	Flaviene Scheidt de Cristo
	FSC10
	GRR20101915
************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/***************
	Funções
***************/
void trataCoordenadas (char **argv, int *l1, int *l2, int *l3, int *c1, int *c2, int *c3)//Pega coordenadas da linha de comando e converte para int
{
	/*** Linhas ***/
	*l1 = atoi(argv[3]);
	*l2 = atoi(argv[5]);
	*l3 = atoi(argv[7]);
	/*** Colunas ***/
	*c1 = atoi(argv[4]);
	*c2 = atoi(argv[6]);
	*c3 = atoi(argv[8]);
}
void geraBloco (int *l2, int *l3, int *c2, int *c3)//Altura e largura do bloco a ser copiado para arq3
{
	int temp;
	if (*l3<*l2)
	{
		temp = *l3;
		*l3 = *l2;
		*l2 = temp;
	}
	if (*c3<*c2)
	{
		temp = *c3;
		*c3 = *c2;
		*c2 = temp;
	}
}
int contacol(FILE *arq1) //Conta número de colunas
{
	int numcol = 0;
	char c;
	c = fgetc(arq1);
	while (c != '\n')
	{
		numcol++;
		c = fgetc(arq1);
	}
	rewind(arq1);
	return numcol;
}
void iniciaArq3(FILE *arq3, FILE *arq1) //Copia conteudo do arq1 para o arq3
{
	int i;
	char c;
	c = fgetc(arq1);
	while (c != EOF)
	{
		fputc(c, arq3);
		c = fgetc(arq1);
	}
	rewind(arq1);
	rewind(arq3);
}
void copiaBloco(FILE *arq3, FILE *arq2, int numcol, int c1, int c2, int c3, int l1,int l2, int l3) //Copia bloco e gera coluna
{
	int c, l, i, j;
	char aux;
	l = 0;
	c = 0;
	/***** Coloca ponteiro do arq3 na primeira coordenada *****/
	while (l != (l1-1)) //Percorre arquivo até chegar a linha indicada
	{
		c++;
		aux = fgetc(arq3);
		if (c = numcol)
		{
			l++;
		}
	}
	c = 0;
	while (c != (c1-1)) //Percorre arquivo até chegar no coluna indicada
	{
		aux = fgetc(arq3);
		c++;
	}
	/***** Coloca ponteiro do arq2 na segunda coordenada *****/
	c = 0;
	l = 0;
	while (l != (l2)) //Percorre arquivo até chegar a linha indicada
	{
		c++;
		aux = fgetc(arq2);
		if (c = numcol)
		{
			l++;
		}
	}
	c = 0;
	while (c != (c2)) //Percorre arquivo até chegar no coluna indicada
	{
		aux = fgetc(arq2);
		c++;
	}
	/***** Coloca espaços na primeira linha *****/
	c = 0;
	while (c != (c3+1)) //Percorre as colunas
	{
		fputc(' ', arq3); //Subescreve caracteres com espaços
		c++;
	}
	fputc(' ', arq3);
	/***** Copia *****/
	i = 0;
	j = 0;
	while (i != l3)
	{
		while (j != (c2-1)) //Coloca o ponteiro na coluna certa
		{
			aux = fgetc(arq2);
			j++;
		}
		fputc(' ', arq3);
		while (j != c3) //Copia linha
		{
			aux = fgetc(arq2);
			fputc(aux, arq3);
			j++;
		}
		fputc(' ', arq3);
		while (j != numcol) //Percorre o resto da linha
		{
			aux = fgetc(arq2);
			j++;
		}
		i++;
		j = 0;
	}
	/***** Coloca espaços na última linha *****/
	c = 0;
	while (c != (c2-1)) //Percorre linha até a coluna desejada
	{
		aux = fgetc(arq2);
		c++;
	}
	while (c != (c3+1))
	{
		fputc(' ', arq3);
		c++;
	}
	fputc(' ', arq3);
}
/**************
	Programa Principal
**************/
int main (int argc, char **argv)
{
	/*** Declara Variáveis ***/
	int numcol; //Numero de colunas
	int l1, c1, l2, c2, l3, c3; //Coordenadas
	FILE *arq1, *arq2, *arq3;
	/*** Arquivos ***/
	arq1 = fopen(argv[1], "r+");
	if (arq1 == NULL)
	{
		printf("\nArquivo 1 inválido\n");
		return(1);
	}
	else
	{
		printf("\nArquivo 1 aberto com sucesso\n");
	}
	arq2 = fopen(argv[2], "r+");
	if (arq2 == NULL)
	{
		printf("\nArquivo 2 Inválido\n");
		return(1);
	}
	else
	{
		printf("\n Arquivo 2 aberto com sucesso \n");
	}
	arq3 = fopen("resultado.txt", "w+");
	if (arq3 == NULL)
	{
		printf("\nErro ao criar arquivo 3\n");
		return(1);
	}
	else
	{
		printf("\n  Arquivo 3 aberto com sucesso (resultado.txt) \n");
	}
	/*** Programa Começa Aqui ***/
	trataCoordenadas(argv, &l1, &l2, &l3, &c1, &c2, &c3);
	printf("\n     Coordenadas ok!\n");
	numcol = contacol(arq1);
	printf("\n     Número de colunas ok!\n");
	geraBloco(&l2, &l3, &c2, &c3);
	printf("\n     Bloco gerado com sucesso!\n");
	iniciaArq3(arq3, arq1);
	printf("\n     Arquivo 3 iniciado com sucesso\n");
	copiaBloco(arq3, arq2, numcol, c1, c2, c3, l1, l2, l3);
	printf("\n     Sucesso! Copiado em resultado.txt\n");
	return(0);
}

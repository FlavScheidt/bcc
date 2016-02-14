/*************************
	(ordfrases)  Faça um programa que receba um conjunto de frases do usuário.
	Após a entrada de todas as frases, o programa deve ordená-las lexicograficamente 
	(em ordem crescente) e apresentar o resultado na tela.
	O programa também deve tratar a opção   -r   quando passada como argumento do 
	programa. Com esta opção, o programa deve fazer a ordenação reversa.
	Use ponteiros e alocação dinâmica de memória.
*************************/
/************************
	Flaviene Scheidt de Cristo
	FSC10
	GRR20101915
************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/***************
	Funções
***************/
void Ordena(char **frases,int n)
{
	int j;
	char *temp = (char *) malloc (201*sizeof(char)); //Aloca variavel temporária usada na troca
	for (j=0;j<(n-1);j++) //Percorre todo o vetor de strings frases
	{	
		if (strcmp(frases[j], frases[j+1]) > 0) //Se a próxima frase for menor, troca as duas de lugar
		{
			strcpy(temp, frases[j]);
			strcpy(frases[j], frases[j+1]);
			strcpy(frases[j+1],temp);
		}
	}
	free(temp); //Libera o espaço alocado para a variável temporária
}
void OrdenaReverso(char **frases, int n) //Ordena de modo inverso (-r)
{
	int j;
	char *temp = (char *) malloc(201*sizeof(char));
	for (j=0; j<n; j++)
	{
		if (strcmp(frases[j], frases[j+1]) < 0)
		{
			strcpy(temp, frases[j]);
			strcpy(frases[j], frases[j+1]);
			strcpy(frases[j+1],temp);
		}
	}
	free(temp);
}
void le(char **frases, int n)
{
	int i, tam;
	for (i=0; i<n; i++)
	{
		frases[i] = (char *) malloc (201*sizeof(char)); //Aloca espaço para a frase que será inserida
		fgets(frases[i], 200, stdin); //Lê a frase da linha de comando
		tam = strlen(frases[i]);
		tam--;
		frases[tam] = '\0';
	}
}
void imprime(char **frases, int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%s \n", frases[i]);
	}
}
/***************
	Programa Principal
***************/
int main(int argc, char **argv)
{
	char **frases;
	int n;//Número de frases
	int i,j; //Contadores
	if (argv[1] == "-r") //Se -r for digitado como argumento, ordena inverso
	{
		printf("\nDigite o numero de elementos \n");
		scanf("%d", &n);
		getchar();
		frases = (char **) malloc (n*sizeof(char *));
		printf("\nDigite uma frase por Linha - até 200 caracteres \n");
		le(frases, n);
		OrdenaReverso(frases, n);
	}
	else
	{
		printf("\nDigite o numero de elementos \n");
		scanf("%d", &n);
		getchar();
		frases = (char **) malloc (n*sizeof(char *));
		printf("\nDigite uma frase por linha - até 200 caracteres\n");
		le(frases, n);
		Ordena(frases, n);
	}
	printf("\n Frases Ordenadas \n");
	imprime(frases,n);
	/* Libera espaço alocado dinamicamente */
	for (i=0; i<n; i++)
	{
		free(frases[i]);
	}
	free(frases);
	getchar();
	return(0);
}

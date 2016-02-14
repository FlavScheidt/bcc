/*************************
	(mescla)   Um programa recebe pela linha de comando nome de 2 arquivos de texto, e 3 pares de inteiros representando coordenadas (linha,caracter) em um arquivo de texto (ASCII). Exemplo:
	mescla texto-01 texto-02 19 21 3 12 8 46
	O programa deve copiar um bloco de texto do 2o arquivo no 1o arquivo, a partir da coordenada indicada no 1o par de inteiros, sobrescrevendo o conteúdo a partir desta posição. O bloco do 2o arquivo é definido pelos dois pares de coordenadas restantes. Após copiar o bloco, espaços em branco devem ser preenchidos ao redor. Finalmente, o resultado deve ser salvo em um 3o arquivo, cujo nome é arbitrário, sendo que uma mensagem final do programa deve indicar este nome.
*************************/
/************************
	Flaviene Scheidt de Cristo
	FScord1x20
	GRR20101915
************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/***************
	Funções
***************/
void ConverteArgumentos(int *coordenada, char *argumento)
{
	*coordenada = atoi(argumento);
} 
/***************
	Programa Principal
***************/
int main (int argc,char *argv[])
{
 	FILE *arquivo1, *arquivo2, *arquivo3;
	int cord1x1, cord1x2;
 	int cord2x1, cord2x2;
	int cord3x1, cord3x2;
 	int cord1,cord2;
 	char caracter;
	/* Abre arquivos */
	arquivo1 = fopen(argv[1], "r+");
	arquivo2 = fopen(argv[2], "r+");
	arquivo3 = fopen("resultado.txt", "r+");
  	if (argc < 9) //Verifica se o numero de argumento passado está correto
    	{
     		printf("\n Coordenadas Inválidas \n");
      		exit(0);
    	}
	/* Converte argumentos para inteiro */
	ConverteArgumentos(&cord1x1, argv[3]);
	ConverteArgumentos(&cord1x2, argv[4]);
	ConverteArgumentos(&cord2x1, argv[5]);
	ConverteArgumentos(&cord2x2, argv[6]);
	ConverteArgumentos(&cord3x1, argv[7]);
	ConverteArgumentos(&cord3x2, argv[8]);
	cord1 = 1;
 	cord2 = 0;
	while (cord2 != (cord1x2+1)) //Busca coordenada e joga caracteres no arquivo3
	{
		caracter = fgetc(arquivo1);
		if (caracter == '\n')
			cord1++;
		if (cord1 >= cord1x1)
			cord2++;
		fputc (caracter,arquivo3);
	}
	cord2 = 0;
	cord1 = 0;
	while (cord2 != cord2x2) //Busca coordenada
	{
		caracter = fgetc(arquivo2);
		if (caracter == '\n')
			cord1++;
		if (cord1 >= cord2x1-1)
			cord2++;	      
	}
	if (cord3x1>cord2x1) 
		cord2 = 0;
	while (cord2 != (cord3x2+1))
	{
		caracter = fgetc(arquivo2);
		fputc (caracter,arquivo3);
		if (caracter == '\n')
			cord1++;
		if (cord3x1 > cord2x1)
		{
			if(cord1 >= (cord3x1-1))
				cord2++;
		}
		else
			cord2++;
	}
	fclose (arquivo2);
	while ((caracter = fgetc(arquivo1)) != EOF)
		fputc (caracter,arquivo3);
	printf("Sucesso! Salvo em resultado.txt\n");
	fclose (arquivo1);
	fclose (arquivo3);
	}

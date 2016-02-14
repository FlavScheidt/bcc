/************************
	(mult_matrizes)  Faça um programa que leia pares de matrizes de um arquivo e calcule o produto entre elas. O resultado deve ser gravado em outro arquivo. O nome do arquivo de entrada de dados pode opcionalmente ser fornecido pela linha de comando. Caso não seja fornecido, o nome default deste arquivo é matriz.dat. O nome do arquivo de saída deve ser formado pela string res- seguida do nome do arquivo de entrada (por exemplo, res-matriz.dat).
	O arquivo de entrada (tipo ASCII) consiste de uma linha contendo a dimensão das matrizes a serem multiplicadas, seguida das duas matrizes. Exemplo:
	2 2  (dimensão do 1o conjunto de matrizes)
	1 2  (1a matriz - 2x2)
	3 7
	7 8  (2a matriz - 2x2)
	4 1
	3 2  (dimensão do 2o conjunto de matrizes)
	2 4  (1a matriz - 3x2)
	9 2
	4 3
	0 2 7  (2a matriz - 2x3)
	12 21 1
	O arquivo de saída (também do tipo ASCII) deve conter a linha com a ordem da matriz, seguida do resultado da multiplicação. O programa deve validar a entrada de dados antes de proceder aos cálculos. Use ponteiros e alocação dinâmica de memória onde for necessário e eficiente. 
************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**************
	Estruturas
**************/
typedef struct Matriz
{
	int Linhas; //Numero de linhas
	int Colunas; //Numero de colunas
	int **matriz; //Vetor de ponteiros, cada ponteiro aponta para uma linhas, ou seja, um vetor com o número de colunas
} Matriz;
/**************
	Funções
**************/
void tiraEnter(char *s)
{
	int i, cont;
	cont = strlen(s);
	for (i=0; i<=cont; i++)
	{
		if (i = cont)
		{
			s[i] = '\n';
		}
	}
}
void leArquivo() //Le do arquivo e joga na matriz por meio de fgets. Primeiro aloca espaço para uma nova estrutura no vetor de estruturas, depois joga le o tamanho da matriz e joga em matriz[i].Colunas e matriz[i].Linhas. Depois lê linha por linha, jogando no vetor, o limitador é o número de linhas. Incrementa o contador e parte para a leitura de uma nova matriz e assim por diante.
{
	
}
void inverteMatriz (Matriz matriz) //Inverte matriz para auxiliar na multiplicação - Tranforma linhas em colunas e colunas em linhas por meio de um vetor auxiliar, que guarda os valores da coluna. Os valores da linha são então tranferidos para a coluna e os valores do vetor auxiliar colocados na linha
{

}
void multiplicaMatrizes(Matriz matriz1, Matriz matriz2, Matriz matriz3) //Multiplica as matrizes levando em consideração que a segunda delas já foi invertida
{
	int cont1, cont2, cont3, cont4, i, j, res, resultado;
	cont1 = 0;
	cont2 = cont1;
	cont3 = cont2;
	cont4 = cont3;
	matriz3.Linhas = matriz1.Linhas;
	matriz3.Colunas = matriz2.Colunas;
	/***** Aloca vetores temporários para trabalhar mais facilmente com as linhas em separado *****/
	int *linha = (int *) malloc (matriz1.Colunas*sizeof(int));
	int *linha2 = (int *) malloc (matriz2.Colunas*sizeof(int));
	int *linha3 = (int *) malloc (matriz3.Colunas*sizeof(int));
	while (cont1 <= matriz1.Linhas) //Percorre todas as linhas da primeira matriz
	{
		linha = matriz1.matriz[cont1]; //Coloca a primeira linha da matriz no vetor linha
		matriz3.matriz[cont1] = (int *) malloc(matriz3.Colunas*sizeof(int)); //Aloca nova linha na matriz 3
		while (cont2 <= matriz1.Colunas) //Percorre todas as colunas da primeira matriz
		{
			i = linha[cont2];
			resultado = 0;
			while (cont3 <= matriz2.Linhas) //Percorre todas as linhas da matriz 2
			{
				linha2 = matriz2.matriz[cont3];
				while (cont4 <= matriz2.Colunas) //Percorre todas as colunas da matriz 2
				{
					j = linha2[cont4];
					res = j*i; //Faz a multiplicação dos dois elementos
					cont4++;
				}
				cont3++;
				resultado = resultado + res; //Soma todas as multiplicações feitas com aquela linha.
			}
			cont2++;
			linha3[cont2] = resultado;
		}
		matriz3.matriz[cont1] = linha3; //Coloca a linha resultado na matriz 3
	}
}
void imprimeArquivo(Matriz matriz) //Imprime resultados no arquivo
{
 	
}
/**************
	Programa Principal
**************/
main (int argc, char **argv)
{
	/***** Declarações *****/
	FILE *fp;
	int i, j;
	int numMatrizes; //Número de matrizes
	Matriz *matriz; //Vetor de matrizes
	Matriz matrizFinal;
	/***** Abre arquivo *****/
	if (argv[1] != NULL)
	{
		fp = fopen(argv[1], "r+");
	}
	else
	{
		fp = fopen("matriz.dat", "r+");
	}
	/***** Programa *****/
	leArquivo(matriz, fp, numMatrizes);
	while (i <= numMatrizes)
	{
		inverteMatriz(matriz[j]);
		multiplicaMatrizes(matriz[i], matriz[j], matrizFinal);
		imprimeArquivo (matrizFinal);
	}
}

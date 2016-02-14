/*************************
	Selection sort.
	Sua entrada deve ser um arquivo de texto de nome select.txt
	contendo o vetor a ser ordenado
*************************/
/************************
	fsc10
	jbnj09
	mfg08
************************/
#include <stdio.h>
#define TAM_VET 10000

/***************
	Declara Funções
***************/	
	int criavet(int *, FILE *); //Lê arquivo, joga no vetor e retorna o tamanho do vetor
	void selection (int *, int, int); //Organniza vetor utilizando selection sort
	void troca (int *, int *); //Troca posições
	int minimo(int *, int, int); //Encontra o menor elemento do vetor 

/**************
	Programa Principal
**************/
int main ()
{
	FILE *fp;
	int vet [TAM_VET];
	int i, tam;
	fp = fopen("select.txt", "r");
	tam = criavet(vet, fp);
	selection(vet, 0, tam);
	for (i=0; i<=tam; i++)
		printf("%d \n", vet[i]); 
}
/*************
	Funções
*************/
int criavet(int *vet, FILE *fp)
{
	int i = 0;
	while (fscanf(fp, "%d", &vet[i]) != EOF) 
        	i++;
	return i;
}
void selection (int *vet, int inicio, int fim)
{
	int menor, i;
	if (vet[inicio] >= vet[fim]) 
	{	
		return;
	}
	menor = minimo(vet, inicio, fim);
	troca(&vet[inicio], &vet[menor]);
	selection(vet, (inicio+1), fim);
}
void troca (int *inicio, int *menor)
{
	int aux;
	aux = *inicio;
	*inicio = *menor;
	*menor = aux;
	return;
}
int minimo (int *vet, int inicio, int fim)
{
	int menor, j;
	menor = vet[inicio];
	for (j=inicio; j<= fim; j++)
	{
		if(vet[j]<menor)
		menor = vet[j];
	}
	return menor;
}

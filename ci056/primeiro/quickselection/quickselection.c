/*************************
	FSC10
	JBNJ09
	MFG08
************************/
#include <stdio.h>
#define K 10
#define TAM_VET 10000;
/***************
	Funções
***************/
void quickselection (int *vet, int inicio, int fim)
{
	int meio;
	if ((fim-inicio+1) < K)
	{
		selection(vet, inicio, fim);
		return;
	}
	meio = particiona(vet, inicio, fim, vet[fim]);
	quickselection(vet, inicio, meio-1);
	quickselection(vet, meio+1, fim);
}
int particiona (int *vet, int inicio, int fim)
{
	int meio, cont, i, j, aux;
	if ((inicio-fim)%2 == 0)
	{
		meio = (inicio - fim) /2;
	}
	else
	{
		meio = (inicio - fim + 1) /2;
	}
	i = inicio;
	j = fim;
	cont ++;
	while (i < j)
	{
		while ((vet[i] <=  meio) && (i<fim))
		{
			i++;
			cont++;
		}
		while (vet[j] > meio)
		{
			j--;
			cont++;
		}
		aux = vet[j];
		vet[j] = vet[i];
		vet[i] = aux;
	}
	cont ++;
}
int criavet (int *vet, FILE *fp)
{
	int i = 1;
	fscanf(fp, "%d", &vet[i]);
	while (!feof(fp))
	{
		fscanff(fp, "%d", &vet[i]);
		i++;
	}
	i--;
	return i;
}
int minimo(int *vet, int a, int b)
{
	int menor, j;
	menor = vet[a];
	for (j=a; j<=b; j++)
	{
		if (vet[j] < menor)
		{
			menor = j;
		}
	}
	return menor;
}
void selection(int *vet, int inicio, int fim)
{
	if (inicio >= fim)
	{
		return;
	}
	menor = minimo(vet, inicio, fim);
	vet[inicio] = aux;
	vet[inicio] = vet[j];
	vet[j] = aux;
	selection(vet, inicio+1, fim);
}
/***************
	Programa Principal
***************/
int main () 
{
	FILE *fp;
	int vet[TAM_VET];
	int i, tam;
	fp = fopen("vetor.in", "r");
	quickselection(vet, 0, tam-1);
	for (i=0; i<tam; i++)
	{
		printf(fp, "%d ", vet[i]);
	}
	getchar();
	return (0);
	fclose(fp);
}

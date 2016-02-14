#include <stdio.h>
#define TAM_VET 10000
int CriaVetor (int *v)
{
	int i = 0;
	while (scanf("%d", &v[i]) != EOF)
	{
		i++;
	}
	i--;
	return i;
}
void particiona (int *v, int inicio, int fim, int pivo)
{
	printf("Entra particiona \n");
	int i = inicio;
	int j = fim;
	int contPivo = v[pivo]; 
	int aux;
	while (i != j)
	{
		while (v[i] < contPivo)
			i++;
		while (v[j] > contPivo)
			j--;
		printf("Troca \n");
		aux = v[j];
		v[j] = v[i];
		v[i] = aux;
	}
}
void quick (int *v, int inicio, int fim)
{
	printf("Entra quick \n");
	int pivo;
	if (inicio < fim)
	{
		if ((inicio+fim)%2 == 0)
			pivo = (inicio+fim)/2;
		else
			pivo = (inicio+fim+1)/2;

		particiona(v, inicio, fim, pivo);
		quick(v, inicio, pivo-1);
		quick(v, pivo+1, fim);
		return;
	}
}

int main ()
{
	int v[TAM_VET];
	int i, tam;
	tam = CriaVetor(v);
	quick(v, 0, tam);
	for (i = 0; i<=tam; i++)
	{
		printf("%d \n", v[i]);
	}
}

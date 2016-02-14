#include <stdio.h>
#define TAM_VET 10000

int criavet (int *vet)
{
	int i;
	i = 0;
	while (scanf("%d", &vet[i]) != EOF)
	{
		i++;
	}
	i--;
	return i;
}
void troca (int *inicio, int *menor)
{
	int aux;
	aux = *inicio;
	*inicio = *menor;
	*menor = aux;
}
void selection (int *vet, int inicio, int fim)
{
	int menor, i, NovoInicio;
	if (inicio >= fim)
	{
		return;
	}
	menor = minimo(vet, inicio, fim);
	troca(&vet[inicio], &vet[menor]);
	NovoInicio = inicio+1;
	selection(vet, NovoInicio, fim);
}
int minimo (int *vet, int inicio, int fim)
{
	int i, menor;
	i = 0;
	menor = 0;
	for (i=0; i<=fim; i++)
	{
		if (vet[i] < vet[menor])
		{
			menor = i;
		}
	}
	printf("%d, %d", menor, vet[menor]);
	return menor;
}
int main()
{
	int vet[TAM_VET];
	int tam, i;
	tam = criavet(vet);
	selection(vet, 0, tam);
	for (i=0; i<=tam; i++)
	{
		printf("\n %d \n", vet[i]);
	}
}

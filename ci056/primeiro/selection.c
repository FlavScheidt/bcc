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
void selection(int *inicio, int tam)
{
	int i, menor = 0, temp, temp_index;
	if (tam == 0)
		return;
	for(i = 0; i < tam; i++)
	{
		if (*(inicio+i) < menor)
		{
			menor = *(inicio+i);
			temp_index = i; 
		}
	}
	temp = *(inicio+tam-1);
	*(inicio+temp_index) = temp;
	*(inicio+tam-1) = menor;
	selection(inicio, --tam);
}
int main()
{
	int vet[TAM_VET];
	int tam, i;
	tam = criavet(vet);
	selection(&vet[0], tam);
	for (i=0; i<=tam; i++)
	{
		printf("\n %d \n", vet[i]);
	}
}

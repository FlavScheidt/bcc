#include<stdio.h>
#include<stdlib.h>
char * Troca (char *vetor, int posicao)
{
	char aux;
	printf("\n-----------------------\n");
	aux = vetor[posicao];
	printf("aux = %c\n", aux);
	vetor[posicao] = vetor[posicao-1];
	printf("posicao = %c\n", vetor[posicao]);
	vetor[posicao-1] = aux;
	printf("posicao - 1 = %c\n", vetor[posicao-1]);
	getchar();
	return vetor;
}
int main ()
{
	int max = 16;
	int i;
	char *tentativa = malloc (4*sizeof(char));
	for (i = 0; i < 4; i++)
	{
		tentativa[i] = 'A'+i;
	}
	int posicao = 3;
	for (i = 0; i <= max; i++)
	{
		tentativa = Troca(tentativa, posicao);
		if (posicao == 1)
		{
			posicao = 3;
		}
		else
		{
			posicao--;
		}
		printf("%s\n", tentativa);
	}
	free(tentativa);
}

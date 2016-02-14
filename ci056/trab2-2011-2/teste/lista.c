#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "lista.h"
fila * ConstroiFila(void)
{
    fila *f = malloc (sizeof(fila));
    if (!f)
    	return NULL;
    f->tam = 0;
    f->primeiro = NULL;
    return f;
}
void RetiraPrimeiro(fila *f)
{
	conteiner *aux = f->primeiro;
	f->primeiro = aux->proximo;
	f->tam--;
	return;
}
int PatioVazio(int **patio)
{
	int i;
	for (i=0; i<5; i++)
	{
		if (patio[i] != NULL)
			return 0;
	}
	return 1;
}
int BuscaConteiner(int **patio)
{
	int i = 0, indice = 0;
	conteiner *aux = NULL;
	conteiner critico;
	memset(&critico,0,sizeof(conteiner));
	for(i=0; i<5; i++)
	{
		aux = (conteiner*)patio[i];
		if(aux != NULL)
		{
			if (aux->aduana > critico.aduana)
			{
				critico.aduana = aux->aduana;
				indice = i;
			}
		}
	}
	return indice;
}
void InsereFila(conteiner *c, fila *f)
{
	conteiner *aux = NULL;
    	if (!c)
		return;
    	if (f->tam == 0)
        	f->primeiro = c;
    	else
    	{
    		aux = f->primeiro;
    		while(aux->proximo != NULL)
    		aux = aux->proximo;
    		aux->proximo = c;
    	}
    	f->tam++;
}

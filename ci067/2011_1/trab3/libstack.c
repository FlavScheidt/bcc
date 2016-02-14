#include <stdio.h>
#include <string.h>
#include "libstack.h"
/************************
	OBS.:
	1 - O topo da pilha é sempre a maior posição ocupada
************************/
/***************
	Inicia Pilha
***************/
void IniciaPilha(Pilha *Stack)
{
	Stack = (Pilha *) malloc (sizeof(Pilha)); // Aloca espaço para uma nova pilha
	Stack -> pilha[0] = malloc (float *) (sizeof(float));
	Stack -> topo = Stack -> pilha[0]; //Topo da pilha
	Stack -> tamanho = 0; //Incia o tamanho da pilha
}
/**************
	Verifica se a Pilha está vazia
**************/
int Vazia(Pilha *Stack)
{
	if (Stack -> tamanho == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
/**************
	Empilha dado
**************/
void Empilha(Pilha *Stack. float dado)
{
	int i; //Variável auxiliar
	Stack -> tamanho++;
	i = Stack -> tamanho;
	Stack -> pilha[i] = (float *) realloc (tamanho*sizeof(float) + sizeof(float)); //Aloca novo nodo
	Stack -> pilha[i] = dado; //Coloca dado no novo nodo
	Stack -> topo = Stack -> pilha[i]; //Aponta o topo da pilha, ou seja, o novo nodo
}
/**************
	Desempilha dado (joga em uma variável de retorno e deleta da pilha)
**************/
float Desempilha(Pilha *Stack, float dado)
{
	int i; //Variável auxiliar
	i = Stack -> tamanho;
	dado = Stack -> pilha[i]; //Salva o dado na variável de retorno
	Stack -> topo = Stack -> pilha[i -1]; //Abaixa o topo da pilha
	free(Stack -> pilha[i]); //Libera o espaço
	Stack -> tamanho--;
	return(dado);
	}
}
/**************
	Desaloca
**************/
void Desaloca (Pilha *Stack)
{
	free (Stack -> pilha);
	free(Stack);
}

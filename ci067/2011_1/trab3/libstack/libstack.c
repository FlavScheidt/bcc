#include <stdio.h>
#include <stdlib.h>
#include "libstack.h"
void IniciaPilha (estruturaPilha *Pilha);
{
	Pilha -> Topo = (estruturaNodo *) malloc (sizeof(estruturaNodo)); //Aloca novo nodo
	Pilha -> Topo -> Prox = NULL; //Aponta ponteiro para NULL
	Pilha -> Tamanho = 0;
	return;
}
int Vazia (estruturaPilha *Pilha) //Verifica se a pilha está vazia
{
	if (Pilha -> Tamanho == 0)
		return 0;
	else
		return 1;
}
void Empilha (estruturaDados Dado, estruturaPilha *Pilha)
{
	estruturaNodo *novoNodo; //Cria um nodo
	novoNodo = (estruturaNodo *) malloc (sizeof(estruturaNodo)); //Aloca nodo
	Pilha -> Topo -> Dados = Dado; //Coloca dados no nodo cabeça
	novoNodo -> Prox = Pilha -> Topo; //Faz o novo nodo apontar para o nodo cabeça
	Pilha -> Topo = novoNodo; //Faz o topo apontar para o novo nodo, que se torna o nodo cabeça
	Pilha -> Tamanho ++;
	return;
}
void Desempilha (estruturaPilha *Pilha, estruturaDados *Retorno)
{
	estruturaNodo *aux;
	if (Vazia(*Pilha))
	{
		printf("Erro: Lista Vazia");
	}
	else
	{
		aux = Pilha > Topo; //Salva o topo da pilha
		Pilha -> Topo = aux -> Prox; //Faz o topo da pilha apontar para o próximo item
		*Retorno = aux -> Prox -> Dados; //Pega os dados do nodo a ser desempilhado e salva na estrutura de retorno
		free(aux); //Libera espaço do apontador auxilixar
		Pilha -> Tamanho--;
	}
	return;
}

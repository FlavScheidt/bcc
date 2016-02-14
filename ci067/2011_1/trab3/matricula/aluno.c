#include "main.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
aluno * InsereAluno(int id, char *nome, aluno * lista) //Insere aluno no topo da lista
{
	aluno *p; 
	if((p = (aluno *)malloc(sizeof(aluno))) == NULL) { //Se não puder alocar espaço, retorna erro
		fprintf(stderr, "Voce nao dispoe de memoria suficiente\n");
		exit(2);
	}
	p->nome = nome; //Coloca os dados no novo nodo
	p->id = id;
	p->next = lista;
	return(p);
}
aluno * RemoveAluno(int id, aluno *lista) //Remove aluno da lista
{
	aluno *r, *p, *anterior;
	r = lista;
	p = anterior = lista;
	/***** Busca Matrícula a remover *****/
	while(p != NULL) {
		/* Achou matricula a remover */
		if(p->id == id) {
			anterior->next = p->next; //Faz nodo anterior apontar para o próximo, retirando o nodo atual da lista
			if(p == anterior)
				r = p->next; 
			free(p->nome); //Libera espaço alocado
			free(p);
			return(r);
		}
		anterior = p;
		p = p->next; // Percorre a lista
	}
	return(r);
}
aluno * DestroiAlunos (aluno *p) //Destroi lista de alunos
{
	while(p != NULL) //Percorre a lista removendo nodo por nodo
		p = RemoveAluno(p->id, p);
	return(p);
}
aluno * ProcuraAluno (aluno *lista, int id) //Procura aluno na lista
{
	aluno *p;
	p = lista;
	while(p != NULL) { //Percorre a lista
		if(p->id == id) //Se o ID atual for igual ao buscado, retorna
			return(p);
		p = p->next;
	}
	return(NULL);
}

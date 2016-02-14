#include "main.h"
#include "matricula.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
matricula * InsereMatricula(char *codigo, int id, matricula * lista) //Insere matrícula
{
	matricula *p;
	if((p = (matricula *)malloc(sizeof(matricula))) == NULL) //Verifica se tem memória para alocar
	{
		fprintf(stderr, "Voce nao dispoe de memoria suficiente\n");
		exit(2);
	}
	/***** Coloca informações no nodo *****/
	p->codigo = codigo;
	p->id = id;
	p->nota1 = INDISP;
	p->nota2 = INDISP;
	p->next = lista;
	return(p);
}
matricula * RemoveMatricula(char *codigo, int id, matricula * lista) //Remove matrícula da lista
{
	matricula *r, *p, *anterior;
	r = lista;
	p = anterior = lista;
	while(p != NULL) {
		/* Achou matricula a remover */
		if((strcmp(p->codigo, codigo) == 0) && p->id == id) {
			anterior->next = p->next;
			if(p == anterior)
				r = p->next;
			free(p->codigo);
			free(p);
			return(r);
		}
		anterior = p;
		p = p->next;
	}
	return(lista);
}
matricula * DestroiMatriculas(matricula *p) //Destroi lista de matrículas
{
	while(p != NULL)
		p = RemoveMatricula(p->codigo, p->id, p);
	return(p);
}
matricula * ProcuraMatricula(matricula *lista, int id, char *codigo) //Busca matrícula
{
	matricula *p;
	p = lista;
	while(p != NULL) {
		if(p->id == id && strcmp(p->codigo, codigo) == 0)
			return(p);
		p = p->next;
	}
	return(NULL);
}
int EstaMatriculado(int id, matricula *lista) //Veirfica se o aluno está matriculado em algo
{
	matricula *p;
	p = lista;
	while(p != NULL) {
		if(p->id == id)
			return(1);
		p = p->next;
	}
	return(0);
}
int AlteraNotas(matricula *lista, int id, char *codigo, int nota1, int nota2) //Altera as notas de um aluno
{
	matricula *p;
	p = ProcuraMatricula(lista, id, codigo);
	if(p == NULL)
		return(0);
	p->nota1 = nota1;
	p->nota2 = nota2;
	return(1);
}

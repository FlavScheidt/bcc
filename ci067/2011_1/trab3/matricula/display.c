#include "main.h"
#include "display.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ImprimeMenu() //Imprime o menu
{
	printf("\nMENU:\n");
	printf("0 - Sair\n");
	printf("1 - Inserir aluno\n");
	printf("2 - Remover aluno\n");
	printf("3 - Inserir matricula\n");
	printf("4 - Remover matricula\n");
	printf("5 - Alterar notas\n");
	printf("6 - Consultar aluno\n");
	printf("7 - Consultar matricula\n");
	printf("8 - Carregar do arquivo\n");
	printf("9 - Salvar\n");
	printf("\n");
}
void ImprimeAluno(aluno *p) //Imprime informações sobre um aluno
{
	printf("Nome: %s\nID: %d\n", p->nome, p->id);
}
void ImprimeNotas(matricula *p) //Imprime as notas de um aluno x
{
	if(p->nota1 != INDISP) //Se a nota não estiver indisponível, não imprime nada
		printf("Nota 1: %f\n", p->nota1);
	else
		printf("Nota 1: Indisponivel\n");
	if(p->nota2 != INDISP)
		printf("Nota 2: %f\n", p->nota2);
	else
		printf("Nota 2: Indisponivel\n");
}
int ConsultaAluno(int id, aluno *alunos, matricula *matriculas) //Imprime informações sobre um aluno e suas matrículas
{
	aluno *a;
	matricula *m;
	a = ProcuraAluno(alunos, id); //Procura o aluno
	if(a == NULL) { //Se o retorno da função anteior for null, imprime mensagem de erro
		printf("Aluno nao existe.\n");
		return(0);
	}
	ImprimeAluno(a); //Imprime as informações gerais do aluno
	printf("Matriculado em:\n"); //Imprime matrículas
	for(m = matriculas; m != NULL; m = m->next) {
		if(m->id == id) {
			printf("Disciplina: %s\n", m->codigo);
			ImprimeNotas(m);
		}
	}
}
int ConsultaDisciplina(char *codigo, aluno *alunos, matricula *matriculas) //Imprime lista de alunos matriculados em uma disciplina x
{
	aluno *a;
	matricula *m;
	printf("Disciplina %s:\n", codigo);
	/***** Busca disciplina *****/
	for(m = matriculas; m != NULL; m=m->next)
		if(strcmp(m->codigo, codigo) == 0)
		{
			a = ProcuraAluno(alunos, m->id);
			if(a == NULL)
				continue;
			ImprimeAluno(a);
			ImprimeNotas(m);
		}
}

/************************ 
	(matricula)  Faca um programa que controle a matricula de alunos em
	disciplinas. Cada aluno tem um numero de dentificacao ID (1 <=  ID <=
	100.000) e um nome (maximo de 100 caracteres). Cada matricula contem o
	ID do aluno, o codigo da disciplina (5 caracteres), e as duas notas de
	avaliacao P1 e P2  (0,0 <= P1,P2 <= 10,0) naquela disciplina. Se a nota
	ainda nao esta disponivel, seu valor e -1.  O programa deve permitir
	a insercao e remocao de alunos e matriculas, bem como a insercao e
	alteracao de notas. Um aluno somente pode ser removido se nao estiver
	matriculado em nenhuma disciplina. A remocao e alteracao de notas se
	fazem com a indicacao do ID de um aluno e do codigo da disciplina. O
	usuario deve ser capaz de consultar a lista de matriculas completa,
	por disciplina ou por aluno.
************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "aluno.h"
#include "matricula.h"
#include "display.h"
/**************
	Programa Principal
**************/
int main(int argc, char **argv)
{
	/***** Declaração de variáveis, listas e arquivos *****/
	FILE *fp;
	int i, id, c;
	float nota1, nota2;
	char codigo[MAXCOD];
	char nome[MAXNOM];
	char buf[MAXB];
	aluno *a, *alunos = NULL; //Inicia a lista de alunos
	matricula *m, *matriculas = NULL; //Inicia a lista de matriculas
	do // Enquanto c não for digitado, continua imprimindo o menu
	{
		ImrpimeMenu();
		scanf("%d%*c", &c);
		switch(c)
		{
			case 0:
				break;
			case 1: //Insere aluno
				printf("Digite a ID do aluno: ");
				scanf("%d%*c", &id);
				printf("Digite o nome do aluno: ");
				fgets(nome, MAXNOM, stdin);
				TiraEnter(nome);
				alunos = InsereAluno(id, strdup(nome), alunos);
				break;
			case 2: //Remove aluno
				printf("Digite a ID do aluno: ");
				scanf("%d%*c", &id);
				if(!EstaMatriculado(id, matriculas)) //Se o aluno estiver matriculado, não pode removê-lo
					alunos = RemoveAluno(id, alunos);
				else
					fprintf(stderr, "Aluno esta matriculado\n");
				break;
			case 3: //Insere matrícula
				printf("Digite o codigo da disciplina: ");
				fgets(codigo, MAXCOD, stdin);
				remove_pulo(codigo);
				printf("Digite a ID do aluno: ");
				scanf("%d%*c", &id);
				matriculas = inserir_matricula(strdup(codigo), id, matriculas);
				break;
			case 4: //Remove Matricula
				printf("Digite o codigo da disciplina: ");
				fgets(codigo, MAXCOD, stdin);
				remove_pulo(codigo);
				printf("Digite a ID do aluno: ");
				scanf("%d%*c", &id);
				matriculas = RemoveMatricula(codigo, id, matriculas);
				break;
			case 5: //Altera notas
				printf("Digite o codigo da disciplina: ");
				fgets(codigo, MAXCOD, stdin);
				TiraEnter(codigo);
				printf("Digite a ID do aluno: ");
				scanf("%d%*c", &id);
				printf("Digite a Primeira Nota: ");
				scanf("%f%*c", &nota1);
				printf("Digite a Segunda Nota: ");
				scanf("%f%*c", &nota2);
				AlterarNotas(matriculas, id, codigo, nota1,nota2);
				break;
			case 6:	//Procura aluno
				printf("Digite a ID do aluno: ");
				scanf("%d%*c", &id);
				ConsultaAlunos(id, alunos, matriculas);
				break;
			case 7:	//Procura alunos matrículados em uma disciplina
				printf("Digite o codigo da disciplina: ");
				fgets(codigo, MAXCOD, stdin);
				TiraEnter(codigo);
				ConsultaDisciplina(codigo, alunos, matriculas);
				break;
			case 8: //Carrega de um arquivo
				DestroiAlunos(alunos);
				DestroiMatriculas(matriculas);
				/***** Carrega alunos a partir do arquivo alunos.sav *****/
				if((fp = fopen("alunos.sav", "r")) == NULL) //Se houver algum erro ao carregar o arquivo, retorna erro
				{{
					fprintf(stderr, "Impossivel carregar\n");
					break;
				}
				do
				{
					fgets(nome, MAXNOM, fp);
					TiraEnter(nome);
					fscanf(fp, "%d%*c", &id);
					alunos = InsereAluno(id, strdup(nome),alunos);
				} while(!feof(fp));
				close(fp);
				/***** Carrega matriculas a partir do arquivo matriculas.sav *****/
				if((fp = fopen("matriculas.sav", "r")) == NULL) 
				{
					fprintf(stderr, "Impossivel carregar\n");
					break;
				}
				do {
					fgets(codigo, MAXCOD, fp);
					remove_pulo(codigo);
					fscanf(fp, "%d%*c", &id);
					fscanf(fp, "%f%*c", &nota1);
					fscanf(fp, "%f%*c", &nota2);
					matriculas = InsereMatricula(strdup(codigo), id, matriculas);
					AlteraNotas(matriculas, id, codigo,nota1, nota2);
				} while(!feof(fp));
				close(fp);
				break;
			case 9:
				a = alunos;
				/***** Salva lista de alunos no arquivo alunos.sav *****/
				if((fp = fopen("alunos.sav", "w")) == NULL)
					fprintf(stderr, "Impossivel salvar\n");
				else 
					while(a)
					{
						fprintf(fp, "%s\n", a->nome);
						fprintf(fp, "%d\n", a->id);
						a=a->next;
					}
				close(fp);
				m = matriculas;
				/***** Salva matriculas no arquivos matriculas.sav *****/
				if((fp = fopen("matriculas.sav", "w")) == NULL)
					fprintf(stderr, "Impossivel salvar\n");
				else 
				while(m)
				{
					fprintf(fp, "%s\n", m->codigo);
					fprintf(fp, "%d\n", m->id);
					fprintf(fp, "%f\n", m->nota1);
					fprintf(fp, "%f\n", m->nota2);
					m=m->next;
				}
				close(fp);
				break;
			default: //Qualquer outra opcao digitada retorna erro
				fprintf(stderr, "Opcao invalida\n");
				break;
		}
	} while(c);
	DestroiAlunos(alunos); //Destroi lista de alunos
	DestroiMatriculas(matriculas); //Destroi matrículas
	return(0);
}
void TiraEnter(char *s) //Remove o \n das strings lidas com fgets
{
	while(*s != '\0' && *s != '\n')
		s++;
	*s = '\0';
	}


#include <stdio.h>
#include <string.h>

/***************
	Estruturas
***************/
typedef struct estruturaDados //Dados contidos nos nodos
{
	int ID;
	char *nome;
	char  disciplina[5];
	float *notas;
	char *verificador, *verificador2;
}estruturaDados;
typedef struct estruturaNodo //Estrutura de cada nodo
{
	estruturaDados dados;
	struct estruturaNodo *prox;
}estruturaNodo;
typedef struct estruturaLista //Estrutura da lista
{
	estruturaNodo *primeiro;
	estruturaNodo *ultimo;
	int tamanho;
}estruturaLista;
/***************
	Funções
**************/
void CriaLista (estruturaLista *Alunos, estruturaNodo *Nodo) //Cria uma lista
{

	Alunos -> primeiro = *Nodo; //Faz o primeiro apontar para o nodo cabeça
	Alunos -> ultimo = Alunos -> primeiro;
	Alunos -> tamanho = 0;
	Nodo -> prox = NULL;
}
estruturaLista* PreencheLista (FILE *matriculas, estruturaLista *Alunos) //Pega as informações do arquivo e joga na lista
{
	char *ID, *nome, *disciplina, *verificador, *verificador2, *p1, *p2;
	Alunos -> ultimo -> dados = (estruturaDados *) malloc (sizeof(estruturaDados)); //Aloca espaço para os dados
	/*** Pega dados do arquivo */
	fgets(*ID, 8*sizeof(char), *matriculas);
	fgets(*nome, 102*sizeof(char), *matriculas);
	fgets(*disciplina, 7*sizeof(char), *matriculas);
	fgets(*verificador, 5*sizeof(char), *matriculas);
	Alunos -> ultimo -> dados -> verificador = *verificador;
	/*** Verifica se há notas ou não para ler ***/
	if (verificador == "sim\n") //Modificar para trabalhar com pilha
	{
		fgets(*p1, 4*sizeof(char), *matriculas);
		Alunos -> ultimo -> dados -> notas[0] = p1;
	}
	fgets(*verificador2, 5*sizeof(char), *matriculas);
	Alunos -> ultimo -> dados -> verificador2 = *verificador2;
	if (verificador2 == "sim\n")
	{
		fgets(*p2, 4*sizeof(char), *matriculas);
		Alunos -> ultimo -> dados -> notas[1] = p2;
	}
	/*** Joga no arquivo ***/
	Alunos -> ultimo -> dados -> ID = *ID;
	Alunos .-> ultimo -> dados -> nome = *nome;
	Alunos -> ultimo -> dados -> disciplina = *disciplina;
	/*** Manipula os ponteiros ***/
	estruturaNodo *Novo = (estruturaNodo *) malloc (sizeof(estruturaNodo));
	Alunos -> ultimo -> prox = *Novo;
	Novo -> prox = NULL;
	return (Alunos);
}
estruturaLista* Insercao (estruturaLista *Alunos) //Procedimento para inserção de novos alunos na lista
{
	printf("\nInsira o nome do aluno\n");
	fgets(*nome, 102*sizeof(char), stdin);
	Alunos -> ultimo -> dados -> nome = *nome;
	printf("\nInsira a ID do aluno\n");
	fgets(*ID, 8*sizeof(char), stdin);
	Alunos -> ultimo -> dados -> ID = *ID;
	printf("\nInsira o código da disciplina ou aperte enter se desejar inserir a disciplina depois\n");
	fgets(*disciplina, 4*sizeof(char), stdin);
	Alunos -> ultimo -> dados -> disciplina = *disciplina;
	printf("\nDeseja inserir as notas?\n");
	fgets(*verificador, 5*sizeof(char), stdin);
	tolower(*verificador); //Converte para minusculas, para fazer a verificação mais facilmente
	Alunos -> ultimo -> dados -> verificador = *verificador;
	if (verificador == "sim\n")
	{
		printf("\nInsira a P1\n");
		fgets(*p1, 4*sizeof(char), stdin);
		Alunos -> ultimo -> dados -> notas[0] = *p1;
		printf("Deseja inserir a P2?");
		fgets(*verificador2, 5*sizeof(char), stdin);
		tolower(*verificador2);
		Alunos -> ultimo -> dados -> verificador2 = *verificador2;
		if (verificador2 == "sim\n") // Modificar para trabalhar com pilha
		{
			printf("\nInsira a P2\n");
			fgets(*p2, 5*sizeof(char), stdin);
			Alunos -> ultimo -> dados -> notas[1] = *p2;
		}
	}
	return(Alunos);
}
void PreencheArquivo (FILE *matriculas, estruturaLista *Alunos) //Joga lista para o arquivo
{
	rewind(*matriculas); //"Rebobina" o arquivo, para sobescrever a lista anterior
	estruturaNodo *apontador; //Ponteiro auxiliar que irá percorrer a lista jogando os dados dos nodos para os arquivos
	for (apontador = Alunos -> primeiro; apontador != NULL; apontador = apontador -> prox)
	{
		fprintf(matriculas, "%s", apontador -> dados -> ID);
		fprintf(matriculas, "%s", apontador -> dados -> nome);
		fprintf(matriculas, "%s", apontador -> dados -> disciplina);
		fprintf(matriculas, "%s", apontador -> dados -> verificador);
		if (apontador -> verificador == "sim\n") // Modificar para trabalhar com pilha
		{
			fprintf(matriculas, "%s", apontador -> notas[0]);
			fprintf(matriculas, "%s", apontador -> verificador2);
			if (apontador -> verificador2 == "sim\n")
			{
				fprintf(matriculas, "%s", apontador -> notas[1]);
			}
		}
	}
	printf("\n Registros salvos com sucesso \n");
}
void ImprimeNodo(estruturaNodo *nodo)
{
	printf("---------------------------------");
	printf("Nome: ");
	printf("%s", nodo -> dados -> nome);
	printf("ID: ");
	printf("%s", nodo -> dados -> ID);
	printf("Disciplina: ");
	printf("%s", nodo -> dados -> disciplina);
	if (nodo -> dados -> verificador == "sim\n")
	{
		printf("Notas: ");
		printf("%s ", nodo -> dados -> notas[0]);
		if (nodo -> dados -> verificador2 == "\nsim")
		{
			printf("%s ", nodo -> dados -> notas[1]);
		}
	}
	printf("---------------------------------");
}
void RemoveAluno(estruturaNodo *nodo, int cont, estruturaLista *Alunos)
{
	estruturaNodo *apontador;
	int i = 0;
	apontador = Alunos -> primeiro;
	do
	{
		i++;
		apontador = apontador -> prox;
	}
	while (i<cont);
	apontador-> prox = nodo -> prox;
	free(nodo);
}
/*void EditaNota (estruturaNodo *nodo); //Edita as notas (precisa usar pilha)
{

}
void InsereNota (estruturaNodo *nodo); //Insere notas (precisa usar pilha)
{

}*/
void BuscaNome (estruturaLista *Alunos)
{
	estruturaNodo *apontador;
	int encontrou = 0;
	char *busca;
	printf("\nInsira o nome que deseja buscar\n");
	fgets(*busca, 102*sizeof(char), stdin);
	for (apontador = Alunos -> primeiro; apontador != NULL; apontador = apontador -> prox) //Percorre a lista buscando as entradas indicadas
	{
		if (strstr(apontador -> dados -> nome, busca))
		{
			ImprimeNodo(apontador);
			encontrou = 1;
		}
	}
	if (encontrou == 0)
	{
		printf("\nNenhum registro encontrado\n");
	}
}
void BuscaDisciplina (estruturaLista *Alunos)
{
	estruturaNodo *apontador;
	int encontrou = 0;
	char *busca;
	printf("\nInsira o código da disciplina que deseja buscar\n");
	fgets(*busca, 8*sizeof(char), stdin);
	for (apontador = Alunos -> primeiro; apontador != NULL; apontador = apontador -> prox)
	{
		if (strstr(apontador -> dados -> disciplina, busca))
		{
			ImprimeNodo(apontador);
			encontrou = 1;
		}
		if (encontrou == 0)
		{
			printf("\nNenhum registro encontrado\n");
		}
	}
}
void BuscaId (estruturaLista *Alunos) //Busca por ID. Como o ID é único, apenas um aluno será mostrado
}
	estruturaNodo *apontador;
	int encontrou = 0;
	char *busca;
	int cont = 0;
	printf("\nInsira a ID do aluno que deseja buscar\n");
	fgets(*busca, 4*sizeof(char), stdin);
	apontador = Alunos -> primeiro;
	while ((encontrou = 0) || (cont <= Alunos -> tamanho)) 
	{
		cont ++;
		if (strstr(apontador -> dados -> ID, busca))
		{
			ImprimeNodo(apontador);
			encontrou = 1;
		}
	}
	apontador = apontador -> prox;
	if (encontrou == 0)
	{
		printf("\nNenhum registro encontrado\n");
	}
	else
	{
		printf("\nDigite D para deletar o aluno, N para editar as notas, I para inserir as notas e S se não deseja executar nenhuma ação\n");
		switch (opcao)
		{
			case 'D':
			{
				cont --;
				RemoveAluno(apontador, cont, Alunos);
				break;
			}
			case 'N':
			{
				EditaNota(apontador);
				break;
			}
			case 'I':
			{
				InsereNota(apontador);
				break;
			}
			case 'S':
			{
				break;
			}
		}			
	}
}
/**************
	Programa Principal
**************/
main ()
{
	/********** Inicia Arquivo **********/
	FILE *matriculas;
	fopen(matriculas, "r+");
	/********** Inicia Lista **********/
	*Alunos = (estruturaLista *) malloc (sizeof(estruturaLista)); //Aloca espaço para a lista
	*Nodo = (estruturaNodo *) malloc (sizeof(estruturaNodo)); //Aloca nodo cabeça
	CriaLista(Alunos, Nodo);
	PreencheLista(matriculas, Alunos);
	/********** Menu **********/
	char opcao;
	while (opcao != 'Q')
	{
		printf("-----------------------------");
		printf("A - Inserir Aluno");
		printf("B - Buscar aluno por nome");
		printf("C - Editar ou Remover aluno");
		printf("D - Buscar disciplina");
		printf("Q - Sair");
		printf("-----------------------------");
		switch (opcao)
		{
			case 'A'
			{
				Insercao(Alunos);
				break;
			}
			case 'B'
			{
				BuscaNome(Alunos);
				break;
			}
			case  'C'
			{
				BuscaID(Alunos);
				break;
			}
			case 'D'
			{
				BuscaDisciplina(Alunos);
				break;
			}
		}
	}
	PreencheArquivo(matriculas, Alunos);
	fclose(matriculas);
}

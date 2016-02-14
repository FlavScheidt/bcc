/*************************
	(agenda)  Integre as soluções dos programas grava_agenda e ler_agenda da lista #4 (exercícios 8 e 9) em um único programa, de forma que ao usuário seja possível inserir ítens na agenda, consultar endereços dado um NOME e salvar os dados em qualquer momento. O programa só termina se for digitada a letra Q para sair do programa. Além disso, não deve mais existir quaisquer limites na quantidade de ítens na agenda.
*************************/
/*************************
	Flaviene Scheidt de Cristo
	FSC10
	GRR20101915
*************************/
/************************
	Comentários gerais:
	Programa utiliza lista encadeada
	Problema: escreve errado no arquivo (porque?)
************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/***************
	Declaração da estrutura
***************/
typedef struct lista { //Define a lista encadeada
	char nome[50]; 
	char disciplina[5]; 
	float *notas;
	struct lista* prox; //Ponteiro para a próxima posição
} Lista;
/**************
	Funções
**************/
void tiraEnter(char *elemento) //Tira o \n das strings lidas com fgets
{
	int tam;
	tam = strlen(elemento);
	elemento[tam-1] = '\0'; //Coloca \0 no lugar do \n
}
Lista* inicializa() //Inicializa e retorna a lista
{
	return NULL; 
}
void copiaLista (Lista *l, FILE *registro, int *numContato) //Copia o que está no arquivo e insere na lista
{
	int controle = 0;
	for (controle = 0; controle<*numContato; controle++)
	{
		Lista* novo = (Lista*) malloc (1*sizeof(Lista*)); //Aloca novo nodo na lista
		fgets(novo-> nome, 52*sizeof(char), registro);
		tiraEnter(novo->nome);
		fgets(novo->disciplina, 7*sizeof(char), registro);
		tiraEnter(novo->disciplina);
		fgetc(registro);
		novo -> prox = l;
	}
}
Lista* insere (Lista *l, FILE *registro) //Insere na lista
{
	Lista  *novo = (Lista *) malloc(1*sizeof(Lista *));//Aloca um novo nodo na lista
	/***** Inicia leitura *****/
	printf("\nNome: \n");
	fgets (novo -> nome, 52*sizeof(char), stdin);
	tiraEnter(novo -> nome);
	printf("Disciplina: \n");
	fgets (novo -> disciplina, 7*sizeof(char), stdin);
	tiraEnter (novo -> disciplina);
	novo -> prox = l;
	/***** Joga para o Arquivo *****/
	fprintf(registro, "%s", novo -> nome);
	fprintf(registro, "%s", novo -> disciplina);
	return novo;
}
void imprime_tudo(Lista* l) //Imprime todos os dados
{
	Lista* p;
	if (l == NULL)
	{
		printf("-------------------------");
		printf("\nErro 102 - Registro vazio! \n");
		printf("-------------------------");
	}
	else
	{
		for (p=l; p != NULL; p=p->prox)
		{    
			printf("---------------------------------------------\n");
			printf(" Nome: %s\n", p->nome);
			printf(" Disciplina: %s\n", p->disciplina);
			printf("---------------------------------------------\n\n");
		}
	}
	printf("\nTecle q para retornar ao menu\n");
	getchar();
}
int vazia (Lista* l) //Retorna um se a lista está vazia e zero se não está
{
	if (l == NULL)
		return 1;
	else
		return 0;
}
void busca (Lista* l) //Busca por nome, encontra pedaços dentro da string
{
	char chave[51];
	int achado, count;
	count = 0;
	Lista* p;
	p = l; 
	achado = 0;
	system("clear");
	printf("----------------------------------\n");
	printf("Digite o nome a ser buscado\n");
	printf("----------------------------------\n");
	fgets (chave, 51*sizeof(char), stdin);
	tiraEnter(chave);
	for (p = l; p != NULL; p = p -> prox) //Percorre a lista
	{
		if (strstr(p -> nome, chave) != NULL)//Se a chave estiver contida em p -> nome, retorna verdadeiro
		{
			achado = 1;
			count++;
		}
		if (achado == 1) //Se achar, imprime
		{
			printf("---------------------------------------\n");
			printf(" Nome: %s\n", p->nome);
			printf(" Disciplina: %s\n", p->disciplina);
			printf("---------------------------------------\n");
			achado = 0;
		}	  
	}
	if (count == 0)
	{
		printf("--------------------------------------------------\n");
		printf("Não encontrado. Pressione enter para continuar.\n");
		printf("--------------------------------------------------\n");
	}
}
char imprime_menu() //Imprime o menu
{
	char opc;
	system("clear");
	printf("  O que deseja fazer?\n");
	printf("-------------------------------------------\n");
	printf("i - Inserir aluno\n");
	printf("b - Buscar aluno\n");
	printf("p - Imprimir lista\n");
	printf("q - Sair\n");
	printf("-------------------------------------------\n");
	opc = getchar();
	getchar();
	return opc;
}
/***************
	Programa Principal
***************/
void main()
{
	char *aux;
	char opcao=' '; 
	int num = 0;
	/***** Inicia Arquivo *****/
	FILE *registro;
	registro = fopen("matriculas.dat", "r +");
	if (registro == NULL)
	{
		printf("----------------------------------\n");
		printf("Erro 101 - Arquivo Inexistente\n");
		printf("----------------------------------\n");
	}
	else
	{
		Lista* matriculas;//Cria agenda do tipo lista
		agenda = inicializa(); //Inicializa lista
		if (fgetc(registro) != EOF)
		{
			rewind(registro);
			fgets(aux, 30*sizeof(char), registro);
			num = atoi(aux);
			printf("%d", num);
			copiaLista(matriculas, registro, &num);
		}
		else
		{
			fprintf(registro, "%d", num);
		}
		/***** Menu *****/
		while (opcao != 'q')
		{
			opcao = imprime_menu(); //Imprime o menu
			switch (opcao)
			{
				case 'i':
					matriculas = insere(matriculas, registro);
					num++;
					break;
				case 'b':
					busca(matriculas);
					getchar();
					break;
				case 'p': 
					imprime_tudo(matriculas);
					getchar();
					break;
			}
		}
		rewind(registro);
		fprintf(registro, "%d \n", num); //Coloca numero de contatos no inicio do arquivo
		printf("---------------------------\n");
		printf("Salvando e saindo\n");
		printf("---------------------------\n");
	}
}
/*************************
	ERROS:
		101 - Arquivo Inexistente
			Arquivo precisa ser criado manualmente (> touch agenda.dat)
		102 - Agenda Vazia
			Se a agenda está vazia, não há o que buscar e, portanto, o programa retorna um erro.
*************************/

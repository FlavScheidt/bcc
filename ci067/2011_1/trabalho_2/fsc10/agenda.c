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
	char endereco[150]; 
	char fone[11]; 
	char email[30]; 
	char cidade[30]; 
	char cep[8]; 
	char estado[2];
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
void copiaLista (Lista *l, int *numContato, FILE *registro) //Copia o que está no arquivo e insere na lista
{
	int controle = 0;
	char enter;
	for (controle = 0; controle<*numContato; controle++)
	{
		Lista* novo = (Lista*) malloc (1*sizeof(Lista*)); //Aloca novo nodo na lista
		fgets(novo-> nome, 52*sizeof(char), registro);
		tiraEnter(novo->nome);
		fgets(novo->endereco, 152*sizeof(char), registro);
		tiraEnter(novo->endereco);
		fgets(novo->fone, 13*sizeof(char), registro);
		tiraEnter(novo->fone);
		fgets(novo -> email, 32*sizeof(char), registro);
		tiraEnter(novo->email);
		fgets(novo -> cidade, 32*sizeof(char), registro);
		tiraEnter(novo->cidade);
		fgets(novo -> cep, 10*sizeof(char), registro);
		tiraEnter(novo -> cep);
		fgets(novo->estado, 4*sizeof(char), registro);
		tiraEnter(novo->estado);
		novo -> prox = l;
		printf("-");
	}
	printf("\nAgenda carregada com sucesso\n");
}
Lista* insere (Lista *l) //Insere na lista
{
	FILE *registro;
	registro = fopen("agenda.dat", "a +");
	Lista  *novo = (Lista *) malloc(1*sizeof(Lista *));//Aloca um novo nodo na lista
	/***** Inicia leitura *****/
	/* Nome */
	printf("\nNome: ");
	fgets (novo -> nome, 52*sizeof(char), stdin);
	tiraEnter(novo -> nome);
	/* Endereço */
	printf("Endereco: ");
	fgets (novo -> endereco, 152*sizeof(char), stdin);
	tiraEnter(novo -> endereco);
	/* Telfone */
	printf("Telefone (DDD00000000): ");
	fgets (novo -> fone, 13*sizeof(char), stdin);
	tiraEnter(novo -> fone);
	/* E-mail */
	printf("E-mail: ");
	fgets (novo -> email, 32*sizeof(char), stdin);
	tiraEnter(novo ->email);
	/* Cidade */
	printf("Cidade: ");
	fgets (novo -> cidade, 32*sizeof(char), stdin);
	tiraEnter(novo -> cidade);
	/* CEP */
	printf("CEP: ");
	fgets (novo -> cep, 10*sizeof(char), stdin);
	tiraEnter(novo -> cep);
	/* Estado */
	printf("Estado: ");
	fgets (novo -> estado, 4*sizeof(char), stdin);
	tiraEnter(novo -> estado);
	novo -> prox = l;
	/***** Joga para o Arquivo *****/
	fprintf(registro, "%s\n", novo -> nome);
	fprintf(registro, "%s\n", novo -> endereco);	
	fprintf(registro, "%s\n", novo -> fone);	
	fprintf(registro, "%s\n", novo -> email);	
	fprintf(registro, "%s\n", novo -> cidade);	
	fprintf(registro, "%s\n", novo -> cep);	
	fprintf(registro, "%s\n", novo -> estado);
	fclose(registro);
	printf("\nContato adicionado com sucesso!");
	return novo;
}
void imprime_tudo(Lista* l) //Imprime todos os dados
{
	Lista* p;
	if (l == NULL)
	{
		printf("-------------------------");
		printf("\nErro 102 - Agenda vazia! \n");
		printf("-------------------------");
	}
	else
	{
		for (p=l; p != NULL; p=p->prox)
		{    
			printf("---------------------------------------------\n");
			printf(" Nome: %s\n", p->nome);
			printf(" Endereco: %s\n", p->endereco);
			printf(" Telefone: %s\n", p->fone);
			printf(" Email: %s\n", p->email);
			printf(" Cidade: %s\n", p->cidade);
			printf(" CEP: %s\n", p->cep);
			printf(" Estado: %s\n", p->estado);
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
			printf(" Endereço: %s\n", p->endereco);
			printf(" Telefone: %s\n", p->fone);
			printf(" Email: %s\n", p->email);
			printf(" Cidade: %s\n", p->cidade);
			printf(" CEP: %s\n", p->cep);
			printf(" Estado: %s\n", p->estado);
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
	printf("i - Inserir contato\n");
	printf("b - Buscar contato\n");
	printf("p - Imprimir lista de contatos\n");
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
	int numContato = 0;
	/***** Inicia Arquivo *****/
	FILE *registro;
	Lista* agenda;//Cria agenda do tipo lista
	agenda = inicializa(); //Inicializa lista
	registro = fopen("agenda.dat", "a +");
	rewind(registro);
	if (!feof(registro)) //Verifica se o arquivo está vazio
	{
		fgets(aux, 30*sizeof(char), registro); //Lê o número de contatos
		numContato = atoi(aux);
		printf("%d", numContato);
		copiaLista(agenda, &numContato, registro);
	}
	else
	{
		fprintf(registro, "%d", numContato);
	}
	fclose(registro);
	/***** Menu *****/
	while (opcao != 'q')
	{
		opcao = imprime_menu(); //Imprime o menu
		switch (opcao)
		{
			case 'i':
				agenda = insere(agenda);
				numContato++;
				break;
			case 'b':
				busca(agenda);
				getchar();
				break;
			case 'p': 
				imprime_tudo(agenda);
				getchar();
				break;
		}
	}
	registro = fopen("agenda.dat", "r +");
	fprintf(registro, "%d \n", numContato); //Coloca numero de contatos no inicio do arquivo
	printf("---------------------------\n");
	printf("Salvando %d contatos e saindo\n", numContato);
	printf("---------------------------\n");
	fclose(registro);
}
/*************************
	ERROS:
		101 - Arquivo Inexistente
			Arquivo precisa ser criado manualmente (> touch agenda.dat)
		102 - Agenda Vazia
			Se a agenda está vazia, não há o que buscar e, portanto, o programa retorna um erro.
*************************/

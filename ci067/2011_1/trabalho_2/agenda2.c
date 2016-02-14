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
	Programa Precisa ser modoficado para ler e escrever em arquivo
	Programa precisa ser modificado para abortar a qualquer momento
	Programa precisa ser modificado para ler n entradas (só lê uma)
************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
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
Lista* inicializa() //Inicializa e retorna a lista
{
	return NULL; 
}
Lista* insere (Lista* l) //Insere na lista
{
	char nom[50], end[150], tel[11], mail[30], cid[30], CEP[8], est[2];
	int tamanho;
	/***** Inicia leitura *****/
	printf("\nNome: \n");
	gets (nom);
	printf("Endereço: \n");
	gets (end);
	printf("Telefone (com DDD): \n");  
	gets (tel);
	printf("E-mail: \n");  
	gets (mail);
	printf("Cidade: \n");  
	gets (cid);
	printf("CEP: \n");  
	gets (CEP);
	printf("Estado (sigla): \n");  
	gets (est);
	Lista* novo = (Lista*) malloc(1*sizeof(Lista*)); //Aloca um novo nodo da lista
	/***** Joga para a Lista *****/
	strcpy(novo -> nome, nom); 
	strcpy(novo -> endereco, end); 
	strcpy(novo -> fone, tel);
	strcpy(novo -> email, mail);
	strcpy(novo -> cidade, cid);
	strcpy(novo -> cep, CEP);
	strcpy(novo -> estado, est);  
	novo -> prox = l;
	return novo;
}
void imprime_tudo(Lista* l) //Imprime todos os dados
{
	Lista* p;
	if (l == NULL)
	{
		printf("-------------------------");
		printf("\n Agenda vazia! \n");
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
	getchar();
}
int vazia (Lista* l) //Retorna um se a função está vazia e zero se não está
{
	if (l == NULL)
		return 1;
	else
		return 0;
}
void busca (Lista* l) //Busca por nome, encontra pedaços dentro da string
{
	char chave[MAX], aux[MAX];
	int tamanho_c, tamanho_s, i, k, achado, exclui, achado2;
	Lista* p;
	Lista* ant = NULL;
	p=l; 
	achado = 0;
	system("clear");
	printf("\nDigite o nome a ser buscado\n");
	gets (chave);
	tamanho_c = strlen(chave);
	tamanho_s = strlen(p->nome);
	for (p = l; p != NULL; p = p -> prox)
	{
		for (i = 0; i < tamanho_s-tamanho_c; i++)
		{
			for (k = 0; k < tamanho_c; k++)
				aux[k] = p->nome[i+k];
			if (!strcmp(aux,chave))
			{
				achado=1;
				achado2=1;
			}
		}
		if (achado == 1)
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
}
char imprime_menu() //Imprime o menu
{
	char opc;
	system("clear");
	printf("  O que deseja fazer?\n");
	printf("\n");
	printf("i - Inserir contato\n");
	printf("b - Buscar contato\n");
	printf("p - Imprimir lista de contatos\n");
	printf("q - Sair\n");
	opc = getchar();
	getchar();
	return opc;
}
/***************
	Programa Principal
***************/
void main()
{
	char opcao=' '; 
	int n_de_contatos;
	Lista* agenda;
	agenda = inicializa();
	while (opcao != 'q')
	{
		opcao = imprime_menu();
		switch (opcao)
		{
			case 'i':
				n_de_contatos++;
				agenda=insere(agenda);
				break;
			case 'b':
				busca(agenda);
				getchar();
				break;
			case 'p': 
				imprime_tudo(agenda);
				break;
		}
	}
}

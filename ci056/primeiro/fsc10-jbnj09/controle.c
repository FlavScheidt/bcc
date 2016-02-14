#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curses.h>
/************************
	Estruturas
************************/
typedef struct estruturaVoo //Estrutura de cada voo (lista encadeada)
{
	struct estruturaAeroporto *destino;
	int numvoo;
	struct estruturaVoo *prox;
} estruturaVoo;
typedef struct estruturaAeroporto //Estrutura de cada aeroporto (vetor)
{
	int ID;
	char *cidade;
	char *codigo;
	int voos;
	estruturaVoo *adjacencia;
} estruturaAeroporto;
/************************
	Funções
************************/
void TiraEnter (char *s)
{
	while(*s != '\0' && *s != '\n')
		s++;
	*s = '\0';
}
void IniciaLista (estruturaAeroporto *Lista) //Inicia o vetor de aeroportos
{
	int i;	
	for (i=0; i<=9; i++)
	{
		Lista[i].ID = i; //Atribui uma ID
		Lista[i].cidade = "<vazio>";
		Lista[i].codigo = "<vazio>";
		Lista[i].voos = 0;
		Lista[i].adjacencia = (estruturaVoo*) malloc (sizeof(estruturaVoo)); //Aloca lista de adjacencias
		Lista[i].adjacencia -> prox = NULL;
	}
}
void CadastraAeroporto (estruturaAeroporto *Lista, char *cidade, char *codigo)
{
	int ID;
	int i = 0;
	while ((i <= 9) && (strcmp(Lista[i].cidade,"<vazio>") != 0)) //Percorre vetor buscando posição vazia
	{
		i++;
	}
	if (Lista[i].cidade == "<vazio>") //Se chegou ao fim do vetor, verifica se a última posição é vazia
	{
		Lista[i].cidade = cidade;
		Lista[i].codigo = codigo;
		printf("\nAeroporto inserido com a ID %d\n", Lista[i].ID);
	}
	else
	{
		printf("\nImpossível Cadastrar. Número máximo de aeroportos excedido\n");
	}
}
void CadastraVoo(int numvoo, char *origem, char *destino, estruturaAeroporto *Lista)
{
	int encontrou = 0;
	int i = 0;
	int j = 0;
	/***** Busca origem *****/
	while ((i <= 9) && (encontrou = 0))
	{
		if (Lista[i].codigo == origem)
		{
			encontrou = 1;
		}
		else
		{
			i++;
		}
	}
	encontrou = 0;
	/***** Busca destino *****/
	while ((j <= 9) && (encontrou = 0))
	{
		if (Lista[j].codigo == destino)
		{
			encontrou = 1;
		}
		else
		{
			j++;
		}
	}
	/*** Coloca novo voo na lista *****/
	estruturaVoo *novo = (estruturaVoo*) malloc (sizeof(estruturaVoo)); // Aloca novo nodo
	Lista[i].adjacencia -> numvoo;  //Coloca informações no nodo cabeça
	Lista[i].adjacencia = Lista[j].adjacencia;
	novo -> prox = Lista[i].adjacencia -> prox;
	Lista[i].adjacencia = novo; // Coloca novo nodo cabeça no lugar
	Lista[i].voos++;
}
void RemoveVoo (int numvoo, estruturaAeroporto *Lista) 
{
	int encontrou = 0;
	int i = 0;
	int j = 0;
	estruturaVoo *nodo = Lista[i].adjacencia;
	estruturaVoo *anterior = nodo;
	/***** Busca o aeroporto *****/
	while ((encontrou = 0) && (i <= 9))
	{
		while ((j <= Lista[i]. voos) && (encontrou == 0))
		{
			if (nodo -> numvoo  == numvoo)
			{
				encontrou = 1;
			}
			else
			{
				anterior = nodo;
				nodo = nodo -> prox;
				j++;
			}
			i++;
		}
		if (encontrou == 0) // Se não encontrou, retorna a lista e uma mensagem de erro
		{
			printf("\nVoo não encontrado");
		}
		else //Remove o voo
		{
			anterior -> prox = nodo -> prox; // Aponta o nodo anterior para o próximo nodo
			free(nodo); // Libera memória
		}
	}
}
void ImprimeVoos (char *entrada, estruturaAeroporto *Lista)
{
	/***** Busca o aeroporto passado como parâmetro *****/
	int encontrou = 0;
	int i = 0;
	estruturaVoo *aux;
	while ((i <= 9) && (encontrou == 0)) 
	{
		if (strcmp(Lista[i].codigo, entrada) == 0)
		{
			encontrou = 1;
			printf("\nEncontrou\n");
		}
		else
		{
			printf("\nIncrementa\n");
			i++;
		}
	}
	if (encontrou == 1) //Confere se o aeroporto foi encontrado
	{
		/***** Percorre lista de adjacencias imprimindo tudo *****/
		printf("%s\n", Lista[i].codigo);
		if (Lista[i].voos == 0)
		{
			printf("\nNenhum voo partindo desse aeroporto\n");	
		}
		else
		{
			for (aux = Lista[i].adjacencia -> prox; aux != NULL; aux = aux ->prox)
			{
				printf("-----------------------------\n");
				printf("%s - %d", Lista[i].codigo, aux -> numvoo);
			}
		}
	}
	else
	{
		printf("\nAeroporto não encontrado\n");
	}
}
void ImprimeTudo (estruturaAeroporto *Lista)
{
	int i = 0;
	while ((i <= 9) && (strcmp(Lista[i].codigo, "<vazio>") != 0))
	{
		printf("\n------------------\n");
		printf("------------------\n");
		printf("Origem: %s\n", Lista[i].cidade);
		printf("------------------\n");
		printf("------------------\n");
		estruturaVoo *aux;
		for (aux = Lista[i].adjacencia -> prox; aux != NULL; aux = aux -> prox) //Percorre a lista de adjacencias
		{
			printf("----------\n");
			printf("%s - %d\n", Lista[i].codigo, aux -> numvoo);
		}
		i++;
	}
}
void ProcuraVoo (estruturaAeroporto Destino, estruturaAeroporto Origem, estruturaAeroporto *proximo, estruturaAeroporto anterior, estruturaVoo *voo, int count, int conexoes, estruturaAeroporto *Lista)
{
	for (voo = anterior.adjacencia; voo != NULL; voo = voo -> prox) //Percorre a lista de adjacencias do aeroporto
	{
		if ((proximo -> codigo != Destino.codigo) && (count <= conexoes) && (proximo -> codigo != Origem.codigo) && (proximo -> codigo != anterior.codigo))
		{ // Se não encontrou o destino, não for igual a origem, o número de conexões máximas não tiver excedido e não for igual ao aeroporto anterior continua a procurar (executa a recursão
		/***** Prepara para entrar na recursão *****/
			count++;
			anterior = *proximo;
			proximo = voo -> prox -> destino;
			voo = proximo -> adjacencia -> prox;
			ProcuraVoo(Destino, Origem, proximo, anterior, voo, count, conexoes, Lista);
		}
		else if ((proximo -> codigo == Destino.codigo) && (count <= conexoes)) //Se encontrou o destino e o número de conexões não tiver excedido, imprime
		{
			//Imprime() Função ainda não implementada
			printf("Imprime voo");
			return;
		}
		else
		{
			return;
		}
	}
}
/***********************
	Programa Principal
************************/
int main ()
{
	char cidade[30];
	char codigo[5];
	int opcao;
	int numvoo;
	char codigodestino[5];
	int encontrou  = 0;
	estruturaAeroporto Origem;
	estruturaAeroporto Destino;
	estruturaVoo *voo;
	char codOrigem[5];
	char codDestino[5];
	int conexoes;
	char auxconexoes[5];
	int count;
	char numaux[5];
	estruturaAeroporto *proximo;
	estruturaAeroporto anterior;
	/***** Vetor *****/
	struct estruturaAeroporto Lista[10];
	IniciaLista(Lista);
	/***** Menu *****/
	do
	{
		printf("----------------------\n");
		printf("1 - Inserir Aeroporto\n");
		printf("2 - Inserir Voo\n");
		printf("3 - Remover Voo\n");
		printf("4 - Buscar Voo\n");
		printf("5 - Imprimir voos partindo de um aeroporto\n");
		printf("6 - Imprimir tudo\n");
		printf("0 - Sair\n");
		printf("----------------------\n");
		scanf("%d%*c", &opcao);
		switch (opcao)
		{
			case 1:
				/***** Cadastra aeroporto *****/
				printf("\nInsira o nome da cidade\n");
				fgets(cidade, 30*sizeof(char), stdin);
				TiraEnter(cidade);
				printf("\nInsira o código do aeroporto\n");
				fgets(codigo, 5*sizeof(char), stdin);
				TiraEnter(codigo);
				CadastraAeroporto(Lista, cidade, codigo);
				break;
			case 2:
				/***** Cadastra Voo *****/
				printf("\nNúmero de voo\n");
				fgets(numaux, 5*sizeof(char), stdin);
				TiraEnter(numaux);
				numvoo = atoi(numaux);
				printf("\nAeroporto de origem\n");
				fgets(codigo, 5*sizeof(char), stdin);
				TiraEnter(numaux);
				printf("\nAeroporto de destino\n");
				fgets(codigodestino, 5*sizeof(char), stdin);
				TiraEnter(codigodestino);
				CadastraVoo(numvoo, codigo, codigodestino, Lista);
				printf("\nVôo cadastrado com sucesso\n");
				break;
			case 3:
				/***** Remove Voo *****/
				printf("\nInforme o número do Vôo\n");
				fgets(numaux, 5*sizeof(char), stdin);
				TiraEnter(numaux);
				numvoo = atoi(numaux);
				RemoveVoo(numvoo, Lista);
				break;
			case 4:
				/***** Busca Voo *****/
				printf("\nDigite o código do aeroporto de origem\n");
				fgets(codOrigem, 5*sizeof(char), stdin);
				TiraEnter(codOrigem);
				/***** Busca aeroporto de origem *****/
				int i = 0;
				while ((i <= 9) || (encontrou == 0))
				{
					if (Lista[i].codigo == codOrigem)
					{
						encontrou = 1;
						Origem = Lista[i];
					}
					else
					{
						i++;
					}
				}
				/***** Busca aeroporto de destino *****/
				printf("\nDigite o código do aeroporto de destino\n");
				fgets(codDestino, 5*sizeof(char), stdin);
				TiraEnter(codDestino);
				while ((i <= 9) || (encontrou == 0))
				{
					if (Lista[i].codigo == codDestino)
					{
						encontrou = 1;
						Destino = Lista[i];
					}
					else
					{
						i++;
					}
				}
				printf("\nDigite o número máximo de conexões\n");
				fgets(auxconexoes, 4*sizeof(char), stdin);
				TiraEnter(auxconexoes);
				conexoes = atoi(auxconexoes);
				count = 0;
				anterior = Origem;
				voo = anterior.adjacencia -> prox;
				proximo = voo -> destino;
				ProcuraVoo (Destino, Origem, proximo, anterior, voo, count, conexoes, Lista);
				break;
			case 5:
				/***** Imprime Voo *****/
				printf("\nInsira o código do aeroporto\n");
				fgets(codigo, 5*sizeof(char), stdin);
				TiraEnter(codigo);
				ImprimeVoos(codigo, Lista);
				break;
			case 6:
				/***** Imprime Tudo *****/
				ImprimeTudo(Lista);
				break;
			case 0:
				/***** Sai *****/
				break;
			default:
				fprintf(stderr, "Opção Inválida \n");
				break;
		}
	}while (opcao);
	return(0);
}

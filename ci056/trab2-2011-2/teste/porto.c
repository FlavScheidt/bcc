/************************
	Comentários Gerais:
		- Implementar lista de prioridades (furar fila na função que recebe as entradas)
************************/
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "lista.h"
/*************
	FUNÇÕES
**************/
void IniciaAduana(int **patio)
{
	int i;
	for (i=0; i<5; i++)
	{
		patio[i] = NULL;
	}
}
void LeConteiner(fila *tre, fila *cam)
{
	int scan = 1;
	conteiner *c;
	while (scan != EOF)
	{	
        	c = malloc(sizeof(conteiner));
		scan = scanf("%d", &c->entrada);
		scan = scanf("%d", &c->aduana);
		scan = scanf("%s", c->ID);
		scan = scanf("%s", c->tipo);
       		c->proximo = NULL;
       		c->espera = 0;
       		if(scan != EOF)
		{
			if(strstr("TRE", c->tipo) != NULL) //Se for trem, insere na fila de trens, se não, na de caminhões
			{
				InsereFila(c, tre);
			}
			else
       			{
				InsereFila(c, cam);
			}
		}
	}
}
int main()
{
	int i;
    	int tempo = 0;
    	int *patio[5];
    	int adicionado = 0;
    	conteiner *primeiro;
    	conteiner *aux;
    	fila *cam;
	fila *tre;
    	// inicializa o ponteiro de ponteiros
    	IniciaAduana(patio);
	cam = ConstroiFila();
	tre = ConstroiFila();
    	// Recebe os conteiners e suas informações da entrada padrão
	LeConteiner(tre, cam);
    	while (cam->primeiro != NULL || tre->primeiro != NULL || PatioVazio(patio) == 0)
    	{
		// Aumenta o tempo de espera dos conteiners do patio
    		for (i=0; i<5; i++)
    		{
    			if (patio[i] != NULL)
    			{
    				aux = (conteiner*)patio[i];
    				aux->espera++;
    			}
    		}	
    		/***************
			CARREGA
		***************/
		adicionado = 0;
		i = BuscaConteiner(patio); //Funcao que busca o conteiner a mais tempo no patio
		aux = (conteiner*)patio[i];
		if (aux != NULL)
		{
			// Se o tempo no pátio for maior que 20, ele irá pra linha de montagem
			if (aux->espera >= aux->aduana)
			{
				printf("Carrega %d %s\n", tempo+3, aux->ID); //Já imprime com o tempo gasto no guindaste contabilizado
				patio[i] = NULL;
				adicionado = 1;
			}
		}		
		/***************
			ENTRA
		***************/
		for (i=0; i<5; i++)
    		{
    			// Verifica se o primeiro da lista está apto a entrar no patio
    			if (tre->primeiro != NULL && tre->primeiro->entrada <= tempo && adicionado != 1)
			{
    				// Procura uma posição vazia no pátio para colocar um conteiner apto
				if (patio[i] == NULL)
				{
					printf("Entra %d %s\n", tempo+3, tre -> primeiro->ID);
					patio[i] = (int*)primeiro;
					RetiraPrimeiro(tre); //Assim que o conteiner for para o patio, é tirado da lista
					adicionado = 1;
					break; //Se tiver inserido no patio, sai do condicional
				}
				if (adicionado != 1)
					tre -> primeiro->espera++;
			}
			if (cam->primeiro != NULL && cam->primeiro->entrada <= tempo && adicionado != 1)
			{
				if (patio[i] == NULL)
				{
					printf("Entra %d %s\n", tempo +3, tre -> primeiro -> ID);
					patio[i] - (int*)primeiro;
					RetiraPrimeiro(cam);
					adicionado = 1;
					break;
				}
				if (adicionado != 1)
					cam->primeiro->espera++;
			}

    		}
		//Trata o tempo. Se o guindaste estiver em funcionamento, acresce em 3, pois apenas a chegada é tratada durante esse periodo, e esta já está implementada na fila
		if (adicionado == 1)
		{
			tempo = tempo+3;
		}
		else
		{
			tempo++;
		}
    	}
    	return 1;
}

/************************
	Comentários Gerais:
		- Implementar lista de prioridades (furar fila na função que recebe as entradas
		- Fazer mais funções
		- Mudar nomes da biblioteca
		- Implementar tempo de espera do guindaste
		- Revisar execução
************************/
#include <stdio.h>
#include <string.h>
#include <malloc.h>
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
void LeConteiner(fila *f)
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
       			insere_fila(c, f);
		}
	}
}
int main()
{
    	int i;
    	int tempo = 0;
    	int *patio[5];
    	int adicionado = 0, usoGuindaste = 0;
    	conteiner *primeiro;
    	conteiner *guindaste = NULL;
    	conteiner *aux = NULL;
    	fila *f;
    	IniciaAduana(patio);
    	f = constroi_fila();
    	// Recebe os conteiners e suas informações da entrada padrão
	LeConteiner(f);
	//Laço
   	while (f->primeiro != NULL || patio_vazio(patio) == 0)
    	{
		/*if (guindaste != NULL)
    		{
    			if (usoGuindaste == 3)
    			{
    				free(guindaste);
    				guindaste = NULL;
    			}
			else
			{
				usoGuindaste = usoGuindaste+1;
			}
    		}*/
		primeiro = f->primeiro;
    		for (i=0; i<5; i++)
    		{
    			if (patio[i] != NULL)
    			{
    				aux = (conteiner*)patio[i];
    				aux->espera++;
    			}
    		}	
    		for (i=0; i<5; i++)
    		{
    			// Verifica se o primeiro da lista está apto a entrar no patio
    			if (primeiro != NULL && primeiro->entrada <= tempo && guindaste != NULL)
			{
				if (patio[i] == NULL)
				{
					printf("Entra %d %s\n", tempo, primeiro->ID);
					guindaste = (conteiner *) primeiro;
					patio[i] = (int*)primeiro;
					retira_primeiro_lista(f); //Assim que o conteiner vai para o patio, é retirado da lista
					adicionado = 1;
					break; //Se tiver inserido no patio, sai do condicional
				}
				if (adicionado != 1)
					primeiro->espera++;
			}

    		}	
		i = busca_conteiner_patio(patio); //Funcao que busca o conteiner há mais tempo no pátio
		aux = (conteiner*)patio[i];
		if (aux != NULL)
		{
			if (aux->espera >= 20 && guindaste == NULL)
			{
				printf("Carrega %d %s\n", tempo, aux->ID);
				guindaste = (conteiner*)patio[i];
				guindaste->espera = tempo + guindaste->aduana; //Coloca o tempo total
				patio[i] = NULL;
			}
		}
		tempo++; // Aumenta em 1m o tempo global
    	}
    	return 1;
}

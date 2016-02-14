/************************
	Comentários Gerais:
************************/
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "lista.h"
/*************
	FUNÇÕES
**************/
void IniciaAduana(conteiner **patio)
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
       			InsereFila(c, f);
		}
	}
}
int main()
{
	// Declarações
	conteiner *patio[5];
	int i;
	int estado = 0; //0 para carregar e 1 para coloca no patio
	int uso = 0; //Uso do guindaste
	fila *f = ConstroiFila();
	conteiner *guindaste = NULL;
	conteiner *primeiro = f->primeiro;
	conteiner *aux = NULL;
	int tempo = 0;
	// Inicia patio e fila de espera
	IniciaAduana(patio);
	LeConteiner(f);
	// Inicia laço
	while ((f->primeiro != NULL) || (PatioVazio(patio) == 0))
	{
		// Incrementa tempo dos conteiners no patio
		for (i=0; i<5; i++)
		{
			if (patio[i] != NULL)
			{
				aux = (conteiner *) patio[i];
				aux->espera++;
			}
		}
		/***************
			Carrega
		***************/
		// Se o guindaste não estiver em funcionamento e o pátio não estiver vazio, tira conteiner do patio e coloca no navio
		if ((uso == 0) && (PatioVazio(patio) == 0))
		{
			printf("Entra no carrega\n");
			i = BuscaConteiner(patio); //Procura conteiner a mais tempo no patio
			guindaste = (conteiner *) patio[i];
			if (aux -> aduana <= aux -> espera) //Verifica se já ficou tempo o suficiente na aduana
			{
				uso = 1; //Guindaste em uso
				patio[i] = NULL; // Tira do pátio
				estado = 0;
			}
			else
			{
				guindaste = NULL;
			}
		}
		// Se já estiver a 3 minutos no guindaste, coloca no navio
		if ((uso == 3) && (estado == 0))
		{
			printf("Carrega %d %s\n", tempo, guindaste->ID);
			guindaste == NULL;
			uso = 0;
		}
		/***************
			Entra
		***************/
		if (uso == 0)
		{
			primeiro = f->primeiro;
			for (i=0; i<5; i++) //Percorre o patio atrás de um local vazio
			{
				if ((f->primeiro != NULL) && (primeiro -> entrada <= tempo))
				{
					if (patio[i] == NULL);
					{
						patio[i] = primeiro;
						uso = 1;
						estado = 1;
						break;
					}
				}
			}
			printf("Entra %d %s", tempo, primeiro -> ID);
		}
		if ((uso == 3) && (estado == 1))
		{
			printf("Entra %d %s", tempo, primeiro -> ID);
			RetiraPrimeiro(f);
			uso = 0;
		}
		//Atualiza tempo do guindaste
//		if ((uso != 0) || (uso != 3))
//		{
//			uso++;
//		}
		tempo++;
	}
	return 1;
}

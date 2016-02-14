
/* -------------------------------------------------------------------
 *            Aquivo: compilador.c
 * -------------------------------------------------------------------
 *              Autor: Bruno Muller Junior
 *               Data: 08/2007
 *      Atualizado em: [15/03/2012, 08h:22m]
 *
 * -------------------------------------------------------------------
 *
 * Funções auxiliares ao compilador
 *
 * ------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"


/* -------------------------------------------------------------------
 *  variáveis globais
 * ------------------------------------------------------------------- */

FILE* fp=NULL;

void geraCodigo (char* rot, char* comando) {

  if (fp == NULL) {
    fp = fopen ("MEPA", "w");
  }

  if ( rot == NULL ) {
    fprintf(fp, "     %s\n", comando); fflush(fp);
    printf("teste");
  } else {
    fprintf(fp, "%s: %s \n", rot, comando); fflush(fp);
  }
}

/*****************************************
	Imprime códigos com a apenas um parâmetro
	DMEN X
	AMEN X
	CRCT X
*****************************************/
void geraCodigo1Param (char *rot, char *comando, int param) //parametro char para tratar labels em comandos de desvio
{
	if (fp == NULL)
	{
		fp = fopen("MEPA", "w");
	}

	if (rot == NULL)
	{
		fprintf(fp, "     %s %d \n", comando, param); fflush(fp);
	}
	else
	{
		fprintf(fp, "%s: %s %d \n", rot, comando, param); fflush(fp);
	}
}

void geraCodigoParamRot (char *rot, char *comando, char *param) // Para comandos cujo parâmetro é um rótulo
{
	if (fp == NULL)
	{
		fp = fopen("MEPA", "w");
	}

	if (rot == NULL)
	{
		fprintf(fp, "     %s %s \n", comando, param); fflush(fp);
	}
	else
	{
		fprintf(fp, "%s: %s %s \n", rot, comando, param); fflush(fp);
	}
}

/*****************************************
	Imprime códigos com dois parâmetros
	CRVL X,Y
	ARMZ X,Y
*****************************************/
void geraCodigo2Params (char *rot, char *comando, int param1, int param2)
{
	if (fp == NULL)
	{
		fp = fopen("MEPA", "w");
	}

	if (rot == NULL)
	{
		fprintf(fp, "     %s %d, %d \n", comando, param1, param2); fflush(fp);
	}
	else
	{
		fprintf(fp, "%s: %s %d,%d \n", rot, comando, param1, param2); fflush(fp);
	}
}


int imprimeErro ( char* erro ) {
  fprintf (stderr, "Erro na linha %d - %s\n", nl, erro);
  exit(-1);
}

/***********************************************************************
	Funções da Tabela de Símbolos
	Tabela de símbolos é uma pilha usando realocação dinâmica
	(quando o número de vars for maior do que 32)
**********************************************************************/
void InsereTS (char simbolo[32], int tipo, int nLexico, int nDesloc, int tpVar, int rotulo)
{
	TabelaSimbolos *auxTS;
	int validaToken;

	topoTS++;

//	if (topoTS > 32) //Se não há mais espaços, aloca mais
//	{
//		auxTS = realloc(TS, topoTS*sizeof(TabelaSimbolos));
//		TS = auxTS;
//	}

	// Atribui os valores de indexação
	strcpy(TS[topoTS].simbolo, simbolo);
	TS[topoTS].tipo 	= tipo;
        TS[topoTS].nLexico      = nLexico;
        TS[topoTS].nDesloc      = nDesloc;


	// Trata as informações de acordo com o tipo
	if (tipo == 0)
	{
		validaToken = VerificaTokenTS(simbolo, nLexico);
		TS[topoTS].info.infoVar.tipoVar 	= tpVar;
	}
	else if (tipo == 1)
	{
		//Para labels não há validação de duplicação
		TS[topoTS].info.infoLabel.nRotulo = rotulo;
	}
	else if (tipo == 2)
	{
		validaToken = VerificaTokenTS(simbolo, nLexico);
		TS[topoTS].info.infoProcedure.nRotulo = nRotulo;
	}

}

int VerificaTokenTS(char simbolo[32], int nLexico)
{
	int aux = topoTS;
	
	while(aux>=0 && strcmp(TS[aux].simbolo, simbolo) != 0)
	{
		if (TS[aux].tipo != 1)
		{
			if (TS[aux].nLexico == nLexico)
			{
				fprintf(stdout, "ERRO: Variável ou procedimento %s declarada anteriormente", simbolo); fflush(stdout);
				exit(1);
				return 1;
			}
		}
		else
		{
	        	fprintf(stdout, "ERRO: Variável ou procedimento %s declarada anteriormente", simbolo); fflush(stdout);
	        	exit(1);
                	return 1;
		}

		aux--;
	}
	return 0;
}

int BuscaTS (char * simboloBusca, int tipo)
{
	int 	percorrePilha = topoTS;

	//Se a tabela está vazia, retorna erro
	if (TS == NULL)
	{
		return -1;
	}

	//Percorre a tabela
	while (percorrePilha >= 0)
	{
		if (strcmp(TS[percorrePilha].simbolo, simboloBusca) == 0 && TS[percorrePilha].tipo == tipo)
		{
			return percorrePilha;
		}
		--percorrePilha;
	}

	//Se chegou ao fim e não achou, retorna erro
	fprintf(stdout, "ERRO: Variavel %s nao declarada\n", simboloBusca); fflush(stdout);
	exit(1);
	return -1;
}

void RetiraTS ()
{
	topoTS--;
}

void ImprimeTS()
{
	fprintf(stdout, "\n\n"); fflush(stdout);
	int i = topoTS;

	while( i>=0)
	{
		fprintf(stdout, "%s %d ", TS[i].simbolo, TS[i].tipo);
		if (TS[i].tipo != 1)
		{
			fprintf(stdout, "%d %d \n", TS[i].nLexico,
						TS[i].nDesloc); fflush(stdout);
		}
		else
		{
			fprintf(stdout, "%d \n", TS[i].info.infoLabel.nRotulo);fflush(stdout);
		}
		--i;
	}
	fprintf(stdout, "\n \n"); fflush(stdout);
}

/*********************************************************************
	Funções da Tabela de Rótulos e tratamento de Rótulos
*********************************************************************/
int GeraNovoRotulo() //Calcula o número do próximo rótulo com base no topo da TR
{
	ultimoRotulo ++;

	return ultimoRotulo;
}

void FormataRotulo(int nLabel, char retorno[3]) //Formata rótulo para impressão
{

	if (nLabel > 9)
	{
		sprintf(retorno, "R%d", nLabel);		
	}
	else
	{
		sprintf(retorno, "R0%d", nLabel);
	}

}

void InsereTR(int nLabel)
{
	topoTR++;
	TR[topoTR] = nLabel;
}

void RemoveTR()
{
	topoTR--;
}

void ImprimeTR()
{
	int i = topoTR;
	while (i>=0)
	{
		fprintf(stdout, "\n %d %d \n", TR[i], i);fflush(stdout);
		i--;
	}
}

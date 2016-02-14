
%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"


int num_vars; 		//Número de variáveis declaradas (para alocação AMEN)
int num_vars2;		//Auxiliar
int nLexico; 		//nível léxico atual
int nDesloc; 		//deslocamento da variável
int nVarsAloc; 		//Número de vars para alocação
int tipoVar;		//Tipo da variável (aqui apenas int)

int buscaSimbolo;	//Auxiliar para busca de símbolos na TS
int is_boolean;		//Auxiliar para a análise de tipos

int auxRotuloEntradaW;	//Rótulo de entrada while
int auxRotuloSaidaW;	//Rótulo de saída do while

int auxRotuloDesvioI;	//Rótulo else do if
int auxRotuloSaidaI;	//Rótulo de saída do if

int auxRotuloEntradaP;	//Rotulo de entrada do procedimento
int auxRotuloSaidaP; 	//Rotulo de saida do procedimento, para que o bloco nao seja executado

int nLexicoCham;	//Nível léxico do procedimento ou função chamadores de procedimentos e funções
int nParamsProc;	//Número de parâmetros de um procedimento
%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES 
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO
%token FUNCTION PROCEDURE
%token MAIOR MENOR MAIOR_IGUAL MENOR_IGUAL IGUAL AND DIFF DIV FALSE TRUE MULT MAIS MENOS OR
%token INTEGER BOOLEAN
%token WHILE DO IF THEN ELSE LOWER_THAN_ELSE
%token LABEL NUMERO

%%

programa    :{
		
		num_vars 	= 0;
		nLexico		= 0;
		nDesloc		= 0;

             	geraCodigo (NULL, "INPP");
             }	
             PROGRAM IDENT 
             ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
             bloco PONTO 
	     {

		// Percorre TS e conta o número de vars para desalocar
		int nVarsDesaloc = 0;
		
		//Nao da pra usar for =(
		int i = topoTS;
		while (i >= 0)
		{
			if(TS[i].tipo == 0)
			{
				nVarsDesaloc++;
			}
			i--;
		}
		
		//Transforma nVarsDesloc em char
		geraCodigo1Param(NULL, "DMEN", nVarsDesaloc);
             	geraCodigo (NULL, "PARA"); 
             }
;

bloco       :
		parte_declara_rot
		{
		}

		parte_declara_vars
		{
		}

		declara_sub_rotina
		{
		}

		comando_composto
		{
		}
;

parte_declara_rot: LABEL lista_rots PONTO_E_VIRGULA
	|
;

lista_rots: lista_rots
	VIRGULA
	NUMERO
	{
		InsereTS(token, 1, nLexico, nDesloc, NULL, GeraNovoRotulo());
	}
	| NUMERO
	{
		InsereTS(token, 1, nLexico, nDesloc, NULL, GeraNovoRotulo());
	}
;

parte_declara_vars:  var 
;


var         : { } VAR declara_vars
		{
			geraCodigo1Param(NULL, "AMEM", num_vars);
			num_vars = 0;
		}
            |
;

declara_vars: declara_vars declara_var 
            | declara_var 
;

declara_var : {  nVarsAloc = 0; } 
              lista_id_var DOIS_PONTOS 
              tipo
	      {
			//Atualiza o tipo de variável na tabela
			int i 		= topoTS;
			int cont 	= 0;

			while (cont <= nVarsAloc)
			{
				TS[i].info.infoVar.tipoVar = tipoVar;
				cont++;
				i--;
			}
              }
              PONTO_E_VIRGULA
;

tipo        : INTEGER { tipoVar = 0; }
	| BOOLEAN { tipoVar = 1;}
;

lista_id_var: lista_id_var VIRGULA IDENT 
              	{
		      	InsereTS(token, 0, nLexico, nDesloc, 0, -1);
		 	nDesloc++;
		      	num_vars++;
			nVarsAloc++;
		}
            | IDENT 
	    	{ 
			InsereTS(token, 0, nLexico, nDesloc, 0, -1);
			nDesloc++;
			num_vars++;
			nVarsAloc++;
		}
;

lista_idents: lista_idents VIRGULA IDENT  
            | IDENT
;

declara_sub_rotina: declara_procedimento
	|
;

declara_procedimento: PROCEDURE IDENT
	{
		char auxRotulo[3];

		auxRotuloSaidaP 	= GeraNovoRotulo();
		auxRotuloEntradaP   	= GeraNovoRotulo();

		InsereTS(token, 2, nLexico, 0, 0, auxRotuloEntradaP);
		InsereTR(auxRotuloSaidaP);

		FormataRotulo(auxRotuloSaidaP, auxRotulo);
		geraCodigoParamRot(NULL, "DSVS", auxRotulo);

		FormataRotulo(auxRotuloEntradaP, auxRotulo);
		geraCodigo(auxRotulo, "NADA");

		geraCodigo1Param(NULL, "ENPR", nLexico);
		
		nLexico++;
		nDesloc = 0;

	}
	ABRE_PARENTESES params_formais_proc FECHA_PARENTESES
	{
		//Inserir o número de parâmetros na tabela de símbolos
		//Nesse momento o procedimento está no topo da pilha
		TS[topoTS].info.infoProcedure.nParams = nParams;
	}
	PONTO_E_VIRGULA
	bloco
	{
		char auxRotulo[3];
		geraCodigo2Params(NULL, "RTPR", nLexicoCham, 0);

		FormataRotulo(TR[topoTR], auxRotulo);
		geraCodigo(auxRotulo, "NADA");

		RemoveTR();

		// Retirar parâmetros e variáveis e retornar ao nivel lexico anterior
		int i = topoTS;
 
		while (TS[i].nLexico == nLexico)
		{
			RetiraTS();
		}

		nLexico--;

	} PONTO_E_VIRGULA
;

params_formais_proc: params_formais_proc VIRGULA param_formal_proc
	| param_formal_proc
;

param_formal_proc: IDENT 
	{
		//Adiciona parametro na tabela de simbolos
		nParamsProc++;
		InsereTS(token, 3, nLexico, nDesloc, 0, 0);
	}
	DOIS_PONTOS tipo
	{
		//Adiciona o tipo do 
		TS[topoTS].info.infoParamFormal.tipoVar = tipoVar;				
	}
;

comando_composto: T_BEGIN comandos T_END
;

comandos: comando PONTO_E_VIRGULA comandos
         | comando PONTO_E_VIRGULA;
 
comando: comando_sem_rotulo
        | NUMERO
         {
                 buscaSimbolo = BuscaTS(token, 1);
                 geraCodigo(FormataRotulo(TS[buscaSimbolo].info.infoLabel.nRotulo),
                         "NADA");
         }
         DOIS_PONTOS comando_sem_rotulo
;
 
comando_sem_rotulo: atribuicao_var
                 | comando_composto
		 | repetitivo
		 | condicional
		 | chama_procedimento
		 | read
		 | write
;

atribuicao_var: atrib_direita ATRIBUICAO expressao
	{
                 geraCodigo2Params(NULL, "ARMZ", TS[buscaSimbolo].nLexico,
                        TS[buscaSimbolo].nDesloc);
	}
;

atrib_direita: 
	IDENT
	{
		fprintf(stdout, "IDENT: %s", token); fflush(stdout);
		buscaSimbolo = BuscaTS(token, 0);
		is_boolean = 0;
	}
;

expressao: expressao_simples expressao_simples1
	|
;

expressao_simples1:
	| IGUAL expressao_simples
	{
		if (is_boolean == 1)
		{
			fprintf(stdout, "ERRO: operação inteira com booleanos"); fflush(stdout);
			exit(1);
		}
		geraCodigo(NULL, "CMIG");
		is_boolean = 1;
	}
	| DIFF expressao_simples
	{
		if (is_boolean == 1)
		{
			fprintf(stdout, "ERRO: operação inteira com booleanos"); fflush(stdout);
			exit(1);
		}
		geraCodigo(NULL, "CMDG");
		is_boolean = 1;
	}
	| MAIOR expressao_simples
	{
		if (is_boolean == 1)
		{
			fprintf(stdout, "ERRO: operação inteira com booleanos"); fflush(stdout);
			exit(1);
		}
		geraCodigo(NULL, "CMMA");
		is_boolean = 1;
	}
	| MENOR expressao_simples
	{
		if (is_boolean == 1)
		{
			fprintf(stdout, "ERRO: operação inteira com booleanos"); fflush(stdout);
			exit(1);
		}
		geraCodigo(NULL, "CMME");
		is_boolean = 1;
	}
	| MAIOR_IGUAL expressao_simples
	{
		if (is_boolean == 1)
		{
			fprintf(stdout, "ERRO: operacao inteiro com booleanos");fflush(stdout);
			exit(1);
		}
		geraCodigo(NULL, "CMAG");
		is_boolean = 1;
	}
	| MENOR_IGUAL expressao_simples
	{
		if (is_boolean == 1)
		{
			fprintf(stdout, "ERRO: Operação inteira com booleanos"); fflush(stdout);
			exit(1);
		}
		geraCodigo(NULL, "CMEG");
		is_boolean = 1;
	}
;

expressao_simples: expressao_simples MAIS termo 
	{
		geraCodigo(NULL, "SOMA");	
	}
	| expressao_simples MENOS termo
	{
		geraCodigo(NULL, "SUBT");
	}
	| expressao_simples OR termo
	{
		if (is_boolean == 0)
		{
			fprintf(stdout, "ERRO: Operação lógica com inteiros"); fflush(stdout);
			exit(1);
		}
		geraCodigo(NULL, "DISJ");
	}
	| termo
;

termo: termo MULT fator 
	{
		geraCodigo(NULL, "MULT");
	}
	| termo DIV fator 
	{
		geraCodigo(NULL, "DIVI");
	}
	| termo AND fator
	{
		if (is_boolean == 0)
		{
			fprintf(stdout, "ERRO: Operação lógica com inteiros"); fflush(stdout);
			exit(1);
		}
		geraCodigo(NULL, "CONJ");
	}
	| fator
;

fator:  IDENT
         {
                 int buscaSimbolo = BuscaTS(token, 0);
                 geraCodigo2Params(NULL, "CRVL", TS[buscaSimbolo].nLexico,
                                         TS[buscaSimbolo].nDesloc);
                 if (TS[buscaSimbolo].info.infoVar.tipoVar == 1)
                 {
                         is_boolean = 1;
                 }
         }

	| NUMERO
	{
		geraCodigoParamRot(NULL, "CRCT", token);
	}
	| ABRE_PARENTESES expressao FECHA_PARENTESES
	| TRUE
	{
		is_boolean = 1;
		geraCodigoParamRot(NULL, "CRCT", token);
	}
	| FALSE
	{
		is_boolean = 1;
		geraCodigoParamRot(NULL, "CRCT", token);
	}
;

repetitivo: WHILE
	{
		char auxRotulo[3];

		auxRotuloEntradaW = GeraNovoRotulo();
		InsereTR(auxRotuloEntradaW);

		FormataRotulo(TR[topoTR], auxRotulo);
		geraCodigo(auxRotulo, "NADA");
	}
	expressao
	{
		char auxRotulo[3];

		auxRotuloSaidaW = GeraNovoRotulo();
		
		InsereTR(auxRotuloSaidaW);
		
		FormataRotulo(TR[topoTR], auxRotulo);
		geraCodigoParamRot(NULL, "DSVF", auxRotulo);
	}
	DO
	comando_sem_rotulo
	{
		char auxRotulo[3];

		FormataRotulo(TR[topoTR-1], auxRotulo);
		geraCodigoParamRot(NULL, "DSVS", auxRotulo);

		FormataRotulo(TR[topoTR], auxRotulo);
		geraCodigo(auxRotulo, "NADA");

		RemoveTR();
		RemoveTR();
	}
;

condicional: if_then cond_else
	{
		char auxRotulo[3];

		FormataRotulo(TR[topoTR], auxRotulo);
		geraCodigo(auxRotulo, "NADA");

		if (TR[topoTR] == auxRotuloSaidaI)
		{
			RemoveTR();
			RemoveTR();
		}
		else
		{
			RemoveTR();
		}

	}
;

if_then: IF expressao
	{
		char auxRotulo[3];

		auxRotuloDesvioI = GeraNovoRotulo();
		InsereTR(auxRotuloDesvioI);

		FormataRotulo(TR[topoTR], auxRotulo);

		geraCodigoParamRot(NULL, "DSVF", auxRotulo);
	}
	THEN comando_sem_rotulo
;

cond_else: ELSE
	{
		char auxRotulo[3];

		auxRotuloSaidaI = GeraNovoRotulo();
		InsereTR();

		FormataRotulo(TR[topoTR], auxRotulo);
		geraCodigoParamRot(NULL, "DSVS", auxRotulo);
		
		FormataRotulo(TR[topoTR-1], auxRotulo);
		geraCodigo(auxRotulo, "NADA");
	} comando_sem_rotulo
	| %prec LOWER_THAN_ELSE
;

chama_procedimento: IDENT 
	{
		
	}
ABRE_PARENTESES lista_param_proc FECHA_PARENTESES
;

read: ABRE_PARENTESES lista_param_read FECHA_PARENTESES
;

lista_param_read: lista_param_read VIRGULA ident_read
	| ident_read
;

ident_read: IDENT
	{
		geraCodigo(NULL, "LEIT");
		simboloBuscado = BuscaTS(token, 0);

		geraCodigo2Params(NULL, "ARMZ", TS[simboloBusca].nLexico, TS[simboloBusca].nDesloc);

	}
;

write: ABRE_PARENTESES lista_param_write FECHA_PARENTESES
;

lista_param_write: lista_param_write VIRGULA ident_write
	| ident_write
;

ident_write:
	{
		simboloBuscado = BuscaTS(token, 0);

		geraCodigo2Params(NULL, "CRVL", TS[simboloBuscado].nLexico, TS[simboloBuscado].nDesloc);
		geraCodigo(NULL, "IMPR");
	}
;

%%

main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   int i;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }


/* -------------------------------------------------------------------
 *  Inicia a Tabela de Símbolos
 * ------------------------------------------------------------------- */
	topoTS = -1;
	TS = malloc(32*sizeof(TabelaSimbolos));
	
/**********************************************************************
	Inicia tabela de rótulos
**********************************************************************/
	ultimoRotulo = -1;
	topoTR = -1;
	TR = malloc(16*sizeof(int)); // o normal é ter menos rótulo do que variável

   yyin=fp;
   yyparse();

   return 0;
}


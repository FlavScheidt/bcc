%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"

int num_vars, niv_lex, dec_var_global, num_params;
int simb_buscado;
int i;
int var_atrib;
char rotulo[10];
int retorno_rot;
int ref;
int func;
int num_params_proc, curr_par, num_ref_vars, curr_proc_func;
int tipo_var;
int is_boolean;
int num_vars2;

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES 
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO NUMERO
%token MAIS MENOS OR MULT DIV AND IGUAL DIFF MAIOR MENOR MAIOR_IGUAL MENOR_IGUAL
%token DO WHILE IF THEN ELSE PROCEDURE LOWER_THAN_ELSE FUNCTION LABEL GOTO READ WRITE TRUE FALSE BOOLEAN INTEGER

%%

programa    :{ niv_lex = 0; desloc = 0; num_vars = 0; simb_buscado = -1; var_atrib =-1; num_rot=-1; dec_var_global=1;
             geraCodigo (NULL, "INPP",0,NULL); 
             }
             PROGRAM IDENT 
             ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
             bloco PONTO {

	     int i =topo_tabela-1;
	     int num_vars1=0;
	     while (i!=-1)
	     {
//printf("%s ",tab_simb[i].nome);
	     	if (tab_simb[i].tipo==0)
		  num_vars1++;
		i--;
	     }
	     geraCodigoInt (NULL, "DMEM",1,num_vars1,0);
             geraCodigo (NULL, "PARA",0,NULL);
             }
;

bloco       : parte_declara_rot
              parte_declara_vars 
              parte_subrotinas
              comando_composto
              ;




parte_subrotinas: { niv_lex+=1; desloc=0; geraRotulo(rotulo); empilhaRotulo(num_rot); geraCodigo (NULL, "DSVS",1,rotulo);  } 
                  proc_ou_func
                  {
                  retorno_rot = desempilhaRotulo();
		  niv_lex--;
                  concatenaRotulo(retorno_rot,rotulo);  
                  geraCodigo (rotulo, "NADA",0,NULL);
                  } 
		  parte_subrotinas
                |
             
;

proc_ou_func: PROCEDURE procedimento
	    | FUNCTION funcao

;

procedimento: IDENT 
              { 
              geraRotulo(rotulo); empilhaRotulo(num_rot); insereSimbolo(token, 1, niv_lex, desloc, rotulo, 0); 
              geraCodigo (rotulo, "NADA",0,NULL);
              geraCodigoInt (NULL, "ENPR",1,niv_lex,0);
              }

              param_formais0
	      PONTO_E_VIRGULA 
              bloco
              {
              retorno_rot = desempilhaRotulo();
              concatenaRotulo(retorno_rot,rotulo); 
              simb_buscado = buscaSimbolo(rotulo,1); 
              int num_vars2=0;

	     int i =topo_tabela-1;
	     while (tab_simb[i].tipo!=1 || tab_simb[i].niv_lex!=niv_lex)
	     {
		  if (tab_simb[i].tipo==0)
		    num_vars2++;
		  topo_tabela--;
		i--;
	     }              



              geraCodigoInt (NULL, "DMEM",1,num_vars2,0);
              geraCodigoInt (NULL, "RTPR",2,tab_simb[simb_buscado].niv_lex,tab_simb[simb_buscado].num_param); 
              }
              PONTO_E_VIRGULA

;

funcao: IDENT 
              { 
              geraRotulo(rotulo); empilhaRotulo(num_rot); insereSimbolo(token, 3, niv_lex, desloc, rotulo, 0); 
              geraCodigo (rotulo, "NADA",0,NULL);
              geraCodigoInt (NULL, "ENPR",1,niv_lex,0);
              }

              param_formais0
              DOIS_PONTOS
              tipo
              PONTO_E_VIRGULA
	      {
	      int i =topo_tabela-1;
	      while (tab_simb[i].tipo!=3 || tab_simb[i].niv_lex!=niv_lex)
	      {
		i--;
	      }
	      tab_simb[i].desloc = -4 - (tab_simb[i].num_param);

	      }
              bloco
              {
              retorno_rot = desempilhaRotulo();
              concatenaRotulo(retorno_rot,rotulo); 
              simb_buscado = buscaSimbolo(rotulo,1); 
              int num_vars2=0;

	     int i =topo_tabela-1;
	     while (tab_simb[i].tipo!=3 || tab_simb[i].niv_lex!=niv_lex)
	     {
		  if (tab_simb[i].tipo==0)
		    num_vars2++;
		  topo_tabela--;
		i--;
	     }


              geraCodigoInt (NULL, "DMEM",1,num_vars2,0);
              geraCodigoInt (NULL, "RTPR",2,tab_simb[simb_buscado].niv_lex,tab_simb[simb_buscado].num_param); 
              }
PONTO_E_VIRGULA
;

param_formais0: ABRE_PARENTESES
	        {num_params=0; }
                param_formais
		{ 
		int i =topo_tabela;
		int desl = -4;
                int achou = 0;
	        while (achou!=1)
	        {  
		  if (tab_simb[i].tipo==1 || tab_simb[i].tipo==3)
		  { 
		    achou = 1;
		  }
		  else
		    i--;
		  if (tab_simb[i].tipo==2)
		  { 
		    tab_simb[i].desloc = desl;
		    desl--;
		  }
	        }   
                int idx=0;
		int idx_p = i; 
		tab_simb[i].indices = malloc(num_params*sizeof(int));
                tab_simb[i].num_param = num_params;
		while (i!=topo_tabela-1)
	        { 
		  i++;
		  if (tab_simb[i].tipo==2)
		  {
		    tab_simb[idx_p].indices[idx] = tab_simb[i].num_param;
		    idx++;
		  }
	        }   
	        num_params = 0;
		}
                FECHA_PARENTESES
	      |

;

param_formais: PONTO_E_VIRGULA param_formais1 
             | param_formais1
             |
		
;

param_formais1: VAR { ref=1; } param_formais2 param_formais
	     | { ref=0; } param_formais2 param_formais
		
;



param_formais2 : { } 
              lista_params DOIS_PONTOS 
              tipo 
              {
              }
              
;

lista_params: lista_params 
              VIRGULA 
              IDENT 
              { insereSimbolo(token, 2, niv_lex, desloc, "0", ref); 

		num_params++;
              }
            | IDENT 
              { 
                insereSimbolo(token, 2, niv_lex, desloc, "0", ref); 
		num_params++;
              }
;







parte_declara_rot: LABEL lista_rots PONTO_E_VIRGULA
            |

;


lista_rots: lista_rots 
              VIRGULA 
              NUMERO
              { geraRotulo(rotulo); insereSimbolo(token, 4, niv_lex, 0, rotulo, 0); 
              }
            | NUMERO
              { 
                geraRotulo(rotulo); insereSimbolo(token, 4, niv_lex, 0, rotulo, 0); 
              }
;







parte_declara_vars:  var 
;


var         : { } VAR declara_vars
              {
              geraCodigoInt (NULL, "AMEM",1,num_vars,0);
              num_vars =0;
              }
            |
;

declara_vars: declara_vars declara_var 
            | declara_var 
;

declara_var : { num_vars2 =0; } 
              lista_id_var DOIS_PONTOS 
              tipo 
              {
		int i=topo_tabela;
                int contador=0;
	      while(contador!=num_vars2+1)
		{
		tab_simb[i].num_param = tipo_var;
		contador++;
		i--;
		}
              }
              PONTO_E_VIRGULA
;

tipo        : BOOLEAN { tipo_var=1; }
              | INTEGER { tipo_var=0; }
;

lista_id_var: lista_id_var 
              VIRGULA 
              IDENT 
              { insereSimbolo(token, 0, niv_lex, desloc, "0", 0); 
                desloc++; 
                num_vars++;
		num_vars2++; 
              }
            | IDENT 
              { 
                insereSimbolo(token, 0, niv_lex, desloc, "0", 0); 
                desloc++; 
                num_vars++; 
		num_vars2++; 
              }
;

lista_idents: lista_idents VIRGULA IDENT
            | IDENT
;


comando_composto: T_BEGIN comandos T_END 
;

comandos: comando PONTO_E_VIRGULA comandos
        | comando
;

comando: comando_sem_rotulo
       | NUMERO
         {
	   simb_buscado = buscaSimbolo(token,0); 
	   int i = 0;
           int num_locais = 0;
           while (i!=topo_tabela)
	        { 
		  if (tab_simb[i].tipo==0 && tab_simb[i].niv_lex==niv_lex)
		  {
		    num_locais++;
		  }
                  i++;
	        }
           geraCodigo (tab_simb[simb_buscado].rot, "NADA",0,NULL);
	   geraCodigoInt (NULL, "ENRT",2,niv_lex,num_locais);  
               
         }
         DOIS_PONTOS comando_sem_rotulo
;

comando_sem_rotulo: atrib_proc
                  | comando_repetitivo
                  | comando_condicional
                  | comando_composto
                  | desvio
		  | READ {  } ABRE_PARENTESES lista_param_leit FECHA_PARENTESES
		  | WRITE ABRE_PARENTESES lista_param_impr FECHA_PARENTESES
;


lista_param_leit: lista_param_leit VIRGULA ident_leit
                | ident_leit 
;

ident_leit: IDENT
          { 
		    geraCodigo (NULL, "LEIT",0,NULL);
		    
		    simb_buscado = buscaSimbolo(token,0);  
		    if (simb_buscado != -1)
                    {
		      if (tab_simb[simb_buscado].tipo==0 || (tab_simb[simb_buscado].tipo==2 && tab_simb[simb_buscado].num_param==0))
		        geraCodigoInt(NULL,"ARMZ",2,tab_simb[simb_buscado].niv_lex,tab_simb[simb_buscado].desloc);
	    	      else if (tab_simb[simb_buscado].tipo==2 && tab_simb[simb_buscado].num_param==1)
	                geraCodigoInt(NULL,"ARMI",2,tab_simb[simb_buscado].niv_lex,tab_simb[simb_buscado].desloc);
	    	      else
	              {
		        printf("erro \n");
		        exit(1);
	              }
	             }
                     else
                     {
	               printf("erro, nao achou\n");
	               exit(1);
	             }
		   }
;

lista_param_impr: lista_param_impr VIRGULA ident_impr
                | ident_impr 
;

ident_impr: IDENT
          { 
		    simb_buscado = buscaSimbolo(token,0);  
		    if (simb_buscado != -1)
                    {
		      if (tab_simb[simb_buscado].tipo==0 || (tab_simb[simb_buscado].tipo==2 && tab_simb[simb_buscado].num_param==0))
		        geraCodigoInt(NULL,"CRVL",2,tab_simb[simb_buscado].niv_lex,tab_simb[simb_buscado].desloc);
	    	      else if (tab_simb[simb_buscado].tipo==2 && tab_simb[simb_buscado].num_param==1)
	                geraCodigoInt(NULL,"CRVI",2,tab_simb[simb_buscado].niv_lex,tab_simb[simb_buscado].desloc);
	    	      else
	              {
		        printf("erro xxx\n");
		        exit(1);
	              }
	             }
                     else
                     {
	               printf("erro, nao achou\n");
	               exit(1);
	             }

		     geraCodigo (NULL, "IMPR",0,NULL);
		   }
;


desvio: GOTO NUMERO
	{ 
	  simb_buscado = buscaSimbolo(token,0);
          if (simb_buscado==-1)
	      {
		printf("erro, label nao existe\n");
		exit(1);
	      } 
	  geraCodigoInt (tab_simb[simb_buscado].rot, "DSVR",3,tab_simb[simb_buscado].niv_lex,niv_lex);

	}

;


comando_condicional: if_then cond_else 
                     { 
                       retorno_rot = desempilhaRotulo();
                       concatenaRotulo(retorno_rot,rotulo);
                       geraCodigo (rotulo, "NADA",0,NULL); 
                     }
;

if_then: IF expressao 
         {
           geraRotulo(rotulo);
           empilhaRotulo(num_rot);
           geraCodigo (NULL, "DSVF",1,rotulo); 
           geraRotulo(rotulo);
         }
         THEN comando_sem_rotulo
         {
           retorno_rot = desempilhaRotulo();
           empilhaRotulo(retorno_rot+1);
           concatenaRotulo(retorno_rot+1,rotulo);
           geraCodigo (NULL, "DSVS",1,rotulo); 
           concatenaRotulo(retorno_rot,rotulo);
           geraCodigo (rotulo, "NADA",0,NULL); 
         }
;

cond_else   : ELSE comando_sem_rotulo
            | %prec LOWER_THAN_ELSE
;

;

comando_repetitivo:
				WHILE
                                { 
                                  geraRotulo(rotulo);
                                  geraCodigo (rotulo, "NADA",0,NULL); 
				}
				expressao
				DO
                                {
                                  geraRotulo(rotulo);
                                  empilhaRotulo(num_rot);
                                  geraCodigo (NULL, "DSVF",1,rotulo); 
                                  
				}
				comando_sem_rotulo
				{
                                  retorno_rot = desempilhaRotulo();
                                  concatenaRotulo(retorno_rot-1,rotulo);
                                  geraCodigo (NULL, "DSVS",1,rotulo); 
                                  concatenaRotulo(retorno_rot,rotulo);
                                  geraCodigo (rotulo, "NADA",0,NULL); 
                                  
                                  
				}
;

atrib_proc: IDENT 
            {
              var_atrib = buscaSimbolo(token,0); 
              if (var_atrib==-1)
	      {
		printf("erro, variavel nao existe\n");
		exit(1);
	      }
	      else
	      {
	        if (tab_simb[var_atrib].tipo==1)
		{
		  insereSimbolo("", 5, num_params_proc, curr_par, "", var_atrib);
		  num_params_proc = tab_simb[var_atrib].num_param;
		  curr_par = 0;
		}
	      }
            }
	    
            atrib_proc2
;

atrib_proc2: ATRIBUICAO
            expressao { imprimeTabSimb(); }
            { 
	      if (tab_simb[var_atrib].num_param==1 && is_boolean==0)
	     {
		printf("erro, variavel é booleana.\n");
		exit(1);
	     }
	      if (tab_simb[var_atrib].tipo==0 || tab_simb[var_atrib].tipo==3 || (tab_simb[var_atrib].tipo==2 && tab_simb[var_atrib].num_param==0))
		{
                geraCodigoInt (NULL, "ARMZ",2,tab_simb[var_atrib].niv_lex,tab_simb[var_atrib].desloc); 

		}
	      else if (tab_simb[var_atrib].tipo==2 && tab_simb[var_atrib].num_param==1)
	        geraCodigoInt (NULL, "ARMI",2,tab_simb[var_atrib].niv_lex,tab_simb[var_atrib].desloc); 
	      else
	      {
		printf("erro, variavel nao foi passada por referencia\n");
		exit(1);
	      }
	is_boolean=0;
            }
	   | chama_proc
            {
	     if (curr_par!=num_params_proc) 
	     {
		printf("erro, procedimento com numero diferente de parametros\n");
		exit(1);
	     }
	     topo_tabela--;
	     curr_par = tab_simb[topo_tabela].desloc;
	     num_params_proc = tab_simb[topo_tabela].niv_lex;
	     geraCodigoInt (tab_simb[var_atrib].rot, "CHPR",4,niv_lex,0);
	    }
;

chama_proc: ABRE_PARENTESES 
	    lista_de_parametros 
	    { 
	    } FECHA_PARENTESES
          |
;

lista_de_parametros: lista_de_parametros VIRGULA expressao { curr_par++; }
            | expressao { curr_par++; }
;

expressao: expressao_simples expressao_simples1
;

expressao_simples1:
         |
           IGUAL { is_boolean = 1; }
           expressao_simples
           {
             geraCodigo (NULL, "CMIG",0,NULL); 
           }
         |
           DIFF { is_boolean = 1; }
           expressao_simples
           {
             geraCodigo (NULL, "CMDG",0,NULL); 
           }
         |
           MAIOR { is_boolean = 1; }
           expressao_simples
           {
             geraCodigo (NULL, "CMMA",0,NULL); 
           }
         |
           MENOR { is_boolean = 1; }
           expressao_simples
           {
             geraCodigo (NULL, "CMME",0,NULL); 
           }
         |
           MAIOR_IGUAL { is_boolean = 1; }
           expressao_simples
           {
             geraCodigo (NULL, "CMAG",0,NULL); 
           }
         |
           MENOR_IGUAL { is_boolean = 1; }
           expressao_simples
           {
             geraCodigo (NULL, "CMEG",0,NULL); 
           }
;

expressao_simples: expressao_simples MAIS termo { geraCodigo (NULL, "SOMA",0,NULL); }
                 | expressao_simples MENOS termo { geraCodigo (NULL, "SUBT",0,NULL); }
                 | expressao_simples OR termo { geraCodigo (NULL, "OR",0,NULL); }
                 | termo
;

termo: termo MULT fator { geraCodigo (NULL, "MULT",0,NULL); }
     | termo DIV fator { geraCodigo (NULL, "DIVI",0,NULL); }
     | termo AND fator { geraCodigo (NULL, "AND",0,NULL); }
     | fator
;

fator: NUMERO
       { 
         geraCodigo (NULL, "CRCT",1,token);
       }
     | ABRE_PARENTESES expressao FECHA_PARENTESES 
     | ident_func
     | TRUE { geraCodigo (NULL, "CRCT",1,"1"); }
     | FALSE { geraCodigo (NULL, "CRCT",1,"0"); }
;

ident_func : IDENT
		 { 
		 simb_buscado = buscaSimbolo(token,0);
		   if (simb_buscado != -1)
		   {
			if (tab_simb[simb_buscado].tipo==0 || (tab_simb[simb_buscado].tipo==2 && tab_simb[simb_buscado].num_param==0))
                          if (tab_simb[topo_tabela-1].tipo==5 && tab_simb[tab_simb[topo_tabela-1].num_param].indices[curr_par]==0)
			  	geraCodigoInt(NULL,"CRVL",2,tab_simb[simb_buscado].niv_lex,tab_simb[simb_buscado].desloc);
			  else if (tab_simb[topo_tabela-1].tipo==5 && tab_simb[tab_simb[topo_tabela-1].num_param].indices[curr_par]==1)
				geraCodigoInt(NULL,"CREN",2,tab_simb[simb_buscado].niv_lex,tab_simb[simb_buscado].desloc);
			  else
				geraCodigoInt(NULL,"CRVL",2,tab_simb[simb_buscado].niv_lex,tab_simb[simb_buscado].desloc);
		    	else if (tab_simb[simb_buscado].tipo==2 && tab_simb[simb_buscado].num_param==1)
			{
				if (tab_simb[topo_tabela-1].tipo==5 && tab_simb[tab_simb[topo_tabela-1].num_param].indices[curr_par]==1)
					geraCodigoInt(NULL,"CRVL",2,tab_simb[simb_buscado].niv_lex,tab_simb[simb_buscado].desloc);
				else 
					geraCodigoInt(NULL,"CRVI",2,tab_simb[simb_buscado].niv_lex,tab_simb[simb_buscado].desloc);
			}

			else if (tab_simb[simb_buscado].tipo==3)
			{
			  insereSimbolo("", 5, num_params_proc, curr_par, "", simb_buscado);
			  num_params_proc = tab_simb[simb_buscado].num_param;
		  	  curr_par = 0;
			  func = simb_buscado;
			  geraCodigoInt (NULL, "AMEM",1,1,0);
			}
		   }
		   else
		   {
		     printf("erro, nao achou\n");
		     exit(1);
		   }
		}
	     func_chamada 

;

func_chamada: ABRE_PARENTESES lista_de_parametros FECHA_PARENTESES 
	      { topo_tabela--;
		printf("topo da tabela: %d %d\n",tab_simb[topo_tabela].desloc,tab_simb[topo_tabela].niv_lex);
		if (curr_par!=num_params_proc) 
	          	{
		   	  printf("erro, funcao com numero diferente de parametros\n");
		    	  exit(1);
	          	}
			else
		  	  geraCodigoInt (tab_simb[func].rot, "CHPR",4,niv_lex,0);
		curr_par = tab_simb[topo_tabela].desloc;
		num_params_proc = tab_simb[topo_tabela].niv_lex;

	      }
	    | {
		if (tab_simb[simb_buscado].tipo==3)
		  {
			topo_tabela--;
			if (curr_par!=num_params_proc) 
	          	{
		   	  printf("erro, funcao com numero diferente de parametros\n");
		    	  exit(1);
	          	}
			else
		  	  geraCodigoInt (tab_simb[func].rot, "CHPR",4,niv_lex,0); 
			curr_par = tab_simb[topo_tabela].desloc;
			num_params_proc = tab_simb[topo_tabela].niv_lex;
		  }
	      }

;

%%

main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

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
 *  Inicia a Tabela de S\EDmbolos
 * ------------------------------------------------------------------- */
topo_tabela=0;
topo_rot =0;
is_boolean=0;
tab_simb = malloc(sizeof(elem_tabela)*30);
for (i=0; i<30; i++)
  tab_simb[i].tipo=-1;
  
tab_rot = malloc(sizeof(int)*30);

   yyin=fp;
   yyparse();

   return 0;
}


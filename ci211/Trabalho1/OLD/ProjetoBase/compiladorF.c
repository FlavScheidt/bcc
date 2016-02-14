
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
void geraCodigo (char* rot, char* comando, int tipo, char* ct) {

  if (fp == NULL) {
    fp = fopen ("MEPA", "w");
  }
  if ( tipo == 0 ) { //sem parametros
    if ( rot == NULL ) {
      fprintf(fp, "     %s\n", comando); fflush(fp);
    } else {
      fprintf(fp, "%s: %s \n", rot, comando); fflush(fp);
    }
  }
  else {
    fprintf(fp, "     %s %s\n", comando, ct); fflush(fp);
  }
}

void geraRotulo (char* destino) {
  num_rot++;
  if (num_rot>9)
    sprintf(destino, "R%d",num_rot);
  else
    sprintf(destino, "R0%d",num_rot);
}

void concatenaRotulo (int num, char* destino) {
  if (num>9)
    sprintf(destino, "R%d",num);
  else
    sprintf(destino, "R0%d",num);
}


void geraCodigoInt (char* rot, char* comando, int tipo, int ct1, int ct2) {

  if (fp == NULL) {
    fp = fopen ("MEPA", "w");
  }
  if ( tipo == 0 ) { //sem parametros
  }
  else if ( tipo == 1) {
    fprintf(fp, "     %s %d\n", comando, ct1); fflush(fp);
  }
  else if ( tipo == 2) {
    fprintf(fp, "     %s %d, %d\n", comando, ct1,ct2); fflush(fp);
  }
  else if ( tipo == 3) {
    fprintf(fp, "     %s %s, %d, %d\n", comando,rot,ct1,ct2); fflush(fp);
  }
  else if ( tipo == 4) {
    fprintf(fp, "     %s %s, %d\n", comando,rot,ct1); fflush(fp);
  }
}



void imprimeTabSimb() {
  int i=0;
  for (i=0; i<topo_tabela; i++) {
    if (tab_simb[i].tipo==0)
      printf("nome: %s, tipo, %d, nivel lexico %d, des %d, tipo %d.\n", tab_simb[i].nome, tab_simb[i].tipo, tab_simb[i].niv_lex, tab_simb[i].desloc, tab_simb[i].num_param);
    if (tab_simb[i].tipo==1 || tab_simb[i].tipo==3)
    {
      int k=0;
      printf("nome: %s, tipo, %d, nivel lexico %d, rotulo %s, num_param %d desloc %d ", tab_simb[i].nome, tab_simb[i].tipo, tab_simb[i].niv_lex, tab_simb[i].rot, tab_simb[i].num_param,tab_simb[i].desloc);
      while (k<tab_simb[i].num_param)
      {
        printf("param[%d]: %d ",k,tab_simb[i].indices[k]);
        k++;
      }
      printf("\n");


    }
    if (tab_simb[i].tipo==2)
      printf("nome: %s, tipo, %d, nivel lexico %d, desloc %d, ref %d.\n", tab_simb[i].nome, tab_simb[i].tipo, tab_simb[i].niv_lex, tab_simb[i].desloc, tab_simb[i].num_param);
    if (tab_simb[i].tipo==4)
      printf("nome: %s, tipo, %d, nivel lexico %d, rotulo %s.\n", tab_simb[i].nome, tab_simb[i].tipo,tab_simb[i].niv_lex, tab_simb[i].rot);

  }
}
void insereSimbolo(char *nome, int tipo, int niv_lex, int des, char *rotulo, int num_param) {
  strcpy(tab_simb[topo_tabela].nome,nome); 
  tab_simb[topo_tabela].tipo=tipo;
  tab_simb[topo_tabela].niv_lex=niv_lex;
  tab_simb[topo_tabela].desloc=des;
  strcpy(tab_simb[topo_tabela].rot,rotulo); 
  tab_simb[topo_tabela].num_param=num_param;
  topo_tabela++; 
}

void empilhaRotulo(int num) {
  tab_rot[topo_rot]=num;
  topo_rot++;
}

int desempilhaRotulo() {
  topo_rot--;
  return tab_rot[topo_rot];
}

int buscaSimbolo(char *nome, int tipo) {
  int i = topo_tabela-1;
  int igual = 0;
  for (i=topo_tabela-1; i>-1; i--) {
    if (tipo==0)
      igual = strcmp(nome, tab_simb[i].nome);
    else
      igual = strcmp(nome, tab_simb[i].rot);
    if (igual == 0)
      return i;
  }
  return -1;
}

int imprimeErro ( char* erro ) {
  fprintf (stderr, "Erro na linha %d - %s\n", nl, erro);
  exit(-1);
}

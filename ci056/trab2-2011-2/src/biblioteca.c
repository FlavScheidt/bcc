#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "biblioteca.h"

/*----------------------------------------------------------------------------*/
int *constroi_objeto_int(int n) {
  
  int *novo = malloc(sizeof(int));
  
  if ( ! novo ) return NULL;

  *novo = n;

  return novo;
}
/*----------------------------------------------------------------------------*/
par *constroi_objeto_par(int primeiro, int segundo) {
  
  par *novo = malloc(sizeof(par));
  
  if ( ! novo ) return NULL;

  novo->primeiro = primeiro;
  novo->segundo = segundo;

  return novo;
}
/*----------------------------------------------------------------------------*/
void escreve_objeto_par(objeto o) { 

  printf("(%d,%d)", ((par *)o)->primeiro, ((par *)o)->segundo); 
}
/*----------------------------------------------------------------------------*/
objeto le_objeto_int(void) { 

  int i;
  
  if ( scanf("%d", &i) != 1 ) return NULL;

  return constroi_objeto_int(i);
}
/*----------------------------------------------------------------------------*/
void escreve_objeto_int(objeto o) { printf("%d", *((int *)o)); }

/*----------------------------------------------------------------------------*/
lista *le_lista(lista *l, objeto le_objeto(void)) {

  objeto o;

  if ( ! l ) return NULL;

  while ( (o=le_objeto()) ) insere_lista(o,l);

  return l;
}
/*----------------------------------------------------------------------------*/
void escreve_lista(lista *l, void escreve_objeto(objeto)) {

  printf("(");

  no *p = primeiro_no(l);

  if ( p ) {
    
    escreve_objeto(objeto_no(p));

    for ( p=sucessor_no(p,l); p; p=sucessor_no(p,l) ) {
      
      printf(",");
      escreve_objeto(objeto_no(p));
    }
  }
  printf(")");
}

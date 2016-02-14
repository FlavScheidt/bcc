#include <malloc.h>

#include "lista.h"

/*----------------------------------------------------------------------------*/
int vazia_lista(lista *l) { return tamanho_lista(l) == 0; }

/*============================================================================*/

/*----------------------------------------------------------------------------*/
unsigned int tamanho_lista(lista *l) { return l->tamanho; }

/*----------------------------------------------------------------------------*/
objeto objeto_no(no *p) { return *p; }

/*----------------------------------------------------------------------------*/
static no *ultimo_no(lista *l) { 
  
  return l->v + l->tamanho - 1;
}
/*----------------------------------------------------------------------------*/
no *sucessor_no(no *p, lista *l) { 

  return !p || p==ultimo_no(l) ? NULL : p+1;
}
/*----------------------------------------------------------------------------*/
no *primeiro_no(lista *l) { 

  return vazia_lista(l) ? NULL : l->v;
}
/*----------------------------------------------------------------------------*/
lista *constroi_lista(void) {

  lista *l = malloc(sizeof(lista));

  if ( ! l ) return NULL;

  l->capacidade = l->tamanho = 0;

  if ( (l->v = malloc(2*sizeof(no))) ) l->capacidade = 2;

  return l;
}
/*----------------------------------------------------------------------------*/
void destroi_lista(lista *l) {

  free(l->v);

  free(l);
}
/*----------------------------------------------------------------------------*/
static int aumenta_lista(lista *l) { 

  unsigned int nova_capacidade = l->capacidade<2 ? 2 : 2*l->capacidade;

  objeto *aumentado = realloc(l->v,nova_capacidade*sizeof(objeto));

  if ( ! aumentado ) return 0;
  
  l->v = aumentado;

  l->capacidade = nova_capacidade;

  return 1;
}
/*----------------------------------------------------------------------------*/
static void diminui_lista(lista *l) {

  unsigned int nova_capacidade = l->capacidade/2;

  if ( realloc(l->v,nova_capacidade*sizeof(objeto)) ) 

    l->capacidade = nova_capacidade;
}
/*----------------------------------------------------------------------------*/
objeto remove_lista(lista *l) {

  objeto o;

  if ( vazia_lista(l) ) return NULL;

  o = objeto_no(ultimo_no(l));

  if ( --l->tamanho<l->capacidade/4 && l->capacidade>2 ) 
    
    diminui_lista(l);

  return o;
}
/*----------------------------------------------------------------------------*/
no *insere_lista(objeto o, lista *l) { 

  if ( l->tamanho==l->capacidade && !aumenta_lista(l) ) return NULL;

  l->v[l->tamanho++] = o;

  return ultimo_no(l);
}
/*============================================================================*/



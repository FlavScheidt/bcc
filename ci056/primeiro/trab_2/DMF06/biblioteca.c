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


/*----------------------------------------------------------------------------*/
int vazia_lista(lista *l) { return tamanho_lista(l) == 0; }

/*----------------------------------------------------------------------------*/
unsigned int tamanho_lista(lista *l) { return l->tamanho; }

/*----------------------------------------------------------------------------*/
no *primeiro_no(lista *l) { return l->primeiro; }

/*----------------------------------------------------------------------------*/
objeto objeto_no(no *p) { return p->o; }

/*----------------------------------------------------------------------------*/
no *sucessor_no(no *p, lista *l) { return p->sucessor; }

/*----------------------------------------------------------------------------*/
lista *constroi_lista(void) {

  lista *l = malloc(sizeof(lista));

  if ( ! l ) return NULL;

  l->primeiro = NULL;
  l->tamanho = 0;

  return l;
}
/*----------------------------------------------------------------------------*/
objeto remove_lista(lista *l) { 

  no *primeiro = primeiro_no(l);
  objeto o;

  if ( ! primeiro ) return NULL;

  o = objeto_no(primeiro);

  l->primeiro = sucessor_no(primeiro,l);
  --l->tamanho;
  free(primeiro);

  return o;
}
/*----------------------------------------------------------------------------*/
void destroi_lista(lista *l) { 
  
  no *p;

  while ( (p = primeiro_no(l)) ) {
    
    l->primeiro = sucessor_no(p,l);
    free(p);
  }

  free(l);
}
/*----------------------------------------------------------------------------*/
no *insere_lista(objeto o, lista *l) { 

  no *novo = malloc(sizeof(no));

  if ( ! novo ) return NULL;

  novo->o = o;
  novo->sucessor = primeiro_no(l);
  ++l->tamanho;
  
  return l->primeiro = novo;
}
/*----------------------------------------------------------------------------*/
no *insere_final_lista(objeto o, lista *l) { 
  if (l->tamanho == 0)
      return insere_lista (o, l);

  no *novo = malloc(sizeof(no));
  no *p;

  if ( ! novo ) return NULL;

  for (p=primeiro_no(l); p->sucessor; p = sucessor_no(p,l));

  novo->o = o;
  novo->sucessor = NULL;
  ++l->tamanho;

  return p->sucessor = novo;
}
/*============================================================================*/

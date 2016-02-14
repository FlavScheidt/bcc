/* trocar lista.h por lista_sequencial.h ou lista_ligada.h */
#include "lista.h"

int *constroi_objeto_int(int n);
objeto le_objeto_int(void);
void escreve_objeto_int(objeto o);

typedef struct {
  int primeiro, segundo;
} par;

par *constroi_objeto_par(int a, int b);
void escreve_objeto_par(objeto o);

lista *le_lista(lista *l, objeto le_objeto(void));
void escreve_lista(lista *l, void escreve_objeto(objeto));


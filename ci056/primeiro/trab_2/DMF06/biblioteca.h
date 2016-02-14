typedef void *objeto;

/* typedef ... no;    */

/* typedef ... lista; */

typedef struct no {
  objeto o;
  struct no *sucessor;
} no;

typedef struct {
  no *primeiro;
  unsigned int tamanho;
} lista;

objeto objeto_no(no *p);
no *sucessor_no(no *p, lista *l);
no *primeiro_no(lista *l);

int vazia_lista(lista *l);
unsigned int tamanho_lista(lista *l);
lista *constroi_lista(void);
void destroi_lista(lista *l);
no *insere_lista(objeto o, lista *l);
no *insere_final_lista(objeto o, lista *l);
objeto remove_lista(lista *l);




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

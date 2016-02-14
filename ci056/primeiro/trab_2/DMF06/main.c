/*
--------------------------------------------
CI056 - 2009/2
Segundo trabalho prático

Arquivo com a aplicação principal

NÃO ALTERE O CONTEÚDO DESTE ARQUIVO
--------------------------------------------
*/

#include <stdio.h>
#include <malloc.h>
#include "ligeirinho.h"


/* 
-----------------------------------------------------------------
Rotinas de manipulação do tipo relacao (definido em ligeirinho.h)
-----------------------------------------------------------------
*/

relacao * constroi_relacao(void);
void escreve_relacao(relacao *R);
int insere_tripla(relacao *R, int primeiro, int segundo, int rota);
int le_tubo(int *t);
int le_ligeirinhos(relacao **R, int *inicio, int *fim);



/* Construtor */
relacao * constroi_relacao(void)
{
  relacao *r;
  int i;

  r = (relacao *) malloc(sizeof(relacao));

  if (r)
    {
      for (i=0;i<MAXTUBOS;i++)
        r->adjacentes[i] = constroi_lista();
  
      r->n_pares = 0;
    }

  return r;
}

/* Rotina para uso em debug */
void escreve_relacao(relacao *R)
{
  int primeiro, segundo, rota;
  lista *l;
  no *p;
  par *o;

  if (R)
    {
      for (primeiro = 1; primeiro < MAXTUBOS; primeiro++)
        {
          l = R->adjacentes[primeiro];
          for (p=primeiro_no(l); p; p = sucessor_no(p,l))
            {
              o = (par*) objeto_no(p);
              rota = o->primeiro;
              segundo = o->segundo;
              printf("R%d(%d,%d)\n", rota, primeiro, segundo);
            }
        }
    }
  
}

/* Para uso na leitura de dados */
int insere_tripla(relacao *R, int primeiro, int segundo, int rota)
{
  par *p;

  p = constroi_objeto_par(rota,segundo);

  if (! insere_lista((void*)p, R->adjacentes[primeiro]))
    return 0;

  R->n_pares ++;

  return 1;
}


/* Para uso na leitura de dados */
int le_tubo(int *t)
{
  if ( scanf("%d", t) != 1 ) 
    return 0;
  return 1;
}

/* Rotina de entrada de dados */
/*
Observe que cada par da relação na verdade é uma
tripla (primeiro, segundo, rota) e que cada elemento
das listas de adjacência são pares (rota, segundo).
*/
int le_ligeirinhos(relacao **R, int *inicio, int *fim)
{
  int rota=1;
  int primeiro, segundo;

  /* Lê a primeira linha */
  if ((!le_tubo(inicio)) || (!le_tubo(fim)))
    return 0;

  if (!((*R) = constroi_relacao()))
    return 0;

  /* Lê as linhas de rota (Ligeirinhos) */
  do
    {
      primeiro = 0;
      while (le_tubo(&segundo))
        {
          if (primeiro)
            if (!insere_tripla(*R,primeiro,segundo,rota))
              return 0;
          primeiro = segundo;
        }

      rota++;
      
    }
  while (scanf("#") == 0);
  
  return 1;
}



/*
-----------------------------------------------------------------
Rotina principal
-----------------------------------------------------------------
*/

int main(void)
{
  relacao *R;

  int tuboA, tuboB;

  lista *caminho_tubos, *caminho_linhas;

  if (!le_ligeirinhos(&R,&tuboA,&tuboB)) 
    {
      printf("Erro na leitura!\n");
      return 0;
    }

  escreve_relacao (R);

  caminho_tubos = caminho_minimo_tubos(R, tuboA, tuboB);

  printf ("tubos: ");
  escreve_caminho(caminho_tubos);
  printf ("----\n");

  caminho_linhas = caminho_minimo_linhas(R, tuboA, tuboB);

  escreve_caminho(caminho_linhas);

  return 1;
}


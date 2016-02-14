#include <stdio.h>
#include "ligeirinho.h"

lista * caminho_minimo_tubos(relacao *R, int tuboA, int tuboB)
{
	no *p;
	lista *fila = constroi_lista ();
	int i, ant[MAXTUBOS], cont[MAXTUBOS], cont_rotas[MAXTUBOS];
	int *tubo1, *tubo2, *tubo, j;
	par *o;

	j=0;
	for (i = 0; i < MAXTUBOS; i++)
		ant[i] = cont[i] = cont_rotas[i] = -1;

	ant[tuboA] = j++;
	tubo = constroi_objeto_int (tuboA);  
	if (! insere_final_lista(tubo, fila))
		return NULL;

	while ((tubo1 = remove_lista (fila))) {
		printf ("tubo1:%d\n", *tubo1);

		for (p=primeiro_no(R->adjacentes[*tubo1]); p; p=sucessor_no(p,R->adjacentes[*tubo1])) {
			o = objeto_no(p);
			tubo2 = &o->segundo;
			printf ("tubo1:%d tubo2:%d\n", *tubo1, *tubo2);

			if (ant[*tubo2] == -1) {
				tubo = constroi_objeto_int (*tubo2);  
				if (! insere_final_lista(tubo, fila))
  					return NULL;
				ant[*tubo2] = j++;
				cont[*tubo2] = *tubo1;
				cont_rotas[*tubo2] = o->primeiro;
			}
		}
	}

	for (i = tuboB; i != tuboA; i = cont[i]){

		o = constroi_objeto_par(i, cont_rotas[i]);
		if (! insere_lista(o, fila))
			return NULL;
	}
    
	o = constroi_objeto_par(i, cont_rotas[i]);
	if (! insere_lista(o, fila))
		return NULL;

	return fila;
}


lista * caminho_minimo_linhas(relacao *R, int tuboA, int tuboB)
{
	no *p;
	lista *l;
	lista *fila = constroi_lista ();
	int i, j, k, ant[MAXTUBOS], cont[MAXTUBOS], cont_rotas[MAXTUBOS];
	int *tubo1, *tubo2, *tubo;
	par *o;

	k=0;
	for (j = 1; j < MAXTUBOS; j++){
		
		l = R->adjacentes[j];
		if (tamanho_lista(l) == 0)
		continue;

		for (i = 1; i < MAXTUBOS; i++)
			ant[i] = cont[i] = cont_rotas[i] = -1;

		ant[j] = k++;
		tubo = constroi_objeto_int (j);  
		if (! insere_final_lista(tubo, fila))
			return NULL;

		while ((tubo1 = remove_lista (fila))) {
			printf ("tubo1:%d\n", *tubo1);

		for (p=primeiro_no(R->adjacentes[*tubo1]); p; p=sucessor_no(p,R->adjacentes[*tubo1])) {
			o = objeto_no (p);
			tubo2 = &o->segundo;
			printf ("tubo1:%d tubo2:%d\n", *tubo1, *tubo2);

			if (ant[*tubo2] == -1) {
				tubo = constroi_objeto_int (*tubo2);  
				if (! insere_final_lista(tubo, fila))
					return NULL;
			ant[*tubo2] = k++;
			cont[*tubo2] = *tubo1;
			cont_rotas[*tubo2] = o->primeiro;
			}
		}
	}

	for (k = 1; k < MAXTUBOS; k++){

		if (ant[k] < 0)
			continue;

		if (j == k)
			continue;

		o = constroi_objeto_par(cont_rotas[k], k);
		if (! insere_lista(o, l))
			return NULL;
            
		for (i = k; i != j; i = cont[i]) {
				printf("(%d)-%d-", i, cont_rotas[i]);
		}
		printf("(%d)\n", i);
		printf("---\n");
		}
	}

    return caminho_minimo_tubos(R,tuboA,tuboB);
}

void escreve_caminho(lista *lc)
{
	no *p;
	par *o;

	if (!lc)
		return;

	p=primeiro_no(lc);
	o = objeto_no (p);
	printf ("(%d)", o->primeiro);

	for (p = sucessor_no(p,lc); p; p = sucessor_no(p,lc)) {
		o = objeto_no (p);
		printf ("-%d-(%d)", o->segundo, o->primeiro);
	}
	printf("\n");
}

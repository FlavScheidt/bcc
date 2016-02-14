#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "PatTree.h"

Dib Bit (IndexAmp i, ChaveTipo k)
{
	int c, j;
	int aux;
	aux = D-1;
	if (i==0) //Se a posição passada for zero, sempre retorna zero
		return 0;
	else
	{
		c = k;
		for(j = 1; j <= aux; j++) 
		{	
			c = c/2; //Divide c por 2 para definir se o bit é 1 ou 0
		}
		return (c & 1);
	}
}

short EExterno(Arvore p)
{
	return (p->nt == Externo);
}

Arvore CriaNoInt(int i, Arvore *Esq, Arvore *Dir)
{
	Arvore p;
	p = (Arvore) malloc(sizeof(PatNo));
	p -> nt = Interno;
	p -> NO.NInterno.Esq = *Esq;
	p -> NO.NInterno.Dir = *Dir;
	p -> NO.NInterno.Index = i;
	return p;
}

Arvore CriaNoExt(ChaveTipo k)
{
	Arvore p;
	p = (Arvore) malloc(sizeof(PatNo));
	p -> nt = Externo;
	p -> NO.Chave = k;
	return p;
}

ChaveTipo Pesquisa(ChaveTipo k, Arvore t)
{
	if (EExterno(t))
	{
		if (k == t -> NO.Chave)
		{
			printf("Elemento Encontrado\n");
			return t -> NO.Chave;
		}
		else
		{
			printf("Elemento não encontrado\n");
			return;
		}
		if (Bit(t -> NO.NInterno.Index, k) == 0)
			Pesquisa(k, t -> NO.NInterno.Esq);
		else
			Pesquisa(k, t-> NO.NInterno.Dir);
	}

}

Arvore InsereEntre(ChaveTipo k, Arvore *t, int i)
{
	Arvore p;
	if (EExterno(*t) || i < (*t) ->NO.NInterno.Index)
	{
		p = CriaNoExt(k);
		if (Bit(i, k) == 1)
			return CriaNoInt(i, t, &p);
		else
			return CriaNoInt(i, &p, t);
	}
	else
	{
		if (Bit((*t) -> NO. NInterno.Index, k) == 1)
			(*t) -> NO.NInterno.Dir = InsereEntre(k, &(*t) -> NO.NInterno.Dir, i);
		else
			(*t) -> NO.NInterno.Esq = InsereEntre(k, &(*t) -> NO.NInterno.Esq, i);
		return(*t);
	}
}

Arvore Insere (ChaveTipo k, Arvore *t)
{
	Arvore p;
	int i;
	int aux = D-1;
	if (*t == NULL)
		return CriaNoExt(k);
	else
	{
		while(!EExterno(p))
		{
			if (Bit(p -> NO.NInterno.Index, k) == 1)
				p = p -> NO.NInterno.Dir;
			else
				p = p -> NO.NInterno.Esq;
		}
		i = 1;
		while ((i <= aux) && Bit(i, k) == Bit(i, p -> NO.Chave))
			i++;
		if (i > aux)
		{
			printf("Chave já está na árvore\n");
			return (*t);
		}
		else
			return(InsereEntre(k, t, i));
	}
}

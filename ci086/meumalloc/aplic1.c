#include "meuAlocador.h"

int main()
{
	tree raiz = NULL;
	object chave;
	char tipo;
	int num_rot=0;

	char *o1 = meuAlocaMem(200);
	char *o2 = meuAlocaMem(100);
	char *o3 = meuAlocaMem(50);
	char *o4 = meuAlocaMem(200);
	char *o5 = meuAlocaMem(100);
	char *o6 = meuAlocaMem(50);
	char *o7 = meuAlocaMem(200);
	char *o8 = meuAlocaMem(100);
	char *o9 = meuAlocaMem(50);
	char *o10 = meuAlocaMem(200);
	char *o11 = meuAlocaMem(100);
	char *o12 = meuAlocaMem(50);
meuRealocaMem(o3,5);
//imprMapa();
//meuLiberaMem (o2);
//imprMapa();
//meuLiberaMem (o3);
//imprMapa();
//char *o4 = meuAlocaMem(6);
//	meuLiberaMem (o2);
//	char *o4 = meuAlocaMem(6);
//	meuLiberaMem (o3);
//	meuLiberaMem (o4);
/*	meuLiberaMem (o1);
	char *o3 = meuAlocaMem(50);
	char *o4 = meuAlocaMem(40);
	char *o5 = meuAlocaMem(20);
	meuLiberaMem (o2);
	char *o6 = meuAlocaMem(50);
	char *o7 = meuAlocaMem(40);
	char *o8 = meuAlocaMem(20);
	meuLiberaMem (o4);
	char *o9 = meuAlocaMem(50);
	imprMapa();
	meuLiberaMem (o8);*/

//	char *o4 = meuAlocaMem(1);
//	char *o5 = meuAlocaMem(1);
//	meuLiberaMem (o2);
//	meuLiberaMem (o1);
//	meuLiberaMem (o4);
	imprMapa();
	imprMapa2();

	imprMemoria();

}

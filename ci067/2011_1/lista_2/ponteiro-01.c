#include <stdio.h>

main () 
{
  char *pstr = "Armando Delgado, O Gordao",
       frs[] = "Armando Delgado, O Gordao";

  printf ("F1 = %s\nF2 = %s\n", frs, pstr);
  printf ("FRS = %p\nPSTR = %p\n", frs, pstr);
}

/***************
	Atribui a frase em questao as strings pstr e frs, primeiramente usando
	notação de ponteiros e depois de vetores ( o resultado e o mesmo ).
	Depois imprimi ambas as strings com printf.
***************/

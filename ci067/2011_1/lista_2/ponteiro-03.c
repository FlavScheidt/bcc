#include <stdio.h>

main () 
{
  char dogma[] = "Armando Delgado eh Gordao", *pstr;
  int num=20, *pi, quant[5]={12,34,67,89,56};

  puts(dogma + 1);
  puts(dogma++);
  puts(pstr++);

  pstr=dogma+5;
  puts(pstr);
  puts(pstr=dogma+10);

  pi=&num;
  printf("PI = %p = %d\n", pi, *pi);

  pi=&quant;
  printf("QUANT = %d\n", pi+3);

  pi=quant+2;
  printf("QUANTS = %d -- %d -- %d -- %d\n", *(quant+1), *(pi+3), pi[3], pi[5]);

}
/***************
	Imprimi a posição 1 da string dogma (r)
	Imprimi a posição 1 da string dogma (r)
	Imprimi a primeira posição de pstr
	Atribui pstr a sexta posição de dogma
	Imprimi pstr
	Imprimi a posição 11 de dogma (l)
	Atribui ao ponteiro pi o endereço de num
	Imprimi o endereço contido em pi e o valor que este referencia
	Atribui a pi o endereço de quant
	Imprimi o valor do terceiro elemento de quant
	Atribui a pi o edereço do terceiro elemento de quant
	Imprimi os valores do segundo, terceiro, quarto, quinto e sexto elemetos de pi
***************/


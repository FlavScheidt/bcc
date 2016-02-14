#include <stdio.h>

main () 
{
  char buffer[20], nome[20], *pstr;

  
  printf ("Digite seu nome (maxximo de 20 caractesres): ");
  gets(buffer);

  nome = buffer;   /* copiando o que foi digitado para array nome[] */
  pstr = &buffer;

  printf ("F1 = %s", buffer);  /* imprimindo nome digitado */
  printf ("FRS = %p\nPSTR = %p = %s\n", buffer, pstr, pstr);
}

/***************
	Lê a string inserida e armazena no array "buffer".
	Copia para nome o que foi inserido em buffer.
	Coloca o endereço de buffer em pstr.
	Imprime o nome digitado (armazenado em buffer).
	Imprime o endereço contido em pstr e depois o valor referenciado por pstr (buffer).
***************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parametros.h"

main(int argc, char *argv[]){
int a1,a2,b1,b2,c1,c2;//parametro


//---------------parametros-----------------//
	if (argc != 8)
	{
	printf("Voce esqueceu de digitar algum parametro\n");
	exit(0);
	}

FILE *arq, *arq2;
  arq = fopen(argv[1],"r");
  arq2 = fopen(argv[2],"r");
  if(!arq){
   printf("Erro na leitura do texto 1\n");
   exit(1);}

  if(!arq2){
   printf("Erro na leitura do texto 1\n");
   exit(1);}

a1=atoi(argv[3]);
a2=atoi(argv[4]);
b1=atoi(argv[5]);
b2=atoi(argv[6]);
c1=atoi(argv[7]);
c2=atoi(argv[8]);

//-----------------------------------------//
}

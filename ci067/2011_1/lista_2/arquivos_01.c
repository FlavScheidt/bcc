#include <stdio.h>

#define MAX 500

main()
{
  int fr;
  char dado[MAX],
       *arquivo="arquivos_01.dat";
  FILE *arq;
  
  arq= fopen(arquivo, "r+");

  fr = fread(dado, sizeof(char), MAX, arq);

  printf ("\nForam lidos %d caracteres do arquivo \"%s\".\n", fr, arquivo);

  fclose(arq);

}
/*************************
	Declara variável fr
	Declara Vetor dado
	Ponteiro para a String "arquivos_01.dat"
	Defina *arq como um arquivo
	Abre o arquivo para leitura e escrita
	Lê dados contidos em arq, do tamanho string, colocando no vetor dados, até o limite MAX (500)
	Imprime o número de dados lidos.
**************************/

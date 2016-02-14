/*  Programa MESCLA.
 *  Programa recebe pela linha de comando  nome de 2 arquivos de texto, e
 *  3 pares  de inteiros representando coordenadas  (linha,caracter) em um
 *  arquivo texto.  Exemplo:
 * 
 *      mescla texto-1.txt texto-2.txt 19 21  3 12 8 46
 * 
 *  Programa  deve copiar  um bloco  de texto  do do  2o.  arquivo  no 1o.
 *  arquivo,  a partir  da coordenada  indicada  no 1o.  par de  inteiros,
 *  sobrescrevendo o conteúdo a partir desta posição.
 *  O bloco  do 2o.   arquivo é definido  pelos dois pares  de coordenadas
 *  restantes.   Após  copiar  o   bloco,  espaços  em  branco  devem  ser
 *  preenchidos ao redor.
 *  Finalmente, o resultado deve ser salvo em um 3o.  arquivo, cujo nome é
 *  arbitrário, sendo que uma mensagem final do programa deve indicar este
 *  nome.
 * 
 *  Este programa NAO TRATA:
 *  - bloco a ser copiado possui linhas de tamanhos diferentes
 *    (como fica o contorno de espacos em branco?)
 *  - limites de margem no resultado
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *cigets (char *, int , FILE *);

#define TAM_FRASE   255

main (int argc, char * argv[]) 
{
  char buffer[TAM_FRASE + 1] = "\n";
  char **texto1, **texto2;
  int i, j;
  FILE *fp1, *fp2;

  /* verifica se todos os argumentos da linha de comando foram dados */
  /* Por que 9 e nao 8? */
  if (argc != 9) {
    printf("Entre com 8 args: arq1 arq2 x1 y1 x2 y2 x3 y3\n");
    exit(1);
  }

  /* Abre os arquivos para leitura */
  fp1 = fopen (argv[1], "r");
  fp2 = fopen (argv[2], "r");
  if (fp1 == NULL || fp2 == NULL) {
    printf("Erro ao abrir arquivos %s ou %s\n", argv[1], argv[2]);
    exit(1);
  }

  /* aloca memoria para ler 1o. arquivo */  
  texto1 = (char **) calloc (1, sizeof(char *));
  if (texto1 == NULL) {
    printf ("ERRO DE ALOCACAO DE TEXTO1\n");
    exit(1);
  }

  /* Leitura do 1o. arquivo, usando vetor de ponteiros */
  for (i = 0; (texto1[i] = fgets(buffer, TAM_FRASE, fp1)) != NULL; i++) 
  {
    if((texto1[i] = strdup(buffer)) != NULL)
      texto1 = (char **) realloc (texto1, (i + 2) * sizeof(char *));
  }
  
  /* Leitura do 2o. arquivo */
  texto2 = (char **) calloc (1, sizeof(char *));
  if (texto2 == NULL) {
    printf ("ERRO DE ALOCACAO DE TEXTO2\n");
    exit(1);
  }

  for (i = 0; (texto2[i] = fgets(buffer, TAM_FRASE, fp2)) != NULL; i++) 
  {
    if((texto2[i] = strdup(buffer)) != NULL)
      texto2 = (char **) realloc (texto2, (i + 2) * sizeof(char *));
  }

  /* Copia do 2o para o 1o */
  {
    char *arqres = "resp.txt";
    FILE *fp3;
    int ini1, ini2, linhabloco, altbloco,
        l1, c1, l2, c2, l3, c3,
	lib, lfb, cib, cfb;
    
    l1 = atoi (argv[3]) - 1;
    c1 = atoi (argv[4]) - 1;
    l2 = atoi (argv[5]) - 1;
    c2 = atoi (argv[6]) - 1;
    l3 = atoi (argv[7]) - 1;
    c3 = atoi (argv[8]) - 1;
    
    /* quant. caracteres em cada linha do bloco */
    linhabloco = c3-c2+1;

    /* quant. linhas no bloco */
    altbloco = l3-l2+1;
    
    /* Copia bloco para posicao x1, y1 */
    for (ini1=l1, ini2=l2; ini2 <= l3; ini1++, ini2++)
      strncpy (&texto1[ini1][c1], &texto2[ini2][c2], linhabloco);
    

    /* Faz contorno de espacos em branco ao redor do bloco copiado */
    lib = l1 - 1;
    lfb = l1 + altbloco;
    cib = c1 - 1;
    cfb = c1 + linhabloco;

    /* Coloca espacos nas linhas antes e apos o bloco */
    for (i = cib; i <= cfb; i++)
      texto1[lib][i] = texto1[lfb][i] = ' ';
    
    /* Coloca espacos nas colunas antes e apos o bloco */
    for (i = lib+1; i < lfb; i++)
      texto1[i][cib] = texto1[i][cfb] = ' ';
    
    /* Cria arquivo para gravar resultado */
    fp3 = fopen (arqres, "w");
    if (fp3 == NULL) {
      printf("Erro ao criar arquivo %s\n", arqres);
      exit(1);
    }  

    /* Salva resultado em arquivo */
    for (i = 0; texto1[i] != NULL; i++) 
    {
      fputs(texto1[i], fp3);
    }
    fclose(fp3);

    printf("\nResultado salvo no arquivo \"%s\"\n\n", arqres);
  }

  /* fecha arquivos */
  fclose(fp1);
  fclose(fp2);

} /*FIM PROGRAMA */
  

/* Mesmo que fgets(), mas retira do buffer o caracter '\n' final que
 * fgets() insere no buffer de entrada */

char *cigets (char *buffer, int size, FILE *stream)
{
  int i;
  buffer = fgets(buffer, size, stream);
  
  /* elimina '\n' inserido por fgets() */
  if (buffer != NULL) {
    for (i = strlen(buffer); buffer[i] != '\n'; i--);
    buffer[i] = '\0';
  }
  
  return buffer;
}




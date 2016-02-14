/*(mescla) Programa recebe pela linha de comando nome de 2 arquivos de texto, e 3 pares de omteorps, representando coordenadas (linha, caracter) em um arquivo texto. Exemplo:
mescla texto1 texto2 19 21 3 12 8 46
O programa deve copiar bloco do 2° arquivo no 1° arquivo, a partir da coordenada indicada no 1° par de inteiros, sobrescrevendo o conteúdo anterior.
O bloco do 2° arquivo é definido pelos pares de coordenadas restantes.
Ao copiar bloco, caracteres ao redor devem ser espaços em branco.
Salvar resultado em um 3° arquivo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 150

void main (int *argc, char *argv[9]) {

	FILE *t1, *t2, *t3;
	char buf[TAM],**frases, **frases2, *temp;
	int i=0, n, lt1, ct1, lit2, cit2, lft2, cft2, l, l2, c, c2;

	//colocando primeiro texto na memória
	t1 = fopen ("texto1.txt", "r");
	fgets (buf, TAM, t1);
	n= strlen (buf) + 1;
	frases = malloc (sizeof(char));
	frases[i] = malloc(n * sizeof(char));
	strncpy (frases[i], buf, n);
	printf ("\nfrase %d %s ",i, frases[i]);	
	i++;	

	while (fgets (buf, TAM, t1)) {
	n= strlen (buf) + 1;
	frases = realloc (frases, (i+1)* sizeof(char*));
	if (!frases){
		printf ("\nErro na alocação\n");
		exit (1);}
	frases[i] = malloc(n * sizeof(char));
	strncpy (frases[i], buf, n);
	printf ("\nfrase %d %s ",i, frases[i]);	
	i++;}	
	
	fclose(t1);
	
	i=0;
	
	//colocando segundo texto na memória
	t2 = fopen ("texto2.txt", "r");
	fgets (buf, TAM, t2);
	n= strlen (buf) + 1;
	frases2 = malloc (sizeof(char));
	frases2[i] = malloc(n * sizeof(char));
	strncpy (frases2[i], buf, n);
	printf ("\nfrase %d %s ",i, frases2[i]);	
	i++;	

	while (fgets (buf, TAM, t1)) {
	n= strlen (buf) + 1;
	frases2 = realloc (frases2, (i+1)* sizeof(char*));
	if (!frases2){
		printf ("\nErro na alocação\n");
		exit (1);}
	frases2[i] = malloc(n * sizeof(char));
	strncpy (frases2[i], buf, n);
	printf ("\nfrase %d %s ",i, frases2[i]);	
	i++;}	
	
	fclose(t2);

	lt1 = atoi (argv[3]);
	ct1 = atoi (argv[4]);
	lit2 = atoi (argv[5]);
	cit2 = atoi (argv[6]);
	lft2 = atoi (argv[7]);
	cft2 = atoi (argv[8]);
	
	l2 = lt1;

	for (l = lit2; l <= lft2; l++){
		c2 = ct1;	
		for (c = cit2; c <= cft2; c++){
			frases[l2][c2] = frases2[l][c];
			c2++;}
				
		l2++;}

	/*for (c2 = (ct1 - 1); c2 = (c+1-cit2);c2++){
		frases[lt1-1][c2] = ' ';
		frases[l-lit2+1][c2] = ' ';	}	*/

	for (l=0; l<=i; l++)
		printf ("\n\n%s",frases[l]);

	//printf ("\n linha texto 1 = %d\n", lt1);
	
	


}

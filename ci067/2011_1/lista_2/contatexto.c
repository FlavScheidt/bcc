/*************************
	(contatexto)  Faça um programa que conte linhas, caracteres e palavras lidas da entrada padrão. Considere que uma palavra pode ser 	separada por um ou mais espaços, nova linha e/ou tabulação (’\t’). (Contribuição do Prof. Egon Hilgenstieler). 
*************************/
/************************
	Flaviene Scheidt de Cristo
	FSC10
	GRR20101915
************************/
#include <stdio.h>
/***************
	Funções
***************/
	void leconta(int *palavras, int *letras, int *linhas) {
		char texto;
		int sep = 0;
		texto = getchar();
		while (texto != EOF){
			(*letras)++;
			if (texto == '\n') {
				(*linhas)++;
			}
			if (sep == 0) {
				if (!isalpha(texto)) {
					++(*palavras);
					sep = 1;
				} 
			}  else {
				if (isalpha(texto)) {
				sep = 0;
				}
			}
			texto = getchar();
			(*palavras) = palavras - linhas;		
		}
	}
/***************
	Programa
	Principal
***************/
main () {
	/***** Variáveis *****/
	int pnum = 0; 
	int lenum = 0; 
	int linum = 0;
	/***** Pede a inserção do texto, lê e faz a contagem *****/
	printf("Insira o texto (CRTL D para final da entrada) \n");
	leconta(&pnum, &lenum, &linum);
	/***** Imprimi *****/
	printf("O Texto contém: \n %d letras \n %d palavras \n %d linhas\n", lenum, pnum, linum);
}
	

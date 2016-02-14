/********************************************
	28. (histograma)  Dada uma seq��ncia de N n�meros, determinar quantos 
	n�meros distintos comp�em a seq��ncia e o n�mero de vezes que cada um 
	deles ocorre na mesma. Exemplo:
	N=5
	1 2 3 2 3
	a seq��ncia tem tr�s n�meros distintos, 1, 2 e 3. Ocorr�ncias:
	1 1 vez
	2 2 vezes
	3 2 vezes
********************************************/

/******************************************
	Flaviene Sheidt de Cristo
	FSC10
	GRR20101915
*******************************************/

#include <stdio.h>
/***************
	Estruturas 
***************/
struct elemento {
	int numero;
	int ocorrencias;
}
/***************
	Programa Pincipal
***************/
main () {
	/*** Declara Vari�veis ***/
	int tam;
	int n;
	int i;
	/*** Inicia Vari�veis ***/
	tam = 10;
	/*** Declara Vetores ***/
	int v1[tam];
	/*** L� Vetor ***/
	printf("Insira uma sequencia com %d elementos", tam);
	for (n=0; n<=tam;n++) {
		scanf("%d", &v[n]);
		/*** Verifica exst�ncia ***/
		for (i=0, i<=tam, i++){
			struct elemento v[i];
			if (v[n]==v[i].numero) {
				v[i].ocorrencias = v[i].ocorrencias + 1;
			} else {
				v[n].numero = v[n];
				v[n].ocorrencias = 1;
			}
	}
	
}	
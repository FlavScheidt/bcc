/*************************
	29.(convbin)  Dadas duas seqüências com N números inteiros, cada qual assumindo os valores 0 ou 1, interpretadas como números binários:
	imprimir o valor decimal dos números;
	calcular a soma de ambos (em binário);
	imprimir o valor decimal da soma.
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
 void le(int);
 int decimal (int, int);
/***************
	Programa Principal
***************/
main() {
	/*** Declara Variáveis ***/
	int i, j, valor, tam, n, carry, aux;
	/*** Declara Vetores ***/
	tam = 9;
	int v1[tam];
	int v2[tam];
	int v3[tam];
	/*** Atribuição vazia para o último elemento do vetor ***/
	v1[tam] = \0;
	v2[tam] = \0;
	v3[tam] = \0;
	tam --;
	le(v1);
	le(v2);
	printf("Primeiro numero na base decimal");
	decimal(v1, n);
	printf("%d",n);
	printf("Segundo numero na base decimal");
	decimal(v2, n);
	printf("%d",n);
	/*** Soma ***/
	printf("Soma:");
	carry = 0;
	for (j=0; j<=tam; j++) {
		v3[j]= v2[j] + v1[j] + carry;
		if (v3[j] == 2) {
			v3[j] = 0;
			carry = 1;
		} elseif (v3[j] == 3) {
			v3[j] = 1;
			carry =1;
		}
	}
	if (carry == 1){
		v[tam+1] = 1;
		for (j=tam+1; j<=0; j--){
			aux = v[j-1];
			v3[j-1] = v[j];
			v3[j] = aux;
		}
		for (j=0; j<=tam+1; j++){
			printf("%d", v3[j]);
		}
	} else {
		for (j=0; j<=tam; j++) {
			printf("%d", v3[j]);
		}
	}
	/*** Soma Decimal ***/
	decimal (v3, n);
	printf("Soma decimal: %d", n);
}
/***************
	Funções
***************/
void le (int v[tam])
	printf("Insira um valor binário de oito dígitos");
	for (i=0, i<=tam, i++) {
		scanf("%d", &valor);
		v[i] = valor;
	}
return; }
int decimal (v[tam], n);
	n = 0;
	for (i=tam, i>=0, i--) {
		if (v[i]==1) & (l!= 0){
			for (l=1, <=j, l++){
				n = n + (2*2);
			}
		} elseif((i=0) & (l != 0)) {
			n = n+1;
		}
	}
return n; }
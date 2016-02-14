/*************************
	10 tuplas com três elementos cada.
	Resolve raizes da equação e joga num array
************************/

/************************
	Flaviene scheidt de Cristo
	FSC10
	GRR20101915
************************/

#include <math.h>
#include <stdio.h>
/***************
	Estuturas
***************/
typedef struct conjunto {
	int a;
	int b;
	int c;
	int x1;
	int x2;
} conj;
Main(){
	/*** Declara Variáveis ***/
	int i, delta,a, b, c;
	/*** Declara vetor ***/
	conj v[10];
	/*** Inicia variaveis ***/
	i = 0;
	/*** Lê ***/
	printf("Insira 10 conjuntos de 3 elementos");
	while (i<=9) {
		struct conjunto v[i];
		scanf("%d %d %d", v[i].a, v[i].b, v[i].c);
		i++;
	}
	/*** Encontra raízes ***/
	for (i=0; i<=9; i++){
		struct conjunto v[i];
		a = v[i].a;
		b = v[i].b;
		c = v[i].c;
		delta = (b*b) - (4*a*c);
		delta = sqrt(delta);
		v[i].x1 = (-b+delta)/a;
		v[i].x2 = (-b-delta)/a;
	}
	/*** Imprime ***/
	for (i=0; i<=9; i++){
		struct conjunto v[i];
		printf("%d %d %d \n", v[i].a, v[i].b, v[i].c);
		printf("x1 = %d x2 = %d", v[i].x1, v[i].x2);
	}
}

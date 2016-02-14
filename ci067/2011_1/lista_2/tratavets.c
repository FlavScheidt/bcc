/************************
	(tratavets)  Faça um programa que receba interativamente do usuário 5 conjuntos de 5 inteiros cada e armazene cada conjunto em um
	vetor diferente. Em seguida, para cada elemento de um sexto vetor adicional defina uma referência a cada um dos 5 vetores com 		inteiros. Ao final, seu programa deve imprimir na tela o conteúdo completo de seu “vetor de vetores” (i.e., o sexto vetor). 
************************/
/***********************
	Flaviene Scheidt de Cristo
	FSC10
	GRR20101915
***********************/
#include <stdio.h>
/***************
	Funções
***************/
void le(int v[5]){ //Lê os inteiros interativamente e joga no vetor
	int i;
	for (i = 0; i<5; i++)
		scanf("%d", v+i);
}
void imprime(int v[5]){ //Imprime os valores
	int i;	
	while (*v) {
		i = *v;
		printf("%d ",i);
		v++;
	}
}
/***************
	Programa Principal
***************/
main(){
	/***** Declara Vetores *****/
	int v1[5], v2[5], v3[5], v4[5], v5[5];
	int *v6[5];
	/***** Declara Variáveis *****/
	int i;
	int j;
	/***** Lê vetores *****/
	printf("Insira cinco inteiros \n");
	le(v1);
	printf("Insira mais cinco inteiros \n");
	le(v2);
	printf("Insira outros cinco inteiros \n");
	le(v3);
	printf("E mais cinco \n");
	le(v4);
	printf("Últimos cinco \n");
	le(v5);
	/***** Faz o sexto vetor referenciar os outros cinco *****/
	v6[1] = v1;
	v6[2] = v2;
	v6[3] = v3;
	v6[4] = v4;
	v6[5] = v5;
	/***** Imprime *****/
	j = 0;
	while (j <= 5) {
		imprime(v6[j]);
		j++;
		printf("\n");
	}	
}

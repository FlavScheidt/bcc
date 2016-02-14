/**********************************************
Entram dois vetores desordenados
Sai um vetor ordenado
*********************************************/
#include <stdio.h>
main() {
	/* Declaração de variáveis */
	int tam;
	int i;
	int j;
	int l;
	int k;
	int n;
	int tamv3;
	int valor;
	/* Declaração de vetores */
	tam = 25;
	int v1[tam];
	int v2[tam];
	int v[tam+tam];
	/* Inicia variáveis */
	i,j,l,k = 0;
	/* Lê */
	printf("Insira uma sequencia numerica com no maximo %d elementos",tam);
	while ((scanf("%d",&valor) != EOF) || (i<=tam)) {
		v1[i] = valor;
		i++;
	}
	printf("Insira uma sequencia numerica com menos de %d elmentos",i);
	i--;
	while ((scanf("%d",&valor) != EOF) || (j<=i)){
		v2[j] = valor;
		j ++;
	}
	j--;
	/* Concatena */
	while (k<=i){
		v[k] = v1[l];
		k++;
		l++;
	}
	tamv3 = i+j;
	while (k<=tamv3) {
		v[k] = v2[j];
		k++;
		j++;
	}
	i = 0;
	/* Ordena */
	for (i=tam; i>0; i--){
		if (v[1]<v[i-1]){
			n = v[i-1];
			v[i-1] = v[i];
			v[i] = n;
		}
	
	/* Imprime */
	j = 0;
	while (j<=tamv3) {
		n = v[j];
		printf("%d",n);
		j++;
	}
}

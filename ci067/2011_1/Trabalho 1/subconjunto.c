/***************************************
	Lê primeira sequencia
	Lê segunda sequencia
	Verifica se a segunda está contida na primeira
****************************************/

#include <stdio.h>
main (){
	/* Declaração de variáveis */
	int tam;
	int n;
	int i;
	int j;
	int k;
	int l;
	int compara;
	int pertence;
	/* Declaração de vetores */
	tam = 25;
	int v1[tam];
	int v2[tam];
	/* Inicia variáveis */
	i,j,k,l = 0;
	/* Lê vetores */
	printf("Insira uma sequencia numerica com no maximo %d elementos\n", tam);
	while ((scanf("%d",&n) =! NULL) || (i<=tam)) {
		v1[i] = n;
		i++;
	}
	printf("Insira uma sequencia numérica com menos de %d elementos\n", i);
	i--;
	while ((scanf("%d",&n) =! NULL) || (j<=i)) {
		v2[j] = n;
		j++;
	}
	j--;
	/* Efetua busca para saber se o segundo vetor está contido no primeiro */
	pertence = 0;
	for (l = 0; l<j; l++){
		while ((pertence == 0 )|| (k<=i)) {
			if (v2[l] == v1[k]) {
				pertence = 1;
			}
		}
		if (pertence == 1)
			compara = 1;
		else
			compara = 0;
	}
	if (compara == 1)
		printf("A sequencia 2 está contida na sequencia 1");
	else
		printf("A sequencia 2 não está contida na sequencia 1");
}

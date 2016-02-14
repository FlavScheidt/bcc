#include <stdio.h>
/***************
	FUNÇÕES	
***************/
/*************** Cria o Vetor ***************/
int criavet(int *vet, FILE *fp){
	int i = 1;
	do {
		fscanf (fp,"%d", &vet[i]);
		i++;
	} while (!feof(fp));
	return i;
}

int levet(int *vet, int comeco, int final) { //Lê vet da linha de comando, vet de 10000 posições
}

/*************** Troca ***************/
int troca(int *vet, int arga, int argb) { //Troca posições
	int temporario = vet[arga];
	vet[arga] = vet[argb];
	vet[argb] = temporario;
}

/**************** Particiona **************/
int particiona(int *vet, int comeco, int final) { //Particiona e joga os menores para a esquerda e os maiores para direita
	int x = vet[comeco];
	int i = comeco;
	for (int j=comeco+1; j<=final; j++)
	{
	        if (vet[j] <= x) {
	            i++;
	            troca(vet, i, j);
   		}
	}
	troca(vet, comeco, i);
	return i;
}

/*************** Imprime Vetor ***************/
int imprimevet(int *vet, int comeco, int final) { //Imprime o vet na saída padrão
	for (int i=comeco; i<=final; i++){
		if (vet[i] != 0) {
	        printf("%d\n", vet[i]);  
		}
	}
}

/*************** Menor Elemento do vetor ***************/
int minimo(int *vet, int comeco, int final) { //Encontra o menor elemento do vet e retorna a posição
	int i, menor;
	i = menor = comeco;
	while (i<final)
	{
	        i++;
	        if (vet[i] < vet[menor])
	        	menor = i;
	}
	return menor;
}

/*************** Selection Sort ***************/
int *selectionSort(int *vet, int comeco, int final) { //Ordena por seleção
	if (comeco >= final)
        	return vet;
	troca(vet, comeco, minimo(vet, comeco, final));
	return selectionSort(vet, comeco+1, final);
}

/*************** Quick Select ***************/
int *quickSelect(int *vet, int comeco, int final, int k) { // Ordena por select se o vetor for menor do que k, e por quick se for maior ou igual
	if ((final-comeco+1) < k) // Verifica se deve ordenar por quick ou select
	{
        	selectionSort(vet, comeco, final);
        	return vet;
	} 
	int meio = particiona(vet, comeco, final);
	quickSelect(vet, comeco, meio-1, k);
	quickSelect(vet, meio+1, final, k);
	return vet;
}
/*******************
	Programa Principal
*******************/
int main(){
	int k = 4;
	int max; //tamanho do vetor
	int vet[100000];
	FILE *fp;
	fp = fopen("teste.in", "r");
	max = criavet(vet,fp);
	quickSelect(vet, 0, max-1, k);
	imprimevet(vet, 0, max-1);
}

#include <stdio.h>
#include <stdlib.h>
#include "SistemasLineares.h"

void ImprimeSistema(float sistema[9])
{
	for (int i=0; i<9; i++)
	{
		if (i == 3 || i == 6)
		{
			printf("\n");
		}
		printf("	%f	", sistema[i]);
	}
	printf("\n");
}

void ReducaoGauss()
{
	printf("\n Início \n");
	ImprimeSistema(A1);

	float pivo;
	float mAux;

	int indiceM 	= 0;		//Indice do vetor de multiplicadores
	int indicePivo 	= 0;		//Indice da posicao atual do pivo no vetor A1
	int indiceA; 			//Indice que percorre o vetor A1
	int indicePLin 	= 0;		//Indice das colunas da linha pivo
	int indiceBpivo = 0;		//Indica onde etá a linha pivo em b

	for (int i=1; i<linhas; i++) //Comeca em 1, pois o último elemento da última linha nao zera
	{
		printf("\nRODADA %d", i);
		pivo = A1[indicePivo];
		printf("\n Pivo: %f \n", pivo);
		indiceA = i*linhas;

		for (int l=i; l<linhas; l++) // Comeca em 1, pois a primera linha não é alterada
		{
			mAux		= A1[(indicePivo%linhas)+(linhas*l)]; //Elemento que está na coluna do pivo
			m[indiceM] 	= mAux/pivo;
			indicePLin	= (indicePivo/linhas)*linhas;
			for (int c=0; c<linhas; c++) // Comeca em zero, pois todos as colunas sofrem alteracao
			{
				printf("\n A1[%d] = %f  pLin =  %f \n", indiceA, A1[indiceA], A1[indicePLin]);
				A1[indiceA] = A1[indiceA] - (A1[indicePLin]*m[indiceM]);
				indiceA++;
				indicePLin++;
			}
			//Calculo do b (guardado em outro vetor por conta do refinamento
			b1[l] = b1[l] - (b1[indiceBpivo] * pivo);
			ImprimeSistema(A1);
		}
		printf("\nResultado:\n");
		ImprimeSistema(A1);

		indiceBpivo++; //proxima rodada, a proxima linha eh a linha pivo
		indicePivo = indicePivo+linhas+1; //Indice do pivo é o próximo elemento da diagonal principal
	}
}

void main()
{
	//Inicializa o sistema
	// O sistema é representado por um vetor (otimiza cache)
	linhas 	= 3; //Numero de linhas sempre igual ao de colunas
	int tamVetor 	= linhas*linhas;
	//A = malloc(tamVetor*sizeof(double));
	//x = malloc(tamVetor*sizeof(double));
	//b = malloc(linhas*sizeof(double));

	//m 	= malloc(linhas*sizeof(double));
	//A1 	= malloc(tamVetor*sizeof(double)); 

	//Preenche primeira linha
	A[0] = -3.2;
	A[1] = -5;
	A[2] = -4;

	//Preenche segunda linha
	A[3] = -3;
	A[4] = -2.9;
	A[5] = -2.7;
	
	//Preenche terceira linha
	A[6]= -1.5;
	A[7]= -0.4;
	A[8]= 1.1;

	//Preenche b
	b[0] = 2.5;
	b[1] = -4.4;
	b[2] = 3.5;

	//Vizando preservar o sistema original, copiamos para A1
	for (int i = 0; i<=tamVetor; i++)
	{
		A1[i] = A[i];
	}
	for (int i = 0; i<=linhas; i++)
	{
		b1[i] = b[i];
	}

	ReducaoGauss();
}

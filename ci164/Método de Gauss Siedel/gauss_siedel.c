#include <stdio.h>
#include <stdlib.h>
#include "gauss_siedel.h"

unsigned int modulo(int a, int b)
{
	return (a-b);
}

int ComparaRodadas(int indiceR)
{
	int i;
	int j;
	if (indiceR%2 == 1)
	{
		i = L;
		j = 0;
	}
	else
	{
		i = 0;
		j = L;
	}

	for (int n = 0; n<=L; n++)
	{
		i =+ n; 
		j =+ n;
		if (modulo(R[j], R[i]) > 0.0001)
		{
			return 1;
		}
	}

	return 0;
}

int GaussSiedel ()
{
	float rAux;		
	int n;
	int indiceR;		//Indice do vetor R (resultados parciais)
	int indiceA;		//Indice do vetor A (matriz inicial)
	int indiceMult;		//Indice do multiplicador no vetor R
	int criterioParada = 0;

	indiceR 	= L;
	indiceA 	= 0;
	indiceMult 	= 0;

	while (criterioParada >= 0)
	{
		//Começamos com a linha 0 da matriz, como ela só possui dois elementos, tratamos fora do loop
		//Além do mais, é a primeira linha que se inicia com o valor da iteração anterior, sem o uso
		//dos valores já obtidos nesta iteração
		R[indiceR] = (A[indiceA+2] - A[indiceA-1]*R[indiceMult])/A[indiceA];

		indiceA += 3; 	//Coloca o apontador no início da linha 1
		indiceR++;	//Coloca o apontador na posicao da próxima variável

		for(n = 1; n < L; n++)
		{
			//Quando entramos aqui, sempre temos pelo menos um valor já resolvido para a rodada, o valor multiplica a[indiceA]
			indiceMult = indiceR-1;
			//Calcular os índices no vetor
			rAux = (A[indiceA+3]-A[indiceA]*R[indiceMult]);
			
			//Mas ainda não temos um valor que multiplique A[indiceA+2] para esta rodada, então precisamos
			//voltar para a posição de R onde estão os valores da rodada anterior
			if (indiceR%2 == 1) //Verifica em qual parte do vetor estamos
			{
				indiceMult = 0 + n + 1; 
				//Se estamos na segunda parte, então o resultado da rodada anterior esta na primeira parte
			}
			else
			{
				indiceMult = L + n + 1; //Senao, esta na segunda parte
			}

			R[indiceR] = (rAux-A[indiceA+2]*R[indiceMult])/A[indiceA+1];

			indiceA += 4;
			indiceR ++;
		}

		//Calculamos agora a linha n, que possui apenas dois elementos
		//Nesse caso já temos todos os valores anteriores calculados
		if (indiceR%2 == 1)
		{
			indiceMult = 0;
		}
		else
		{
			indiceMult = L;
		}

		R[indiceR] = (A[indiceA+2] - A[indiceA-1]*R[indiceMult])/A[indiceA];

		//realiza a comparação entre as etapas
		if (ComparaRodadas(indiceR) == 0)
			return 0;
		else if (criterioParada >= 50)
			return 1;

		//Calculamos os índices da próxima iteração
		if (indiceR%2 == 1)
		{
			indiceR 	= 0;
			indiceMult 	= L;
		}
		else
		{
			indiceR 	= L;
			indiceMult	= 0;
		}
		
		indiceA+=4;
	}
}

int main()
{
	//Matriz

	//Primeira linha - Adicionar apenas os valores não nulos para a matriz
	A[0] = 2;
	A[1] = 1;
	A[2] = -1; //Termo independente. Esse pode ser 0

	//Segunda linha

	A[3] = 1;
	A[4] = 2;
	A[5] = 1;
	A[6] = -1;

	//Terceira Linha

	A[7] = 1;
	A[8] = 2;
	A[9] = 1;
	A[10] = -1;

	//Quarta Linha

	A[11] = 1;
	A[12] = 2;
	A[13] = 1;
	A[14] = -1;

	//Quinta Linha
	
	A[15] = 1;
	A[16] = 2;
	A[17] = -1;

	//Iniciamos a primeira parte do vetor de resultados parciais (R) com o valores iniciais
	R[0] = 0;
	R[1] = 0;
	R[2] = 0;
	R[3] = 0;
	R[4] = 0;

	if (GaussSiedel() == 1)
	{
		printf("\n Não convergiu \n");
	}
	else
	{
		printf("\n Sucesso \n");
	}

}

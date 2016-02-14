#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int K, M, N;
/**************
	FUNÇÕES
**************/
void LimpaBuffer (char *string)
{
	int i;
	int tam = strlen(string);
	for (i=0; i<=tam; i++)
	{
		string[i] = '\0';
	}
}
int Existe (char a, char *senha, int i) //Verifica se o caracter já existe na senha
{
	int j;
	for (j = 0; j <= i; j++)
	{
		if (senha[j] == a)
		{
			return 0;
		}
	}
	return 1;
}
int verifica_tentativa(char *tentativa, int *P, int *Q) {
	static char senha[26];
	static int inicio = 1;
	int valida = 0;
	int aux, existe, i, j, tamTentativa, confere = 1;
	char caracter;
	if(inicio)
	{
		inicio = 0;
		// Uma senha aleatória de M caracteres deve ser gerada aqui. Apenas os N primeiros caracteres maiúsculos do alfabeto podem ser utilizados e o mesmo caracter não pode ser utilizado mais de uma vez.
		for (i=0; i<M; i++)
		{
			srand(time(NULL));
			aux = rand() % N;
			caracter = 'A' + aux;
			existe = Existe(caracter, senha, i);
			while (existe == 0)
			{
				srand(time(NULL));
				aux = rand() %N;
				caracter = 'A' + aux;
				existe = Existe(caracter, senha, i);
			}
			senha[i] = caracter;
		}
	}
	printf("\n%s\n", senha);
	// Aqui deve-se testar se a tentativa é válida ou não. Caso a tentativa seja válida, a variável "valida" deve receber um valor diferente de 0.
	tamTentativa = strlen(tentativa);
	if (tamTentativa == M++)
	{
		valida = 1;
		caracter = 'A'+N;
		for (i = 0; i <tamTentativa; i++) //Percorre o vetor tentativa
		{
			if ((tentativa[i] > caracter) || (tentativa[i] < 'A')) //Verifica se o caractere está contido em N
			{	
				confere = 0;
			}
		}
		if (confere == 0) //Se houver algum caratere fora de N
		{
			valida = 0;
		}
	}
	if(!valida)
		return 0;
	// Caso a tentativa seja válida, o valor de i deve receber a quantidade de caracteres que existem na senha, mas estão no lugar errado na tentativa e o valor de j deve receber a quantidade de caracteres que existem na senha e estão no lugar certo na tentativa. Caso um caracter que exista na senha apareça no lugar correto e em um ou mais lugares incorretos, ele deve ser contado somente como um caracter na posição correta, ou seja, ele não deve ser considerado no valor de i.
	/***** Verifica P *****/
	*P = 0;
	*Q = 0;
	for (i = 0; i <= M; i++)
	{
		if (tentativa[i] == senha[i])
		{
			*Q++;
		}
	}
	/***** Verifica Q *****/
	for (i = 0; i <= M; i++)
	{
		for (j = 0; j <= M; j++)
		{
			if (j != i) // Desconsidera quando i e j são iguais, pois essa condição é tratada em P
			{
				if (tentativa[i] == senha [j])
				{
					*P++;
				}
			}
		}
	}
	return 1;
}
/**************
	PROGRAMA PRINCIPAL
**************/
int main(int argc, char **argv) 
{
	int i, P, Q;
	char tentativa[27];
	if(argc != 4) 
	{ // Se o número de parâmetros for maior do que 4, retorna erro
		printf("Parâmetros inválidos!\n");
		return 1;
	}
	/* Transforma os parâmetros em int */
	K = atoi(argv[1]);
	M = atoi(argv[2]);
	N = atoi(argv[3]);
	// Testar aqui se os valores de K, M e N recebem valores válidos!
	if ((K < 10) || (K > 20))
	{
		return 1;
		printf("\nO número de tentativas deve estar entre 10 e 20\n");
	}
	else
	{
		if ((M < 4) || (M > 26))
		{
			printf("\nO tamanho da senha deve estar entre 4 e 26\n");
			return 1;
		}
		else
		{
			if ((N < M) || (N > 26))
			{
				printf("\nO número de caracteres deve estar ser maior do que o tamanho da senha e menor do que 26\n");
				return 1;
			}
		}
	}
	printf("Digite uma senha de %d caracteres utilizando apenas os caracteres ", M);
	/* Imprime os caracteres que podem ser utilizados */	
	for(i=0; i < N-1; i++)
		printf("\'%c\', ", 'A'+i);
	printf("e \'%c\'.\n", 'A'+N-1);
	for(i=0; i < K; i++) //Inicia o as jogadas
	{
		printf("%da tentativa: ", i+1); //Número da tentativa
		scanf("%s", tentativa); //Pega tentativa
		if(verifica_tentativa(tentativa, &P, &Q)) //Verifica se a tentativa é válida
		{
			if(Q == M) //Se todas as letras estiverem no lugar certo, retorna sucesso
			{
				printf("Senha correta!\n");
				break;
			}
			else //Se não, retorna os valores de P e Q
				printf("Senha incorreta: P=%d Q=%d\n", P, Q);
		}
		else 
		{
			printf("Tentativa incorreta!\n");
			i--;
		}
		LimpaBuffer(tentativa); //Limpa a string
	}
	return 0;
}

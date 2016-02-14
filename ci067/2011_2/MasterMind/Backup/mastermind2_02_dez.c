/************************
	Flaviene Scheidt de Cristo
	FSC10
	GRR20101915
************************/
/************************
	Última modificação: 2/Dez/2011
************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int K, M, N;
/**************
	ESTRUTURAS
**************/
typedef struct
{
	char tentativa[27];
	struct nodo *proximo;
}nodo;
typedef struct
{
	struct nodo *primeiro;
	struct nodo *ultimo;
}lista;
/**************
	FUNÇÕES
**************/
lista * CriaLista (lista *l)
{
	l = malloc (sizeof(lista));
	if (!l)
	{
		return NULL;
	}
	l -> primeiro = NULL;
	l -> ultimo = NULL;
	return l;
}
int RemoveLista (lista *l, nodo *n) //Remove de qualquer lugar
{
	nodo *aux;
	if (l -> ultimo == l -> primeiro)
	{
		return 0;
	}
	if ((nodo *)l -> primeiro == n)
	{
		l -> primeiro = n -> proximo;
		free(n);
		return 1;
	}
	aux = (nodo *)l -> primeiro;
	while ((nodo *)aux -> proximo != n)
	{
		aux = (nodo *)aux -> proximo;
	}
	if ((nodo *)l -> ultimo == n)
	{
		aux -> proximo = NULL;
		free(n);
		return 1;
	}
	aux -> proximo = n -> proximo;
	free(n);
	return 1;
}
nodo * InsereLista (char *tentativa, lista *l) //Insere no fim
{
	nodo *novo = malloc(sizeof(nodo));
	if (!novo)
	{
		return NULL;
	}
	strcpy(novo -> tentativa, tentativa);
	novo -> proximo = NULL;
	l -> ultimo = (nodo *) novo;
	return novo;
}
int Existe (char a, char *senha, int i) //Verifica se o caracter já existe
{
	int j;
	for (j = 0; j < i; j++)
	{
		if (senha[j] == a)
		{
			return 0;
		}
	}
	return 1;
}
int ExisteLista (lista *l, char *tentativa)
{
}
void PQ (int *P, int *Q, char *tentativa, char *comparacao) //Contabiliza P e Q
{
	int i, j, existe;
	for (i=0; i<=M; i++)
	{
		if (tentativa[i] == comparacao[i])
		{
			*Q = *Q+1;
		}
		else
		{
			for (j=0; j<i; j++) //Verifica a existência anterior do caracter no vetor. Se já existe, já foi checado
			{
				if (tentativa[i] == tentativa[j])
				{
					existe = 1;
				}
				else
				{
					existe = 0;
				}
			}
			if (existe == 0)
			{
				for (j=0; j<=M; j++) //Percorre o vetor senha procurando por ocorrências
				{
					if (comparacao[j] == tentativa[i])
					{
						*P = *P + 1;
					}
				}
			}
		}
	}
	*Q = *Q - 1;
}
void GeraSenhaAleatoria (char *s)
{
	int i;
	char caracter;
	int aux;
	int existe;
	for (i=0; i < M; i++)
	{
		srand(time(NULL));
		aux = rand() % N;
		caracter = 'A' + aux;
		existe = Existe(caracter, s, i);
		while (existe = 0)
		{
			srand(time(NULL));
			aux = rand() % N;
			caracter = 'A' + aux;
			existe = Existe (caracter, s, i);
		}
		s[i] = caracter;
	}
}
int verifica_tentativa(char *tentativa, int *P, int *Q)
{
	static char senha[26];
	static int inicio = 1;
	int valida = 0;
	int tamTentativa, i, confere;
	char caracter;
	if(inicio) 
	{
		inicio = 0;
		// Uma senha aleatória de M caracteres deve ser gerada aqui. Apenas os N primeiros caracteres maiúsculos do alfabeto podem ser utilizados e o mesmo caracter não pode ser utilizado mais de uma vez.
		GeraSenhaAleatoria(senha);
	}
	// Aqui deve-se testar se a tentativa é válida ou não. Caso a tentativa seja válida, a variável "valida" deve receber um valor diferente de 0.
	tamTentativa = strlen(tentativa);
	if (tamTentativa == M++)
	{
		valida = 1;
		caracter = 'A'+N;
		for (i = 0; i < tamTentativa; i++)
		{
			if ((tentativa[i] > caracter) || (tentativa[i] < 'A'))
			{
				confere == 0;
			}
		}
		if (confere == 0)
		{
			valida = 0;
		}
	}
	if(!valida)
		return 0;
	// Caso a tentativa seja válida, o valor de i deve receber a quantidade de caracteres que existem na senha mas estão no lugar errado na tentativa e o valor de j deve receber a quantidade de caracteres que existem na senha e estão no lugar certo na tentativa. Caso um caracter que exista na senha apareça no lugar correto e em um ou mais lugares incorretos, ele deve ser contado somente como um caracter na posição correta, ou seja, ele não deve ser considerado no valor de i.
	*P = 0;
	*Q = 0;
	PQ(P, Q, tentativa, senha);
	return 1;
}
void gera_tentativa(int k, int P, int Q, char *tentativa) 
{
	int i, j, aux, existe = 0, Pc, Qc;
	char caracter;
	int tentativasPossiveis = M*N;
	static int estado = 0;
	static char tentativaMae[27];
	lista *l;
	// A variável k informa a quantidade de tentativas já realizadas
	// Os variáveis P e Q informam os valores retornados pela função verfica_tentativa para a última tentativa realizada
	// A variável "tentativa" deve receber a nova tentativa
	// Aqui deve ser gerada a tentativa de M caracteres. Apenas os N primeiros caracteres maiúsculos do alfabeto podem ser utilizados, mas uma tentativa pode utilizar o mesmo caracter mais de uma vez.
	switch (estado)
	{
		case 0: //Primeira rodada
			/***** Cria primeira tentativa ABCD... *****/
			for (i = 0; i < M; i++)
			{
				tentativa[i] = 'A' + i;
			}
			strcpy(tentativaMae, tentativa);
			estado = 1;
			break;
		case 1: //Segunda rodada
			/***** Cria lista de tentativas *****/
			l = CriaLista(l);
			if ((P == 0) && (Q == 0))
			{
				tentativasPossiveis = M*N - (M*M);
				/*** Gera senha sem os caracteres ***/
				for (j = 0; j <= tentativasPossiveis; j++)
				{
					srand(time(NULL));
					aux = rand() % N;
					caracter = 'A' + aux + j;
					existe = Existe(caracter, tentativa, i);
					while (existe = 0)
					{
						srand(time(NULL));
						aux = rand() % N;
						caracter = 'A' + aux + j;
						existe = Existe (caracter, tentativa, i);
					}
					tentativa[i] = caracter;
					if (!ExisteLista(l, tentativa))
					{
						InsereLista(tentativa, l);
					}
				}			
			}
			else
			{
				for (j = 0; j <= tentativasPossiveis; j++)
				{
					GeraSenhaAleatoria(tentativa);
					if (ExisteLista(l, tentativa))
					{
						continue;
					}
					/*** Contabiliza P e Q de acordo com a primeira tentativa ***/
					PQ(&Pc, &Qc, tentativa, tentativaMae);
					if ((Pc == P) && (Qc == Q))
					{
						InsereLista(tentativa, l);
					}
				}
			}
			estado = 2;
			break;
		case 2: //Demais rodadas
			break;
	}
}
int main(int argc, char **argv) {
	int i, P, Q, validos = 0;
	char tentativa[27];
	if(argc != 4) 
	{
		printf("Parâmetros inválidos!\n");
		return 1;
	}
	K = atoi(argv[1]);
	M = atoi(argv[2]);
	N = atoi(argv[3]);
	// Testar aqui se os valores de K, M e N recebem valores válidos! Caso recebam, a variável "validos" deve reveber um valor diferente de 0.
	if ((K > 10) && (K < 20))
	{
		validos = 1;
		if ((M < 4) || (M > 26))
		{
			validos = 0;
		}
		if ((N < M) || (N > 26))
		{
			validos = 0;
		}
	}
	if(!validos) 
	{
		printf("Parâmetros inválidos!\n");
		return 1;
	}
	for(i=0; i < K; i++) 
	{
		gera_tentativa(i, P, Q, tentativa);
		tentativa[M] = '\0';
		printf("%da tentativa: %s\n", i+1, tentativa);
		if(verifica_tentativa(tentativa, &P, &Q)) 
		{
			if(Q == M) 
			{
				printf("Senha correta!\n");
				break;
			}
			else
				printf("Senha incorreta!\n");
		}
		else 
		{
			printf("Tentativa incorreta!\n");
			i--;
		}
	}

	return 0;
}

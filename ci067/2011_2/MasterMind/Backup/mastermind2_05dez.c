/************************
	Flaviene Scheidt de Cristo
	FSC10
	GRR20101915
************************/
/************************
	Última modificação: 5/Dez/2011 14:40
************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int K, M, N;
/**************
	ESTRUTURAS
**************/
typedef struct nodo
{
	char tentativa[27];
	struct nodo *proximo;
}nodo;
typedef struct lista
{
	struct nodo *primeiro;
	struct nodo *ultimo;
}lista;
/**************
	FUNÇÕES
**************/
lista * CriaLista ()
{
	lista *l = malloc (sizeof(lista));
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
	char *tentativa;
	if (l -> primeiro == NULL)
	{
		return 0;
	}
	tentativa = l -> primeiro -> tentativa;
	if (l->primeiro == l->ultimo)
	{
		l -> primeiro = NULL;
		free(n);
		return 1;
	}
	aux = l -> primeiro;
	if (l -> primeiro == n)
	{
		l -> primeiro = n -> proximo;
		free(n);
		return 1;
	}
	aux = l -> primeiro;
	while (aux -> proximo != n)
	{
		aux = aux -> proximo;
	}
	if (l -> ultimo == n)
	{
		printf("Ultimo\n");
		aux -> proximo = NULL;
		free(n);
		return 1;
	}
	aux -> proximo = n -> proximo;
	free(aux);
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
	l -> ultimo = novo;
	if (l -> primeiro == NULL)
	{
		l -> primeiro = novo;
	}
	return novo;
}
int Existe (char a, char *senha, int i) //Verifica se o caracter já existe
{
	int j;
	for (j = 0; j < i; j++)
	{
		if (senha[j] == a)
		{
			return 1;
		}
	}
	return 0;
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
		while (existe)
		{
			srand(time(NULL));
			aux = rand() % N;
			caracter = 'A' + aux;
			existe = Existe (caracter, s, i);
		}
		s[i] = caracter;
	}
}
void PQ (int *P, int *Q, char *tentativa, char *comparacao) //Contabiliza P e Q
{
	int i, j, existe = 0;
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
}
char * Troca (char *vetor, int posicao)
{
	char aux;
	aux = vetor[posicao];
	vetor[posicao] = vetor[posicao-1];
	vetor[posicao-1] = aux;
	return vetor;
}
int verifica_tentativa(char *tentativa, int *P, int *Q)
{
	static char senha[26];
	static int inicio = 1;
	int valida = 1;
	int tamTentativa, i, confere = 1;
	char caracter;
	int auxP = 0, auxQ = 0;
	if(inicio) 
	{
		inicio = 0;
		// Uma senha aleatória de M caracteres deve ser gerada aqui. Apenas os N primeiros caracteres maiúsculos do alfabeto podem ser utilizados e o mesmo caracter não pode ser utilizado mais de uma vez.
		GeraSenhaAleatoria(senha);
		printf("senha: %s\n", senha);
	}
	// Aqui deve-se testar se a tentativa é válida ou não. Caso a tentativa seja válida, a variável "valida" deve receber um valor diferente de 0.
	tamTentativa = strlen(tentativa);
	if (tamTentativa == M--)
	{
		valida = 1;
		caracter = 'A'+N;
		for (i = 0; i < M; i++)
		{
			if ((tentativa[i] > caracter) || (tentativa[i] < 'A'))
			{
				confere = 0;
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
	PQ(&auxP, &auxQ, tentativa, senha);
	*P = auxP;
	*Q = auxQ;
	return 1;
}
void gera_tentativa(int k, int P, int Q, char *tentativa) 
{
	int i, j, aux, existe = 0, Pc, Qc;
	char caracter;
	int tentativasPossiveis = M*N;
	static int estado = 0;
	static char *tentativaMae;
	int posicao;
	lista *l = CriaLista();
	nodo *n;
	nodo *p;
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
			tentativaMae = malloc(M-1*(sizeof(char)));
			strcpy(tentativaMae, tentativa);
			estado = 1;
			break;
		case 1: //Segunda rodada
			if ((P == 0) && (Q == 0))
			{
				printf("Entra no if\n");
				getchar();
				tentativasPossiveis = M*N - (M*M);
				/*** Gera senha sem os caracteres ***/
				for (j = 0; j <= tentativasPossiveis; j++)
				{
					srand(time(NULL));
					aux = rand() % N;
					caracter = 'A' + aux + j;
					existe = Existe(caracter, tentativa, j);
					while (existe)
					{
						srand(time(NULL));
						aux = rand() % N;
						caracter = 'A' + aux + j;
						existe = Existe (caracter, tentativa, j);
					}
					tentativa[j] = caracter;
					InsereLista(tentativa, l);
				}			
			}
			else
			{
				getchar();
				posicao = M;
				for (i = 0; i < M-1; i++)
				{
					tentativa[i] = 'A'+ i;
				}
				for (j = 0; j < tentativasPossiveis-1; j++)
				{
					Pc = 0;
					Qc = 0;
					tentativa = Troca(tentativa, posicao);
					if(posicao == 1)
					{
						posicao = M;
					}
					else
					{
						posicao--;
					}
					/*** Contabiliza P e Q de acordo com a primeira tentativa ***/
					PQ(&Pc, &Qc, tentativa, tentativaMae);
					printf("%d %d\n", Pc, Qc);
					if ((Pc == P) && (Qc == Q))
					{
						InsereLista(tentativa, l);
						printf("%s\n", l -> ultimo -> tentativa);
						printf("Insere na lista\n");
					}
				}
			}
			/*** Retira Primeira Tentativa e Compara com a senha ***/
			n = l -> primeiro;
			tentativa = l -> primeiro -> tentativa;
			printf("%s\n", tentativa);
			printf("\n-----------------------------\n");
			for( p = l-> primeiro; p->proximo != NULL; p = p -> proximo)
			{
				printf("%s", p -> tentativa);
			}
			printf("\n-----------------------------\n");
			if (!RemoveLista(l, n))
			{
				printf("Erro!\n");
			}
			printf("%s\n", tentativa);
			estado = 2;
			break;
		case 2: //Demais tentativas
			for (p = (nodo *) l -> primeiro; p -> proximo != NULL; p = (nodo *) p -> proximo)
			{
				Pc = 0;
				Qc = 0;
				PQ(&Pc, &Qc, p -> tentativa, tentativaMae);
				if ((Pc != P) || (Qc != P))
				{
					if(!RemoveLista(l, l -> primeiro))
					{
						printf("Erro\n");
					}
				}
				/*** Compara o primeiro da lista ***/
				tentativa = l -> primeiro -> tentativa;	
				strcpy(tentativaMae, tentativa);
				if(!RemoveLista(l, l -> primeiro))
				{
					printf("Erro!\n");
				}
			}
			break;
	}
}
int main(int argc, char **argv) 
{
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
	if ((K >= 10) && (K <= 20))
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
			printf("%d %d\n", P, Q);
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

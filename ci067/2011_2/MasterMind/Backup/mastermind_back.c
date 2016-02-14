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
#include <time.h>
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
	nodo *primeiro;
	nodo *ultimo;
	int tam;
}lista;
/**************
	FUNÇÕES
**************/
lista * CriaLista ()
{
	lista *l = malloc(sizeof(lista));
	l -> ultimo = l -> primeiro = NULL;
	l -> tam = 0;
	return l;
}
int RemoveFila (lista *l)//Remove do início
{
	if (l -> tam == 0)
	{
		return 0;
	}
	nodo *n;
	n = l -> primeiro;
	l -> primeiro = n -> proximo;
	free(n);
	l -> tam--;
	return 1;
}
int RemoveLista (lista *l, nodo *n) //Remove de qualquer lugar
{
	nodo *o;
	/***** Se estiver vazia *****/
	if (l -> tam == 0)
	{
		return 0;
	}
	if (l -> primeiro == n)
	{
		if (!RemoveFila(l))
		{
			return 1;
		}
	}
	/***** Pega o nodo anterior *****/
	o = l -> primeiro;
	while (o -> proximo != n)
	{
		o = o -> proximo;
	}
	/***** Caso esteja removendo o último ítem da lista *****/
	if (l -> ultimo)
	{
		l -> ultimo = o;
		o -> proximo =  NULL;
		free(n);
		l -> tam--;
		return 1;
	}
	o -> proximo = n -> proximo;
	free(n);
	l -> tam--;
	return 1;
}
nodo * InsereFila (char *tentativa, lista *l) //Insere no final  
{
	nodo *n = malloc(sizeof(nodo));
	strcpy(n -> tentativa, tentativa);
	n -> proximo = NULL;
	l -> ultimo = n;
	if (l -> tam == 0)
	{
		l -> primeiro = n;
	}
	l -> tam++;
	return n;
}
int ExisteLista(lista *l, char *tentativa)
{
	if (l -> tam == 0)
	{
		return 0;
	}
	nodo *n;
	for (n = l -> primeiro; n -> proximo != NULL; n = n -> proximo)
	{
		if (n -> tentativa == tentativa)
		{
			return 1;
			free(n);
		}
	}
	return 0;
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
	for (i=0; i<M; i++)
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
				for (j=0; j<M; j++) //Percorre o vetor senha procurando por ocorrências
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
lista * GeraLista(char *tentativa, int P, int Q, lista *l)
{
	int numTentativas = M, Pc, Qc;
	int i;
	char novaTentativa[27];
	/****** Calcula o número de tentativas possíveis ******/
	for (i = M-1; i > 0; i--)
	{
		numTentativas = numTentativas*i;
	}
	/***** Gera Tentativas Possiveis *****/
	for (i = 0; i < numTentativas-1; i++)
	{
		Pc = Qc = 0;
		GeraSenhaAleatoria(novaTentativa);
		if (ExisteLista(l, novaTentativa))
		{
			continue;
		}
		PQ(&Pc, &Qc, novaTentativa, tentativa);
		if ((Pc == P) && (Qc == Q))
		{
			InsereFila(novaTentativa, l);
		}
	}
	return l;
}
lista * RefinaLista (lista *l, char *tentativa, int P, int Q)
{
	nodo *n;
	int Pc, Qc;
	printf("%s\n", l->primeiro->proximo->tentativa);
	for (n = l -> primeiro; n  -> proximo != NULL; n = n -> proximo)
	{
		PQ(&Pc, &Qc, n -> tentativa, tentativa);
		if ((Pc != P) && (Qc != Q))
		{
			RemoveLista(l, n);
		}
	}
	free(n);
	return l;
}
int verifica_tentativa(char *tentativa, int *P, int *Q)
{
	static char senha[26];
	static int inicio = 1;
	int valida = 1;
	int mAux;
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
	mAux = M-1;
	if (tamTentativa == mAux)
	{
		valida = 1;
		caracter = 'A'+N;
		for (i = 0; i < mAux; i++)
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
	int i;
	static int estado = 0;
	lista *l = malloc(sizeof(lista));
	l = CriaLista();
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
			estado = 1;
			break;
		case 1: //Segunda rodada
			l = GeraLista(tentativa, P, Q, l);
			/***** Pega o último ítem da lista e joga em tentativa *****/ 
			strcpy(tentativa, l -> ultimo -> tentativa);
			if (!RemoveFila(l))
			{
				printf("Erro!\n");
				exit(0);
			}
			printf("%d\n", l -> tam);
			estado = 2;
			break;
		case 2: //Demais tentativas
			RefinaLista(l, tentativa, P, Q);
			strcpy(tentativa, l -> ultimo -> tentativa);
			if (!RemoveFila(l))
			{
				printf("Erro\n");
				exit(0);
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

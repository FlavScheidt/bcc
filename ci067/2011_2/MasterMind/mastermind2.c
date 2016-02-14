/************************
	Flaviene Scheidt de Cristo
	FSC10
	GRR20101915
************************/
/************************
	Última modificação: 15/Dez/2011
************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int K, M, N;
typedef char* tentativas;
/**************
	FUNÇÕES
**************/
void TiraEnter (char *v)
{
	int tam = strlen(v);
	v[tam] = '\0';
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
void GeraLista(char *tentativa, char *v, int P, int Q, int n, int inicio, FILE *arq, int *numTentativas)
{
	int Pc, Qc;
	int i;
	char aux;
	if (inicio == n-1) 
	{
		Pc = 0; 
		Qc = 0;
		PQ(&Pc, &Qc, v, tentativa);
		if ((Pc == P) && (Qc == Q))
		{
			fprintf(arq, "%s\n", v);
			*numTentativas = *numTentativas+1;
		}
  	}
  	else 
	{
    		for (i = inicio; i < n; i++) 
		{
      			aux = v[i];
      			v[i] = v[inicio];
      			v[inicio] = aux;
      			GeraLista(tentativa, v, P, Q, n, inicio+1, arq, numTentativas);
      			v[inicio] = v[i];
      			v[i] = aux;
		}
	}
}
void RefinaLista (char *tentativa, int P, int Q, FILE *arq, char *disable, int numTentativas)
{
	int Pc, Qc;
	int i = 0;
	char novaTentativa[27];
	int pos;
	rewind(arq);
	while (i <= numTentativas)
	{
		pos = ftell(arq);
		fread(novaTentativa, M+1*sizeof(char), 1, arq);
		i++;
		while (novaTentativa[1] == '-')
		{
			pos = ftell(arq);
			fread(novaTentativa, M+1*sizeof(char), 1, arq);
			i++;
		}
		TiraEnter(novaTentativa);
		Pc = Qc = 0;
		PQ(&Pc, &Qc, novaTentativa, tentativa);
		if ((Pc != P) || (Qc != Q))
		{
			fseek(arq, pos, 0);
			fwrite(disable, M+1*sizeof(char), 1, arq);
		}
	}
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
		printf("\nSenha: %s\n", senha);
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
	static char disable[27];
	static int pos = 0;
	char novaTentativa[27];
	FILE *arq;
	static int numTentativas = 0;
	// A variável k informa a quantidade de tentativas já realizadas
	// Os variáveis P e Q informam os valores retornados pela função verfica_tentativa para a última tentativa realizada
	// A variável "tentativa" deve receber a nova tentativa
	// Aqui deve ser gerada a tentativa de M caracteres. Apenas os N primeiros caracteres maiúsculos do alfabeto podem ser utilizados, mas uma tentativa pode utilizar o mesmo caracter mais de uma vez.
	/*** Cria Caracter Disable ***/
	for (i=0; i<M; i++)
	{
		disable[i] = '-';
	}
	disable[M] = '\n';
	disable[M+1] = '\0';
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
			/*** Cacula o tamanho do vetor de tentativas ***/
			arq = fopen("arq.dat", "w+");
			strcpy(novaTentativa, tentativa);
			GeraLista(tentativa, novaTentativa, P, Q, M, 0, arq, &numTentativas);
			fclose(arq);
			arq = fopen("arq.dat", "r + b");
			fgets(tentativa, M+1*sizeof(char), arq); 
			TiraEnter(tentativa);
			rewind(arq);
			fwrite(disable, M+1*sizeof(char), 1, arq);
			fprintf(arq, "\n");
			pos = ftell(arq);
			estado = 2;
			fclose(arq);
			break;
		case 2: //Demais tentativas
			arq = fopen("arq.dat", "r + b");
			RefinaLista(tentativa, P, Q, arq, disable, numTentativas);
			rewind(arq);
			fread(tentativa, M+1*sizeof(char), 1, arq);
			while (tentativa[1] == '-')
			{
				fread(tentativa, M+1*sizeof(char), 1, arq);
			}
			printf("teste: %s\n", tentativa);
			TiraEnter(tentativa);
			fwrite(disable, M+1*sizeof(char), 1, arq);
			fclose(arq);
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

/************************
	Flaviene Scheidt de Cristo
		FSC10
		GRR20101915
	Bruno Rodolfo Mayer de Souza
		BRMS07
		GRR20075600
************************/
/**************
	Tipos
**************/
typedef struct Pilha 
{
	float *pilha;
	int tamanho;
	float *topo;
}Pilha;
/**************
	Funções
**************/
void IniciaPilha (Pilha *);
int Vazia (Pilha *);
void Empilha (Pilha *, float);
float Desempílha (Pilha *, float);
void Desaloca (Pilha *);

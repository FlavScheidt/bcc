/************************
	Flaviene Scheidt de Cristo
		FSC10
		GRR20101915
	Bruno Rodolfo Mayer de Souza
		BRMS07
		GRR20075600
************************/
/************************
	Comentários Gerais:
		Biblioteca dinâmica para manipulação de pilhas
		Esta biblioteca utiliza três estruturas, uma para a pilha, outra para cada nodo
		e uma terceira para os dados que cada nodo deve guardar. As estruturas são descritas
************************/
/***********************
	DEFINIÇÃO DE TIPOS
***********************/
	typedef struct //Guarda os dados contidos dentro dos nodos
	{
		int Chave; //Identificador do nodo
		float Dado1; //Dado
		/*** Outros dados ***/
	}estruturaDados;
	typedef struct //Estrutura dos nodos
	{
		estruturaDados Item; //Dados
		estruturaNodo *Prox; //Ponteiro para o próximo nodo
	}estruturaNodo;
	typedef struct
	{
		estruturaNodo *Topo; //Apontador para o nodo cabeça
		int Tamanho; //Número de nodos da pilha
	}
/***********************
	FUNÇÕES
***********************/
	void IniciaPilha (estruturaPilha); //Inicia a pilha (cria o nodo cabeça)
	int Vazia (estruturaPilha); //Verifica se a pilha está vazia
	void Empilha (estruturaDados, estruturaPilha); //Empilha nodo elemento
	void Desempilha (estruturaPilha, estruturaDados); //Desempilha elemento e coloca em um valor de retorn

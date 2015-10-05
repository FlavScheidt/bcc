**********************************************************************************
*********************** AUTORES***************************************************
**********************************************************************************
* luism & marcos
**********************************************************************************
*********************** ESTRUTURAS USADAS ****************************************
**********************************************************************************
1) Estrutura Lista
2) Estrutura No
3) Estrutura Grafo
4) Estrutura Vertice
5) Estrutura Aresta

**********************************************************************************

1) A estrutura lista contém, ponteiro para o primeiro/ultimo no.

2) A estrutura No contém um ponteiro para o proximo nó e um void* com o conteúdo, que pode ser um grafo, um vertice ou uma aresta.

3) A estrutura "grafo" guarda todas as informações relevantes para um grafo:

	- Um inteiro para saber se o grafo é direcionado.
	- Um inteiro para saber se o grafo possui pesos.
	- Um array de vértices.


3) A estrutura "vertice" guarda as informações dos vertices:

	- Uma lista de arestas de saída.
	- Uma lista de arestas de chegada.
	- Uma string com o nome do vertice.
	- Informações úteis como 
	
4) A estrutura "aresta" guarda as informações das arestas:

	- Um ponteiro para o vertice da cauda.
	- Um ponteiro para o vertice da cabeça.
	- Um inteiro para guardar o peso da aresta.
	- Informações úteis como tamanho, cor, etc...
	
**********************************************************************************
************************ BUG's conhecidos ***************************************
**********************************************************************************

Funções Implementadas:
- Arborescencia de caminhos mínimos
- Ordenação Topológica
- Arvore Geradora Mínima


Funções Não Implementadas
- Distancias
- Diametro
- Conexo/Fortemente conexo
- Blocos
- Componentes
- Destroi Lista/Destroi Grafo


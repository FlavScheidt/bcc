#include <stdio>
#include "lista.h"
#include "grafo.h"

struct grafo 
{
	char * nome;
	lista * listaVertices;
	unsigned int numVertices;
	unsigned int numArestas;
	int direcionado;
	int ponderado;
} grafo;

typedef struct vertices
{
        char *nome;
        lista listaArestasEntrada;
        lista listaArestasSaida;
        unsigned int grauEntrada;
        unsigned int grauSaida;
} vertices;

typedef struct arestas
{
        unsigned int peso;
        vertices * ponta1;
        vertices * ponta2;
}

char *nome_grafo(grafo g)
{
	return g.nome;
}

int direcionado(grafo g)
{
	return g.direcionado;
}

int ponderado(grafo g)
{
	return g.ponderado;
}

unsigned int n_vertices(grafo g)
{
	return g.numVertices;
}

unsigned int n_arestas(grafo g)
{
	return g.numArestas;
}

char *nome_vertice(vertice v)
{

        return v.nome;
}

//------------------------------------------------------------------------------
// lê um grafo no formato dot de input, usando as rotinas de libcgraph
// 
// desconsidera todos os atributos do grafo lido exceto o atributo
// "peso" quando ocorrer; neste caso o valor do atributo é o peso da
// aresta/arco que é um long int
// 
// num grafo com pesos todas as arestas/arcos tem peso
// 
// o peso default de uma aresta num grafo com pesos é 0
// 
// todas as estruturas de dados alocadas pela libcgraph são
// desalocadas ao final da execução
// 
// devolve o grafo lido ou
//         NULL em caso de erro 

grafo le_grafo(FILE *input)
{
        Agraph_t *g = agread(input, NULL);
        Agnode_t *v;
        Agedge_t *a;
        
        void * aux;
        grafo           new     = malloc(sizeof(grafo));
        vertices        vt      = malloc(sizeof(vertices));
        arestas         ar      = malloc(sizeof(arestas));

        if ( !g )
                return NULL;
      
                
        strcmp(new.nome, agnameof(g))
        new.direcionado         = agisdirected(g);
        new.numVertices         = agnnodes(g);
        new.numArestas          = agnedges(g);
        new.ListaVertices       = constroi_lista();
        
        //Insere vértices
        //Necessário colocar antes os vértices, pois a lista de adjacências é uma lista de ponteiros
        for (int i=0; i<new.numVertices; ++i)
        {
                vt.nome         = agnameof(v);
                
                vt.listaArestasSaida = constroi_lista();
                if (newdirecionado == 1)
                        vt.listaArestasEntrada = constroi_lista();
                else
                        vt.ListaArestasEntrada = NULL;
                      
                insere_lista(vt, new.ListaVertices);
        }

        agclose();
        
        return new;
}

//------------------------------------------------------------------------------
// desaloca toda a memória usada em *g
// 
// devolve 1 em caso de sucesso ou
//         0 caso contrário
// 
// g é um (void *) para que destroi_grafo() possa ser usada como argumento de
// destroi_lista()

int destroi_grafo(void *g);

//------------------------------------------------------------------------------
// escreve o grafo g em output usando o formato dot, de forma que
// 
// 1. todos os vértices são escritos antes de todas as arestas/arcos 
// 
// 2. se uma aresta tem peso, este deve ser escrito como um atributo 
//    de nome "peso"
//
// devolve o grafo escrito ou
//         NULL em caso de erro 

grafo escreve_grafo(FILE *output, grafo g);


lista vizinhanca(vertice v)
{
        return v.listaArestasSaida;
}

lista vizinhanca_entrada(vertice v)
{
        return v.listaArestasEntrada;       
}

lista vizinhanca_saida(vertice v)
{
        return v.listaArestasSaida;
}

unsigned int grau(vertice v)
{
        return v.grauSaida;
}

unsigned int grau_entrada(vertice v)
{
        return v.grauEntrada;
}

unsigned int grau_saida(vertice v)
{
        return v.grauSaida;
}

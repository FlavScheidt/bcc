#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <graphviz/cgraph.h>
#include "lista.h"
#include "grafo.h"

struct grafo 
{
	char nome[65];
	lista listavertice;
	unsigned int numvertice;
	unsigned int numArestas;
	int direcionado;
	int ponderado;
};

struct vertice
{
        char nome[65];
        lista listaArestasEntrada;
        lista listaArestasSaida;
        unsigned int grauEntrada;
        unsigned int grauSaida;
};

struct arestas
{
        int peso;
        vertice ponta;
};

char *nome_grafo(grafo g)
{
	return g->nome;
}

int direcionado(grafo g)
{
	return g->direcionado;
}

int ponderado(grafo g)
{
	return g->ponderado;
}

unsigned int n_vertices(grafo g)
{
	return g->numvertice;
}

unsigned int n_arestas(grafo g)
{
	return g->numArestas;
}

char *nome_vertice(vertice v)
{

        return v->nome;
}

//Busca vértice
vertice * buscaVertice(char * nome)
{
}

void guarda_arestas(Agraph_t *g, grafo new)
{
        Agedge_t *a;
        Agnode_t *v;
        arestas ar = malloc(sizeof(arestas));
                
        if (new->direcionado)
        {
                for (v=agfstnode(g); v; v=agnxtnode(g,v))
                {
                        //new->grauSaida = 0;
                        //new->gauEntrada = 0;
                        //Arestas saida
                         for (a=agfstout(g,v); a; a=agnxtout(g,a))
                         {
                               ar->peso = agget(a, (unsigned int)"ar->peso");
                               ar->ponta = buscaVertice(aghead(a));
                               //new->grauSaida++;
                         }
                         //Arestas entrada
                         for (a=agfstout(g,v); a; a=agnxtout(g,a))
                         {
                               ar->peso = agget(a, (unsigned int)"ar->peso");
                               ar->ponta = buscaVertice(agtail(a));
                               //new->grauEntrada++;
                         }
                }
        }
        else
        {
                for (v=agfstnode(g); v; v=agnxtnode(g,v))
                {
                        for (a=agfstedge(g,v); a; a=agnxtedge(g,a,v))
                        {
                                ar->peso = agget(a, (unsigned int)"ar->peso");
                                ar->ponta = buscaVertice(aghead(a));
                                //new->grauSaida++;
                        }
                }
        }
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

static Agraph_t * armazena_grafo(Agraph_t *g, grafo new)
{
        int i=0;

        Agnode_t *v;
        
        no              n;
        void            *aux;
        vertice         vt      = malloc(sizeof(vertice));
        
        //cria novo grafo        
        strcpy(new->nome, agnameof(g));
        new->direcionado         = agisdirected(g);
        new->numvertice          = agnnodes(g);
        new->numArestas          = agnedges(g);
        new->listavertice        = constroi_lista();
        
        //Insere vértices
        //Necessário colocar antes os vértices, pois a lista de adjacências é uma lista de ponteiros
        for (v=agfstnode(g); v; v=agnxtnode(g,v))
        {
                strcpy(vt->nome, agnameof(v));
                
                //Cria listas de arestas
                vt->listaArestasSaida = constroi_lista();
                if (new->direcionado == 1)
                {
                        vt->listaArestasEntrada = constroi_lista();              
                }
                else
                {
                        vt->listaArestasEntrada = NULL;
                        
                }
                              
                //Insere vértice na lista
                n = insere_lista(vt, new->listavertice);
        }
        
        guarda_arestas(g, new);

        return g;
}

grafo le_grafo(FILE *input)
{
        grafo * new = malloc(sizeof(grafo));
        Agraph_t *g = agread(input, NULL);
        
        if ( !g )
                return NULL;
      
      
        agclose(armazena_grafo(g, new));
        
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

int destroi_grafo(void *g)
{
}

//------------------------------------------------------------------------------
// escreve o grafo g em output usando o formato dot, de forma que
// 
// 1-> todos os vértices são escritos antes de todas as arestas/arcos 
// 
// 2-> se uma aresta tem peso, este deve ser escrito como um atributo 
//    de nome "peso"
//
// devolve o grafo escrito ou
//         NULL em caso de erro 

grafo escreve_grafo(FILE *output, grafo g)
{
}


lista vizinhanca(vertice v)
{
        return v->listaArestasSaida;
}

lista vizinhanca_entrada(vertice v)
{
        return v->listaArestasEntrada;       
}

lista vizinhanca_saida(vertice v)
{
        return v->listaArestasSaida;
}

unsigned int grau(vertice v)
{
        return v->grauSaida;
}

unsigned int grau_entrada(vertice v)
{
        return v->grauEntrada;
}

unsigned int grau_saida(vertice v)
{
        return v->grauSaida;
}

#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <graphviz/cgraph.h>
#include "lista.h"
#include "grafo.h"

//------------------------------------------------------------------------------
// (apontador para) estrutura de dados para representar um grafo
// 
// o grafo pode ser
// - direcionado ou não
// - com pesos nas arestas ou não
// 
// além dos vértices e arestas, o grafo tem um nome, que é uma "string"
// 
// num grafo com pesos nas arestas todas as arestas tem peso, que é um long int
// 
// o peso default de uma aresta é 0

struct grafo
{
        char nome[32];
        unsigned int numArestas;
        unsigned int numVertices;
        int ponderado;
        int direcionado;
        lista listaArestas;
        lista listaVertices;
};

struct aresta
{
        vertice tail;
        vertice head;
        char * peso;
};

struct vertice
{
        char nome[32];
        unsigned int grauEntrada;
        unsigned int grauSaida;
};

//------------------------------------------------------------------------------
// devolve o nome do grafo g

char *nome_grafo(grafo g)
{
        return g->nome;
}

//------------------------------------------------------------------------------
// devolve 1, se g é direcionado, ou
//         0, caso contrário

int direcionado(grafo g)
{
        return g->direcionado;
}

//------------------------------------------------------------------------------
// devolve 1, se g tem pesos nas arestas/arcos,
//      ou 0, caso contrário

int ponderado(grafo g)
{
       return g->ponderado;
}

//------------------------------------------------------------------------------
// devolve o número de vértices do grafo g

unsigned int n_vertices(grafo g)
{
        return g->numVertices;
}

//------------------------------------------------------------------------------
// devolve o número de arestas/arcos do grafo g

unsigned int n_arestas(grafo g)
{
        return g->numArestas;
}

//------------------------------------------------------------------------------
// devolve o nome do vertice v

char *nome_vertice(vertice v)
{
        return v->nome;
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

vertice buscaVertice(char * nome, grafo g)
{
        for (no n=primeiro_no(g->listaVertices); n; n=proximo_no(n))
        {       
                if (strcmp(nome, nome_vertice(conteudo(n))) == 0)
                        return conteudo(n);
        }
        return NULL;
}

aresta buscaAresta(char * head, char * tail, grafo g)
{
        aresta ar;
        
        if (g->direcionado)
        {
                for (no n=primeiro_no(g->listaArestas); n; n=proximo_no(n))
                {       
                        ar = conteudo(n);
                        if (strcmp(head, nome_vertice(ar->head)) == 0 && strcmp(tail, nome_vertice(ar->tail)) == 0)
                                return ar;
                }
        }
        else
        {
                for (no n=primeiro_no(g->listaArestas); n; n=proximo_no(n))
                {       
                        ar = conteudo(n); 
                        if ((strcmp(head, nome_vertice(ar->head)) == 0 && strcmp(tail, nome_vertice(ar->tail)) == 0) ||
                           (strcmp(head, nome_vertice(ar->tail)) == 0 && strcmp(tail, nome_vertice(ar->head)) == 0))     
                                return ar;
                }
        }
        
        return NULL;
}

void insereNovoVertice(Agnode_t * v, grafo new)
{
        vertice vt = malloc(sizeof(vertice));
        
        strcpy(vt->nome, agnameof(v));
        vt->grauEntrada = 0;
        vt->grauSaida   = 0;
        
        no n = insere_lista(vt, new->listaVertices);
        vt = conteudo(n);
}

void insereNovaAresta(Agnode_t * v, Agedge_t * a, grafo new)
{      
       aresta ar = malloc(sizeof(aresta));
       
       ar->head = buscaVertice(agnameof(aghead(a)), new);
       if (ar->head == NULL)
       {
                insereNovoVertice(aghead(a), new);
                ar->head = conteudo(primeiro_no(new->listaVertices));
        }
        
        ar->tail = buscaVertice(agnameof(agtail(a)), new);
        if (ar->tail == NULL)
        {
                insereNovoVertice(agtail(a), new);
                ar->tail = conteudo(primeiro_no(new->listaVertices));
        }
       
        ar->peso = agget(a, (char *)"peso");
        if (ar->peso == NULL)
                ar->peso = "0\0";
       
       no n = insere_lista(ar, new->listaArestas);
}


static Agraph_t * guardaGrafo(Agraph_t *g, grafo new)
{
        aresta ar;
        
        new->listaArestas       = constroi_lista();
        new->listaVertices      = constroi_lista();
        strcpy(new->nome, agnameof(g));
        new->direcionado        = agisdirected(g);
        new->ponderado          = 0; //Só saberemos com certeza quando iniciarmos a importação
        new->numArestas         = agnedges(g);
        new->numVertices        = agnnodes(g);
        
        //Vamos guardar as arestas
        for (Agnode_t *v=agfstnode(g); v; v=agnxtnode(g,v)) 
        {
                //Busca vértice na lista, se não existir, aloca novo grafo
                if (buscaVertice(agnameof(v), new) == NULL)
                        insereNovoVertice(v, new);
                        
                for (Agedge_t *a=agfstedge(g,v); a; a=agnxtedge(g,a,v))
                {
                        if (buscaAresta(agnameof(aghead(a)), agnameof(agtail(a)), new) == NULL)
                                insereNovaAresta(v, a, new);
                }
        }
        
        return g;
}

grafo le_grafo(FILE *input)
{
        Agraph_t *g = agread(stdin, NULL);
        grafo new = malloc(sizeof(grafo));

        if ( !g )
                return NULL;

        agclose(guardaGrafo(g, new));
        
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
// 1. todos os vértices são escritos antes de todas as arestas/arcos 
// 
// 2. se uma aresta tem peso, este deve ser escrito como um atributo 
//    de nome "peso"
//
// devolve o grafo escrito ou
//         NULL em caso de erro 

grafo escreve_grafo(FILE *output, grafo g)
{
        char dir[3];
        aresta ar;
        
        dir[0] = '-';
        dir[1] = g->direcionado ? '>' : '-';
        dir[2] = '\0';

        fprintf(output, "strict graph %s {\n", nome_grafo(g));fflush(output);
        for (no n=primeiro_no(g->listaArestas); n; n=proximo_no(n))
        {  
                ar = conteudo(n);
                fprintf(output, "%s %s %s [peso=%s]\n", nome_vertice(ar->tail), dir, nome_vertice(ar->head), ar->peso);fflush(output);
        }
        fprintf(output, "}\n");fflush(output);
        
        return g;
}

//------------------------------------------------------------------------------
// devolve a vizinhança do vértice v

lista vizinhanca(vertice v);
//------------------------------------------------------------------------------
// devolve a vizinhança de entrada do vértice v

lista vizinhanca_entrada(vertice v);

//------------------------------------------------------------------------------
// devolve a vizinhança de saída do vértice v

lista vizinhanca_saida(vertice v);

//------------------------------------------------------------------------------
// devolve o grau do vértice v

unsigned int grau(vertice v);

//------------------------------------------------------------------------------
// devolve o grau de entrada do vértice v

unsigned int grau_entrada(vertice v);

//------------------------------------------------------------------------------
// devolve o grau se saída do vértice v

unsigned int grau_saida(vertice v);

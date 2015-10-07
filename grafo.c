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
vertice buscaVertice(char * nome, grafo new)
{
        vertice vt;
        for (no n=primeiro_no(new->listavertice); n; n=proximo_no(n))
        {
                vt = conteudo(n);
                if (strcmp(vt->nome, nome) == 1)
                        return vt;
        }
        
        return NULL;
}

void guarda_arestas(Agraph_t *g, grafo new, vertice vt, Agnode_t *v)
{
        Agedge_t *a;
        arestas ar = malloc(sizeof(arestas));
        
        no n0;
        
        if (new->direcionado)
        {
                vt->grauSaida = 0;
                vt->grauEntrada = 0;
                //Arestas saida
                for (a=agfstout(g,v); a; a=agnxtout(g,a))
                {
                        ar->peso = agget(a, (unsigned int)"ar->peso");
                        ar->ponta = buscaVertice(agnameof(aghead(a)), new);
                        vt->grauSaida++;
                        n0 = insere_lista(ar, vt->listaArestasSaida);
                }
                //Arestas entrada
                for (a=agfstout(g,v); a; a=agnxtout(g,a))
                {
                        ar->peso = agget(a, (unsigned int)"ar->peso");
                        ar->ponta = buscaVertice(agnameof(agtail(a)), new);
                        vt->grauEntrada++;
                        n0 = insere_lista(ar, vt->listaArestasEntrada);
                }
                v=agnxtnode(g,v);
        }
        else
        {
                vt->grauSaida = 0;
                for (a=agfstedge(g,v); a; a=agnxtedge(g,a,v))
                {
                        ar->peso = agget(a, (unsigned int)"ar->peso");
                        ar->ponta = buscaVertice(agnameof(aghead(a)), new);
                        printf("%s - %s\n", vt->nome, ar->ponta->nome);fflush(stdout);
                        vt->grauSaida++;
                        n0 = insere_lista(ar, vt->listaArestasSaida);
                }
                v=agnxtnode(g,v);
        }
}

void insereVertice(Agraph_t *g, Agnode_t *v, grafo new)
{
        no n;
        int i;
        vertice vt = malloc(sizeof(vertice));
        
        strcpy(vt->nome, agnameof(v));
        i = strlen(agnameof(v));
        vt->nome[i] = '\0';
                
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

static Agraph_t * armazena_grafo(Agraph_t *g, grafo new)
{
        int i=0;

        Agnode_t *v;
        
        no              n;
        void            *aux;
        vertice         vt      = malloc(sizeof(vertice));
        
        //cria novo grafo        
        strcpy(new->nome, agnameof(g));
        i = strlen(agnameof(g));
        vt->nome[i] = '\0';
        
        new->direcionado         = agisdirected(g);
        new->numvertice          = agnnodes(g);
        new->numArestas          = agnedges(g);
        new->listavertice        = constroi_lista();
        
        //Insere vértices
        //Necessário colocar antes os vértices, pois a lista de adjacências é uma lista de ponteiros
        for (v=agfstnode(g); v; v=agnxtnode(g,v))
                insereVertice(g, v, new);
        
        v=agfstnode(g);
        for (n=primeiro_no(new->listavertice); n; n=proximo_no(n))
        {
                vt = conteudo(n);
                guarda_arestas(g, new, vt, v);
        }

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
        no n,m;
        vertice v;
        arestas a;
        char dir[1];
        
        if (g->direcionado)
                strcpy(dir,"->");
        else
                strcpy(dir,"--");
                
       // fprintf(output, "strict graph %s {\n", g->nome);fflush(output);
        
        for (n=primeiro_no(g->listavertice); n; n=proximo_no(n))
        {
                v = conteudo(n);
                for(m=primeiro_no(v->listaArestasSaida); m; m=proximo_no(m))
                {
                        a = conteudo(m);
                        //fprintf(output, "%s %s \n", v->nome, dir);
                }
        }
        fprintf(output, "}");
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

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
	int tam;
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
        char peso[10];
        //vertice tail;
        vertice head;
};


void strToInt(int arr[], int sizeArr, char num[])
{
    for(int i = 0; i < sizeArr; i++)
        arr[i] = (int)num[i] - 48;
}

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
                if (strcmp(vt->nome, nome) == 0)
                        return vt;
        }
        
        return NULL;
}

void insereAresta(Agedge_t *a, Agraph_t *g, Agnode_t *v, grafo new, unsigned int es, vertice vt)
{
        arestas ar = malloc(sizeof(arestas));
        no n;
        
        char *peso = agget(a, (char *)"peso");
        if (peso == NULL)
        {
                strcpy(ar->peso, "0\0");
                new->ponderado = 0;
        }
        else
                strcpy(ar->peso, peso);
             
        fprintf(stdout, "%s\n", ar->peso);fflush(stdout);
        
        //fprintf(stdout, "Buscando nodo %s\n", agnameof(aghead(a)));fflush(stdout);
        ar->head = buscaVertice(agnameof(aghead(a)), new);
        
        //ar->tail = buscaVertice(agnameof(agtail(a)), new);
        
        if (es)
        {
                n = insere_lista(ar, vt->listaArestasSaida);
                //fprintf(stdout, "inseriu saida \n", agnameof(aghead(a)));fflush(stdout);
                
        }
        else
                n = insere_lista(ar, vt->listaArestasEntrada);
                
        new->tam++;
                
                //3351
       // fprintf(stdout, "%s - %s %d \n", vt->nome, ar->head->nome, new->tam); fflush(stdout);
}

void guarda_arestas(Agraph_t *g, grafo new, vertice vt, Agnode_t *v)
{
        Agedge_t *a;
        
       //Arestas saida
       vt->grauSaida = 0;
       for (a=agfstout(g,v); a; a=agnxtout(g,a))
       {
                vt->grauSaida++;
                insereAresta(a, g, v, new, 1, vt);
       }
        
       if (new->direcionado)
       {
               vt->grauEntrada = 0;
               //Arestas entrada
               for (a=agfstin(g,v); a; a=agnxtin(g,a))
               {
                        vt->grauEntrada++;
                        insereAresta(a, g, v, new, 0, vt);
               }
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
        
        i=0;
        
        new->direcionado         = agisdirected(g);
        new->numvertice          = agnnodes(g);
        new->numArestas          = agnedges(g);
        new->listavertice        = constroi_lista();
        
        //Insere vértices
        //Necessário colocar antes os vértices, pois a lista de adjacências é uma lista de ponteiros
        for (v=agfstnode(g); v; v=agnxtnode(g,v))
                insereVertice(g, v, new);
        
        v=agfstnode(g);
        new->tam = 0;
        for (n=primeiro_no(new->listavertice); n; n=proximo_no(n))
        {
                vt = conteudo(n);
                guarda_arestas(g, new, vt, v);
                i++;
                v=agnxtnode(g,v);
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

grafo escreve_grafo(FILE *output, grafo g)
{
        no n,m;
        vertice v;
        arestas a;
        char dir[3];
        
        dir[0] = '-';
        dir[1] = g->direcionado ? '>' : '-';
        dir[2] = '\0';
                
        fprintf(output, "strict graph %s {\n", g->nome);fflush(output);
        
        for (n=primeiro_no(g->listavertice); n; n=proximo_no(n))
        {
                v = conteudo(n);

                for(m=primeiro_no(v->listaArestasSaida); m; m=proximo_no(m))
                {
                        a = conteudo(m);
                        fprintf(output, "%s %s %s [peso=%s] \n", v->nome, dir, a->head->nome, a->peso);fflush(output);
                }
        }
        fprintf(output, "}\n");
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

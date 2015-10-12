#include <stdio.h>
#include "grafo.h"
#include "lista.h"

//------------------------------------------------------------------------------
//rc: enriquecer o teste com mais processamento que possa servir de exemplo
//
//    - calcular graus mínimos e máximos, de entrada e saída
//    - detectar vértices isolados, fontes e sorvedouros   
//    - indicar se o grafo é regular ou não
//    - indicar se o grafo (direcionado) tem laços
//    - indicar se o grafo (direcionado) é simétrico
//    - indicar se o grafo (direcionado) é anti-simétrico
//    - que mais?

int main(void) {

  grafo g = le_grafo(stdin);

  if ( !g )

    return 1;

  printf("nome: %s\n", nome_grafo(g));
  printf("%sdirecionado\n", direcionado(g) ? "" : "não ");
  printf("%sponderado\n", ponderado(g) ? "" : "não ");
  printf("%d vértices\n", n_vertices(g));
  printf("%d arestas\n", n_arestas(g));

  escreve_grafo(stdout, g);

  return ! destroi_grafo(g);
}

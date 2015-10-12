Trabalho de Implementação 1
===========================

Alunas
------
FLAVIENE SCHEIDT DE CRISTO    - GRR 20101915
JAQUELINE FERNANDA BORGES NANDE - GRR GRR20102604 

Estrutura de Dados
------------------

- A estrutura "grafo" guarda uma lista de todos os vértices, uma lista de todas
    as arestas e informações do grafo, como nome, número de vértice, número de 
    arestas, e se é ponderado e direcionado
- A etrutura "vertice" guarda as informações de um vértice, como nome, grau de
    entrada, grau de saída, a lista de arestas que partem dele e a lista de
    que chegam nele. No caso de grafos não direcionados, todas as arestas são
    guardadas na lista de arestas de saída, e o grau é o grau de saída
- A estrutura "aresta" possui um apontador para o vértice "head" da aresta e o
    outro para o vértice "tail"da aresta, além de seu peso, guardado como char *


Bugs e Warnings
---------------

- Apresenta falha de segmentação no carregamento de grafos direcionados
- Não identifica corretamente se o grafo é ponderado, embora os pesos sejam
    sempre carregados corretamente
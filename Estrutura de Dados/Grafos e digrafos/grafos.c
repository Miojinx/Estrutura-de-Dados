/* Grafos
Algoritmos: Busca, Inserção e Exclusão
Representado por vértices e arestas 
G = (V, E)
G: Conjunto não vazio
V: Vértice 
E: Aresta
Grafo orientado: as arestas possuem uma direção. Instagram
Grafo não orientado: as arestas são bi-direcionais. Facebook
orientado: v1->v2 , incidente de v1 e incidente a v1
não orientado: v1<->v2 incidente de v1 e v2
Grau: quantidade de arestas. Vértices com grau 0 são isolados
Ordem de um grafo: número de vértices*/
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
 typedef struct vizinho{
    int idVizinho;
    struct vizinho *prox
 }TVizinho;

 typedef struct grafo{
    int idVertice;
    TVizinho * primVizinho;
    struct grafo *prox;
 }TGrafo;
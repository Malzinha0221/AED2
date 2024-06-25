#include <stdio.h>
#include "grafos.h"

int main() {
    int Vertice = 9;
    Grafo* grafo = criarGrafo(Vertice);
    adicionarAresta(grafo, 0, 1, 4);
    adicionarAresta(grafo, 0, 7, 8);
    adicionarAresta(grafo, 1, 2, 8);
    adicionarAresta(grafo, 1, 7, 11);
    adicionarAresta(grafo, 2, 3, 7);
    adicionarAresta(grafo, 2, 8, 2);
    adicionarAresta(grafo, 2, 5, 4);
    adicionarAresta(grafo, 3, 4, 9);
    adicionarAresta(grafo, 3, 5, 14);
    adicionarAresta(grafo, 4, 5, 10);
    adicionarAresta(grafo, 5, 6, 2);
    adicionarAresta(grafo, 6, 7, 1);
    adicionarAresta(grafo, 6, 8, 6);
    adicionarAresta(grafo, 7, 8, 7);

    imprimirGrafo(grafo);
    dijkstra(grafo, 0);
    return 0;
}

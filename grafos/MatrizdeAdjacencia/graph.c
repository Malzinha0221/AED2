#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// Função para criar um grafo com V vértices
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;

    // Alocar memória para a matriz de adjacência
    graph->matrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->matrix[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->matrix[i][j] = 0;  // Inicializar todas as posições com 0
        }
    }

    return graph;
}

// Função para adicionar uma aresta ao grafo
void addEdge(Graph* graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;  // Para grafos não direcionados, adicionar nas duas direções
}

// Função para remover uma aresta do grafo
void removeEdge(Graph* graph, int src, int dest) {
    graph->matrix[src][dest] = 0;
    graph->matrix[dest][src] = 0;  // Para grafos não direcionados, remover nas duas direções
}

// Função para imprimir o grafo
void printGraph(const Graph* graph) {
    printf("Matriz de Adjacência:\n");
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

// Função para liberar a memória alocada pelo grafo
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
}

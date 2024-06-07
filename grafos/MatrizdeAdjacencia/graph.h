#ifndef GRAPH_H
#define GRAPH_H

typedef struct {
    int V;          // Número de vértices
    int **matrix;   // Matriz de adjacência
} Graph;

// Função para criar um grafo com V vértices
Graph* createGraph(int V);

// Função para adicionar uma aresta ao grafo
void addEdge(Graph* graph, int src, int dest);

// Função para remover uma aresta do grafo
void removeEdge(Graph* graph, int src, int dest);

// Função para imprimir o grafo
void printGraph(const Graph* graph);

// Função para liberar a memória alocada pelo grafo
void freeGraph(Graph* graph);

#endif // GRAPH_H

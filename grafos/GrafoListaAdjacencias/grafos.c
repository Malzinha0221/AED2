#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó na lista de adjacência
typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

// Estrutura para representar a lista de adjacência
typedef struct AdjList {
    AdjListNode* head;  // Ponteiro para o cabeçalho da lista de adjacência
} AdjList;

// Estrutura para representar um grafo
typedef struct Graph {
    int V;  // Número de vértices
    AdjList* array;  // Array de listas de adjacência
} Graph;

// Função para criar um novo nó na lista de adjacência
AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Função para criar um grafo com V vértices
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));

    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Função para adicionar uma aresta ao grafo
void addEdge(Graph* graph, int src, int dest) {
    // Adicionar a aresta do src para o dest
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Se o grafo não for direcionado, adicionar a aresta do dest para o src também
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Função para imprimir o grafo
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Lista de adjacência do vértice %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// Função para liberar a memória alocada pelo grafo
void freeGraph(Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        AdjListNode* pCrawl = graph->array[v].head;
        while (pCrawl) {
            AdjListNode* temp = pCrawl;
            pCrawl = pCrawl->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);
}

int main() {
    // Criar o grafo conforme o número de vértices
    int V = 5;
    Graph* graph = createGraph(V);

    // Adicionar as arestas
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Imprimir o grafo
    printGraph(graph);

    // Liberar a memória alocada pelo grafo
    freeGraph(graph);

    return 0;
}

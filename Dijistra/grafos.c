//
// Created by Daniel Nazário em 24/06/2024.
//

#include "grafos.h"

Grafo* criarGrafo(int Vertice) {
    Grafo* grafo = (Grafo*) malloc(sizeof(Grafo));
    grafo->Vertice = Vertice;
    grafo->array = (ListaAdjacencia*) malloc(Vertice * sizeof(ListaAdjacencia));
    for (int i = 0; i < Vertice; ++i) {
        grafo->array[i].cabeca = NULL;
    }
    return grafo;
}

ListaAdjacenciaNo* criarNovoNo(int destino, int peso) {
    ListaAdjacenciaNo* novoNo = (ListaAdjacenciaNo*) malloc(sizeof(ListaAdjacenciaNo));
    novoNo->destino = destino;
    novoNo->peso = peso;
    novoNo->proxima = NULL;
    return novoNo;
}

void adicionarAresta(Grafo* grafo, int origem, int destino, int peso) {
    ListaAdjacenciaNo* novoNo = criarNovoNo(destino, peso);
    novoNo->proxima = grafo->array[origem].cabeca;
    grafo->array[origem].cabeca = novoNo;

    novoNo = criarNovoNo(origem, peso);
    novoNo->proxima = grafo->array[destino].cabeca;
    grafo->array[destino].cabeca = novoNo;
}

void imprimirGrafo(Grafo* grafo) {
    int v;
    for (v = 0; v < grafo->Vertice; ++v) {
        ListaAdjacenciaNo* temp = grafo->array[v].cabeca;
        printf("\n Lista de adjacência do vértice %d\n cabeça", v);
        while (temp) {
            printf(" -> %d (%d)", temp->destino, temp->peso);
            temp = temp->proxima;
        }
        printf("\n");
    }
}

int minDistancia(int dist[], int CaminhomaisCurto[], int Vertice) {
    int min = INF, min_index;

    for (int i = 0; i < Vertice; ++i) {
        if (!CaminhomaisCurto[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(Grafo* grafo, int origem) {
    int Vertice = grafo->Vertice;
    int dist[Vertice];
    int CaminhomaisCurto[Vertice];
    for (int i = 0; i < Vertice; i++) {
        dist[i] = INF;
        CaminhomaisCurto[i] = 0;
    }
    dist[origem] = 0;
    for (int count = 0; count < Vertice - 1; count++) {
        int menorDistancia = minDistancia(dist, CaminhomaisCurto, Vertice);
        CaminhomaisCurto[menorDistancia] = 1;
        ListaAdjacenciaNo* temp = grafo->array[menorDistancia].cabeca;
        while (temp !=NULL) {
            int v = temp->destino;
            if (!CaminhomaisCurto[v] && dist[menorDistancia] != INF && dist[menorDistancia] + temp->peso < dist[v]) {
                dist[v] = dist[menorDistancia] + temp->peso;
            }
            temp = temp->proxima;
        }
    }
    printf("Vértice   Distância da origem\n");
    for (int i = 0; i < Vertice; ++i) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

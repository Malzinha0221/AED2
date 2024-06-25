//
// Created by Daniel Nazário em 24/06/2024.
//

#ifndef GRAFOS_H
#define GRAFOS_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct ListaAdjacenciaNo {
    int destino;
    int peso;
    struct ListaAdjacenciaNo* proxima;
} ListaAdjacenciaNo;

typedef struct ListaAdjacencia {
    ListaAdjacenciaNo* cabeca;
} ListaAdjacencia;

typedef struct Grafo {
    int Vertice;
    ListaAdjacencia* array;
} Grafo;

void dijkstra(Grafo* grafo, int origem);
Grafo* criarGrafo(int Vertice);
ListaAdjacenciaNo* criarNovoNo(int destino, int peso);
int minDistancia(int dist[], int CaminhomaisCurto[], int Vertice);
void adicionarAresta(Grafo* grafo, int origem, int destino, int peso);
void imprimirGrafo(Grafo* grafo);
#endif //GRAFOS_H

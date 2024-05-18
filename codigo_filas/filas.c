#include "filas.h"
#include <stdio.h>
#include <stdlib.h>

// Inicializar a lista
void inicializalista(O_HEAP *hp)
{
    hp->no_elem = 0;
}

// Inserir um novo elemento (ao final da lista)

void iniserir_novo(O_HEAP *vetor, int valor)
{
    vetor->no_elem++;
    vetor->chave[vetor->no_elem - 1] = valor;
    heapify_up(vetor, vetor->no_elem);
}

// Consertar o heap subindo: levar o elemento inserido para a sua respectativa posição na heap de acordo com a sua prioridade

void heapify_up(O_HEAP *vetor, int novo)
{
    int i = novo;
    int tmp;
    while (i >= 2 && (vetor->chave[(i / 2) - 1] < vetor->chave[i - 1]))
    {
        tmp = vetor->chave[(i / 2) - 1];
        vetor->chave[(i / 2) - 1] = vetor->chave[i - 1];
        vetor->chave[i - 1] = tmp;
        i = i / 2;
    }
}

// Elemento com maior prioridade

int max_prioridade(O_HEAP hp)
{
    return hp.chave[0];
}

// Remover o elemento com maior prioridade

int remover_maximo(O_HEAP *hp)
{
    int maximo = hp->chave[0];
    hp->chave[0] = hp->chave[hp->no_elem - 1];
    hp->no_elem--;
    heapify_donw(hp, 1);
    return maximo;
}

// Conserta o heap descendo

void heapify_donw(O_HEAP *hp, int i)
{
    int l = 2 * i - 1;
    int r = 2 * i;
    int m = i - 1;
    int tmp;
    if (l < hp->no_elem && hp->chave[l] > hp->chave[m])
    {
        m = l;
    }
    if (r < hp->no_elem && hp->chave[r] > hp->chave[m])
    {
        m = r;
    }
    if (m != i - 1)
    {
        tmp = hp->chave[m];
        hp->chave[m] = hp->chave[i - 1];
        hp->chave[i - 1] = tmp;
        heapify_donw(hp, m + 1);
    }
}

// Aumentar o valor de uma chave

void aumentar_valor(O_HEAP *vetor, int elemt, int valor)
{
    if (vetor->chave[elemt - 1] > valor)
    {
        printf("Erro: novo valor menor que o atual\n");
    }
    else
    {
        vetor->chave[elemt - 1] < valor;
        heapify_up(vetor, elemt);
    }
}

// Diminuir o valor de uma chave
void dism_valor(O_HEAP *vetor, int elemt, int valor)
{
    if (vetor->chave[elemt - 1] < valor)
    {
        printf("Erro: novo valor maior que o atual\n");
    }
    else
    {
        vetor->chave[elemt - 1] = valor;
        heapify_donw(vetor, elemt);
    }
}

// Imprimir a heap

void imprimir_heap(O_HEAP hp)
{
    int i;
    for (i = 0; i < hp.no_elem; i++)
    {
        printf("%d ", hp.chave[i]);
    }
    printf("\n");
}
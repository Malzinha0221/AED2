#include "Oferta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void trocar(Oferta *a, Oferta *b)
{
    Oferta temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(FilaDePrioridade *fila, int index)
{
    if (index && fila->heap[(index - 1) / 2].preco < fila->heap[index].preco)
    {
        trocar(&fila->heap[index], &fila->heap[(index - 1) / 2]);
        heapify_up(fila, (index - 1) / 2);
    }
}

void heapify_down(FilaDePrioridade *fila, int index)
{
    int maior = index;
    int esquerda = 2 * index + 1;
    int direita = 2 * index + 2;

    if (esquerda < fila->tamanho && fila->heap[esquerda].preco > fila->heap[maior].preco)
        maior = esquerda;

    if (direita < fila->tamanho && fila->heap[direita].preco > fila->heap[maior].preco)
        maior = direita;

    if (maior != index)
    {
        trocar(&fila->heap[index], &fila->heap[maior]);
        heapify_down(fila, maior);
    }
}
FilaDePrioridade *criar_fila(int capacidade)
{
    FilaDePrioridade *fila = (FilaDePrioridade *)malloc(sizeof(FilaDePrioridade));
    fila->heap = (Oferta *)malloc(capacidade * sizeof(Oferta));
    fila->tamanho = 0;
    fila->capacidade = capacidade;
    return fila;
}

void inserir_oferta(FilaDePrioridade *fila, char *nome, int preco)
{
    if (fila->tamanho == fila->capacidade)
    {
        printf("Capacidade da fila atingida!\n");
        return;
    }
    Oferta oferta;
    strcpy(oferta.nome, nome);
    oferta.preco = preco;

    fila->heap[fila->tamanho] = oferta;
    heapify_up(fila, fila->tamanho);
    fila->tamanho++;
}

Oferta obter_melhor_oferta(FilaDePrioridade *fila)
{
    if (fila->tamanho == 0)
    {
        printf("Fila está vazia!\n");
        Oferta vazio = {"", -1};
        return vazio;
    }
    Oferta raiz = fila->heap[0];
    fila->heap[0] = fila->heap[fila->tamanho - 1];
    fila->tamanho--;
    heapify_down(fila, 0);
    return raiz;
}

#include "hospital.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tracar Paciente por prioridade
void trocar(Paciente *primeiro, Paciente *ultimo)
{
    Paciente temp = *primeiro;
    *primeiro = *ultimo;
    *ultimo = temp;
}

// Consertar o heap subindo: levar o elemento inserido para a sua respectativa posição na heap de acordo com a sua prioridade

void heapify_up(FilaDePrioridade *fila, int index)
{
    if (index && fila->heap[(index - 1) / 2].grau_urgencia < fila->heap[index].grau_urgencia)
    {
        trocar(&fila->heap[index], &fila->heap[(index - 1) / 2]);
        heapify_up(fila, (index - 1) / 2);
    }
}

// Consertar o heap descendo: levar o elemento removido para a sua respectiva posição na heap de acordo com a sua prioridade

void heapify_down(FilaDePrioridade *fila, int index)
{
    int maior = index;
    int esquerda = 2 * index + 1;
    int direita = 2 * index + 2;
    if (esquerda < fila->tamanho && fila->heap[esquerda].grau_urgencia > fila->heap[maior].grau_urgencia)
    {
        maior = esquerda;
    }
    if (direita < fila->tamanho && fila->heap[direita].grau_urgencia > fila->heap[maior].grau_urgencia)
    {
        maior = direita;
    }
    if (maior != index)
    {
        trocar(&fila->heap[index], &fila->heap[maior]);
        heapify_down(fila, maior);
    }
}

FilaDePrioridade* criar_fila(int capacidade) {
    FilaDePrioridade *fila = (FilaDePrioridade*)malloc(sizeof(FilaDePrioridade));
    fila->heap = (Paciente*)malloc(capacidade * sizeof(Paciente));
    fila->tamanho = 0;
    fila->capacidade = capacidade;
    return fila;
}

void inserir_paciente(FilaDePrioridade *fila, char *nome, char *telefone, int grau_urgencia) {
    if (fila->tamanho == fila->capacidade) {
        printf("Capacidade da fila atingida!\n");
        return;
    }
    Paciente paciente;
    strcpy(paciente.nome, nome);
    strcpy(paciente.telefone, telefone);
    paciente.grau_urgencia = grau_urgencia;

    fila->heap[fila->tamanho] = paciente;
    heapify_up(fila, fila->tamanho);
    fila->tamanho++;
}

Paciente obter_proximo_paciente(FilaDePrioridade *fila) {
    if (fila->tamanho == 0) {
        printf("Fila está vazia!\n");
        Paciente vazio = {"", "", -1};
        return vazio;
    }
    Paciente raiz = fila->heap[0];
    fila->heap[0] = fila->heap[fila->tamanho - 1];
    fila->tamanho--;
    heapify_down(fila, 0);
    return raiz;
}

void imprimir_fila(FilaDePrioridade *fila) {
    for (int i = 0; i < fila->tamanho; i++) {
        printf("Nome: %s, Telefone: %s, Grau de Urgência: %d\n", fila->heap[i].nome, fila->heap[i].telefone, fila->heap[i].grau_urgencia);
    }
}

int tamanho_fila(FilaDePrioridade *fila) {
    return fila->tamanho;
}

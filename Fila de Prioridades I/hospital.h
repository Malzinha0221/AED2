// Criar um Estrutura de Dados Paciente e outra como Fila de Prioridade

#ifndef HOSPITAL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    char telefone[15];
    int grau_urgencia;
} Paciente;

typedef struct
{
    Paciente *heap;
    int tamanho;
    int capacidade;
} FilaDePrioridade;

void trocar(Paciente *primeiro, Paciente *ultimo);

void heapify_up(FilaDePrioridade *fila, int index);
void heapify_down(FilaDePrioridade *fila, int index);
FilaDePrioridade *criar_fila(int capacidade);
void inserir_paciente(FilaDePrioridade *fila, char *nome, char *telefone, int grau_urgencia);
Paciente obter_proximo_paciente(FilaDePrioridade *fila);
void imprimir_fila(FilaDePrioridade *fila);
int tamanho_fila(FilaDePrioridade *fila);

#endif // Hospital_h

#ifndef OFERTA_H


typedef struct {
    char nome[50];
    int preco;
} Oferta;

typedef struct {
    Oferta *heap;
    int tamanho;
    int capacidade;
} FilaDePrioridade;

void trocar(Oferta *a, Oferta *b);
void heapify_up(FilaDePrioridade *fila, int index);
void heapify_down(FilaDePrioridade *fila, int index);
FilaDePrioridade *criar_fila(int capacidade);
void inserir_oferta(FilaDePrioridade *fila, char *nome, int preco);
Oferta obter_melhor_oferta(FilaDePrioridade *fila);
#endif
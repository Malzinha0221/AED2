#include "Oferta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    int tamanho;
    printf("Escreva o tamanho da fila: ");
    scanf("%d", &tamanho);

    FilaDePrioridade *fila = criar_fila(tamanho);
    char evento[10];
    char nome[50];
    int preco;

    for (int i = 0; i < tamanho; i++) {
        printf("Escreva o evento (OFERTA ou VENDA): ");
        scanf("%s", evento);
        if (strcmp(evento, "OFERTA") == 0) {
            printf("Escreva o nome: ");
            scanf("%s", nome);
            printf("Escreva o preco da oferta: ");
            scanf("%d", &preco);
            inserir_oferta(fila, nome, preco);
        } else if (strcmp(evento, "VENDA") == 0) {
            Oferta melhor_oferta = obter_melhor_oferta(fila);
            printf("%d %s\n", melhor_oferta.preco, melhor_oferta.nome);
        }
    }

    free(fila->heap);
    free(fila);
    return 0;
}

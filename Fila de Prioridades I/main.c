#include "hospital.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FilaDePrioridade *fila = criar_fila(10);

    inserir_paciente(fila, "João", "1234-5678", 5);
    inserir_paciente(fila, "Maria", "2345-6789", 4);
    inserir_paciente(fila, "Carlos", "3456-7890", 3);

    printf("Fila de espera:\n");
    imprimir_fila(fila);

    printf("\nPróximo paciente a ser operado:\n");
    Paciente proximo = obter_proximo_paciente(fila);
    printf("Nome: %s, Telefone: %s\n", proximo.nome, proximo.telefone);

    printf("\nFila de espera atualizada:\n");
    imprimir_fila(fila);

    printf("\nTamanho da fila de espera: %d\n", tamanho_fila(fila));

    free(fila->heap);
    free(fila);

    return 0;
}

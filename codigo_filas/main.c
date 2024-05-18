#include "filas.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    O_HEAP hp;
    inicializalista(&hp);
    iniserir_novo(&hp,20);
    iniserir_novo(&hp,10);
    iniserir_novo(&hp,5);
    iniserir_novo(&hp,30);
    iniserir_novo(&hp,50);
    iniserir_novo(&hp,45);
    iniserir_novo(&hp,35);
    imprimir_heap(hp);
    aumentar_valor(&hp, 6, 48);
    dism_valor(&hp, 3, 25);
    imprimir_heap(hp);
    printf("Maior prioridade: %d\n", max_prioridade(hp));
    printf("Removendo o maior: %d\n", remover_maximo(&hp));
    imprimir_heap(hp);
    return 0;
}
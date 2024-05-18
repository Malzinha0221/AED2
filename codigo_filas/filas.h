#define MAX 100

typedef struct {
    int chave[MAX];
    int no_elem;
}O_HEAP;

void inicializalista(O_HEAP *hp);
void iniserir_novo(O_HEAP *vetor, int valor);
void heapify_up(O_HEAP *vetor, int novo);
int max_prioridade(O_HEAP hp);
int remover_maximo(O_HEAP *hp);
void heapify_donw(O_HEAP *hp, int i);
void aumentar_valor(O_HEAP *vetor, int elemt, int valor);
void dism_valor (O_HEAP *vetor, int elemt, int valor);
void imprimir_heap(O_HEAP hp);
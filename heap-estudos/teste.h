#define MAXTAM 10000

typedef int TipoIndice;

typedef int TipoVetor[MAXTAM + 1];

typedef struct {
    TipoVetor itens;
    TipoIndice n;
} TipoHeap;

void imprimeTeste(int x);

void fazHeapVazio(TipoHeap *heap);
int heapVazio(TipoHeap *heap);
void insereHeap(TipoHeap *heap, int chave);
void imprimeHeap(TipoHeap *heap);
void retiraMax(TipoHeap *heap);

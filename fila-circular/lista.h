typedef int tipoElemento;

typedef struct celula {
    tipoElemento elem;
    struct celula* prox;
} Celula;

typedef struct {
    Celula* cabeca;
    int tamanho;
} TipoFila;

void fazFilaVazia(TipoFila* fila);
void imprimeFila(TipoFila* fila);
int enfileira(TipoFila* fila, tipoElemento* elem);
int desenfileira(TipoFila* fila);
int adicionaFilaSimples(TipoFila* fila, tipoElemento* elem);

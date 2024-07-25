typedef int tipoElemento;

#define TAM 100

typedef struct {
    tipoElemento elementos[TAM];
    int start;
    int after;
    int tam;
} TipoFila;

void fazFilaVazia(TipoFila *fila);
int enfileira(TipoFila *fila, tipoElemento *elem);
int desenfileira(TipoFila *fila);
void imprimefila(TipoFila *fila);
int filaVazia(TipoFila *fila);
int filaCheia(TipoFila *fila);

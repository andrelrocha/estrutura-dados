#define TAM 100

typedef int tipoElemento;

typedef struct {
    int tamanho;
    tipoElemento elementos[TAM];
    int frente;
    int tras;
} TipoFila;

void fazfilavazia(TipoFila* fila);
void imprimeFila(TipoFila* fila);
int enfileira(TipoFila* fila, int elemento);
int desinfileira(TipoFila* fila);

typedef struct {
    int tamanho;
    tipoElemento elementos[TAM];
    int frente;
    int tras;
} TipoPilha;

int empilha(TipoPilha* pilha, int elemento);
int desimpilha(TipoPilha* pilha);

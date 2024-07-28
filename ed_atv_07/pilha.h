typedef int tipoElemento;

typedef struct celula {
    tipoElemento chave;
    struct celula* prox;
} Celula;

typedef struct {
    int tamanho;
    Celula* topo;
} TipoPilha;

void faz_pilha_vazia(TipoPilha* pilha);
int empilha(TipoPilha* pilha, tipoElemento* elemento);
int desempilha(TipoPilha* pilha, tipoElemento* elemento);
void imprime_pilha(TipoPilha* pilha);
int tamanho_pilha(TipoPilha* pilha);

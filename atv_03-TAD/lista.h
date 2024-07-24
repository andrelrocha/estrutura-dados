typedef int tipoChave;

typedef struct Celula {
    tipoChave chave;
    struct Celula* prox;
} Celula;

typedef struct {
    Celula* primeiro;
    int tamanho;
} TipoLista;

void fazListaVazia(TipoLista* lista);
int insereLista(TipoLista* lista, tipoChave chave);
int buscaRemoveDaLista(TipoLista* lista, tipoChave chave);
int tamanhoLista(TipoLista* lista);
int removePrimeiroDaLista(TipoLista* lista, tipoChave *chave);

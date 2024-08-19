typedef int tipoElemento;

typedef struct celula {
    tipoElemento chave;
    struct celula* esq;
    struct celula* dir;
} Celula;

typedef Celula* tipoNo;

void faz_arvore_vazia(tipoNo* raiz);
void insere_no(tipoNo* raiz, int chave);
void remove_no(tipoNo* raiz, int chave);
void imprime_arvore(tipoNo raiz);

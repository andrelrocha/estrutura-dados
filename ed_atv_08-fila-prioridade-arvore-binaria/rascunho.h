
typedef int tipoChave;

typedef struct celula {
    tipoChave chave;
    struct celula* esquerda,
    struct celula *direita
} Celula;

typedef struct {
    Celula* raiz,
    int tamanho
} FilaPrioridade;

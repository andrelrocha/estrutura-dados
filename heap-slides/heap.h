#define MAXTAM 10000

typedef int TipoIndice;
typedef long TipoChave;

typedef struct TipoItem {
    TipoChave chave;
} TipoItem;

typedef TipoItem TipoVetor[MAXTAM + 1];
TipoVetor A;


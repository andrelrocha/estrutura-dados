typedef int TipoChave;

typedef struct {
    TipoChave Chave;
} TipoItem;

extern long long int compSelecao;
extern long long int movSelecao;
extern long long int compInsercao;
extern long long int movInsercao;
extern long long int compShellsort;
extern long long int movShellsort;

void Selecao(TipoItem *A, int n);
void Insercao(TipoItem *A, int n);
void Shellsort(TipoItem *A, int n);

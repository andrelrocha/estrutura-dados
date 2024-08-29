typedef struct TipoNo {
    int registro;
    struct TipoNo* esq;
    struct TipoNo* dir;
} TipoNo;

typedef TipoNo* TipoFP;

/*1.Função para criar e inicializar uma fila de prioridades vazia (árvore
binária de pesquisa):*/
void criaFP(TipoFP *fp);

/*2.Função para apagar toda a memória alocada para a fila de prioridades.
(você deve fazer um caminhamento pós-fixado na APB, apagando cada nó): */
void apagaFP(TipoFP *fp);

/*3.Função para imprimir os elementos da fila de prioridades em ordem
decrescente (fazer um caminhamento central “invertido” na APB): */
void imprimeFP(TipoFP fp);

/*4.Função que insere um novo registro na fila de prioridades:*/
void insereFP(int x, TipoFP *fp);

/*5.Função que remove o registro com a maior chave da fila de prioridades*/
void retiramax(int *x, TipoFP *fp);

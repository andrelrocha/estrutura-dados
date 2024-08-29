typedef struct TipoNo {
    int registro;
    struct TipoNo* esq;
    struct TipoNo* dir;
} TipoNo;

typedef TipoNo* TipoFP;

/*1.Fun��o para criar e inicializar uma fila de prioridades vazia (�rvore
bin�ria de pesquisa):*/
void criaFP(TipoFP *fp);

/*2.Fun��o para apagar toda a mem�ria alocada para a fila de prioridades.
(voc� deve fazer um caminhamento p�s-fixado na APB, apagando cada n�): */
void apagaFP(TipoFP *fp);

/*3.Fun��o para imprimir os elementos da fila de prioridades em ordem
decrescente (fazer um caminhamento central �invertido� na APB): */
void imprimeFP(TipoFP fp);

/*4.Fun��o que insere um novo registro na fila de prioridades:*/
void insereFP(int x, TipoFP *fp);

/*5.Fun��o que remove o registro com a maior chave da fila de prioridades*/
void retiramax(int *x, TipoFP *fp);

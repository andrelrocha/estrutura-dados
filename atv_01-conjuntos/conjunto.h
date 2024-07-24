
#define MAX_SIZE 100

typedef int ConjuntoDeInteiros[MAX_SIZE];

void fazConjuntoVazio(ConjuntoDeInteiros conjunto);
void imprimeConjunto(ConjuntoDeInteiros conjunto);
int insereNoConjunto(int elemento, ConjuntoDeInteiros conjunto);
int pertenceAoConjunto(int elemento, ConjuntoDeInteiros conjunto);
int retiraDoConjunto(int elemento, ConjuntoDeInteiros conjunto);
int maxDoConjunto(int *elemento, ConjuntoDeInteiros conjunto);
int maxMinDoConjunto(int *maiorElemento, int *menorElemento, ConjuntoDeInteiros conjunto);
int maxMinDoConjunto2(int *maiorElemento, int *menorElemento, ConjuntoDeInteiros conjunto);

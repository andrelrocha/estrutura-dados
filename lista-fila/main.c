#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    TipoFila fila;
    fazFilaVazia(&fila);
    imprimefila(&fila);

    enfileira(&fila, 10);
    enfileira(&fila, 20);
    imprimefila(&fila);

    enfileira(&fila, 30);
    enfileira(&fila, 40);
    imprimefila(&fila);

    desenfileira(&fila);
    imprimefila(&fila);

    enfileira(&fila, 10);
    imprimefila(&fila);

    filaVazia(&fila);
    filaCheia(&fila);

    return 0;
}

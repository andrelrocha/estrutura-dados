#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{
    TipoFila fila;
    fazfilavazia(&fila);

    imprimeFila(&fila);

    enfileira(&fila, 10);
    enfileira(&fila, 20);
    enfileira(&fila, 30);
    imprimeFila(&fila);

    desinfileira(&fila);
    imprimeFila(&fila);

    return 0;
}

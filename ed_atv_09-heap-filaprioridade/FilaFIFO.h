#ifndef TIPOFILA_FIFO_H
#define TIPOFILA_FIFO_H

#include "Registro.h"

typedef struct registroFila {
    TipoRegistro registro;
    struct registroFila *prox;
} RegistroFila;

typedef struct {
    RegistroFila *primeiro;
    RegistroFila *ultimo;
} TipoFilaFIFO;

void criaFilaFIFO(TipoFilaFIFO *f); /*cria *f vazia*/

int vaziaFilaFIFO(TipoFilaFIFO *f); /*retorna 1 se a fila *f estiver vazia; 0 caso contr�rio*/

void imprimeFilaFIFO(TipoFilaFIFO *f); /*imprime os itens da fila *f */

void apagaFilaFIFO(TipoFilaFIFO *f); /*libera a mem�ria alocada pela fila *f, retirando todos os elementos
que houver */

void enfileiraFilaFIFO(TipoFilaFIFO *f, TipoRegistro item); /* enfileira o retistro item na filaFIFO *f. */

void desenfileiraFilaFIFO(TipoFilaFIFO *f, TipoRegistro *item); /* retorna 0 se *f estava vazia; 1 se
desenfileirou o registro *item da filaFIFO *f. */

#endif

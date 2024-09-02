#ifndef FP_H
#define FP_H

#include "Registro.h"
#include "FilaFIFO.h"

#define MAXTAM 10000

typedef int TipoIndice;

typedef struct {
    TipoRegistro registro;
    TipoFilaFIFO fila;
} TipoItemFP;

typedef TipoItemFP TipoVetorFP[MAXTAM + 1];

typedef struct {
    TipoVetorFP itens;
    TipoIndice n;
} FP;

void FPVazia(FP *fp);
int VaziaFP(FP fp);
void InsereFP(FP *fp, TipoRegistro registro);
int RemoveFP(FP *fp, TipoRegistro *registro);
void ImprimeFP(FP fp);

#endif

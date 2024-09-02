#include <stdio.h>
#include <stdlib.h>
#include "FP.h"

void criaFP(FP *fp) {
    fp->n = 0;
}

int vaziaFP(FP *fp) {
    return fp->n == 0;
}

void insereFP(FP *fp, TipoRegistro registro) {
    TipoIndice i;

    if (fp->n >= MAXTAM) {
        printf("Fila de prioridade cheia!\n");
        return;
    }

    //passo necessário para enfileirar elementos repetidos
    for (i = 1; i <= fp->n; i++) {
        if (fp->itens[i].registro.chave == registro.chave) {
            enfileiraFilaFIFO(&fp->itens[i].fila, registro);
            return;
        }
    }

    fp->n++;
    i = fp->n;


    // Sobe o novo item no heap para manter a propriedade do max-heap
    while (i > 1 && registro.chave > fp->itens[i / 2].registro.chave) {
        fp->itens[i] = fp->itens[i / 2];
        i /= 2;
    }

    // Adiciona o novo item no heap
    fp->itens[i].registro = registro;
    criaFilaFIFO(&fp->itens[i].fila);
    enfileiraFilaFIFO(&fp->itens[i].fila, registro);
}

int removeFP(FP *fp, TipoRegistro *registro) {
    if (vaziaFP(fp)) {
        printf("Fila de prioridade vazia!\n");
        return 0;
    }

    // Remove o item da raiz (maior prioridade)
    *registro = fp->itens[1].fila.primeiro->registro;
    desenfileiraFilaFIFO(&fp->itens[1].fila, registro);

    // Se a FilaFIFO estiver vazia, remova o item do heap
    if (vaziaFilaFIFO(&fp->itens[1].fila)) {
        fp->itens[1] = fp->itens[fp->n--];
        desceNoHeap(fp, 1);
    }

    return 1;
}

void desceNoHeap(FP *fp, TipoIndice i) {
    TipoIndice j = 2 * i;
    TipoItemFP x = fp->itens[i];

    while (j <= fp->n) {
        // Escolhe o maior filho para comparar
        if (j < fp->n && fp->itens[j].registro.chave < fp->itens[j + 1].registro.chave) {
            j++;
        }

        // Se o pai for maior ou igual ao maior filho, o heap está ajustado
        if (x.registro.chave >= fp->itens[j].registro.chave) {
            break;
        }

        fp->itens[i] = fp->itens[j]; // Move o filho para cima
        i = j;
        j = 2 * i;
    }

    fp->itens[i] = x; // Coloca o item x na posição correta
}

void imprimeFP(FP *fp) {
    for (int i = 1; i <= fp->n; i++) {
        printf("Chave: %ld - ", fp->itens[i].registro.chave);
        imprimeFilaFIFO(&fp->itens[i].fila);
    }
}

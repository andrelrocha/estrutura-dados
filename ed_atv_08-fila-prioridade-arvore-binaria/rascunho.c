#include "fila.h"

/*
Celula* novaCelula(int chave) {
    Celula *novo = (Celula*)malloc(sizeof(Celula));
    novo->chave = chave;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

void inserir(FilaPrioridade* fila, int chave) {
    Celula **atual = &(fila->raiz);
    while (*atual != NULL) {
        if (chave < (*atual)->chave) {
            atual = &((*atual)->esquerda);
        } else {
            atual = &((*atual)->direita);
        }
    }
    *atual = novaCelula(chave);
    fila->tamanho++;
}

void inserirNo(Celula** raiz, tipoChave chave) {
    if (*raiz == NULL) {
        *raiz = novaCelula(chave);
    }

    if (chave <= (*raiz)->chave) {
        return inserirNo(&(*raiz)->esquerda, chave);
    }

    return inserirNo(&(*raiz)->direita, chave);
}

void inserirIterativo(Celula *raiz, tipoChave chave) {
    if (raiz == NULL) {
        raiz = novaCelula(chave);
    }

    Celula* aux = raiz;

    while (aux != NULL) {
        if (chave <= aux->chave) {
            if (aux->esquerda == NULL) {
                aux->esquerda = novaCelula(chave);
            }
            aux = aux->esquerda;
        } else {
            if (aux->direita == NULL) {
                aux->direita = novaCelula(chave);
            }
            aux = aux->direita;
        }

    }
}

void criarRaiz(Celula* raiz, tipoChave chave) {
    *raiz = novaCelula(chave);
}

int numeroNos(Celula* raiz) {
    if (raiz == NULL) return 0;
    return 1 + (numeroNos(raiz->esquerda)) + (numeroNos(raiz->direita));
}

void exibirArvoreEmOrdem(Celula *raiz) {
    if (raiz == NULL) return;
    exibirArvoreEmOrdem(raiz->esquerda);
    printf("%i ", raiz->chave);
    exibirArvoreEmOrdem(raiz->direita);
}

void exibirArvorePreOrdem(Celula *raiz) {
    if (raiz == NULL) return;
    printf("%i ", raiz->chave);
    exibirArvoreEmOrdem(raiz->esquerda);
    exibirArvoreEmOrdem(raiz->direita);
}

void exibirArvorePosOrdem(Celula *raiz) {
    if (raiz == NULL) return;
    exibirArvoreEmOrdem(raiz->esquerda);
    exibirArvoreEmOrdem(raiz->direita);
    printf("%i ", raiz->chave);
}

Celula* buscarChave(tipoChave chave, Celula *raiz) {
    if (raiz == NULL) return NULL;
    if (raiz->chave == chave) return raiz;
    Celula* aux = buscarChave(chave, raiz->esquerda);
    if (aux) return aux;
    return buscarChave(chave, raiz->direita);

}

Celula* buscaBinariaRecursiva(tipoChave chave, Celula *raiz) {
    Celula* aux = raiz;
    if (chave == aux->chave) return aux;
    if (chave < aux->chave) return buscaBinariaRecursiva(chave, aux->esquerda);
    if (chave > aux->chave) return buscaBinariaRecursiva(chave, aux->direita);
    return NULL;
}

Celula* buscaBinariaIterativa(tipoChave chave, Celula *raiz) {
    Celula* atual = raiz;

    while (atual != NULL) {
        if (chave == atual->chave) {
            return atual;
        } else if (chave < atual->chave) {
            atual = atual->esquerda;
        } else {
            atual = atual->direita;
        }
    }

    return NULL;
}
*/

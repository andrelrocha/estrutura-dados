#include <stdlib.h>
#include "lista.h"

void createEmptyList(Lista* lista) {
    lista->tam = 0;
    lista->top = NULL;
}

int addElementAtStart(Lista* lista, int elem) {
    Node* no = malloc(sizeof(Node));

    no->key = elem;
    no->next = NULL;

    if (lista->top == NULL) {
        lista->top = no;
        return 1;
    }
    Node* aux = lista->top;
    no->next = aux;
    lista->top = no;
    lista->tam++;
    return 1;
}

int addElementAtEnd(Lista* lista, int elem) {
    Node* no = malloc(sizeof(Node));

    no->key = elem;
    no->next = NULL;

    if (lista->top == NULL) {
        lista->top = no;
    } else {
        Node* aux = lista->top;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = no;
    }

    lista->tam++;
    return 1;
}

int addElementBefore(Lista* lista, int elem, int comp) {
    Node* no = malloc(sizeof(Node));

    no->key = elem;

    Node* aux = lista->top;

    if (aux->key == comp) {
        addElementAtStart(lista, elem);
        return 1;
    }

    while (aux->next->key != comp) {
            if (aux->next == NULL) {
                return 0;
            }
            aux = aux->next;
    }
    no->next = aux->next;
    aux->next = no;


    lista->tam++;
    return 1;
}


int addElementAfter(Lista* lista, int elem, int comp) {
    Node* no = malloc(sizeof(Node));

    no->key= elem;

    Node* aux = lista->top;
    while(aux->key != comp) {
        aux= aux->next;
    }
    no->next = aux->next;
    aux->next = no;

    lista->tam++;
    return 1;
}

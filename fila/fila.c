#include "fila.h"
#include <stdlib.h>

void createVoidList(Lista* lista) {
    lista->tam = 0;
    lista->top = NULL;
}

void printList(Lista* lista) {
    Node* current = lista->top;
    if (current == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    printf("Conteudo da lista:\n");
    while (current != NULL) {
        printf("%d\n", current->key);
        current = current->next;
    }
}

int addValueToQueue(Lista* lista, int element) {
    Node* no = malloc(sizeof(lista));

    no->key = element;
    no->next = NULL;

    if (lista->top == NULL) {
        lista->top = no;
    } else {
        Node* aux = lista->top;
        while(aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = no;
    }

    lista->tam++;
    return ;
}

int removeValueInQueue(Lista *lista) {
    if (lista->top == NULL) {
        printf("A lista esta vazia");
        return 0;
    }

    Node* aux = lista->top;
    lista->top = aux->next;

    free(aux);

    lista->tam--;
}

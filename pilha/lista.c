#include "pilha.h"
#include <stdlib.h>


void createVoidList(Lista* lista) {
    lista->tam = 0;
    lista->top = NULL;
}

void printList(Lista* lista) {
    Node* current = lista->top;
    if (current == NULL) {
        printf("A pilha esta vazia.\n");
        return;
    }
    printf("Conteudo da pilha:\n");
    while (current != NULL) {
        printf("%d\n", current->key);
        current = current->next;
    }
}

int addElementToStack(int element, Lista* lista) {
    Node* no = malloc(sizeof(lista));

    no->key = element;
    no->next = lista->top;

    lista->top = no;
    lista->tam++;
    return 1;
}

int removeElementInStack(Lista* lista) {
    if (lista->top == NULL) {
        printf("Lista esta vazia");
        return 0;
    }

    Node* temp = lista->top;
    lista->top = temp->next;
    free(temp);
    lista->tam--;
}

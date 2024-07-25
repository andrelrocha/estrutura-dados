#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

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

int main()
{
    Lista lista;
    createEmptyList(&lista);
    printList(&lista);

    addElementAtStart(&lista, 5);
    printList(&lista);

    addElementAtStart(&lista, 10);
    printList(&lista);

    addElementAtStart(&lista, 20);
    printList(&lista);

    addElementAtEnd(&lista, 15);
    printList(&lista);

    addElementBefore(&lista, 100, 5);
    printList(&lista);

    addElementBefore(&lista, 200,20);
    printList(&lista);

    addElementAfter(&lista, 300,100);
    printList(&lista);

    return 0;
}

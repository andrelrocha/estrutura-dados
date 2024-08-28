#include <stdlib.h>
#include <stdio.h>
#include "avltree.h"

int main() {
    // Cria uma nova árvore AVL
    AVLTree *tree = createAVLTree();

    // Insere alguns valores na árvore
    printf("Inserindo valores na arvore:\n");
    insertAVL(tree, 30);
    insertAVL(tree, 20);
    insertAVL(tree, 40);
    insertAVL(tree, 10);
    insertAVL(tree, 25);
    insertAVL(tree, 35);
    insertAVL(tree, 50);

    // Imprime a árvore após inserções
    printf("Arvore apos insercoes:\n");
    printAVLTree(tree);

    // Busca alguns valores na árvore
    int keysToSearch[] = {10, 25, 35, 50, 60}; // Alguns valores para buscar
    for (int i = 0; i < sizeof(keysToSearch) / sizeof(keysToSearch[0]); i++) {
        AVLNode *result = searchAVL(tree, keysToSearch[i]);
        if (result != NULL) {
            printf("Valor %d encontrado na arvore.\n", keysToSearch[i]);
        } else {
            printf("Valor %d nao encontrado na arvore.\n", keysToSearch[i]);
        }
    }

    // Remove alguns valores da árvore
    printf("Removendo valores da arvore:\n");
    deleteAVL(tree, 10);
    deleteAVL(tree, 25);
    deleteAVL(tree, 50);

    // Imprime a árvore após remoções
    printf("Arvore apos remocoes:\n");
    printAVLTree(tree);

    // Libera a memória alocada para a árvore
    destroyAVLTree(tree);

    return 0;
}

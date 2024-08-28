#include <stdlib.h>
#include <stdio.h>
#include "avltree.h"

// Função principal para testar a árvore AVL
int main() {
    TreePointer root = NULL;

    // Inserindo elementos na árvore AVL
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Exibindo a árvore AVL
    printf("Arvore AVL apos insercoes:\n");
    printAVLTree(root);

    root = delete(root, 20);
    root = delete(root, 30);
    root = delete(root, 50);

    printf("Arvore AVL apos remocao:\n");
    printAVLTree(root);

    // Destruindo a árvore AVL
    destroyAVLTree(root);

    return 0;
}

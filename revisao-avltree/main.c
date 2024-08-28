#include <stdlib.h>
#include <stdio.h>
#include "avltree.h"

// Fun��o principal para testar a �rvore AVL
int main() {
    TreePointer root = NULL;

    // Inserindo elementos na �rvore AVL
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Exibindo a �rvore AVL
    printf("Arvore AVL apos insercoes:\n");
    printAVLTree(root);

    root = delete(root, 20);
    root = delete(root, 30);
    root = delete(root, 50);

    printf("Arvore AVL apos remocao:\n");
    printAVLTree(root);

    // Destruindo a �rvore AVL
    destroyAVLTree(root);

    return 0;
}

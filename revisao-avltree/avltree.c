#include <stdlib.h>
#include <stdio.h>
#include "avltree.h"

void destroyNode(TreePointer node) {
    if (node != NULL) {
        destroyNode(node->left);
        destroyNode(node->right);
        free(node);
    }
}
void destroyAVLTree(TreePointer root) {
    destroyNode(root);
}

TreePointer createNode(int entry) {
    TreePointer node = (TreePointer)malloc(sizeof(TreeNode));
    node->entry = entry;
    node->bal = 0;
    node->count = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printNode(TreePointer node) {
    if (node != NULL) {
        printNode(node->left);
        printf("%d ", node->entry);
        printNode(node->right);
    }
}
void printAVLTree(TreePointer root) {
    printf("AVLTree: ");
    printNode(root);
    printf("\n");
}

int height(TreePointer root) {
    if (root == NULL) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int balanceFactor(TreePointer node) {
    if (node == NULL) return 0;

    return height(node->left) - height(node->right);
}

TreePointer rotateLeft(TreePointer node) {
    TreeNode* newRoot = node->right;
    TreeNode* temp = newRoot->left;

    newRoot->left = node;
    node->right = temp;

    node->bal =  balanceFactor(node);
    newRoot->bal = balanceFactor(newRoot);

    return newRoot;
}

TreePointer rotateRight(TreePointer node) {
    TreeNode *newRoot = node->left;
    TreeNode *aux = newRoot->right;

    newRoot->right = node;
    node->left = aux;

    node->bal = balanceFactor(node);
    newRoot->bal = balanceFactor(node);

    return newRoot;
}

TreePointer insert(TreePointer root, int entry) {
    if (root == NULL) {
        TreePointer node = createNode(entry);
        return node;
    }

    if (entry < root->entry) {
        root->left = insert(root->left, entry);
    } else if (entry > root->entry) {
        root->right = insert(root->right, entry);
    } else {
        return root;
    }

    root->count = 1 + (root->left ? root->left->count : 0) + (root->right ? root->right->count : 0);

    root->bal = balanceFactor(root);

    if (root->bal > 1 && entry < root->left->entry) {
        return rotateRight(root);
    }
    if (root->bal > 1 && entry > root->left->entry) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (root->bal < -1 && entry > root->right->entry) {
        return rotateLeft(root);
    }

    if (root->bal < -1 && entry < root->right->entry) {
        root->right = rotateLeft(root->right);
        return rotateLeft(root);
    }

    return root;
}

TreePointer delete(TreePointer root, int entry) {
    if (root == NULL) return root;

    if (entry < root->entry) {
        root->left = delete(root->left, entry);
    } else if (entry > root->entry) {
        root->right = delete(root->right, entry);
    } else {
        // Nó a ser removido encontrado
        if (root->left == NULL) {
            TreePointer temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreePointer temp = root->left;
            free(root);
            return temp;
        }

        // Nó com dois filhos: encontra o menor nó na subárvore direita
        TreePointer aux = root->right;
        while (aux->left != NULL) {
            aux = aux->left;
        }

         // Substitui o valor do nó a ser removido pelo valor do menor nó encontrado
        root->entry = aux->entry;

        // Remove o menor nó encontrado na subárvore direita
        root->right = delete(root->right, aux->entry);
    }

    root->count = 1 + (root->left ? root->left->count : 0) + (root->right ? root->right->count : 0);

    root->bal = balanceFactor(root);

    // Caso Left Left (LL)
    if (root->bal > 1 && balanceFactor(root->left) >= 0) {
        return rotateRight(root);
    }

    // Caso Left Right (LR)
    if (root->bal > 1 && balanceFactor(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Caso Right Right (RR)
    if (root->bal < -1 && balanceFactor(root->right) <= 0) {
        return rotateLeft(root);
    }

    // Caso Right Left (RL)
    if (root->bal < -1 && balanceFactor(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;

}




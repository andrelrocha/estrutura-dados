#include <stdlib.h>
#include <stdio.h>
#include "avltree.h"

AVLTree* createAVLTree() {
    AVLTree *tree = (AVLTree*)malloc(sizeof(AVLTree));
    tree->root = NULL;
    return tree;
}

void destroyAVLTree(AVLTree *tree) {
    void destroyNode(AVLNode *node) {
        if (node != NULL) {
            destroyNode(node->left);
            destroyNode(node->right);
            free(node);
        }
    }

    destroyNode(tree->root);
    free(tree);
}

int getHeight(AVLNode *node) {
    return (node == NULL) ? 0 : node->height;
}

// Fun��o para obter o fator de balanceamento de um n�
int getBalance(AVLNode *node) {
    return (node == NULL) ? 0 : getHeight(node->left) - getHeight(node->right);
}

AVLNode* rotateLeft(AVLNode *node) {
    AVLNode *newRoot = node->right;
    AVLNode *temp = newRoot->left;

    newRoot->left = node;
    newRoot->right = temp;

    node->height = 1 + ((getHeight(node->left) > getHeight(node->right)) ? getHeight(node->left) : getHeight(node->right));
    newRoot->height = 1 + ((getHeight(newRoot->left) > getHeight(newRoot->right)) ? getHeight(newRoot->left) : getHeight(newRoot->right));

    return newRoot;
}

AVLNode* rotateRight(AVLNode *node) {
    AVLNode* newRoot = node->left;
    AVLNode* temp = newRoot->right;

    newRoot->left = temp;
    newRoot->right = node;

    node->height = 1 + ((getHeight(node->left) > getHeight(node->right)) ? getHeight(node->left) : getHeight(node->right));
    newRoot->height = 1 + ((getHeight(node->left) > getHeight(node->right)) ? getHeight(node->left): getHeight(node->right));

    return newRoot;
}

void printNode(AVLNode *node) {
    if (node != NULL) {
        printNode(node->left);
        printf("%d ", node->key);
        printNode(node->right);
    }
}

void printAVLTree(AVLTree *tree) {
    printf("AVLTree: ");
    printNode(tree->root);
    printf("\n");
}

AVLNode* insertNode(AVLNode *node, int key) {
    if (node == NULL) {
        node = (AVLNode*)malloc(sizeof(AVLNode));
        node->height = 1;
        node->key = key;
        node->left = NULL;
        node->right = NULL;
    }

    if (key < node->key) {
        node->left = insertNode(node->left, key);
    } else if (key > node->key) {
        node->right = insertNode(node->right, key);
    } else {
        return node; // Chave duplicada n�o � permitida
    }

    node->height = 1 + ((getHeight(node->left) > getHeight(node->right)) ? getHeight(node->left) : getHeight(node->right));

    int balance = getBalance(node);

    // Caso 1: Rota��o � esquerda
    if (balance > 1 && key < node->left->key) {
        return rotateRight(node);
    }

    // Caso 2: Rota��o � esquerda direita
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Caso 3: Rota��o � direita
    if (balance < -1 && key > node->right->key) {
        return rotateLeft(node);
    }

    // Caso 4: Rota��o � direita esquerda
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

AVLNode* deleteNode(AVLNode *root, int key) {
    // caso base recursivo
    if (root == NULL) {
        return root;
    }

    // Passo 1: Realiza a busca e remo��o
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // N� a ser removido encontrado
        if (root->left == NULL) {
            AVLNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            AVLNode *temp = root->left;
            free(root);
            return temp;
        }

        // N� com dois filhos: encontra o menor n� na sub�rvore direita
        AVLNode *temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
         // Substitui o valor do n� a ser removido pelo valor do menor n� encontrado
        root->key = temp->key;

        // Remove o menor n� encontrado na sub�rvore direita
        root->right = deleteNode(root->right, temp->key);
    }

    root->height = 1 + ((getHeight(root->left) > getHeight(root->right)) ? getHeight(root->left) : getHeight(root->right));

    int balance = getBalance(root);

    // Caso 1: Rota��o � esquerda
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rotateRight(root);
    }

    // Caso 2: Rota��o � esquerda direita
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Caso 3: Rota��o � direita
    if (balance < -1 && getBalance(root->right) <= 0) {
        return rotateLeft(root);
    }

    // Caso 4: Rota��o � direita esquerda
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Fun��o auxiliar para buscar um n� na �rvore AVL
AVLNode* searchNode(AVLNode *node, int key) {
    // Se o n� � NULL ou a chave � encontrada
    if (node == NULL || node->key == key) {
        return node;
    }

    // Se a chave � menor que a chave do n� atual, busca na sub�rvore esquerda
    if (key < node->key) {
        return searchNode(node->left, key);
    }

    // Se a chave � maior que a chave do n� atual, busca na sub�rvore direita
    return searchNode(node->right, key);
}


AVLNode* insertAVL(AVLTree *tree, int key) {
    tree->root = insertNode(tree->root, key);
    return tree->root;
}

AVLNode* deleteAVL(AVLTree *tree, int key) {
    tree->root = deleteNode(tree->root, key);
    return tree->root;
}

AVLNode* searchAVL(AVLTree *tree, int key) {
    return searchNode(tree->root, key);
}

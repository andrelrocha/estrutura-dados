#ifndef AVL_TREE_H
#define AVL_TREE_H

typedef struct AVLNode {
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

typedef struct {
    AVLNode *root;
} AVLTree;

// Funções da árvore AVL
AVLTree* createAVLTree();
void destroyAVLTree(AVLTree *tree);
AVLNode* insertAVL(AVLTree *tree, int key);
AVLNode* deleteAVL(AVLTree *tree, int key);
AVLNode* searchAVL(AVLTree *tree, int key);
void printAVLTree(AVLTree *tree);
int getHeight(AVLNode *node);
int getBalance(AVLNode *node);
AVLNode* rotateLeft(AVLNode *node);
AVLNode* rotateRight(AVLNode *node);

#endif

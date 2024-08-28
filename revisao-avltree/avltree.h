
#ifndef AVL_TREE_H
#define AVL_TREE_H

typedef struct TreeNode {
    int entry;
    int bal;        // Fator de balan�o
    int count;      // N�mero de elementos na sub�rvore
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef TreeNode* TreePointer;

// Fun��es para manipula��o da �rvore AVL
TreePointer createNode(int entry);  //OK
void printAVLTree(TreePointer node); //OK
void destroyAVLTree(TreePointer root); //OK

TreePointer insert(TreePointer root, int entry); //OK
TreePointer delete(TreePointer root, int entry);
TreePointer search(TreePointer root, int entry);

void inorderTraversal(TreePointer root);
void preorderTraversal(TreePointer root);
void postorderTraversal(TreePointer root);


#endif

typedef int key;

typedef struct node {
    int key;
    struct node* next;
} Node;

typedef struct {
    Node* top;
    int tam;
} Lista;

void createVoidList(Lista* lista);
void printList(Lista* lista);
int addValueToQueue(Lista* lista, int element);

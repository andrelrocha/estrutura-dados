typedef struct node {
    int key;
    struct node* next;
} Node;

typedef struct {
    int tam;
    Node* top;
} Lista;

void createEmptyList(Lista* lista);
int addElementAtStart(Lista* lista, int elem);
int addElementAtEnd(Lista* lista, int elem);
int addElementBefore(Lista* lista, int elem, int comp);
int addElementAfter(Lista* lista, int elem, int comp);

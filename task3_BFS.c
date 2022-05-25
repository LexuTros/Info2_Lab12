#include<stdio.h>
#include<stdlib.h>


typedef struct node {
    int val;
    struct node *next;
} node_t;

void enqueue(node_t **head, int val) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    if (!new_node) return;

    new_node->val = val;
    new_node->next = *head;

    *head = new_node;
}


int isEmpty(node_t **head) {
	if (*head == NULL) return 1;
	else return 0;
}

int dequeue(node_t **head) {
    node_t *current, *prev = NULL;
    int retval = -1;

    if (*head == NULL) return -1;

    current = *head;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    retval = current->val;
    free(current);
    
    if (prev)
        prev->next = NULL;
    else
        *head = NULL;

    return retval;
}

void BFS(int adj[7][7], char V[], int n, int s){
    // Initialising all Vertexes as White
    for (int i = 0; i < n; i++)
    {
        V[i] = 'W';
    }
    
    V[s] = 'G';
    node_t* Q = NULL;
    enqueue(&Q, s);
    while (!isEmpty(&Q))
    {
        int v = dequeue(&Q);
        for (int i = 0; i < n; i++)
        {
            if (adj[v][i]) // if vertex i is adjacent to v
            {
                if (V[i] == 'W') {V[i] = 'G'; enqueue(&Q, i);}
            }
        }
        V[v] = 'B';
    }
}

// Helper function checks if all Vertices were visited (=are different from W)
int rootChecker(char V[], int n){
    for (int i = 0; i < n; i++)
    {
        if (V[i] == 'W') {return 0;};
    }
    return 1;
}

// Helper function prints the found Root Vertices
void resPrinter(int R[], int n){
    printf("The Root Vertexes of the Graph are:\n");
    for (int j = 0; j < n; j++)
    {
        if (R[j] != 0) {printf("%d\n", j);}
    }
}

// Checks every Vertex for root property and prints the Result
void rootFinder(int adj[7][7], char V[], int n){
    int R[7] = {0,0,0,0,0,0}; // array of root vertexes
    for (int i = 0; i < n; i++)
    {
        BFS(adj, V, n, i);
        if (rootChecker(V, n)) {R[i] = 1;}
    }
    resPrinter(R, n);
}


int main() {
	int adj[7][7] = {
		{0,0,0,0,0,0,0},	
		{1,1,0,0,0,0,0},
		{0,0,1,1,0,0,0},
		{0,0,0,1,1,0,0},
		{0,1,0,0,1,1,0},
		{0,0,0,0,1,1,1},
		{0,0,1,0,0,0,1}
		};

    char Vertex[7]; // array of vertexes with only relevant property "color": W - white, G - gray, B - Black
    int n = 7;

    rootFinder(adj, Vertex, n);

    return 0;
}


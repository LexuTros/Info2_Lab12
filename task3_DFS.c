#include<stdio.h>
#include<stdlib.h>


void DFS_Tree(int adj[7][7], char V[], int n, int s){
    V[s] = 'G';
    for (int i = 0; i < n; i++)
    {
        if (adj[s][i]) // if vertex i is adjacent to s
        {
            if (V[i] == 'W') {DFS_Tree(adj, V, n, i);}
        }
    }
    V[s] = 'B';
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
        for (int j = 0; j < n; j++) {V[j] = 'W';} // Initialising all Vertexes as White
        DFS_Tree(adj, V, n, i);
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


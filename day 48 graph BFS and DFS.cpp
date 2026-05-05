#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue for BFS
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int v) {
    queue[rear++] = v;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Graph using adjacency matrix
int adj[MAX][MAX];
int visited[MAX];
int n; // number of vertices

// Add edge (undirected)
void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// BFS Traversal
void BFS(int start) {
    // Reset visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    front = rear = 0;

    visited[start] = 1;
    enqueue(start);

    printf("BFS Traversal: ");

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }

    printf("\n");
}

// DFS Traversal (Recursive)
void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

// Display adjacency matrix
void displayMatrix() {
    printf("\nAdjacency Matrix:\n   ");
    for (int i = 0; i < n; i++)
        printf("%d ", i);
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    displayMatrix();

    printf("\nEnter starting vertex: ");
    scanf("%d", &start);

    BFS(start);

    // Reset visited for DFS
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}

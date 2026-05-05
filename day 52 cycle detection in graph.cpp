#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

// DFS utility for cycle detection in directed graph
int dfsCycleDirected(int vertex, int recStack[]) {
    visited[vertex] = 1;
    recStack[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i]) {
            if (!visited[i]) {
                if (dfsCycleDirected(i, recStack))
                    return 1;
            }
            else if (recStack[i]) {
                return 1; // Back edge found = cycle
            }
        }
    }

    recStack[vertex] = 0;
    return 0;
}

// Detect cycle in directed graph
int hasCycleDirected() {
    int recStack[MAX] = {0};

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsCycleDirected(i, recStack))
                return 1;
        }
    }

    return 0;
}

// DFS utility for cycle detection in undirected graph
int dfsCycleUndirected(int vertex, int parent) {
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i]) {
            if (!visited[i]) {
                if (dfsCycleUndirected(i, vertex))
                    return 1;
            }
            else if (i != parent) {
                return 1; // Cycle detected
            }
        }
    }

    return 0;
}

// Detect cycle in undirected graph
int hasCycleUndirected() {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsCycleUndirected(i, -1))
                return 1;
        }
    }

    return 0;
}

int main() {
    int edges, u, v, type;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter 1 for Directed, 2 for Undirected graph: ");
    scanf("%d", &type);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        if (type == 2)
            adj[v][u] = 1;
    }

    if (type == 1) {
        if (hasCycleDirected())
            printf("\nCycle DETECTED in directed graph!\n");
        else
            printf("\nNo cycle in directed graph.\n");
    } else {
        if (hasCycleUndirected())
            printf("\nCycle DETECTED in undirected graph!\n");
        else
            printf("\nNo cycle in undirected graph.\n");
    }

    return 0;
}

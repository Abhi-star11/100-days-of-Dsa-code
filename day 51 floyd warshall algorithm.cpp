#include <stdio.h>

#define MAX 100
#define INF 99999

int n;

// Floyd-Warshall Algorithm
void floydWarshall(int dist[MAX][MAX]) {
    int i, j, k;

    // Apply Floyd-Warshall
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF
                    && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print result
    printf("\nShortest Distance Matrix:\n");
    printf("     ");
    for (i = 0; i < n; i++)
        printf("%5d", i);
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%3d: ", i);
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("  INF");
            else
                printf("%5d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int dist[MAX][MAX];
    int edges, u, v, w;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        dist[u][v] = w;
    }

    printf("\nInitial Distance Matrix:\n");
    printf("     ");
    for (int i = 0; i < n; i++)
        printf("%5d", i);
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%3d: ", i);
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("  INF");
            else
                printf("%5d", dist[i][j]);
        }
        printf("\n");
    }

    floydWarshall(dist);

    return 0;
}

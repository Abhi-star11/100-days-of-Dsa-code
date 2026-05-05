#include <stdio.h>

#define MAX 100
#define INF 99999

int graph[MAX][MAX];
int visited[MAX];
int dist[MAX];
int n;

// Find unvisited vertex with minimum distance
int minDistance() {
    int min = INF, minIndex = -1;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Dijkstra's Algorithm
void dijkstra(int src) {
    int parent[MAX];

    // Initialize
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance();

        if (u == -1) break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print results
    printf("\nShortest distances from vertex %d:\n", src);
    printf("Vertex\tDistance\tPath\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t", i);

        if (dist[i] == INF) {
            printf("INF\t-\n");
        } else {
            printf("%d\t", dist[i]);

            // Print path
            int path[MAX], pathLen = 0;
            int j = i;
            while (j != -1) {
                path[pathLen++] = j;
                j = parent[j];
            }

            for (int k = pathLen - 1; k >= 0; k--) {
                printf("%d", path[k]);
                if (k > 0) printf("->");
            }
            printf("\n");
        }
    }
}

int main() {
    int edges, u, v, w, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(src);

    return 0;
}

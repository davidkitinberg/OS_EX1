#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 1000000000

int adj[MAX_VERTICES][MAX_VERTICES];
int dist[MAX_VERTICES];
int visited[MAX_VERTICES];
int num_vertices;

void dijkstra(int src) {
    for (int i = 0; i < num_vertices; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < num_vertices - 1; count++) {
        int u = -1;
        for (int i = 0; i < num_vertices; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        if (dist[u] == INF) break; // No more reachable vertices
        visited[u] = 1;

        for (int v = 0; v < num_vertices; v++) {
            if (!visited[v] && adj[u][v] && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
}

void reset_graph() {
    for (int i = 0; i < MAX_VERTICES; i++)
        for (int j = 0; j < MAX_VERTICES; j++)
            adj[i][j] = 0;
}

int main() {
    while (1) {
        int num_edges;
        printf("Enter number of vertices and edges: ");
        if (scanf("%d %d", &num_vertices, &num_edges) != 2) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        reset_graph();

        printf("Enter edges (u v w):\n");
        for (int i = 0; i < num_edges; i++) {
            int u, v, w;
            if (scanf("%d %d %d", &u, &v, &w) != 3 || u < 0 || v < 0 || u >= num_vertices || v >= num_vertices || w < 0) {
                printf("Invalid edge values.\n");
                i--; // try again
                continue;
            }
            adj[u][v] = w;
            adj[v][u] = w;  // ← גרף לא מכוון
        }

        int src;
        printf("Enter source vertex: ");
        if (scanf("%d", &src) != 1 || src < 0 || src >= num_vertices) {
            printf("Invalid source vertex.\n");
            continue;
        }

        dijkstra(src);

        printf("\nShortest distances from vertex %d:\n", src);
        for (int i = 0; i < num_vertices; i++) {
            if (dist[i] == INF)
                printf("Vertex %d: Unreachable\n", i);
            else
                printf("Vertex %d: %d\n", i, dist[i]);
        }

        printf("\n--- New graph input ---\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 100
#define INF 1000000000

int adj[MAX_VERTICES][MAX_VERTICES];
int dist[MAX_VERTICES];
int visited[MAX_VERTICES];
int num_vertices;
int num_edges;
bool isFirstTime = true;

void dijkstra(int src) {
    // Algorithm initialization
    for (int i = 0; i < num_vertices; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0; // Set source vertex dist to 0

    for (int count = 0; count < num_vertices - 1; count++) 
    {
        int u = -1;
        for (int i = 0; i < num_vertices; i++) 
        {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) 
            {
                u = i;
            }
        }

        if (dist[u] == INF) break; // No more reachable vertices
        visited[u] = 1;

        for (int v = 0; v < num_vertices; v++) 
        {
            if (!visited[v] && adj[u][v] && dist[u] + adj[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
}

// Reset adjacency matrix
void reset_graph() {
    for (int i = 0; i < MAX_VERTICES; i++)
        for (int j = 0; j < MAX_VERTICES; j++)
            adj[i][j] = 0;
}

int main() {
    while (1) {
        ///////// Build the graph through user's input from scratch /////////
        printf("\n==== New Graph ====\n");

        if(!isFirstTime)
        {
            printf("Run again? (1 = yes, 0 = no): ");
            int again;
            if(scanf("%d", &again) == 1)
            {
                if (again == 0) 
                {
                    printf("Exiting.\n");
                    break;
                }
            }
        }
        
        // Reading from stdin the number of vertices and edges for the new graph
        char extra; // To clear the input line

        // Read number of vertices
        while (1) {
            printf("Enter number of vertices: ");
            int result = scanf("%d%c", &num_vertices, &extra);
    
            if (result == 2 && extra == '\n' && num_vertices >= 0) {
                break; // Valid input
            }
    
            fprintf(stderr, "Error: Please enter exactly one non-negative integer.\n");
    
            // Flush everything until newline
            while ((result = getchar()) != '\n' && result != EOF);
        }

        // Read number of edges
        while (1) {
            printf("Enter number of edges: ");
            int result = scanf("%d%c", &num_edges, &extra);
    
            if (result == 2 && extra == '\n' && num_edges >= 0) {
                break; // Valid input
            }
    
            fprintf(stderr, "Error: Please enter exactly one non-negative integer.\n");
    
            // Flush everything until newline
            while ((result = getchar()) != '\n' && result != EOF);
        }

        reset_graph(); // Reset adjacency matrix for the new graph

        printf("Enter edges (u v w):\n");
        for (int i = 0; i < num_edges;) 
        {
            int u, v, w;
            // Reading from stdin each edge and it's weight for the new graph
            if (scanf("%d %d %d", &u, &v, &w) != 3 || u < 0 
                        || v < 0 || u >= num_vertices 
                        || v >= num_vertices || w < 0 || u == v) {
                fprintf(stderr, "Error: Please input correct vertices and weight values\n");
                fprintf(stderr, "Vertices must be between 0 and %d (inclusive), and weights must be non-negative.\n", num_vertices - 1);
                while (getchar() != '\n'); // clear garbage input
                printf("Enter edges (u v w):\n"); // Roll-back to input again
                continue; // stay on the same i
            }
            adj[u][v] = w;
            adj[v][u] = w;  // In undirected graph we add a directed edge on each side
            i++; // move to next edge only if successful
        }

        // Reading from stdin the wanted source vertex's index for the new graph
        int src;
        while (1) {
            printf("Enter source vertex: ");
            if (scanf("%d", &src) != 1 || src < 0 || src >= num_vertices) {
                fprintf(stderr, "Error: Please input correct source vertex's index\n");
                fprintf(stderr, "The source index must be between 0 and %d\n", num_vertices - 1);
                while (getchar() != '\n'); // clear bad input
                continue;
            }
            while (getchar() != '\n'); // clear extra input
            break;
        }

        dijkstra(src); // We run dijkstra on the new graph

        ///////// Print the shortest parths that we recieve from dijkstra /////////
        printf("\nShortest distances from vertex %d:\n", src);
        for (int i = 0; i < num_vertices; i++) 
        {
            if (dist[i] == INF)
                printf("Vertex %d: Unreachable\n", i);
            else
                printf("Vertex %d: %d\n", i, dist[i]);
        }

        isFirstTime = false;
    }

    return 0;
}

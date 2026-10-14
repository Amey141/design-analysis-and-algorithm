#include <stdio.h>
#include <stdlib.h>

#define INF 1e9

// Structure to represent a weighted edge in the graph
struct Edge {
    int u, v, w;
};

// Recursive function to print the path from source to vertex j
void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d", j);
        return;
    }
    printPath(parent, parent[j]);
    printf("->%d", j);
}

int main() {
    int V, E;
    if (scanf("%d", &V) != 1) return 0;
    if (scanf("%d", &E) != 1) return 0;

    // Dynamically allocate memory for edges
    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    for (int i = 0; i < E; i++) {
        if (scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w) != 3) {
            return 0;
        }
    }

    int src;
    if (scanf("%d", &src) != 1) return 0;

    // Initialize distance and parent arrays
    int* dist = (int*)malloc((V + 1) * sizeof(int));
    int* parent = (int*)malloc((V + 1) * sizeof(int));

    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0;

    // Relax all edges V - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    // Check for negative-weight cycles
    int negative_cycle = 0;
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            negative_cycle = 1;
            break;
        }
    }

    // Output results matching the layout structure
    if (negative_cycle) {
        printf("Negative cycle detected\n");
    } else {
        for (int i = 1; i <= V; i++) {
            if (i == src) continue; // Skip source vertex as per rules
            
            if (dist[i] == INF) {
                printf("%d INF None\n", i);
            } else {
                printf("%d %d ", i, dist[i]);
                printPath(parent, i);
                printf("\n");
            }
        }
    }

    // Free dynamically allocated memory
    free(edges);
    free(dist);
    free(parent);
    return 0;
}


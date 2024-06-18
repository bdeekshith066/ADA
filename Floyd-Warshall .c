#include <stdio.h>
#include <limits.h>

#define V 10 // Maximum number of vertices in the graph

// Function to print the solution matrix
void printSolution(int dist[][V], int n) {
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

// Function to implement Floyd's algorithm for All-Pairs Shortest Path Problem
void floydWarshall(int graph[][V], int n) {
    int dist[V][V];

    // Initialize the solution matrix with the given graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    // Update dist[] matrix to find the shortest path between every pair of vertices
    for (int k = 0; k < n; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < n; i++) {
            // Pick all vertices as destination for the above picked source
            for (int j = 0; j < n; j++) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distances matrix
    printSolution(dist, n);
}

int main() {
    int n;

    printf("Enter the number of vertices in the graph (maximum %d): ", V);
    scanf("%d", &n);

    if (n <= 0 || n > V) {
        printf("Invalid input. Number of vertices should be between 1 and %d.\n", V);
        return 1;
    }

    int graph[V][V];

    printf("Enter the adjacency matrix of the graph (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    floydWarshall(graph, n);

    return 0;
}

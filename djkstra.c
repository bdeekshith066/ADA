#include<stdio.h>

void dijkstra(int src, int n, int cost[10][10], int dest[10], int vis[10]) {
    int i, count, min, u;

    // Initialize arrays and variables
    for (i = 0; i < n; i++) {
        dest[i] = cost[src][i];  // Initialize distances from source to all vertices
        vis[i] = 0;  // Initialize all vertices as not visited
    }
    vis[src] = 1;  // Mark the source vertex as visited
    dest[src] = 0;  // Distance from source to itself is 0
    count = 1;  // Initialize count of visited vertices

    while (count < n) {
        min = 999;
        // Find the vertex with minimum distance which is not visited
        for (i = 0; i < n; i++) {
            if (dest[i] < min && !vis[i]) {
                min = dest[i];
                u = i;
            }
        }

        vis[u] = 1;  // Mark the selected vertex as visited

        // Update distances of the adjacent vertices of the selected vertex
        for (i = 0; i < n; i++) {
            if (!vis[i] && dest[u] + cost[u][i] < dest[i]) {
                dest[i] = dest[u] + cost[u][i];
            }
        }

        count++;
    }
}

int main() {
    int i, n, src;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int cost[10][10], dest[10], vis[10];

    // Input the cost matrix
    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Input the source vertex
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    // Call Dijkstra's algorithm function
    dijkstra(src, n, cost, dest, vis);

    // Output the shortest paths
    printf("Shortest paths from vertex %d:\n", src);
    for (i = 0; i < n; i++) {
        printf("%d -> %d : %d\n", src, i, dest[i]);
    }

    return 0;
} 


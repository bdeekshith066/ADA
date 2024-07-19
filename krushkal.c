#include <stdio.h>

#define MAX_VERTICES 10

int cost[MAX_VERTICES][MAX_VERTICES], n;
int t[MAX_VERTICES][2]; 
int sum = 0;

void kruskal();
int find(int parent[], int vertex);

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    
    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    kruskal();

    printf("Edges of the minimal spanning tree:\n");
    for (int i = 0; i < n - 1; i++) {
        printf("(%d, %d) ", t[i][0], t[i][1]);
    }
    printf("\nSum of minimal spanning tree: %d\n", sum);

    return 0;
}

// Implementation of Kruskal's algorithm
void kruskal() {
    int min, u, v, count = 0;
    int parent[MAX_VERTICES]; // Array to keep track of parent of each vertex

    // Initialize parent array for Union-Find
    for (int i = 0; i < n; i++) {
        parent[i] = i; // Each vertex is its own parent initially
    }

    while (count < n - 1) {
        min = 999;

        u = -1;
        v = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                if (find(parent, i) != find(parent, j) && cost[i][j] < min) {
                    min = cost[i][j];
                    u = i; /
                    v = j; 
                }
            }
        }

        int root_u = find(parent, u); 
        int root_v = find(parent, v); 

        if (root_u != root_v) {
            parent[root_u] = root_v; 
            t[count][0] = u;
            t[count][1] = v; 
            sum += min; 
            count++; 
        }
    }
}

// Function to find the root parent of a vertex using path compression technique
int find(int parent[], int vertex) {
    while (parent[vertex] != vertex) { // Traverse up to find root parent
        vertex = parent[vertex]; // Move up to parent
    }
    return vertex; // Return the root parent
}


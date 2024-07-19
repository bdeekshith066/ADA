
#include <stdio.h>
#include <stdbool.h>

#define INF 999  // Define INF as 999

void prims(int V, int G[V][V]) {
    int no_edge = 0;  
    bool selected[V];  
    
  
    for (int i = 0; i < V; i++) {
        selected[i] = false;
    }

    selected[0] = true;

    int x, y; 


    printf("Edge : Weight\n");

    while (no_edge < V - 1) {
        int min = INF;  
        x = 0;
        y = 0;

   
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
         
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j] && G[i][j] < min) {
                  
                        min = G[i][j];  
                        x = i;  
                        y = j;  
                    }
                }
            }
        }

        
        printf("%d - %d : %d\n", x, y, G[x][y]);

        
        selected[y] = true;
        no_edge++;
    }
}

int main() {
    int V;  
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int G[V][V];

   
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &G[i][j]);  
        }
    }

  
    prims(V, G);

    return 0;
}

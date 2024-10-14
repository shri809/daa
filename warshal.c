#include <stdio.h>

#define V 4  // Number of vertices

// Function to print the matrix
void printMatrix(int matrix[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Warshall's algorithm to find the transitive closure
void warshallAlgorithm(int graph[V][V]) {
    int reach[V][V];

    // Initialize reach matrix with the input graph's adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            reach[i][j] = graph[i][j];
        }
    }

    // Update the reach matrix using Warshall's algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    printf("Transitive closure matrix:\n");
    printMatrix(reach);
}

int main() {
    // Adjacency matrix of the graph
    int graph[V][V] = {
        {0, 1, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    warshallAlgorithm(graph);
    return 0;
}

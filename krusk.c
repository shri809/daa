#include <stdio.h>
#include <stdlib.h>

#define INF 999  // A large value to represent infinity

// Function to find the parent of a node (using path compression)
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

// Function to perform the union of two sets
void unionSets(int parent[], int rank[], int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);

    if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
    } else if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
    } else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

// Function to implement Kruskal's algorithm
void kruskal(int cost[10][10], int n) {
    int parent[n + 1], rank[n + 1];
    int mincost = 0, edges = 0;

    // Initialize parent and rank arrays
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    printf("\nEdges in the Minimum Spanning Tree:\n");

    // Continue until we have n-1 edges in the MST
    while (edges < n - 1) {
        int min = INF, u = -1, v = -1;

        // Find the smallest edge that doesn't form a cycle
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cost[i][j] < min && find(parent, i) != find(parent, j)) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        // Perform the union and include the edge in the MST
        unionSets(parent, rank, u, v);
        printf("Edge %d -> %d with cost = %d\n", u, v, min);
        mincost += min;
        edges++;

        // Mark the edge as used by setting its cost to infinity
        cost[u][v] = cost[v][u] = INF;
    }

    printf("\nMinimum cost of the spanning tree = %d\n", mincost);
}

int main() {
    int n, cost[10][10];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        printf("Enter the elements of row %d:\n", i);
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    kruskal(cost, n);

    return 0;
}

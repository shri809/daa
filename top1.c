#include <stdio.h>

void topologicalSort(int graph[10][10], int n)
{
    int inDegree[10] = {0};          // Array to store in-degree of each vertex
    int result[10], resultIndex = 0; // Store topological order
    int i, j;

    // Calculate the in-degree of all vertices
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[j][i] == 1)
            {
                inDegree[i]++;
            }
        }
    }

    // Perform Topological Sorting by vertex removal
    for (int count = 0; count < n; count++)
    {
        // Find a vertex with in-degree 0
        int currentVertex = -1;
        for (i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                currentVertex = i;
                break;
            }
        }

        // If no vertex with in-degree 0 is found, there’s a cycle
        if (currentVertex == -1)
        {
            printf("The graph contains a cycle! Topological sorting not possible.\n");
            return;
        }

        // Add the current vertex to the result and "remove" it from the graph
        result[resultIndex++] = currentVertex;
        inDegree[currentVertex] = -1; // Mark the vertex as removed

        // Decrease the in-degree of its adjacent vertices
        for (j = 0; j < n; j++)
        {
            if (graph[currentVertex][j] == 1)
            {
                inDegree[j]--;
            }
        }
    }

    // Print the topological order
    printf("Topological Order: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main()
{
    int n, i, j, graph[10][10];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter the elements of row %d:\n", i + 1);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    topologicalSort(graph, n);

    return 0;
}

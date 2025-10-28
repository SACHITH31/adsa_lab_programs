#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTEX 100

void dfs (int graph[MAX_VERTEX][MAX_VERTEX], int visited[MAX_VERTEX], int vertex, int start) {
    printf("%d", start);
    visited[start] = 1;

    for (int i = 0; i < vertex; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs(graph, visited, vertex, i);
        }
    }
}


int main () {
    int vertex, edge;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertex);

    if (vertex <= 0 || vertex > MAX_VERTEX) {
        printf("Invalid Vertex");
        return 1;
    }

    int graph[MAX_VERTEX][MAX_VERTEX] = {0};
    int visited[MAX_VERTEX] = {0};

    printf("Enter the number of edges: ");
    scanf("%d", &edge);

    if (edge < 0 || edge > vertex * (vertex - 1)) {
        printf("Invalid Edges");
        return 1;
    }

    for (int i = 0; i < edge; i++) {
        int start, end;
        printf("Enter the start and end for %d", i + 1);
        scanf("%d %d", &start, &end);

        if (start < 0 || end < 0 || start >= vertex || end >= vertex) {
            printf("Invalid ");
            i--;
            continue;
        }
        graph[start][end] = 1;
    }


    int startVertex;
    printf("Enter start vertex: ");
    scanf("%d", &startVertex);

    if (startVertex <= 0 || startVertex > vertex) {
        printf("Invalid");
        return 1;
    }

    dfs(graph, visited, vertex, startVertex);
    return 0;
}
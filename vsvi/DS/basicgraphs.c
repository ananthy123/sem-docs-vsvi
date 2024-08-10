// Basically, there are 2 ways you can represent graphs, either by matrix or by adjacent list.
// I am hoping that your instructor has moved on to C++ by this time since it is very hard to code adjacency list in C.
// The basic concepts you need to focus on graphs are BFS, DFS, and then algorithms regarding min distance.

#include <stdio.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;

void initializeGraph() {
    int i, j;
    numVertices = 0;

    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int source, int destination) {
    if (source >= 0 && source < numVertices && destination >= 0 && destination < numVertices) {
        graph[source][destination] = 1;
        graph[destination][source] = 1;
    }
}

void printGraph() {
    int i, j;

    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initializeGraph();

    // Add edges to the graph
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 4);

    // Print the adjacency matrix
    printGraph();

    return 0;
}

#include <stdbool.h>
#include <stdlib.h>
#include "../../adt/Graph.h"
#include "../../adt/Stack.h"

static int componentSize(Graph g, int start, bool *visited, int *vertices) {
    int size = 0;
    Stack s = StackNew();

    visited[start] = true;
    StackPush(s, &vertices[start]);

    while (!StackIsEmpty(s)) {
        int v = *(int *) StackPop(s);
        size++;

        for (int i = 0; i < GraphDegree(g, v); i++) {
            int w = GraphNeighbour(g, v, i);
            if (!visited[w]) {
                visited[w] = true;
                StackPush(s, &vertices[w]);
            }
        }
    }

    StackFree(s, NULL);
    return size;
}

int findHappyComponent(Graph g, int k) {
    int nV = GraphNumVertices(g);
    bool *visited = calloc(nV, sizeof(bool));
    int *vertices = malloc(nV * sizeof(int));
    for (int v = 0; v < nV; v++) {
        vertices[v] = v;
    }

    int count = 0;
    for (int v = 0; v < nV; v++) {
        if (!visited[v] && componentSize(g, v, visited, vertices) >= k) {
            count++;
        }
    }

    free(visited);
    free(vertices);
    return count;
}

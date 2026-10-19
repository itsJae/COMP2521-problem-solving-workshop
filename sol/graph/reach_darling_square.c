#include <stdbool.h>
#include <stdlib.h>
#include "../../adt/Graph.h"
#include "../../adt/Queue.h"

bool reachDarlingSquare(Graph g, int src, int dest) {
    int nV = GraphNumVertices(g);
    bool *visited = calloc(nV, sizeof(bool));
    int *vertices = malloc(nV * sizeof(int));
    for (int v = 0; v < nV; v++) {
        vertices[v] = v;
    }

    Queue q = QueueNew();
    visited[src] = true;
    QueueEnqueue(q, &vertices[src]);

    bool found = false;
    while (!QueueIsEmpty(q)) {
        int v = *(int *) QueueDequeue(q);
        if (v == dest) {
            found = true;
            break;
        }

        for (int i = 0; i < GraphDegree(g, v); i++) {
            int w = GraphNeighbour(g, v, i);
            if (!visited[w]) {
                visited[w] = true;
                QueueEnqueue(q, &vertices[w]);
            }
        }
    }

    QueueFree(q, NULL);
    free(visited);
    free(vertices);
    return found;
}

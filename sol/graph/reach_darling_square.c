#include <stdbool.h>
#include <stdio.h>
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

static Graph buildGraph(int nV, int edges[][2], int nEdges) {
    Graph g = GraphNew(nV);
    for (int i = 0; i < nEdges; i++) {
        GraphInsertEdge(g, edges[i][0], edges[i][1]);
    }
    return g;
}

static void runTest(char *name, int nV, int edges[][2], int nEdges,
                    int src, int dest, bool expected) {
    Graph g = buildGraph(nV, edges, nEdges);
    bool actual = reachDarlingSquare(g, src, dest);
    printf("%-4s %-10s -> got %s, expected %s\n",
           actual == expected ? "PASS" : "FAIL", name,
           actual ? "true" : "false", expected ? "true" : "false");
    GraphFree(g);
}

int main(void) {
    int edges1[][2] = {{1, 2}, {2, 0}, {0, 3}, {4, 5}};
    runTest("test1", 6, edges1, 4, 1, 3, true);
    runTest("test2", 6, edges1, 4, 1, 5, false);
    runTest("test3", 6, edges1, 4, 4, 5, true);
    runTest("test4", 6, edges1, 4, 2, 2, true);
    runTest("test5", 3, NULL, 0, 0, 2, false);

    int edges6[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    runTest("test6", 5, edges6, 4, 0, 4, true);

    return 0;
}

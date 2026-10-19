#include <stdbool.h>
#include <stdio.h>
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

static Graph buildGraph(int nV, int edges[][2], int nEdges) {
    Graph g = GraphNew(nV);
    for (int i = 0; i < nEdges; i++) {
        GraphInsertEdge(g, edges[i][0], edges[i][1]);
    }
    return g;
}

static void runTest(char *name, int nV, int edges[][2], int nEdges, int k, int expected) {
    Graph g = buildGraph(nV, edges, nEdges);
    int actual = findHappyComponent(g, k);
    printf("%-4s %-10s -> got %d, expected %d\n",
           actual == expected ? "PASS" : "FAIL", name, actual, expected);
    GraphFree(g);
}

int main(void) {
    int edges1[][2] = {{1, 2}, {2, 0}, {0, 3}, {4, 5}};
    runTest("test1", 6, edges1, 4, 3, 1);
    runTest("test2", 6, edges1, 4, 2, 2);
    runTest("test3", 6, edges1, 4, 5, 0);
    runTest("test4", 4, NULL, 0, 1, 4);

    int edges5[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    runTest("test5", 5, edges5, 4, 5, 1);

    return 0;
}

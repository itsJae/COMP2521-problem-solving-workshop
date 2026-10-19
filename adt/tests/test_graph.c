#include "../Graph.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    Graph g = GraphNew(5);
    assert(GraphNumVertices(g) == 5);
    assert(GraphNumEdges(g) == 0);

    GraphInsertEdge(g, 0, 1);
    GraphInsertEdge(g, 1, 2);
    GraphInsertEdge(g, 3, 4);

    assert(GraphNumEdges(g) == 3);
    assert(GraphDegree(g, 0) == 1);
    assert(GraphDegree(g, 1) == 2);
    assert(GraphDegree(g, 2) == 1);
    assert(GraphDegree(g, 3) == 1);
    assert(GraphDegree(g, 4) == 1);

    bool hasZero = false, hasTwo = false;
    for (int i = 0; i < GraphDegree(g, 1); i++) {
        int w = GraphNeighbour(g, 1, i);
        if (w == 0) hasZero = true;
        if (w == 2) hasTwo = true;
    }
    assert(hasZero && hasTwo);

    GraphFree(g);
    printf("test_graph: all tests passed\n");
    return 0;
}

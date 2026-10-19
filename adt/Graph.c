#include "Graph.h"

#include <stdlib.h>
#include <assert.h>

struct graph {
    int nV;
    int nE;
    int **adj;
    int *degree;
};

static void addNeighbour(Graph g, int v, int w) {
    g->adj[v] = realloc(g->adj[v], (g->degree[v] + 1) * sizeof(int));
    g->adj[v][g->degree[v]] = w;
    g->degree[v]++;
}

Graph GraphNew(int nV) {
    Graph g = malloc(sizeof(*g));
    assert(g != NULL);
    g->nV = nV;
    g->nE = 0;
    g->adj = calloc(nV, sizeof(int *));
    g->degree = calloc(nV, sizeof(int));
    return g;
}

void GraphFree(Graph g) {
    for (int v = 0; v < g->nV; v++) {
        free(g->adj[v]);
    }
    free(g->adj);
    free(g->degree);
    free(g);
}

void GraphInsertEdge(Graph g, int v, int w) {
    assert(v >= 0 && v < g->nV);
    assert(w >= 0 && w < g->nV);
    addNeighbour(g, v, w);
    addNeighbour(g, w, v);
    g->nE++;
}

int GraphNumVertices(Graph g) {
    return g->nV;
}

int GraphNumEdges(Graph g) {
    return g->nE;
}

int GraphDegree(Graph g, int v) {
    assert(v >= 0 && v < g->nV);
    return g->degree[v];
}

int GraphNeighbour(Graph g, int v, int i) {
    assert(v >= 0 && v < g->nV);
    assert(i >= 0 && i < g->degree[v]);
    return g->adj[v][i];
}

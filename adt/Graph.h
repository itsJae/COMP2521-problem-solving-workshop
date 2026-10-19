/**
 * Undirected graph, adjacency-list representation, opaque type.
 */

#ifndef GRAPH_H
#define GRAPH_H

typedef struct graph *Graph;

/**
 * Creates a new graph with nV vertices (labelled 0 .. nV-1) and no edges
 */
Graph GraphNew(int nV);

/**
 * Frees all memory associated with the given graph
 */
void GraphFree(Graph g);

/**
 * Inserts an undirected edge between vertices v and w
 */
void GraphInsertEdge(Graph g, int v, int w);

/**
 * Returns the number of vertices in the graph
 */
int GraphNumVertices(Graph g);

/**
 * Returns the number of edges in the graph
 */
int GraphNumEdges(Graph g);

/**
 * Returns the degree (number of neighbours) of vertex v
 */
int GraphDegree(Graph g, int v);

/**
 * Returns the i-th neighbour of vertex v
 */
int GraphNeighbour(Graph g, int v, int i);

#endif

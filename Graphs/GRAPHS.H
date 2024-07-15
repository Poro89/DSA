#ifndef GRAPHS_H
#define GRAPHS_H

#define MAX_VERTICES 5

extern int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
extern char vertices[MAX_VERTICES];
extern int vertexCount;

void addVertex(char vertex);
void addEdge(char start, char end);
void deleteVertex(char vertex);
void displayAdjacencyMatrix(const char* message);

#endif


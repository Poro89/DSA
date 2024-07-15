#include <stdio.h>
#include "graphs.h"

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
char vertices[MAX_VERTICES] = {'A', 'B', 'C', 'D', 'E'};
int vertexCount = 5;

void addVertex(char vertex) {
    if (vertexCount < MAX_VERTICES) {
        vertices[vertexCount++] = vertex;
    } else {
        printf("Cannot add more vertices.\n");
    }
}

void addEdge(char start, char end) {
    int startIndex = -1, endIndex = -1;
    
    int i;
    for ( i = 0; i < vertexCount; i++) {
        if (vertices[i] == start) {
            startIndex = i;
        }
        if (vertices[i] == end) {
            endIndex = i;
        }
    }
    
    if (startIndex != -1 && endIndex != -1) {
        adjacencyMatrix[startIndex][endIndex] = 1;
        adjacencyMatrix[endIndex][startIndex] = 1;
    } else {
        printf("Invalid vertices.\n");
    }
}

void deleteVertex(char vertex) {
    int vertexIndex = -1;

	int i, j;
    for ( i = 0; i < vertexCount; i++) {
        if (vertices[i] == vertex) {
            vertexIndex = i;
            break;
        }
    }
    
    if (vertexIndex == -1) {
        printf("Vertex not found.\n");
        return;
    }

    for ( i = vertexIndex; i < vertexCount - 1; i++) {
        vertices[i] = vertices[i + 1];
    }
    vertexCount--;

    for ( i = vertexIndex; i < vertexCount; i++) {
        for ( j = 0; j < MAX_VERTICES; j++) {
            adjacencyMatrix[i][j] = adjacencyMatrix[i + 1][j];
        }
    }
    for ( i = vertexIndex; i < vertexCount; i++) {
        for ( j = 0; j < MAX_VERTICES; j++) {
            adjacencyMatrix[j][i] = adjacencyMatrix[j][i + 1];
        }
    }

    for ( i = 0; i < MAX_VERTICES; i++) {
        adjacencyMatrix[vertexCount][i] = 0;
        adjacencyMatrix[i][vertexCount] = 0;
    }
}

void displayAdjacencyMatrix(const char* message) {
    printf("%s\n", message);
    printf("  ");
    int i, j;
    for ( i = 0; i < vertexCount; i++) {
        printf("%c ", vertices[i]);
    }
    printf("\n");
    
    for ( i = 0; i < vertexCount; i++) {
        printf("%c ", vertices[i]);
        for ( j = 0; j < vertexCount; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


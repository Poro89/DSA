#include <stdio.h>
#include <stdlib.h>
#include "graphs.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char c;
	int i;
	for ( c = 'A'; c <= 'E'; c++) {
    addVertex(c);
    }
    
    printf("Vertices added:\n");
    for ( i = 0; i < vertexCount; i++) {
        printf("%c ", vertices[i]);
    }
    printf("\n\n");
    
    displayAdjacencyMatrix("Initial Adjacency Matrix:");
    
    addEdge('A', 'B');
    addEdge('A', 'C');
    addEdge('A', 'D');
    addEdge('B', 'C');
    addEdge('B', 'D');
    addEdge('B', 'E');
    addEdge('C', 'D');
    addEdge('D', 'E');
    
    displayAdjacencyMatrix("Final Adjacency Matrix:");
    
    deleteVertex('C');
    
    displayAdjacencyMatrix("Adjacency Matrix after deleting vertex C:");
    
	return 0;
}

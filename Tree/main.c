#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	NodePtr root = NULL;
    Product p;

	int i;
    for ( i = 0; i < 3; i++) {
        printf("Enter details for product %d:\n", i + 1);
        inputProduct(&p);
        root = insert(root, p);
    }

    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    printf("BFS Traversal: ");
    bfs(root);
    printf("\n");

    char deleteName[20];
    printf("Enter product name to delete: ");
    scanf("%s", deleteName);
    root = deleteNode(root, deleteName);
    printf("Inorder Traversal after deletion: ");
    inorder(root);
    printf("\n");

	return 0;
}

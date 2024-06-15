#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[20];
	int idNum;
	int age;
	
}info;

typedef struct node {
	info data;
	struct node* next;
}node;

node* createNode(info data){
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insertFront(node** head, info data) {
	node* newNode = createNode(data);
	newNode->next = *head;
	*head = newNode;
}

void printList(node* head){
	node* current = head;
	while(current != NULL){
		printf("Name: %s, ID: %d, Age: %d\n", current->data.name, current->data.idNum, current->data.age);
		current=current->next;
	}
}

int main(){
    node* head = NULL;
    info data;
    int i;

    for ( i = 0; i < 3; i++) {
        printf("Enter data for person %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", data.name);
        printf("ID: ");
        scanf("%d", &data.idNum);
        printf("Age: ");
        scanf("%d", &data.age); 

        insertFront(&head, data);
    }

    printf("\nLinked List:\n");
    printList(head);
    
    node* current = head;
    node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    return 0;
}

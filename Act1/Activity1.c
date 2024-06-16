#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int age;
    struct Student* next;
} Student;

Student* head = NULL; 


void insertFront(Student* new_student);
void insertRear(Student* new_student);
void insertByIndex(int index, Student* new_student);
void displayList();
void swap(Student* a, Student* b);
void sortByAge();

int main() {
    
    Student s1 = {"Todd", 25, NULL};
    Student s2 = {"John", 28, NULL};
    Student s3 = {"Charlie", 27, NULL};

    insertFront(&s1);
    insertRear(&s2);
    insertByIndex(1, &s3);

    printf("List before sorting:\n");
    displayList();

	printf("\n");
    sortByAge();

    printf("List after sorting:\n");
    displayList();

    return 0;
}

void insertFront(Student* new_student) {
    new_student->next = head;
    head = new_student;
}

void insertRear(Student* new_student) {
    if (head == NULL) {
        head = new_student;
        new_student->next = NULL;
    } else {
        Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_student;
        new_student->next = NULL;
    }
}

void insertByIndex(int index, Student* new_student) {
	int i;
    if (index == 0) {
        insertFront(new_student);
        return;
    }
Student* temp = head;
    for ( i = 0; i < index - 1; ++i) {
        if (temp == NULL) {
            printf("Index out of bounds\n");
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Index out of bounds\n");
        return;
    }

    new_student->next = temp->next;
    temp->next = new_student;
}

void displayList() {
    Student* temp = head;
    while (temp != NULL) {
        printf("Name: %s, Age: %d\n", temp->name, temp->age);
        temp = temp->next;
    }
}

void swap(Student* a, Student* b) {
    char temp_name[50];
    int temp_age;

    strcpy(temp_name, a->name);
    temp_age = a->age;

    strcpy(a->name, b->name);
    a->age = b->age;

    strcpy(b->name, temp_name);
    b->age = temp_age;
}

void sortByAge() {
    if (head == NULL) {
        return;
    }

    int swapped;
    Student* ptr1;
    Student* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->age > ptr1->next->age) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

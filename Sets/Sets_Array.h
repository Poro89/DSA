#ifndef Sets_Array
#define Sets_Array

#define MAX_SIZE 20

typedef struct {
    int elements[MAX_SIZE];
    int size;
} Set;

void add(Set *set, int value);
void delete(Set *set, int value);
void findUnion(Set *set1, Set *set2, Set *result);
void findIntersection(Set *set1, Set *set2, Set *result);
void printSet(Set *set);
void inputSet(Set *set); 


#endif

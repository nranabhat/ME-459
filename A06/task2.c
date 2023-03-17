#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

int main() {
    // Print the size of each structure
    printf("Size of struct A: %ld bytes\n", sizeof(struct A));
    printf("Size of struct B: %ld bytes\n", sizeof(struct B));
    
    // Allocate a struct A in heap memory
    struct A* a = (struct A*) malloc(sizeof(struct A));
    
    // Set the fields of the struct
    a->i = 42;
    a->c = 'x';
    a->d = 3.14;
    
    // Print each field of the struct
    printf("i: %d\n", a->i);
    printf("c: %c\n", a->c);
    printf("d: %f\n", a->d);
    
    // Free the memory allocated for the struct
    free(a);
    
    return 0;
}

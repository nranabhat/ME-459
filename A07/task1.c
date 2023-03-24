#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

#define ARRAY_SIZE 10

int main() {
    int A[ARRAY_SIZE];
    srand(time(NULL));
    printf("Original array: ");
    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        A[i] = rand() % 100;
        printf("%d ", A[i]);
    }
    printf("\n");
    sort(A, ARRAY_SIZE);
    printf("Sorted array: ");
    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}

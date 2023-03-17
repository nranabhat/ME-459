#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return *(int*) b - *(int*) a;
}

int main(int argc, char* argv[]) {
    // Check that a single command line argument was provided
    if (argc != 2) {
        return 0;
    }
    
    // Convert the command line argument to an integer
    int N = atoi(argv[1]);
    
    // Check that the input is a positive integer
    if (N <= 0) {
        return 0;
    }
    
    // Allocate dynamically an array of N + 1 ints
    int* arr = (int*) malloc((N + 1) * sizeof(int));
    
    // Fill the array with values 0, 1, ..., N
    for (int i = 0; i <= N; i++) {
        arr[i] = i;
    }
    
    // Print the array
    for (int i = 0; i <= N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Sort the array in descending order using qsort
    qsort(arr, N + 1, sizeof(int), compare);
    
    // Print the sorted array
    for (int i = 0; i <= N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Free dynamically allocated memory
    free(arr);
    
    return 0;
}

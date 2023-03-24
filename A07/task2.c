#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mvmul.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s n\n", argv[0]);
        return 1;
    }
    const size_t n = atoi(argv[1]);

    // Allocate matrix A
    double *A = (double *) malloc(n * n * sizeof(double));

    // Allocate vectors b and c
    double *b = (double *) malloc(n * sizeof(double));
    double *c = (double *) malloc(n * sizeof(double));

    // Initialize matrix A with random numbers
    srand(time(NULL));
    for (size_t i = 0; i < n * n; i++) {
        A[i] = ((double) rand() / RAND_MAX) * 2.0 - 1.0;
    }

    // Initialize vector b with all 1's
    for (size_t i = 0; i < n; i++) {
        b[i] = 1.0;
    }

    // Perform matrix-vector multiplication and time it
    clock_t start = clock();
    mvmul(A, b, c, n);
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

    // Print last entry of vector c
    printf("Last entry of c: %f\n", c[n - 1]);

    // Free dynamically allocated memory
    free(A);
    free(b);
    free(c);

    // Print time it took for matrix-vector multiplication
    printf("Time for matrix multiplication: %f ms\n", time);

    return 0;
}

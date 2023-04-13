#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sumArray.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s n\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0 || n > 4096) {
        printf("n must be between 1 and 4096\n");
        return 1;
    }

    double* A = (double*) malloc(n * n * sizeof(double));
    if (A == NULL) {
        printf("Failed to allocate memory for matrix A\n");
        return 1;
    }

    // Fill matrix A with random values in the range [-1, 1]
    srand(time(NULL));
    for (int i = 0; i < n * n; i++) {
        A[i] = (double)rand() / RAND_MAX * 2.0 - 1.0;
    }

    // Time and compute sum using sumArray1
    clock_t start = clock();
    double sum1 = sumArray1(A, n);
    clock_t end = clock();
    double time1 = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

    // Time and compute sum using sumArray2
    start = clock();
    double sum2 = sumArray2(A, n);
    end = clock();
    double time2 = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

    printf("sumArray1: sum = %lf, time = %lf ms\n", sum1, time1);
    printf("sumArray2: sum = %lf, time = %lf ms\n", sum2, time2);

    free(A);
    return 0;
}

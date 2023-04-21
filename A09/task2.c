#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N_ELEMS 131072 // 512KB data array with 8-byte doubles

void test1(double* data, int elems, int stride);
void test2(double* data, int elems, int stride);

int main() {
    double* data = malloc(N_ELEMS * sizeof(double));
    if (data == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    // Initialize data array with random double numbers in the range [-1,1]
    for (int i = 0; i < N_ELEMS; i++) {
        data[i] = ((double)rand()/(double)(RAND_MAX)) * 2.0 - 1.0;
    }

    // Warm up cache by calling test1 once
    test1(data, N_ELEMS, 1);

    struct timeval start, end;
    double elapsedTime, totalTime;

    // Test for different stride values
    int strideValues[] = {1, 2, 4, 8, 11, 15, 17};
    int numStrideValues = sizeof(strideValues) / sizeof(int);
    printf("test1: ");
    for (int i = 0; i < numStrideValues; i++) {
        totalTime = 0.0;
        for (int j = 0; j < 100; j++) {
            gettimeofday(&start, NULL);
            test1(data, N_ELEMS, strideValues[i]);
            gettimeofday(&end, NULL);
            elapsedTime = (end.tv_sec - start.tv_sec) * 1000.0;
            elapsedTime += (end.tv_usec - start.tv_usec) / 1000.0;
            totalTime += elapsedTime;
        }
        printf("%.2f ", totalTime/100.0);
    }
    printf("\n");

    printf("test2: ");
    for (int i = 0; i < numStrideValues; i++) {
        totalTime = 0.0;
        for (int j = 0; j < 100; j++) {
            gettimeofday(&start, NULL);
            test2(data, N_ELEMS, strideValues[i]);
            gettimeofday(&end, NULL);
            elapsedTime = (end.tv_sec - start.tv_sec) * 1000.0;
            elapsedTime += (end.tv_usec - start.tv_usec) / 1000.0;
            totalTime += elapsedTime;
        }
        printf("%.2f ", totalTime/100.0);
    }
    printf("\n");

    free(data);
    return 0;
}

void test1(double* data, int elems, int stride) {
    int i;
    double result = 0.0;
    volatile double sink; // To prevent the loop from being optimized away
    for (i = 0; i < elems; i += stride) {
        result += data[i];
    }
    sink = result;
}

void test2(double* data, int elems, int stride) {
    int i;
    volatile double result = 0.0; // Prefix result with volatile
    volatile double sink; // To prevent the loop from being optimized away
    for (i = 0; i < elems; i += stride) {
        result += data[i];
    }
    sink = result;
}

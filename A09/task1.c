#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matmul.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s n\n", argv[0]);
    return 1;
  }

  const size_t n = atoi(argv[1]);
  if (n <= 0) {
    fprintf(stderr, "n must be a positive integer\n");
    return 1;
  }

  double *A = (double*)malloc(n * n * sizeof(double));
  double *B = (double*)malloc(n * n * sizeof(double));
  double *C = (double*)malloc(n * n * sizeof(double));

  // Fill matrices A and B with random double numbers in the range [-1,1]
  srand(time(NULL));
  for (size_t i = 0; i < n * n; ++i) {
    A[i] = ((double)rand()/(double)(RAND_MAX)) * 2.0 - 1.0;
    B[i] = ((double)rand()/(double)(RAND_MAX)) * 2.0 - 1.0;
  }

  // Time the mmul1 function call
  clock_t start = clock();
  mmul1(A, B, C, n);
  clock_t end = clock();

  // Output the timing results in milliseconds along with the last element of the resulting C matrix
  double last_element = C[n * n - 1];
  double time_elapsed = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
  printf("%.3f %f\n", time_elapsed, last_element);

  // Free the memory
  free(A);
  free(B);
  free(C);

  return 0;
}

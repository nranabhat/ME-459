#include "sumArray.h"

double sumArray1(const double* A, const size_t n) {
    double sum = 0.0;
    size_t i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            sum += A[i * n + j];
        }
    }
    return sum;
}

double sumArray2(const double* A, const size_t n) {
    double sum = 0.0;
    size_t i, j;
    for (j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {
            sum += A[i * n + j];
        }
    }
    return sum;
}

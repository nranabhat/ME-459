#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matmul.h"

#define DIM 1024
#define IDX(i,j,ld) (((i)*(ld))+(j))

int main() {
    double *A = (double *) malloc(DIM * DIM * sizeof(double));
    double *B = (double *) malloc(DIM * DIM * sizeof(double));
    double *C1 = (double *) malloc(DIM * DIM * sizeof(double));
    double *C2 = (double *) malloc(DIM * DIM * sizeof(double));
    double *C3 = (double *) malloc(DIM * DIM * sizeof(double));
    double *C4 = (double *) malloc(DIM * DIM * sizeof(double));

    srand(time(NULL)); // seed random number generator

    // initialize A and B with random values
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            A[IDX(i,j,DIM)] = ((double) rand() / RAND_MAX) * 2.0 - 1.0;
            B[IDX(i,j,DIM)] = ((double) rand() / RAND_MAX) * 2.0 - 1.0;
        }
    }

    // compute matrix product using mmul1
    clock_t start = clock();
    mmul1(A, B, C1, DIM);
    double time1 = (double) (clock() - start) / CLOCKS_PER_SEC * 1000;

    // compute matrix product using mmul2
    start = clock();
    mmul2(A, B, C2, DIM);
    double time2 = (double) (clock() - start) / CLOCKS_PER_SEC * 1000;

    // compute matrix product using mmul3
    start = clock();
    double *Bt = (double *) malloc(DIM * DIM * sizeof(double));
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            Bt[IDX(i,j,DIM)] = B[IDX(j,i,DIM)];
        }
    }
    mmul3(A, Bt, C3, DIM);
    double time3 = (double) (clock() - start) / CLOCKS_PER_SEC * 1000;
    free(Bt);

    // compute matrix product using mmul4
    start = clock();
    double *At = (double *) malloc(DIM * DIM * sizeof(double));
    double *Bt2 = (double *) malloc(DIM * DIM * sizeof(double));
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            At[IDX(i,j,DIM)] = A[IDX(j,i,DIM)];
            Bt2[IDX(i,j,DIM)] = B[IDX(j,i,DIM)];
        }
    }
    mmul4(At, B, C4, DIM);
    double time4 = (double) (clock() - start) / CLOCKS_PER_SEC * 1000;
    free(At);
    free(Bt2);

    // output timing results and last element of C matrix for each function
    printf("mmul1: %lf ms, C[%d,%d] = %lf\n", time1, DIM-1, DIM-1, C1[IDX(DIM-1,DIM-1,DIM)]);
    printf("mmul2: %lf ms, C[%d,%d] = %lf\n", time2, DIM-1, DIM-1, C2[IDX(DIM-1,DIM-1,DIM)]);
    printf("mmul3: %lf ms, C[%d,%d] = %lf\n", time3, DIM-1, DIM-1, C3[IDX(DIM-1,DIM-1,DIM)]);
    printf("mmul4: %lf ms, C[%d,%d] = %lf\n", time4, DIM-1, DIM-1, C4[IDX(DIM-1,DIM-1,DIM)]);

    free(A);
    free(B);
    free(C1);
    free(C2);
    free(C3);
    free(C4);

    return 0;
}

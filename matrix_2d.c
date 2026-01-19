#include <stdio.h>
#include <omp.h>
#define N 1000

int main() {
    int i, j, k;
    double A[N][N], B[N][N], C[N][N];
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            A[i][j] = i;
            B[i][j] = i+1;
            C[i][j] = i+2;
        }
    }
    double start = omp_get_wtime();
    #pragma omp parallel for collapse(2)
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            for(k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    double end = omp_get_wtime();
    printf("2D threading time = %f", end - start);
    return 0;
}

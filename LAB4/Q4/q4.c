#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 8

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    setbuf(stdout, NULL);

    if (N % size != 0) {
        if (rank == 0) printf("Error: N must be divisible by number of processes.\n");
        MPI_Finalize();
        return 0;
    }

    int local_n = N / size;
    int local_A[local_n], local_B[local_n];

    int A[N] = {1,2,3,4,5,6,7,8};
    int B[N] = {8,7,6,5,4,3,2,1};

    MPI_Scatter(A, local_n, MPI_INT, local_A, local_n, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(B, local_n, MPI_INT, local_B, local_n, MPI_INT, 0, MPI_COMM_WORLD);

    int local_dot = 0;
    for (int i = 0; i < local_n; i++) local_dot += local_A[i] * local_B[i];

    int global_dot = 0;
    MPI_Reduce(&local_dot, &global_dot, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    printf("Rank %d local_dot=%d\n", rank, local_dot);

    if (rank == 0) {
        printf("\nDot Product = %d (Expected 120)\n", global_dot);
    }

    MPI_Finalize();
    return 0;
}

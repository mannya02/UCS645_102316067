    } else {
        MPI_Recv(&value, 1, MPI_INT, prev, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        value += rank;
        printf("Rank %d updated value to %d\n", rank, value);

        MPI_Send(&value, 1, MPI_INT, next, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>
#include <time.h>

int main(int argc, char* argv[])
{
    int local_count, flip = 1 << 28;
    int rank, num_ranks, i, iter, provided;
    double x,y,z,pi;

    MPI_Init_thread(&argc, &argv, MPI_THREAD_SINGLE, &provided);

    double start_time, stop_time, elapsed_time;
    start_time = MPI_Wtime();

    MPI_Comm_size(MPI_COMM_WORLD, &num_ranks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    srand(time(NULL) + 123456789 + rank*100);

    flip = flip/num_ranks;

    for (iter = 0; iter < flip; iter++)
    {
        x = (double) random() / (double) RAND_MAX;
        y = (double) random() / (double) RAND_MAX;
        z = sqrt(x*x + y*y); 
        if (z <= 1.0)
            local_count++;
    }

    if (rank == 0)
    {
        int counts[num_ranks - 1];
        MPI_Status requests[num_ranks - 1];
        int global_count = 0;

        for (i = 1; i < num_ranks; i++)
        {
            // MPI_Irecv for non-blocking
            MPI_Recv(&counts[i-1], 1, MPI_INT, i, 0, MPI_COMM_WORLD, &requests[i-1]);
        }
        // MPI_Waitall for non-blocking
        global_count += local_count;
        for (i = 0; i < num_ranks - 1; i++)
        {
            global_count += counts[i];
        }
        pi = ((double) global_count / (double) (flip*num_ranks)) * 4.0;
    }
    else
    {
        // buf, count, datatype, dest, tag, communicator
        MPI_Send(&local_count, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    stop_time = MPI_Wtime();
    elapsed_time = stop_time - start_time;
    if (rank == 0)
    {
        printf("pi: %f\n", pi);
        printf("Execution time: %f\n", elapsed_time);
    }
    MPI_Finalize();
    return 0;
}
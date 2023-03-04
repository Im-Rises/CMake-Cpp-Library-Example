/*
 * This file is an example of using OpenMPI to calculate twin prime numbers.
 * It is one of my project, which you can find details about in the GitHub link below:
 * https://github.com/Im-Rises/cTwinPrimeNumberParallel/tree/main
 */

#include <cstdio>
#include <cstdlib>
#include <mpi.h>
#include <cmath>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define BLOCK_LOW(id, p, n) ((id) * (n) / (p))
#define BLOCK_HIGH(id, p, n) (BLOCK_LOW((id) + 1, p, n) - 1)
#define BLOCK_SIZE(id, p, n) (BLOCK_LOW((id) + 1, p, n) - BLOCK_LOW(id, p, n))
#define BLOCK_OWNER(index, p, n) (((p) * ((index) + 1) - 1) / (n))

int main(int argc, char** argv) {
    int count = 0;
    double elapsed_time;
    int first;
    int global_count = 0;
    /*    int high_value;*/
    int i;
    int id;
    int index;
    int low_value;
    char* marked;
    int n;
    int p;
    /*    int proc0_size;*/
    int prime;
    int size;

    /*MPI_Init(&argc, &argv);*/
    int provided;
    MPI_Init_thread(&argc, &argv, MPI_THREAD_SINGLE, &provided);

    MPI_Barrier(MPI_COMM_WORLD);

    /* Start timer */
    elapsed_time = -MPI_Wtime();

    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    if (!id)
    {
        printf("|-----Sieve of Eratosthenes Parallel MPI V1-----|\n\n");
        printf("Started with %d processes\n", p);
    }

    if (argc != 2)
    {
        if (!id)
        {
            printf("Command line: %s <m>\n", argv[0]);
        }
        MPI_Finalize();
        exit(1);
    }

    n = atoi(argv[1]);

    if (sqrt(n) >= (double)n / p)
    {
        if (!id)
        {
            printf("Error : Too many processes\n");
        }
        MPI_Finalize();
        exit(1);
    }

    low_value = 2 + BLOCK_LOW(id, p, n - 1);
    size = BLOCK_SIZE(id, p, n - 1);

    marked = (char*)malloc(size * sizeof(char));

    if (marked == NULL)
    {
        printf("Cannot allocate enough memory\n");
        MPI_Finalize();
        exit(1);
    }

    for (i = 0; i < size; i++)
    {
        marked[i] = 0;
    }

    if (!id)
    {
        index = 0;
    }

    prime = 2;

    do
    {
        if (prime * prime > low_value)
        {
            first = prime * prime - low_value;
        }
        else
        {
            if (!(low_value % prime))
            {
                first = 0;
            }
            else
            {
                first = prime - (low_value % prime);
            }
        }

        for (i = first; i < size; i += prime)
        {
            marked[i] = 1;
        }

        if (!id)
        {
            while (marked[++index])
                ;
            prime = index + 2;
        }

        MPI_Bcast(&prime, 1, MPI_INT, 0, MPI_COMM_WORLD);
    } while (prime * prime <= n);

    /* Count twin primes in process*/
    count = 0;
    for (i = 0; i < size; i++)
    {
        if (marked[i] == 0)
        {
            if (i + 2 < size && marked[i + 2] == 0)
                count++;
        }
    }

    /* Count twin primes between processes*/
    if (p > 1 && id != p - 1)
    {
        MPI_Send(&marked[size - 2], 2, MPI_CHAR, id + 1, 0, MPI_COMM_WORLD);
    }

    if (id != 0)
    {
        char prev[2];
        MPI_Recv(&prev, 2, MPI_CHAR, id - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        if (prev[0] == 0 && marked[0] == 0)
            count++;
        if (prev[1] == 0 && marked[1] == 0)
            count++;
    }


    /* Sum local counts */
    MPI_Reduce(&count, &global_count, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    /* Free array */
    free(marked);

    /* Stop timer */
    elapsed_time += MPI_Wtime();

    /* Print results */
    if (!id)
    {
        printf("There are %d twin primes less than or equal to %d\n", global_count, n);
        printf("Total elapsed time: %10.6f\n", elapsed_time);
    }

    /* Finalize MPI */
    MPI_Finalize();

    return 0;
}

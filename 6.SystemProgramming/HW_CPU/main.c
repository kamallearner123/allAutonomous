#include <mpi.h>
#include <stdio.h>
#include "getcpuid.h"

int main(int argc, char** argv)
{
    int id, np;
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int processor_name_len;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Get_processor_name(processor_name, &processor_name_len);

    int cpu_id = get_cpu_id();
    printf("Hello from process %03d out of %03d, hostname %s, cpu_id %d\n", 
        id, np, processor_name, cpu_id);

    MPI_Finalize();
    return 0;
}


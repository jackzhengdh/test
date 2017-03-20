#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

int main(void) {
	int comm_sz;
	int my_rank;
	int num[6] = {1, 2, 3, 4, 2, 1};
	int result = 0;

	MPI_Init(NULL, NULL);
	comm = MPI_COMM_WORLD;
	MPI_Comm_size(comm, &comm_sz);
	MPI_Comm_rank(comm, &my_rank);

	// if (my_rank != 0) {
	// 	MPI_Reduce(num, &result, 6, MPI_INT, MPI_MIN, 0, comm);
	// }	
	// else {
	// 	MPI_Reduce(num, &result, 6, MPI_INT, MPI_MIN, 0, comm);
	// 	printf("%d\n", result);
	// }
	

	MPI_Allreduce(num, &result, 1, MPI_INT, MPI_MIN, comm);
	if (my_rank == 0) {
		printf("%d\n", result);
	}
	// MPI_Reduce(num, &result, 6, MPI_INT, MPI_MIN, 0, comm);
	// printf("%d\n", result);
	MPI_Finalize();
	return 0;
}
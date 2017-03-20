#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
	int comm_sz;
	int my_rank;
	int num[6] = {1, 2, 3, 4, 2, 1};
	int result = 0;

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	if (my_rank!= 0)
		MPI_Reduce(num, &result, 6, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
	else {
		MPI_Reduce(num, &result, 6, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
		printf("%d\n", result);
	}
	
	// MPI_Reduce(num, &result, 6, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
	// printf("%d\n", result);
	MPI_Finalize();
	return 0;
}
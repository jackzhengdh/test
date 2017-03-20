/* File: read.c
 *
 * Purpose: Demonstrate file input in c language.
 *
 * Compile: gcc -o read read.c
 * Run: ./read
 *
 * Input: x.txt
 * Output: Content of input file
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void read_input(int* n_p, double* err_p, FILE* fp);
void read_matrix(int n, double x[], FILE* fp);

/*---------------------------------------------------------------------------*/

int main(int argc, char *argv[]) {

	int n, local_n;
	double err;
	int my_rank, comm_sz;
	double* x;

	char *filename = argv[1];
	printf("Check filename %s\n", filename);
	FILE* fp;
	fp = fopen(filename, "r");

	read_input(&n, &err, fp);

	printf("test %d\n", n);
	printf("test %lf\n", err);
	x = malloc(n * sizeof(double));

	read_matrix(n, x, fp);
	for (int i = 0; i < n; i++) {
		printf("%lf ", x[i]);
	}
	printf("\n");

}

void read_input(int* n_p, double* err_p, FILE* fp) {

	fscanf(fp, "%d ", n_p);
	fscanf(fp, "%lf ", err_p);

}

void read_matrix(int n, double x[], FILE* fp) {
	
	for (int i = 0; i < n; i++) {
		fscanf(fp, "%lf", &x[i]);
	}
}



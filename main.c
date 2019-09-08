#include <stdio.h>
#include <stdlib.h>
#include "init.h"

int main()
{
	double **mat;
	mat = malloc(3 * sizeof *mat);
	for (int i = 0; i < 3; ++i)
		mat[i] = malloc(3 * sizeof *mat[i]);

	init_zeroes(mat, 3, 3);
	return 0;
}

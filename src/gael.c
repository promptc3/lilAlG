#include <stdio.h>
#include <stdlib.h>
#include "../include/function.h"

void gael(double** mat, double* y, int n, int m);

void gael(double** mat, double* y, int n, int m)
{
	/* throw error if number of eqns is less than no of vars */
	if (m > n) {
		fprintf(stderr, "No Possible Solution\n");
		exit(-1);
	}

	/* perform triangularizarion */
	r_upptri(mat, y, n, m);

	/* perform back substitution */
	r_bacsub(mat, y, n, m);

}

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main()
{
	/* get rows ans columns */
	int n, m;
	double** mat, y[n];
	init_mat(mat, n, m);
	init_vec(y, n);

	/* throw error if number of eqns is less than no of vars */
	if (m > n) {
		fprintf(stderr, "No Possible Solution\n");
		exit(-1);
	}

	/* perform triangularizarion */
	trnglrz(mat, y, n, m);

	/* perform back substitution */
	back_subs(mat, y, n, m);

	return 0;
}

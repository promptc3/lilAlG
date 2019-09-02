#include <stdio.h>
#include <stdlib.h>
#include "gael.h"

int main()
{
	/* get rows ans columns */
	int n, m;
	scanf("%d %d", &n, &m);

	/* throw error if number of eqns is less than no of vars */
	if (m > n) {
		fprintf(stderr, "No Possible Solution\n");
		exit(-1);
	}
	double** mat, y[n];

	/* allocate size to matrix */
	mat = malloc(n * sizeof *mat);
	for (int i=0; i < n; ++i)
		mat[i] = malloc(m * sizeof *mat[i]);

	/* get all the elements of the matrix */
	for (int i=0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%lf", &mat[i][j]);
		}
	}

	/* get the Y matrix */
	for (int i=0; i < n; ++i)
		scanf("%lf", &y[i]);

	/* perform triangularizarion */
	trnglrz(mat, y, n, m);

	/* perform back substitution */
	back_subs(mat, y, n, m);


	/* free the allocated memory */
	for (int i=0; i < n; ++i) free(mat[i]);
	free(mat);

	return 0;
}

void trnglrz(double** mat, double y[], int r, int c)
{
	/* Transform into upper triangular matrix */
	for (int i = 0; i < r; ++i) {
		double div = mat[i][i];

		for (int j=0; j < c; ++j)
			mat[i][j] = mat[i][j]/div;

		y[i] = y[i]/div;

		for (int k=i+1; k < r; ++k) {
			if (k < r) {
				double temp[c], temp_y, mult = mat[k][i];
				for (int j = 0; j < c; ++j) {
					temp[j] = mat[i][j]*mult;
					mat[k][j] = mat[k][j] - temp[j];
				}
				temp_y = y[i]*mult;
				y[k] = y[k] - temp_y;
			}
			else continue;
		}
	}
}

void back_subs(double** mat, double y[], int r, int c)
{
	double ans[r];
	/* Perform back substitution */
	ans[r-1] = y[r-1];
	for (int i = r-2; i >= 0; --i) {
		double sum = 0;
		for (int j = c-i-1; j < c; ++j)
			sum += ans[j]*mat[i][j];
		ans[i] = y[i] - sum;
	}
	/* print the answer */
	for (int i=0; i < r; ++i)
		printf("%0.3f\t", ans[i]);
}

#include <stdio.h>
#include "utils.h"

int main()
{ }

void r_init_mat(double **matrix, int row, int column)
{
	scanf("%d %d", &row, &column);
	for (int i=0; i < row; ++i) {
		for (int j=0; j < column; ++j)
			scanf("%lf", &matrix[i][j]);
	}
}

void r_init_vec(double *vector, int size)
{
	scanf("%d", &size);
	for (int i = 0; i < size; ++i)
		scanf("%lf", &vector[i]);
}

/* Convert to upper triangular */
void r_upptri(double** mat, double y[], int r, int c)
{
	for (int i = 0; i < r; ++i) {
		double pivot = mat[i][i];

		for (int j=0; j < c; ++j)
			mat[i][j] = mat[i][j]/pivot;

		y[i] = y[i]/pivot;

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

/* Perform back substitution */
double* r_bacsub(double** mat, double y[], int r, int c)
{
	double ans[r];
	ans[r-1] = y[r-1];
	for (int i = r-2; i >= 0; --i) {
		double sum = 0;
		for (int j = c-i-1; j < c; ++j)
			sum += ans[j]*mat[i][j];
		ans[i] = y[i] - sum;
	}

	return *ans;
}

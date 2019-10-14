#include <stdio.h>
#include "../include/function.h"

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
	double *p_ans;
	ans[r-1] = y[r-1];
	for (int i = r-2; i >= 0; --i) {
		double sum = 0;
		for (int j = c-i-1; j < c; ++j)
			sum += ans[j]*mat[i][j];
		ans[i] = y[i] - sum;
	}
	p_ans = ans;

	return p_ans;
}

int max_vec(double *vector, int s)
{
	double t_max = 0;int i_max = 0;
	for (int i=0; i < s; ++i) {
		if (vector[i] > t_max) {
			t_max = vector[i];
			i_max = i;
		}
	}
	return i_max;
}

void swap_vec(double *a, double *b, int s)
{
	double temp;
	for(int i = 0; i < s; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}


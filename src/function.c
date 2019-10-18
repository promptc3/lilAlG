#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "../include/function.h"

/* Cholesky Decomposition */
void cholesky(double** mat, int n)
{
	double ans[n][n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; j++) {
			ans[i][j] = 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0;  j < i; ++j) {
			
			double sum = 0;
			if (i == j) {
				for (int k = 0; k < j; ++k)
					sum += pow(ans[j][k], 2);
				ans[j][j] = sqrt(mat[j][j] - sum);
			}
			else {
				for (int k = 0; k < j; ++k)
					sum += (ans[i][k]*ans[j][k]);
				ans[i][j] = (mat[i][j] - sum) / ans[j][j];
			}
		}
	}

	for(int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {	
			mat[i][j] = ans[i][j];
		}
	}
}
/* Convert to upper triangular */
void upptrngl(double** mat, double y[], int r, int c)
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
double* bcksb(double** mat, double y[], int r, int c)
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

int min_vec(double *vector, int s)
{
	double t_max = INT_MAX;int i_max = 0;
	for (int i=0; i < s; ++i) {
		if (vector[i] < t_max) {
			t_max = vector[i];
			i_max = i;
		}
	}
	return i_max;
}

void swp_vec(double *a, double *b, int s)
{
	double temp;
	for(int i = 0; i < s; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void det(double** mat, int r, int c)
{
	double div = 1.0;
	for (int k = 0; k < r-1; k++) {
		for (int i = k+1; i < r; i++) {
			if (k != i) {
				for (int j = k+1; j < c; j++) {
					if (k == 0) { div = 1.0; }
					else { div = mat[k-1][k-1]; }
					double temp = 0;
					temp = ((mat[i][j]*mat[k][k])- (mat[i][k]*mat[k][j]));
					mat[i][j] = temp/div;
				}
			}
		}
	}
}

void mmap(double** mat, int r, int c, double v)
{
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			mat[i][j] *= v;
		}
	}
}

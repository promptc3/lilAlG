#include <stdio.h>
#include <stdlib.h>

void lupdec(double **mat, int r, int c);

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	double **mat;
	mat = malloc(n * sizeof *mat);
	for (int i = 0; i < n; ++i)
		mat[i] = malloc(m * sizeof *mat[i]);

	for (int i=0; i < n; ++i) {
		for (int j=0; j < m; ++j)
			scanf("%lf", &mat[i][j]);
	}

	lupdec(mat, n, m);
	return 0;
}

void lupdec(double **mat, int r, int c)
{
	double l_m[r][c], u_m[r][c];
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			l_m[i][j] = 0.0;
			u_m[i][j] = mat[i][j];
		}
	}
	for (int i = 0; i < r; ++i) {
		double temp[c];
		l_m[i][i] = 1;
		for (int k = i+1; k < r; ++k) {
			double pivot = mat[k][i]/mat[i][i];
			for (int j = 0; j < c; ++j) {
				l_m[k][j] = pivot;
				temp[j] = pivot*mat[i][j];
				u_m[k][j] = mat[k][j] - temp[j];
			}
		}
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			printf("%lf ", l_m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			printf("%lf ", u_m[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (i <= j)
				mat[i][j] = u_m[i][j];
			else
				mat[i][j] = l_m[i][j];
		}
	}
}

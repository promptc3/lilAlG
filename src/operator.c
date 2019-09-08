#inlcude "operator.h"
/* Add */
void add(double **mat1, double **mat2, int r, int c)
{
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			mat1[i][j] += mat2[i][j];
		}
	}
}

/* Subtract */
void subt(double **mat1, double **mat2, int r, int c)
{
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			mat1[i][j] -= mat2[i][j];
		}
	}
}

/* Multiply */
void mult(double **mat1, double **mat2, int r, int c)
{
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			mat1[i][j] *= mat2[i][j];
		}
	}
}

void mat_mult(double **mat1, double **mat2, int r, int c)
{
	double ans[r][r];
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			ans[i][j] = 0;
			for (int k = 0; k < r; ++k) {
				ans[i][j] += mat1[i][k]*mat2[k][j];
			}
		}
	}
}

/* Divide */
void div(double **mat1, double **mat2, int r, int c)
{
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			mat1[i][j] /= mat2[i][j];
		}
	}
}

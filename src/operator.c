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

void mat_mult(double **mat1, double **mat2, int n, int m, int p)
{
	double ans[n][p];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ans[i][j] = 0;
			for (int k = 0; k < p; ++k) {
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

double dot(double vec1, double vec2, int size)
{
	double sum = 0.0;
	for (int i = 0; i < size; ++i) {
		sum += vec1[i]*vec2[i];
	}
	return sum;
}

double cross(double vec1, double vec2, int size)
{
	double sum = 0.0;
	if (size == 2) {
		sum = vec1[0]*vec2[1] - vec1[1]*vec2[0];
		return sum;
	}
	else if (size == 3) {
		double ans[3];
		ans[0] = vec1[1]*vec2[2] - vec1[2]*vec2[1];
		ans[1] = vec1[2]*vec2[0] - vec1[0]*vec2[2];
		ans[2] = vec1[0]*vec2[1] - vec1[1]*vec2[0];
		return 0;
	}
	else { fprintf(stderr, "Cross exists for vector upto size 3"); }
}

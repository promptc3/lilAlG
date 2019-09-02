#include <stdio.h>

int main()
{ }

void init_mat(double **matrix, int row, int column)
{
	scanf("%d %d", &row, &column);
	for (int i=0; i < row; ++i) {
		for (int j=0; j < column; ++j)
			scanf("%lf", &matrix[i][j]);
	}
}

void init_vec(double *vector, int size)
{
	scanf("%d", &size);
	for (int i = 0; i < size; ++i)
		scanf("%lf", &vector[i]);
}

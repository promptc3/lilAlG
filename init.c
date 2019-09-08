#include "init.h"

void malloc_mat(double **mat, int r, int c)
{
	mat = malloc(r * sizeof *mat);
	for (int i = 0; i < r; ++i)
		mat[i] = malloc(c * sizeof *mat[i]);
}

void init_zeroes(double **mat, int r, int c)
{
	malloc_mat(mat, r, c);
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) { mat[i][j] = 0.0; }
	}
}

void init_ones(double **mat, int r, int c)
{
	malloc_mat(mat, r, c);
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) { mat[i][j] = 1.0; }
	}
}

void init_idntt(double **mat, int r, int c)
{
	malloc_mat(mat, r, c);
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (i == j) { mat[i][j] = 1.0; }
			else mat[i][j] = 0.0;
		}
	}
}

void init_zeroes_vec(double vec, int size)
{
	for (int i = 0; i < size; ++i)
		vec[i] = 0.0;
}

void init_ones_vec(double vec, int size)
{
	for (int i = 0; i < size; ++i)
		vec[i] = 1.0;
}

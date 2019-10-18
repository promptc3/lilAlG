#include <stdio.h>
#include <stdlib.h>
#include "eztest.h"
#include "../include/operator.h"
#include "../include/init.h"

TEST (Add, AddTwoMatrices)
{
	double **mat, **mat1;
	static int r = 3, c = 3;

	mat = malloc(r * sizeof *mat);
	for (int i = 0; i < r; ++i)
		mat[i] = malloc(c * sizeof *mat[i]);
	mat1 = malloc(r * sizeof *mat1);
	for (int i = 0; i < r; ++i)
		mat1[i] = malloc(c * sizeof *mat1[i]);

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; j++) {
			mat[i][j] = i+1;
			mat1[i][j] = 10-i;
		}
	}

	add(mat, mat1, r, c);

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; j++) {
			ASSERT_EQ(mat[i][j], 11);
		}
	}

	for (int i = 0; i < r; ++i)
		free(mat[i]);

	free(mat);
}

TEST (Subtract, SubtractTwoMatrices)
{
	double **mat, **mat1;
	static int r = 3, c = 3;

	mat = malloc(r * sizeof *mat);
	for (int i = 0; i < r; ++i)
		mat[i] = malloc(c * sizeof *mat[i]);
	mat1 = malloc(r * sizeof *mat1);
	for (int i = 0; i < r; ++i)
		mat1[i] = malloc(c * sizeof *mat1[i]);

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; j++) {
			mat[i][j] = i+1;
			mat1[i][j] = i+1;
		}
	}

	subt(mat, mat1, r, c);

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; j++) {
			ASSERT_EQ(mat[i][j], 0);
		}
	}

	for (int i = 0; i < r; ++i)
		free(mat[i]);

	free(mat);
}

TEST (Multiply, MultiplyElementWiseTwoMatrices)
{
	double **mat, **mat1;
	static int r = 3, c = 3;

	mat = malloc(r * sizeof *mat);
	for (int i = 0; i < r; ++i)
		mat[i] = malloc(c * sizeof *mat[i]);
	mat1 = malloc(r * sizeof *mat1);
	for (int i = 0; i < r; ++i)
		mat1[i] = malloc(c * sizeof *mat1[i]);

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; j++) {
			mat[i][j] = 1;
			mat1[i][j] = i+1;
		}
	}

	mult(mat, mat1, r, c);

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; j++) {
			ASSERT_EQ(mat[i][j], i+1);
		}
	}

	for (int i = 0; i < r; ++i)
		free(mat[i]);

	free(mat);
}

TEST (Matrix_Multiply, MultiplyTwoMatrices)
{
	double **mat, **mat1;
	static int r = 3, c = 3;

	mat = malloc(r * sizeof *mat);
	for (int i = 0; i < r; ++i)
		mat[i] = malloc(c * sizeof *mat[i]);
	mat1 = malloc(r * sizeof *mat1);
	for (int i = 0; i < r; ++i)
		mat1[i] = malloc(c * sizeof *mat1[i]);

	init_idntt(mat, r, c);

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; j++) {
			mat1[i][j] = i+1;
		}
	}

	mat_mult(mat, mat1, r, c, r);

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; j++) {
			ASSERT_EQ(mat[i][j], i+1);
		}
	}

	for (int i = 0; i < r; ++i)
		free(mat[i]);

	free(mat);
}

TEST (Matrix_Divsion, DivideElementWiseTwoMatrices)
{
	double **mat, **mat1;
	static int r = 3, c = 3;

	mat = malloc(r * sizeof *mat);
	for (int i = 0; i < r; ++i)
		mat[i] = malloc(c * sizeof *mat[i]);
	mat1 = malloc(r * sizeof *mat1);
	for (int i = 0; i < r; ++i)
		mat1[i] = malloc(c * sizeof *mat1[i]);

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; j++) {
			mat[i][j] = i+1;
			mat1[i][j] = i+1;
		}
	}

	mat_div(mat, mat1, r, c);

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; j++) {
			ASSERT_EQ(mat[i][j], 1);
		}
	}

	for (int i = 0; i < r; ++i)
		free(mat[i]);

	free(mat);
}

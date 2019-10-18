#include <stdio.h>
#include <stdlib.h>
#include "eztest.h"
#include "../include/init.h"

TEST (InitZeroTest, TestLibraryInitializesZeroMatrices)
{
	double **mat;
	static int r = 3, c = 3;

	mat = malloc(r * sizeof *mat);
	for (int i = 0; i < r; ++i)
		mat[i] = malloc(c * sizeof *mat[i]);
	init_zeroes(mat, r, c);

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; j++) {
			ASSERT_EQ(mat[i][j], 0);
		}
	}

	for (int i = 0; i < r; ++i)
		free(mat[i]);

	free(mat);
}

TEST (InitOnesTest, TestLibraryInitializesOnesMatrices)
{
	double **mat1;
	static int r = 3, c = 3;

	mat1 = malloc(r * sizeof *mat1);
	for (int i = 0; i < r; ++i)
		mat1[i] = malloc(c * sizeof *mat1[i]);
	init_ones(mat1, r, c);

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; j++) {
			ASSERT_EQ(mat1[i][j], 1);
		}
	}

	for (int i = 0; i < r; ++i)
		free(mat1[i]);

	free(mat1);
}

TEST (InitIdentityTest, TestLibraryInitializesIdentityMatrices)
{
	double **mati;
	static int r = 3, c = 3;

	mati = malloc(r * sizeof *mati);
	for (int i = 0; i < r; ++i)
		mati[i] = malloc(c * sizeof *mati[i]);
	init_idntt(mati, r, c);
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; j++) {
			if (i == j) { ASSERT_EQ(mati[i][j], 1); }
			else { ASSERT_EQ(mati[i][j], 0); }
		}
	}

	for (int i = 0; i < r; ++i)
		free(mati[i]);

	free(mati);
}

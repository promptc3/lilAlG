#ifndef _LILALG_FUNCTION_H_
#define _LILALG_FUNCTION_H_

/* transform a matrix to upper triangular */
void upptrngl(double** matrix_A, double *vector_B, int row, int column);

/* perform back substitution on a matrix */
/* returns pointer to the new vector */
double* bcksb(double** matrix_A, double *vector_B, int row, int column);

/* swap elements of two vectors*/
void swp_vec(double *a, double *b, int s);

/* find maximum element in a vector */
/* returns index of that element */
int max_vec(double *vector, int s);

/* find minimum element in a vector */
/* returns index of that element */
int min_vec(double *vector, int s);

/* find determinant using Bareiss Algorithm */
void det(double** matrix, int row, int column);

/* Map the matrix with a number */
void mmap(double** matrix, int row, int column, double val);

/* Cholesky Decomposition */
/* Saves the answer in the input matrix itself */
void cholesky(double** matrix, int n);

#endif

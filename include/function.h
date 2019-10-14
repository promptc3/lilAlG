#ifndef _FUCNTION_H_
#define _FUCNTION_H_
/* initialize a matrix of size row X column */
void r_init_mat(double **matrix, int row, int column);

/* initialize a vector of given size */
void r_init_vec(double *vector, int size);

/* transform a matrix to upper triangular */
void r_upptri(double** matrix_A, double *vector_B, int row, int column);

/* perform back substitution on a matrix */
double* r_bacsub(double** matrix_A, double *vector_B, int row, int column);

/* swap elements of two vectors*/
void swap_vec(double *a, double *b, int s);

/* find max element in a vector */
int max_vec(double *vector, int s);
#endif

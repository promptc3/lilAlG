#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED
#endif
/* init.h : Initialize 
 * Functions to initialize a matrix and vectors */

/* Initialize matrix of zeroes */
void init_zeroes(double **mat, int row, int column);

/* Initialize matrix of ones */
void init_ones(double **mat, int row, int column);

/* Initialize identity matrix */
void init_idntt(double **mat, int row, int column);

/* Initialize vectors of zeroes */
void init_zeroes_vec(double vec, int size);

/* Initialize vectors of ones */
void init_ones_vec(double vec, int size);

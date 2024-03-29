#ifndef _LILALG_INIT_H_
#define _LILALG_INIT_H_
/* init.h : Initialize 
 * Functions to initialize a matrix and vectors */

/* Initialize matrix of zeroes */
void init_zeroes(double **mat, int row, int column);

/* Initialize matrix of ones */
void init_ones(double **mat, int row, int column);

/* Initialize identity matrix */
void init_idntt(double **mat, int row, int column);

/* Initialize vectors of zeroes */
void init_zeroes_vec(double *vec, int size);

/* Initialize vectors of ones */
void init_ones_vec(double *vec, int size);
#endif

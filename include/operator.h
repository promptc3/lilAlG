#ifndef _OPERATOR_H_
#define _OPERATOR_H_
/* Add */
void add(double **mat1, double **mat2, int r, int c);

/* Subtract */
void subt(double **mat1, double **mat2, int r, int c);

/* Element wise multiplication */
void mult(double **mat1, double **mat2, int r, int c);

/* Matrix Multiplication */
void mat_mult(double **mat1, double **mat2, int r, int c, int r1);

/* Element wise Division */
void mat_div(double **mat1, double **mat2, int r, int c);

/* Dot Product */
double dot(double *vec1, double *vec2, int size);

/* Cross Product*/
double cross(double *vec1, double *vec2, int size);
#endif

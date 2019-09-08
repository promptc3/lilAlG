/* initialize a matrix of size row X column */
void r_init_mat(double **matrix, int row, int column);

/* initialize a vector of given size */
void r_init_vec(double *vector, int size);

/* transform a matrix to upper triangular */
void r_upptri(double** matrix_A, double *vector_B, int row, int column);

/* perform back substitution on a matrix */
void r_bacsub(double** matrix_A, double *vector_B, int row, int column);

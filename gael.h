/* Maximum Cpacity of Matrix */
#define MAX 100
/* Create an Upper Triangular Matrix */
void trnglrz(double *matrix[MAX], double output[], int row, int column);
/* Perform Back Substitution*/
void back_subs(double *matrix[MAX], double output[], int row, int column);

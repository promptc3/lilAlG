#include <stdio.h>

int main()
{
	double mat[3][3] = {{3,2,1},{5,4,3},{6,3,4}};
	int r = 3, c = 3;
	double div = 1.0;
	for (int k = 0; k < r-1; k++) {
		for (int i = k+1; i < r; i++) {
			if (k != i) {
				for (int j = k+1; j < c; j++) {
					if (k == 0) { div = 1.0; }
					else { div = mat[k-1][k-1]; }
					double temp = 0;
					temp = ((mat[i][j]*mat[k][k])- (mat[i][k]*mat[k][j]));
					mat[i][j] = temp/div;
				}
			}
		}
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			printf("%lf ", mat[i][j]);
		}
	printf("\n");
	}
}

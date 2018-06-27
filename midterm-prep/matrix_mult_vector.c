#include <stdio.h>
#include <stdlib.h>

#define A(I,J)  *(a+ (I)* n+ (J))

void mult(double *, double [], double [], int , int );

int main(){
	
	double mat[4][3] = {{3,2,1}, {5,6,4}, {8,4,20}, {2,1,2}};
	double vec[3] = {1,2,3};
	double result[4];
	
	mult(&mat[0][0], vec, result, 4, 3);
	
	printf("%lf \t %lf",result[0], result[1]);
	return 0;
}

void mult(double *a, double vector[], double result [], int m, int n)
{
	double sum = 0.0;
	int i,j;
	
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			sum += vector[j] * A(i,j);
		}
		result[i] = sum;
		sum = 0;
	}
	
}

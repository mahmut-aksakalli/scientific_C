#include <stdio.h>
#include <stdlib.h>

#define A(I,J)  *(a+ (I)* n+ (J))
#define B(I,J)  *(b+ (I)* p+ (J))
#define C(I,J)  *(c+ (I)* p+ (J))

void mult(double *, double *, double *, int , int , int);

int main(){
	
	double mat[3][2] = {{3,2}, {4,1}, {7,9}};
	double vec[2][2] = {2,3,-1,9};
	double c[3][2];
	
	mult(&mat[0][0], &vec[0][0], &c[0][0], 3, 2, 2);
	
	printf("%lf \t",c[0][0]);
	
	return 0;
}

void mult(double *a, double *b, double *c, int m, int n, int p)
{
	double sum = 0.0;
	int i,j,k;
	
	for(i=0; i<m; i++){
		for(j=0; j<p; j++){
			sum = 0.0;
			for(k=0; k<n;k++){
				sum += A(i,k) * B(k,j) ;				
			}
			C(i,j) = sum;
		}
		
		
	}
	
}

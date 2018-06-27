#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define A(I,J)  (*(a + (I)*n + (J)) )
#define WORK(I,J) (*(work + (I)*(n+1) + (J)))

void gauss_jordan(double *a,double *b, double *work,int n);

int main(){
	int n = 2;
	int i,j;
	
	double input[2][2] ;  //{0.250,-0.011},{-0.011,0.169}
	double b[2];
	double work_matrix[2][3];
									//## create input and b matrix
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				printf("Enter the element (%d,%d) of a matrix: ",i+1,j+1);
				scanf("%lf",&input[i][j]);
			}
		}
		for(i = 0;i<n;i++){
				printf("Enter the element (%d) of b matrix: ",i+1);
				scanf("%lf",&b[i]);			
		}
	
	gauss_jordan(&input[0][0],&b[0],&work_matrix[0][0],n);
											// ## write down the solution
			printf("solution matrix is:\n");
			for(i=0; i<n; i++){
					printf(" v(%d) : %.2lf \t",i+1,work_matrix[i][2]);
			}
	return 0;
}

void gauss_jordan(double *a,double *b, double *work,int n){
	double m,max,temp;
	int i,j,k,swap;
							// ## set up working matrix
	for(i=0; i<n;i++){
		for(j=0;j<=n;j++){
			if(j<n){
				WORK(i,j) = A(i,j);
			}else{
				WORK(i,j) =  b[i];
			}

		}
	}	
	

	for(i=0; i<n; i++){
						// ## pivoting process		
		max =-1.0;
		for(k=i; k<n;k++){
			if( fabs(WORK(k,i)) > max ){
				max = fabs(WORK(k,i));
				swap = k;
			}
		}
		
		if(swap != i){
			for(k=i; k<=n;k++){
				temp = WORK(i,k);
				WORK(i,k) = WORK(swap,k);
				WORK(swap,k) = temp;
			}
		}
								// ## gauss elimination
		for(j=0;j<n;j++){
			if(j != i){
				m = WORK(j,i)/WORK(i,i);
				for(k=i;k<=n;k++){
					WORK(j,k) -= m*WORK(i,k);
				}
			}
		}
		
	}		
	// ## obtain inverse
	for(i=0;i<n;i++){					
				WORK(i,n) = WORK(i,n)/WORK(i,i);															
	}			
		
}


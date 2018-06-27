#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define A(I,J)  (*(a + (I)*n + (J)) )
#define INVERSE(I,J)  (*(identity + (I)*n + (J)) )
#define WORK(I,J) (*(work + (I)*(n*2) + (J)))

int gauss_jordan(double *a,double *identity, double *work,int n);

main(){
	int n,i,j,singular = 0;
	
	printf("Enter the value N, of an NxN matrix:");		//## N ve input matrix oku
	scanf("%d",&n);
	double input[n][n];
	double inverse[n][n];
	double work_matrix[n][2*n];
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("Enter the element (%d,%d): ",i+1,j+1);
			scanf("%lf",&input[i][j]);
		}
	}
														//## N dimension identity matrix oluþtur
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i == j){
				inverse[i][j] = 1;
			}else{
				inverse[i][j] = 0;
			}
		}
	}

	singular = gauss_jordan(&input[0][0],&inverse[0][0],&work_matrix[0][0],n);
			
	if(singular == 1){
		
		printf("input matrix is singular.. \n");
		
	}else{
			printf("Inverse of the matrix is:\n");
			for(i=0; i<n; i++){
				for(j=n; j<2*n; j++){
					printf("%.2lf \t",work_matrix[i][j]);
				}
				printf("\n");
			}
	}
	
	 return 0;
}

int gauss_jordan(double *a,double *identity, double *work,int n){
	double m,max,temp;
	int i,j,k,swap;
							// ## set up working matrix
	for(i=0; i<n;i++){
		for(j=0;j<2*n;j++){
			if(j<n){
				WORK(i,j) = A(i,j);
			}else{
				WORK(i,j) =  INVERSE(i,j-n);
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
			for(k=i; k<2*n;k++){
				temp = WORK(i,k);
				WORK(i,k) = WORK(swap,k);
				WORK(swap,k) = temp;
			}
		}
		
		for(j=0;j<n;j++){
			if(j != i){
				m = WORK(j,i)/WORK(i,i);
				for(k=i;k<2*n;k++){
					WORK(j,k) -= m*WORK(i,k);
				}
			}
		}
		
	}		
	// ## obtain inverse
	for(i=0;i<n;i++){
		if(WORK(i,i) == 0){ return 1; }
		for(j=n;j<2*n;j++){					
				WORK(i,j) = WORK(i,j)/WORK(i,i);															
		}
	}			
		
}



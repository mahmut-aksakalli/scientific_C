#include <stdio.h>
#include <stdlib.h>
#include <math.h>


main(){
	
	int i,j,m,n;
	float *input_matrix, *output_matrix;
	float sum = 0;
		printf("Enter dimension of Matrix: ");
		scanf("%d %d",&m,&n);
								//		## Create input_dynamic Matrix
		input_matrix = (float *)malloc((m*n) * sizeof(float));
		output_matrix = (float *)malloc((m*n) * sizeof(float));
		float multipy[m][m];
		if((input_matrix == NULL) || (output_matrix == NULL)){
			printf("Error! Memory is not allocated");
			exit(0);
		}
								//		## Read input_Matrix Elements
		for(i=0; i<m; i++){
			for(j=0; j<n; j++){
				printf("Enter element (%d,%d) :",i+1,j+1);
				scanf("%f",(input_matrix + i*n + j));
				
			}
		}	
							// 		## Transpose process
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			*(output_matrix +j*m + i) = *(input_matrix + i*n + j);
		}
	}
								//		## Write Console to Transpose of Matrix (output_matrix + (i*m + j)
	for(i = 0;i<m;i++){
		for(j=0;j<n;j++){
			for (int k=0;k<3;k++){
				sum = sum + (*(output_matrix+ i*m +k)) * (*(input_matrix + k*n + j));
			}
			multipy[i][j] = sum;
			sum = 0;
		}
	}
								//		## Write Console to Transpose of Matrix
		printf("Transpose of input Matrix: \n");						
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				printf("%.1f \t",*(output_matrix + (i*m + j)));
				
			}
			printf("\n");
		}
			
	printf("Multiplication of At A \n");
	for(i = 0;i<m;i++){
		for(j = 0;j<m;j++){
			printf("%f \t",multipy[i][j]);
		}
		printf("\n");
	}		
	
	
	return 0;
}

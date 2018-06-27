#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void transpose();
int norm ();
int is_equalMatrix();

int main(){
	int m,n,i,j,selected,equal_flag;
menu:	
	printf("The functions of program: \n \t 1.Matrix Transpose \n \t 2.Norm of A Vector \n \t 3.Check Equal Matrices \nSelect a process: ");
	scanf("%d",&selected);
	
	if(selected == 1)
	{
										//		## Calculate Transpose
		transpose();
		goto menu;		
	}else if (selected == 2){
										// 		## Calculate Norm of a Vector
		norm();
		goto menu; 				
	}else if(selected == 3){
										//		## Control two Matrices is Equal
		equal_flag = is_equalMatrix();
		if(equal_flag == 1){
			printf("The given matrices are not equal\n");
		}else if(equal_flag == 0){
			printf("The given matrices are equal\n");
		}
		goto menu;
	}
				
	return 0;
}

void transpose(){
	int i,j,m,n;
	float *input_matrix, *output_matrix;
		printf("Enter dimension of Matrix: ");
		scanf("%d %d",&m,&n);
								//		## Create input_dynamic Matrix
		input_matrix = (float *)malloc((m*n) * sizeof(float));
		output_matrix = (float *)malloc((m*n) * sizeof(float));
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
								//		## Write Console to Transpose of Matrix
		printf("Transpose of input Matrix: \n");						
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				printf("%.1f \t",*(output_matrix + (i*m + j)));
				
			}
			printf("\n");
		}
			
		free(input_matrix);
		free(output_matrix);			
}

int norm(){
		int i,vector_size ;
		float *vector;
		float norm;
		
		printf("Enter dimension of vector:");
		scanf("%d",&vector_size);
								//		## Dimension control
		if(vector_size > 10){
			printf("Maximum allowed size of vector is 10 \n");
			return 1;
		}	
								//		## Create vector dynamic array
		vector = (float*)malloc(vector_size * sizeof(float));
		if(vector == NULL) {
			printf("Error! Memory is not allocated");
			exit(0);			
		}
								//		## Read and calculate Norm of Vector		
		for(i=0; i<vector_size;i++){
			printf("Enter %d element of vector :",i+1);
			scanf("%f",(vector+i));
			norm += (*(vector+i)) * (*(vector+i));
		}
		norm = sqrt(norm);	
		printf("The Norm of the Vector : %.1f \n",norm);
		
		free(vector);
		
		return 0;
}

int is_equalMatrix(){
	int m,n,i,j,flag = 0;
	float *first_matrix, *second_matrix;
	
		printf("Enter dimension of Matrices: ");
		scanf("%d %d",&m,&n);	
								//		## Create input_dynamic Matrices
		first_matrix = (float *)malloc((m*n) * sizeof(float));
		second_matrix = (float *)malloc((m*n) * sizeof(float));	
		
		if((first_matrix == NULL) || (second_matrix == NULL)){
			printf("Error! Memory is not allocated");
			exit(0);
		}	
								//		## Read first_Matrix Elements
		for(i=0; i<m; i++){
			for(j=0; j<n; j++){
				printf("Enter element (%d,%d)  of 1 matrix:",i+1,j+1);
				scanf("%f",(first_matrix + i*n + j));
				
			}
		}		
								//		## Read second_Matrix Elements
		for(i=0; i<m; i++){
			for(j=0; j<n; j++){
				printf("Enter element (%d,%d)  of 2 matrix:",i+1,j+1);
				scanf("%f",(second_matrix + i*n + j));
				
			}
		}	
								//		## Control Matrices are equal
		for(i=0; i<m; i++){
			for(j=0; j<n; j++){
				if( (*(first_matrix + i*n + j)) != (*(second_matrix + i*n + j)) ){
					flag = 1;
					break;
				}		
			}
		}	
	return flag;					
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double newton(double (*f)(double), double (*fprime)(double), double , double , double , int *);
double function(double);
double dfunction(double);

int n = 5;
double coeff[50];

int main(){
	int i, flag;
	double parameters[3], root;	
								//		## FILE OPEN 	
	FILE * text;
	text = fopen("2016_HW4_210206034_input.txt","r");
	if(text == NULL){
		printf("ERROR! file could't opened");
		exit(0);
	}
								//		## Read PARAMETERES Aad COEFF From File 		
	fscanf(text, "%lf %lf %lf \n", &parameters[0], &parameters[1], &parameters[2]);
	for(i=0; i <= n; i++){ 
		fscanf(text, "%lf ",&coeff[i]); 
	}	
	fclose(text);
								//		## Call NEWTON function
	root = newton(function, dfunction, parameters[0], parameters[1], parameters[2], &flag);
								//		## Write Root on text file
	FILE *output;
	output = fopen("2016_HW4_210206034_result.txt","w");
	fprintf(output,"%lf ",root);
	fclose(output);			
			
	printf("%lf", root);
	
	return 0;
}
								//		## NEWTON root finding function
double newton(double (*f)(double), double (*fprime)(double), double dmin, double x0, double epsilon, int *error)
{

	double deltax;
cycling:	
	deltax = 2.0 * epsilon;
	*error = 0;	
	while( !(*error) && fabs(deltax) > epsilon){
		if(fabs(fprime(x0)) > dmin ){
			deltax = f(x0)/ fprime(x0);
			
			if(-1*x0 == (x0-deltax)){
				x0 = x0-1;
				printf("cycling\n");
				goto cycling;
				break;
			}else{
				x0 = x0 - deltax;
			}
		}
		else{
			*error = 1;
			break;
		}		
	}
	return (x0);
}

/**								//		## function that is given 
double function(double x)
{
	int i;
	double result = 0;
	for(i=0; i<=n; i++){
		result += coeff[i] * pow(x,i);
	}
	return result;
}

								//		## derivative function that is given 
double dfunction(double x)
{
	int i;
	double result = 0;
	for(i=0; i<=n; i++){
		result += coeff[i] * i * pow(x,i-1);
	}
	return result;
}

*/

double function(double x)
{
    return (1/(1+exp(x)) - 0.5);
    //return(x*x*x-2*x+2);
}
double dfunction (double x)
{
    return (-exp(x)/(1+exp(x))*(1+exp(x)));
    //return(3*x*x-2);
}



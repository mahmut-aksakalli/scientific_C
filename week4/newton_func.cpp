#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double newton(double (*f)(double, double [], int), double (*fprime)(double, double [], int), double , double , double , int *, double [], int);
double function(double, double [], int);
double dfunction(double, double [], int);

double fun(double x,double coeff[], int n)
{
    return (1/(1+exp(x)) - 0.5);
    //return(1.1*x*x*x*x*x+4.5*x*x*x-2.3*x-3.1);
}
double dfun (double x,double coeff[], int n)
{
    return (-exp(x)/(1+exp(x))*(1+exp(x)));
    //return(5.5*x*x*x*x+13.5*x*x-2.3);
}

int main(){
	int i, dimension, flag;
	double parameters[3], root;
								//		## Take the dimension of polynomial on text file	
	printf("Enter dimension of polynomial: ");
	scanf("%d", &dimension);
	double coeff[dimension+1];	
	
	FILE * text;
								//		## FILE OPEN 	
	text = fopen("text.txt","r");
	if(text == NULL){
		printf("ERROR! file could't opened");
		exit(0);
	}
								//		## Read PARAMETERES Aad COEFF From File 		
	fscanf(text, "%lf %lf %lf \n", &parameters[0], &parameters[1], &parameters[2]);
	for(i=0; i <= dimension; i++){ fscanf(text, "%lf ",&coeff[i]); }	
	fclose(text);
								//		## Call NEWTON function
	root = newton(fun, dfun, parameters[0], parameters[1], parameters[2], &flag,coeff,dimension);
			
			printf("%lf",root);

	return 0;
}
								//		## NEWTON root finding function
double newton(double (*f)(double, double [], int), double (*fprime)(double, double [], int), double dmin, double x0, double epsilon, int *error, double coeff[], int n)
{
	double deltax;
	
	deltax = 2.0 * epsilon;
	*error = 0;
cycling:	
	while( !(*error) && fabs(deltax) > epsilon){
		if(fabs(fprime(x0,coeff,n)) > dmin ){
			deltax = f(x0,coeff,n)/ fprime(x0,coeff,n);
			
			if(x0 == -(x0-deltax)){
				x0 = x0 -1;
				goto cycling;
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

								//		## function that is given 
double function(double x, double coeff[], int n)
{
	int i;
	double result = 0;
	for(i=0; i<=n; i++){
		result += coeff[i] * pow(x,i);
	}
	return result;
}

								//		## derivative function that is given 
double dfunction(double x, double coeff[], int n)
{
	int i;
	double result = 0;
	for(i=0; i<=n; i++){
		result += coeff[i] * i * pow(x,i-1);
	}
	return result;
}



#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double newton(double (*f)(double), double (*fprime)(double), double , double , double , int *);
double function(double);
double dfunction(double);
double secand(double (*f)(double), double , double , double , int , int *);

double r0,r,v0,a,t,root,root_second;
double dmin = 10e-30;
double x0 = -1.9;
double epsilon = 0.00001;

int main(){
	
	int flag,found_flag;
	
	printf("Problem formulation is : r = r0 + v0*t + 0.5*a*t2\n");
	printf("Enter r0:");
	scanf("%lf", &r0);
	printf("Enter r:");
	scanf("%lf", &r);
	printf("Enter v0:");
	scanf("%lf", &v0);
	printf("Enter a:");
	scanf("%lf", &a);
	
	root = newton(function, dfunction, dmin, x0, epsilon, &flag);
	root_second = secand(function,  -5, 5,epsilon, 10000, &found_flag);
	
	printf("The newton root %lf\n",root);	
	printf("The secand root %lf\n",root_second);	
	
	return 0;
}
double secand(double (*f)(double), double x1, double x2, double epsilon, int max_tries, int *found_flag)
{
	int count;
	double root2 = x1;
	*found_flag = 1;
	
	while(fabs(x2-x1) >epsilon && count < max_tries){
		root2 = x1 - f(x1)* (x2-x1)/(f(x2)- f(x1));
		x1=x2;
		x2= root2;
		count = count +1;
		}
	
	if(fabs(x2-x1) >epsilon )
		*found_flag = 0;
	
	return (root2); 
}
								//		## NEWTON root finding function
double newton(double (*f)(double), double (*fprime)(double), double dmin, double x0, double epsilon, int *error)
{

	double deltax;
	
	deltax = 2.0 * epsilon;
	*error = 0;	
	while( !(*error) && fabs(deltax) > epsilon){
		if(fabs(fprime(x0)) > dmin ){
			deltax = f(x0)/ fprime(x0);			
			x0 = x0 - deltax;
		}
		else{
			*error = 1;
			break;
		}		
	}
	return (x0);
}

							//		## function that is given
double function(double t)
{
    return ( (r0-r) + v0*t + 0.5*a*pow(t,2));
}
								//		## derivative function that is given 
double dfunction(double t)
{
    return ( v0 + a*t);
}



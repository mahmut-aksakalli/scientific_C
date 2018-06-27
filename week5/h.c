#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.14

double function1(double);
double trapezoidal(double (*f)(double), double, double ,int );
double simpson(    double (*f)(double), double ,double ,int );

int main(){
	int n = 1000000;
	double a,b;
	double t_integral,s_integral;
	
	a= 0;
	b = 50*pow(10,-3);
	t_integral = trapezoidal(function1,a,b,n);
	s_integral = simpson(function1,a,b,n);	
	
	printf("Trapezoidal Method \n -----------------------\ntotal energy dissipated t=50ms is %.10lf\n",t_integral);
	printf("Simpson Method \n -----------------------\ntotal energy dissipated t=50ms is %.10lf",s_integral);
	
		return (0);
}


double trapezoidal(double (*f)(double), double a, double b ,int n){
	
	double answer, h;
	int i;
	
	answer = f(a)/2;
	h= (b-a)/n;
	for(i=1;i<=n;i++){
		answer = answer + f(a+i*h);
	}
	
	answer = answer - f(b)/2;
	return(h*answer);
}

double simpson(double (*f)(double), double a,double b,int n)
{
	double answer, h;
	double x;
	int i;
	answer=f(a);
	h=(b-a)/n;

	for(i=1;i<=n;i++){
		x=a+i*h;
		answer=answer+4*f(x-(h/2))+2*f(x);
	}
	answer=answer-f(b);

	return (h*answer/6);
}

double function1(double x)
{
    return (60*exp(-50*x)/1000);
}

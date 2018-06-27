#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double function1(double);
double function2(double);
double function3(double);
double trapezoidal(double (*f)(double), double, double ,int );

int main(){
	int selected;
	double integral;
	double a = 0;
	double b = 2;
	int n = 10;

	
	printf("1. y = cos(x^2)+ 2x^3 \n2. y = 2/1+x^2 \n3. y = x-3 \n");
	printf("Enter the function number you want to calculate (1, 2 or 3)? \n");
	scanf("%d",&selected);
		
	if(selected == 1){
		integral = trapezoidal(function1, a, b, n);

	}else if (selected ==2){
		integral = trapezoidal(function2, a, b, n);
		
	}else if(selected == 3){
		integral = trapezoidal(function3, a, b, n);
	
	}	
	
	FILE * output;
	output = fopen("output.txt","w");
	fprintf(output, "a\tb\t\Trapezoidal\n");
	fprintf(output, "%.1lf\t%.1lf\t%.3lf\n",a,b,integral);
	
		return 0;
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

double function1(double x)
{
    return (cos(pow(x,2)*3.14/180)+ 2*pow(x,3) );
}
double function2(double x)
{
    return (2/(1 + pow(x,2)));
}
double function3(double x)
{
    return (x-3);
}

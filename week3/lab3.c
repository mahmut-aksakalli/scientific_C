#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double function(double);
int find_interval(double (*f)(double) , double, double ,double ,double [][2],double []);
double bisect(double (*f)(double), double, double, double );
double result[5][2];
double epsilon1 = 0.0001;
double root[10];

int main(){
		int index,i;
		double xstart = -10;
		double xend = 10;
		double stepsize = 0.01;
								//		## Call function
		index = find_interval(function,xstart,xend,stepsize,result,root);
								//		## write intervals if there is		
		if(index != -1){
			for(i=0; i<=index; i++){
					printf("Interval%d --> [%lf, %lf]\n",i+1,result[i][0],result[i][1]);				
			}
			for(i=0; i<=index; i++){
				printf("root [%d] :  %lf \n",i+1,root[i]);
			}
			
		}else{
			printf("Interval not found");
		}
		
		printf("%lf",function(6.0));
		return 0;
}
								//		## function to find root intervals
int find_interval(double (*f)(double), double xstart, double xend, double stepsize,double output[][2],double root[])
{
	int count = -1;
	double xleft;
	double xright;
	
	xleft = xstart;
	xright = xleft + stepsize;
	
	while(xleft < xend)
	{
		if( f(xleft) * f(xright) <= 0.0){
			count++;
			output[count][0] 	= xleft;
			output[count][1] 	= xright;			
			root[count] = bisect(function, xleft, xright, epsilon1);			
		}
		xleft = xright;
		xright = xright + stepsize;
		
		if(xright > xend){	xright = xend;	}
	}
	return count;
}
								//		## function that is given 
double function(double x)
{
	return (pow(x,5) -11.08*pow(x,4) + 25.9605*pow(x,3) + 18.4986*pow(x,2) + 41.2429*x + 63.4687);	
	//return ((x*x*x*x) + ( (7/2)*x*x*x) - (3*x*x) - ((7/2)*x) + 2 );
}
								//		## bisect function	
double bisect(double (*f)(double), double x1, double x2, double epsilon){
	double y;
	
	for(y=(x1+x2)/2.0; fabs(x1-y) >epsilon; y=(x1+x2)/2.0){
		
		if(f(x1)*f(y) <= 0.0 ){
			x2 = y;
		}else{
			x1 = y;
		}
	}
	
	return (y);
}

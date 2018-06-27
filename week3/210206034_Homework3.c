#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double function(double);
int find_interval(double (*f)(double) , double, double ,double ,double [][2]);
double result[5][2];

int main(){
		int index,i;
		double xstart = -10;
		double xend = 10;
		double stepsize = 0.002;
								//		## Call function
		index = find_interval(function,xstart,xend,stepsize,result);
								//		## write intervals if there is		
		if(index != -1){
			for(i=0; i<=index; i++){
					printf("Interval%d --> [%lf, %lf]\n",i+1,result[i][0],result[i][1]);				
			}
		}else{
			printf("Interval not found");
		}
		return 0;
}
								//		## function to find root intervals
int find_interval(double (*f)(double), double xstart, double xend, double stepsize,double output[][2])
{
	int count = -1;
	double xleft;
	double xright;
	
	xleft = xstart;
	xright = xleft + stepsize;
	
	while(xleft < xend)
	{
		if( f(xleft) * f(xright) <= 0){
			count++;
			output[count][0] 	= xleft;
			output[count][1] 	= xright;			
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
	//return (pow(x,5) -11.08*pow(x,4) + 25.9605*pow(x,3) + 18.4986*pow(x,2) + 41.2429*x + 63.4687);
	//return ((x*x*x*x) + ( (7/2)*x*x*x) - (3*x*x) - ((7/2)*x) + 2 );
	return(x*x-x-20);
}

double bisect(){
	
}

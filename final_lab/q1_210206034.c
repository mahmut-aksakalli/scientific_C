#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14


int find_interval(double, double, double ,double ,double,double);
double bisect(double , double , double, double , double , double );
double newton(double , double , double , double , double );

double h, g,theta;
double epsilon1 = 0.00001;

int main()
{
	double stepsize = 0.001;		
	double xstart = -21;
	double xend = 21;	
	double init_point;
	
	printf("height of stone: ");
	scanf("%lf", &h);
	printf("gravitational acc.: ");
	scanf("%lf", &g);
	printf("angle: ");
	scanf("%lf", &theta);
	printf("init_point: ");
	scanf("%lf", &init_point);
		
	find_interval(h,g,theta,xstart,xend,stepsize);
	
	newton(h, g, theta, init_point,epsilon1);

	return 0;
}

int find_interval(double h, double g, double theta, double xstart,double xend, double stepsize)
{
	int count = -1;
	double xleft;
	double xright;
	double root;
	xleft = xstart;
	xright = xleft + stepsize;
	
	while(xleft < xend)
	{
		if( (2*xleft-(h-(pow(xleft,2)*(pow(sin(theta*pi/180),2))/(2*g)))/ (-2*xleft*(pow(sin(theta*pi/180),2))/(2*g)) ) * (2*xright-(h-(pow(xright,2)*(pow(sin(theta*pi/180),2))/(2*g)))/ (-2*xright*(pow(sin(theta*pi/180),2))/(2*g)) ) <= 0){
			count++;
			root = bisect(h, g, theta, xleft,xright,epsilon1);
			printf("Founded interval %d : [%lf, %lf]  -> bisection root : %lf\n",count+1,xleft,xright,root);	
					
		}
		xleft = xright;
		xright = xright + stepsize;
		
		if(xright > xend){	xright = xend;	}
	}
	return count;
}

double bisect(double h, double g, double theta, double x1, double x2, double epsilon){
	double y;
	
	for(y=(x1+x2)/2.0; fabs(x1-y) >epsilon; y=(x1+x2)/2.0){
		
		if((h-(pow(x1,2)*(pow(sin(theta*pi/180),2))/(2*g))) *(h-(pow(x2,2)*(pow(sin(theta*pi/180),2))/(2*g)))  <= 0.0 ){
			x2 = y;
		}else{
			x1 = y;
		}
	}
	
	return (y);
}

double newton(double h, double g, double theta, double x0, double epsilon)
{
	double deltax;
	
	deltax = 2.0 * epsilon;
	while( fabs(deltax) > epsilon){
			
			deltax = (h-(pow(x0,2)*(pow(sin(theta*pi/180),2))/(2*g))) / (-2*x0*(pow(sin(theta*pi/180),2))/(2*g));			
			x0 = x0 - deltax;
			
	}
	printf("Newton founded root : %lf\n", x0);
	return (x0);
}

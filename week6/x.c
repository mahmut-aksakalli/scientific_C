#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.14

double function(double,double);
double euler();
double runge_1();

double r,l,v;
double tlast = 0.001;
double h=0.00001;
double i,vr;
int main()
{
	int select;
	
	printf("a.2nd Order Runge Kutta\nb.Euler's Method\nEnter your choice(1 or 2)\n");
	scanf("%d",&select);
	printf("write R value:");
	scanf("%lf",&r);
	printf("write L value:");
	scanf("%lf",&l);	
	printf("write V value:");
	scanf("%lf",&v);	
	//printf("write i0 value:");
	//scanf("%lf",&i0);
	if(select == 1){
		
		i=runge_1(0.0,0.0000001,function,h,tlast);

		printf("i = %g  ",i);
	}else if(select == 2 ){
		printf("euler selected\n");
		i=euler(0.0,0.0000001,function,h,tlast);

		printf("i = %.10g   ",i);		
	}
	    return 0;
}

double euler(double x0, double y0, double (*g)(double,double), double h, double xlast)
{

    for(;x0<=xlast;x0=x0+h)
    {
        y0=y0+h*g(x0,y0);
    }
    return y0;
}


double runge_1(double x0, double y0, double (*g)(double,double), double h, double xlast)
{
 double temp;
    for(;x0<=xlast;x0=x0+h)
    { temp=h*g(x0,y0);
        y0=y0+h*g(x0+h/2.0,y0+temp/2.0);
    }
    return y0;
}

double function(double x, double y){

	return((v-r*y)/l);
}

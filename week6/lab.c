#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.14

double error();
double dfunc();
double euler();
double runge_1();
double runge_2();

int main()
{
    double x,y;
    int i;


    return 0;
}

double euler(double x0, double y0, double (*g)(double,double), double h, double xlast)
{

    for(;x0<=xlast;x0=x0+h)
    {
        y0=y0+h*g(x0,y0);
    }
    //return y0;
}

double runge_1(double x0, double y0, double (*g)(double,double), double h, double xlast)
{
 double temp;
    for(;x0<=xlast;x0=x0+h)
    { temp=h*g(x0,y0);
        y0=y0+h*g(x0+h/2.0,y0+temp/2.0);
    }
    //return y0;
}
double runge_2(double x0, double y0, double (*g)(double,double), double h, double xlast)
{
 double ta,tb,tc,td;
    for(;x0<=xlast;x0=x0+h)
    {   ta=h*g(x0,y0);
        tb=h*g(x0+h/2.0,y0+ta/2.0);
        tc=h*g(x0+h/2.0,y0+tb/2.0);
        td=h*g(x0+h,y0+tc);
        y0=y0+(ta+2.0*tb+2.0*tc+td)/6.0;
    }

    //return y0;
}

double dfunc(double x, double y)
{
   return (-(y-4)/x);
}

double error(double a, double b)
{
   return (fabs((a-b)/a)*100);
}

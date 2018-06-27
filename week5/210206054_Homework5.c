#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.14
double trapezoidal();
double new_simpson();
double adapt();
double function1();
double function2();
double function3();
double simpson();
int main()
{
    int n=10.0 ,c;
    double a=0.0 ,b=2.0;
    FILE *fp;
fp=fopen("output.txt","w");
    printf("Enter the function number you want to calculate (1, 2 or 3)?\n");
   A:
    printf(" 1. y=cos(x^x) + 2*x^3\n 2. y=2/(1 + x^2)\n 3. y=x-3\n CHOICE= ");
    scanf("%d",&c);
   // fprintf(fp,"a\t\t\t b \t\t\t trapezoidal\n");
    //fprintf(fp,"-\t\t\t - \t\t\t -----------\n");
    if(c==1)
        printf("%lf",adapt(function1,a,b,n,0.1));
        //fprintf(fp,"%.1lf\t\t\t %.1lf \t\t\t %.4lf",a,b,trapezoidal(function1,a,b,n));

    else if(c==2)
        printf("%lf",simpson(function2,a,b,n));
        //fprintf(fp,"%.1lf\t\t\t %.1lf \t\t\t %.4lf",a,b,trapezoidal(function2,a,b,n));

    else if(c==3)
        printf("%lf",simpson(function3,a,b,n));
        //fprintf(fp,"%.1lf\t\t\t %.1lf \t\t\t %.4lf",a,b,trapezoidal(function3,a,b,n));

    else
        {printf("\nPlease choose 1,2 or 3!!!\n\n") ;  goto A  ;}

    printf("\n The result has printed to the output.txt file, check it!\n");

fclose(fp);
return 0;

}

double trapezoidal(double (*f)(double), double a, double b, int n)
{
    double answer, h;
    int i;
    answer=f(a)/2;
    h=(b-a)/n;

    for(i=1;i<=n;i++)
        answer=answer+f(a+i*h);
    answer=answer-f(b)/2;
    return (h*answer);
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

double new_simpson(double(*f)(double), double a, double b, int n0, double tolerance)
    {
        double check=tolerance+1.0;
        double lowval,val;
        lowval=simpson(f,a,b,n0);
        while(check>tolerance)
        {
            n0=2*n0;
            val=simpson(f,a,b,n0);
            check=fabs((val-lowval)/val);
            lowval=val;
        }
    return (val);
    }

double adapt(double(*f)(double), double a, double b, int n, double tolerance)
{
    double check,val;
    val=simpson(f,a,b,n*2);

    check=fabs((simpson(f,a,b,n)-val)/val);
    if(check>tolerance)
        val=adapt(f,a,(a+b)/2.0,n,tolerance)+adapt(f,(a+b)/2.0,b,n,tolerance);
    return (val);
}

double function1(double x)
{
    return (cos(x*x*pi/180) + 2*pow(x,3));
}
double function2(double x)
{
    return (2/(1 + x*x));
}
double function3(double x)
{
    return (x-3);
}

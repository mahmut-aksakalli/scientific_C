#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double function(double,double);
double euler(double, double, double (*g)(double,double),double,double);
double percentage(double,double);
double h1 = 0.01;
double h2 = 0.001;
double h3 = 0.0001;

int main(){	
	double x0 = 0;
	double y0 = -2.5;
	double xlast = 0.50;
	double y01 =  -2.5;
	double y02 =  -2.5;
	double y03 =  -2.5;
	double p1,p2,p3;
	FILE *output;
	output = fopen("output.txt","w");
	
	fprintf(output,"x\texact Value\tEulerResult(h = 0.01)\tEulerResult(h = 0.001)\tEulerResult(h = 0.0001)\n");
	
	for(;x0<=xlast; x0+=0.1){		
		if(x0 !=0)
		fprintf(output,"%.2lf\t%g\t%g\t\t%.5g\t\t\t%g\n",x0,y0,y01,y02,y03);
		
		y0 = euler(x0,y0,function,0.1,x0+0.1);	
		y01 = euler(x0,y01,function,h1,x0+0.1);
		y02 = euler(x0,y02,function,h2,x0+0.1);
		y03 = euler(x0,y03,function,h3,x0+0.1);
	}
	y0  =  -2.5;
	y01 =  -2.5;
	y02 =  -2.5;
	y03 =  -2.5;
	
	fprintf(output,"\n\nx\tPercentage Error(h = 0.01)\tPercentage Error(h = 0.001)\tPercentage Error(h = 0.0001)\n");
	
	for(x0=0.0;x0<=xlast; x0+=0.1){		
		
		p1 = percentage(y0,y01);
		p2 = percentage(y0,y02);
		p3 = percentage(y0,y03);
		
		if(x0 !=0)
		fprintf(output,"%.2lf\t\t%g\t\t\t\t%.5g\t\t\t\t%g\n",x0,p1,p2,p3);
		
		y0 = euler(x0,y0,function,0.10,x0+0.1);	
		y01 = euler(x0,y01,function,h1,x0+0.1);
		y02 = euler(x0,y02,function,h2,x0+0.1);
		y03 = euler(x0,y03,function,h3,x0+0.1);
	}
		
	fclose(output);
	return 0;
}

double euler(double x0, double y0, double (*g)(double,double),double h,double xlast){
	

	for(;x0 <=xlast; x0 = x0 + h){

		y0 = y0 + h* g(x0, y0);
		
		
	}	
	return y0;
}

double percentage(double x ,double y){
	return(fabs((x-y)/x)*100);
}
double function(double x, double y){

	return(exp(cos(x*3.14/180))- y*sin(x*3.14/180));
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void insertion_sort_direct(double [],int);
void shell_sort(double data[], int n);
void selection_sort(double data[], int n);
int main(){
	double x[] = {1.1,2.3,4.0,5.2,1.0,2.2,6.0,3.5};
	double y[] = {1.1,2.3,4.0,5.2,1.0,2.2,6.0,3.5};
	double z[] = {1.1,2.3,4.0,5.2,1.0,2.2,6.0,3.5};
	insertion_sort_direct(x,8);
	int i;
	printf("insertion sort direct\n");
	for(i=0;i<8;i++){
		printf("%.1lf\t",x[i]);
	}
	shell_sort(y,8);
	printf("\nshell sort\n");
	for(i=0;i<8;i++){
		printf("%.1lf\t",y[i]);
	}
	selection_sort(z,8);
	printf("\nselection sort\n");
	for(i=0;i<8;i++){
		printf("%.1lf\t",z[i]);
	}
	
	return 0;
}

void insertion_sort_direct(double data[], int n){
	int position,index;
	double value;
	
	for(position = 1;position<n;position++){
		value = data[position];
		
		for(index=position;index>0 && data[index-1]>value; index--){
			data[index] = data[index-1];}
			data[index] = value;
		
	}
}

void shell_sort(double data[], int n){
	double temp;
	int h,i,j;
	
	for(h=n/2;h>0;h/=2){
		for(i=h;i<n;i++){
			for(j=i-h; j>=0 && data[j]>data[j+h]; j-=h){
				temp = data[j];
				data[j] = data[j+h];
				data[j+h] = temp;
			}
		}
	}
}

void selection_sort(double data[], int n){
	int min,i,j;
	double temp;
	
	for(i=0;i<n;i++){
		min = i;
		
		for(j=i+1;j<n;j++){
			if(data[j]<data[min]){
				min = j;
			}
		}
		
		temp = data[min];
		data[min] = data[i];
		data[i] = temp;		
	}
}

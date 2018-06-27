#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 5

struct data_vec{
	int coord[3];
	double mag;
};

struct stack_vec{
	int count;
	struct data_vec data[5];
};

void init_stack(struct stack_vec *);
int give_count(struct stack_vec);
struct stack_vec push(struct stack_vec,struct  data_vec);
struct stack_vec pop (struct stack_vec);

int main(){	

	int i,k,j=1;
	struct data_vec temp;
	struct stack_vec stack;
	
	init_stack(&stack);
	
	while(give_count(stack)<MAX){

			printf("Enter the x coordinate of %d.data = ",j);
			scanf("%d",&temp.coord[0]);			
			printf("Enter the y coordinate of %d.data = ",j);
			scanf("%d",&temp.coord[1]);
			printf("Enter the z coordinate of %d.data = ",j);
			scanf("%d",&temp.coord[2]);
			temp.mag = sqrt(temp.coord[0]*temp.coord[0]+temp.coord[1]*temp.coord[1]+temp.coord[2]*temp.coord[2]);
			printf("Magnitude of vector is %lf\n",temp.mag);
			stack = push(stack,temp);
			printf("stack after push\n\n");
			
			for(i=0;i<give_count(stack);i++){
				printf("x=%d, y=%d, z=%d and mag= %lf\n",stack.data[i].coord[0],stack.data[i].coord[1],stack.data[i].coord[2],stack.data[i].mag);
			}
			if(give_count(stack) != 1){
				if(stack.data[(stack.count-1)].mag == stack.data[(stack.count-2)].mag){
					stack = pop(stack); 
					printf("Stack after pop \n");
					for(k=0;k<give_count(stack);k++){
							printf("x=%d, y=%d, z=%d and mag= %lf\n",stack.data[k].coord[0],stack.data[k].coord[1],stack.data[k].coord[2],stack.data[k].mag);
					}
				}
			}
			j++;
	}
	return 0;
}

void init_stack(struct stack_vec *stack){
	stack->count = 0;
}

struct stack_vec push(struct stack_vec stack,struct  data_vec temp){
	
	if(give_count(stack) < MAX){
		stack.data[stack.count] = temp;
		stack.count++; 
	}
	return(stack);
}
struct stack_vec pop(struct stack_vec stack){
	
		stack.count--;

	return(stack);
}

int give_count(struct stack_vec stack){
	return (stack.count);
}

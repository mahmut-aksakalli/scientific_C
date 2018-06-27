#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXCOUNT 45

struct students{
	int fstdID;
	char name [50];
	int yearofbirth;
	float gpa;
};
struct stack_s{
	int count;
	struct students data[MAXCOUNT];
};

void init_stack(struct stack_s *s);
int give_count(struct stack_s *s);
struct students pop(struct stack_s *s);
void push(struct stack_s *s, struct students *p);
void students_list(struct stack_s *s);
void stats_on_gpa(struct stack_s *s);
void performance_list(struct stack_s *s);
FILE *text;
int main(){	
	struct stack_s stack;
	struct students temp;
	int select; 

menu:
	init_stack(&stack);
	
	text = fopen("students.txt","r");
	while(fscanf(text,"%d %s %d %f",&temp.fstdID, temp.name, &temp.yearofbirth, &temp.gpa) != EOF ){		
		push(&stack,&temp);
	}
	fclose(text);
	printf("1-student_list() \n2-Stats on gpa() \n3-performance list() \nEnter choosen function : ");
	scanf("%d",&select);
	
	if(select == 1){		
		students_list(&stack);
		goto menu;
	}
	else if(select == 2){
		stats_on_gpa(&stack);
		goto menu;
	}	
	else if(select == 3){
			performance_list(&stack);
			goto menu;
		}	
	return 0;
}

void init_stack(struct stack_s *s){
	s->count = 0;
}

int give_count(struct stack_s *s){
	return(s->count);
}

struct students pop(struct stack_s *s){
	if(s->count > 0){
		s->count--;
		return(s->data[s->count]);
	}else{
		printf("Error - Attempt to pop empty stack\n");
		exit(-1);
	}
}

void push(struct stack_s *s,struct students *p){
	if(s->count < MAXCOUNT){
		s->data[s->count] = *p;
		s->count++;
	}else{
		printf("Error - Attempt to push full stack\n");
		exit(-2);
	}
	
}
								//		## Student List Function
void students_list(struct stack_s *s){
	struct students temp;
	int i = 1;
	while(give_count(s) > 0){
		temp = pop(s);
		printf("%d.) %d\t%s\t%d\t%f\n",i,temp.fstdID,temp.name,temp.yearofbirth,temp.gpa);
		i++;
	}	
}
								//		## Find minimum, maximum, average values
void stats_on_gpa(struct stack_s *s){
	struct students temp;
	float min = 4.0;
	float max = 0;
	float average = 0;
	int maxCount = give_count(s);
	while(give_count(s) > 0){
		temp = pop(s);
		
		if(temp.gpa > max){
			max = temp.gpa;
		}
		
		if(temp.gpa < min){
			min = temp.gpa;
		}
		average += temp.gpa;
		
	}
	average /=maxCount;
	printf("Minimum GPA of students: %f \nAverage GPA of students: %f\nMaximum GPA of students: %f\n",min,average,max);
}
								//		## Performans List
void performance_list(struct stack_s *s){
	struct students temp;
	struct stack_s stemp;
	float min = 4.0;
	float max = 0;
	float average = 0;
	int maxCount = give_count(s);
	int i = 1;
	int high,low;
								//		## to evaluate min,max,average
	while(give_count(s) > 0){
		temp = pop(s);
		
		if(temp.gpa > max){
			max = temp.gpa;
			high = temp.fstdID;
		}
		
		if(temp.gpa < min){
			min = temp.gpa;
			low = temp.fstdID;
		}
		average += temp.gpa;
		
	}
	average /=maxCount;
								//		## create stack again to write performances
	text = fopen("students.txt","r");
	while(fscanf(text,"%d %s %d %f",&temp.fstdID, temp.name, &temp.yearofbirth, &temp.gpa) != EOF ){		
		push(&stemp,&temp);
	}
	fclose(text);
								//		## write performances	
	while(give_count(&stemp) > 0){
		temp = pop(&stemp);		
		if(temp.fstdID == high){
			printf("%d.) %s -> %s\n",i,temp.name,"Best");
		}else if(temp.fstdID == low){
			printf("%d.) %s -> %s\n",i,temp.name,"Worst");
		}else{
			if(temp.gpa>average){			
				printf("%d.) %s -> %s\n",i,temp.name,"Successful");
			}else{
				printf("%d.) %s -> %s\n",i,temp.name,"Failed");
			}
		}
		i++;
	}
}


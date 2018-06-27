#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define MAXCOUNT 50
struct students{
	char x;
};
struct stack_s{
	int count;
	struct students data[MAXCOUNT];
};

void init_stack(struct stack_s *s);
int give_count(struct stack_s *s);
struct students pop(struct stack_s *s);
void push(struct stack_s *s, struct students *p);

int main(){	
	struct stack_s stack;
	struct students temp;
	char input[60];
	char palind[60];
	int len;
	int i=0,j=0;
	
	printf("Write string:");
	scanf("%s",input);
	len = strlen(input);
	while(i<len){
		if(isspace(input[i]) || ispunct (input[i])){
			j=i;
			while(j<len){
				input[j] = input[j+1];
				j++;
			}
			len--;
		}
		input[i] = tolower(input[i]);
		i++;
	}
	
	init_stack(&stack);
	for(i=0;i<len;i++){
		temp.x = input[i];
		push(&stack,&temp);
	}
	
	for(i=0;i<len;i++){
		temp=pop(&stack);
		palind[i] = temp.x; 
	}
	int flag = 1;
	for(i=0;i<len;i++){
			if(input[i]!=palind[i]){
				flag = 0;
			}
			
	}
	
	if(flag == 1){
		printf("palindrome");
	}else{
		printf("not palindrome");
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

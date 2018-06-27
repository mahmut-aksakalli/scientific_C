#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct list_node{
	int number;
	struct list_node *next;
};

typedef struct list_node * List;

List init_list();
int empty_list(List);
List add_to_front(List, int  ,int *);
void destroy_list(List);
List delete_from_list(List,int, int *);
int search_list(List , int );
void show_names(List);
int fibonacci(int );

int main(){	
	int i,tempNumber,flag,count;
	List odd,even;
	
	odd =  init_list();
	even = init_list();
	
	printf("Write fibonacci element number:");
	scanf("%d",&count);
	for(i=2;i<=count;i++){
		tempNumber = fibonacci(i);

		if((tempNumber % 2) == 1){
			
				odd = add_to_front(odd,tempNumber,&flag);			
		}
		else{			
				even = add_to_front(even,tempNumber,&flag);
		}
	}
	
	printf("Even List:");
	show_names(even);
	printf("\nOdd List:");
	show_names(odd);	
	
	destroy_list(even);
	destroy_list(odd);
	return 0;
}
								//		## init a list
List init_list(){
	return(NULL);
}

int empty_list(List slist){
	if(slist == NULL){
		return 1;
	}
	return(0);
}
								//		## insert node on the front of list
List add_to_front(List slist, int number ,int *flag){
	List node;
	
	node = malloc(sizeof(struct list_node));
	if(node == NULL){
		*flag = 0;
	}
	else{
		node->number = number;
		node->next = slist;
		slist = node;
		*flag = 1;
	}
	return(slist);
}
								//		## destroy a list
void destroy_list(List slist){
	if(!empty_list(slist)){
		destroy_list(slist->next);
		free(slist);
	}
}
								//		## Delete a node from list
List delete_from_list(List slist, int number,int *flag){
	List temp;
	List prev;
	
	*flag = 0;
	temp = slist;
								//		## search item	
	while(!empty_list(temp) && !(*flag)){
		if(temp->number == number){
			*flag = 1;
		}
		else{
			prev = temp;
			temp = temp->next;
		}
	}
								//		## if item was found	
	if(*flag){
		if(temp == slist){		//		## if it's 1st node on list
			slist = slist->next;
		}
		else{
			prev->next = temp->next;
		}
		free(temp);
	}
	
	return(slist);
}
								//		## Search a node from list
int search_list(List slist, int number){
	List temp;
	List prev;
	
	int flag = 0;
	temp = slist;
								//		## search item	
	while(!empty_list(temp) && !(flag)){
		if(temp->number == number){
			flag = 1;
		}
		else{
			prev = temp;
			temp = temp->next;
		}
	}
	return(flag);
}
								//		## show items
void show_names(List slist){
	if(!empty_list(slist)){
		show_names(slist->next);
		printf("%d ",slist->number);
	}
}

int fibonacci( int eleman_no )
{
	if( eleman_no > 1 ) {
		return fibonacci( eleman_no - 1 ) + fibonacci( eleman_no - 2 ) ;
	}
	else if( eleman_no == 1 )
		return 1;
	else if(eleman_no ==0)
		return 0;
} 

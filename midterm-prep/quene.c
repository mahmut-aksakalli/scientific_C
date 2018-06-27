#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct list_node{
	int exp;
	struct list_node *next;
};

typedef struct list_node * List;

struct queue_struct{
	List front;
	List rear;	
};

typedef struct queue_struct * Queue;
List init_list(void);
List add_to_front(List,int);
List delete_from_list(List);
Queue make_queue(void);
void add_to_queue(Queue,int);
void remove_from_queue(Queue);
int empty_list(List);

int main(){
	
	
	
	return 0;
}

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
List add_to_front(List slist, int x){
	List node;
	
	node = malloc(sizeof(struct list_node));
	node->exp = x;
	node->next = slist;
	slist = node;
	
	return(slist);
}

List delete_from_list(List slist){
	List temp;
	
	temp = slist;
	slist = slist->next;
	
	free(temp);
	
	return(slist);
}

Queue make_queue(void){
	Queue q;
	
	q = malloc(sizeof(struct queue_struct));
	
	if(q != NULL){
		q->front = NULL;
		q->rear  = NULL;
	}
	
	return(q);
}

void add_to_queue(Queue q, int x){
	List node;
	
	node = init_list();
	node = add_to_front(node,x);
	
	if(empty_list(q->rear)){
		q->front = node;
		q->rear  = node;
	}else{
		q->rear->next = node;
		q->rear = node;
	}
}

void remove_from_queue(Queue q){
	
	if(!empty_list(q->front)){
		q->front = delete_from_list(q->front);	
	}
	
	if(empty_list(q->front)){
		q->rear = NULL;
	}
}

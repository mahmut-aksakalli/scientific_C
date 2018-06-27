#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct list_node{
	int coeff;
	int exp;
	struct list_node *next;
};

typedef struct list_node * List;

List init_list();
int empty_list(List);
List add_to_front(List, int  ,int ,int *);
void destroy_list(List);
void show_names(List);


int main(){
	int n,i,flag;
	
	printf("number of parameters ");
	scanf("%d",&n);
	int poly[n][2];
	printf("Write polynomials\n");
	for(i=0;i<n;i++){
		scanf("%d %d",&poly[i][0],&poly[i][1]);
	}
	
	List pol;

	pol = init_list();
	for(i=0;i<n;i++){
		pol = add_to_front(pol,poly[i][0],poly[i][1],&flag);
	}	
	
	show_names(pol);
	
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

void show_names(List slist){
	if(!empty_list(slist)){

		show_names(slist->next);
		printf("(%dx^%d+)",slist->coeff,slist->exp);
		
	}
}

								//		## insert node on the front of list
List add_to_front(List slist, int coeff ,int exp,int *flag){
	List node;
	
	node = malloc(sizeof(struct list_node));
	if(node == NULL){
		*flag = 0;
	}
	else{
		node->coeff = coeff;
		node->exp = exp;
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

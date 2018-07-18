#include <stdio.h>
#include <stdlib.h>

struct list_t{
	int value;
	struct list_t *next;
};

typedef struct list_t list_t;

// Protos

list_t *
list_cons(int value, list_t *list);

void
list_print(list_t *list);

void
list_free(list_t *head);

// Functions

list_t *
list_cons(int value, list_t *list){
	list_t *new;
	new=malloc(sizeof(list_t));
	if(new){
		new->value=value;
		new->next=list;
	}
	return new;
}

void
list_print(list_t *list){
	while(list){
		printf("%i ", list->value);
		list=list->next;
	}
	printf("\n");
}

void
list_free(list_t *head){
	list_t *tail;
	while(head){
		tail=head->next;
		free(head);
		head=tail;
	}
}
// Main

int
main(int argv, char **argc){

	list_t *a;
	
	a=NULL;

	a=list_cons(1, a);
	a=list_cons(2, a);
	a=list_cons(3, a);

	list_print(a);
	list_free(a);

	return 0;
}

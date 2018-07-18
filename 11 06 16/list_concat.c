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

list_t *
list_last(list_t *head);

list_t *
list_concat(list_t *list1, list_t *list2);

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

list_t *
list_last(list_t *head){
	list_t *last;

	last=NULL;
	while(head){
		last=head;
		head=head->next;
	}
	return last;
}

list_t *
list_concat(list_t *list1, list_t *list2){
	list_t *last;
	last=list_last(list1);
	
	if(last){
		last->next=list2;
	}else{
		list1=list2;
	}
	return list1;
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

	list_t *a, *b, *c, *d;
	
	a=NULL;
	a=list_cons(1, a);
	a=list_cons(2, a);
	a=list_cons(3, a);

	b=NULL;
	b=list_cons(4, b);
	b=list_cons(5, b);
	b=list_cons(6, b);

	printf("Lista a:");
	list_print(a);

	printf("Lista b:");
	list_print(b);

	d=NULL;
	d=list_last(a);
	printf("Ultimo elemento di a:");
	list_print(d);

	c=NULL;
	c=list_concat(a, b);
	printf("Lista concatenata c:");
	list_print(c);

	list_free(a);
	list_free(b);
	list_free(c);
	list_free(d);
	
	return 0;
}

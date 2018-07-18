#include <stdio.h>
#include <stdlib.h>

// Types
struct list_t{
	int value;
	struct list_t *next;
};
typedef struct list_t list_t;

// Protos
list_t *
list_cons(int value, list_t *list);
void
list_free(list_t *head);
list_t *
list_concat(list_t *list1, list_t *list2);
list_t *
list_last(list_t *head);
void
list_print(list_t *list);
list_t *
list_print_to_file(list_t *list, FILE *filename);
list_t *
list_read_from_file(char *filename);


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
list_free(list_t *head){
	list_t *tail;

	while(head){
		tail=head->next;
		free(head);
		head=tail;
	}
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

void
list_print(list_t *list){
	while(list){
		printf("%i ", list->value);
		list=list->next;
	}
	printf("\n");
}

list_t *
list_print_to_file(list_t *list, FILE *file){
	while(list){
		fprintf(file, "%i", list->value);
		list=list->next;
	}
	fprintf(file, "\n");
}

list_t *
list_read_from_file(char *filename){
	FILE *f; //puntatore al file da leggere
	list_t *l;
	int value, retval, value_read;	

	l=NULL;
	f=fopen(filename, "r"); // apre il file "fileneame" e fa l'operazione di lettura
	if(f){// controlla se effettivamente il file contenga qualcosa
		do{	
			retval=fscanf(f, "%i", &value);
			value_read=(retval==1);
			printf("%i: value: %i\n", retval, value);	
			if(value_read){
				l=list_cons(value, l); 	
			}
		}while(value_read);
		fclose(f);
	}else{
		printf("Could not open file: %s\n", filename);
	}
	return l;
}
	

// Main 
int
main(int argv, char **argc){
	list_t *a, *b, *c, *d, *user_data;
	FILE *file;

	a=NULL;
	a=list_cons(1, a);
	a=list_cons(2, a);
	a=list_cons(3, a);
	printf("Lista A:");
	list_print(a);

	b=NULL;
	b=list_cons(4, b);
	b=list_cons(5, b);
	b=list_cons(6, b);
	printf("Lista B:");
	list_print(b);

	c=NULL;
	c=list_last(a);
	printf("Ultimo elemento delle lista A:");
	list_print(c);
	
	d=NULL;
	d=list_concat(a, b);
	printf("Lista Concatenata:");
	list_print(d);

	printf("user data:\n");
	user_data=list_read_from_file("data");
	list_print(user_data);

	file=fopen("data", "w");
	if(file){
		list_print_to_file(user_data, file);
		fclose(file);
	}	

	return 0;
}



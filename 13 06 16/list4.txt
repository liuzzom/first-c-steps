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
list_last(list_t *head);
list_t *
list_concat(list_t *list1, list_t *list2);
list_t *
list_concat_cache(list_t *list1, list_t *list2, list_t *last);
list_t *
read_from_file(char *filename){
list_t *
list_search_previous(list_t *list, int value);
list_t *
list_insert(list_t *list, int value);
void
list_print(list_t *list);
void
list_print_to_file(list_t *list, FILE *file);

//Funtions

list_t * // Inserimento in testa nella lista
list_cons(int value, list_t *list){
	list_t *new; // puntatore al nuovo elemento della lista

	new=malloc(sizeof(list_t)); //chiede uno spazio in memoria grande quando list_t (12 byte)
	if(new){ // verifica se viene eseguita correttamente l'allocazione in memoria
		new->value=value;
		new->next=list;
	}
	return new; // ritorna il puntatore all'elemento appena creato
}

void // dealloca la lista
list_free(list_t *head){ 
	list_t *tail; // coda della lista (tutti gli elementi esclusa la testa)
	while(head){ // verifica che la testa non punti a NULL(lista vuota)
		tail=head->next; //definizione di coda
		free(head); // libera la testa
		head=tail; // sposta il puntatore alla coda a quella coda
	}
}

list_t * // concatena due liste
list_concat(list_t *list1, list_t *list2){
	list_t *last; // puntatore all'ultimo elemento di una lista
	last=list_last(list1); // assegna l'ultimo elemento della lista 1

	if(last){ //verifica che last non punti a NULL
		last->next=list2; //l'elemento successivo all'ultimo della lista1 viene collegata alla lista2
	}else{ // se last=NULL, quindi se la lista1 è vuota
		list1=list2; // si va direttamante alla lista2
	}

	return list1; //ritorna il puntatore alla lista1, che ora è  stata concatenata
}

list_t * //cerca l'ultimo elemento di una lista
list_last(list_t *head){
	list_t *last; //ultimo elemento della lista
	last=NULL; // si iniziallizza a NULL

	while(head){ //verifica che la testa non sia NULL
		last=head; //l'elemento in testa viene provvisoriamente considerato come l'utimo
		head=head->next;
	}
	return last;
}

void // stampa la lista
list_print(list_t *list){

	while(list){ //verifica se la lista non sia NULL
		printf("%i ", list->value);// stampa il valore dell'elemento della lista
		list=list->next; // va all'elemento successivo della lista
	}
	printf("\n");
}

list_t * //cerca l'elemento precedente ad un elemento stabilito
list_search_previous(list_t *list, int value){
	list_t *previous; // elemento precedente

	previous=NULL; // si inizializza a NULL
	while(list){ // si vede se la lista non sia NULL
		if(list->value>=value){ // controlla se il valore stabilito sia maggiore o uguale a quello attuale, quindi abbiamo finito la ricerca
			return previous;
		}
		previous=list;
		list=list->next;// si passa all'elemento successivo della lista e si continua quindi la ricerca
	}
	return previous;
}

list_t * //inserisce un valore in maniera ordinata
list_insert(list_t *list, int value){
	list_t *previous, *new; // puntatori all'elemento precedente e a quello che verrà inserito

	new=list_cons(value, NULL); //inserimento in testa del valore a una lista NULL 
	if(!new){
		return list;
	}
	previous=list_search_previous(list, value); //si cerca l'elemento immediamente precedente a quello da inserire 

	if(previous){ // verifica che sia tornato l'elemento precedente a quello da inserire
		new->next=previous->next;
		previous->next=new;
	}else{
		new->next=list;
		list=new;
	}	

	return list;
} 

list_t * // apre un file e ne legge i valori memorizzati
read_from_file(char *filename){
	FILE *f; // puntatore al file appena letto
	list_t *l, *new, *last;
	int value, retval, value_read;	

	l=NULL;
	f=fopen(filename, "r");
	if(f){
		last=NULL;
		do{	
			retval=fscanf(f, "%i", &value);
			value_read=(retval==1);
			printf("%i: value: %i\n", retval, value);	
			if(value_read){
				new=list_cons(value, NULL);
				l=list_concat_cache(l, new, last);
				last=new; 	
			}
		}while(value_read);
		fclose(f);
	}else{
		printf("Could not open file: %s\n", filename);
	}
	return l;
}

void
list_print_to_file(list_t *list, FILE *file){
	
	while(list){
		fprintf(file, "%i ", list->value);
		list=list->next;
	}
	fprintf(file, "\n");
}

// Main

int
main(int argc, char **argv){
	list_t *a, *b, *c, *d, *user_data, *previous;
	FILE *file;
 
	a=NULL;
	a=list_cons(1, a);
	a=list_cons(2, a);
	a=list_cons(3, a);
	b=NULL;
	b=list_cons(5, b);
	b=list_cons(6, b);
	b=list_cons(7, b);
	
	printf("list a:\n");
	list_print(a);

	printf("user data:\n");
	user_data=read_from_file("data");
	list_print(user_data);

	previous=list_search_previous(user_data, 25);
	list_print(previous);

	user_data=list_insert(user_data, 25);
	list_print(user_data);
	user_data=list_insert(user_data, 70);
	list_print(user_data);
	user_data=list_insert(user_data, 7);
	list_print(user_data);
	
	printf("list b:\n");
	list_print(b);

	d=list_last(a); 
	if(d){
		printf("last value of list a: %i\n", d->value);
	}
	
	c=list_concat(a,b);
	a=NULL;
	b=NULL;

	file=fopen("data", "w");
	if(file){
		list_print_to_file(user_data, file);
		fclose(file);
	}	

	printf("list c:\n");
	list_print(c);

	list_free(c);

	return 0;
}


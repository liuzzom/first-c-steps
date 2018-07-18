#include <stdio.h>
#include <stdlib.h>

#define PERSON_FIELD_LENGHT 30

// Definizioni //

struct person_t{
	char nome[PERSON_FIELD_LENGHT];
	char cognome[PERSON_FIELD_LENGHT];
};
typedef struct person_t person_t;
// Prototipi //

person_t *
people_alloc(size_t number_of_people);

void
people_dealloc(person_t * people);

void
people_input(person_t * people, size_t number_of_people);

void
people_print(person_t * people, size_t number_of_people);

// Funzioni //

person_t *
people_alloc(size_t number_of_people){
	return calloc( sizeof(person_t), number_of_people);
}

void
people_dealloc(person_t * people){
	free(people);
}

void 
people_input(person_t * people, size_t number_of_people){
	size_t i;
	
	for(i=0;i<number_of_people; i++){
		printf("Inserire Nome:");
		scanf("%s", people[i].nome);
		printf("Inserire Cognome:");
		scanf("%s", people[i].cognome);
	}
}

void
people_print(person_t * people, size_t number_of_people){
	size_t i;
	
	for(i=0; i<number_of_people; i++){
		printf("%zu:\t Nome:%s\t Cognome:%s\n", (i+1), people[i].nome, people[i].cognome);
	}
}  


// Main //

int
main(int argc, char **argv){
	person_t *people=NULL;
	size_t number_of_people, i;
	
	printf("Insert number of people:");
	scanf("%i", &number_of_people);

	people=people_alloc(number_of_people);
	if(people){
		people_input(people, number_of_people);
		people_print(people, number_of_people);
		people_dealloc(people);
	}
		
return 0;
}

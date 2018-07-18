#include <stdio.h>
#include <stdlib.h>

#define PERSON_FIELD_SIZE 30
#define PERSON_FIELD_STRING_SPEC "29"

struct person_t {
	char name[PERSON_FIELD_SIZE];
	char surname[PERSON_FIELD_SIZE];
	unsigned age;
};

typedef struct person_t person_t;

/* Protos
 *
 */

person_t *
people_alloc(size_t number_of_people);
void
people_dealloc(person_t *people);
void
people_input(person_t *people, size_t number_of_people);
void
people_print(person_t *people, size_t number_of_people);

/* Functions
 *
 */

person_t *
people_alloc(size_t number_of_people){
	return calloc(sizeof(person_t), number_of_people);
}

void
people_dealloc(person_t *people){
	free(people);
}

void
people_input(person_t *people, size_t number_of_people){
	size_t i;

	for(i=0; i<number_of_people; i++){
		printf("\nInsert # %zu name: ", i);
		scanf("%" PERSON_FIELD_STRING_SPEC "s", people[i].name);
		printf("surname: ");
		scanf("%" PERSON_FIELD_STRING_SPEC "s", people[i].surname);
		printf("age: ");
		scanf("%u", &people[i].age);
	}
}

void
people_print(person_t *people, size_t number_of_people){
	size_t i;

	printf("\n\nName\t\t\tSurname\t\t\tAge\n"); 
	for(i=0;i<80; i++){
		printf("-");
	}
	printf("\n");
	for(i=0; i<number_of_people; i++){
		printf("%s\t\t\t%s\t\t\t%u\n", people[i].name, people[i].surname, people[i].age); 
	}
}

int
main(int argc, char **argv){
	person_t *people=NULL;
	char s[PERSON_FIELD_SIZE];
	size_t number_of_people;

	printf("Insert number of people: ");
	scanf("%zu", &number_of_people);

	people=people_alloc(number_of_people);
	if(people){
		people_input(people, number_of_people);
		people_print(people, number_of_people);
		people_dealloc(people);
	}
	return 0;
}

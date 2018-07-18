#include <stdio.h>
#include <stdlib.h>
#define LENGHT 30

// Types
struct rubrica_t{
	char nome[LENGHT];
	char cognome[LENGHT];
	unsigned eta;
};

typedef struct rubrica_t rubrica_t;

// Protos
rubrica_t *
rubrica_alloc(size_t number_of_people);
void
rubrica_dealloc(rubrica_t *rubrica);
void
rubrica_input(rubrica_t *rubrica, size_t number_of_people);
void
rubrica_print(rubrica_t *rubrica, size_t number_of_people);

//Functions

rubrica_t *
rubrica_alloc(size_t number_of_people){
	return calloc(sizeof(rubrica_t), number_of_people);
}

void
rubrica_dealloc(rubrica_t *rubrica){
	free(rubrica);
}

void
rubrica_input(rubrica_t *rubrica, size_t number_of_people){
	size_t i;
	for(i=0; i<number_of_people; i++){
		printf("Inserire Nome Contatto:");
		scanf("%s", rubrica[i].nome);
		printf("Inserire Cognome Contatto:");
		scanf("%s", rubrica[i].cognome);
		printf("Inserire età Contatto:");
		scanf("%u", &rubrica[i].eta);
	}
}

void
rubrica_print(rubrica_t *rubrica, size_t number_of_people){
	size_t i;
	for(i=0; i<number_of_people; i++){
		printf("Nome:%s\tCognome:%s\t,Età:%u\n", rubrica[i].nome, rubrica[i].cognome, rubrica[i].eta);
	}
}
	
// Main 
int
main(int argv, char **argc){
	rubrica_t *rubrica;
	rubrica=NULL;
	char s[LENGHT];
	size_t number_of_people;
	printf("Quante persone inserire?");
	scanf("%zu", &number_of_people);

	rubrica=rubrica_alloc(number_of_people);
	if(rubrica){
		rubrica_input(rubrica, number_of_people);
		rubrica_print(rubrica, number_of_people);
		rubrica_dealloc(rubrica);
	}
	return 0;
}
		

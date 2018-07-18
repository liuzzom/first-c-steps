#include <stdio.h>
#include <stdlib.h>
#define MAX 30
#define STORAGE 100

// Types

struct rubrica_t{
	char nome[MAX];
	char cognome[MAX];
	unsigned long numero;
	struct rubrica_t *next;
};
typedef struct rubrica_t rubrica_t;

// Protos 

void
print_menu();
rubrica_t *
rubrica_input(rubrica_t *rubrica);
void
rubrica_free(rubrica_t *head);
void
rubrica_print(rubrica_t *head);

// Functions

void
print_menu(){
	printf("1)Inserisci Contatto\n2)Visualizza Contatti\n3)Elimina Tutti i Contatti\n4)Verifica se ci stanno Tracciando\n");
}

rubrica_t *
rubrica_input(rubrica_t *rubrica){
	rubrica_t *new;

	new=NULL;
	new=malloc(sizeof(rubrica_t));
	if(new){
		printf("Inserire Nome:");
		scanf("%29s", new->nome);
		printf("Inserire Cognome:");
		scanf("%29s", new->cognome);
		printf("Inserire Numero:");
		scanf("%lu", &new->numero);

		new->next=rubrica;
	}else{
		printf("Spazio non disponibile\n");
	}
	return new;

}

void
rubrica_print(rubrica_t *head){
	rubrica_t *tail;
	tail=NULL;
	if(!head){
		printf("Ndo stanno i Contatti, mica li vedo\n");
	}
	while(head){
		tail=head->next;
		printf("Nome:%s\tCognome:%s\tNumero:%lu\n", head->nome, head->cognome, head->numero);
		head=tail;
	}
} 

void
rubrica_free(rubrica_t *head){
	rubrica_t *tail;

		while(head){
			tail=head->next;
			free(head);
			head=tail;
		}
}

// Main

int
main(int argv, char **argc){
	rubrica_t *rubrica;
	char choose;
	size_t counter;
	counter=0;
	rubrica=NULL;
	printf("Benvenuto!\nPremere un comando valido del menu per continuare:\n");
	
	do{
		print_menu();
		scanf("%c", &choose);

		switch(choose){
			case '1':{
				printf("Inserisci Contatto\n");
				counter++;
				if(counter<STORAGE){
					rubrica=rubrica_input(rubrica);
				}else{
					printf("Massimo numero di contatti raggiunto\n");
				}
				break;
				}
			case '2':{
				printf("Visualizza Contatti\n");
				rubrica_print(rubrica);
				break;
				}
			case '3':{
				printf("Elimina Tutti i Contatti\n");
				rubrica_free(rubrica);
				break;
				}
		}
	}while(choose!='4');

	printf("\aCi Stanno Tracciando....STACCAH STACCAH!!!\n");
	rubrica_free(rubrica);
	return 0;
}
	

#include <stdio.h>
#include <stdlib.h>
#define LENGHT 30

// Types 
struct rubrica_t{
	char nome[LENGHT];
	char cognome[LENGHT];
	unsigned long numero;
	struct rubrica_t *next;
};
typedef struct rubrica_t rubrica_t;

// Protos
void
print_menu();
rubrica_t *
rubrica_alloc(rubrica_t *rubrica);
void
rubrica_dealloc(rubrica_t *rubrica);
void
rubrica_print(rubrica_t *head);
// Functions
void
print_menu(){
	printf("1)Aggiungi Contatto.\n2)Visualizza Contatti.\n3)Elimina Contatti\n4)Esci\n");
}

rubrica_t *
rubrica_alloc(rubrica_t *rubrica){
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
	while(head){
		tail=head->next;
		printf("Nome:%s\tCognome:%s\tNumero:%lu\n", head->nome, head->cognome, head->numero);
		head=tail;
	}
}

void
rubrica_dealloc(rubrica_t *rubrica){
	rubrica_t *next;

	while(rubrica){
		next=rubrica->next;
		free(rubrica);
		rubrica=next;
	}
}

// Main
int
main(int argv, char **argc){
	rubrica_t *rubrica;	
	char choose;

	printf("Benvenuto.\nScegliere l'operazione da fare.\n");
	rubrica=NULL;

	do{
		print_menu();
		scanf("%c", &choose);
		switch(choose){
			case '1':{
				printf("Aggiungi contatto\n");
				rubrica=rubrica_alloc(rubrica);
				break;
			}
			case '2':{
				printf("Visualizza contatti\n");
				rubrica_print(rubrica);
				break;
			}
			case '3':{
				printf("Elimina tutto\n");
				rubrica_dealloc(rubrica);
				rubrica=NULL;
				break;
			}
		}
	}while(choose!='4');
	printf("Arrivederci\n");
	rubrica_dealloc(rubrica);
	return 0;
}

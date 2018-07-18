#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 30

typedef struct rubrica_t {
	char nome[max];
	char cognome[max];
	unsigned int telefono;
	struct rubrica_t *next;
} rubrica_t ;

rubrica_t *
rubrica_cons(char nome[], char cognome[], long int telefono, rubrica_t *list, int n){
	rubrica_t *new;
	
	new=malloc(sizeof(rubrica_t));
	if(new){
		printf("Inserire Nome: ");
		scanf("%29s", new[n-1].nome);
		printf("Inserire Cognome: ");
		scanf("%29s", new[n-1].cognome);
		printf("Inserire Numero di telefono: ");
		scanf("%u", &new[n-1].telefono);
		new->next=list;
	} else {
		printf("\nNon c'e' spazio per creare una nuova scheda!!\n");
		return NULL;
	}
	return new;
}

void
rubrica_print(rubrica_t *head){
	rubrica_t *tail;
	
	tail=NULL;
	do {
		tail=head->next;
		printf("Nome\t\t\tCognome\t\t\tTelefono\n");
		printf("%s\t\t\t%s\t\t\t%u\n", head->nome, head->cognome, head->telefono);
		head=tail;
	} while (head);
	
}

void
rubrica_free(rubrica_t *rubrica){
	rubrica_t *next;
	
	while(next){
		next=rubrica->next;
		free(rubrica);
		rubrica=next;
	}	
}

int
main (int argc, char **argv){
	rubrica_t *rubrica;
	char scelta, nome[max], cognome[max];
	long int telefono;
	int cont;
	
	rubrica=NULL;
	cont=0;
	printf("\t\t\t\tCreazione di una Rubrica\n");
	do {
		printf("\t\t\t\tMenu' Principale\n");
		printf("A)ggiungi scheda\nC)ancella scheda\nV)isualizza Rubrica\nE)limina tutto\nU)uscita Programma\n");
		scanf("%c", &scelta);
		switch(scelta){
			case 'A' :
			case 'a' : {
				printf("\n\n");
				cont++;
				rubrica=rubrica_cons(nome, cognome, telefono, rubrica, cont);
				break;
			}
			case 'V' :
			case 'v' : {
				printf("\n\n");
				rubrica_print(rubrica);
				break;
			}
			case 'C' :
			case 'c' : {
				
				break;
			}
			case 'E' :
			case 'e' : {
				rubrica_free(rubrica);
				break;
			}
		}
		printf("\n\n");
	} while((scelta!= 'U') && (scelta!= 'u'));
	
	return 0;
}

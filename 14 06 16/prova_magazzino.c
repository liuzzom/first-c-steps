#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
#define STORAGE 100

// Types 

struct magazzino_t{
	char nome_pezzo[MAX];
	unsigned quantita;
	struct magazzino_t *next;
};
typedef struct magazzino_t magazzino_t;

// Protos

void
print_menu();
void
menu();
magazzino_t *
magazzino_input(magazzino_t *magazzino);
void
magazzino_free(magazzino_t *head);
void
magazzino_print(magazzino_t *head);

// Funztions
void
print_menu(){
	printf("1)Inserisci Ricambio\n2)Visualizza Magazzino\n3)Svuota Magazzino\n4)Esci\n");
}


void
menu(){
	magazzino_t *magazzino;
	size_t counter=0;
	char choose;
	magazzino=NULL;
	do{
		print_menu();
		scanf("%c", &choose);
		switch(choose){
			case'1':{
				printf("Inserisci Ricambio:\n");				
				counter++;
				if(counter<STORAGE){
					magazzino=magazzino_input(magazzino);
				}else{
					printf("Magazzino Pieno!\n");
				}
				break;
			}
			case'2':{
				printf("Visaulizza Magazzino:\n");
				magazzino_print(magazzino);
				break;
			}
			case'3':{
				printf("Svuota Magazzino:\n");
				magazzino_free(magazzino);
				break;
				}
		}
	}while(choose!='4');

	printf("Esci Dal Magazzino:\n");
	printf("A Presto\n");
}

magazzino_t *
magazzino_input(magazzino_t *magazzino){
	magazzino_t *new;

	new=NULL;
	new=malloc(sizeof(magazzino_t));
	if(new){
		printf("Inserire Tipo Ricambio:");
		scanf("%29s", new->nome_pezzo);
		printf("Inserire Numero Ricambi:");
		scanf("%u", &new->quantita);

		new->next=magazzino;
	}else{
		printf("Spazio non disponibile\n");
	}
	return new;

}
void
magazzino_free(magazzino_t *head){
	magazzino_t *tail;

	while(head){
		tail=head->next;
		free(head);
		head=tail;
	}
}

void
magazzino_print(magazzino_t *head){
	magazzino_t *tail;
	
	while(head){
		tail=head->next;
		printf("Tipo Ricambio:%s\tNumero pezzi in Magazzino:%u\n", head->nome_pezzo, head->quantita);
		head=tail;
	}
}




// Main
int
main(int argv, char **argc){
	
	printf("Benvenuto!\nPremere un Comando del menu per continuare:\n");
	menu();

	return 0;
}
	

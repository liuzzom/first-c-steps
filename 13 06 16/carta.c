#include <stdio.h>
#include <stdlib.h>

// Types
struct carta{
	char *figura;
	char *seme;
};
typedef struct carta carta;

// Main

int
main(){
	carta carta1;
	
	carta1.figura="Asso";
	carta1.seme="Spade";

	printf("La Carta e un/a %s di %s\n", carta1.figura, carta1.seme);

	return 0;
}

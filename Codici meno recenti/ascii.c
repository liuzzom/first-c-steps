#include <stdio.h>
#include <stdlib.h>

int
main(){
	char c;
	
	printf("inserire carattere:");
	scanf("%c", &c);
	
	if( (c>='a' && c<='z') || (c>='A' && c<='Z') ){
		printf("Carattere Alfabetico.\n");
	} else if (c>='0' && c<='9'){
		printf("Carattere Numerico.\n");
	} else {
		printf ("Carattere Speciale.\n");
	}
	
	return 0;
}

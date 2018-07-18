#include <stdio.h>
#include <stdlib.h>

// Prototipi //


// Funzioni //


// Main //

int
main(int argc, char **argv){
	int i;
	for(i=0; i<argc; i++){
		
		printf("argv[%i]: %s\n", i, *(argv+i));
	}
	
return 0;
}

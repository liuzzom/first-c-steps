#include <stdio.h>
#include <stdlib.h>

// Prototipi //
void
print(int argc, char **argv);

// Funzioni //
void
print(int argc, char **argv){
	int i;
	for(i=0; i<argc; i++){
		printf("argv[%i]: %s\n", i, argv[i]);
	}
}
// Main //

int
main(int argc, char **argv){
	
	print( argc,  argv);
	
return 0;
}

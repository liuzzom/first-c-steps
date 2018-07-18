#include <stdio.h>
#include <stdlib.h>

// Prototipi //
void
print(size_t argc, char **argv);


// Funzioni //
void
print(size_t argc, char **argv){
	size_t i;
	for(i=0; i<argc; i++){
		printf("argv[%i]: %s\n", i, argv[i]);
	}
}


// Main //

int
main(int argc, char **argv){
	int value;
	int *value_ptr;
	void *ptr;
	
	value=10;
	
	value_ptr=&value;
	printf("%c\n", *argv[0]);
	printf("%c\n", **argv);
	printf("%s\n", argv[0]);
	printf("value: %i\n", value);
	printf("value_ptr: %p\n", value_ptr);
	printf("*value_ptr: %i\n", *value_ptr);
	
	printf("%s\n", argv[0]);
	printf("%s\n", *(argv+0));
	ptr=argv;
	printf("ptr: %p\n", ptr);
	printf("%s\n", *((char **)ptr));
	
	ptr=argv[0];
	printf("%s\n", ptr); 
	
	print(argc, argv);
	
return 0;
}

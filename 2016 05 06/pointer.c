#include <stdio.h>
#include <stdlib.h>

// Prototipi //


// Funzioni //


// Main //

int
main(int argc, char **argv){
	int value;
	int *value_ptr;
	void *ptr;
	
	value=10;
	
	value_ptr=&value;
	ptr=value_ptr;
	ptr=argv;
	
	printf("argc: %i\n", argc);
	printf("argv: %c\n", *argv[0]);
	printf("argv: %s\n", *argv);
	printf("argv: %c\n", *argv[1]);
	printf("%zu\n", argc* sizeof(char *));

	printf("value: %i\n", value);
	printf("value_ptr: %p\n", value_ptr);
	printf("*value_ptr: %i\n", *value_ptr);
	
	printf("%s\n", argv[0]);
	printf("%s\n", *(argv+0));
	printf("ptr: %p\n", ptr);
	printf("%s\n", *((char**)ptr));
	
return 0;
}

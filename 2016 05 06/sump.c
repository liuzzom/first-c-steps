#include <stdio.h>
#include <stdlib.h>

//Prototipi//

unsigned int
string_to_int(const char string[]);

//Funzioni//

unsigned int
string_to_int(const char string[]){
	unsigned int value;
	size_t i;
	
	value=0;
	i=0;
	
	while(string[i]!='\0'){
		value*=10;
		value+=string[i]-'0';
		i++;
}		

return value;	
}

//Main//

int
main(int argc, char **argv){
	int i, sum;
	sum=0;
	for(i=1; i<argc; i++){
		sum+=string_to_int(argv[i]);
}

printf ("sum is: %i\n", sum);
	
return 0;
}

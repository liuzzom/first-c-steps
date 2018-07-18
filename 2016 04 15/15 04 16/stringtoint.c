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
main(){
	char string[]="123";
	
	printf("%c: %u ", string[0], string[0]-'0');
	printf("%u\n", string_to_int(string));
	
return 0;
}

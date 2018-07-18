#include <stdio.h>
#include <stdlib.h>

//Prototipi//



//Funzioni//

int
calc(char **strings, size_t number_of_strings){
	int sum;
	size_t i;
	
	sum=0;
	for(i=0; i<number_of_strings; i++){
		sum+=atoi(strings[i]);
		}
		return sum;
}


//Main//

int
main(int argc, char **argv){
	int i, sum;

	sum=calc(argv+1, argc-1);	
	printf ("sum is: %i\n", sum);
	
return 0;
}

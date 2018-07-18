#include <stdio.h>
#include <stdlib.h>

int
main(){
	int fibonacci[15], i;
	
	fibonacci[0]=0;
	fibonacci[1]=1;
	
	for(i=2; i<15; i++){
		fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
	}
	
	for(i=0; i<15; i++){
		printf("%i ", fibonacci[i]);
	}
	printf("\n");
	return 0;
}		

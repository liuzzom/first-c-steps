#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_GRADES 6

int
main(){
	int grades[6],n_voti, i, sum;
	
	n_voti=NUMBER_OF_GRADES;
	
	for (i=0; i<n_voti; i++){
		printf("Inserire #%i Voto: ", i);
		scanf("%i", &grades[i]);
	}
	
	sum=0;
	for(i=0; i<n_voti; i++){
		sum+=grades[i];
	}
	printf("La sua Media è: %f\n", (float)sum/(float)n_voti);
	
	for(i=0; i<n_voti; i++){
		printf("%i: %i\n", i, grades[i]);
	}	
	return 0;
}
	

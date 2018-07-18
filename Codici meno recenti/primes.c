#include <stdio.h>
#include <stdlib.h>

int
main(){
	int primes[50], p, is_prime, i, primes_index;
	
	primes [0]=2;
	primes [1]=3;
	primes_index=2;
	
	for(p=5; p<=50; p+=2){
		is_prime=1;
		for(i=0;(is_prime && (i<primes_index)); i++){
			if(p%primes[i]==0){
				is_prime=0;
			}
		}
		if(is_prime){
			primes[primes_index]=p;
			primes_index++;
			
		}
	}
	for(i=0; i<primes_index; i++){
		printf("%i ",primes[i]);
	}

	printf("\n");
		
return 0;
}
	
			

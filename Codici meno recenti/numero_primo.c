#include <stdio.h>
#include <stdlib.h>

int
main(){
	int d, p, is_prime;
		
	for(p=2; p<50; p++){
		is_prime=1;	
		for(d=2; d<p; d++){
			if(p%d==0){
				is_prime=0;				
			}
		}
		if(is_prime){
			printf("%i ", p);	
		}
	}
	printf("\n");
	
	return 0;
}	

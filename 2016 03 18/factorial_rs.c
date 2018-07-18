#include <stdio.h>
#include <stdlib.h>

//Functions//

unsigned long int
factorial(unsigned int n){
	unsigned long result, temp;
	
	printf("n: %u\n", n);
	
	if(n==0){
			
		result=1;		
		
	}else{
		temp= factorial(n-1);
		result= n*temp;
		printf("n: %u result: %u*%lu=%lu\n", n, n, temp,result); 
	}	
		
			
	return result;
}

//Main//

int
main(){
	unsigned int n;
	
	n=5;
	
	printf("%i!= %lu\n", n, factorial(n));

	return 0;
}

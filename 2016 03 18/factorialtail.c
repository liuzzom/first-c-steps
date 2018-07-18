#include <stdio.h>
#include <stdlib.h>

unsigned long int
factorial_tail(unsigned int n, unsigned long int result){

	if(n==0){
		return result;
	}else {
		return factorial_tail(n-1, n*result);
	}
}

int
main(){
	unsigned int n;
	
	n=5;
	
	printf("(tail) %u!= %lu\n", n, factorial_tail(n,1));
	
	return 0;
}




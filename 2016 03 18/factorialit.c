#include <stdio.h>
#include <stdlib.h>

unsigned long int
factorial_it(unsigned int n){
	unsigned long result;
	
	result=1;
	
	if(n==0){
		result=1;
	}else{
	
		while(n>0){
		
			result=result*n;
			n--;
			printf("n: %u result: %lu\n", n, result);	
		}
	}
	
	return result;

}

int main(){
	unsigned int n;
	
	n=5;
	
	printf("%i!=%lu\n", n, factorial_it(n));
	
	return 0;
	
}
		
	

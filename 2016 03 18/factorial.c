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

unsigned long int
factorial_tail(unsigned int n, unsigned long int result){

	if(n==0){
		return result;
	}else {
		return factorial_tail(n-1, n*result);
	}
}


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

//Main//

int
main(){
	unsigned int n;
	
	n=5;
	
	printf("(recursive) %u!= %lu\n", n, factorial(n));
	printf("(tail) %u!= %lu\n", n, factorial_tail(n,1));
	printf("(iterative) %u!=%lu\n", n, factorial_it(n));
	
	return 0;
}


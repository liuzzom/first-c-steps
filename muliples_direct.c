#include <stdio.h>
#include <stdlib.h>
#define SIZE 64

int main(int argc, char **argv){
	
	int multiples[SIZE];
	int index=0;

	if(argc==2){

		int integer = atoi(argv[1]);		

		for(int count=2; count<=(integer/2); count++){
		
		if(integer%count==0){ //search and save the integer's multiples
			multiples[index]=count;
			index++;
			}

		}

		if(index==0){ //case: integer is a prime number
			printf("%d is prime\n", integer);
		}else{ // case: integer has some multiples
			printf("%d multiples are:", integer);
			for(int i=0; i<index; i++){
				printf("%d ", multiples[i]);
			}
			printf("\n");
		}
	}else{
		printf("ERROR:Insert ONLY one number\n");
	}

	return 0;
}
#include <stdio.h>
#define SIZE 64

int main(){
	int multiples[SIZE];
	int integer;
	int index=0;

	printf("Enter an integer:");
	scanf("%d", &integer);

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

	return 0;
}
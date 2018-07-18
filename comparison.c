#include <stdio.h>

int main(){
	int integer1, integer2;

	printf("Insert first number:");
	scanf("%d", &integer1);
	printf("Insert second number:");
	scanf("%d", &integer2);

	if(integer1 < integer2){ // if verifica la condizione e esegue il blocco al suo interno se essa è vera
		printf("%d is less than %d\n", integer1, integer2);
	}else if(integer1  > integer2){
		printf("%d is greater than %d\n", integer1, integer2);
	}else{
		printf("The numbers entered are the same:%d\n", integer1);
	}

	return 0;
}
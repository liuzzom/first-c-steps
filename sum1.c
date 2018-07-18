#include <stdio.h>

int main(){
	int integer1, integer2, sum; // dichiarazione variabili di tipo int, ossia interi con segno

	printf("Insert first number:");
	scanf("%d", &integer1); // &:opreratore di reference; &integer1 è l'indirizzo in memoria di integer1

	printf("Insert second number:");
	scanf("%d", &integer2);

	sum=integer1+integer2; // aseegnamento

	printf("%d+%d=%d\n", integer1, integer2, sum);

	return 0;
}
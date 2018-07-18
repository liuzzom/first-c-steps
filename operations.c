#include <stdio.h>

int main(){
	int integer1, integer2;

	printf("Insert first number:");
	scanf("%d", &integer1);
	printf("Insert second number:");
	scanf("%d", &integer2);

	printf("Sum:%d\nDifference:%d\nProduct:%d\nQuotient:%d\nRemainder:%d\n", integer1+integer2, integer1-integer2, integer1*integer2, integer1/integer2, integer1%integer2);

	return 0;
}
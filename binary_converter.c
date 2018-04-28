#include <stdio.h>
#include <math.h>

int main(int argc, char const **argv){
	unsigned long int number, a;
	int index=0;
	int converted_number=0;
	int digit;

	printf("Insert a binary number:");
	scanf("%lu", &number);
	a=number;

	do{
		converted_number += (number%10)*pow(2, index);
		index++;
		number/=10;
	}while(number!=0);

	printf("Binary:%lu\nDecimal:%d\n", a, converted_number);

	return 0;
}
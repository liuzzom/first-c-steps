#include <stdio.h>

int main(int argc, char const **argv){
	int number, i, j;

	puts("This program will draw a trangle made of *.");
	printf("Please, insert a number:");
	scanf("%d", &number);
	puts("");

	for(i=0; i<number; i++){
		for(j=0; j<=i; j++){
			printf("* ");
		}
		puts("");
	}

	puts("");

	return 0;
}
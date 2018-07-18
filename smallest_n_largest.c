#include <stdio.h>
#include <limits.h>

int main(int argc, char** argv){
	int counter=0;
	int smallest=INT_MAX;
	int largest=INT_MIN;
	int number, limit;

	printf("How many numbers do you have to compare? ");
	scanf("%d", &limit);

	while(counter<limit){
		printf("Insert a number (%d of %d):", counter+1, limit);
		scanf("%d", &number);

		if(number<smallest){
			smallest=number;
		}

		if(number>largest){
			largest=number;
		}

		counter++;
	}

	printf("The largest number is:%d\nThe smallest number is:%d\n", largest, smallest);

	return 0;
}
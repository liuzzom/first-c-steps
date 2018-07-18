#include <stdio.h>

int main()
{

	printf("number\tsquare\tthird power\n");

	for(int index=0; index<=10; index++){

		printf("%d\t%d\t%d\t\n", index, index*index, index*index*index);
	}

	return 0;
}
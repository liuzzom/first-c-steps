#include <stdio.h>
#define SIZE 5

int main(int argc, char const **argv){
	int array[SIZE];
	int i, j, tmp;

	// inserting values into the array
	for(i=0; i<SIZE; i++){
		printf("insert a number(%d of %d):", i+1, SIZE);
		scanf("%d", &array[i]);
	}

	// printing of not sorted elements
	printf("Not sorted elements: ");
	for(i=0; i<SIZE; i++){
		printf("%d ", array[i]);
	}
	printf("\n");

	// sorting operation
	for(i=0; i<SIZE-1; i++){
		for(j=0; j<SIZE; j++){
			if(array[j+1]<array[j]){
				//swap operation
				tmp=array[j];
				array[j]=array[j+1];
				array[j+1]=tmp;
			}
		}
	}

	// printing of sorted elements
	printf("sorted elements: ");
	for(i=0; i<SIZE; i++){
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}
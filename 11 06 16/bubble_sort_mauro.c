#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Protos 

void
array_print(int array[], size_t number_of_elements);

void
array_order(int array[], size_t number_of_elements);

// Functions

void
array_print(int array[], size_t number_of_elements){
	size_t i;

	for(i=0; i<number_of_elements; i++){
		printf("%i", array[i]);
	}
	printf("\n");
	return;
}

void
array_order(int array[], size_t number_of_elements){
	size_t i, j;
	int temp;
	

	for(i=0; i<number_of_elements; i++){
		for(j=0; j<number_of_elements; j++){
			if(array[j+1]<array[j]){
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}

	return;
}
// Main

int
main(int argc, char **argv){

	int array[MAX]; // array indefinito di int
	int number_of_elements, i; // indici del numero di elemeneti e per scorrere l'array

	printf("Inserire numero di elementi dell' array(max:100 elementi):"); 
	scanf("%i", &number_of_elements);// inserimento del numero di elementi da inserire 

	for(i=0; i<number_of_elements; i++){
		printf("Inserire valore:"); // inserimento dei valori nell'array
		scanf("%i", &array[i]);
	}

	array_print(array, number_of_elements);
	array_order(array, number_of_elements);
	array_print(array, number_of_elements);

	return 0;
}
